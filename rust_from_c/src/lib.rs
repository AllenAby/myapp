#[no_mangle]
pub extern "C" fn sum_from_rust(a: i32, b:i32) -> i32 {
    let sum = a + b;
    return sum;
}

#[no_mangle]
pub extern "C" fn hello_from_rust() {
    println!("Hello from Rust!");
}

// pub extern "C" fn print_from_rust(input: &str) {
//     println!("{}", input);
// }
