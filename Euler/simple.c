
// Euler problem 3
long long int largestPrimeFactor (long long int n)
{
	long long int i;
	long long int largest = 1;
	long long int currentFactor = n;
		
	for (i = 2; i <= currentFactor; i++)
	{
		while (currentFactor % i == 0)
		{
			// printf ("debug... factor discovered. currentFactor = %lli, i = %lli. \n", currentFactor, i);
			largest = i;
			currentFactor = currentFactor/i;

		}
	}	
 
	return largest;

}

// Euler problem 2
int fibEvenSum (int upper)
{
	
	int sum = 0;
	int first = 1;
	int second = 1;

	while (second + first < upper)
	{
	
		first += second;
		second += first;

		if (first % 2 == 0)
			sum += first;

		if (second % 2 == 0 && second < upper)
			sum += second;
		
	}

	return sum;

}

// Euler Problem 1
int sumOfMultiples (int upper, int fac1, int fac2)
{

	int sum = 0;
	int n = 0;
	int smaller; 
	if (fac1 < fac2)
		smaller = fac1;
	else
		smaller = fac2;

	for (n = 1; n*smaller < upper; n++)
	{

		// Add the multiples of 3
		if (n*fac1 < upper) 
			sum += n*fac1;

		// Add the multiples of 5
		if (n*fac2 < upper) 
			sum += n*fac2;

		// Subtract the multiples of 15
		// Otherwise they will be counted twice
		if (n*fac1*fac2 < upper) 
			sum -= n*fac1*fac2;

	}

	return sum;

}

// Euler problem 6
int sumSquareDifference(int max)
{
	int sum = 0;
	int squareSum = 0;
	int i;
	for (i = 1; i <= max; i++)
	{
		sum += i;
		squareSum += i*i;
	}

	return ((sum*sum) - squareSum);

}
