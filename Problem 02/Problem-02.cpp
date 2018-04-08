#include <stdio.h>
#include <iostream>
using namespace std;

unsigned long int fiboIterative(int nTrm)
{
	if(nTrm == 0 )
		return 0 ;
			
	int firstTrm = 1 , secondTrm = 2 ;
	unsigned long int nTrmValue = 0 ;
	
	if(nTrm == 1)
		nTrmValue = 1; 
	else if(nTrm == 2)
		nTrmValue = 2;
	else
	{
		int i = 0 ;
		
		for( i = 1 ; i <= nTrm ; i++)
		{
			nTrmValue = firstTrm + secondTrm ; 
			firstTrm = secondTrm ;
			secondTrm = nTrmValue ;
		}
	}
	return nTrmValue ; 
}

int main(int argc,char* argv[])
{
	unsigned long int lSum = 0,lValue ;
	int iCounter = 0 ;
	
	while( lValue < 4000000)
	{
		if(lValue%2 == 0)
			lSum = lSum+lValue ;
		iCounter++ ;
		
		lValue = fiboIterative(iCounter);	
		
	}
	
	printf("The summation value is :%lu\n\n",lSum);

	//Answer: 4613732
	return 0 ;	
}


