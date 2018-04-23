#include <iostream>
using namespace std;

/*
Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/

int divs[100];
bool d(int a);

void setArrZeros(int a[],int size){
	for(int i = 0 ; i < size ; i++)
		a[i] = 0 ;
}

void viewArr(int a[],int size){
	for(int i = 0 ; i < size ; i++){
		if(a[i] > 0 )
			cout << a[i] << "\t" ; 
	}
}

int arrSum(int a[],int size)
{
	int iSum = 0 ;
	for(int i = 0 ; i < size ; i++)
	{
		if( a[i] > 0 )
			iSum+=a[i];
	}
	return iSum ;
}

void getNumDivisors(int num)
{
	//set array to zeros
	setArrZeros(divs,100);

	int iArrIndex = 0 ;

	for(int i = 1 ; i < num ; i++)
	{
		float m_Tmp = num/i ;
		if(m_Tmp * i == num)
		{
			divs[iArrIndex] = i ;
			iArrIndex++;
		}
	}
}


int main(int argc, char* argv[])
{
	int iSum = 0 ;
	for( int i  = 1 ; i < 10000 ; i++)
	{
		if(d(i))
		{
			iSum+=i;
		}
	}
	cout <<iSum ;

	//Solution = 31626
}


bool d(int a)// =b
{
	bool bRet = false ;

	int iaResult = 0 ;
	getNumDivisors(a);
	iaResult =  arrSum(::divs,100);	//=b

	if(iaResult != a)
	{
		int ibResult = 0 ;
		getNumDivisors(iaResult);
		ibResult =  arrSum(::divs,100);	//=b

		if (a == ibResult)
			bRet = true ;
	}
	
	return bRet ;
}
