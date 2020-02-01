# include <thread>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;



bool isPrime(int inNumber){
    bool divisible = false;

    if (inNumber == 1){
        return true;
    }

    for (int i = 2; i < inNumber / 2+1; i++)
    {
        if (inNumber % i == 0)
        {
            divisible = true;
            break;
        }
    }
    return !divisible;
}

vector<int> checkInterval(int start, int stop, int numberOfThreads)
{
    mutex valueLock;
    vector<thread> threads;
    vector<int> primeNumbers;
    int valueToCheck = start;

    for(int i=0; i<numberOfThreads; i++){
        threads.emplace_back(([&valueToCheck, &valueLock, &stop, &primeNumbers] {
            
            while(true){
           
                if (valueToCheck < stop)
                {
                    valueLock.lock();
                    if (isPrime(valueToCheck))
                    {
                        primeNumbers.emplace_back(valueToCheck);
                        /*
                        cout << valueToCheck << "\n";
                        cout << "hello from thread" << i << "\n";
                        */
                    }
                    valueToCheck++;
                    valueLock.unlock();
                } else
                {
                    break;
                }
            }
        }));
    }

    for(auto &thread : threads){
        thread.join();
    }

    return primeNumbers;

}



int main()
{   
vector<int> list = checkInterval(2,1000, 4);

for(auto integer : list){
    cout << integer << "\n";
}

}




