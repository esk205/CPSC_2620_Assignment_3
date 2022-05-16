// ********************************************************************
// CPSC2620 Spring 2016
// File Name: geometricSequence2.h
// Purpose: Defines geometricSequence class
// Created on: Feb 18, 2016
// Author: Michael Wynnychuk
// ********************************************************************

#ifndef GEOMETRICSEQUENCE2_H
#define GEOMETRICSEQUENCE2_H
using namespace std;
// * Use const class-name& object to
//   specify that formal parameter object cannot be changed by the
//   functions execution.
// * Accessor methods should be declared const 
template<typename T>
class geometricSequence{
  public: // public data members
	// default constructor
    geometricSequence (T = 1,T = 1,int = 1); // sets a, r, n all to 1
	friend ostream& operator<<(ostream&, const geometricSequence& );
	friend istream& operator>>(istream&, geometricSequence&);
	// Destructor
    ~geometricSequence(); // deletes gs in array and points array to nullptr (0).

   //Copy constructor
  // geometricSequence(const geometricSequence&);
   //geometricSequence& operator=(geometricSequence&); // assignment operator

   int& operator[](int); // access operator
   int& operator[](int) const; // access 

   geometricSequence& operator*=(geometricSequence&); // compound assignment operator
   geometricSequence& operator+=(geometricSequence&); // compound assignment operator
   geometricSequence& operator+(geometricSequence&); // arithmetic operator
   geometricSequence& operator*(geometricSequence&); // arithmetic operator
 
  // set methods (Modifier methods) Definition: Changes values
  // void setA(int); // changes the value of a
  // void setR(int); // changes the value of r
  // void setN(int); // changes the value of n
   
  // get methods (Accessor methods) Definition: Retrieves values.
  // void getCharacteristics(int &a, int &r, int &n) const; // Retrieve characteristic of sequence

  private:  // private data members
   int a; // the 'a' characteristic of the sequence
   int r; // the 'r' characteristic of the sequence
   int n; // the 'n' characteristic of the sequence
   int* arrays = new int[n]; // array that holds the terms for sequence
   void generateValues(); // generate sequence terms for array 
};
#endif
