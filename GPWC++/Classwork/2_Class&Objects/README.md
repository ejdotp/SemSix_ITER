# Game Programming With C++

## Classes and Objects

### C Structures Revisited

For example, consider the following declaration:

```cpp
struct student
{
    char name[20];
    int roll_number;
    float total_marks;
};
struct student A;   // C declaration
```

### Limitations of C Structure

The standard C does not allow the struct data type to be treated like built-in types.

For example, consider the following structure:

```cpp
struct complex
{
    float x;
    float y;
};
struct complex c1, c2, c3;
```

The complex numbers c1, c2, and c3 can easily be assigned values using the dot operator, but we cannot add two complex numbers or subtract one from the other.

For example:

```cpp
c3 = c1 + c2;      // Error: Structs do not support arithmetic operations. // is illegal in C.
```

In C++, a structure can have both variables and functions as members. It can also declare some of its members as 'private' so that they cannot be accessed directly by the external functions.

For example, we can declare the student variable A as:

```cpp
student A;           // C++ declaration
```

**NOTE:** The only difference between a structure and a class in C++ is that, by default, the members of a class are private, while, by default, the members of a structure are public.

### Specifying a Class

A class is a way to bind the data and its associated functions together. It allows the data (and functions) to be hidden, if necessary, from external use.

When defining a class, we are creating a new abstract data type that can be treated like any other built-in data type.

Generally, a class specification has two parts:

1. Class declaration
2. Class function definitions

The general form of a class declaration is:

```cpp
class class_name
{
    private:
        variable declarations;    // data members
        function declarations;    // member function

    public:
        variable declarations;
        function declaration;
};
```

- Private can be accessed only from within the class
- Public members can be accessed from outside the class also
- The data hiding (using private declaration) is the key feature of object-oriented programming
- By default, the members of a class are private
- The binding of data and functions together into a single class-type variable is referred to as encapsulation

### A Simple Class Example

```cpp
class item
{
    int number;    // variables declaration
    float cost;

public:
    void getdata(int a, float b)    // functions declaration
    void putdata(void);
};
```

### Creating Objects

```cpp
item x;   // memory for x is created
```

Creates a variable x of type item. In C++, the class variables are known as objects. Therefore, x is called an object of type item.

We may also declare more than one object in one statement.

Example:

```cpp
item x, y, z;
```

### Accessing Class Members

The private data of a class can be accessed only through the member functions of that class.

The following is the format for calling a member function:

```cpp
object-name.function-name (actual-arguments);
```

For example, the function call statement:

```cpp
x.getdata(100,75.5);
x.putdata();
```

Example: A variable declared as public can be accessed by the objects directly.

```cpp
class xyz
{
    int x;
    int y;

public:
    int z;
};
....
....
xyz p;
p.x = 0;  // error, x is private
p.z = 10  // OK, z is public
```

### Defining Member Functions

Member functions can be defined in two places:

- Outside the class definition
- Inside the class definition

#### Outside the class definition

An important difference between a member function and a normal function is that:
A member function incorporates a membership 'identity label' in the header. This 'label' tells the compiler which class the function belongs to.

The general form of a member function definition is:

```cpp
return-type  class-name :: function-name (argument declaration)
{
    Function body
}
```

The symbol :: is called the scope resolution operator.

Example: For instance, consider the member functions getdata() and putdata().

```cpp
void item :: getdata(int a, float b)
{
    number = a;
    cost = b;
}

void item :: putdata(void)
{
    cout << "Number :" << number << "\n"
    cout << "Cost :" << cost << "\n"
}
```

#### Inside the class definition

```cpp
class item
{
    int number;
    float cost;

public:
    void getdata(int a, float b);  // declaration

    void putdata(void)   // definition inside the class
    {
        cout << number << "\n"
        cout << cost << "\n"
    }
};
```

### General Format of Class Implementation

```cpp
#include <iostream>
using namespace std;

class item
{
    int number;  // private by default
    float cost;  // private by default

public:
    void getdata(int a, float b); // prototype declaration

    void putdata(void) // Member Function Definition (Inside class)
    {
        cout << "number :" << number << "\n"
        cout << "cost :" << cost << "\n"
    }
};

// Member Function Definition (Outside class)
void item :: getdata(int a, float b)  // use membership label
{
    number = a;  // private variables directly used
    cost = b;
}

// Main Program
int main()
{
    item x;    // create object x

    x.getdata(100, 299.95);  // call member function
    x.putdata(); // call member function

    item y;  // create another object
    y.getdata(200, 175.50)
    y.putdata();
    return 0;
}
```

