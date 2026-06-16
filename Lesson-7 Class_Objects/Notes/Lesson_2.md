# **<span style="color:#00E5FF">Copy Constructor and Copy Assignment Operator in C++</span>**

To understand these concepts properly, we must first understand:

> What does it actually mean to "copy an object"?

This question leads directly to why copy constructors and copy assignment operators exist.

---

# **<span style="color:#FFEA00">The Fundamental Problem</span>**

Suppose we have:

```cpp
class Student
{
public:
    int age;
};
```

Create:

```cpp
Student s1;
s1.age = 20;
```

Now:

```cpp
Student s2 = s1;
```

Question:

```text
How should s2 be created?
```

Compiler needs a mechanism to copy data from:

```text
s1
```

to

```text
s2
```

This mechanism is:

```text
Copy Constructor
```

---

# **<span style="color:#00E5FF">What is a Copy Constructor?</span>**

A copy constructor is a special constructor used to create a new object from an existing object.

---

## **Syntax</span>**

```cpp
ClassName(const ClassName& other);
```

Example:

```cpp
class Student
{
public:

    int age;

    Student(const Student& other)
    {
        age = other.age;
    }
};
```

---

# **<span style="color:#FFEA00">When Is Copy Constructor Called?</span>**

---

## **Case 1: Object Initialization From Another Object</span>**

```cpp
Student s1;

Student s2 = s1;
```

---

## **Case 2: Pass By Value</span>**

```cpp
void func(Student s)
{
}
```

Call:

```cpp
func(s1);
```

Compiler creates a copy.

---

## **Case 3: Return By Value</span>**

```cpp
Student create()
{
    Student s;

    return s;
}
```

(Move/RVO may optimize this away.)

---

# **<span style="color:#00E5FF">What is Copy Assignment Operator?</span>**

Different purpose.

---

Copy constructor:

```text
Creates new object
```

Copy assignment:

```text
Copies into existing object
```

---

## **Syntax</span>**

```cpp
ClassName&
operator=(const ClassName& other);
```

---

Example:

```cpp
Student s1;
Student s2;

s2 = s1;
```

Here:

```text
s2 already exists
```

No new object is created.

Only contents are copied.

---

# **<span style="color:#FFEA00">Copy Constructor vs Copy Assignment</span>**

| Operation          | Uses                     |
| ------------------ | ------------------------ |
| `Student s2 = s1;` | Copy Constructor         |
| `s2 = s1;`         | Copy Assignment Operator |

---

## **Visual Difference</span>**

### Copy Constructor

```cpp
Student s1;

Student s2 = s1;
```

```text
s2 is being born
```

---

### Copy Assignment

```cpp
Student s1;
Student s2;

s2 = s1;
```

```text
s2 already exists
```

---

# **<span style="color:#00E5FF">Compiler-Generated Copy Constructor</span>**

If you don't write one:

```cpp
class Student
{
public:
    int age;
};
```

Compiler generates something similar to:

```cpp
Student(const Student& other)
{
    age = other.age;
}
```

---

This is called:

```text
Shallow Copy
```

or

```text
Member-wise Copy
```

---

# **<span style="color:#FFEA00">How Compiler Generated Copy Works</span>**

Example:

```cpp
Student s1;
s1.age = 20;

Student s2 = s1;
```

---

Before:

```text
s1

age = 20
```

---

Compiler-generated copy:

```cpp
s2.age = s1.age;
```

---

After:

```text
s1.age = 20
s2.age = 20
```

Works perfectly.

---

# **<span style="color:#00E5FF">Why Does It Work Here?</span>**

Because:

```cpp
int
```

is a value type.

Copying value is safe.

---

# **<span style="color:#FF5733">The Problem Begins With Resources</span>**

Consider:

```cpp
class Buffer
{
public:

    int* data;

    Buffer()
    {
        data = new int(10);
    }

    ~Buffer()
    {
        delete data;
    }
};
```

---

Now:

```cpp
Buffer b1;

Buffer b2 = b1;
```

---

# **<span style="color:#FFEA00">Dry Run of Compiler Generated Copy</span>**

---

## **Step 1</span>**

Create:

```cpp
Buffer b1;
```

Memory:

```text
b1

data -----> Heap
             [10]
```

---

## **Step 2</span>**

Copy:

```cpp
Buffer b2 = b1;
```

Compiler generated copy:

```cpp
b2.data = b1.data;
```

---

Result:

```text
b1.data ----+
            |
            v
          Heap
           [10]
            ^
            |
b2.data ----+
```

---

# **<span style="color:#FF5733">Disaster</span>**

