# **<span style="color:#00E5FF">How to Perform Move Semantics in C++</span>**

Before learning syntax, remember:

> **Move semantics does not move data.**
>
> It usually moves **ownership of resources**.

This distinction is critical.

---

# **<span style="color:#FFEA00">What Does "Moving" Actually Mean?</span>**

Consider:

```cpp
std::vector<int> v(1000000);
```

Internally:

```text
Vector Object

size
capacity
pointer ---> heap memory
```

Memory:

```text
Heap
[1,000,000 integers]
```

---

## **Copy Operation**

```cpp
std::vector<int> v2 = v;
```

Compiler must:

```text
Allocate new heap block
Copy 1,000,000 integers
```

---

## **Move Operation**

```cpp
std::vector<int> v2 = std::move(v);
```

Compiler usually:

```text
Copy pointer
Copy size
Copy capacity
Reset source object
```

No million integers copied.

---

# **<span style="color:#00E5FF">The Simplest Move Syntax</span>**

---

## **Using std::move()</span>**

```cpp
#include <utility>

std::string s1 = "Hello";

std::string s2 = std::move(s1);
```

---

## **Result</span>**

Before:

```text
s1 --> "Hello"
```

After:

```text
s2 --> "Hello"

s1 --> valid but unspecified state
```

Usually:

```text
s1 = ""
```

but this is not guaranteed.

---

# **<span style="color:#FFEA00">What std::move() Actually Does</span>**

Most beginners think:

```cpp
std::move(obj);
```

moves the object.

Wrong.

---

## **Reality</span>**

`std::move()` only performs:

```cpp
static_cast<T&&>(obj)
```

Conceptually.

---

It merely tells compiler:

```text
Treat this object as an rvalue
```

---

Actual movement happens later.

Usually in:

```cpp
Move Constructor
Move Assignment Operator
```

---

# **<span style="color:#00E5FF">Move Constructor</span>**

---

## **Syntax</span>**

```cpp
ClassName(ClassName&& other);
```

---

## **Example</span>**

```cpp
class Buffer
{
    int* data;

public:

    Buffer(int size)
    {
        data = new int[size];
    }

    Buffer(Buffer&& other)
    {
        data = other.data;

        other.data = nullptr;
    }
};
```

---

## **Dry Run</span>**

### Before Move

```text
A

data ------+
           |
           v

Heap
[100 integers]
```

---

### Move

```cpp
Buffer B(std::move(A));
```

---

### After Move

```text
B

data ------+
           |
           v

Heap
[100 integers]
```

---

```text
A

data = nullptr
```

Ownership transferred.

---

# **<span style="color:#00E5FF">Move Assignment Operator</span>**

---

## **Syntax</span>**

```cpp
ClassName&
operator=(ClassName&& other);
```

---

## **Example</span>**

```cpp
Buffer a(100);
Buffer b(200);

b = std::move(a);
```

---

Instead of:

```text
Copy all data
```

we:

```text
Transfer ownership
```

---

# **<span style="color:#FFEA00">Automatic Move</span>**

Sometimes compiler automatically moves.

---

## **Example</span>**

```cpp
std::vector<int> create()
{
    std::vector<int> temp(1000);

    return temp;
}
```

---

Modern compilers often perform:

```text
Move
```

or even:

```text
RVO (Return Value Optimization)
```

No copy occurs.

---

# **<span style="color:#00E5FF">Where Move Semantics is Valid</span>**

---

## **1. Temporary Objects</span>**

```cpp
std::string s =
    std::string("Hello");
```

Temporary object.

Move possible.

---

## **2. Objects Explicitly Cast Using std::move</span>**

```cpp
std::string a = "Hello";

std::string b =
    std::move(a);
```

Valid.

---

## **3. Returning Large Objects</span>**

```cpp
return vector;
```

Move often used.

---

## **4. Containers</span>**

```cpp
std::vector
std::string
std::map
std::unique_ptr
```

All support moves.

---

# **<span style="color:#FF5733">Where Move Semantics is Invalid</span>**

---

## **Case 1: Object Has No Move Constructor</span>**

```cpp
class A
{
};
```

If move constructor unavailable:

```cpp
A b = std::move(a);
```

Compiler may fall back to copy.

---

## **Case 2: const Objects</span>**

Very important.

```cpp
const std::string s = "Hello";

std::string x =
    std::move(s);
```

---

Many beginners expect move.

Usually:

```text
Copy occurs
```

---

### Why?

Moving requires modifying source.

Example:

```text
source.pointer = nullptr
```

---

But:

