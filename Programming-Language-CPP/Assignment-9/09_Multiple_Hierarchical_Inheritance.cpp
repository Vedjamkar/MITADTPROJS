// Assignment 9 (repeated as 11 in the handout):
// Multiple inheritance using PersonalDetails, SalaryDetails and Employee classes,
// and hierarchical inheritance using Shape, Circle and Rectangle classes.
#include<iostream>
#include<string>
using namespace std;

// ---------- Multiple inheritance: PersonalDetails + SalaryDetails -> Employee ----------
class PersonalDetails
{
protected:
    string name;
    int age;
public:
    void getPersonal()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }
};

class SalaryDetails
{
protected:
    float basic;
    float hra;
public:
    void getSalary()
    {
        cout<<"Enter basic salary: ";
        cin>>basic;
        cout<<"Enter HRA: ";
        cin>>hra;
    }
};

class Employee : public PersonalDetails, public SalaryDetails
{
    int empId;
public:
    void getEmployee()
    {
        cout<<"Enter employee id: ";
        cin>>empId;
        getPersonal();          // from PersonalDetails
        getSalary();            // from SalaryDetails
    }
    void display()
    {
        cout<<"Employee Id  : "<<empId<<endl;
        cout<<"Name         : "<<name<<endl;
        cout<<"Age          : "<<age<<endl;
        cout<<"Basic        : "<<basic<<endl;
        cout<<"HRA          : "<<hra<<endl;
        cout<<"Gross Salary : "<<basic+hra<<endl;
    }
};

// ---------- Hierarchical inheritance: Shape -> Circle, Shape -> Rectangle ----------
class Shape
{
protected:
    string shapeName;
public:
    void showName()
    {
        cout<<"Shape : "<<shapeName<<endl;
    }
};

class Circle : public Shape
{
    float radius;
public:
    Circle(float r)
    {
        shapeName="Circle";
        radius=r;
    }
    void showArea()
    {
        showName();
        cout<<"Radius : "<<radius<<endl;
        cout<<"Area   : "<<3.14*radius*radius<<endl;
    }
};

class Rectangle : public Shape
{
    float length, breadth;
public:
    Rectangle(float l, float b)
    {
        shapeName="Rectangle";
        length=l;
        breadth=b;
    }
    void showArea()
    {
        showName();
        cout<<"Length : "<<length<<", Breadth : "<<breadth<<endl;
        cout<<"Area   : "<<length*breadth<<endl;
    }
};

int main()
{
    cout<<"===== Multiple Inheritance ====="<<endl;
    Employee e;
    e.getEmployee();
    cout<<"\nEmployee details:"<<endl;
    e.display();

    cout<<"\n===== Hierarchical Inheritance ====="<<endl;
    Circle c(5);
    Rectangle r(4, 6);
    c.showArea();
    cout<<endl;
    r.showArea();
    return 0;
}
