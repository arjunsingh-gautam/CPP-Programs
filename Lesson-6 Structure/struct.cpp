// In this program we will create a structure for book having bookid,title,price 
// A function to input data
// A function to display book details

// C style struct
#include<iostream>
using namespace std;
typedef struct
{
    int bookid;
    char title[100];
    float price;
}Book;

void input_data(Book *ptr);
void display_data(Book *ptr);
int main()
{
    Book b1;
    Book *ptr=&b1;
    input_data(ptr);
    display_data(ptr);
}
void input_data(Book *ptr)
{
    
    cout<<"Enter Book Id:";
    cin>>ptr->bookid;
    cin.ignore();
    cout<<"Enter Book Title:";
    cin.getline(ptr->title,100);// cin.getline(const * char,size) used to take string input with white spaces
    cout<<"Enter Book Price:";
    cin>>ptr->price;
}

void display_data(Book * ptr)
{
    cout<<"Book Details are as follows:\n";
    cout<<"Book Title:"<<ptr->title<<"\n"<<"Book Price:"<<ptr->price<<"\n"<<"Book ID:"<<ptr->bookid<<"\n";
}