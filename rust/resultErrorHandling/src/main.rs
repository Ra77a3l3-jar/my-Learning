#[derive(Debug)]
enum MathError {
    DivisionByZero,
    Overflow,
}

#[derive(Debug)]
struct Calculator {
    last_result: f64,
}

impl Calculator {
    fn new() -> Self {
        Self { last_result: 0.0 }
    }
    fn divide(&mut self, a: f64, b: f64) -> Result<f64, MathError> {
        if b == 0.0 {
            return Err(MathError::DivisionByZero);
        }

        let result = a / b;

        if !result.is_finite() {
            return Err(MathError::Overflow);
        }

        self.last_result = result;
        Ok(result)
    }
    fn safe_divide(&mut self, a: f64, b: f64) {
        match self.divide(a, b) {
            Ok(result) => {
                println!("Result: {}", result);
            }
            Err(MathError::DivisionByZero) => {
                println!("Error: cannot divide by zero.");
            }
            Err(MathError::Overflow) => {
                println!("Error: number overflow.")
            }
        }
    }
}

fn main() {
    let mut calculator = Calculator::new();

    calculator.safe_divide(127.0, 0.0);
    calculator.safe_divide(10.0, 5.1);
    calculator.safe_divide(1e308, 1e-308);

    println!("The last result stored is: {}", calculator.last_result);
}
