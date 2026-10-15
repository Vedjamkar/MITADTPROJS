// Assignment 8 (repeated as 10 in the handout):
// Single inheritance using Person and Student classes, and
// multilevel inheritance using Vehicle, Car and ElectricCar classes.
#include<iostream>
#include<string>
using namespace std;

// ---------- Single inheritance: Person -> Student ----------
class Person
{
protected:
    string name;
    int age;
public:
    void getPerson()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }
    void showPerson()
    {
        cout<<"Name    : "<<name<<endl;
        cout<<"Age     : "<<age<<endl;
    }
};

class Student : public Person
{
    int rollNo;
    string course;
public:
    void getStudent()
    {
        getPerson();            // function of the base class
        cout<<"Enter roll number: ";
        cin>>rollNo;
        cout<<"Enter course: ";
        cin>>course;
    }
    void showStudent()
    {
        showPerson();
        cout<<"Roll No : "<<rollNo<<endl;
        cout<<"Course  : "<<course<<endl;
    }
};

// ---------- Multilevel inheritance: Vehicle -> Car -> ElectricCar ----------
class Vehicle
{
protected:
    string brand;
    int wheels;
public:
    void setVehicle(string b, int w)
    {
        brand=b;
        wheels=w;
    }
    void showVehicle()
    {
        cout<<"Brand        : "<<brand<<endl;
        cout<<"Wheels       : "<<wheels<<endl;
    }
};

class Car : public Vehicle
{
protected:
    string model;
    int seats;
public:
    void setCar(string m, int s)
    {
        model=m;
        seats=s;
    }
    void showCar()
    {
        showVehicle();
        cout<<"Model        : "<<model<<endl;
        cout<<"Seats        : "<<seats<<endl;
    }
};

class ElectricCar : public Car
{
    int batteryKWh;
    int rangeKm;
public:
    void setElectricCar(int bat, int range)
    {
        batteryKWh=bat;
        rangeKm=range;
    }
    void showElectricCar()
    {
        showCar();              // Car::showCar() in turn calls Vehicle::showVehicle()
        cout<<"Battery      : "<<batteryKWh<<" kWh"<<endl;
        cout<<"Range        : "<<rangeKm<<" km"<<endl;
    }
};

int main()
{
    cout<<"===== Single Inheritance ====="<<endl;
    Student s;
    s.getStudent();
    cout<<"\nStudent details:"<<endl;
    s.showStudent();

    cout<<"\n===== Multilevel Inheritance ====="<<endl;
    ElectricCar ec;
    ec.setVehicle("Tata", 4);       // from Vehicle
    ec.setCar("Nexon_EV", 5);       // from Car
    ec.setElectricCar(40, 465);     // its own function
    ec.showElectricCar();
    return 0;
}
