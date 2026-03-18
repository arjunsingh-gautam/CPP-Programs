# **<span style="color:#00E5FF">Conversion Ranking in Overload Resolution (Deep Dive)</span>**

This is where most people get confused — **promotion vs standard conversion** look similar but are **very different in compiler priority**.

---

# **<span style="color:#FFEA00">Big Picture: Conversion Hierarchy</span>**

```text
Exact Match
   ↓
Promotion
   ↓
Standard Conversion
   ↓
User-defined
   ↓
Ellipsis
```

> Promotion is **stronger (better)** than standard conversion

---

# **<span style="color:#00E5FF">What are Promotions</span>**

## **<span style="color:#00FF9C">Definition</span>**

**Promotion = Safe, lossless widening within a tightly defined set**

- No information loss
- No ambiguity
- Guaranteed safe

---

## **<span style="color:#FFEA00">Types of Promotions in C++</span>**

### **1. Integral Promotions**

```cpp id="w2czq1"
char  → int
bool  → int
short → int
```

### **Why?**

- CPU naturally operates on `int`
- Smaller types promoted for efficiency

---

### **2. Floating Point Promotion**

```cpp id="qg5v3o"
float → double
```

- More precision
- No loss

---

## **<span style="color:#00FF9C">Key Properties of Promotion</span>**

- Always **safe**
- No precision loss
- Very **limited set**
- Preferred over standard conversions

---

# **<span style="color:#00E5FF">What are Standard Conversions</span>**

## **<span style="color:#FFEA00">Definition</span>**

**Standard Conversion = Built-in type conversion that may involve loss or change**

- Broader category
- Less safe than promotion

---

## **<span style="color:#FFEA00">Types of Standard Conversions</span>**

---

### **1. Numeric Conversions**

```cpp id="h3azya"
int → double     // widening
double → int     // narrowing (loss)
int → float
```

---

### **2. Pointer Conversions**

```cpp id="jtylqf"
Derived* → Base*
nullptr → any pointer type
```

---

### **3. Qualification Conversions**

```cpp id="d5s7ot"
int → const int
```

---

### **4. Boolean Conversions**

```cpp id="o2fd5m"
int → bool
pointer → bool
```

---

## **<span style="color:#00FF9C">Key Properties of Standard Conversion</span>**

- May cause:
  - Precision loss
  - Data truncation

- Larger category than promotions
- Lower priority than promotions

---

# **<span style="color:#00E5FF">Core Difference (Very Important)</span>**

| Feature  | Promotion             | Standard Conversion |
| -------- | --------------------- | ------------------- |
| Safety   | Always safe           | May lose data       |
| Examples | char → int            | int → double        |
| Scope    | Very limited          | Broad               |
| Priority | Higher                | Lower               |
| Purpose  | Normalize small types | General conversion  |

---

# **<span style="color:#FFEA00">Deep Insight (Compiler Thinking)</span>**

> Compiler prefers **“natural widening” over “general conversion”**

- Promotion = **natural upgrade**
- Standard conversion = **forced adjustment**

---

# **<span style="color:#00E5FF">Walkthrough Examples</span>**

---

## **<span style="color:#00FF9C">Case 1: Promotion vs Standard</span>**

```cpp id="1jowc5"
void func(int);
void func(double);

char c = 'A';
func(c);
```

### **Analysis**

| Function     | Conversion Type          |
| ------------ | ------------------------ |
| func(int)    | char → int (Promotion)   |
| func(double) | char → double (Standard) |

### **Result**

> Promotion wins → `func(int)`

---

## **<span style="color:#FF5733">Case 2: Only Standard Conversion Available</span>**

```cpp id="2jzv4h"
void func(double);

int x = 10;
func(x);
```

### **Analysis**

- `int → double` = Standard conversion

### **Result**

> Selected (no competition)

---

## **<span style="color:#FF5733">Case 3: Standard vs Standard → Ambiguity</span>**

```cpp id="w0hfr5"
void func(int);
void func(double);

float f = 10.5;
func(f);
```

### **Analysis**

| Function     | Conversion     |
| ------------ | -------------- |
| func(int)    | float → int    |
| func(double) | float → double |

Both:

- Standard conversions

### **Result**

> ERROR: Ambiguous

---

## **<span style="color:#00FF9C">Case 4: Promotion Beats Standard Clearly</span>**

```cpp id="30qkqa"
void func(float);
void func(double);

float f = 5.5;
func(f);
```

### **Analysis**

| Function     | Conversion                 |
| ------------ | -------------------------- |
| func(float)  | Exact                      |
| func(double) | float → double (Promotion) |

### **Result**

> Exact match wins (even above promotion)

---

# **<span style="color:#FFEA00">Subtle but Important Clarification</span>**

### **Is `int → double` a promotion?**

> **NO**

Even though it looks safe, it is:

- **Standard conversion**

### **Why?**

- Promotion is strictly limited to:
  - Small integer → int
  - float → double

---

# **<span style="color:#00E5FF">Mental Model (Very Important)</span>**

Think like compiler:

- Promotion =
  **“Upgrade within same family safely”**

- Standard conversion =
  **“Convert across types, may need adjustment”**

---

# **<span style="color:#00FF9C">Key Takeaways</span>**

- Promotion is:
  - Limited
  - Safe
  - Preferred

- Standard conversion:
  - Broader
  - Less preferred
  - May lose precision

- Overload resolution:

  ```
  Promotion always beats standard conversion
  ```

---

## **<span style="color:#FFEA00">Interview-Level Insight</span>**

> Most tricky questions are designed around:

- `char`, `float`, `int`, `double`
- To test if you know **promotion vs standard difference**

---
