# **<span style="color:#00E5FF">Function Pointers in C++</span>**

Function pointers are one of the oldest forms of **runtime behavior selection** in C and C++.

Before lambdas, functors, `std::function`, virtual functions, and templates became common, function pointers were the primary way to:

- Pass behavior as an argument
- Implement callbacks
- Create dispatch tables
- Select algorithms at runtime

---

# **<span style="color:#FFEA00">What is a Function Pointer?</span>**

A function pointer is:

> A variable that stores the address of a function.

Just like:

```cpp
int* ptr;
```

stores the address of an integer,

```cpp
int (*funcPtr)(int, int);
```

stores the address of a function.

---

## **<span style="color:#00FF9C">Memory Analogy</span>**

Normal pointer:

```text
ptr
 |
 v
1000 ----> integer value
```

Function pointer:

```text
funcPtr
   |
   v
0x401200 ----> machine instructions of function
```

---

# **<span style="color:#FFEA00">Why Can Functions Have Addresses?</span>**

When compiled:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

becomes machine code stored in the:

```text
Text Segment (Code Segment)
```

Example:

```text
0x401000
```

Function name:

```cpp
add
```

acts like:

```text
Address of function
```

similar to:

```cpp
arr
```

being the address of first element of array.

---

# **<span style="color:#00E5FF">Basic Function Pointer Syntax</span>**

---

## **Normal Function**

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Signature:

```cpp
int(int,int)
```

---

## **Function Pointer Declaration**

```cpp
int (*ptr)(int, int);
```

---

## **Understanding the Syntax</span>**

Read inside-out.

```cpp
(*ptr)
```

means:

```text
ptr is a pointer
```

---

Then:

```cpp
(int,int)
```

means:

```text
points to function taking two ints
```

---

Then:

```cpp
int
```

means:

```text
returns int
```

---

Final meaning:

```text
Pointer to function
taking (int,int)
returning int
```

---

# **<span style="color:#FFEA00">Assigning a Function</span>**

```cpp
ptr = add;
```

or

```cpp
ptr = &add;
```

Both are valid.

---

## **Why Both Work?</span>**

Function name automatically decays to:

```text
Function address
```

similar to arrays.

---

# **<span style="color:#FFEA00">Calling Through Function Pointer</span>**

---

## **Method 1**

```cpp
ptr(10,20);
```

---

## **Method 2**

```cpp
(*ptr)(10,20);
```

---

Both produce:

```text
30
```

---

# **<span style="color:#00E5FF">Complete Example</span>**

```cpp
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*ptr)(int,int);

    ptr = add;

    cout << ptr(10,20);
}
```

Output:

```text
30
```

---

# **<span style="color:#FFEA00">Dry Run Internally</span>**

Suppose:

```text
add function at address 5000
```

---

### Step 1

```cpp
ptr = add;
```

Memory:

```text
ptr
 |
 v
5000
```

---

### Step 2

```cpp
ptr(10,20);
```

CPU:

```text
Jump to address 5000
Execute instructions
Return result
```

---

# **<span style="color:#00E5FF">Function Pointer as Function Argument</span>**

This is the most important use.

---

## **Example**

```cpp
int add(int a,int b)
{
    return a+b;
}

int multiply(int a,int b)
{
    return a*b;
}
```

---

### Generic Function

```cpp
void execute(
    int (*operation)(int,int),
    int x,
    int y)
{
    cout << operation(x,y);
}
```

---

### Usage

```cpp
execute(add,10,20);
execute(multiply,10,20);
```

Output:

```text
30
200
```

---

# **<span style="color:#FFEA00">Why Do We Need Function Pointers?</span>**

Without function pointers:

```cpp
if(choice==1)
    add();

else if(choice==2)
    multiply();

else if(choice==3)
    divide();
```

---

With function pointers:

```cpp
operation(x,y);
```

Behavior selected dynamically.

---

# **<span style="color:#00E5FF">Use Case 1: Runtime Algorithm Selection</span>**

```cpp
int ascending(int,int);
int descending(int,int);
```

Choose at runtime:

```cpp
int (*compare)(int,int);
```

---

Assign:

```cpp
compare = ascending;
```

or

```cpp
compare = descending;
```

---

Algorithm remains same.

Behavior changes.

