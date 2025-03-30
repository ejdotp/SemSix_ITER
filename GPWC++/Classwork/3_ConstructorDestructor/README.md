# Constructors and Destructors in C++

## Introduction

Think of constructors and destructors like turning on and off a smart device.

### Concept

When we buy a smart fan and plug it in, it should automatically set itself to a default speed (medium). You don't need to manually press buttons to set it up - it just works.

Similarly, when we unplug the fan, it should turn off and clean up temporary settings before shutting down.

- A constructor is like the fan automatically setting itself up when plugged in - it initializes the object as soon as it is created.
- A destructor is like the fan turning off and cleaning up when unplugged - it destroys the object when it is no longer needed.

## Basic Examples

### Without a Constructor

```cpp
class Fan {
    int speed;
public:
    void setSpeed(int s) { speed = s; }
    void showSpeed() { cout << "Speed: " << speed << endl; }
};

int main() {
    Fan myFan;
    myFan.setSpeed(3);  // Manually setting speed
    myFan.showSpeed();  // Speed: 3
}
```

### With a Constructor

```cpp
class Fan {
    int speed;
public:
    Fan() { speed = 2; }  // Constructor sets default speed
    void showSpeed() { cout << "Speed: " << speed << endl; }
};

int main() {
    Fan myFan;  // Automatically set to speed 2
    myFan.showSpeed();  // Speed: 2
}
```

### With a Destructor

```cpp
class Fan {
    int speed;
public:
    Fan() { speed = 2; }
    ~Fan() { cout << "Fan turned off" << endl; }  // Destructor
    void showSpeed() { cout << "Speed: " << speed << endl; }
};

int main() {
    Fan myFan;
    myFan.showSpeed();
}  // When program ends, "Fan turned off" is printed
```

## Constructors in C++

A constructor is a special member function in a class that automatically initializes objects when they are created. It has the same name as the class and is called automatically upon object creation.

### Key Points

- No need to call it explicitly
- When a constructor is declared for a class, initialization of the class objects becomes mandatory

### Example

```cpp
#include <iostream>
using namespace std;

class Integer {
    int m, n;  // Private data members
public:
    Integer() { // Constructor (same name as class)
        m = 0;
        n = 0;
    }
    void showData() {
        cout << "m = " << m << ", n = " << n << endl;
    }
};

int main() {
    Integer int1;  // Object is created, constructor is called automatically
    int1.showData(); // Output: m = 0, n = 0
    return 0;
}
```

### Constructor Characteristics

- They should be declared in the public section
- They are invoked automatically when the objects are created
- They do not have return types, not even void and cannot return values
- They cannot be inherited, though a derived class can call the base class constructor
- Like other C++ functions, they can have default arguments
- Constructors cannot be virtual
- We cannot refer to their addresses
- An object with a constructor (or destructor) cannot be used as a member of a union
- They make 'implicit calls' to the operators new and delete when memory allocation is required

## Types of Constructors

### 1. Default Constructor

A constructor with no parameters is called a default constructor. If no constructor is defined, the compiler provides a default constructor automatically.

```cpp
class A {
public:
    A() { cout << "Default constructor called" << endl; }
};

int main() {
    A obj;  // Automatically calls the default constructor
}
```

### 2. Parameterized Constructors

Constructors can take parameters to initialize objects with different values.

```cpp
#include <iostream>
using namespace std;

class Integer {
    int m, n;
public:
    Integer(int x, int y) { // Parameterized constructor
        m = x;
        n = y;
    }
    void showData() {
        cout << "m = " << m << ", n = " << n << endl;
    }
};

int main() {
    Integer int1(0, 100);  // Implicit call
    Integer int2 = Integer(5, 50);  // Explicit call

    int1.showData(); // Output: m = 0, n = 100
    int2.showData(); // Output: m = 5, n = 50

    return 0;
}
```

### Ways to Call Parameterized Constructor

1. **Explicit Call:**

```cpp
Integer int2 = Integer(0, 100);
```

This method explicitly calls the constructor and assigns the returned object to int1.

2. **Implicit Call (Shorthand Method):**

```cpp
Integer int1(0, 100);
```

