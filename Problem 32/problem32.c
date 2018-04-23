#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
using namespace std;

void reverse(char s[]);
void  itoa(int n, char s[]);
//functions Prototype
int isPandigit(int num);
int fullPandigit(char* szString);
int unusual(int t1,int t2, long int result);

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
for example, the 5-digit number, 15234, is 1 through 5 pandigital.
The product 7254 is unusual, as the identity, 39 × 186 = 7254, 
containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

int isPandigit(int num)
{
	int bRet = 1 ;

	char* szBuffer  = (char*) malloc(sizeof(char) * 10);
	memset(szBuffer, '\0', 10 );

	itoa(num, szBuffer);

	int iLen =  strlen(szBuffer);
	int i = 0, j = 0 ;

	for( i  = 0 ; i < iLen ; i++)
	{
		for(j = i+1 ; j < iLen ; j++)
		{
			if(szBuffer[i] == szBuffer[j])
			{
				bRet= 0 ;
				break;
			}
		}

		if(! bRet)
			break;
	}

	return bRet ;
}

int fullPandigit(char* szString)
{
	//check is there Zero
	if(strchr(szString,'0'))
		return 0 ;

	int bRet = 0 ;

	int iLen =  strlen(szString);
	int i = 0, j = 0 ;

	//printf("The string length :%2d\n",iLen);

	if(iLen == 9)
	{
		for( i = 0 ; i < iLen ; i++)
		{
			int acc = 0 ;
			char tmp2 = szString[i] ;
			//look for 1-9 Occurrence..
			for( j = 0 ; j < iLen ; j++)
			{
				//convert int value to char
				//char tmp = (char)(((int)'0') + j ) ;
				char tmp = szString[j];
				//printf("%c \t%c \t%d \t%d\n",tmp,tmp2,tmp,tmp2);

				if(tmp == tmp2 )
					acc++ ;
			}

			if(acc == 1)
			{
				bRet = 1 ;
			}
			else if(acc == 0 || acc > 1)
			{
				bRet = 0 ;
				break;
			}
			//printf("Occurrence %d\n",acc);
		}

		if(bRet == 0 )
			exit ;
	}

	return bRet ;
}

int unusual(int t1,int t2, long int result)
{
	int bRet = 0 ;

	char* szPart  = (char*) malloc(sizeof(char) * 10);
	//memset(szPart, '\0', 10 );
	itoa(t1, szPart);
	//Allocate the buffer
	char* szFull  = (char*) malloc(sizeof(char) * 100);
	//Clear the buffer
	memset(szFull,'\0', 100 );
	//concatenate the first term
	strcat(szFull,szPart);
	//clear the buffer
	memset(szPart, '\0', 10 );
	//convert into string
	itoa(t2, szPart);
	//concatenate the second term
	strcat(szFull, szPart);
	//clear the buffer
	memset(szPart, '\0', 10 );
	//convert the last part
	itoa(result, szPart);
	//concatenate the last part
	strcat(szFull, szPart);
	//release from memory
	free(szPart);
	//Check the len
	if(strlen(szFull) == 9 )
	{
		//Assure that's a Pandigit String... X * Y = Z
		if(fullPandigit(szFull))
		{
			bRet = 1 ;
		}
	}

	return bRet ;
}



