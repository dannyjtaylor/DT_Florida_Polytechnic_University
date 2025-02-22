#include <stdio.h>
//min function, return the smaller number between a and b
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else if (a == b) {
        return a;
    }
    else {
        return b;
    }
}
//max function, return the larger number between a and b
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else if (a == b) {
        return a;
    }
    else {
        return b;
    }
}
//gcd function
int gcd(int a, int b) {
    //base case, if minimum is 0, return max
    if (min(a, b) == 0) {
        return (max(a, b));
    }
    else {
        if (a >= b) {
            gcd(a - b, b);
        }
        else {
            gcd(a, b - a);
        }
    }
}
int main(void) {
    //compute gcd of 165 and 363
    int result0 = gcd(165, 363);
    //compute gcd of 48 and 180
    int result1 = gcd(48, 180);
    //compute gcd of 27 and 36
    int result2 = gcd(27, 36);
    //print results
    printf("gcd(165,363) is %d\ngcd(48,180) is %d\ngcd(27,36) is %d\n", result0, result1, result2);
    return 0;
}
/*
RULES:
Start with two positive numbers, A and B.

If min(A, B) == 0, GOTO step 5.

Subtract the smaller number from the larger number.

GOTO step 2.

The maximum of A and B is the GCD
*/