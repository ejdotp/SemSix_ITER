#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Book {
    char *author, *title, *pblshr;
    float price;
    int stock;

public:
    Book() : author(nullptr), title(nullptr), pblshr(nullptr), price(0), stock(0) {}

    ~Book() {
        delete[] author;
        delete[] title;
        delete[] pblshr;
    }

    void inputDetails() {
        string temp;

        cout << "Enter book title: ";
        cin.ignore();  // Ignore leftover newline character
        getline(cin, temp);
        title = new char[temp.length() + 1];
        strcpy(title, temp.c_str());

        cout << "Enter author name: ";
        getline(cin, temp);
        author = new char[temp.length() + 1];
        strcpy(author, temp.c_str());

        cout << "Enter publisher: ";
        getline(cin, temp);
        pblshr = new char[temp.length() + 1];
        strcpy(pblshr, temp.c_str());

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter stock: ";
        cin >> stock;

        cout << endl;
    }

    bool checkAvail(const char *a, const char *b) {
        return (strcmp(title, a) == 0 && strcmp(author, b) == 0);
    }

    void updateStock(int x) {
        if (x > stock) {
            cout << "Not enough stock available!\n";
            return;
        }
        cout << "Total cost: " << x * price << endl;
        stock -= x;
    }

    void display() {
        cout << "Book Details:\n"
             << "Title: " << title << "\n"
             << "Author: " << author << "\n"
             << "Publisher: " << pblshr << "\n"
             << "Price: " << price << "\n"
             << "Stock: " << stock << " copies\n";
    }
};

int main() {
    int n, f, x = -1;
    string t, a;

    cout << "Store Setup:\nEnter number of books: ";
    cin >> n;

    Book *lib = new Book[n];

    cout << "Enter details for " << n << " books:\n------------------------------\n";
    for (int i = 0; i < n; i++) {
        lib[i].inputDetails();
    }

    cout << "\n------------------------------\n\nEnter the title of the book you're looking for: ";
    cin.ignore();
    getline(cin, t);

    cout << "Enter the author of the book: ";
    getline(cin, a);

    cout << "\n------------------------------\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (lib[i].checkAvail(t.c_str(), a.c_str())) {
            lib[i].display();
            x = i;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found!" << endl;
        delete[] lib;
        return 0;
    }

    cout << "\n------------------------------\nEnter the number of copies required: ";
    cin >> f;
    lib[x].updateStock(f);

    delete[] lib;
    return 0;
}

/*Sample output:

Store Setup:
Enter number of books: 2
Enter details for 2 books:
------------------------------
Enter book title: ABC
Enter author name: abc
Enter publisher: xyz
Enter price: 80
Enter stock: 3

Enter book title: DEF
Enter author name: def
Enter publisher: zyx
Enter price: 90
Enter stock: 6


------------------------------

Enter the title of the book you're looking for: DEF
Enter the author of the book: def

------------------------------
Book Details:
Title: DEF
Author: def
Publisher: zyx
Price: 90
Stock: 6 copies

------------------------------
Enter the number of copies required: 3
Total cost: 270*/