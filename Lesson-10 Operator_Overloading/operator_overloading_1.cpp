// Demonstrating Operator Overloading in C++17
#include <iostream>

class Vector
{
public:
    float x, y, z;

public:
    Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
        std::cout << "Vector Created" << std::endl;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector operator+(const Vector &rhs)
    {
        Vector result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;
        return result;
    }

    Vector operator-(const Vector &rhs)
    {
        Vector result;
        result.x = x - rhs.x;
        result.y = y - rhs.y;
        result.z = z - rhs.z;
        return result;
    }

    bool operator==(const Vector &rhs) const
    {
        if (x == rhs.x && y == rhs.y && z == rhs.z)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "Vector is:" << "(" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
    return os;
}

int main()
{
    Vector v1(1.0f, 2.0f, 3.0f);
    std::cout << v1;
    Vector v2(4.3f, 5.3f, -11.0f);
    std::cout << v2;
    Vector v3 = v1 + v2;
    std::cout << v3;
    Vector v4 = v1 - v2;
    std::cout << v4;

    if (v1 == v2)
    {
        std::cout << "Vectors are equal" << std::endl;
    }
    else
    {
        std::cout << "Vectors are not equal" << std::endl;
    }
}