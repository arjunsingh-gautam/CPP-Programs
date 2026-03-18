# **<span style="color:#00E5FF">Compile-Time vs Run-Time Polymorphism (C++)</span>**

---

## **<span style="color:#FFEA00">What is Compile-Time Polymorphism</span>**

**Compile-Time Polymorphism** means:

> The function call is resolved **at compile time**

- Also called:
  - **Static Binding**
  - **Early Binding**

### **How it is achieved**

- Function Overloading
- Operator Overloading
- Templates (important advanced case)

---

## **<span style="color:#00FF9C">Working (Step-by-Step Walkthrough)</span>**

```cpp id="k1h9ax"
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;        // int version
    cout << m.add(2.5, 3.5) << endl;    // double version
}
```

### **Execution Flow**

1. Compiler sees `m.add(2,3)`
2. Matches function signature → `int add(int,int)`
3. Generates **direct function call**

### **Important Insight**

- Decision is made **before execution**
- No runtime decision involved

---

## **<span style="color:#FF5733">Overheads (Compile-Time)</span>**

- **Minimal / Almost Zero**
  - No vtable
  - No indirection
  - Direct call → highly optimized

- Possible downside:
  - **Code bloat (templates)** → multiple copies generated

---

## **<span style="color:#00FF9C">Benefits (Compile-Time)</span>**

- Extremely **fast execution**
- **Inline optimization possible**
- Simple and predictable behavior
- No extra memory overhead

---

---

# **<span style="color:#00E5FF">Run-Time Polymorphism</span>**

---

## **<span style="color:#FFEA00">What is Run-Time Polymorphism</span>**

**Run-Time Polymorphism** means:

> The function call is resolved **during execution (runtime)**

- Also called:
  - **Dynamic Binding**
  - **Late Binding**

### **How it is achieved**

- Inheritance
- Virtual functions
- Base class pointer/reference

---

## **<span style="color:#00FF9C">Working (Step-by-Step Walkthrough)</span>**

```cpp id="4x9r2j"
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

int main() {
    Shape* s;
    Circle c;

    s = &c;
    s->draw();   // runtime decision
}
```

---

### **Execution Flow (Deep Understanding)**

1. `Shape* s = &c;`
   - Pointer type = `Shape*`
   - Object type = `Circle`

2. Compiler sees:

   ```cpp
   s->draw();
   ```

   - Cannot decide at compile time

3. At runtime:
   - Object (`Circle`) has **vptr**
   - vptr → points to **vtable of Circle**

4. Program:
   - Looks up `draw()` in vtable
   - Calls `Circle::draw()`

---

### **Key Internal Concept**

- **vptr (Virtual Pointer)** → inside object
- **vtable (Virtual Table)** → function mapping

> This is what enables dynamic dispatch

---

## **<span style="color:#FF5733">Overheads (Run-Time)</span>**

### **1. Runtime Cost**

- Extra **pointer lookup (vtable access)**

### **2. Memory Overhead**

- Each object stores **vptr**

### **3. Cache Impact**

- Indirect calls → less predictable for CPU

### **4. No Inlining**

- Compiler cannot inline virtual functions easily

---

## **<span style="color:#00FF9C">Benefits (Run-Time)</span>**

### **1. Flexibility**

- Behavior depends on **actual object type**

### **2. Extensibility**

- Add new derived classes without modifying old code

### **3. Clean Architecture**

- Eliminates `if-else` chains

### **4. Real-world Modeling**

- Models real systems naturally (polymorphic behavior)

---

---

# **<span style="color:#00E5FF">Direct Comparison</span>**

| Feature         | Compile-Time           | Run-Time          |
| --------------- | ---------------------- | ----------------- |
| Binding Time    | Compile Time           | Run Time          |
| Speed           | Very Fast              | Slightly Slower   |
| Mechanism       | Overloading, Templates | Virtual Functions |
| Memory Overhead | None                   | vptr per object   |
| Flexibility     | Low                    | High              |
| Optimization    | High (Inlining)        | Limited           |
| Use Case        | Performance-critical   | Scalable design   |

---

## **<span style="color:#FFEA00">When to Use What (Engineering Perspective)</span>**

### **Use Compile-Time Polymorphism When**

- Performance is critical (HFT, systems programming)
- Behavior is known beforehand

### **Use Run-Time Polymorphism When**

- You need **extensibility**
- System evolves with new types
- You want clean architecture

---

## **<span style="color:#00FF9C">Final Insight (Very Important)</span>**

> Good engineers **balance both**

- Use **compile-time polymorphism for speed**
- Use **run-time polymorphism for flexibility**

---
