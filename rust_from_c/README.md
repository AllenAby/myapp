# Run call_rust from src
`cargo build`
`gcc call_rust.c -o call_rust -lrust_from_c -L../target/debug`
`./call_rust`