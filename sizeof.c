#include <stdio.h>

int main() {
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of char string: %zu bytes\n", sizeof(char[50]));
    printf("Size of char array: %zu bytes\n", sizeof(int[50]));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    return 0;
}