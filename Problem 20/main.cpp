#include <iostream>
#include "BigNumber.h"
using namespace std ;

int getInt(char c)
{
	switch(c)
		{
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		default:
			return -1 ;
			break;
		}
}

int main(){


	Factorial m(100);
	cout << m.getValue() << endl;
	
	char* szBuffer = "9332621544394415268169923885626670049071596826438162146859296389521759999322991560894146397615651828625369792082722375825118521091686400000000000000000000000000\n";
	int iLen = strlen(szBuffer);
	int sum = 0 ;

	for(int i = 0 ; i < iLen ; i++){	
		if(isdigit(szBuffer[i]))
		{
			int tmp = getInt(szBuffer[i]);
			sum+= tmp ; 
		}
	}

	cout << "Sum "  << sum << endl ;

 	system("pause");
	return 0 ;
}
