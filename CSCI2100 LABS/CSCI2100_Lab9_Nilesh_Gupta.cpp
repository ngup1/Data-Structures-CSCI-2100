#include <iostream>
#include <list>
using namespace std;

struct Book {
    int id;
    int width;
};

int main() {
    int sim_count = 1;
    int shelf_width;

    while (true) {
        cout << "Enter the shelf width (enter -1 to stop): ";
        cin >> shelf_width;
        if (shelf_width == -1) break;

        list<Book> bookshelf; 
        int current_width = 0;

        cout << "Starting simulation " << sim_count++ << "\n";

        while (true) {
            string command;
            cout << "Enter command (A to add (ID, width) , R to remove, E to end): ";
            cin >> command;

            if (command == "E") {
                break;
            } else if (command == "A") {
                int book_id, width;
                cin >> book_id >> width;

                bool book_exists = false;
                for (const Book& book : bookshelf) {
                    if (book.id == book_id) {
                        book_exists = true;
                        break;
                    }
                }

                if (!book_exists) {
                    bookshelf.push_front({book_id, width});
                    current_width += width;

                    while (current_width > shelf_width) {
                        Book last_book = bookshelf.back();
                        current_width -= last_book.width;
                        cout << "Removed book " << last_book.id << " to fit on the shelf.\n";
                        bookshelf.pop_back();
                    }
                } else {
                    cout << "Book " << book_id << " is already on the shelf.\n";
                }
            } else if (command == "R") {
                int book_id;
                cin >> book_id;

                bool book_removed = false;
                list<Book> updated_shelf;
                for (const Book& book : bookshelf) {
                    if (book.id == book_id && !book_removed) {
                        current_width -= book.width;
                        book_removed = true;
                        cout << "Removed book " << book_id << " from the shelf.\n";
                    } else {
                        updated_shelf.push_back(book);
                    }
                }

                if (!book_removed) {
                    cout << "Book " << book_id << " not found on the shelf.\n";
                }

                bookshelf = updated_shelf;
            } else {
                cout << "Invalid command.\n";
            }
        }

        cout << "Remaining books on the shelf: ";
        for (const Book& book : bookshelf) {
            cout << book.id << " ";
        }
        cout << "\n";
    }

    return 0;
}


