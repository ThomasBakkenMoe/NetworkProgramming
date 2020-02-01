# include <thread>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;



bool isPrime(int inNumber){
    bool divisible = false;

    if (inNumber == 1){
        return false;
    }

    for (int i = 2; i < (inNumber / 2)+1; i++)
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
    mutex listLock;

    for(int i=0; i<numberOfThreads; i++){
        threads.emplace_back(([i, &valueToCheck, &valueLock, &stop, &primeNumbers, &listLock] {
            int localValue = 0;
            while(localValue < stop){


                valueLock.lock();
                localValue = valueToCheck;
                valueToCheck++;
                valueLock.unlock();


                    if (isPrime(localValue))
                    {
                        listLock.lock();
                        primeNumbers.emplace_back(localValue);

                        cout << localValue << endl;
                        cout << "hello from thread" << i << endl;
                        listLock.unlock();

                    }

            }
        }));
    }

    for(auto &thread : threads){
        thread.join();
    }

    //TODO: Need to sort list before return
    return primeNumbers;

}



int main()
{   
vector<int> list = checkInterval(1,100000, 7);

for(auto integer : list){
    //cout << integer << "\n";
}

cout << "Found " << list.size() << " prime numbers";
 
}




