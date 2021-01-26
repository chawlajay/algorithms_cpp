// Basic Euclidean Algorithm - to find GCD
// Extended Euclidean algorithm also finds integer coefficients x and y such that: ax + by = gcd(a, b) 

// link - https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// Function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
 
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
 
    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
 
    return gcd; 
} 

// Driver Code
int main()
{
	int a = 10, b = 15;
	cout<<GCD(a,b)<<"\n";
  a = 35, b = 15; 
  
  int g = gcdExtended(a, b, &x, &y); 
  cout << "GCD(" << a << ", " << b << ") = " << g << endl;
	return 0;
}

