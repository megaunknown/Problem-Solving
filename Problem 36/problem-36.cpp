#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
Problem 36
The decimal number, 585 = 1001001001(binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

//General Counter
long int i = 0 ;

//Convert long integer to Binary
char* convertDicBin(long a)
{
	int iIndex = 0 ;
	char szBuffer[1024];
	char szRevBuffer[1024];

	for( ; a > 0 ; )	
	{
		if(a % 2 == 0 )
		{
			szBuffer[iIndex] = '0' ;
		}
		else
		{
			szBuffer[iIndex] = '1';
		}
		a = a / 2 ;
		iIndex++;
	}

	szBuffer[iIndex] = '\0';
	//Reverse the string...
	int t = iIndex-1 ;

	for( i = 0 ; i < iIndex ; i++, t--)
	{
		szRevBuffer[i] = szBuffer[t] ; 		
	}
	szRevBuffer[i] = '\0';

	return szRevBuffer ;
}

//return len of given string.
long strLen(char* szText)
{
	i = 0 ;
	while(szText[i] != '\0')
		i++;
	return i;
}

//Check Decimal Number Palindrom
bool isPalindromDec(int a)
{
	//convert to string.
	char szDecimal[1024];
	itoa(a,szDecimal,10);


	bool bRet = false ;
	int len = strLen(szDecimal);
	int iCenter ;

	if(len % 2 == 0) //even
	{
		iCenter = (len/2) -1 ;
		for(int i = 0 , j = len-1 ; i  <= iCenter && j >= iCenter ; i++ , j--)
		{

			if( szDecimal[i] == szDecimal[j]){
				bRet = true ;
			}
			else{
				bRet = false ;
				break;
			}
		}
	}
	else
	{
		iCenter = (len / 2) ;
		for(int i = 0 , j = len -1 ; i <= iCenter && j >= iCenter ; i++ , j--)
		{
			if( szDecimal[i] == szDecimal[j]){
				bRet = true ;
			}
			else{
				bRet = false ;
				break;
			}
		}
	
	}
	return bRet ;
	
}

//Check Binary Number Palindrom
bool isPalindromBin(char* szBinary)
{
	bool bRet = false ;
	int len = strLen(szBinary);
	int iCenter ;
	if(len % 2 == 0) //even
	{
		iCenter = (len/2) -1 ;
		for(int i = 0 , j = len-1 ; i  <= iCenter && j >= iCenter ; i++ , j--)
		{
			if( szBinary[i] == szBinary[j])
				bRet = true ;
			else
			{
				bRet = false ;
				break;
			}
		}
	}
	else
	{
		iCenter = (len / 2) ;
		for(int i = 0 , j = len -1 ; i <= iCenter && j >= iCenter ; i++ , j--)
		{
			if( szBinary[i] == szBinary[j])
				bRet = true ;
			else
			{
				bRet = false ;
				break;
			}
		}
	
	}
	return bRet ;
}

//Check is decimal & it's binary value are palindromic or not
bool isDecBinPalindrom(long Dec)
{
	bool bRet = false ;
	if(isPalindromDec(Dec))
	{
		char* szBuffer = new char[1024];
		szBuffer = convertDicBin(Dec);
		if(isPalindromBin(szBuffer))
			bRet = true;
		else
			bRet = false ;
	}

	return bRet;
}

//Check is decimal & it's binary value are palindromic or not
//based on special case "Not Begins with 0 Either the decimal number or the binary number."
bool isDecBinPalindrom36(long Dec)
{
	bool bRet = false ;
	
	char* szBuffer = new char[1024];
	itoa(Dec,szBuffer,10);
	int len = strLen(szBuffer);

	if( szBuffer[len-1] == '0')
	{
		return bRet ;
	}

	szBuffer = convertDicBin(Dec);
	len = strLen(szBuffer);

	if( szBuffer[len-1] == '0')
	{
		return bRet ;
	}

	if(isPalindromDec(Dec))
	{
	
		if(isPalindromBin(szBuffer))
			bRet = true;
		else
			bRet = false ;
	
	}

	return bRet;
}

int main()
{
	//Get the sum of all numbers below 1 million which satisfy the rule.
	unsigned long int iSum = 0 ;
	for(int i = 1 ; i < 1000000 ; i++)
	{
		if(isDecBinPalindrom36(i))
			iSum+= i ;
	}
	cout << iSum << endl;
	return 0 ;
}

