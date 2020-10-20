/*
Name - Sarnav Dutta
College - Techno India Saltlake
*/

// C++ program to check if the 
// given number is prime using 
// Wheel Factorization Method 
#include "bits/stdc++.h" 
using namespace std; 

// Function to check if a given 
// number x is prime or not 
void isPrime(int N) 
{ 
	bool isPrime = true; 
	// The Wheel for checking 
	// prime number 
	int arr[8] = { 7, 11, 13, 17, 
				19, 23, 29, 31 }; 

	// Base Case 
	if (N < 2) { 
		isPrime = false; 
	} 

	// Check for the number taken 
	// as basis 
	if (N % 2 == 0 || N % 3 == 0 
		|| N % 5 == 0) { 
		isPrime = false; 
	} 

	// Check for Wheel 
	// Here i, acts as the layer 
	// of the wheel 
	for (int i = 0; i < sqrt(N); i += 30) { 

		// Check for the list of 
		// Sieve in arr[] 
		for (int c : arr) { 

			// If number is greater 
			// than sqrt(N) break 
			if (c > sqrt(N)) { 
				break; 
			} 

			// Check if N is a multiple 
			// of prime number in the 
			// wheel 
			else { 
				if (N % (c + i) == 0) { 
					isPrime = false; 
					break; 
				} 
			} 

			// If at any iteration 
			// isPrime is false, 
			// break from the loop 
			if (!isPrime) 
				break; 
		} 
	} 

	if (isPrime) 
		cout << "Prime Number"; 
	else
		cout << "Not a Prime Number"; 
} 

// Driver's Code 
int main() 
{ 
	int N = 121; 

	// Function call for primality 
	// check 
	isPrime(N); 
	return 0; 
} 


/*
Name - Sarnav Dutta
College - Techno India Saltlake
*/