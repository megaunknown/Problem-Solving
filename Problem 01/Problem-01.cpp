#include <iostream>
using namespace std;

int main()
{
	int sum = 0 ;
	for( int num = 1 ; num < 1000 ; num++)
	{
		if( (num % 3 == 0 )|| (num % 5 == 0))
			sum += num ;
	}
	cout << sum << endl;
	return 0 ;
}
