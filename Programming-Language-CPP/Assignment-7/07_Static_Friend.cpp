// Assignment 7: Demonstrate
//   (a) static data members and static member functions
//   (b) a friend function for comparing private data of two classes
//   (c) a friend class for accessing private members
#include<iostream>
#include<string>
using namespace std;

// ---------- (a) static data member and static member function ----------
class Counter
{
    int id;
    static int count;       // shared by all objects of the class

public:
    Counter()
    {
        count++;
        id=count;
    }

    void showId()
    {
        cout<<"Object id: "<<id<<endl;
    }

    // static function can use only static members, called using class name
    static void showCount()
    {
        cout<<"Total objects created: "<<count<<endl;
    }
};

int Counter::count=0;       // static member must be defined outside the class

// ---------- (b) friend function comparing private data of two classes ----------
class ClassB;               // forward declaration, needed for the friend function

class ClassA
{
    int marks;
public:
    ClassA(int m)
    {
        marks=m;
    }
    friend void compareMarks(ClassA a, ClassB b);
};

class ClassB
{
    int marks;
public:
    ClassB(int m)
    {
        marks=m;
    }
    friend void compareMarks(ClassA a, ClassB b);
};

// not a member of either class, but can read the private data of both
void compareMarks(ClassA a, ClassB b)
{
    cout<<"ClassA marks = "<<a.marks<<", ClassB marks = "<<b.marks<<endl;
    if(a.marks>b.marks)
        cout<<"ClassA has more marks"<<endl;
    else if(b.marks>a.marks)
        cout<<"ClassB has more marks"<<endl;
    else
        cout<<"Both have equal marks"<<endl;
}

// ---------- (c) friend class ----------
class Account
{
    string holder;
    float balance;
public:
    Account(string h, float b)
    {
        holder=h;
        balance=b;
    }
    friend class Bank;      // Bank can access private members of Account
};

class Bank
{
public:
    void showAccount(Account acc)
    {
        cout<<"Account holder : "<<acc.holder<<endl;
        cout<<"Balance        : "<<acc.balance<<endl;
    }

    void addInterest(Account &acc, float rate)
    {
        acc.balance=acc.balance+acc.balance*rate/100;
    }
};

int main()
{
    cout<<"===== (a) Static members ====="<<endl;
    Counter c1, c2, c3;
    c1.showId();
    c2.showId();
    c3.showId();
    Counter::showCount();

    cout<<"\n===== (b) Friend function ====="<<endl;
    ClassA a(78);
    ClassB b(85);
    compareMarks(a, b);

    cout<<"\n===== (c) Friend class ====="<<endl;
    Account acc("Ved", 10000);
    Bank bank;
    bank.showAccount(acc);
    cout<<"After adding 5% interest:"<<endl;
    bank.addInterest(acc, 5);
    bank.showAccount(acc);
    return 0;
}
