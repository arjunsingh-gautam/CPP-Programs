# **<span style="color:#00E5FF">Operator Overloading in C++</span>**

Operator overloading is one of C++'s most powerful features.

It allows user-defined types (classes, structs) to behave like built-in types.

Example:

```cpp
int a = 10;
int b = 20;

int c = a + b;
```

The operator:

```cpp
+
```

already knows how to add integers.

But suppose we create our own type:

```cpp
class Complex
{
    int real;
    int imag;
};
```

Wouldn't it be nice if we could write:

```cpp
Complex c3 = c1 + c2;
```

instead of:

```cpp
Complex c3 = c1.add(c2);
```

This is exactly why operator overloading exists.

---

# **<span style="color:#FFEA00">The Fundamental Idea</span>**

Operator overloading means:

> Give existing operators a meaning for user-defined types.

---

Example:

```cpp
Complex c3 = c1 + c2;
```

Compiler transforms it into a function call.

Conceptually:

```cpp
c1.operator+(c2);
```

or

```cpp
operator+(c1,c2);
```

depending on implementation.

---

# **<span style="color:#00E5FF">Why Do We Need Operator Overloading?</span>**

Without overloading:

```cpp
Vector v3 = v1.add(v2);
```

With overloading:

```cpp
Vector v3 = v1 + v2;
```

---

Benefits:

- More readable
- Natural syntax
- Mimics built-in types
- Better abstraction

---

# **<span style="color:#FFEA00">Syntax of Operator Overloading</span>**

General syntax:

```cpp
return_type operatorOP(parameters)
{
}
```

---

Example:

```cpp
Complex operator+(const Complex& other)
{
}
```

Meaning:

```text
Overload +
for Complex objects
```

---

# **<span style="color:#00E5FF">How Operator Overloading Works Internally</span>**

Consider:

```cpp
Complex c3 = c1 + c2;
```

Compiler does NOT treat `+` magically.

It transforms it conceptually into:

```cpp
Complex c3 = c1.operator+(c2);
```

if member operator exists.

---

Or:

```cpp
Complex c3 = operator+(c1,c2);
```

if free function exists.

---

Thus:

```text
Operator Overloading
=
Function Call Overloading
```

---

# **<span style="color:#FFEA00">Method 1: Member Function Overloading</span>**

Most common.

---

## Example

```cpp
class Complex
{
public:

    int real;
    int imag;

    Complex(int r,int i)
        : real(r), imag(i)
    {
    }

    Complex operator+(const Complex& other)
    {
        return Complex(
            real + other.real,
            imag + other.imag
        );
    }
};
```

---

Usage:

```cpp
Complex c1(1,2);
Complex c2(3,4);

Complex c3 = c1 + c2;
```

---

Compiler transforms:

```cpp
c1 + c2
```

into:

```cpp
c1.operator+(c2);
```

---

# **<span style="color:#FFEA00">Dry Run</span>**

---

Object:

```text
c1

real = 1
imag = 2
```

---

Object:

```text
c2

real = 3
imag = 4
```

---

Call:

```cpp
c1.operator+(c2);
```

---

Returns:

```text
real = 4
imag = 6
```

---

# **<span style="color:#00E5FF">Method 2: Free Function Overloading</span>**

Sometimes preferred.

---

## Example

```cpp
class Complex
{
public:

    int real;
    int imag;

    Complex(int r,int i)
        : real(r), imag(i)
    {
    }
};

Complex operator+(
    const Complex& lhs,
    const Complex& rhs)
{
    return Complex(
        lhs.real + rhs.real,
        lhs.imag + rhs.imag
    );
}
```

---

Usage:

```cpp
Complex c3 = c1 + c2;
```

Compiler transforms:

```cpp
operator+(c1,c2);
```

---

# **<span style="color:#FFEA00">Member vs Free Function</span>**

| Feature             | Member               | Free Function        |
| ------------------- | -------------------- | -------------------- |
| Left operand        | Implicit (`this`)    | Explicit             |
| Syntax              | `obj.operator+(rhs)` | `operator+(lhs,rhs)` |
| Access private data | Yes                  | Need friend/getters  |
| Symmetry            | Less                 | Better               |

---

# **<span style="color:#00E5FF">How Compiler Resolves Operator Overloading</span>**

Operator overloading follows the same overload resolution rules as normal functions.

---

Suppose:

```cpp
class Number
{
public:

    Number operator+(int);
    Number operator+(double);
};
```

---

Call:

```cpp
Number n;

n + 5;
```

Compiler sees:

```cpp
n.operator+(5);
```

Candidates:

