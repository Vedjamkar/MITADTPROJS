// Assignment 5: Book class using a parameterized constructor, copy constructor
// and destructor. Display the details of the original and copied objects.
#include<iostream>
#include<string>
using namespace std;

class Book
{
    string title;
    string author;
    float price;

public:
    // parameterized constructor
    Book(string t, string a, float p)
    {
        title=t;
        author=a;
        price=p;
        cout<<"Parameterized constructor called for "<<title<<endl;
    }

    // copy constructor - takes reference of an object of the same class
    Book(const Book &b)
    {
        title=b.title;
        author=b.author;
        price=b.price;
        cout<<"Copy constructor called for "<<title<<endl;
    }

    // destructor - called automatically when the object goes out of scope
    ~Book()
    {
        cout<<"Destructor called for "<<title<<endl;
    }

    void display()
    {
        cout<<"Title  : "<<title<<endl;
        cout<<"Author : "<<author<<endl;
        cout<<"Price  : "<<price<<endl;
    }
};

int main()
{
    Book b1("Let_Us_C++", "Kanetkar", 450);   // original object
    Book b2(b1);                              // copy constructor
    Book b3=b1;                               // copy constructor again

    cout<<"\n--- Original Book (b1) ---"<<endl;
    b1.display();
    cout<<"\n--- Copied Book (b2) ---"<<endl;
    b2.display();
    cout<<"\n--- Copied Book (b3) ---"<<endl;
    b3.display();

    cout<<"\nEnd of main, objects will be destroyed now"<<endl;
    return 0;
}
