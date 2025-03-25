#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
public:
    virtual void display() const = 0;
    virtual string getTitle() const = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book(){}
    Book(const string& title, const string& author, int pages)
        : title(title), author(author), pages(pages) {}

    void display() const override {
        cout << "Book: " << title << endl;
        cout << "  Author: " << author << endl;
        cout << "  Pages: " << pages << endl;
    }

    string getTitle() const override {
        return title;
    }

    int getPages() const {
        return pages;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(){}
    Newspaper(const string& name, const string& date, const string& edition)
        : name(name), date(date), edition(edition) {}

    void display() const override {
        cout << "Newspaper: " << name << endl;
        cout << "  Date: " << date << endl;
        cout << "  Edition: " << edition << endl;
    }

    string getTitle() const override {
        return name;
    }

    string getEdition() const {
        return edition;
    }
};

class Library {
private:
    Book books[100];
    int bookCount;
    Newspaper newspapers[100];
    int newspaperCount;

public:
    Library() : bookCount(0), newspaperCount(0) {}

    void addBook(const Book& book) {
        if (bookCount < 100) {
            books[bookCount++] = book;
        }
        else {
            cout << "Library is full (books)." << endl;
        }
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (newspaperCount < 100) {
            newspapers[newspaperCount++] = newspaper;
        }
        else {
            cout << "Library is full (newspapers)." << endl;
        }
    }

    void displayCollection() const {
        cout << "Books:\n";
        for (int i = 0; i < bookCount; ++i) {
            books[i].display();
        }
        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; ++i) {
            newspapers[i].display();
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; ++i) {
            for (int j = 0; j < bookCount - i - 1; ++j) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; ++i) {
            for (int j = 0; j < newspaperCount - i - 1; ++j) {
                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(const string& title) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (int i = 0; i < newspaperCount; ++i) {
            if (newspapers[i].getTitle() == name) {
                return &newspapers[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}