# **<span style="color:#00E5FF">Constructors in C++: First Principles Understanding</span>**

Before learning default constructors, understand the problem constructors solve.

---

# **<span style="color:#FFEA00">Why Do Constructors Exist?</span>**

Suppose we have:

```cpp
class Student
{
public:
    int age;
};
```

Create an object:

```cpp
Student s;
```

---

Question:

What is inside:

```cpp
s.age
```

?

Answer:

```text
Garbage Value
```

because memory was allocated but not initialized.

---

## **The Fundamental Problem</span>**

When an object is created:

```text
Memory allocated
```

but

```text
Object state not initialized
```

This leads to:

- Invalid states
- Bugs
- Undefined behavior

---

### Language Designers Wanted

When object is created:

```text
Allocate memory
+
Initialize object
```

automatically.

This is the reason constructors exist.

---

# **<span style="color:#00E5FF">What is a Constructor?</span>**

A constructor is a special member function that executes automatically when an object is created.

---

## **Example</span>**

```cpp
class Student
{
public:

    Student()
    {
        std::cout << "Created\n";
    }
};
```

---

Usage:

```cpp
Student s;
```

Output:

```text
Created
```

---

Compiler automatically calls constructor.

You never call it directly.

---

# **<span style="color:#FFEA00">What is a Default Constructor?</span>**

A default constructor is:

> A constructor that can be called with no arguments.

---

## **Example</span>**

```cpp
class Student
{
public:

    Student()
    {
        std::cout << "Default Constructor\n";
    }
};
```

---

Usage:

```cpp
Student s;
```

Compiler invokes:

```cpp
Student();
```

automatically.

---

# **<span style="color:#00E5FF">Why is it Called "Default"?</span>**

Because it constructs an object using default initialization behavior.

---

Example:

```cpp
Student s;
```

No information provided.

Compiler uses default constructor.

---

# **<span style="color:#00E5FF">How Default Constructor Works Internally</span>**

Consider:

```cpp
class Student
{
public:

    Student()
    {
        std::cout << "Created\n";
    }
};
```

---

Create object:

```cpp
Student s;
```

---

## **Step 1: Memory Allocation</span>**

Compiler reserves memory.

Example:

```text
Student size = 16 bytes
```

Memory:

```text
Stack

+-------------+
| Student s   |
+-------------+
```

---

## **Step 2: Constructor Call</span>**

Compiler automatically inserts something conceptually similar to:

```cpp
Student::Student(&s);
```

Not actual C++ syntax, but conceptually.

---

## **Step 3: Constructor Executes</span>**

```cpp
std::cout << "Created";
```

runs.

---

## **Step 4: Object Becomes Valid</span>**

Now object is fully initialized.

---

# **<span style="color:#FFEA00">Compiler-Generated Default Constructor</span>**

Suppose:

```cpp
class Student
{
public:
    int age;
};
```

No constructor written.

---

Compiler automatically generates:

```cpp
Student::Student()
{
}
```

called:

```text
Implicit Default Constructor
```

---

# **<span style="color:#FF5733">Important Caveat</span>**

Compiler-generated constructor:

```cpp
Student()
{
}
```

does NOT initialize:

```cpp
age
```

---

Example:

```cpp
Student s;

std::cout << s.age;
```

May print garbage.

---

# **<span style="color:#00E5FF">Writing Your Own Default Constructor</span>**

---

## **Method 1: User-Defined Constructor</span>**

```cpp
class Student
{
public:

    int age;

    Student()
    {
        age = 18;
    }
};
```

---

Result:

```cpp
Student s;
```

produces:

```text
age = 18
```

---

# **<span style="color:#FFEA00">Method 2: Member Initializer List</span>**

Preferred.

```cpp
class Student
{
public:

    int age;

    Student()
        : age(18)
    {
    }
};
```

---

Why preferred?

Because:

```text
Direct initialization
```

instead of:

```text
Initialize
Then assign
```

---

# **<span style="color:#00E5FF">Syntax of Constructor</span>**

---

## **General Form</span>**

```cpp
ClassName(parameters)
{
}
```

---

Example:

```cpp
class Student
{
public:

    Student()
    {
    }
};
```

---

## **Constructor Rules</span>**

### Same Name as Class

```cpp
Student()
```

---

### No Return Type

Wrong:

```cpp
void Student()
{
}
```

---

Constructors never return values.

---

### Called Automatically

You don't do:

```cpp
s.Student();
```

Compiler handles it.

---

# **<span style="color:#00E5FF">What Are the Functions of a Constructor?</span>**

---

## **1. Initialize Data Members</span>**