### Making an Outside Function Inline

It is good practice to define the member functions outside the class.

#### Concept (without inline)

Imagine you are a teacher in a school. You have a math formula written in a notebook in the staff room.

Non-Inline Function (Normal Function): Every time a student asks for the formula, you tell them: "Go to the staff room, open page 10, and read the formula."

This means:

- The student leaves the classroom (like a function call)
- Walks to the staff room (jumps to function memory)
- Reads the formula (executes the function)
- Comes back to class (returns from the function)

This is like a normal (non-inline) function because the program jumps to another memory location, executes the function, and returns.

Example (without inline):

```cpp
#include <iostream>
using namespace std;

class Item {
    int number;
    float cost;

public:
    void getdata(int a, float b);
    void show();
};

// Function definition (Not inline)
void Item::getdata(int a, float b) {
    number = a;
    cost = b;
}

// Function definition (Not inline)
void Item::show() {
    cout << "Number: " << number << ", Cost: " << cost << endl;
}

int main() {
    Item obj;
    obj.getdata(5, 99.99);  // program jumps here
    obj.show();             // program jumps here
    return 0;
}
```

#### Concept (with inline)

Inline Function:
Instead of making students go to the staff room, you write the formula on the classroom board.

Now, whenever a student needs the formula, they can see it immediately without leaving the room.

This is like an inline function because the function code is directly inserted into the main program, avoiding jumps and saving execution time.

Example (with inline):

```cpp
class item
{
    // ...
public:
    void getdata(int a, float b);  // declaration
};

inline void item :: getdata(int a, float b)  // definition (Outside class)
{
    number = a;
    cost = b;
}
```

Example 2 (inline):

```cpp
#include <iostream>
using namespace std;

class Item {
    int number;
    float cost;

public:
    inline void getdata(int a, float b)
    {
        number = a;
        cost = b;
    }

    inline void show() {
        cout << "Number: " << number << ", Cost: " << cost << endl;
    }
};

int main() {
    Item obj;
    obj.getdata(5, 99.99);  // No function call, code is inserted directly
    obj.show();  // No function call, code is inserted directly
    return 0;
}
```

### Nesting of Member Functions

A member function can be called by using its name inside another member function of the same class. This is known as nesting of member functions.

Example 1: Calculate area of Rectangle using class implementation and nesting members functions.

```cpp
#include <iostream>
using namespace std;

class Rectangle
{
    int length, width;

public:
    void read()
    {
        cout << "Enter length and width: ";
        cin >> length >> width;
    }

    int calArea()
    {
        return length * width;
    }

    void display()
    {
        int area = calArea();
        cout << "The area of the rectangle is: " << area << endl;
    }
};

int main() {
    Rectangle r;
    r.read();
    r.display();
    return 0;
}
```

Example 2:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class binary
{
    string s;

public:
    void read()
    {
        cout << "Enter a binary number: ";
        cin >> s;
    }

    void chk_bin()  // Verify binary format
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) != '0' && s.at(i) != '1')
            {
                cout << "\nIncorrect binary number format...the program will quit";
                exit(0);
            }
        }
    }

    void ones()  // Compute one's complement
    {
        chk_bin();

        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '0')
                s.at(i) = '1';
            else
                s.at(i) = '0';
        }
    }

    void displayones()
    {
        ones();
        cout << "\nThe 1's complement of the above binary number is: " << s;
    }
};

int main() {
    binary b;
    b.read();
    b.displayones();
    return 0;
}
```

**Note:** `.at(i)` is similar to `s[i]` but `s[i]` does not perform bounds checking. Accessing an out-of-range index using `s[i]` results in undefined behavior.

### Private Member Functions

Although it is normal practice to place all the data items in a private section and all the functions in public.

Some situations may require certain functions to be hidden (like private data) from the outside calls. Tasks such as deleting an account in a customer file, or providing increment to an employee are events of serious consequences and therefore the functions handling such tasks should have restricted access.

A private member function can only be called by another function that is a member of its class. Even an object cannot invoke a private function using the dot operator.

Private member functions can only be called by other member functions of the same class. They cannot be accessed directly using objects.

Example 1:

```cpp
class sample
{
    int m;

