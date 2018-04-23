#ifndef _BIG_NUMBER_H
#define _BIG_NUMBER_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <limits.h>

using namespace std;

#define MAX_ARRAY_SIZE	4096


class BigNumber
  {
    public:
	
      BigNumber();
      BigNumber(char *szNumber);
      BigNumber(int iValue);
      
	  //In Case: Default Constructor Has Called...
      void Insert(int initNumber);
      //In Case: Default Constructor Has Called...
      void Insert(char *szBuff);

      void add(unsigned long int num);
      void add(char *szBuff);

      void multiply(unsigned long int num = 1);
      void multiply(char *szBuff);

      void Power(int num);

      unsigned long int getIntValue();
      int sum();
      void toString();
	   char *toCharStar();
    private:
      unsigned long int iInitalValue;
      char *strValue;

     
      //Return Precisely the length of given string szBuff
      int stringLength(char *szBuff);
      int maxBuffLength(char **szBuffer, int nElements);
      void modifiyMultRows(char **szBuffer, int nElements);
      char *shiftLeftColumn(char *szBuffer, int iCol);
      char *shiftRightColumn(char *szBuffer, int iCol);
      char *subString(char *string, int start, int end);
      int IntChar(char *string, int index);
      char *ReverseStr(char *szString);
      bool exceedRange(unsigned long int n);
      bool isDigit(char x);
      void clearBuffer(char *szBuffer, int iBuffLen);
      //Return the length of Given number " n "....
      int lenFunc(unsigned long int n);
  };

class Factorial
{
public:
	Factorial(int num)
	{
		clsNum = new BigNumber(num);
		for(int i = 1 ; i <= num ; i++)
		{
			clsNum->multiply(i);
		}

	}

	Factorial(char* szNum)
	{
		clsNum = new BigNumber(szNum);
	}
	
	~Factorial()
	{
		delete clsNum;
	}

	char* getValue()
	{
		char* szBuffer = clsNum->toCharStar();
		return szBuffer ;
	}

	int getFacSum()
	{

	}
private:
	BigNumber* clsNum;

};
#endif

