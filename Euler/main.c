#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <stddef.h>
//#include <ctype.h>
//#include <time.h>

// EULER Problems 1-3
int sumOfMultiples (int upper, int fac1, int fac2);
int fibEvenSum (int upper);
long long int largestPrimeFactor (long long int n);

// EULER Problems 4-6
int largestPalindromicProduct (void);
long long int smallestCommonMultiple(int max);
int sumSquareDifference(int max);

// EULER Problems 7-8
long long int primeSieve(int n);
int greatestProductConsecutiveDigits(char *digitString);

// EULER Problem 10
long long int sumOfPrimes(int limit);

// TESTS
void gcdTest(void);
void isdigitTest (int length);
int mypi(float x);

int main (void)
{

	int result;
	long long int bigResult;
	long long int bigInput;

	result = sumOfMultiples(1000, 3, 5);
	printf ( "Sum of multiples = %i \n", result);

	//result = fibEvenSum(4000000);
	//printf ( "Sum of even Fibonaccis = %i \n", result);

	bigInput = 600851475143;
	bigResult = largestPrimeFactor(bigInput);
	printf ( "Largest prime factor = %lli \n", bigResult);

	//result = largestPalindromicProduct();
	//printf ( "The largest palindromic product of two three digit numbers = %i \n", result);

	//bigResult = smallestCommonMultiple(20);
	//printf ( "The smallest common multiple of the numbers 1..20 = %lli \n", bigResult);

	//result = sumSquareDifference(100);
	//printf ( "The difference = %i \n", result);  // between the sum of the squares of the first 100 natural numbers and the square of their sum

	//bigResult = primeSieve(10001);
	//printf ( "The 10001st prime = %lli \n", bigResult);

	//char digits[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450a";

	//result = greatestProductConsecutiveDigits(digits);
	//printf ( "The greatest product of five consecutive digits = %i \n", result);

//	result = _pi((float) 2000000);
//	printf("The number of primes less than or equal to 2000000 is less than %i \n", result);
	bigResult = sumOfPrimes(2000000);
	printf ( "The sum of all primes less than 2 million = %lli \n", bigResult);

	// isdigitTest(100);
	// gcdTest();

	return 0;

}
