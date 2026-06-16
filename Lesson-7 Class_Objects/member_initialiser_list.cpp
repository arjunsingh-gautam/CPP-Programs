// Member Initialiser List

#include <iostream>

class Vector
{
public:
    float x;
    float y;
    float z;

    Vector(
        float x = 0.0f,
        float y = 0.0f,
        float z = 0.0f)
        : x(x),
          y(y),
          z(z)
    {
        std::cout
            << "Vector Created"
            << std::endl;
    }

    Vector operator+(const Vector &rhs) const
    {
        return Vector(
            x + rhs.x,
            y + rhs.y,
            z + rhs.z);
    }

    Vector operator-(const Vector &rhs) const
    {
        return Vector(
            x - rhs.x,
            y - rhs.y,
            z - rhs.z);
    }

    bool operator==(const Vector &rhs) const
    {
        return x == rhs.x &&
               y == rhs.y &&
               z == rhs.z;
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