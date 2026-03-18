# **<span style="color:#00E5FF">Functional Polymorphism (Function Overloading in C++)</span>**

---

## **<span style="color:#FFEA00">What is Functional Polymorphism</span>**

**Functional Polymorphism** (Function Overloading) means:

> Multiple functions with the **same name** but **different parameters**

- Compiler decides **which function to call** based on arguments
- Happens at **compile time**

---

## **<span style="color:#FFEA00">Conditions for Function Overloading</span>**

For overloading to work correctly, functions must differ in **function signature**.

### **Valid Conditions (At least one must differ)**

### **1. Number of Parameters**

```cpp
int add(int a, int b);
int add(int a, int b, int c);
```

---

### **2. Type of Parameters**

```cpp
int add(int a, int b);
double add(double a, double b);
```

---

### **3. Order of Parameters (if types differ)**

```cpp
void func(int a, double b);
void func(double a, int b);
```

---

## **<span style="color:#FF5733">Invalid Conditions (Do NOT count as overloading)</span>**

### **1. Only Return Type Different**

```cpp
int func(int a);
double func(int a);   // ERROR
```

> Compiler cannot decide based only on return type

---

### **2. Parameter Names Different (but same types)**

```cpp
int func(int a);
int func(int x);   // SAME signature → ERROR
```

---

## **<span style="color:#FFEA00">How Function Overloading is Implemented in C++</span>**

### **Concept: Name Mangling**

C++ compiler internally changes function names to encode:

- Function name
- Parameter types

### **Example**

```cpp
int add(int, int);        // add_int_int
double add(double, double); // add_double_double
```

(Actual mangled names are more complex)

---

## **<span style="color:#00FF9C">Working Example (Step-by-Step)</span>**

```cpp id="j4kp0n"
#include <iostream>
using namespace std;

class Printer {
public:
    void print(int x) {
        cout << "Integer: " << x << endl;
    }

    void print(double x) {
        cout << "Double: " << x << endl;
    }

    void print(string x) {
        cout << "String: " << x << endl;
    }
};

int main() {
    Printer p;

    p.print(10);        // calls int version
    p.print(3.14);      // calls double version
    p.print("Hello");   // calls string version
}
```

---

### **Execution Walkthrough**

1. `p.print(10)`
   - Compiler checks all `print()` functions
   - Finds best match → `print(int)`

2. `p.print(3.14)`
   - Matches → `print(double)`

3. `p.print("Hello")`
   - Matches → `print(string)`

---

### **Important Insight**

> This is resolved **completely at compile time**

No runtime overhead

---

## **<span style="color:#FFEA00">What is Function Signature</span>**

### **Definition**

> Function signature = **function name + parameter list**

Includes:

- Number of parameters
- Types of parameters
- Order of parameters

---

### **What it does NOT include**

- Return type
- Parameter names

---

## **<span style="color:#00FF9C">Why Function Signature is Important</span>**

### **1. Uniquely Identifies Functions**

- Compiler uses it to distinguish overloaded functions

---

### **2. Enables Compile-Time Resolution**

- Decides which function to call **without ambiguity**

---

### **3. Prevents Conflicts**

- If two functions have same signature → compilation error

---

## **<span style="color:#FF5733">Ambiguity Problem (Very Important)</span>**

Sometimes compiler cannot decide best match:

```cpp id="c9b7sy"
void func(int a);
void func(double a);

func(10.5f);   // float → ambiguous
```

### **Why?**

- `float` can convert to:
  - `int`
  - `double`

> Compiler gets confused → error

---

## **<span style="color:#00FF9C">How Compiler Resolves Overloading</span>**

Priority order:

1. Exact match
2. Promotion (int → double)
3. Standard conversion
4. User-defined conversion

---

## **<span style="color:#FFEA00">Benefits of Function Overloading</span>**

### **1. Code Readability**

- Same function name → logical grouping

---

### **2. Ease of Use**

- No need to remember multiple function names

---

### **3. Compile-Time Efficiency**

- No runtime cost

---

### **4. Cleaner API Design**

- Looks natural and intuitive

---

## **<span style="color:#FF5733">Constraints / Limitations</span>**

- Cannot overload based only on return type
- Can lead to **ambiguity errors**
- Complex overloads → harder to debug
- Implicit conversions can cause unexpected behavior

---

## **<span style="color:#00FF9C">Key Takeaways</span>**

- Function overloading = **same name, different signatures**
- Signature = **name + parameters (type, count, order)**
- Resolved at **compile time**
- Implemented using **name mangling**
- Powerful but must avoid **ambiguity**

---
