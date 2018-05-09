#include <iostream>
#include <vector>
using namespace std;

bool IsPrime(int n);
vector<int> PrimeFactors(int n);
vector<int> getSequence(int below);
vector<int> getDivisiors(int num);
    
int main(int argc, char** argv) {
	vector<int> seq;
	seq =  getSequence(999999999);
	
	for(vector<int>::iterator it = seq.begin(); it != seq.end(); ++it)
	{
		cout << "Trying " << *it << endl;
		
		if(getDivisiors(*it).size() > 500)
		{
			cout << *it << endl;		
			break;
		}
	}
	
	return 0;
}

vector<int> getSequence(int below)
{
	vector<int> vec;
	int j = 2;
	
	for(int i = 1 ; i <= below ;i+=j , j++ )
		vec.push_back(i);
	
	return vec;
}

/*
Get Divisors of num
*/
vector<int> getDivisiors(int num)
{
	vector<int> vec;
	for(int i = 1 ; i <= num ; i++)
	{
		if(num%i == 0 )
			vec.push_back(i);
	}
	
	return vec;
}

/*
Check if number n is prime or not.
*/
bool IsPrime(int n){
    for (int i = 2; i <= n; i++)
    {
    	if (n % i == 0)
        {
            if (i == n)
                return true;
            else
               return false;
        }
    }
    return false;
}

/*
Get the prime factors of specific integer n.
*/
vector<int> PrimeFactors(int n){
    vector<int> vec;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0 && IsPrime(i))
        {
            vec.push_back(i);
            n = n / i;
        }
    }
    return vec;
} 











