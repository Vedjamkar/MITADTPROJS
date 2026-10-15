// Assignment 3: Class Product containing an array for monthly sales.
// Create an array of Product objects and display product details,
// total quantity sold and total bill.
#include<iostream>
#include<string>
using namespace std;

class Product
{
    int id;
    string name;
    float price;
    int monthlySale[12];    // array inside the class

public:
    void getData()
    {
        cout<<"Enter product id: ";
        cin>>id;
        cout<<"Enter product name: ";
        cin>>name;
        cout<<"Enter price per unit: ";
        cin>>price;
        cout<<"Enter quantity sold in each month (12 values): ";
        for(int i=0;i<12;i++)
            cin>>monthlySale[i];
    }

    int totalQuantity()
    {
        int total=0;
        for(int i=0;i<12;i++)
            total=total+monthlySale[i];
        return total;
    }

    float totalBill()
    {
        return totalQuantity()*price;
    }

    void display()
    {
        cout<<"Product Id     : "<<id<<endl;
        cout<<"Product Name   : "<<name<<endl;
        cout<<"Price          : "<<price<<endl;
        cout<<"Total Quantity : "<<totalQuantity()<<endl;
        cout<<"Total Bill     : "<<totalBill()<<endl;
    }
};

int main()
{
    Product p[10];      // array of objects (max 10 products)
    int n;

    cout<<"Enter number of products (max 10): ";
    cin>>n;
    if(n<1 || n>10)
    {
        cout<<"Invalid number of products"<<endl;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        cout<<"\n--- Enter details of product "<<i+1<<" ---"<<endl;
        p[i].getData();
    }

    float grandTotal=0;
    cout<<"\n========== Product Details =========="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\nProduct "<<i+1<<endl;
        p[i].display();
        grandTotal=grandTotal+p[i].totalBill();
    }
    cout<<"\nGrand total of all products: "<<grandTotal<<endl;
    return 0;
}
