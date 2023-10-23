use std::fs::File;
use std::io::Write;

#[no_mangle]
pub extern "C" fn sum_from_rust(a: i32, b:i32) -> i32 {
    let sum = a + b;
    return sum;
}

#[no_mangle]
pub extern "C" fn hello_from_rust() {
    println!("Hello from Rust!");
}

#[no_mangle]
pub extern "C" fn filewrite_from_rust() {
    let mut file = File::create("foo.txt").unwrap();
    file.write_all(b"Hello, world!").unwrap();
}
