// ANCHOR: imports
// We're going to use RLBox in a single-threaded environment.
#define RLBOX_USE_EXCEPTIONS
#define RLBOX_ENABLE_DEBUG_ASSERTIONS
#define RLBOX_SINGLE_THREADED_INVOCATIONS


// All calls into the sandbox are resolved statically.
#define RLBOX_USE_STATIC_CALLS() rlbox_wasm2c_sandbox_lookup_symbol
// #define RLBOX_WASM2C_MODULE_NAME mylib
#define RLBOX_WASM2C_MODULE_NAME rust__from__c

#include <stdio.h>
#include <cassert>
// #include "./rust_from_c/src/mylib.h"
#include "./rust_from_c/src/rust_from_c.h"
#include "mylib.wasm.h"
#include "rlbox.hpp"
#include "rlbox_wasm2c_sandbox.hpp"

using namespace std;
using namespace rlbox;

// Define base type for mylib/rust_from_c
// RLBOX_DEFINE_BASE_TYPES_FOR(mylib, wasm2c);
RLBOX_DEFINE_BASE_TYPES_FOR(rust_from_c, wasm2c);


int main(int argc, char const *argv[]) {
  // Declare and create a new sandbox
  // rlbox_sandbox_mylib sandbox;
  rlbox_sandbox_rust_from_c sandbox;
  sandbox.create_sandbox();

  sandbox.invoke_sandbox_function(hello_from_rust);

  // call the sum_from_rust function and check the result:
  auto ok = sandbox.invoke_sandbox_function(sum_from_rust, 3, 4)
                   .copy_and_verify([](int ret){
    printf("Adding... 3+4 = %d\n", ret);
    return ret == 10;
  });
  printf("OK? = %d\n", ok);
  // sandbox.template INTERNAL_invoke_with_func_ptr<decltype(sum_from_rust)>(
  //     "sum_from_rust",
  //     sandbox_lookup_symbol_helper(RLBOX_USE_STATIC_CALLS(), sum_from_rust), 3, 4).copy_and_verify([](int ret) { printf("%d\n", ret); });

  //sandbox.invoke_sandbox_function(hello_from_rust).copy_and_verify([](int ret) { printf("%ds\n", ret); });
  // sandbox.template INTERNAL_invoke_with_func_ptr<decltype(hello_from_rust)>(
  //     "hello_from_rust",
  //     sandbox_lookup_symbol_helper(RLBOX_USE_STATIC_CALLS(), hello_from_rust)).copy_and_verify([](int ret) { printf("%d\n", ret); });

  // sandbox.invoke_sandbox_function(filewrite_from_rust);

  sandbox.invoke_sandbox_function(train_from_rust).copy_and_verify([](float ret) {
    printf("%f\n", ret);
  });

  // destroy sandbox
  sandbox.destroy_sandbox();

  return 0;
}

