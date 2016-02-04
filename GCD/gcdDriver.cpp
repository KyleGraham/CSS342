//Kyle Graham
//Program 2
#include <iostream>
#include <tuple>
#include <sys/time.h>
#include <stdio.h>
int gettimeofday( struct timeval *tv, struct timezone *tz );
using namespace std;
tuple<int,int> euclidean(int a, int b);
int main()
{
	struct timeval tv_begin;
	struct timeval tv_end;
	long double miliseconds;
	long double totalTime;
	int seconds;
	time_t curtime;
	char input = 'y';
	while(input == 'y')
	{
		int n = 0;
		int maxCounter = 0;
		int max = 0;
		int max2 = 0;
		cout << "Enter number greater than 8" << endl << "n = ";
		cin >> n;
		gettimeofday(&tv_begin, NULL);
		int gcd = 0;
		for(int i = 8; i <= n; i++)
		{
			for(int j = 1; j < i; j++)
			{ 
				for(int k = 1; k <= i; k++)
				{
					int counter = 0;
					tie(gcd, counter) = euclidean(j, k);
					if(counter > maxCounter)
					{
						maxCounter = counter;
						max = j;
						max2 = k;
					}
				}
			}
			//assumption made, time given in miliseconds
			gettimeofday(&tv_end, NULL);
			miliseconds=((tv_end.tv_sec-tv_begin.tv_sec) * 1000.0);
			miliseconds += ((tv_end.tv_usec-tv_begin.tv_usec)/1000.0);
			gettimeofday(&tv_begin, NULL);
			totalTime += miliseconds;
			cout <<"At i=" << i << "; gcd (" << max << "," << max2 << ") = " << gcd  << ", took " 
						<< maxCounter << " modulus operations. Run time in miliseconds = " << totalTime <<  endl;
			maxCounter = 0;
			max = 0;
			max2 = 0;
		}
	cout << totalTime << "miliseconds of operation time";
	cout << endl << "Run again?" << endl;
	totalTime = 0.0;
	cin >> input;
	}
	cin.get();
	cin.get();
	return EXIT_SUCCESS;
}
//tuple<int,int> euclidean(int a, int b)
//finds the GCD, returns GCD and a counter of how many
//modulus operations it took to complete
tuple<int,int> euclidean(int a, int b)
{
	int counter = 0;
	int temp = 0;
	if(a < b)
        {
			temp = a;
			a = b;
			b = temp;
        }
	while(b != 0)
	{
		temp = a % b;
		a = b;
        b = temp;
		counter++;
	}
	return make_tuple(a, counter);
}