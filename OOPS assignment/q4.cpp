 #include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;

  cout << "Enter the first string: ";
  cin >> a;
  cout << "Enter the second string: ";
  cin >> b;

  // find the common characters in both the strings
  string common;
  for (char c : a) {
    if (b.find(c) != string::npos) {
      common += c;
    }
  }
  // print the common characters
  cout << "The common characters in both the strings are: " << common << endl;
  return 0;
}
