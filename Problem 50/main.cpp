#include <iostream>
#include <math.h>
#include "list.h"
using namespace std;


/*
Problem 50
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime,
contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

ArrayList<int> genALPrimeBelowN(int N);
void retLargestSeq(ArrayList<int> alPrimList,
				   ArrayList<int> alPrimListEx,
				   int& iMax,
				   int& iPrime);

int retSquence(int iPrime);
void printPrimeNumbersBelowN(int N);
bool isPrime (int num);

int iSeq = 0 ;
int iSum = 0 ;
int iIndex = 0 ;

//Generate all prime numbers below N number.
ArrayList<int> genALPrimeBelowN(int N)
{
	ArrayList<int> myAL(N);
	int i ;
	
	for( i = 2 ; i < N; i++)
		if(isPrime(i))
			myAL.insert(i);

	return myAL ;
}


//Return chained primes.
int retSquence(int iPrime,ArrayList<int> m)
{
	int iSum = 0 ;

	m.moveFirst();
	int iPrimeIndex = m.getPostion();
	int iCurItem = 0 ;
	int iSeq = 0 ;

	
	while(iSum < iPrime)
	{
		while(iSum < iPrime)
		{
			iSum += m.getElement();
			iSeq++;
			m.moveNext();
		}
		if(iSum == iPrime)
			break;

		iPrimeIndex++;
		m.setPostion(iPrimeIndex);
		iSum = 0 ;
		iSeq = 0;
	}
	
	if( iSum != iPrime)
		iSeq = 0 ;
	
	return iSeq ;
}



int main()
{
	ArrayList<int> m = genALPrimeBelowN(1000000);
	ArrayList<int> z = genALPrimeBelowN(1000000);
	
	int iSeq = 0 ;
	int iNum = z.getNumofElements();

	z.moveFirst();
	for(int i = 0 ; i < iNum ; i++)
	{
		int tmp = retSquence(z.getElement(),m) ;
		if(tmp > iSeq )
		{
			iSeq = tmp ;
			cout << "Element :" << z.getElement() << " Seq :" << iSeq << endl;
		}
		z.moveNext();

	}
	cout << retSquence(953);
	return 0 ;
}

/*
	alPrimList : 
	alPrimListEx :
	iMax : return Maximum number of sequence.
	iPrime : return the prime number with Maximum number of sequence.
*/
void retLargestSeq(ArrayList<int> alPrimList,ArrayList<int> alPrimListEx,int& iMax,int& iPrime)
{
	int iMaxTmp = 0 ;
	int iSeq = 0 ;
	
	alPrimList.moveFirst();
	alPrimListEx.moveFirst();

	for(int i = alPrimList.getNumofElements() ; i > 0 ; i--)
	{
//		iSeq = retSquence(alPrimList,alPrimListEx.getElement());
		if ( iSeq > iMaxTmp )
		{
			iMaxTmp = iSeq ;
			iMax = iMaxTmp;	
			iPrime = alPrimListEx.getElement();
//			cout << "\t\tMax Changed " << iMax << " , the prime number is " << iPrime << endl;
		}
		alPrimListEx.moveNext();
		alPrimList.moveFirst();
	}
}



void printPrimeNumbersBelowN(int N)
{
	for(int i = 1 ; i <= N ; i++)
	{
		if(isPrime(i))
		{
			cout << i << endl;
		}
	}
}

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
