// use std::alloc::System;

// #[global_allocator]
// static A: System = System;

// extern crate libc;

// use std::mem;

use std::fs::File;
use std::io::Write;
use std::result::Result;

use linfa::dataset::Dataset;
use linfa::prelude::*;
use linfa_linear::LinearRegression;
use ndarray::prelude::*;

extern "C" {
    fn printf(fmt: *const i8, ...) -> i32;
}

// extern "C" {
//     fn malloc(size_t: usize) -> *mut u8;
// }

// can we do a similar thing w malloc as we did for printf
// and use it to pass to vec and other things that could use custom allocator
// might be possible globally or on an individual basis, globally would be favorable

#[no_mangle]
pub extern "C" fn sum_from_rust(a: i32, b:i32) -> i32 {
    /* unsafe {
        let first:*mut i32 = malloc(4) as *mut i32;
        *first = a;
        return *first + *first + b;
    }
    */
    let v = vec![a, b];
    let sum = v[0] + v[0] + v[1] + v[1];
    println!("hello!");
    println!("bye!");
    return sum;
}

#[no_mangle]
pub extern "C" fn hello_from_rust() {
    match result_from_rust(30) {
         Ok(_x) => {},
         Err(_) => {return;}
     };
    unsafe {
        printf("Hello from Rust!\n\0".as_ptr() as *const i8);
    }
    unsafe {
        printf("Hello from Rust!\n\0".as_ptr() as *const i8);
    }
}

#[no_mangle]
pub extern "C" fn filewrite_from_rust() {
    let mut file = File::create("foo.txt").unwrap();
    file.write_all(b"Hello, world!").unwrap();
}

pub fn result_from_rust(a: i32) -> Result<i32, ()> {
    if a > 10 {
        return Ok(10)
    } else {
        return Err(())
    }
}

#[no_mangle]
pub extern "C" fn train_from_rust() -> f64 {
    let grades: Vec<[f64; 2]> = vec![[0.0, 0.0]];

    let array: Array2<f64> = Array2::from(grades);
    let (x, y) = (
        array.slice(s![.., 0..1]).to_owned(),
        array.column(1).to_owned(),
    );

    let dataset: Dataset<f64, f64, Dim<[usize; 1]>> =
        Dataset::new(x, y).with_feature_names(vec!["x", "y"]);

    // Train the model.
    let lin_reg = LinearRegression::new();
    let model = lin_reg.fit(&dataset).unwrap();
    let grade = model.params()[0] * 0.0 + model.intercept();
    grade
}