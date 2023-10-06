# Running C Code in RLBox
This example is described [here](https://rlbox.dev/chapters/wasm-sandbox.html).

Have updated main.cpp, Makefile to reflect stable build. Need to comment out appropriate parts of Makefile and main.cpp.

Assumes rlbox and rlbox_wasm2c_sandbox have been built as specified in parent README

# Running Rust code in RLBox
In "myapp/rust_from_c":

`rustup target add wasm32-wasi`

`cargo build --target wasm32-wasi`

In "myapp":

`make clean`

`make mylib.wasm.c`

`make mylib.wasm.o`

`make myapp`