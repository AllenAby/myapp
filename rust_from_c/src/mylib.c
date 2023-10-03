#include <stdio.h>
#include "mylib.h"
// extern int sum_from_rust(int, int);
// extern void hello_from_rust();

// int sum_from_rust(int a, int b) {
//   int sum = sum_from_rust(a, b);
//   printf("Sum from rust is %d", sum);
//   return sum;
// }

// void hello_from_rust() {
//   hello_from_rust();
// }

void hello() {
  printf("Hello from mylib\n");
}

unsigned add(unsigned a, unsigned b) {
  return a + b;
}

void echo(const char* str) {
  printf("echo: %s\n", str);
}

void call_cb(void (*cb) (const char* str)) {
  cb("hi again!");
}