This method directly initializes the object with constructor arguments.

### Notes on Parameterized Constructors

- Mandatory Arguments: When a constructor is parameterized, arguments must be provided during object creation
- Automatic Execution: Called automatically when an object is created
- Cannot Use Default Object Declaration

### 3. Copy Constructor

A copy constructor initializes an object using another object of the same class.

#### Invalid Copy Constructor

```cpp
class A {
public:
    A(A); // Illegal: Cannot pass object by value
};
```

**Why?** Passing an object by value requires making a copy of the object, which requires calling the constructor again, leading to an infinite loop.

#### Valid Copy Constructor

```cpp
class A {
public:
    A(A& obj) {  // Pass by reference
        cout << "Copy constructor called" << endl;
    }
};

int main() {
    A obj1;  // Normal object creation
    A obj2 = obj1;  // Copy constructor is called
    return 0;
}
```

### Example of Copy Constructor

```cpp
#include <iostream>
using namespace std;

class code {
    int id;

public:
    code() { }  // Default Constructor
    code(int a) { id = a; }  // Parameterized Constructor
    code(code &x) { id = x.id; }  // Copy Constructor

    void display() { cout << id; }
};

int main() {
    code A(100);  // Object A is created and initialized
    code B(A);    // Copy constructor is called (B is a copy of A)
    code C = A;   // Copy constructor is called again (C is a copy of A)

    code D;  // D is created but not initialized
    D = A;   // Copy constructor not called (assignment, not object creation)

    cout << "\n id of A: "; A.display();
    cout << "\n id of B: "; B.display();
    cout << "\n id of C: "; C.display();
    cout << "\n id of D: "; D.display();

    return 0;
}
```

**Output:**

```
id of A: 100
id of B: 100
id of C: 100
id of D: 100
```

### 4. Multiple Constructors (Constructor Overloading)

C++ allows multiple constructors in the same class, enabling different ways to initialize objects.

```cpp
#include <iostream>
using namespace std;

class integer {
    int m, n;

public:
    integer() { m = 0; n = 0; }  // Constructor 1: No arguments (default)
    integer(int a, int b) { m = a; n = b; }  // Constructor 2: Two arguments
    integer(integer &i) { m = i.m; n = i.n; }  // Constructor 3: Copy constructor

    void display() {
        cout << "m = " << m << ", n = " << n << endl;
    }
};

int main() {
    integer I1;  // Calls Constructor 1 (default constructor)
    integer I2(20, 40);  // Calls Constructor 2
    integer I3(I2);  // Calls Constructor 3 (copy constructor)

    cout << "I1: "; I1.display();
    cout << "I2: "; I2.display();
    cout << "I3: "; I3.display();

    return 0;
}
```

**Output:**

```
I1: m = 0, n = 0
I2: m = 20, n = 40
I3: m = 20, n = 40
```

## Dynamic Constructors

Constructors can be used to allocate memory dynamically when creating objects. This ensures that each object gets the right amount of memory based on its specific requirements.

### Example: String Class Implementation

```cpp
class String
{
    char *name;   // pointer to store a string in dynamically allocated memory
    int length;   // Stores the length of the string

public:
    String()  // Creates an empty string object
    {
        length = 0;
        name = new char[length + 1];  // Allocates 1 byte (for \0)
    }

    String(char *s) // Creates a string object from a given C-style string
    {
        length = strlen(s);  // Get length of input string
        name = new char[length + 1];  // Allocate exact memory required
        strcpy(name, s);  // Copy input string into allocated memory
    }

    void display(void) {
        cout << name << "\n";  // Print the stored string
    }

    void join(String &a, String &b);  // Function to concatenate two strings
};

void String::join(String &a, String &b) {
    length = a.length + b.length;  // Total length of combined strings
    delete name;  // Free previously allocated memory
    name = new char[length + 1];  // Allocate new memory for concatenated string
    strcpy(name, a.name);  // Copy first string
    strcat(name, b.name);  // Append second string
}
```

## Destructors

A destructor is a special member function in a class that is automatically called when an object goes out of scope or is explicitly deleted.

### Features

