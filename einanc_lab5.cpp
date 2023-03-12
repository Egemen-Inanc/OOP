#include<iostream>
#include<string>
using namespace std;

class Publication
{
private:   
    string title;
    float price;
    int ID;
    static int counter;

public:
    Publication(string n,float p)
    {
        title = n;
        price = p;
        ID = counter++;
        
    }

    void pPublication()
    {
        cout<<"title: "<<title<<endl;
        cout<<"price: "<<price<<endl;
        cout<<"ID: "<<ID<<endl;
    }
};

int Publication::counter = 0;

class Sales
{
private:
    int sale_numbers;

public:
  

    int& pullSales()
    {
        return sale_numbers;
    }
    
      Sales(int a)
    {
        sale_numbers=a;
    }

    void pSales()
    {
        cout<<"number of sales: "<<sale_numbers<<endl;
    }

};

class Book : public Publication , public Sales
{
private:
    int page_count;

public:
    Book(string n,float p,int s,int pc):Publication(n,p),Sales(s)
    {
        page_count = pc;
    }

    void printPages()
    {
        cout<<"page count: "<<page_count<<endl;
    }

};

void showBook(Book b)
{
    b.pPublication();
    b.pSales();
    b.printPages();
}

class Tape : public Publication , public Sales
{
private:
    float tp_length;

public:
    Tape(string n,float p,int s,float l):Publication(n,p),Sales(s)
    {
        tp_length = l;
    }

    void pLength()
    {
        cout<<"length: "<<tp_length<<endl;
    }

};

void showTape(Tape t)
{
    t.pPublication();
    t.pSales();
    t.pLength();
}

int main()
{

    Publication test1("Harry Potter and Philosophers Stone", 10.50);
    Publication test2("Automated Orange", 40.00);
    Publication test3("I have no mouth and I must scream", 74.99);

 
     Sales sale1(20);
    Sales sale2(985);
    Sales sale3(1250);

    sale1.pSales();
    sale2.pSales();
    sale3.pSales();

    cout<<"-----------------------------------------------\n";
    
    test1.pPublication();
    test2.pPublication();
    test3.pPublication();
    
    cout<<"-----------------------------------------------\n";
    
    Tape testT("Test Tape",49.99,45000,365);
    
    showTape(testT);


    cout<<"-----------------------------------------------\n";

    
    Book testB("Test Book",25.50,365,49);

    showBook(testB);

    
}