# include <thread>
#include <iostream>


using namespace std;

bool isPrime(int inNumber)
{
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

void checkInterval(int start, int stop, int numberOfThreads)
{
    for (int i = start; i < stop; i++)
    {
        if (isPrime(i))
        {
            cout << i << "\n";
        }
    }
}



int main()
{

checkInterval(2,100, 4);

}




