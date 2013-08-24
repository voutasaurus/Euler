#include <stdbool.h>
#include <math.h>
#include <stdio.h>

// Euler problem 7
// Just a prime sieve
long long int primeSieve(int n) // Returns the nth prime
{

	long long int primes[n];
	bool prime = true;

	// Initialise first prime
	long long int m = 2;
	int i = 0;

	primes[i] = m;
	i++;

	while (i < n)
	{
		m++;
		prime = true;

		for (int j = 0; j < i; j++)
		{
//			printf("Prime number %i is %lli \n", j, primes[j]);
			if (m % primes[j] == 0)
			{
				prime = false;
				j = i + 1; // composite number - exit for loop
//				printf("Composite is %lli \n", m);
			}
		}
		
		if (prime) // if no prime factors
		{
			primes[i] = m;

			//printf("Prime number %i is %lli \n", i, primes[i]);

			i++;
		}

//		
//		printf("debug... n = %i, i = %i, m = %lli \n", n, i, m);

	}

	return m;

}

// Upper bound on the number of primes less than or equal to x
int mypi(float x)
{
	if (x > 598)
		return  (int) ( x / log(x) )*(1 + ( 1.2762 / log(x) ) );
	else
		return 150;
}

// Euler problem 10
long long int sumOfPrimes(int limit)
{
	int primes[mypi((float) limit)];
	bool prime = true;
	long long int sumPrimes = 2;

	// Initialise first prime
	int m = 2;
	int i = 0; // = 0;

	sumPrimes = 2;
	primes[i] = m;
	i = 1;

	while (m < limit)
	{
		m++;
		prime = true;

		for (int j = 0; j < i; j++)
		{
//			printf("Prime number %i is %lli \n", j, primes[j]);
			if (m % primes[j] == 0)
			{
				prime = false;
				j = i + 1; // composite number - exit for loop
//				printf("Composite is %lli \n", m);
			}
		}
		
		if (prime) // if no prime factors
		{
			sumPrimes += m;
			primes[i] = m;
			//printf("Prime number %i is %lli \n", i, primes[i]);
			i++;
		}

//		
//		printf("debug... n = %i, i = %i, m = %lli \n", n, i, m);

	}

	return sumPrimes;

}
