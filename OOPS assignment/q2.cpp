// Main.cpp - Main program

#include<iostream>
#include "HEDDER.h"

using namespace std;
using namespace world;

int main() {
    cout << "Accessing the variable from namespace: " << a << endl;
    method();

    return 0;
}

// g++ -c HEDDER.cpp   // Compile the implementation file
// g++ -c Main.cpp     // Compile the main file
// g++ HEDDER.o Main.o -o YourProgramName  // Link the object files into an executable
// ./YourProgramName 
