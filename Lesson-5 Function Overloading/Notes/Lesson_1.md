# **<span style="color:#00E5FF">Polymorphism in C++</span>**

---

## **<span style="color:#FFEA00">What is Polymorphism</span>**

**Polymorphism** means **"one interface, multiple behaviors"**.

- Same function / method name
- Different behavior depending on **object type**

### **Core Idea**

> You write **generic code**, but it behaves **differently for different objects**

---

## **<span style="color:#FFEA00">Necessary Conditions for Polymorphism</span>**

### **1. Common Interface (Base Class)**

- There must be a **base class pointer/reference**
- Functions should be declared in base class

### **2. Function Overriding (Runtime Polymorphism)**

- Derived classes must **override base class functions**

### **3. Late Binding (Dynamic Binding)**

- Function call resolved **at runtime**, not compile time

### **4. Virtual Function (C++ Specific Requirement)**

- Base class function must be marked `virtual`

---

### **<span style="color:#00FF9C">Are these conditions language dependent?</span>**

**Yes.**

- **C++ → requires `virtual` keyword**
- **Java → methods are virtual by default**
- **Python → dynamic typing handles polymorphism automatically**

> So implementation differs, but concept remains same

---

## **<span style="color:#FFEA00">Polymorphism in C++</span>**

### **Two Types**

### **1. Compile-Time (Static Polymorphism)**

- Function overloading
- Operator overloading

```cpp
int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }
```

---

### **2. Runtime (Dynamic Polymorphism)**

- Achieved using:
  - Inheritance
  - Virtual functions
  - Base class pointer

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks\n";
    }
};

int main() {
    Animal* a;
    Dog d;

    a = &d;
    a->sound();   // Runtime polymorphism

    return 0;
}
```

### **Key Insight**

- `a->sound()` depends on **actual object (Dog)**
- Not on pointer type (Animal)

---

## **<span style="color:#FFEA00">Why Polymorphism is Important</span>**

### **1. Abstraction**

- Focus on **what**, not **how**

### **2. Extensibility**

- Add new classes without modifying existing code

### **3. Loose Coupling**

- Code depends on **interface**, not implementation

### **4. Code Reusability**

- Generalized code works for multiple types

---

## **<span style="color:#00FF9C">Real Engineering Analogy</span>**

Think of:

- `Animal* a` → Remote control
- Different objects → TV, AC, Fan

Same button (`sound()`) → Different behavior

---

## **<span style="color:#FFEA00">Benefits with Simple Example</span>**

### **Without Polymorphism**

```cpp
if(type == "dog") bark();
else if(type == "cat") meow();
```

### **With Polymorphism**

```cpp
Animal* a = getAnimal();
a->sound();
```

### **Why this is powerful**

- No `if-else` explosion
- Cleaner, scalable design
- Add new animals without changing existing code

---

## **<span style="color:#FFEA00">Constraints and Overheads</span>**

### **1. Runtime Overhead (vtable)**

- Virtual functions use **vtable (virtual table)**
- Extra pointer lookup → slight performance cost

---

### **2. Memory Overhead**

- Each polymorphic class has:
  - **vptr (virtual pointer)**

---

### **3. Indirection Cost**

- Function call not direct → slower than inline/static

---

### **4. Debugging Complexity**

- Harder to trace actual function being called

---

### **5. Cannot Inline Virtual Functions Easily**

- Compiler cannot optimize aggressively

---

## **<span style="color:#FF5733">Key Takeaways</span>**

- Polymorphism = **same interface, different behavior**
- In C++ → requires:
  - Inheritance
  - Virtual functions
  - Base pointer/reference

- Enables:
  - Scalable design
  - Clean architecture

- Tradeoff:
  - Small performance + memory overhead

---
