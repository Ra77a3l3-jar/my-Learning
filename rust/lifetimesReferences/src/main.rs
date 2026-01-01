#[derive(Debug)]
struct Book {
    title: String,
    author: String,
}

#[derive(Debug)]
struct BorrowedBook<'a> {
    book: &'a Book,
    borrower_name: String,
}

fn borrow_book<'a>(book: &'a Book, borrower: String) -> BorrowedBook<'a> {
    BorrowedBook {
        book,
        borrower_name: borrower,
    }
}

struct Library {
    books: Vec<Book>,
}

impl Library {
    fn new() -> Self {
        Self { books: Vec::new() }
    }
    fn add_book(&mut self, title: String, author: String) {
        let book = Book { title, author };
        self.books.push(book);
    }
    fn find_book(&self, title: &str) -> Option<&Book> {
        self.books.iter().find(|t| t.title == title)
    }
}

fn main() {
    let mut library = Library::new();

    println!("=== Library ===");

    println!(" - Adding new books.");
    library.add_book("Tex Willer".to_string(), "G. L. Bonelli".to_string());
    library.add_book(
        "Count of Monte Cristo".to_string(),
        "Alexandre Dumas".to_string(),
    );
    library.add_book(
        "Sherlock Holmes".to_string(),
        "Arthur Conan Doyle".to_string(),
    );
    library.add_book(
        "Murder on the Orient Express".to_string(),
        "Agatha Christie".to_string(),
    );

    println!(" - Listing books:");
    for book in &library.books {
        println!("{:?}", book);
    }

    if let Some(book) = library.find_book("Tex Willer") {
        let borrowed = borrow_book(book, "Raffaele Meo".to_string());
        println!("\nBorrowed book: {:?}", borrowed);
    } else {
        println!("Book not found!");
    }
}
