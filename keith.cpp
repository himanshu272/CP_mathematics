// C++ program to check if a number is Keith or not 

#include<bits/stdc++.h> 
using namespace std; 

// Returns true if x is Keith, else false. 
bool isKeith(int x) 
{ 
	// Store all digits of x in a vector "terms" 
	// Also find number of digits and store in "n". 
	vector <int> terms; 
	int temp = x, n = 0; // n is number of digits in x 
	while (temp > 0) 
	{ 
		terms.push_back(temp%10); 
		temp = temp/10; 
		n++; 
	} 

	// To get digits in right order (from MSB to 
	// LSB) 
	reverse(terms.begin(), terms.end()); 

	// Keep finding next trms of a sequence generated 
	// using digits of x until we either reach x or a 
	// number greate than x 
	int next_term = 0, i = n; 
	while (next_term < x) 
	{ 
		next_term = 0; 

		// Next term is sum of previous n terms 
		for (int j=1; j<=n; j++) 
			next_term += terms[i-j]; 

		terms.push_back(next_term); 
		i++; 
	} 

	/* When the control comes out of the while loop, 
	either the next_term is equal to the number 
	or greater than it. 
	If next_term is equal to x, then x is a 
	Keith number, else not */
	return (next_term == x); 
} 

// Driver program 
int main() 
{ 
isKeith(14)? cout << "Yes\n" : cout << "No\n"; 
isKeith(12)? cout << "Yes\n" : cout << "No\n"; 
isKeith(197)? cout << "Yes\n" : cout << "No\n"; 
return 0; 
} 
