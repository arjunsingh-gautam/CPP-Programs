# **<span style="color:#00E5FF">Rule of Three in C++</span>**

The Rule of Three is one of the most important concepts in resource management in pre-modern and modern C++.

The rule states:

> If a class defines **any one** of the following:
>
> 1. Destructor
> 2. Copy Constructor
> 3. Copy Assignment Operator
>
> then it usually needs to define **all three**.

---

# **<span style="color:#FFEA00">Why Does the Rule of Three Exist?</span>**

The rule exists because these three functions are responsible for managing:

```text
Resource Ownership
```

Examples of resources:

- Dynamically allocated memory (`new`)
- Files
- Database connections
- Network sockets
- Mutexes
- OS handles

---

# **<span style="color:#FFEA00">The Fundamental Problem</span>**

Consider:

```cpp
class Person
{
public:
    int* age;

    Person()
    {
        age = new int(10);
    }

    ~Person()
    {
        delete age;
    }
};
```

---

Object creation:

```cpp
Person p1;
```

Memory:

```text
p1.age -----> Heap
               [10]
```

---

Now:

```cpp
Person p2 = p1;
```

Compiler-generated copy constructor performs:

```cpp
p2.age = p1.age;
```

---

Result:

```text
p1.age ----+
           |
           v

         Heap
          [10]
           ^
           |
p2.age ----+
```

Two owners.

One resource.

---

# **<span style="color:#FF5733">What Goes Wrong?</span>**

Program ends.

Destructor for:

```cpp
p2
```

runs:

```cpp
delete age;
```

Memory freed.

---

Destructor for:

```cpp
p1
```

runs:

```cpp
delete age;
```

Same memory freed again.

---

Result:

```text
Double Delete
Undefined Behavior
```

---

# **<span style="color:#00E5FF">Why Destructor Alone Is Dangerous</span>**

The moment you write:

```cpp
~Person()
{
    delete age;
}
```

you are telling compiler:

```text
This class owns a resource
```

---

If class owns a resource:

```text
Copying becomes dangerous
```

because compiler-generated copy operations perform:

```text
Shallow Copy
```

---

Therefore:

```text
Destructor implies
Copy Constructor must be reviewed
Copy Assignment must be reviewed
```

---

# **<span style="color:#00E5FF">The Three Functions</span>**

---

## **1. Destructor</span>**

Responsible for:

```text
Resource Cleanup
```

Example:

```cpp
~Person()
{
    delete age;
}
```

---

## **2. Copy Constructor</span>**

Responsible for:

```text
Creating new object
from existing object
```

Example:

```cpp
Person p2 = p1;
```

---

Syntax:

```cpp
Person(const Person& other);
```

---

## **3. Copy Assignment Operator</span>**

Responsible for:

```text
Copying into existing object
```

Example:

```cpp
p2 = p1;
```

---

Syntax:

```cpp
Person&
operator=(const Person& other);
```

---

# **<span style="color:#FFEA00">Why All Three Must Work Together</span>**

Suppose you implement only:

```cpp
Destructor
Copy Constructor
```

---

But forget:

```cpp
Copy Assignment Operator
```

---

Example:

```cpp
Person p1;
Person p2;

p2 = p1;
```

Compiler generates:

```cpp
age = other.age;
```

---

Result:

```text
Shallow Copy
```

again.

---

Double delete returns.

---

Therefore:

```text
Fixing only one copy path
is not enough
```

---

# **<span style="color:#00E5FF">Pitfall #1: Double Delete</span>**

---

Example:

```cpp
Person p1;

Person p2 = p1;
```

---

Compiler-generated copy:

```cpp
p2.age = p1.age;
```

---

Memory:

```text
Both own same pointer
```

---

Program exits.

```text
delete twice
```

---

Crash.

---

# **<span style="color:#00E5FF">Pitfall #2: Memory Leak</span>**

Suppose:

```cpp
Person p1;
Person p2;

p2 = p1;
```

---

Before assignment:

```text
p2.age -----> HeapB
```

---

Compiler-generated assignment:

```cpp
p2.age = p1.age;
```

---

Now:

```text
HeapB
```

lost forever.

---

Result:

```text
Memory Leak
```

---

