#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int age;
    string profession;
    double salary;
    string address;
    string pan;
    double tax;

public:
    // Default Constructor
    Employee()
    {
        name = "";
        age = 0;
        profession = "";
        salary = 0.0;
        address = "";
        pan = "";
        tax = 0.0;
    }

    // Parameterized Constructor
    Employee(string name, int age, string profession, double salary, string address, string pan)
    {
        this->name = name;
        this->age = age;
        this->profession = profession;
        this->salary = salary;
        this->address = address;
        this->pan = pan;
        this->tax = 0.0;
    }

    // Destructor
    ~Employee() {}

    // Tax Calculation
    int calculateTax()
    {
        double yearly_salary = this->salary; // Assuming salary is annual
        int n = 0;

        if (yearly_salary <= 300000.0)
        {
            tax = 0.0;
            n = 1;
        }
        else if (yearly_salary < 700000.0)
        {
            tax = 0.05 * (yearly_salary - 300000.0);
            n = 2;
        }
        else if (yearly_salary < 1000000.0)
        {
            tax = 20000.0 + 0.1 * (yearly_salary - 700000.0);
            n = 3;
        }
        else if (yearly_salary < 1200000.0)
        {
            tax = 50000.0 + 0.15 * (yearly_salary - 1000000.0);
            n = 4;
        }
        else if (yearly_salary < 1500000.0)
        {
            tax = 80000.0 + 0.20 * (yearly_salary - 1200000.0);
            n = 5;
        }
        else
        {
            tax = 140000.0 + 0.30 * (yearly_salary - 1500000.0);
            n = 6;
        }

        return n;
    }

    // Print Tax Information
    void printTax()
    {
        double taxable_income = salary - 75000.0;
        double surge = 0.0;

        cout << "Name in Full : " << name << endl;
        cout << "Designation : " << profession << endl;
        cout << "Office Address : " << address << endl;
        cout << "Age : " << age << endl;
        cout << "PAN : " << pan << endl;
        cout << "                                               For Financial Year 2024-25 (A.Y. 2025-26)" << endl;
        cout << "Gross Salary (Pay +GP+DA+HRA+ALLOWANCES) :                                      Rs." << salary << endl;
        cout << "Less: Standard Deduction u/s 16(ia)                                           -Rs.75000.00" << endl;
        cout << "Total Income / Taxable Income                                                 Rs." << taxable_income << endl;
        cout << "\nCalculation of Income Tax:" << endl;

        cout << "Income <= 300000            : NIL                                             ";
        if (tax == 0)
            cout << tax << endl;
        else
            cout << "NA" << endl;

        cout << "300000 < Income <= 700000   : 5% of income exceeding 300000                    ";
        if (tax > 0 && tax <= 20000)
            cout << tax << endl;
        else
            cout << "NA" << endl;

        cout << "700000 < Income <= 1000000  : 10% of income exceeding 700000                   ";
        if (tax > 20000 && tax <= 50000)
            cout << tax << endl;
        else
            cout << "NA" << endl;

        cout << "1000000 < Income <= 1200000 : 15% of income exceeding 1000000                  ";
        if (tax > 50000 && tax <= 80000)
            cout << tax << endl;
        else
            cout << "NA" << endl;

        cout << "1200000 < Income <= 1500000 : 20% of income exceeding 1200000                  ";
        if (tax > 80000 && tax <= 140000)
            cout << tax << endl;
        else
            cout << "NA" << endl;

        cout << "Income > 1500000            : 30% of income exceeding 1500000                  ";
        if (tax > 140000)
            cout << tax << endl;
        else
            cout << "NA" << endl;

        cout << "\nRebate (Total Income less than Rs. 7 Lakhs)                                   -Rs.0.00" << endl;
        cout << "Total Tax                                                                     Rs." << tax << endl;

        double cess = tax * 0.04;
        cout << "Education & Health Cess @ 4% on Income Tax                                   Rs." << cess << endl;

        if (taxable_income >= 5000000 && taxable_income < 10000000)
        {
            surge = taxable_income * 0.10;
            cout << "Add: Surcharge @ 10% (if income >= 50 Lakhs)                                 Rs." << surge << endl;
        }
        else if (taxable_income >= 10000000)
        {
            surge = taxable_income * 0.15;
            cout << "Add: Surcharge @ 15% (if income >= 1 Crore)                                  Rs." << surge << endl;
        }
        else
        {
            cout << "Add: Surcharge                                                              NA" << endl;
        }

        cout << "\nTotal tax payable                                                            Rs." << (tax + cess + surge) << endl;
    }
};

int main()
{
    Employee emp("John Doe", 30, "Software Engineer", 1200000, "123 Street, City", "ABCDE1234F");
    emp.calculateTax();
    emp.printTax();
    return 0;
}