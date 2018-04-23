#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
Problem 14 (Collatz Problem)
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain->

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

static int counter = 1 ;
int prodSer(int iStart)
{
	
	if(iStart == 1 )
	{
		return counter;
	}
	else
	{
		if(counter == 1)
			cout << iStart << "->" ;

		counter++;
		//even
		if(iStart%2 == 0){
			cout << iStart/2 << "->" ;
			return prodSer(iStart/2);
		}//odd
		else{
			cout << (3*iStart)+1 << "->" ;
			return prodSer((3*iStart)+1);
		}
	

	}
}


//refined version...
unsigned int Problem14(unsigned long iStart)
{
	static unsigned int counter = 1 ;

	if(iStart == 1 )
	{
		int tmp = counter ;
		counter = 1 ;
		return tmp;
	}
	else if(iStart > 1)
	{
		//Sleep(500);
		counter++;

		
		if(iStart%2 == 0)
		{
			return Problem14(iStart/2); //even
		}
		else
		{
			return Problem14((3*iStart)+1);	//odd
		}
	}
	else
	{
		cout << "NOT COLLATIZ NUMBER\n";
		return -1;
	}
}

int main()
{

	int max = 0 ;
	int v = 0 ; 
	int num = 0 ;
	
	for(int i=1 ; i <= 1000000 ; i++)
	{
		v = Problem14(i);
	//	cout << "Number of terms for " << i << " is ::" << v << endl;

		if(v > max)
		{
			max =  v ; 
			num = i ;
		}
		//sleep(500);
	}
	
	cout << "MAX ::" << max << ", via number ::" << num << endl;
		
	//837799
	return 0;	
}
