#[derive(Debug)]
struct Task {
    id: u32,
    description: String,
    completed: bool,
}

struct TaskManager {
    tasks: Vec<Task>,
    next_id: u32,
}

impl TaskManager {
    fn new() -> Self {
        Self {
            tasks: Vec::new(),
            next_id: 1,
        }
    }
    fn add_task(&mut self, description: String) {
        let task = Task {
            id: self.next_id,
            description,
            completed: false,
        };
        self.tasks.push(task);
        self.next_id += 1;
    }
    fn complete_task(&mut self, id: u32) {
        if let Some(task) = self.tasks.iter_mut().find(|t| t.id == id) {
            task.completed = true;
        } else {
            println!("Task with id {} not found.", id);
        }
    }
    fn count_completed(&self) -> usize {
        self.tasks.iter().filter(|t| t.completed).count()
    }
    fn list_pending(&self) {
        self.tasks
            .iter()
            .filter(|t| !t.completed)
            .for_each(|t| println!("{}: {}", t.id, t.description));
    }
}

fn main() {
    let mut manager = TaskManager::new();

    manager.add_task("Write Rust code".to_string());
    manager.add_task("Test TaskManager".to_string());
    manager.add_task("Read a tex willer".to_string());

    manager.complete_task(2);

    println!("Completed tasks: {}", manager.count_completed());

    println!("Pending tasks:");
    manager.list_pending();
}
