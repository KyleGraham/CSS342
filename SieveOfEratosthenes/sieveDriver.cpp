//Kyle Graham
//Lab 2
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

int sieve(int n, vector<int> &primes)
{
	int cost = 0;
	bool array[n + 1];
// 1. Implement array initialization so that every value is prime except 0 and 1
	for(int i = 2; i <= n; i++)
	{
		array[i] = true;
	}
	for(int i = 2; i <= sqrt(n); i++)
	{
		for(int j = pow(i, 2); j <= n; j += i)
		{
			array[j] = false;
			cost++;
		}

	}
	for(int i = 1; i <= n; i++)
	{
		if(array[i] == true)
			primes.push_back(i);

	}

// 2. Implement Sieve of Eratosthenes algorithm to find prime numbers
// Add cost whenever the array becomes to prime

// 3. Push back the prime numbers into primes (parameter)
	return cost;
}
int main() {
	int n = 0;
	ofstream writer;
	writer.open("output.txt");
	cout << "Enter n ";
	cin >> n;

	char printOption = 'n';
	cout << "print all primes (y|n)? ";
	cin >> printOption;
	for (int i = 2; i <= n; i++) 
	{

		vector<int> primes;
		int cost = sieve( i, primes );

		cout << "primes[1.." << i << "] took " << cost
		<< " sweeping operations" << endl;
		writer << i << "," << cost << endl;

		if ( printOption == 'y' ) 
		{
			cout << "all primes = ";
			for (int j = 0; j < primes.size(); j++ )
				cout << primes[j] << " ";
				cout << endl;

		}

		cerr << i << " " << cost << endl;


	}

	cin.get();
	cin.get();

}

 


 

 