# **<span style="color:#00E5FF">Pitfall #3: Unexpected Shared State</span>**

Suppose:

```cpp
*p1.age = 50;
```

---

Since both pointers point to same memory:

```cpp
*p2.age
```

also becomes:

```text
50
```

---

User expected:

```text
Independent Objects
```

but got:

```text
Shared Resource
```

---

# **<span style="color:#00E5FF">Pitfall #4: Dangling Pointer</span>**

Destroy:

```cpp
p1
```

---

Memory freed.

---

But:

```cpp
p2.age
```

still points there.

---

Result:

```text
Dangling Pointer
```

---

Access:

```cpp
*p2.age
```

Undefined behavior.

---

# **<span style="color:#FFEA00">Proper Rule of Three Example</span>**

```cpp
class Person
{
public:

    int* age;

    Person()
        : age(new int(10))
    {
    }

    Person(const Person& other)
        : age(new int(*other.age))
    {
    }

    Person&
    operator=(const Person& other)
    {
        if(this != &other)
        {
            delete age;

            age = new int(*other.age);
        }

        return *this;
    }

    ~Person()
    {
        delete age;
    }
};
```

---

# **<span style="color:#00E5FF">Dry Run</span>**

---

## **Create p1</span>**

```text
p1.age -----> HeapA
               [10]
```

---

## **Copy Construct p2</span>**

```cpp
Person p2 = p1;
```

Creates:

```text
p2.age -----> HeapB
               [10]
```

Independent copy.

---

## **Assign p3</span>**

```cpp
p3 = p1;
```

Old resource cleaned.

New resource copied.

No leak.

---

## **Destroy Objects</span>**

Each object owns its own memory.

Safe deletion.

---

# **<span style="color:#FFEA00">Why Modern C++ Reduced Need for Rule of Three</span>**

Today we often write:

```cpp
std::string
std::vector
std::unique_ptr
```

instead of raw pointers.

---

Example:

```cpp
class Person
{
public:
    std::string name;
};
```

Compiler-generated copy works correctly.

No custom copy needed.

---

Because:

```cpp
std::string
```

already follows Rule of Three/Five internally.

---

# **<span style="color:#00E5FF">Rule of Three vs Rule of Five</span>**

C++11 introduced move semantics.

New special functions:

```cpp
Move Constructor
Move Assignment Operator
```

---

Result:

```text
Rule of Five
```

---

Functions:

```cpp
Destructor
Copy Constructor
Copy Assignment
Move Constructor
Move Assignment
```

---

# **<span style="color:#00E5FF">Rule of Three vs Rule of Zero</span>**

Modern best practice:

> Don't manage resources manually.

Use:

```cpp
std::vector
std::string
std::unique_ptr
```

---

Then compiler-generated special functions are correct.

This philosophy is called:

```text
Rule of Zero
```

---

# **<span style="color:#00FF9C">When Must You Follow Rule of Three?</span>**

Usually when class directly owns:

```cpp
new/delete
malloc/free
file handles
socket handles
mutex handles
OS resources
```

---

Example:

```cpp
int* data;
FILE* file;
SocketHandle handle;
```

---

# **<span style="color:#00FF9C">Best Practices</span>**

### Prefer Rule of Zero

Use:

```cpp
std::string
std::vector
std::unique_ptr
```

---

### If Owning Raw Resources

Implement:

```cpp
Destructor
Copy Constructor
Copy Assignment
```

together.

---

### Always Handle Self-Assignment

```cpp
if(this != &other)
```

---

### Prefer Deep Copy Over Shallow Copy

When ownership is exclusive.

---

# **<span style="color:#00FF9C">The Most Important Insight</span>**

The Rule of Three is fundamentally about **ownership consistency**.

Once a class owns a resource, three questions must be answered correctly:

1. **How is the resource destroyed?** → Destructor
2. **How is the resource copied when creating a new object?** → Copy Constructor
3. **How is the resource copied into an existing object?** → Copy Assignment Operator

If you answer only one of these questions and leave the others to compiler-generated defaults, the compiler will usually perform shallow copies, leading to:

```text
Double Delete
Memory Leak
Dangling Pointer
Unexpected Shared Ownership
```

The Rule of Three exists to ensure that resource ownership remains correct throughout the entire lifetime of your objects.
