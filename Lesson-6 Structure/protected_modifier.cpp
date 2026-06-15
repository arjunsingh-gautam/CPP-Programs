// Protected Access modifier
#include <iostream>
class A
{
private:
    int x;

public:
    void setX(int val)
    {
        x = val;
    }

    int getX()
    {
        return x;
    }
};

int main()
{
    A obj;
    // obj.x = 10;  ❌ ERROR
    obj.setX(10); // ✔ allowed
    std::cout << obj.getX();
}