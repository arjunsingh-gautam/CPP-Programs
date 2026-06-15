# **<span style="color:#00E5FF">Structure in C++</span>**

---

## **<span style="color:#FFEA00">What is a Structure</span>**

> A **structure (`struct`)** is a user-defined data type that groups **related variables** under one name.

```cpp
struct Point {
    int x;
    int y;
};
```

---

# **<span style="color:#00E5FF">C Structure vs C++ Structure</span>**

---

## **<span style="color:#FFEA00">Similarities</span>**

- Both can:
  - Group multiple variables
  - Have different data types
  - Be used to model real-world entities

```cpp
struct Student {
    int id;
    float marks;
};
```

---

## **<span style="color:#FF5733">Key Differences</span>**

| Feature                 | C Struct       | C++ Struct |
| ----------------------- | -------------- | ---------- |
| Functions inside struct | ❌ Not allowed | ✔ Allowed  |
| Access specifiers       | ❌ No          | ✔ Yes      |
| Constructors            | ❌ No          | ✔ Yes      |
| Inheritance             | ❌ No          | ✔ Yes      |
| Polymorphism            | ❌ No          | ✔ Yes      |
| Encapsulation           | ❌ No          | ✔ Yes      |
| Default access          | Public         | Public     |

---

## **<span style="color:#00FF9C">Core Insight</span>**

> In C++, `struct` is almost the same as a **class**,
> only difference:

- `struct` → default **public**
- `class` → default **private**

---

# **<span style="color:#00E5FF">Extended Features of C++ Struct</span>**

Now we go feature-by-feature with:

- Usage
- Benefit
- Example

---

# **<span style="color:#FFEA00">1. Member Functions</span>**

## **What**

Struct can contain functions

---

## **Example**

```cpp
#include <iostream>
using namespace std;

struct Rectangle {
    int width, height;

    int area() {
        return width * height;
    }
};
```

---

## **Benefit**

- Keeps **data + behavior together**
- Improves **encapsulation**

---

# **<span style="color:#FFEA00">2. Constructors</span>**

## **What**

Struct can initialize objects automatically

---

## **Example**

```cpp
struct Point {
    int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};
```

---

## **Benefit**

- Ensures object is always **properly initialized**
- Cleaner code

---

# **<span style="color:#FFEA00">3. Access Specifiers</span>**

## **What**

Control access using:

- `public`
- `private`
- `protected`

---

## **Example**

```cpp
struct Account {
private:
    int balance;

public:
    void setBalance(int b) {
        balance = b;
    }

    int getBalance() {
        return balance;
    }
};
```

---

## **Benefit**

- Enables **data hiding**
- Protects internal data

---

# **<span style="color:#FFEA00">4. Inheritance</span>**

## **What**

Struct can inherit from another struct

---

## **Example**

```cpp
struct Animal {
    void sound() {
        cout << "Animal sound\n";
    }
};

struct Dog : public Animal {
    void bark() {
        cout << "Dog barks\n";
    }
};
```

---

## **Benefit**

- Code reuse
- Hierarchical design

---

# **<span style="color:#FFEA00">5. Polymorphism (with virtual functions)</span>**

## **Example**

```cpp
#include <iostream>
using namespace std;

struct Base {
    virtual void show() {
        cout << "Base\n";
    }
};

struct Derived : Base {
    void show() override {
        cout << "Derived\n";
    }
};
```

---

## **Benefit**

- Runtime flexibility
- Clean architecture

---

# **<span style="color:#FFEA00">6. Operator Overloading</span>**

## **What**

Define custom behavior for operators

---

## **Example**

```cpp
struct Complex {
    int real, imag;

    Complex operator+(const Complex& c) {
        return {real + c.real, imag + c.imag};
    }
};
```

---

## **Benefit**

- Natural syntax
- Cleaner mathematical modeling

---

# **<span style="color:#FFEA00">7. Static Members</span>**

## **What**

Shared across all objects

---

## **Example**

```cpp
struct Counter {
    static int count;

    Counter() {
        count++;
    }
};

int Counter::count = 0;
```

---

## **Benefit**

- Shared state
- Useful for tracking objects

---

# **<span style="color:#FFEA00">8. Default Member Initialization (C++11)</span>**

## **Example**

```cpp
struct Test {
    int x = 10;
    int y = 20;
};
```

---

## **Benefit**

- Cleaner initialization
- Reduces constructor boilerplate

---

# **<span style="color:#FFEA00">9. Struct as Class (Important Insight)</span>**

```cpp
struct A {
    int x;
};
```

is equivalent to:

```cpp
class A {
public:
    int x;
};
```

---

## **<span style="color:#00FF9C">Key Difference</span>**

| Keyword | Default Access |
| ------- | -------------- |
| struct  | public         |
| class   | private        |

---

# **<span style="color:#FF5733">When to Use struct vs class</span>**

### **Use struct when:**

- Data is mostly public
- Simple data container

### **Use class when:**

- Encapsulation required
- Complex behavior

---

# **<span style="color:#00FF9C">Key Takeaways</span>**

- C++ struct is **much more powerful than C struct**
- Supports:
  - Functions
  - OOP concepts
  - Advanced features

- Difference from class is mostly **convention + default access**

---

## **<span style="color:#FFEA00">Next Step (Recommended)</span>**

To deepen your understanding (important for system design & HFT):

- **Memory layout of struct (padding, alignment)**
- **POD vs non-POD types**
- **Trivial vs non-trivial types**

I can break that down with **memory diagrams + performance insights** if you want.
