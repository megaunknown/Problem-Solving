#include <iostream>
using namespace std ;
#include <math.h>


/*
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.


*/

bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

int main(int argc, char* argv[])
{
	int sum = 0 ;

	for(int i = 2 ; i < 2000000 ; i++)
	{
		if(isPrime(i))
		{
			sum += i ;
		}
	}

	cout << sum << endl;
	system("pause");
}
