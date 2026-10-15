// Assignment 4: Employee class using default and parameterized constructors.
// Calculate and display the total salary after adding a bonus.
#include<iostream>
#include<string>
using namespace std;

class Employee
{
    int id;
    string name;
    float basicSalary;
    float bonus;

public:
    // default constructor
    Employee()
    {
        id=0;
        name="Not Assigned";
        basicSalary=0;
        bonus=0;
        cout<<"Default constructor called"<<endl;
    }

    // parameterized constructor
    Employee(int i, string n, float sal, float b)
    {
        id=i;
        name=n;
        basicSalary=sal;
        bonus=b;
        cout<<"Parameterized constructor called"<<endl;
    }

    float totalSalary()
    {
        return basicSalary+bonus;
    }

    void display()
    {
        cout<<"Employee Id  : "<<id<<endl;
        cout<<"Name         : "<<name<<endl;
        cout<<"Basic Salary : "<<basicSalary<<endl;
        cout<<"Bonus        : "<<bonus<<endl;
        cout<<"Total Salary : "<<totalSalary()<<endl;
    }
};

int main()
{
    Employee e1;                                // default constructor
    Employee e2(101, "Rahul", 30000, 5000);     // parameterized constructor

    // object made from user input using the parameterized constructor
    int id;
    string name;
    float sal, b;
    cout<<"\nEnter employee id, name, basic salary and bonus: ";
    cin>>id>>name>>sal>>b;
    Employee e3(id, name, sal, b);

    cout<<"\n--- Employee 1 ---"<<endl;
    e1.display();
    cout<<"\n--- Employee 2 ---"<<endl;
    e2.display();
    cout<<"\n--- Employee 3 ---"<<endl;
    e3.display();
    return 0;
}