```cpp
age = 18;
```

---

## **2. Acquire Resources</span>**

```cpp
Open File
Allocate Memory
Create Socket
```

---

## **3. Establish Invariants</span>**

Example:

```text
Age must never be negative
```

Constructor ensures valid state.

---

## **4. Prepare Object for Use</span>**

After construction:

```text
Object should be usable immediately
```

---

# **<span style="color:#00E5FF">Various Types of Constructors</span>**

All constructors share one mechanism:

> They initialize an object during creation.

What differs is:

```text
Where initialization data comes from
```

---

# **<span style="color:#FFEA00">1. Default Constructor</span>**

No arguments.

```cpp
Student()
{
}
```

Usage:

```cpp
Student s;
```

---

# **<span style="color:#FFEA00">2. Parameterized Constructor</span>**

Receives values.

```cpp
Student(int age)
{
}
```

Usage:

```cpp
Student s(25);
```

---

### Purpose

Initialize object using user data.

---

# **<span style="color:#FFEA00">3. Copy Constructor</span>**

Creates object from another object.

---

Syntax:

```cpp
Student(const Student& other)
{
}
```

---

Usage:

```cpp
Student s1;

Student s2 = s1;
```

---

Purpose:

```text
Duplicate object
```

---

# **<span style="color:#FFEA00">4. Move Constructor</span>**

Creates object by stealing resources.

---

Syntax:

```cpp
Student(Student&& other)
{
}
```

---

Usage:

```cpp
Student s2 =
    std::move(s1);
```

---

Purpose:

```text
Transfer ownership
Avoid expensive copies
```

---

# **<span style="color:#FFEA00">5. Delegating Constructor</span>**

One constructor calls another.

---

Example:

```cpp
class Student
{
public:

    Student()
        : Student(18)
    {
    }

    Student(int age)
    {
    }
};
```

---

Purpose:

Avoid duplicated code.

---

# **<span style="color:#FFEA00">6. Conversion Constructor</span>**

Single-argument constructor.

---

Example:

```cpp
Student(int age)
{
}
```

---

Allows:

```cpp
Student s = 25;
```

unless marked:

```cpp
explicit
```

---

# **<span style="color:#00E5FF">Common Mechanism of All Constructors</span>**

Every constructor follows:

```text
1. Memory allocated
2. Constructor selected
3. Members initialized
4. Constructor body executes
5. Object becomes usable
```

---

# **<span style="color:#FFEA00">Constructor Selection Algorithm</span>**

Suppose:

```cpp
Student();
Student(int);
Student(double);
```

---

Call:

```cpp
Student s(10);
```

Compiler performs overload resolution.

Chooses:

```cpp
Student(int);
```

---

Exactly like normal function overloading.

---

# **<span style="color:#00E5FF">Best Practices</span>**

---

## **Use Member Initializer Lists</span>**

Good:

```cpp
Student()
    : age(18)
{
}
```

Avoid:

```cpp
Student()
{
    age = 18;
}
```

---

## **Initialize Every Member</span>**

Bad:

```cpp
int age;
```

left uninitialized.

---

Good:

```cpp
Student()
    : age(0)
{
}
```

---

## **Keep Constructors Lightweight</span>**

Avoid:

```cpp
Heavy database calls
Network calls
Long computations
```

inside constructors.

---

## **Use explicit For Single-Argument Constructors</span>**

Good:

```cpp
explicit Student(int age);
```

Prevents unintended conversions.

---

## **Prefer Delegating Constructors</span>**

Avoid duplicated initialization logic.

---

# **<span style="color:#00FF9C">Example Showing Multiple Constructor Types</span>**

```cpp
class Student
{
private:
    int age;

public:

    Student()
        : age(18)
    {
        std::cout << "Default\n";
    }

    Student(int a)
        : age(a)
    {
        std::cout << "Parameterized\n";
    }

    Student(const Student& other)
        : age(other.age)
    {
        std::cout << "Copy\n";
    }

    Student(Student&& other)
        : age(other.age)
    {
        std::cout << "Move\n";

        other.age = 0;
    }
};
```

---

# **<span style="color:#00FF9C">The Most Important Insight</span>**

A constructor is fundamentally:

> **An object initialization mechanism.**

Memory allocation alone does not create a valid object.

The compiler's real object creation sequence is:

```text
Allocate Memory
↓
Run Constructor
↓
Object Becomes Valid
```

All constructor types—default, parameterized, copy, move, delegating—exist to solve the same problem:

> **How should a newly created object acquire its initial state?**

The only difference between them is **where that initial state comes from**.
