#include <stdio.h>
#include <stdbool.h>
#include <string.h>


char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

bool palindromic (int n)
{
	char str[15];
	char rev[15];

	sprintf(str, "%d", n);
	strcpy(rev, str);
	strrev(rev);

	return (strcmp(rev, str) == 0);
}

// Euler problem 4
int largestPalindromicProduct (void)
{
	int left;
	int right;

	int largeLeft = 0;
	int largeRight = 0;

	int largestPalindrome = 10000;


	// int debugProduct;

	//
	for (left = 999; left >= 100; left--)
	{
		for (right = 999; right >= left; right--)
		{
			if (palindromic(left*right))
			{

				largestPalindrome = left*right;
				largeLeft = left;			
				largeRight = right;	
				// printf("debug... left: %i, right: %i, palindrome: %i \n", largeLeft, largeRight, largestPalindrome);

				for (int loff = 1; loff <= 998-largeRight; loff++)
				{
					for (int roff = 0; roff <= 999-largeRight-loff; roff++)
					{
						left = largeLeft - loff;
						right = 999 - roff;

						//printf("debug inner... left offset: %i, right offset: %i \n", loff, roff);

						if (palindromic(left*right) && left*right > largestPalindrome)
						{
							largestPalindrome = left*right;
							largeLeft = left;			
							largeRight = right;						
							// printf("debug... left: %i, right: %i, palindrome: %i \n", largeLeft, largeRight, largestPalindrome);
							
							// Reset the loop - look for more palindromes
							loff = 1;
							roff = 0;
						}
					}
					// debugProduct = left*right;
					// printf("debug inner... left: %i, right: %i, product: %i \n", left, right, debugProduct);
				}

			return largestPalindrome;

			}
		}
	} 
	
	return 1;

}
