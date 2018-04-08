#include <iostream>
#include <math.h>
using namespace std;
	
int main(int argc,char* argv[])
{

	for(int i = 1 ; i < 99999999999999 ; i++ )
	{
		if( i%2 == 0  && i%3 == 0 && i%5 == 0 && i%7 == 0&& i%8 == 0 && i%9 == 0 && i%10 == 0 &&i%11 == 0  && i%12 == 0 && i%13 == 0 && i%14 == 0&& i%15 == 0 && i%16 == 0 && i%17 == 0  && i%18 == 0&& i%19 == 0 && i%20 == 0 )
		{
			cout << i << endl;
			break;	
		}
	}
	
	// Ans : 232792560
	return 0;
	
}
