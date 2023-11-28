#include <stdio.h>
#include <stdbool.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate the size of U(k)
int calculateUSize(int k) {
    int count = 0;
    for (int i = 1; i < k; ++i) {
        if (gcd(i, k) == 1) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Given values of k
    int k_values[] = {18, 54, 162, 486, 50, 250, 98, 242};

    // Calculate and print the size of U(k) for each value
    for (int i = 0; i < sizeof(k_values) / sizeof(k_values[0]); ++i) {
        printf("Size of U(%d): %d\n", k_values[i], calculateUSize(k_values[i]));
    }

    return 0;
}
