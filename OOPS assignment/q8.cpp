// #include <iostream>
// using namespace std;

// class A {
// private:
//     int *ptr;

// public:
//     A(int *p) { ptr = p; }
    
//     ~A() { delete[] ptr; }

//     // Copy constructor
//     A(const A &obj) {
//         ptr = new int[10];
//         for (int i = 0; i < 10; i++)
//             ptr[i] = obj.ptr[i];
//     }
//     void showData() {
//         for (int i = 0; i < 10; i++)
//             cout << ptr[i] << " ";
//         cout << endl;
//     }
// };

// int main() {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     A obj1(arr);

//     // Deep copy of obj1 using copy constructor
//     A obj2 = obj1;
//     cout << "Elements of obj1: ";
//     obj1.showData();
//     cout << "Elements of obj2: ";
//     obj2.showData();
//     return 0;
// }





// #include <iostream>
// #include <cstring>

// class MyClass {
// public:
//     // Default constructor
//     MyClass() {
//         data = nullptr;
//     }

//     // Parameterized constructor
//     MyClass(const char* str) {
//         data = new char[strlen(str) + 1];
//         strcpy(data, str);
//     }

//     // Copy constructor
//     MyClass(const MyClass &other) {
//         // Allocate memory for the copy
//         data = new char[strlen(other.data) + 1];
        
//         // Copy the content from the other object
//         strcpy(data, other.data);
//     }

//     // Destructor
//     ~MyClass() {
//         delete[] data;
//     }

//     // Function to display data
//     void display() {
//         std::cout << "Data: " << data << std::endl;
//     }

// private:
//     char* data;
// };

// int main() {
//     // Creating an object using the parameterized constructor
//     MyClass obj1("Hello");

//     // Using the copy constructor to create obj2 as a copy of obj1
//     MyClass obj2 = obj1;

//     // Displaying the content of both objects
//     std::cout << "Object 1: ";
//     obj1.display();

//     std::cout << "Object 2: ";
//     obj2.display();

//     return 0;
// }




#include<iostream>
using namespace std;

class A{
    public:
    int a;
    *ptr=NULL;

    A(int a){
        cout<<"enter the value of a"<<endl;
        cin>>a;
    }

    // A(int a){
    //     cout<<"copy constructor"<<endl;
    //     *ptr=a;
    //     cout<<*ptr<<endl;
    // }
};

int main(){

    A obj;
    // A obj2;
    
    obj.A(2);


}