trait Animal {
    fn make_sound(&self) -> String;
    fn move_speed(&self) -> i32;
}

#[derive(Debug)]
struct Dog {
    name: String,
    speed: i32,
}

impl Animal for Dog {
    fn make_sound(&self) -> String {
        "Bau".to_string()
    }
    fn move_speed(&self) -> i32 {
        self.speed
    }
}

#[derive(Debug)]
struct Bird {
    species: String,
    speed: i32,
}

impl Animal for Bird {
    fn make_sound(&self) -> String {
        "Chirp".to_string()
    }
    fn move_speed(&self) -> i32 {
        self.speed
    }
}

fn describe_animal(animal: &impl Animal) {
    println!("Sound: {}", animal.make_sound());
    println!("Speed: {} km/h", animal.move_speed());
}

fn main() {
    let dog = Dog {
        name: String::from("Snoopy"),
        speed: 13,
    };

    let bird = Bird {
        species: String::from("Owl"),
        speed: 40,
    };

    println!("=== Dog ===");
    describe_animal(&dog);
    println!("=== Bird ===");
    describe_animal(&bird);
}
