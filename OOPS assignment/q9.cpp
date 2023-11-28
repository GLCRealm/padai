// #include<iostream>
// using namespace std;

// class A{
//     public:

// };

// class B{
//     public:

// };

// int main(){
    
// }

#include<iostream>
using namespace std;

class A {

public:
    A(int age) {
        this->age = age;
    }
    int getAge() {
        return age;
    }
    A operator+(const A& other) {
        A newPerson(age + other.age);
        return newPerson;
    }

private:
    int age;
};

int main() {
    A person1(20);
    A person2(30);
    A person3 = person1 + person2;
    cout << person3.getAge() << endl;
    return 0;
}
