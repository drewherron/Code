use std::io;

fn main() {
    let mut input = String::new();
    println!("Enter the numerator:");
    io::stdin().read_line(&mut input).unwrap();
    let a: f64 = input.trim().parse().expect("Not a valid number");

    input.clear();
    println!("Enter the denominator:");
    io::stdin().read_line(&mut input).unwrap();
    let b: f64 = input.trim().parse().expect("Not a valid number");

    if b == 0.0 {
        println!("Error: Division by zero!");
    } else {
        println!("Result: {}", a / b);
    }
}
