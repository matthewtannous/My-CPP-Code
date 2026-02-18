// How to take input and print using C syntax

// #include <iostream> // also works for scanf and printf

#include <cstdio>

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;

    // Read
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);

    // print
    printf("%d\n%ld\n%c\n%f\n%lf\n", a, b, c, d, e);
}