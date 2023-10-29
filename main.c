#include <stdio.h>
#include "calc.h"

int main() {
    float a = 10.0;
    float b = 5.0;

    printf("Add: %f\n", add(a, b));
    printf("Subtract: %f\n", subtract(a, b));
    printf("Multiply: %f\n", multiply(a, b));
    printf("Divide: %f\n", divide(a, b));

    return 0;
}
