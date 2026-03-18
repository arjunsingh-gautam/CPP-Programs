# **<span style="color:#00E5FF">Compiler Algorithm for Function Overloading Resolution (C++)</span>**

This is one of the **most important deep concepts** for mastering C++.

> Goal: Understand **how compiler decides which overloaded function to call**

---

## **<span style="color:#FFEA00">High-Level Idea</span>**

When compiler sees a function call:

```cpp
func(args);
```

It performs:

1. **Candidate Collection**
2. **Viable Function Filtering**
3. **Conversion Ranking**
4. **Best Match Selection**
5. **Ambiguity Check**

---

# **<span style="color:#00E5FF">Step-by-Step Compiler Algorithm</span>**

---

## **<span style="color:#FFEA00">Step 1: Candidate Function Collection</span>**

Compiler collects all functions with same name:

```cpp
void func(int);
void func(double);
void func(string);
```

All become **candidate set**

---

## **<span style="color:#FFEA00">Step 2: Viable Function Filtering</span>**

A function is **viable** if:

- Number of parameters match
- Each argument can be **converted** to parameter type

---

## **<span style="color:#00FF9C">Example</span>**

```cpp
void func(int);
void func(double);

func(10);
```

Both are viable:

- `int → int` (exact)
- `int → double` (conversion)

---

## **<span style="color:#FFEA00">Step 3: Conversion Ranking</span>**

Compiler assigns **priority to conversions**

### **Ranking (Best → Worst)**

1. **Exact Match**
2. **Promotion**
   - `char → int`
   - `float → double`

3. **Standard Conversion**
   - `int → double`
   - `double → int`

4. **User-Defined Conversion**
   - Constructors
   - `operator T()`

5. **Ellipsis (`...`)**
   - Worst match

---

## **<span style="color:#FFEA00">Step 4: Best Match Selection</span>**

- Compare all viable functions
- Choose function with **best conversion sequence**

---

## **<span style="color:#FFEA00">Step 5: Ambiguity Check</span>**

If:

- Two functions have **same rank**

→ **Compilation Error (Ambiguous call)**

---

# **<span style="color:#00E5FF">Walkthrough Examples (Different Paths)</span>**

---

## **<span style="color:#00FF9C">Case 1: Exact Match Found</span>**

```cpp
void func(int);
void func(double);

func(10);
```

### **Analysis**

| Function     | Conversion   |
| ------------ | ------------ |
| func(int)    | Exact        |
| func(double) | int → double |

### **Result**

- Exact match wins

---

## **<span style="color:#FFEA00">Case 2: No Exact Match → Promotion</span>**

```cpp
void func(int);
void func(double);

char c = 'A';
func(c);
```

### **Analysis**

| Function     | Conversion             |
| ------------ | ---------------------- |
| func(int)    | char → int (promotion) |
| func(double) | char → double          |

### **Result**

- Promotion preferred → `func(int)`

---

## **<span style="color:#FFEA00">Case 3: Standard Conversion Used</span>**

```cpp
void func(double);

func(10);
```

### **Analysis**

- `int → double` (standard conversion)

### **Result**

- Only viable function → selected

---

## **<span style="color:#FF5733">Case 4: Ambiguity (Same Rank)</span>**

```cpp
void func(int);
void func(double);

func(10.5f);  // float
```

### **Analysis**

| Function     | Conversion     |
| ------------ | -------------- |
| func(int)    | float → int    |
| func(double) | float → double |

Both are:

- Standard conversions

### **Result**

> ERROR: Ambiguous

---

## **<span style="color:#00FF9C">Case 5: User-Defined Conversion</span>**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A(int x) { cout << "A constructed\n"; }
};

void func(A obj);

int main() {
    func(10);
}
```

---

### **Analysis**

- No exact match
- No built-in conversion to `A`
- Uses:
  - `A(int)` constructor → **user-defined conversion**

### **Result**

- `func(A)` selected

---

## **<span style="color:#FF5733">Case 6: Multiple User-Defined → Ambiguity</span>**

```cpp
class A {
public:
    A(int);
};

class B {
public:
    B(int);
};

void func(A);
void func(B);

func(10);
```

---

### **Analysis**

- `int → A` (user-defined)
- `int → B` (user-defined)

Same rank

### **Result**

> ERROR: Ambiguous

---

## **<span style="color:#FFEA00">Case 7: Ellipsis (Worst Case)</span>**

```cpp
void func(int);
void func(...);

func(10);
```

### **Analysis**

| Function  | Conversion |
| --------- | ---------- |
| func(int) | Exact      |
| func(...) | Ellipsis   |

### **Result**

- Exact match wins

---

## **<span style="color:#00FF9C">Case 8: Const Qualification Preference</span>**

```cpp
void func(int& x);
void func(const int& x);

int a = 10;
func(a);
```

### **Result**

- `int&` preferred over `const int&`

---

# **<span style="color:#00E5FF">Important Internal Insight</span>**

### **Compiler builds something like:**

```text
func(int)    → cost = 0
func(double) → cost = 1
```

Then chooses **minimum cost function**

---

# **<span style="color:#FF5733">Common Pitfalls</span>**

- Implicit conversions causing ambiguity
- Multiple user-defined conversions
- Mixing `float`, `double`, `int`
- Overusing overloaded functions

---

# **<span style="color:#00FF9C">Key Takeaways</span>**

- Compiler uses a **ranking-based algorithm**
- Order:

  ```
  Exact > Promotion > Standard > User-defined > Ellipsis
  ```

- Ambiguity occurs when:
  - Same rank conversions exist

- Function signature is **central to resolution**

---

## **<span style="color:#FFEA00">Interview-Level Insight</span>**

> Function overloading resolution is basically:
> **“Find all possible → filter → rank → choose best → else error”**

---
