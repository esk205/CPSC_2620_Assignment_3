// ********************************************************************
// CPSC2620 Spring 2016
// File Name: seqTest.cc
// Purpose: Client file for the geometricSequence program
// Created on: Feb 9, 2016
// Author: Michael Wynnychuk
// Notes:
// ********************************************************************
// preprocessor directives
#include <iostream>
#include "geometricSequence2.h"         // class definition for this class
using namespace std;

// Reads in the characteristics of three geometric sequences A, B, and C
// Sets D to be the same geometric sequence as A except that r is negative
// Computes and displays the following results
// The product of A + B
// The sum of A  C
// (A + D)  C
// A with n * 2
// B with a + 3
// C with r * 3

int main()
{
   geometricSequence A,B,C; // Create three geometric sequences
   int a, r, n; // characteristics of a geometric sequence
   cout << endl << "Enter geometric sequence characteristics: ";
   A.read(); // Read in values and generate sequence
   cout << "Sequence A: ";
   A.write(); // Display sequence
  
   cout << endl << "Enter geometric sequence characteristics: ";
   B.read(); // Read in values and generate sequence
   cout << "Sequence B: ";
   B.write(); // Display sequence

   cout << endl << "Enter geometric sequence characteristics: ";
   C.read(); // Read in values and generate sequence
   cout << "Sequence C: ";
   C.write(); // Display sequence
   cout << endl;
      
   A.getCharacteristics(a, r, n); // Retrieve characteristics of sequence A for D
   geometricSequence D(a, -r, n); // Change r value to be negative
   cout << "Sequence D: ";  
   D.write(); // Display sequence
   cout << endl;

   A.add(B); // Product of A += B
   cout << endl << "Product of (A + B): " << A.product() << endl; // Product of A 
  
   A.multiply(C); // The sum of A x C
   cout << "Sum of (A X C): " << A.sum() << endl; // Product of A 
   A.setA(a); // Resets sequence A with a
   A.setR(r); // Resets sequence A with r
   A.setN(n); // Resets sequence A with n

   A.add(D); // (A + D)
   A.multiply(C); // (A + D) * C
   
   cout << "C * (A + D): ";
   A.write(); // Display sequence of C * (A+D) 
   cout << endl; 

   A.setN(n*2); // A with 2 times value of 'n'
   cout << "A with n*2: "; 
   A.write(); // Display sequence 

   B.getCharacteristics(a,r,n); // Retrieve sequence characteristics 
   B.setA(a + 2); // Add 2 to the 'a' value of sequence B 
   cout << endl << "B with a+2: ";
   B.write();// Display sequence 

   C.getCharacteristics(a,r,n); // Retrieve sequence characteristics
   C.setR(r * 3); // Multiply 'r' value by 3 for sequence C
   cout << endl << "C with r*3: ";
   C.write(); // Display sequence 
   cout << endl;
   return 0;
}

