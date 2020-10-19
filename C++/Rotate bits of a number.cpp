#include<bits/stdc++.h>
using namespace std;
#define INT_BITS 32 
class solution 
{ 
	
public: 
int leftRotation(int number, unsigned int rotate_bits) 
{ 
	return (number << rotate_bits)|(number >> (INT_BITS - rotate_bits)); 
} 

int rightRotation(int number, unsigned int rotate_bits) 
{ 
	return (number >> rotate_bits)|(number << (INT_BITS - rotate_bits)); 
} 
}; 

int main() 
{ 
	solution sol; 
	int number;
	cin >> number;
	int rotate_bits;
	cin >> rotate_bits;	
	cout << "Left Rotation of " << number << " by " << rotate_bits << " is "; 
	cout << sol.leftRotation(number, rotate_bits); 
	cout << "\nRight Rotation of " << number << " by " << rotate_bits << " is "; 
	cout << sol.rightRotation(number, rotate_bits); 
	getchar(); 
} 
