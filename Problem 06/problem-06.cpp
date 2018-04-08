#include <iostream>
#include <math.h>
using namespace std;

int diff()
{
	int n = 100 ;
	int sumOfSquares = 0 ;
	int SquaresOfsum = 0 ;


	while(n > 0 )
	{
		sumOfSquares += pow(n,2) ;
		SquaresOfsum+=n ;
		n--;
	}
	SquaresOfsum = pow(SquaresOfsum,2);

	return SquaresOfsum - sumOfSquares ;
}

int main(int argc, char* argv[])
{
	cout << diff() << endl;
	
	//Ans : 25164150
	return 0;
}
