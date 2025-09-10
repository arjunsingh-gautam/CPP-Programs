/* Exercise 1.22: Write a program that reads several transactions for the same
ISBN. Write the sum of all the transactions that were read. */

/* #include<iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item book;
    Sales_item sum;
    int i=1;
    cout<<"Enter Transactions:"<<endl;
    while(cin>>book){
        cout<<"Transaction-"<<i<<" is:"<<book<<endl;
        sum+=book;
        i++;
    }
    cout<<"Cummulative Transaction:"<<sum<<endl;
    return 0;
}
 */

// Optimised Solution:

#include<iostream>
#include "Sales_item.h"
using namespace std;

int main() {
    Sales_item sum;  // Store cumulative sum of transactions
    Sales_item book; // Store individual transactions
    
    cout << "Enter transactions (same ISBN):" << endl;
    
    if (cin >> sum) { // Read the first transaction to initialize `sum`
        while (cin >> book) {
            if (book.isbn() == sum.isbn()) { // Check if ISBNs match
                sum += book; // Add valid transactions
            } else {
                cout << "Error: Different ISBN encountered!" << endl;
                return 1; // Exit with error
            }
        }
        cout << "Cumulative Transaction: " << sum << endl;
    } else {
        cout << "No valid transaction entered." << endl;
    }

    return 0;
}