- Has the same name as the class, but prefixed with a tilde (~)
- Does not take any parameters and does not return any value
- Called implicitly by the compiler when an object is destroyed
- Commonly used to release memory allocated using new to prevent memory leaks

### Example

```cpp
#include <iostream>
using namespace std;

int count = 0;

class test {
public:
    test() {
        count++;
        cout << "Constructor Msg: Object number " << count << " created..";
    }

    ~test() {
        cout << "Destructor Msg: Object number " << count << " destroyed..";
        count--;
    }
};

int main() {
    cout << "Inside the main block..";

    cout << "\nCreating first object T1..";
    test T1;

    {
        cout << "inside Block 1..";
        cout << "\nCreating two more objects T2 and T3..";
        test T2, T3;
        cout << "\nLeaving Block 1..";
    }  // T2 and T3 go out of scope, so their destructors are called

    cout << "\nBack inside the main block..";
    return 0;
}  // T1 is destroyed when main() ends
```

**Output:**

```
Inside the main block..

Creating first object T1..
Constructor Msg: Object number 1 created..

Inside Block 1..

Creating two more objects T2 and T3..
Constructor Msg: Object number 2 created..
Constructor Msg: Object number 3 created..

Leaving Block 1..

Destructor Msg: Object number 3 destroyed..
Destructor Msg: Object number 2 destroyed..

Back inside the main block..

Destructor Msg: Object number 1 destroyed..
```

## Practice Questions

### Q1. String Class Implementation

Define a "class String" that could work as a user-defined string type. Include constructors that will enable us to create an uninitialized string and initialize an object with a string constant.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *name;  // Pointer to dynamically allocated memory for a string
    int length;  // Stores the length of the string

public:
    // Default Constructor (Creates an empty string)
    String()
    {
        length = 0;
        name = new char[1];  // Allocating memory for '\0'
        name[0] = '\0';  // Empty string
    }

    // Parameterized Constructor (Initializes with a string constant)
    String(const char *s)
    {
        length = strlen(s);  // Get length of input string
        name = new char[length + 1];  // Allocate exact memory required
        strcpy(name, s);  // Copy input string into allocated memory
    }

    // Copy Constructor
    String(const String &s)
    {
        length = s.length;
        name = new char[length + 1];
        strcpy(name, s.name);
    }

    // Destructor (Frees dynamically allocated memory)
    ~String() {
        delete[] name;
    }

    // Function to join two strings
    void join(const String &a, const String &b)
    {
        delete[] name;  // Free existing memory
        length = a.length + b.length;
        name = new char[length + 1];  // Allocate memory for concatenated string
        strcpy(name, a.name);
        strcat(name, b.name);
    }

    // Function to display the string
    void display() const
    {
        cout << name << endl;
    }
};

int main()
{
    // (a) Creating an uninitialized string object
    String s1;
    cout << "Uninitialized String (empty): ";
    s1.display();

    // (b) Creating objects with string constants
    String s2("Well done!");
    cout << "Initialized String s2: ";
    s2.display();

    // (c) Concatenating two strings
    String s3(" Keep going!");
    String s4;

    s4.join(s2, s3);
    cout << "Concatenated String (s2 + s3): ";
    s4.display();

    return 0;
}
```

**Output:**

```
Uninitialized String (empty):
Initialized String s2: Well done!
Concatenated String (s2 + s3): Well done! Keep going!
```

### Q2. Book Shop Inventory System

Design a system using a class called books with suitable member functions and constructors. Use new operator in constructors to allocate memory space required.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    char *author, *title, *publisher;
    float price;
    int stock;

public:
    Book()
    {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = 0.0;
        stock = 0;
    }

    ~Book()
    {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    void inputDetails()
    {
        cout << "Enter book title: ";
        cin.ignore(); // Clear the input buffer
        cin.getline(title, 20);

        cout << "Enter author name: ";
        cin.getline(author, 20);

        cout << "Enter publisher: ";
        cin.getline(publisher, 20);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter stock position: ";
        cin >> stock;
    }

    void display() const
    {
        cout << "\nBook Details:\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << " copies\n";
    }

    bool checkAvail(const char *searchTitle, const char *searchAuthor) const
    {
        return (strcmp(title, searchTitle) == 0 && strcmp(author, searchAuthor) == 0);
    }

    void updateStock(int requestedCopies) {
        if (stock >= requestedCopies) {
            float totalCost = requestedCopies * price;
            cout << "Total cost: " << totalCost << endl;
            stock -= requestedCopies;
        } else {
            cout << "Required copies not in stock.\n";
        }
    }
};

int main() {
    const int numBooks = 3;
    Book in[numBooks];  // Array of Book objects

    cout << "Enter details for " << numBooks << " books:\n";
    for (int i = 0; i < numBooks; ++i)
    {
        in[i].inputDetails();
    }

    char searchTitle[20], searchAuthor[20];
    cout << "\nEnter the title of the book you're looking for: ";
    cin.ignore();
    cin.getline(searchTitle, 20);

    cout << "Enter the author of the book: ";
    cin.getline(searchAuthor, 20);

    bool found = false;

    for (int i = 0; i < numBooks; ++i) {
        if (in[i].checkAvail(searchTitle, searchAuthor)) {
            found = true;
            in[i].display();

            int copies;
            cout << "\nEnter the number of copies required: ";
            cin >> copies;

            in[i].updateStock(copies);
            break;
        }
    }

    if (!found) {
        cout << "Book not found in inventory.\n";
    }

    return 0;
}
```

