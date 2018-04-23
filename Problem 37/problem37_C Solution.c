#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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

int isPrime (int num);
void truncsss(int a);
void reverse(char s[]);
char* revString(char* szBuffer);
int isTruncablePrime(int a);

int isPrime(int num)
{
	int bRet = 0 ;
	
	if(num == 1 )
		return 0 ;
	else if(num == 2)
		return 1 ;
	else if(num % 2 == 0 )
		return 0 ;
	else
	{
		int i = 2 ;
		bRet = 1 ;
		for( ;  i < num ; i++)
		{
			if(num % i == 0)
			{
				bRet = 0 ;
				break ;
			}
		}
	}

	return bRet ;
}

void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	
	i = 0;
	
	do         /* generate digits in reverse order */
	{
		s[i++] = n % 10 + '0';   /* get next digit */
	}while ((n /= 10) > 0);       /* delete it */

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	
	reverse(s);
}

char* revString(char* szBuffer)
{
	char* szRev = NULL ;
	int len =  strlen(szBuffer);

	szRev = (char*) malloc(sizeof(char)* len);

	int i = 0;
	int iIndex = 0 ;

	for( i = len-1 ; i >= 0 ; i--)
	{
		szRev[iIndex] = szBuffer[i];
		++iIndex ;
	}

	return szRev ;
}



int main()
{
	int i = 0 ;
	int ist = 0 ;
	int counter = 0 ;
	unsigned long int sum = 0 ;
	
	for( i = 11 ; i < 8000000 ; i++)
	{
		if(isPrime(i))
		{
			if(counter == (int)11)
			{
				printf("\n\n\tSum is :%ld\n\n", sum);
				break ; 
			}
			
			ist = isTruncablePrime(i) ;

			if(ist)
			{
				printf("#%d : %d is prime and %s truncable\n", counter+1 , i , (ist ? "is" : "isn't") );
				sum = sum + i ;
				++counter;
			}
		}
	}
	//748317

/*	isTruncablePrime(3797);*/
	return  0 ;
}

void truncsss(int a)
{
	static int counter = 0 ;
	static int sum = 0 ;

	//allocate buffer
	char* szBuffer = (char*) malloc(sizeof(char)* 10);
	//convert into string
	itoa(a, szBuffer);
	//get the len
	int iLen = strlen(szBuffer);
	//check the length of converted integer...

	//printf("counter carried value is %2d\n\n",counter);
	
	if(counter >= 11 )
	{
		printf("\n\tSum value is ::%d\n",sum);
		exit(-1);
	}

	if(iLen >= 2 )
	{

		int i = 0 , j = 0, c = 0 , intValue = 0, fHalf = 0 , sHalf = 0 ;
		//	printf("left to right\n");
		char* mm = (char*) malloc(sizeof(char)* 10);
		memset(mm,'\0',10);

		for( i = 0 ; i < iLen ; i++)
		{
			for(j = 0 ; j <= i ; j++)
			{
				mm[c] = szBuffer[j];
				c++ ;
			}
			//printf("%s",mm);
			intValue = atoi(mm);
			if(isPrime(intValue) == 1)
				fHalf = 1 ;
			else
			{
				fHalf = 0 ;
				break;
			}
			//printf("Integer String Value ::%-20s ,isPrime::%d\n",mm,isPrime(intValue));
			c = 0 ;
			memset(mm,'\0',10);
		}

		if(fHalf == 1)
		{
			c = 0 ;
			
			for( i = iLen-1 ; i >=0 ; i--)
			{
				for(j = iLen-1 ; j >= i ; j--)
				{
					mm[c] = szBuffer[j];
					c++ ;
				}
				reverse(mm);
				intValue = atoi(mm);
				if(isPrime(intValue) == 1)
					sHalf = 1 ;
				else
				{
					sHalf = 0 ;
					break;
				}
				//printf("Integer String Value ::%-20s ,isPrime::%d\n",mm,isPrime(intValue));
				memset(mm,'\0',10);
				c = 0 ;
			}

			if(sHalf == 1)
			{
				printf("The Prime #%2d Truncable number is : %4d\n",counter+1,a);
				sum = sum + a ;
				//		printf("SUM \t\t %2d\n",sum);
				++counter;
			}
		}

		free(mm);

	}
	free(szBuffer);
}
//573


int isTruncablePrime(int a)
{
	int iResult = 0 ;
	//allocate buffer
	char* szBuffer = (char*) malloc(sizeof(char)* 10);
	//convert into string
	itoa(a, szBuffer);
	//get the len
	int iLen = strlen(szBuffer);
	//check the length of converted integer...

	//printf("counter carried value is %2d\n\n",counter);
	
	if(iLen >= 2 )
	{

		int i = 0 , j = 0, c = 0 , intValue = 0, fHalf = 0 , sHalf = 0 ;
		
		//printf("left to right\n");
		
		char* mm = (char*) malloc(sizeof(char)* 10);
		memset(mm,'\0',10);

		for( i = 0 ; i < iLen-1 ; i++)
		{
			for(j = 0 ; j <= i ; j++)
			{
				mm[c] = szBuffer[j];
				c++ ;
			}
		//	printf("%s\n",mm);
			intValue = atoi(mm);
			
			if(isPrime(intValue) == 1)
				fHalf = 1 ;
			else
			{
				fHalf = 0 ;
				break;
			}
			/**/
			//printf("Integer String Value ::%-20s ,isPrime::%d\n",mm,isPrime(intValue));
			c = 0 ;
			memset(mm,'\0',10);
		}

		if(fHalf == 1)
		{
	//		printf("right to left\n");
			memset(mm,'\0',10);
			c = 0 ;
			
			for( i = iLen-1 ; i >=1 ; i--)
			{
				for(j = iLen-1 ; j >= i ; j--)
				{
					mm[c] = szBuffer[j];
					c++ ;
				}
				reverse(mm);
	//			printf("%s\n",mm);
				
				intValue = atoi(mm);
				
				if(isPrime(intValue) == 1)
					sHalf = 1 ;
				else
				{
					sHalf = 0 ;
					break;
				}
				memset(mm,'\0',10);
				c = 0 ;
			}
		}
		
		if(sHalf == 1)
		{
			iResult = 1 ;
		}
		
		free(mm);
	}
	free(szBuffer);

	return iResult ;
}
