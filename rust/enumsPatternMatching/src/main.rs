#[derive(Debug)]
enum TraficLight {
    Red,
    Yellow,
    Green,
}

#[derive(Debug)]
struct Intersection {
    light: TraficLight,
    cars_waiting: i32,
}

impl Intersection {
    fn new() -> Self {
        Self {
            light: TraficLight::Red,
            cars_waiting: 0,
        }
    }
    fn change_light(&mut self) {
        self.light = match self.light {
            TraficLight::Red => TraficLight::Yellow,
            TraficLight::Yellow => TraficLight::Green,
            TraficLight::Green => TraficLight::Red,
        };
    }
    fn add_car(&mut self) {
        self.cars_waiting += 1;
    }
    fn can_pass(&self) -> bool {
        match self.light {
            TraficLight::Green => true,
            _ => false,
        }
    }
    fn pass_cars(&mut self) {
        match self.light {
            TraficLight::Green => self.cars_waiting = 0,
            _ => {}
        }
    }
    fn cars(&self) -> i32 {
        self.cars_waiting
    }
}

fn main() {
    let mut intersection = Intersection::new();

    println!("=== Intersection ===");

    for _ in 0..5 {
        intersection.add_car();
    }

    println!(
        " - Now there are {} cars waiting at the intersection.",
        intersection.cars()
    );

    intersection.change_light();
    println!(" - Changed the light.");

    if intersection.can_pass() {
        intersection.pass_cars();
        println!(" - The cars are passing the intersection.")
    } else {
        intersection.change_light();
        if intersection.can_pass() {
            intersection.pass_cars();
            println!(" - After a second change on lights the cars are passing.")
        }
    }
}
