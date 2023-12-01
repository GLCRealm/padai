#include <iostream>
using namespace std;

inline int factorial(int a) {
  if (a<=1) {
    return 1;
  } else {
    return a * factorial(a - 1);
  }
}

int main() {
  cout<<factorial(5)<<endl;
}