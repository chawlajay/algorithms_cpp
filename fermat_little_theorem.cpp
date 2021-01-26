// link - https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
// Fermat’s little theorem and modular inverse 
//  Fermat’s little theorem states that if p is a prime number, then for any integer a, the number ap – a is an integer multiple of p. In the notation of modular arithmetic, this is expressed as: 
//  ap = a (mod p) 
//  For example, if a = 2 and p = 7, 27 = 128, and 128 – 2 = 7 × 18 is an integer multiple of 7.
//  If a is not divisible by p, Fermat’s little theorem is equivalent to the statement a p – 1 – 1 is an integer multiple of p, i.e 
//  ap-1 = 1 (mod p)
//  If we multiply both sides by a-1, we get. 
//  ap-2 = a-1 (mod p)
//  So we can find modular inverse as p-2. 

// A modular inverse based solution to
// compute nCr % p
#include <bits/stdc++.h>
using namespace std;

/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x, 
								int y, int p)
{
	unsigned long long res = 1; // Initialize result

	x = x % p; // Update x if it is more than or
	// equal to p

	while (y > 0) 
	{
	
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
	return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little theorem.
unsigned long long nCrModPFermat(unsigned long long n,int r, int p)
{
	// If n<r, then nCr should return 0
	if (n < r) return 0;
	// Base case
	if (r == 0) return 1;

	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;
}

int main()
{
	// p must be a prime greater than n.
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "<< nCrModPFermat(n, r, p);
	return 0;
}
