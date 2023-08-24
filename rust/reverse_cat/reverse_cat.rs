use std::env;
use std::fs;
use std::io::{self, Write};

fn main() -> io::Result<()> {
    // Get the command-line arguments
    let args: Vec<String> = env::args().collect();

    // Check if the filename is provided
    if args.len() != 2 {
        eprintln!("Usage: {} <filename>", args[0]);
        return Err(io::Error::new(io::ErrorKind::InvalidInput, "Expected a filename as an argument"));
    }

    // Read the entire file into a String
    let contents = fs::read_to_string(&args[1])?;

    // Reverse the contents
    let reversed_contents: String = contents.chars().rev().collect();

    // Print the reversed contents
    io::stdout().write_all(reversed_contents.as_bytes())?;

    print!("\n\n");
    
    Ok(())
}
