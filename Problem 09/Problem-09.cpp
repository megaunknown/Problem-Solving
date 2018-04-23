#include <iostream>
#include <math.h>
using namespace std ;

/*
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

int main(int argc, char* argv[])
{
	int a=1,b=2,c=3 ;
	int product = 0 ;
	int limit = 500 ; 
//	while ( product != 1000)
//	{ 
		

	
		//Fix a,b and change in C
		for(a = 1 ; a < limit ; a++)
		{
			for( b = 2 ; b < limit ; b++)
			{
				for(c = 3 ; c < limit ; c++)
				{
					// Check the three terms...
						if(a < b &&  b < c)
						{
							if( pow(a,2) + pow(b,2) == pow(c,2))
							{
							//	cout << "Pythagorean triplet is " << a  << " " << b << " " << c << endl;
								
								product = a + b + c ;
								
								if(product == 1000)
								{
									cout << "Found..."  << endl;
									cout << "a = " << a << endl;
									cout << "b = " << b << endl;
									cout << "c = " << c << endl;

									cout << "The product is " << a * b * c << endl;
									break;
								}
							}

						}
				}
			}
	}

	//a = 200 , b = 375 , c = 425
	return 0;
}

