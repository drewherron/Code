use std::io;

fn main() {
    // Prompt the user for the first number
    println!("Enter the numerator:");
    let a = read_input_as_f64().expect("Failed to read a");

    // Prompt the user for the second number
    println!("Enter the denominator:");
    let b = read_input_as_f64().expect("Failed to read b");

    // Attempt to divide the numbers
    match divide(a, b) {
        Ok(result) => println!("Result: {}", result),
        Err(e) => println!("Error: {}", e),
    }
}

fn read_input_as_f64() -> io::Result<f64> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    let number: f64 = input.trim().parse().map_err(|_| io::Error::new(io::ErrorKind::InvalidInput, "Not a valid number"))?;
    Ok(number)
}

fn divide(a: f64, b: f64) -> Result<f64, String> {
    if b == 0.0 {
        Err("Division by zero!".to_string())
    } else {
        Ok(a / b)
    }
}
