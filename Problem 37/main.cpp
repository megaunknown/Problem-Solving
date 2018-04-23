#include <iostream>
#include <math.h>
#include <string>
#include "list.h"
using namespace std;

/*
Truncatable primes:
-------------------
The number 3797 has an interesting property. Being prime itself,
it is possible to continuously remove digits from left to right,
and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/
char* clrBuffer(char* szBuff);

long strLen(char* szText)
{
	int	i = 0 ;
	while(szText[i] != '\0')
		i++;
	return i;
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

char* ReverseStr(char* szString)
{
	int len = strLen(szString);
	int iCount = 0 ;
	char* szRev = new char[len];

	memset(szRev,'\0',len);
	
	for(int i = len-1 ; i >= 0 ; i--)
	{
		szRev[iCount] = szString[i]; 
		iCount++ ;
	}
	szRev = clrBuffer(szRev);
	return szRev ;
}


ArrayList<int> retAllPossibilities(int a)
{
	ArrayList<int> myAL(100);
	char* szBuffer = new char[7];
	itoa(a,szBuffer,10);
	
	int tmp = 0 ;
	int len = strLen(szBuffer);
	int i = 0;

	char* szTmp = new char[7];
	//Left to Right
	//Completed
	/*	
	for( i = 1 ; i <= len ; i++)
	{
		int index = 0 ;
		memset(szTmp,'\0',len);
		for(int j = 0 ; j < i ; j++)
		{
			szTmp[index] = szBuffer[j];
			index++;
		}
		tmp = atoi(szTmp);
		myAL.insert(tmp);

	}
*/
	//Right to Left
	/**/	
	for( i = len-1 ; i >= 0 ; i--)
	{
		int index = 0 ;
		memset(szTmp,'\0',len);
		
		for(int j = len-1 ; j >= i ; j--)
		{
			szTmp[index] = szBuffer[j];
			index++;
		}
		szTmp = ReverseStr(szTmp);
		cout << szTmp << endl;
		/*
		
		tmp = atoi(szTmp);
		myAL.insert(tmp);
		*/
	}

	return myAL ;
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

ArrayList<int> genALPrimeBelowN(int N)
{
	ArrayList<int> myAL(N);
	int i ;
	

	for( i = 2 ; i < N; i++)
	{
		if(isPrime(i))
		{
			myAL.insert(i);		
		}
	}
	return myAL ;
}

char* clrBuffer(char* szBuff)
{
	int ilen = strLen(szBuff);
	for(int i = 0 ; i < ilen ; i++)
	{
		if(!isalnum((int)szBuff(i)) || !isalpha((int)szBuff(i)))
		{
			szBuff[i] = '\0' ;
		}
	}
	return szBuff;
}

void main()
{
	ArrayList<int> m  = retAllPossibilities(1234);
//	m.print();
//	cout << strLen("9999") ; 
}