```cpp
const std::string
```

cannot be modified.

Therefore:

```text
Move constructor cannot steal resources
```

---

Result:

```text
Copy Constructor
```

---

# **<span style="color:#00E5FF">Why Moving Requires Source Modification</span>**

Suppose:

```cpp
B steals pointer from A
```

Then:

```text
A must relinquish ownership
```

Example:

```text
A.pointer = nullptr
```

Otherwise:

```text
Both objects own same memory
```

Double delete.

---

Hence:

```text
Move requires modifying source
```

---

Therefore:

```cpp
const object
```

cannot usually be moved.

---

# **<span style="color:#00E5FF">Move Semantics Internal Mechanism</span>**

Let's examine:

```cpp
std::vector<int> a(1000000);

std::vector<int> b =
    std::move(a);
```

---

## **Step 1</span>**

`std::move(a)`

produces:

```cpp
vector<int>&&
```

---

## **Step 2</span>**

Compiler sees:

```text
rvalue reference
```

---

## **Step 3</span>**

Move constructor selected:

```cpp
vector(vector&&)
```

instead of:

```cpp
vector(const vector&)
```

---

## **Step 4</span>**

Internal members transferred:

```text
pointer
size
capacity
```

---

## **Step 5</span>**

Source reset.

```text
pointer = nullptr
size = 0
capacity = 0
```

---

## **Result</span>**

```text
No element copied
```

---

# **<span style="color:#FFEA00">Major Move Syntaxes</span>**

---

## **Syntax 1: Explicit Move</span>**

```cpp
std::move(obj)
```

Most common.

---

## **Syntax 2: Move Constructor</span>**

```cpp
T b(std::move(a));
```

---

## **Syntax 3: Move Assignment</span>**

```cpp
b = std::move(a);
```

---

## **Syntax 4: Return Temporary</span>**

```cpp
return temp;
```

Compiler may move.

---

## **Syntax 5: Rvalue Reference Variable</span>**

```cpp
int&& ref = 10;
```

---

# **<span style="color:#00E5FF">Real Use Cases of Move Semantics</span>**

---

## **1. STL Containers</span>**

```cpp
std::vector
std::string
std::deque
std::map
```

---

Large objects.

Avoid copying.

---

## **2. Smart Pointers</span>**

```cpp
std::unique_ptr
```

Move-only type.

---

Example:

```cpp
auto p1 =
    std::make_unique<int>(10);

auto p2 =
    std::move(p1);
```

Ownership transferred.

---

## **3. Returning Large Objects</span>**

```cpp
std::vector<int> create();
```

Efficient return.

---

## **4. Resource Ownership</span>**

Files.

Sockets.

Mutexes.

Database connections.

---

## **5. High-Performance Systems</span>**

Trading systems.

Game engines.

Compilers.

Databases.

---

# **<span style="color:#FF5733">Common Mistakes</span>**

---

## **Mistake 1**

Using moved-from object.

```cpp
std::string a = "Hello";

std::string b = std::move(a);

std::cout << a;
```

Legal.

But state unspecified.

---

## **Mistake 2**

Moving const object.

```cpp
const std::string s;

std::move(s);
```

Usually copy.

---

## **Mistake 3**

Moving object too early.

```cpp
std::move(obj);

obj.use();
```

Potential bug.

---

# **<span style="color:#00FF9C">Performance Comparison</span>**

Suppose:

```cpp
vector<int>
```

contains:

```text
1,000,000 integers
```

---

## **Copy</span>**

```text
Allocate new memory
Copy 1,000,000 values
```

Cost:

```text
O(n)
```

---

## **Move</span>**

```text
Copy 3 pointers
Reset source
```

Cost:

```text
O(1)
```

---

# **<span style="color:#FFEA00">Best Practices</span>**

### Use move when:

- Ownership transfer intended
- Large objects involved
- Source object not needed afterward

---

### Do NOT use move when:

- Source object still needed
- Object is small and cheap to copy
- Object is const

---

### Prefer:

```cpp
std::move()
```

over manual ownership transfer.

---

### Ensure moved-from objects remain valid.

Usually:

```text
Empty
Null
Default state
```

---

# **<span style="color:#00FF9C">The Most Important Insight</span>**

Move semantics is fundamentally:

> **An optimization for ownership transfer.**

The compiler uses **rvalue references (`T&&`)** as a signal that:

```text
This object is temporary
Its resources may be safely stolen
```

Instead of copying large amounts of memory, modern C++ simply transfers ownership of the underlying resources, turning many expensive **O(n)** operations into **O(1)** operations.
