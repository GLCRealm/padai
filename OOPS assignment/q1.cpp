#include <iostream>
//First namespace

namespace First {
int value = 10;
void printValue() {
    std::cout << "First::value = " << value << std::endl;
}
} 

//Second namespace
namespace Second {
int value = 20;
void printValue() {
    std::cout << "Second::value = " << value << std::endl;
}
}   

// Main function
int main() {
    First::printValue();
    Second::printValue();
    return 0;
}
