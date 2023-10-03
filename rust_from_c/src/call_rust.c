#include <stdio.h>
extern int sum_from_rust(int, int);
extern void hello_from_rust();
// extern void print_from_rust(char*);

int main(void) {
    hello_from_rust();
    int sum = sum_from_rust(60, 1);
    printf("Added 60 and 1, got %d", sum);
    // print_from_rust("Hooray!");
    return 0;
}
