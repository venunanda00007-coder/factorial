#include <stdio.h>
#include <limits.h> // for LLONG_MAX if needed

unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // indicate invalid input
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        // Detect overflow
        if (result > ULLONG_MAX / i) {
            return 0; // overflow occurred
        }
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error! Factorial does not exist for negative numbers.\n");
    } else {
        unsigned long long fact = factorial(num);
        if (fact == 0 && num != 0) { // zero indicates error or overflow
            printf("Error! Result too large to be represented.\n");
        } else {
            printf("Factorial of %d is %llu\n", num, fact);
        }
    }

    return 0;
}
