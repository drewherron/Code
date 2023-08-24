use std::io;

// Define the User struct with a single field: name
struct User {
    name: String,
}

// Define methods associated with the User struct
impl User {
    // Constructor-like method to create a new User
    fn new(name: String) -> Self {
        User { name } // same as: User { name: name }, allowed if same name
    }
    
    // Method to greet the user
    fn greet(&self) {
        println!("Hello {}!\n", self.name);
    }
}

fn main() {
    println!("Please enter your name:");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let input = input.trim().to_string();

    // Create a new User and greet them
    let user = User::new(input);
    // also works:
    // let user = User { name: input }
    // in which case you don't need a new() function at all
    user.greet();
}
