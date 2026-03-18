# **<span style="color:#00E5FF">Failure Cases in Function Overloading Resolution (C++)</span>**

Now we go deeper:

> When does the compiler **fail to resolve** which overloaded function to call?

These are **critical edge cases** — heavily asked in interviews and important for writing robust C++.

---

# **<span style="color:#FFEA00">High-Level Failure Categories</span>**

Overload resolution fails when:

1. **No viable function found**
2. **Ambiguous match (same ranking)**
3. **Invalid or conflicting conversions**
4. **Const / reference binding issues**
5. **User-defined conversion conflicts**
6. **Template vs non-template conflicts (advanced)**

---

# **<span style="color:#00E5FF">1. No Viable Function Found</span>**

## **<span style="color:#FF5733">Definition</span>**

> No function can accept given arguments (even after conversion)

---

## **Example**

```cpp id="7tnv1r"
void func(int);
void func(double);

func("hello");
```

---

## **Walkthrough**

- `"hello"` → `const char*`
- No conversion to:
  - `int`
  - `double`

### **Result**

> ERROR: No matching function found

---

# **<span style="color:#00E5FF">2. Ambiguity (Same Rank Conversions)</span>**

## **<span style="color:#FF5733">Definition</span>**

> Multiple functions equally good → compiler cannot decide

---

## **Example**

```cpp id="r93q8q"
void func(int);
void func(double);

float x = 10.5;
func(x);
```

---

## **Walkthrough**

| Function     | Conversion                |
| ------------ | ------------------------- |
| func(int)    | float → int (standard)    |
| func(double) | float → double (standard) |

- Same rank
- No clear winner

### **Result**

> ERROR: Ambiguous call

---

# **<span style="color:#00E5FF">3. Ambiguity Due to Multiple Promotions</span>**

## **Example**

```cpp id="yotc7w"
void func(int);
void func(long);

short x = 10;
func(x);
```

---

## **Walkthrough**

| Function   | Conversion               |
| ---------- | ------------------------ |
| func(int)  | short → int (promotion)  |
| func(long) | short → long (promotion) |

- Both are promotions
- Same priority

### **Result**

> ERROR: Ambiguous

---

# **<span style="color:#00E5FF">4. User-Defined Conversion Conflicts</span>**

## **Example**

```cpp id="n7q7r2"
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

## **Walkthrough**

- `int → A` (user-defined)
- `int → B` (user-defined)

Same rank

### **Result**

> ERROR: Ambiguous

---

# **<span style="color:#00E5FF">5. Conflicting Conversion Paths</span>**

## **Example**

```cpp id="d5wr2y"
void func(long);
void func(double);

func(10);
```

---

## **Walkthrough**

- `int → long` (standard)
- `int → double` (standard)

Same rank

### **Result**

> ERROR: Ambiguous

---

# **<span style="color:#00E5FF">6. Const Qualification Conflict</span>**

## **Example**

```cpp id="4okm8h"
void func(int& x);
void func(const int& x);

func(10);
```

---

## **Walkthrough**

- `10` is rvalue

| Function   | Binding                  |
| ---------- | ------------------------ |
| int&       | ❌ cannot bind to rvalue |
| const int& | ✔ allowed                |

### **Result**

> Only one viable → OK

---

## **Failure Variant**

```cpp id="x5x8qp"
void func(const int&);
void func(const int&);

func(10);
```

### **Result**

> Duplicate signature → compilation error

---

# **<span style="color:#00E5FF">7. Reference Binding Failure</span>**

## **Example**

```cpp id="j1vmbn"
void func(int& x);

func(10);
```

---

## **Walkthrough**

- Non-const reference cannot bind to rvalue

### **Result**

> ERROR: No viable function

---

# **<span style="color:#00E5FF">8. Default Argument Conflicts</span>**

## **Example**

```cpp id="l4gq9k"
void func(int a);
void func(int a, int b = 0);

func(10);
```

---

## **Walkthrough**

Both match:

- `func(int)`
- `func(int, default)`

### **Result**

> ERROR: Ambiguous

---

# **<span style="color:#00E5FF">9. Function Template Ambiguity (Advanced)</span>**

## **Example**

```cpp id="rgph6o"
template<typename T>
void func(T);

void func(int);

func(10);
```

---

## **Walkthrough**

- Exact match → non-template preferred

### **Result**

> Calls `func(int)` → OK

---

## **Failure Variant**

```cpp id="v6utxg"
template<typename T>
void func(T);

template<typename T>
void func(T*);

int x = 10;
func(&x);
```

---

### **Walkthrough**

- `T = int*`
- `T* = int*`

Same rank

### **Result**

> ERROR: Ambiguous

---

# **<span style="color:#00E5FF">10. Ellipsis Conflict (Rare but Important)</span>**

## **Example**

```cpp id="7zrz9m"
void func(int);
void func(...);

func(10);
```

---

## **Walkthrough**

- Exact match vs ellipsis

### **Result**

> Exact match wins → OK

---

## **Failure Variant**

```cpp id="v9s3cd"
void func(...);
void func(...);

func(10);
```

### **Result**

> ERROR: Duplicate / ambiguous

---

# **<span style="color:#FFEA00">Summary of All Failure Scenarios</span>**

| Scenario                          | Reason                        |
| --------------------------------- | ----------------------------- |
| No viable function                | No valid conversion exists    |
| Ambiguous standard conversions    | Same rank                     |
| Ambiguous promotions              | Same rank                     |
| Multiple user-defined conversions | Same rank                     |
| Reference binding failure         | Invalid binding rules         |
| Const conflicts                   | Qualification mismatch        |
| Default argument ambiguity        | Multiple valid paths          |
| Template ambiguity                | Multiple equally good matches |

---

# **<span style="color:#00FF9C">Deep Insight (Very Important)</span>**

> Compiler fails when it **cannot establish a strict “better than” relation**

Meaning:

- It must find **one clearly best function**
- If not → **compilation error**

---

# **<span style="color:#FF5733">Mental Model</span>**

Think of it like:

- Each function gets a **score**
- If:
  - One has lowest score → selected
  - Multiple have same best score → **FAIL**

---

# **<span style="color:#00FF9C">Key Takeaways</span>**

- Overloading is powerful but fragile
- Most failures come from:
  - Implicit conversions
  - Equal ranking

- Avoid:
  - Too many overloads
  - Mixing numeric types carelessly

---

## **<span style="color:#FFEA00">Next Step (Recommended)</span>**

If you're aiming for **top-tier C++ roles (HFT / systems)**, next you should learn:

- **Template specialization vs overloading resolution**
- **SFINAE & substitution failure rules**
- **Concepts (C++20) and how they fix ambiguity**

I can take you there step-by-step.