---

# **<span style="color:#00E5FF">Use Case 2: Callback Functions</span>**

Very common in C libraries.

---

Example:

```cpp
void buttonClicked()
{
    cout<<"Button clicked";
}
```

Framework stores:

```cpp
function pointer
```

When user clicks button:

```text
Call stored function
```

---

# **<span style="color:#00E5FF">Use Case 3: Dispatch Tables</span>**

Instead of:

```cpp
switch(opcode)
{
    case 1:
    case 2:
    case 3:
}
```

Use:

```cpp
function table
```

---

Example:

```cpp
int (*operations[])(int,int) =
{
    add,
    subtract,
    multiply
};
```

Call:

```cpp
operations[2](10,20);
```

---

# **<span style="color:#FFEA00">Different Ways to Define Function Pointers</span>**

---

## **Method 1: Traditional Syntax</span>**

```cpp
int (*ptr)(int,int);
```

Most fundamental.

---

## **Method 2: Using typedef</span>**

```cpp
typedef int (*Operation)(int,int);

Operation ptr;
```

---

### Benefit

Cleaner code.

---

## **Method 3: Using Alias (Modern C++)</span>**

```cpp
using Operation =
    int (*)(int,int);

Operation ptr;
```

Preferred over typedef.

---

# **<span style="color:#00E5FF">Function Returning Function Pointer</span>**

Advanced syntax.

---

```cpp
int add(int,int);
int multiply(int,int);

int (*getOperation())(int,int)
{
    return add;
}
```

---

Meaning:

```text
Function returns
pointer to function
```

---

# **<span style="color:#00E5FF">Array of Function Pointers</span>**

---

```cpp
int (*ops[3])(int,int);
```

---

Memory:

```text
ops[0] -> add
ops[1] -> subtract
ops[2] -> multiply
```

---

Useful for:

- Interpreters
- Compilers
- Virtual machines
- Dispatch systems

---

# **<span style="color:#FFEA00">Limitations of Function Pointers</span>**

---

## **Cannot Store State</span>**

Function:

```cpp
int add(int,int);
```

has no captured variables.

---

Function pointer stores:

```text
Only address
```

---

Unlike lambda:

```cpp
[a](int x)
{
    return x+a;
}
```

---

## **Signature Must Match Exactly</span>**

```cpp
int (*ptr)(int,int);
```

Cannot assign:

```cpp
double func(double,double);
```

---

Compilation error.

---

# **<span style="color:#00E5FF">Function Pointer vs Virtual Function</span>**

| Feature           | Function Pointer | Virtual Function |
| ----------------- | ---------------- | ---------------- |
| Stores            | Function Address | vtable Entry     |
| Runtime Selection | Yes              | Yes              |
| OOP Support       | No               | Yes              |
| State             | No               | Yes              |
| Overhead          | Small            | Small            |

---

# **<span style="color:#00E5FF">Function Pointer vs Lambda</span>**

| Feature            | Function Pointer | Lambda    |
| ------------------ | ---------------- | --------- |
| Captures Variables | No               | Yes       |
| Readability        | Lower            | Higher    |
| Modern C++         | Less Common      | Preferred |
| State Support      | No               | Yes       |

---

# **<span style="color:#FFEA00">Best Practices</span>**

### Use Function Pointers When

- Simple callback needed
- Interfacing with C libraries
- Embedded systems
- Dispatch tables
- Low-level systems programming

---

### Prefer Modern Alternatives When

- State is needed
- Complex behavior required

Use:

```cpp
lambda
```

or

```cpp
std::function
```

---

### Create Aliases

Instead of:

```cpp
int (*ptr)(int,int);
```

prefer:

```cpp
using Operation =
    int (*)(int,int);
```

---

### Verify Signature Matches

Always ensure:

```cpp
return type
parameter types
parameter count
```

match exactly.

---

# **<span style="color:#00FF9C">Most Important Insight</span>**

A function pointer is fundamentally:

> **A variable that stores the address of executable code.**

When you call through it:

```cpp
ptr(10,20);
```

the CPU performs an **indirect jump** to the stored address and executes whatever function is located there.

This ability to treat behavior as data is what makes callbacks, dispatch tables, event systems, and many runtime-polymorphic mechanisms possible.
