// CPP style struct

#include <iostream>
using namespace std;

// Struct definition
struct Book
{
private: // Access Specifier now this members can't be accessed outside struct scope
    int bookid;
    char title[50];
    float price;

public: // Access Specifier this member methods can be accessed outside struct scope
    void input_data()
    {
        cout << "Enter Book ID:";
        cin >> bookid;
        // Data Integrity Handling  bookid should be positive
        if (bookid < 0)
        {
            bookid = -bookid;
        }
        cin.ignore();
        cout << "Enter Book Title:";
        cin.getline(title, 50);
        cout << "Enter Book Price";
        cin >> price;
    }
    void display_data()
    {
        cout << "Book Details:\n"
             << "Book ID:" << bookid << "\tBook Title:" << title << "\tBook Price:" << price << endl;
    }
};

int main()
{
    Book b1, b2;
    b1.input_data();
    b2.input_data();
    b1.display_data();
    b2.display_data();
}