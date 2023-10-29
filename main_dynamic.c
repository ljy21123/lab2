#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "라이브러리 여는 중 오류: %s\n", dlerror());
        return 1;
    }

    float (*add)(float, float) = dlsym(handle, "add");
    float (*subtract)(float, float) = dlsym(handle, "subtract");
    float (*multiply)(float, float) = dlsym(handle, "multiply");
    float (*divide)(float, float) = dlsym(handle, "divide");

    float a = 10.0;
    float b = 5.0;

    printf("Add: %f\n", add(a, b));
    printf("Subtract: %f\n", subtract(a, b));
    printf("Multiply: %f\n", multiply(a, b));
    printf("Divide: %f\n", divide(a, b));

    dlclose(handle);

    return 0;
}
