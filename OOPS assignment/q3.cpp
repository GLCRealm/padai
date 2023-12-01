#include <iostream>
using namespace std;

int main() {

    // 1-D array
    int arr1[] = {1, 2, 3, 4, 5};
    int *ptr1 = arr1;  // pointer pointing to the first element of arr1
    cout << "Elements of 1-D array using pointers:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(ptr1 + i) << " ";  // dereferencing the pointer to access the elements
    }

    cout << endl;

    // 2-D array
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *ptr2 = &arr2[0][0];  // pointer pointing to the first element of arr2
    int sum = 0;
    cout << "Sum of elements of 2-D array using pointers:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += *(ptr2 + i * 3 + j);  // dereferencing the pointer to access the elements
        }
    }
    
    cout << sum << endl;
    return 0;
}
