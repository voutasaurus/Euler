#include <stdio.h>

long long int gcd(long long int m, long long int n)
{
	long long int r = m % n;

	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}

	return n;
}

long long int lcm(long long int m, long long int n)
{
	return (n*m)/gcd(m,n);
}

// Euler problem 5
long long int smallestCommonMultiple(int max)
{
	long long int multiple = 1;
	long long int i;
	for (i = 2; i<= max; i++)
	{
		if ( multiple % i != 0) 
			multiple = (multiple*i) / gcd(multiple, i);
		// printf("debug... i = %lli, multiple = %lli \n", i, multiple);
	}

	return multiple;
}

void gcdTest(void)
{
	long long int m, n;

	for (m = 10; m < 40; m++)
	{
		for (n = 10; n < m; n++)
		{
			printf("m = %lli, n = %lli, gcd(m,n)= %lli \n", m, n, gcd(m,n));
		}
	}
}