void main()
{
	/*
	printf("%d\n", fullPandigit("987654321"));
	printf("%d\n", fullPandigit("123456789"));
	printf("%d\n", fullPandigit("112345678"));
	printf("%d\n", fullPandigit("222222222"));
	printf("%d\n", fullPandigit("918472254"));
	printf("%d\n", fullPandigit("123456789"));
	printf("%d\n", isPandigit(2121111));
	printf("%d\n", isPandigit(1234567));
	printf("%d\n", isPandigit(3234567));
	printf("%d\n", isPandigit(2123));
	*/

	int i = 0 , j = 0 ;
	long sum = 0 ;
	
	long* products= (long*) malloc(sizeof(long)* 100);
	memset(products,0,100);
	
	int counter = 0 ;
	
	for(i = 1 ; i < 2000 ; i++)
	{
		for(j = 1 ; j < 2000 ; j++)
		{
			if(unusual(i,j,i*j) == 1)
			{
				printf("%d * %d = %d\n",i,j,i*j);
				sum += (i*j) ;
				
				products[counter] = (i*j);
				counter++;
				
			}
		}
	}
	printf("The sum value is :%ld\n",sum);
		
	//remove duplicated numbers
	
	for( i  = 0 ; i < counter ; i++)
	{
		for(j = i+1 ; j < counter ; j++)
		{
			if(products[i] == products[j])
			{
				products[j] = 0 ;
			}
		}
	}
	printf("\n\n"); 
	sum = 0 ;
	
	long* ptr = products ;
	long* ptrEnd = ptr + (sizeof(long) * counter) ;
	
	//obtain the summation
	for( ; ptr != ptrEnd  ; ptr++)
		sum+= *ptr;
		
	//view the vlaues of the array 
	ptr = products;
	for( ; ptr != ptrEnd ; ptr++)
		printf("%ld\n",*ptr);
		
	//view the summation value.
	printf("The sum value is : %ld\n",sum);
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
/*
 First Result
12 * 483 = 5796
12 * 695 = 8340
13 * 406 = 5278
13 * 546 = 7098
13 * 604 = 7852
13 * 754 = 9802
15 * 326 = 4890
15 * 486 = 7290
15 * 492 = 7380
15 * 632 = 9480
15 * 648 = 9720
18 * 297 = 5346
18 * 392 = 7056
18 * 409 = 7362
19 * 204 = 3876
19 * 253 = 4807
19 * 402 = 7638
19 * 453 = 8607
23 * 196 = 4508
26 * 345 = 8970
27 * 198 = 5346
28 * 157 = 4396
32 * 169 = 5408
34 * 178 = 6052
34 * 185 = 6290
38 * 159 = 6042
39 * 186 = 7254
42 * 138 = 5796
48 * 159 = 7632
48 * 165 = 7920
54 * 168 = 9072
59 * 108 = 6372
59 * 136 = 8024
63 * 154 = 9702
69 * 108 = 7452
108 * 59 = 6372
108 * 69 = 7452
136 * 59 = 8024
138 * 42 = 5796
154 * 63 = 9702
157 * 28 = 4396
159 * 38 = 6042
159 * 48 = 7632
165 * 48 = 7920
168 * 54 = 9072
169 * 32 = 5408
178 * 34 = 6052
185 * 34 = 6290
186 * 39 = 7254
196 * 23 = 4508
198 * 27 = 5346
204 * 19 = 3876
253 * 19 = 4807
297 * 18 = 5346
326 * 15 = 4890
345 * 26 = 8970
392 * 18 = 7056
402 * 19 = 7638
406 * 13 = 5278
409 * 18 = 7362
453 * 19 = 8607
483 * 12 = 5796
486 * 15 = 7290
492 * 15 = 7380
546 * 13 = 7098
604 * 13 = 7852
632 * 15 = 9480
648 * 15 = 9720
695 * 12 = 8340
754 * 13 = 9802
The sum value is :487708
 *
 *
 second try
18 * 297 = 5346
27 * 198 = 5346
28 * 157 = 4396
39 * 186 = 7254
42 * 138 = 5796
48 * 159 = 7632
138 * 42 = 5796
157 * 28 = 4396
159 * 48 = 7632
186 * 39 = 7254
198 * 27 = 5346
297 * 18 = 5346
The sum value is :71540

 * 
 Third Try
12 * 483 = 5796
18 * 297 = 5346
28 * 157 = 4396
39 * 186 = 7254
48 * 159 = 7632

30424
The sum value is :83132

 * 
12 * 483 = 5796
18 * 297 = 5346
28 * 157 = 4396
39 * 186 = 7254
48 * 159 = 7632


 
 */
