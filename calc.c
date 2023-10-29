#include "calc.h"

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        return 0;  // 예외 처리: 0으로 나누기 방지
    }
    return a / b;
}