    void read(void);  //private member function

public:
    void update(void);
    void write(void);
};

int main()
{
    s1.read();  // Error: Cannot access private member function
}
```

Possible way to access private member function outside & inside the class:

1. Outside the class:

```cpp
void sample :: update(void)
{
    read();  // simple call; no object used
}
```

2. Inside the class:

```cpp
class sample
{
    int m;

    void read(void);  //private member function

public:
    void update(void)
    {
        read();
    }
    void write(void);
};
```

### Arrays within a Class

The arrays can be used as member variables in a class. The array variable a[] declared as a private member of the class, array can be used in the member functions.

Example 1:

```cpp
const int size = 10;  // provides value for array size

class array
{
    int a[size];  // 'a' is int type array

public:
    void setval(void);
    void display(void);
};
```

Example 2:

```cpp
#include <iostream>
using namespace std;

const int SIZE = 5;

class Numbers
{
    int a[SIZE];

public:
    void setVal()
    {
        cout << "Enter " << SIZE << " numbers: ";

        for (int i = 0; i < SIZE; i++)
        {
            cin >> a[i];
        }
    }

    void displayValues()
    {
        cout << "Array elements: ";

        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Numbers num;
    num.setVal();
    num.displayValues();
    return 0;
}
```

### Static Data Members in Class

Static data members in C++ are shared among all objects of a class rather than being unique to each instance.

A data member of a class can be qualified as static, which keeps track of the number of times data is assigned to objects.

A static member variable has certain special characteristics:

- It is initialized to zero when the first object of its class is created. No other initialization is permitted.
- Only one copy of that member is created for the entire class and is shared by all the objects of that class, no matter how many objects are created.
- It is visible only within the class, but its lifetime is the entire program.

**Note: const Member Functions**

If a member function does not alter any data in the class, then we may declare it as a const member function as follows:

```cpp
void mul(int, int) const;
double get_balance() const;
```

The qualifier `const` is appended to the function prototypes (in both declaration and definition). The compiler will generate an error message if such functions try to alter the data values.

Example:

```cpp
#include <iostream>
using namespace std;

class item
{
    static int count;  // Static data member to keep track of count
    int number;

public:
    void getdata(int a)
    {
        number = a;
        count++;
    }

    // Declaring getcount() as const ensures it can only read count and not modify any member variables of the object.
    void getcount(void) const
    {
        cout << "Count: " << count << "\n";
    }
};

// Initialize static data member, each static member variable must be defined outside the class definition.
int item::count = 0;

int main()
{
    item a, b, c;

    cout << "Initial count:\n";
    a.getcount();
    b.getcount();
    c.getcount();

    // Assign data to objects
    a.getdata(100); 	// Assign 100 to object a
    b.getdata(200);
    c.getdata(300);

    // Display count after data assignment
    cout << "\nAfter reading data:\n";
    a.getcount();
    b.getcount();
    c.getcount();

    return 0;
}
```

Output:

```
Initial count:
Count: 0
Count: 0
Count: 0

After reading data:
Count: 3
Count: 3
Count: 3
```

### Static Member Functions

A member function that is declared static has the following properties:

- A static function can have access to only other static members (functions or variables) declared in the same class.
- A static member function can be called using the class name (instead of its objects) as follows:

```cpp
class-name :: function-name;
```

Example:

```cpp
#include <iostream>
using namespace std;

class test
{
    int code;
    static int count; 	// Static member variable

public:
    void setcode(void)
    {
        code = ++count;
    }

    void showcode(void)
    {
        cout << "Object number: " << code << "\n";
    }

