// ********************************************************************
// CPSC2620 Spring 2016
// File Name: seqTest2.cc
// Purpose: Client file for the geometricSequence program
// Created on: Feb 18, 2016
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
   geometricSequence A,B; // Create three geometric sequences
   //int a, r, n, i; // characteristics of a geometric sequence and index 
   cout << endl << "Enter geometric sequence characteristics: ";
   cin >> A;
   cout << "Sequence A: ";
   cout << A;
     
   cout << endl << "Enter geometric sequence characteristics: ";
   cin >> B;
   cout << "Sequence B: ";
   cout << B;
 
   cout << endl << "The A+=B = " << (A += B) << endl;
  // cout << endl << "(A + D) x C = ";

   /*
   A.setN(n * 2); // A with 2 times value of 'n'
   cout << "A with n*2: ";
  // A.write(); // Display sequence 

   B.getCharacteristics(a, r, n); // Retrieve sequence characteristics 
   B.setA(a + 2); // Add 2 to the 'a' value of sequence B 
   cout << endl << "B with a+2: ";
  // B.write();// Display sequence 

   C.getCharacteristics(a, r, n); // Retrieve sequence characteristics
   C.setR(r * 3); // Multiply 'r' value by 3 for sequence C
   cout << endl << "C with r*3: ";
  // C.write(); // Display sequence 
   */
   return 0;
}

