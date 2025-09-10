/* # include <iostream>
int main()
{
    int num;
    std::cout<<"Enter a number:";
    std::cin>>num;
    std::cout<<"Square of "<<num<<" is:"<<num*num<<std::endl;
    return 0;

} */

// using Keyword
/* #include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number:";
    cin>>num;
    cout<<"Square of "<<num<<" is:"<<num*num;
    return 0;
} */

// namespace
#include <iostream>
using namespace std;
namespace l1{
    void greet(const char *p){
        printf("Message from l1\n");
        cout<<"Hello "<<p<<endl;
    }
}
namespace l2{
    void greet(const char *p){
        printf("Message from l2\n");
        cout<<"Hello "<<p<<endl;
    }
}
int main()
{
    l1::greet("Arjun");
    l2::greet("Ashish");
    return 0;
}

/* practice.cpp: In function 'int main()':
practice.cpp:41:15: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
   41 |     l1::greet("Arjun");
      |               ^~~~~~~
practice.cpp:42:15: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
   42 |     l2::greet("Ashish");
      |               ^~~~~~~~ */

// To prevent this use const char *p