    static void showcount(void) // Static member function
    {
        cout << "Count: " << count << "\n";
    }
};

// Definition and initialization of static member variable
int test::count = 0;

int main()
{
    test t1, t2;

    t1.setcode();
    t2.setcode();

    test::showcount(); 	// Accessing static function

    test t3;
    t3.setcode();

    test::showcount();

    t1.showcode();
    t2.showcode();
    t3.showcode();

    return 0;
}
```

Output:

```
Count: 2
Count: 3

Object number: 1
Object number: 2
Object number: 3
```

Remember, the following function definition will not work:

```cpp
static void showcount()
{
    cout << code;	 // code is not static
}
```

### Arrays of Objects

We know that an array can be of any data type including struct. Similarly, we can also have arrays of variables that are of the type class. Such variables are called arrays of objects.

Consider the following class definition:

```cpp
class employee
{
    char name[30];
    float age;

public:
    void getdata(void);
    void putdata(void);
};
```

The identifier employee is a user-defined data type and can be used to create objects that relate to different categories of the employees.

Example:

```cpp
// The array manager contains three objects(managers), namely, manager[0], manager[1]and manager[2].
employee manager[3]; // Array of 3 manager objects

employee foreman[15]; 	// array of foreman
employee worker[75]; 	// array of worker
```

Example 1:

```cpp
#include <iostream>
using namespace std;

class employee
{
    char name[30]; // String as a class member
    float age;

public:
    void getdata(void);
    void putdata(void);
};

void employee::getdata(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void employee::putdata(void)
{
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
}

const int size = 3;

int main()
{
    employee manager[size]; // Array of objects

    // Input details for each manager
    for (int i = 0; i < size; i++) {
        cout << "\nDetails of manager " << i + 1 << ":\n";
        manager[i].getdata();
    }

    // Display details of each manager
    for (int i = 0; i < size; i++) {
        cout << "\nManager " << i + 1 << ":\n";
        manager[i].putdata();
    }

    return 0;
}
```

Output:

```
Manager 1:
Name: ABC
Age: 35

Manager 2:
Name: B
Age: 40

Manager 3:
Name: C
Age: 45
```

Example 2:

```cpp
#include <iostream>
using namespace std;

class Student {
    int marks;
public:
    void set(int m) { marks = m; }
    void show() { cout << "Marks: " << marks << endl; }
};

int main() {
    Student s[2];
    s[0].set(85);
    s[1].set(90);

    s[0].show();
    s[1].show();
    return 0;
}
```

Example 3:

```cpp
#include <iostream>
using namespace std;

class Student
{
    int id;
    string name;

public:
    void setData(int i, string n)
    {
        id = i;
        name = n;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main()
{
    Student students[3];

    students[0].setData(101, "Alice");
    students[1].setData(102, "Bob");
    students[2].setData(103, "Charlie");

    cout << "Student Details:" << endl;

    for (int i = 0; i < 3; i++)
    {
        students[i].display();
    }

    return 0;
}
```

### Objects as Function Arguments

Like any other data type, an object may be used as a function argument.

This can be done in two ways:

- A copy of the entire object is passed to the function.
- Only the address of the object is transferred to the function.

The first method is called pass-by-value. Since a copy of the object is passed to the function, any changes made to the object inside the function do not affect the object used to call the function.

The second method is called pass-by-reference. When an address of the object is passed, the called function works directly on the actual object used in the call. This means that any changes made to the object inside the function will reflect in the actual object.

Example 1:

```cpp
#include <iostream>
using namespace std;

class Example {
    int x;
public:
    void set(int a) { x = a; }
    void show() { cout << "X: " << x << endl; }
};

void display(Example e) {  // Object passed as argument
    e.show();
}

int main() {
    Example obj;
    obj.set(30);
    display(obj);
    return 0;
}
```

Example 2: How to pass objects as function arguments in C++. The sum() function takes two time objects (t1 and t2) and adds their values and stores the result in the calling object (T3).

```cpp
#include <iostream>
using namespace std;

class time
{
    int hours;
    int minutes;

public:
    void gettime(int h, int m) {
        hours = h;
        minutes = m;
    }

    void puttime(void)
    {
        cout << hours << " hours and " << minutes << " minutes\n";
    }

    void sum(time t1, time t2); // Declaration with objects as arguments
};

void time::sum(time t1, time t2)
{
    minutes = t1.minutes + t2.minutes;

    hours = minutes / 60;     // Convert excess minutes to hours
    minutes = minutes % 60;   // Remaining minutes after converting to hours

    hours = hours + t1.hours + t2.hours;
}

int main()
{
    time T1, T2, T3;

    T1.gettime(2, 45);
    T2.gettime(3, 30);

    T3.sum(T1, T2);

    cout << "T1 = ";
    T1.puttime();

    cout << "T2 = ";
    T2.puttime();

    cout << "T3 = ";
    T3.puttime();

    return 0;
}
```

Output:

```
T1 = 2 hours and 45 minutes
T2 = 3 hours and 30 minutes

minutes = 45 + 30 = 75
Since 75 minutes is more than 60, we need to convert the extra minutes into hours.
hours = 75 / 60 = 1
minutes = 75 % 60 = 15
hours = 1 + 2 + 3 = 6

T3 = 6 hours and 15 minutes
```

### Pointer to Data Member in a Class

A pointer to a member allows us to store the address of a specific member of a class and use it dynamically with different objects.

**Concept:**

- A normal pointer stores the address of a variable.
- A pointer to a class member stores the address of a member variable or function of a class.
- To declare a pointer to a class member, we use ::\* (Scope resolution + pointer operator).
- A class member pointer can be declared using the operator ::\* with the class name.

Example 1:

```cpp
#include <iostream>
using namespace std;

class A
{
public:
    int m;

    void show() {
        cout << "Value of m: " << m << endl;
    }
};

int main()
{
    A obj1, obj2;

    obj1.m = 10;
    obj2.m = 20;

    // Declare a pointer to the 'm' member of class A
    int A::*ptr = &A::m;

    // Access the member using the object and pointer
    cout << "Using obj1: " << obj1.*ptr << endl;
    cout << "Using obj2: " << obj2.*ptr << endl;

    // Modify value using pointer
    obj1.*ptr = 30;
    cout << "Updated obj1.m: " << obj1.m << endl;

    return 0;
}
```

**Note:**
Declare a pointer to a member of class A:

- `A::*ptr` - Declares a pointer to an int member of class A.
- `&A::m` - Stores the address of m in ptr.

Example 2:

```cpp
#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int salary;

    void setData(string n, int s)
    {
        name = n;
        salary = s;
    }

    void display()
    {
        cout << "Name: " << name << ", Salary: $" << salary << endl;
    }
};

int main()
{
    Employee e1, e2;

    e1.setData("A", 5000);
    e2.setData("B", 6000);

    // Pointer to Employee's salary
    int Employee::*salaryPtr = &Employee::salary;

    // Using the pointer to update salaries dynamically
    e1.*salaryPtr += 500;  // Increase A's salary
    e2.*salaryPtr += 1000; // Increase B's salary

    e1.display();
    e2.display();

    return 0;
}
```

For example, given the class:

```cpp
class A
{
    int m;

public:
    void show();
};
```

We can define a pointer to the member m as follows:

```cpp
int A ::* ip = &A :: m;
```

The ip pointer created thus acts like a class member in that it must be invoked with a class object.

In the statement above, the phrase `A::*` means "pointer-to-member of A class". The phrase `&A::m` means the "address of the m member of A class".

Remember, the following statement is not valid:

```cpp
int *ip = &m; 	// won't work
```

This is because m is not simply an int type data. It has meaning only when it is associated with the class to which it belongs. The scope operator must be applied to both the pointer and the member.

### Local Classes

Classes can be defined and used inside a function or a block. Such classes are called local classes.

Local classes like temporary workers in a company:

- They only work within one department (function) and cannot be used elsewhere.
- They can access company-wide resources (global variables) but cannot access personal files of employees (local automatic variables).

Examples:

```cpp
void test(int a)  // function
{
    // ...
    class student 	 // local class
    {
        // ...
    };
    // ...
    student  s1 (a);  // create student object
    // ... 		   // use student object
}
```

**Note:**
Local classes can use global variables (declared above the function) and static variables declared inside the function but cannot use automatic local variables. The global variables should be used with the scope operator (::).

There are some restrictions in constructing local classes:

1. Can use global and static variables (with scope resolution :: if needed).
2. Cannot have static data members.
3. Cannot access automatic local variables of enclosing function.
4. Private members of local classes cannot be accessed from enclosing function.

Example 1:

```cpp
#include <iostream>
using namespace std;

static int globalVar = 50;  // Static global variable

void func() {
    class Local {
    public:
        void show() {
            cout << "Global Variable: " << ::globalVar << endl;  // Allowed
        }
    };

    Local obj;
    obj.show();
}

int main() {
    func();
    return 0;
}
```

Example 2:

```cpp
#include <iostream>
using namespace std;

void func() {
    class Local {
    public:
        static int x; // ERROR: Local classes cannot have static data members.
    };

    cout << "Inside func()" << endl;
}

int main() {
    func();
    return 0;
}
```

Example 3:

```cpp
#include <iostream>
using namespace std;

void func() {
    int num = 100;  // Automatic (local) variable

    class Local {
    public:
        void show() {
            cout << "Number: " << num << endl; // ERROR: Cannot access automatic local variables.
        }
    };

    Local obj;
    obj.show();
}

int main() {
    func();
    return 0;
}
```

Example 4:

```cpp
#include <iostream>
using namespace std;

void func() {
    class Local {
    private:
        int secret = 42;
    public:
        int getSecret() { return secret; }
    };

    Local obj;
    cout << obj.secret << endl; // ERROR: Private member not accessible.
}

int main() {
    func();
    return 0;
}
```

Example 5:

```cpp
#include <iostream>
using namespace std;

int globalVar = 100;

void test(int x)
{
    static int staticVar = 50;

    // Local class inside function
    class Student
    {
        int id;

    public:
        Student(int i) { id = i; }

        void display() {
            cout << "Student ID: " << id << endl;
            cout << "Global Variable: " << ::globalVar << endl;
            cout << "Static Variable: " << staticVar << endl;
        }
    };

    Student s1(x);  // Create local class object
    s1.display();
}

int main()
{
    test(101);  // Function call with student ID
    return 0;
}
```

Output:

```
Student ID: 101
Global Variable: 100
Static Variable: 50
```

### Questions and Solutions

#### Q1. Identify the error in the following program.

```cpp
#include <iostream.h>
class Room
{
    int width, height;
    void setValue(int w, int h)
    {
        width = w;
        height = h;
    }
};

void main()
{
    Room objRoom;
    objRoom.width = 12;
}
```

**Corrected Code:**

```cpp
#include <iostream>
using namespace std;
class Room {
    int width, height;    // Private by default
public:
    void setValue(int w, int h) {
        width = w;
        height = h;
    }
    void displayDimensions() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main()
{
    Room objRoom;
    objRoom.setValue(12, 10);
    objRoom.displayDimensions();
    return 0;
}
```

#### Q2. Identify the error in the following program. Output?

```cpp
#include <iostream.h>

class Item
{
private:
    static int count;

public:
    Item()
    {
        count++;
    }

    int getCount()
    {
        return count;
    }

    int* getCountAddress()
    {
        return count;
    }
};

int Item::count = 0;

void main()
{
    Item objItem1;
    Item objItem2;
    cout << objItem1.getCount() << ' ';
    cout << objItem2.getCount() << ' ';
    cout << objItem1.getCountAddress() << ' ';
    cout << objItem2.getCountAddress() << ' ';
}
```

**Errors:**

- Accessing Static Variable Address as a Non-Pointer: We are trying to return the address of the static member variable count.
- This is incorrect because count is an integer, and you must return its address using &count.

```cpp
int* getCountAddress()
{
    return count;  // Error: Returning an integer instead of an address
}
```

This function is declared as returning int\*, but count is an int (not a pointer). This causes a mismatch between the return type and the actual value.

In modern C++, you need to either use namespace std; or prefix cout and endl with std::.

```cpp
std::cout << objItem1.getCount() << ' ';
```

**Corrected Code:**

```cpp
#include <iostream>
using namespace std;
class Item {
private:
    static int count;
public:
    Item() { count++; }
    int getCount() const { return count; }
    int* getCountAddress() { return &count; }  // Corrected: return the address of the static variable
};

int Item::count = 0; 	// Initialize static variable

int main() {
    Item objItem1;
    Item objItem2;
    cout << objItem1.getCount() << ' ';
    cout << objItem2.getCount() << ' ';
    cout << objItem1.getCountAddress() << ' ';
    cout << objItem2.getCountAddress() << ' ';
    return 0;
}
```

**Output:**

```
2 2 0x55c1a8 0x55c1a8
```

The count variable is shared across all objects of the class. Each time an object is created, the count value increments.

#### Q3. Identify the error in the following program.

```cpp
#include <iostream.h>
class staticFunction
{
    static int count;
public:
    static void setCount()
    {count++; }
    void displayCount()
    {cout << count; }
};

int staticFunction::count = 10;

void main()
{
    staticFunction obj1;
    obj1.setCount(5);
    staticFunction::setCount();
    obj1.displayCount();
}
```

**Errors:**
The function setCount() is declared as a static member function.

**Note:**
Static functions cannot accept arguments because they do not operate on a specific instance of the class. However, in the main function, you are trying to call obj1.setCount(5);

```cpp
obj1.setCount(5); 	// Error: Passing an argument to a static function
```

Static member functions and variables are shared among all instances of the class and can be accessed directly using the class name.

**Corrected Code:**

```cpp
#include <iostream>
using namespace std;
class staticFunction {
    static int count; 	// Static variable shared by all instances
public:
    static void setCount() { count++; }
    void displayCount() { cout << count << endl; }
};

int staticFunction::count = 10; // Initialize static variable

int main() {
    staticFunction obj1;
    staticFunction::setCount();
    obj1.displayCount();
    return 0;
}
```

**Output:**

```
11
```

#### Q4. Identify the error in the following program.

```cpp
#include <iostream.h>
class Room;
void Area()
{
    int width, height;
    class Room
    {
        int width, height;
    public:
        void setValue(int w, int h)
        {
            width = w;
            height = h;
        }
        void displayValues()
        {
            cout << (float)width << ' ' << (float)height;
        }
    };

    Room objRoom1;
    objRoom1.setValue(12, 8);
    objRoom1.displayValues();
}

void main()
{
    Area();
    Room objRoom2;
}
```

**Corrected Code:**

```cpp
#include <iostream>
using namespace std;

// Declaration of Room class outside the Area function
class Room {
private:
    int width, height;

public:
    // Method to set width and height
    void setValue(int w, int h) {
        width = w;
        height = h;
    }

    // Method to display the width and height
    void displayValues() {
        cout << (float)width << ' ' << (float)height << endl;
    }
};

// Area function to work with the Room class
void Area() {
    Room objRoom1;
    objRoom1.setValue(12, 8);
    objRoom1.displayValues();
}

int main() {
    Area();
    Room objRoom2;
    return 0;
}
```

#### Q5. Will it compile or not? Correct this code.

```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    void set(int a) { x = a; }
    void show() { cout << "X: " << x << endl; }
};

int main() {
    Demo obj, *ptr;
    ptr = &obj;

    ptr->set(25);
    obj.show();
    return 0;
}
```

**Answer:**
Yes, this code will compile and run correctly.

`ptr->set(25);` is equivalent to `obj.set(25);`.
The arrow operator (->) is used to call functions through a pointer.

#### Q6. Output?

```cpp
#include <iostream>
using namespace std;

class Student {
    int id;
public:
    void set(int x) { id = x; }
    void show() { cout << "ID: " << id << endl; }
};

int main() {
    Student arr[3];
    for (int i = 0; i < 3; i++)
        arr[i].set(i + 1);

    for (int i = 2; i >= 0; i--)
        arr[i].show();

    return 0;
}
```

**Output:**

```
ID: 3
ID: 2
ID: 1
```

#### Q7. What will be the final value of count?

```cpp
#include <iostream>
using namespace std;

class Example {
    static int count;
public:
    void inc() { count++; }
    static void show() { cout << count << endl; }
};

int Example::count = 5;

int main() {
    Example arr[3];
    arr[0].inc();
    arr[1].inc();
    arr[2].inc();
    Example::show();
    return 0;
}
```

**Output:**

```
8
```

#### Q8. Will this compile? Why or why not?

```cpp
#include <iostream>
using namespace std;

void func() {
    int x = 10;
    class Local {
    public:
        void show() { cout << x << endl; }
    };
    Local obj;
    obj.show();
}

int main() {
    func();
    return 0;
}
```

**Answer:**
No, this code will not compile.

Local classes (classes defined inside functions) cannot access non-static local variables of the enclosing function.

**Solutions:**

1. Pass x as a Parameter:

```cpp
#include <iostream>
using namespace std;

void func() {
    int x = 10;
    class Local {
    public:
        void show(int val) { cout << val << endl; }
    };
    Local obj;
    obj.show(x);
}

int main() {
    func();
    return 0;
}
```

2. Make x Static (Global or Function Static):

```cpp
#include <iostream>
using namespace std;

void func() {
    static int x = 10; // Now accessible
    class Local {
    public:
        void show() { cout << x << endl; }
    };
    Local obj;
    obj.show();
}

int main() {
    func();
    return 0;
}
```

### Solved

#### Q1. Define a class to represent a bank account. Include the following members:

**Data members:**

1. Name of the depositor
2. Account number
3. Type of account
4. Balance amount in the account

**Member functions:**

1. To assign initial values
2. To deposit an amount
3. To withdraw an amount after checking the balance
4. To display name and balance

Write a main program to test the program.

**Sample Output:**

```
Account Holder Name: A
Account Number: 123456
Account Type: Savings
Balance: 1000

Amount deposited: 500
Account Holder Name: A
Account Number: 123456
Account Type: Savings
Balance: 1500

Amount withdrawn: 200
Account Holder Name: A
Account Number: 123456
Account Type: Savings
Balance: 1300

Insufficient balance!
```

**Solution:**

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string depositorName;
    int accountNumber;
    string accountType;
    float balance;

public:
    void setAccountDetails(string name, int accNo, string accType, float initialBalance)
    {
        depositorName = name;
        accountNumber = accNo;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited: " << amount << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        }
    }

    void displayAccountInfo() {
        cout << "\nAccount Holder Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account1;

    // Assign initial values
    account1.setAccountDetails("John Doe", 123456, "Savings", 1000.0f);

    account1.displayAccountInfo();

    account1.deposit(500.0f);

    account1.displayAccountInfo();

    account1.withdraw(200.0f);

    account1.displayAccountInfo();

    account1.withdraw(1500.0f);

    return 0;
}
```

### Friendly Functions

Suppose a private club that only allows members to enter. However, the club can issue a special guest pass to allow a friend to enter and access certain areas.

Similarly, in C++; a class usually restricts access to its private members, but it can grant "special access" to a friend function. This function is not a member of the class but can still access its private data.

#### Example 1:

```cpp
#include <iostream>
using namespace std;

class Test {
    int x;
public:
    Test() { x = 15; }
    friend void show(Test obj);
};

void show(Test obj) {
    cout << "X: " << obj.x << endl;
}

int main() {
    Test obj;
    show(obj);
    return 0;
}
```

#### Example 2:

```cpp
#include <iostream>
using namespace std;

class sample
{
    int a;
    int b;
public:
    void setvalue() {a = 25; b = 40; }
    friend float mean(sample s); // Friend function declaration
};

// Friend function definition (not a member of the class)
float mean(sample s)
{
    return float(s.a + s.b)/2.0; // Accessing private members
}

int main()
{
    sample X;
    X.setvalue();
    cout << "Mean value = " << mean(X) << "\n";
    return 0;
}
```

**Note:**

1. Not a member of the class, but still has access to private members.
2. Cannot be called using objects (like obj.function()). Call using function_name(Obj)
3. Has to use an object and dot operator (like s.a).
4. Declared using friend keyword inside the class but defined outside like a normal function.

#### When to Use Friend Functions?

Friend functions are used when a function needs access to private or protected members of a class but is not a member of that class.

Sometimes, two independent classes need to share data with each other. A friend function can be used to access private data of both classes without making them members of each other.

**Example:**

```cpp
#include <iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA
{
private:
    int numA;

public:
    ClassA() { numA = 10; }

    // Friend function declaration
    friend void displaySum(ClassA, ClassB);
};

class ClassB
{
private:
    int numB;

public:
    ClassB() { numB = 20; }

    // Friend function declared in ClassA can access private data of ClassB too
    friend void displaySum(ClassA, ClassB);
};

// Friend function definition
void displaySum(ClassA objA, ClassB objB)
{
    cout << "Sum: " << (objA.numA + objB.numB) << endl;
}

int main()
{
    ClassA objA;
    ClassB objB;

    displaySum(objA, objB); // Call friend function

    return 0;
}
```

### Returning Objects

How a member function can return an object of the same class.

```cpp
#include <iostream>
using namespace std;

class Example {
    int x;
public:
    void set(int a) { x = a; }

    // Since this is a pointer to the current object, *this represents the actual object.
    Example get() { return *this; }  // Returns the current object using *this

    void show() { cout << "X: " << x << endl; }
};

int main() {
    Example obj1, obj2;

    obj1.set(40);

    obj2 = obj1.get(); // obj1.get() returns obj1, and obj2 is assigned that object

    obj2.show();
    return 0;
}
```

If we wrote:

```cpp
Example* get() { return this; }

obj2 = obj1.get();  // ERROR: obj2 is not a pointer, but get() returns a pointer
```

This would require:

```cpp
Example* obj2 = obj1.get();
obj2->show();  // Using pointer to access members
```
