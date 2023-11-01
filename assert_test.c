/* 
 * 5장 디버깅과 오류 처리
 * 파일 이름: assert_test.c 
 */ 

#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 

void my_assert(const char *expr_str) {
    fprintf(stderr, "Assertion failed: %s\n", expr_str);
    abort();
}

void foo(int num) 
{ 
    assert( ((num >= 0) && (num <= 100)) ); 

    printf("foo: num = %d\n", num); 
} 

int main(int argc, char *argv[]) 
{ 
    int num; 

    if (argc < 2) { 
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1); 
    } 

    num = atoi(argv[1]); 
    foo(num); 
}