### Q3. Improved Book Shop System

Improve the system design to incorporate:

1. Price updates using a private member function
2. Automatic stock updates after transactions
3. Transaction statistics using static data members

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    char *author, *title, *publisher;
    float price;
    int stock;
    static int successfulTransactions;
    static int unsuccessfulTransactions;

private:
    void updatePrice(float newPrice) {
        price = newPrice;
    }

public:
    Book()
    {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = 0.0;
        stock = 0;
    }

    ~Book()
    {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    void inputDetails()
    {
        cout << "Enter book title: ";
        cin.ignore();
        cin.getline(title, 20);

        cout << "Enter author name: ";
        cin.getline(author, 20);

        cout << "Enter publisher: ";
        cin.getline(publisher, 20);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter stock position: ";
        cin >> stock;
    }

    void display() const
    {
        cout << "\nBook Details:\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << " copies\n";
    }

    bool checkAvail(const char *searchTitle, const char *searchAuthor) const
    {
        return (strcmp(title, searchTitle) == 0 && strcmp(author, searchAuthor) == 0);
    }

    void updateStock(int requestedCopies) {
        if (stock >= requestedCopies) {
            float totalCost = requestedCopies * price;
            cout << "Total cost: " << totalCost << endl;
            stock -= requestedCopies;
            successfulTransactions++;
        } else {
            cout << "Required copies not in stock.\n";
            unsuccessfulTransactions++;
        }
    }

    static void displayTransactionStats() {
        cout << "\nTransaction Statistics:\n";
        cout << "Successful transactions: " << successfulTransactions << endl;
        cout << "Unsuccessful transactions: " << unsuccessfulTransactions << endl;
        cout << "Total transactions: " << (successfulTransactions + unsuccessfulTransactions) << endl;
    }
};

// Initialize static members
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

int main() {
    const int numBooks = 3;
    Book in[numBooks];

    cout << "Enter details for " << numBooks << " books:\n";
    for (int i = 0; i < numBooks; ++i)
    {
        in[i].inputDetails();
    }

    char searchTitle[20], searchAuthor[20];
    cout << "\nEnter the title of the book you're looking for: ";
    cin.ignore();
    cin.getline(searchTitle, 20);

    cout << "Enter the author of the book: ";
    cin.getline(searchAuthor, 20);

    bool found = false;

    for (int i = 0; i < numBooks; ++i) {
        if (in[i].checkAvail(searchTitle, searchAuthor)) {
            found = true;
            in[i].display();

            int copies;
            cout << "\nEnter the number of copies required: ";
            cin >> copies;

            in[i].updateStock(copies);
            break;
        }
    }

    if (!found) {
        cout << "Book not found in inventory.\n";
    }

    // Display transaction statistics
    Book::displayTransactionStats();

    return 0;
}
```

---
