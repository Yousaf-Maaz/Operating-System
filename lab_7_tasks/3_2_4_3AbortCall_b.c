#include <stdio.h>
#include <stdlib.h>

void f3() {
    abort();  // Program will terminate here
}

void f1() {
    printf("Function f1 called\n");
}

void f2() {
    printf("Function f2 called\n");
}

int main() {
    atexit(f1);  // Register f1 to be called on exit
    atexit(f2);  // Register f2 to be called on exit
    f3();        // Call f3 which has abort()
    exit(0);
}
