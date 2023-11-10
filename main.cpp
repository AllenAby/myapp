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

// // Declare callback function we're going to call from sandboxed code.
// void hello_cb(rlbox_sandbox_mylib& _, tainted_mylib<const char*> str);

int main(int argc, char const *argv[]) {
// ANCHOR_END: imports
// ANCHOR: hello
  // Declare and create a new sandbox
  // rlbox_sandbox_mylib sandbox;
  rlbox_sandbox_rust_from_c sandbox;
  sandbox.create_sandbox();

// ANCHOR: sum_from_rust
  // call the sum_from_rust function and check the result:
  auto ok = sandbox.invoke_sandbox_function(sum_from_rust, 3, 4)
                   .copy_and_verify([](int ret){
    printf("Adding... 3+4 = %d\n", ret);
    return ret == 7;
  });
  printf("OK? = %d\n", ok);
// ANCHOR_END: add
sandbox.invoke_sandbox_function(hello_from_rust);

sandbox.invoke_sandbox_function(filewrite_from_rust);

// ANCHOR: main-end
  // destroy sandbox
  sandbox.destroy_sandbox();

  return 0;
}
// ANCHOR_END: main-end

