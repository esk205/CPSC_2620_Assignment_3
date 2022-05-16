// ********************************************************************
// CPSC2620 Spring 2016
// File Name: geometricSequence2.cc
// Purpose: Implementation of the geometric sequence class
// Created on: Feb 18, 2016
// Author: Michael Wynnychuk
// ********************************************************************
// preprocessor directives
#include <iostream>
#include "geometricSequence2.h" // class definition
#include <assert.h>
using namespace std;

//*********************************************************************
// A private helper function void generate() which generates the
// sequence described by the current values of the characteristics.
// Any previous values in the sequence are discarded.
//*********************************************************************
template<typename T>
geometricSequence<T>::geometricSequence(T A, T R, int N) { // Constructor
   a = A; 
   r = R;
   n = N;
   arrays = new int[n]; // Creates an arrays of integers
   generateValues();  // generates sequence terms and inserts into arrays.
}
void geometricSequence::generateValues() { // Generates sequence terms
	cout << endl << "Generating values" << endl;
	arrays[0] = a; // First term of the sequence is always the a value
	for (int i = 1; i < n; i++)
}

geometricSequence::~geometricSequence() { // Destructor
	cout << endl << "Destructor called" << endl;
	delete[] arrays;  // Deletes all elements in arrays
	arrays = NULL;
	n = 0;
} 
// Copy constructor
geometricSequence::geometricSequence(const geometricSequence &arrayToCopy) {
	cout << endl << "Copy Constructor";
	n = arrayToCopy.n;
	arrays = new int[n];
	for (int i = 0; i < n; i++) {
		arrays[i] = arrayToCopy.arrays[i];
	}
}
geometricSequence& geometricSequence::operator=(geometricSequence &otherArray) {
	cout << endl << "Assignment operator" << endl;
	 if (this != &otherArray){ // protect against invalid self-assignment    
		 delete[] arrays; // remove elements from the current array
		 n = otherArray.n; // resize this object
		 arrays = new int[n];  // create space for array copy  
        }
	 for (int i = 0; i < n; i++) {
		 arrays[i] = otherArray.arrays[i]; // copy array into object
	 }
        return *this;
}
int& geometricSequence::operator[](int i) {
	//assert (n <= i && n >= 0);
	return arrays[i];
}
int& geometricSequence::operator[](int i) const {
	//assert(n <= i && n >= 0);
	return arrays[i];
}
ostream& operator<<(ostream &out, const geometricSequence& arrays) {
	for (int i = 0; i < arrays.n; i++) { ///////////////////////////////
		out << arrays[i] << " "; // Displays the arrays terms
	}
	return out;	
}
istream& operator>>(istream &in, geometricSequence& arrays) {
	int x = 0, y = 0, z = 0; // declare secondary sequence characteristic variables
	in >> x >> y >> z; // Input sequence characteristics from user.
	arrays.a = x;
	arrays.r = y;
	arrays.n = z;
	arrays.generateValues();
	return in;
}
// Must be able to be used in a cascading expression.
// Geometric sequences WILL be changed by these operations (+= , *=).
geometricSequence& geometricSequence::operator*=(geometricSequence& mult) {
	//assert(n == mult.n && n >= 0); // ensure sequences are of equal length
	r = mult.r * r; // get new a value for geometric sequence
	a = mult.a * a; // get new r value for geometric sequence
	generateValues(); // generate terms of new sequence	
	return *this;
}
geometricSequence& geometricSequence::operator+=(geometricSequence& add) {
	//assert(n == add.n && n >= 0); // ensure sequences are of equal length
	r = add.r + r; // get new a value for geometric sequence setR
	a = add.a + a; // get new r value for geometric sequence setA
	cout << endl << "Added a: " << a << " " << "Added r: " << r << endl;
	generateValues(); // generate terms of new sequence
	return *this;
}
// Geometric sequences WILL NOT be changed by these operations (+ , *).
// Must be able to be used in a cascading expression.
geometricSequence& geometricSequence::operator+(geometricSequence& summation){
	//assert(n == summation.n && n >= 0); // ensure sequences are of equal length
	geometricSequence C{ *this };
	C += summation;
	C += *this;
	generateValues(); // generate terms of new sequence	
	cout << endl << "C.a = " << C.a << " " << "C.r = " << C.r << endl;
	return C;
}
geometricSequence& geometricSequence::operator*(geometricSequence& products) {
	//assert(n == products.n && n >= 0); // ensure sequences are of equal length
	geometricSequence C{ *this };
	r = products.r + r; // get new a value for geometric sequence setR
	a = products.a + a; // get new r value for geometric sequence setA
    C.generateValues(); // generate terms of new sequence
	cout << "a = " << a << " " << "r = " << r << endl;
	return C;
}
//////////////////////////////////////////////////////////////////////////////
void geometricSequence::getCharacteristics(int &x, int &y, int &z) const {
   x = a; // Retrieve a value
   y = r; // Retrieve r value
   z = n; // Retrieve n value
}
void geometricSequence::setA(int x) {
   a = x; // Changes a value
   generateValues(); // generates new sequence terms 
}
void geometricSequence::setR(int y) {
   r = y; // Changes r value
   generateValues(); // generates new sequence terms 
}
void geometricSequence::setN(int z) {
   n = z; // Changes n value
   generateValues();  // generates new sequence terms 
}