Now both objects believe:

```text
I own this memory
```

---

Program ends.

---

### Destructor for b2

```cpp
delete data;
```

Memory freed.

---

### Destructor for b1

```cpp
delete data;
```

Same memory freed again.

---

Result:

```text
Double Delete
Undefined Behavior
```

---

# **<span style="color:#00E5FF">This Is Called Shallow Copy</span>**

Compiler copied:

```text
Pointer value
```

Not:

```text
Heap object
```

---

Visual:

```text
Pointer copied

Resource NOT copied
```

---

# **<span style="color:#00E5FF">Solution: Deep Copy</span>**

We write our own copy constructor.

---

```cpp
class Buffer
{
public:

    int* data;

    Buffer()
    {
        data = new int(10);
    }

    Buffer(const Buffer& other)
    {
        data =
            new int(*other.data);
    }

    ~Buffer()
    {
        delete data;
    }
};
```

---

# **<span style="color:#FFEA00">Dry Run</span>**

Create:

```cpp
Buffer b1;
```

---

Copy:

```cpp
Buffer b2 = b1;
```

---

Our constructor:

```cpp
new int(*other.data);
```

creates:

```text
Heap A -> 10
Heap B -> 10
```

---

Result:

```text
b1 owns Heap A

b2 owns Heap B
```

Independent ownership.

No double delete.

---

# **<span style="color:#00E5FF">Pitfall #1: Double Delete</span>**

---

Cause:

```text
Shallow copying owning pointers
```

---

Example:

```cpp
b2.data = b1.data;
```

Both own same memory.

---

Result:

```text
Double delete
```

---

# **<span style="color:#00E5FF">Pitfall #2: Unexpected Shared State</span>**

Example:

```cpp
*b1.data = 100;
```

---

Since:

```text
b1.data
and
b2.data
```

point to same memory:

```cpp
*b2.data
```

becomes:

```text
100
```

also.

---

User expected:

```text
Independent objects
```

but got:

```text
Shared resource
```

---

# **<span style="color:#00E5FF">Pitfall #3: Dangling Pointer</span>**

Destroy:

```cpp
b1
```

Memory freed.

---

Now:

```text
b2.data
```

points to freed memory.

---

Access:

```cpp
*b2.data
```

Undefined Behavior.

---

# **<span style="color:#00E5FF">Compiler Generated Copy Assignment Operator</span>**

Compiler also generates:

```cpp
Buffer&
operator=(const Buffer& other)
{
    data = other.data;

    return *this;
}
```

---

Same problem.

Still shallow copy.

---

# **<span style="color:#FF5733">Extra Danger in Assignment</span>**

Consider:

```cpp
b2 = b1;
```

---

Suppose:

```text
b2 already owns memory
```

Compiler-generated assignment:

```cpp
data = other.data;
```

---

Old memory owned by:

```text
b2
```

lost forever.

---

Result:

```text
Memory Leak
```

---

# **<span style="color:#00E5FF">Proper Copy Assignment Operator</span>**

```cpp
Buffer&
operator=(const Buffer& other)
{
    if(this != &other)
    {
        delete data;

        data =
            new int(*other.data);
    }

    return *this;
}
```

---

Now:

1. Old memory released
2. New memory allocated
3. Deep copy performed

---

# **<span style="color:#FFEA00">Rule of Three</span>**

If your class manages resources and defines:

```cpp
Destructor
```

you usually need:

```cpp
Copy Constructor
Copy Assignment Operator
Destructor
```

This is:

```text
Rule of Three
```

---

Modern C++ extends this to:

```text
Rule of Five
```

adding:

- Move Constructor
- Move Assignment Operator

---

# **<span style="color:#00FF9C">When Compiler-Generated Copy Is Safe</span>**

Safe for:

```cpp
int
double
char
std::string
std::vector
```

because these classes already manage copying correctly.

---

Example:

```cpp
class Student
{
    int age;
    std::string name;
};
```

Compiler-generated copy is usually fine.

---

# **<span style="color:#00FF9C">Most Important Insight</span>**

The compiler-generated copy constructor and copy assignment operator perform **member-wise copying**.

For ordinary values:

```cpp
int
double
bool
```

this is correct.

For resource-owning members such as:

```cpp
raw pointers
file handles
sockets
mutexes
```

member-wise copying often produces:

```text
Multiple owners
Shared resource ownership
Double delete
Memory leaks
Dangling pointers
```

This is why classes that manage resources typically need custom copy logic (deep copy), move semantics, or should disable copying entirely and use modern ownership tools like `std::unique_ptr`.
