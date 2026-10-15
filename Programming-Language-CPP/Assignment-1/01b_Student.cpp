// Assignment 1 (b): Class Student with roll number, name and marks.
// Accept and display student details and calculate the result.
#include<iostream>
#include<string>
using namespace std;

class Student
{
    int rollNo;
    string name;
    float marks[3];     // marks of 3 subjects

public:
    void getData()
    {
        cout<<"Enter roll number: ";
        cin>>rollNo;
        cout<<"Enter name: ";
        cin>>name;
        for(int i=0;i<3;i++)
        {
            cout<<"Enter marks of subject "<<i+1<<" (out of 100): ";
            cin>>marks[i];
        }
    }

    float percentage()
    {
        float total=0;
        for(int i=0;i<3;i++)
            total=total+marks[i];
        return total/3;
    }

    void display()
    {
        cout<<"\nRoll Number : "<<rollNo<<endl;
        cout<<"Name        : "<<name<<endl;
        for(int i=0;i<3;i++)
            cout<<"Subject "<<i+1<<"   : "<<marks[i]<<endl;
        cout<<"Percentage  : "<<percentage()<<"%"<<endl;

        // pass only if every subject is 40 or above
        bool pass=true;
        for(int i=0;i<3;i++)
            if(marks[i]<40)
                pass=false;

        if(pass)
            cout<<"Result      : PASS"<<endl;
        else
            cout<<"Result      : FAIL"<<endl;
    }
};

int main()
{
    Student s;
    s.getData();
    s.display();
    return 0;
}