```cpp
operator+(int)
operator+(double)
```

---

Exact match:

```cpp
operator+(int)
```

selected.

---

Same overload ranking algorithm used for normal functions.

---

# **<span style="color:#FFEA00">Example of Resolution</span>**

```cpp
class Number
{
public:

    Number operator+(int)
    {
        std::cout<<"int";
        return *this;
    }

    Number operator+(double)
    {
        std::cout<<"double";
        return *this;
    }
};
```

---

Call:

```cpp
Number n;

n + 10;
```

Output:

```text
int
```

---

Call:

```cpp
n + 5.5;
```

Output:

```text
double
```

---

# **<span style="color:#FFEA00">Operators That Cannot Be Overloaded</span>**

These are fixed by language.

```cpp
.
.*
::
?:
sizeof
typeid
alignof
```

---

Example:

```cpp
obj.member
```

must always mean member access.

---

# **<span style="color:#00E5FF">Most Common Operator Overloads</span>**

---

# **<span style="color:#FFEA00">1. + Operator</span>**

```cpp
Complex operator+(
    const Complex& other)
{
}
```

Use case:

```cpp
c1 + c2
```

---

# **<span style="color:#FFEA00">2. - Operator</span>**

```cpp
Complex operator-(
    const Complex& other)
{
}
```

---

# **<span style="color:#FFEA00">3. == Operator</span>**

```cpp
bool operator==(
    const Complex& other)
{
}
```

Example:

```cpp
if(c1 == c2)
```

---

# **<span style="color:#FFEA00">4. != Operator</span>**

```cpp
bool operator!=(
    const Complex& other)
{
}
```

---

# **<span style="color:#FFEA00">5. < Operator</span>**

Useful for:

```cpp
std::set
std::map
sorting
```

---

Example:

```cpp
bool operator<(
    const Person& other)
{
}
```

---

# **<span style="color:#FFEA00">6. [] Operator</span>**

Allows array-like syntax.

---

Example:

```cpp
class Array
{
public:

    int data[10];

    int&
    operator[](int index)
    {
        return data[index];
    }
};
```

Usage:

```cpp
arr[3]
```

Internally:

```cpp
arr.operator[](3);
```

---

# **<span style="color:#FFEA00">7. () Operator</span>**

Function-call operator.

---

Example:

```cpp
class Adder
{
public:

    int operator()(int a,int b)
    {
        return a+b;
    }
};
```

Usage:

```cpp
Adder add;

add(10,20);
```

Internally:

```cpp
add.operator()(10,20);
```

---

# **<span style="color:#FFEA00">8. << Operator</span>**

Most famous overload.

---

Example:

```cpp
std::cout << obj;
```

---

Implementation:

```cpp
std::ostream&
operator<<(
    std::ostream& os,
    const Person& p)
{
    os << p.age;

    return os;
}
```

---

# **<span style="color:#00E5FF">When Should We Use Operator Overloading?</span>**

Use when operator meaning is natural.

---

Good:

```cpp
Complex + Complex

Vector + Vector

Money + Money

Matrix * Matrix
```

---

Bad:

```cpp
User + User

Database + Connection

Car + Engine
```

Meaning unclear.

---

# **<span style="color:#FF5733">When Should We Avoid Operator Overloading?</span>**

Avoid if operator behavior becomes surprising.

---

Bad:

```cpp
a + b
```

deletes a file.

---

Bad:

```cpp
a == b
```

modifies object.

---

Operators should behave as users expect.

---

# **<span style="color:#00FF9C">Best Practices</span>**

### Keep Meaning Natural

```cpp
+  => Addition
== => Equality
<  => Ordering
```

---

### Prefer const References

Good:

```cpp
Complex
operator+(const Complex& other)
```

Avoid unnecessary copies.

---

### Return By Value for Arithmetic Operators

```cpp
Complex operator+(...)
```

creates new result.

---

### Maintain Consistency

If you overload:

```cpp
==
```

also consider:

```cpp
!=
```

---

### Avoid Side Effects

```cpp
a+b
```

should not modify:

```cpp
a
```

or

```cpp
b
```

---

# **<span style="color:#00FF9C">The Most Important Insight</span>**

Operator overloading does **not** create new operators.

It simply allows existing operators to be mapped to function calls for user-defined types.

When the compiler sees:

```cpp
a + b
```

it conceptually performs overload resolution and transforms it into either:

```cpp
a.operator+(b);
```

or

```cpp
operator+(a,b);
```

Therefore, operator overloading is fundamentally just **specialized function overloading with operator syntax**, designed to make user-defined types behave naturally like built-in types.
