# **<span style="color:#00E5FF">Dynamic Memory Allocation (DMA) in C++</span>**

Before learning the syntax, understand the goal:

> Dynamic Memory Allocation allows a program to request memory **during execution**, when the size, number of objects, or lifetime is not known at compile time.

---

# **<span style="color:#FFEA00">Why Do We Need Dynamic Memory Allocation?</span>**

Consider:

```cpp
int n;
std::cin >> n;
```

User enters:

```text
1000000
```

Now we need:

```cpp
n integers
```

Compiler could not know this at compile time.

So memory must be requested during execution.

---

# **<span style="color:#00E5FF">Dynamic Memory Allocation in C</span>**

C provides:

```c
malloc()
calloc()
realloc()
free()
```

from:

```c
<stdlib.h>
```

---

## **<span style="color:#FFEA00">malloc()</span>**

Allocates raw memory.

```c
int* arr = (int*)malloc(10 * sizeof(int));
```

---

### What Happens?

```text
Request 40 bytes
Heap allocator finds memory
Returns address
```

---

### Memory State

```text
Unknown / Garbage Values
```

```c
printf("%d", arr[0]);
```

Undefined value.

---

## **<span style="color:#FFEA00">calloc()</span>**

Allocates and initializes to zero.

```c
int* arr = (int*)calloc(10, sizeof(int));
```

---

### Result

```text
0 0 0 0 0 0 ...
```

---

## **<span style="color:#FFEA00">realloc()</span>**

Resize allocation.

```c
arr = realloc(arr, 20 * sizeof(int));
```

---

### Internally

Allocator may:

```text
Expand existing block
OR
Allocate new block
Copy old data
Free old block
```

---

## **<span style="color:#FFEA00">free()</span>**

Release memory.

```c
free(arr);
```

---

# **<span style="color:#FF5733">Problems with C DMA</span>**

---

## **Problem 1: No Constructor Calls**

```cpp
class Student
{
public:
    Student()
    {
        std::cout << "Constructor\n";
    }
};
```

---

### C Allocation

```cpp
Student* s =
    (Student*)malloc(sizeof(Student));
```

Constructor never runs.

Dangerous.

---

## **Problem 2: No Destructor Calls**

```cpp
free(s);
```

Destructor never runs.

Resources leak.

---

## **Problem 3: Type Safety Issues**

```cpp
(int*)malloc(...)
```

Manual casting required.

---

## **Problem 4: Easy to Misuse**

```cpp
malloc()
free()
```

must match perfectly.

---

# **<span style="color:#00E5FF">Modern C++ Dynamic Memory Allocation</span>**

C++ introduces:

```cpp
new
delete
```

---

# **<span style="color:#FFEA00">Single Object Allocation</span>**

```cpp
int* ptr = new int;
```

---

## **What Happens Internally?</span>**

Compiler transforms roughly into:

```cpp
operator new(sizeof(int));
```

Allocator returns memory.

Then:

```cpp
int constructor/initialization
```

runs.

---

## **Memory Layout**

```text
Heap

+------+
| 10   |
+------+
```

Pointer:

```cpp
ptr
```

stores address.

---

# **<span style="color:#FFEA00">Initialization During Allocation</span>**

```cpp
int* ptr = new int(10);
```

---

Result:

```text
Heap

+------+
| 10   |
+------+
```

---

# **<span style="color:#FFEA00">Deleting Memory</span>**

```cpp
delete ptr;
```

---

Internally:

### Step 1

Destructor executes (if object type).

### Step 2

Memory returned to allocator.

---

# **<span style="color:#00E5FF">Dynamic Array Allocation</span>**

---

## **Allocation**

```cpp
int* arr = new int[100];
```

---

## **Deallocation**

```cpp
delete[] arr;
```

---

### Important

```cpp
delete arr;
```

❌ Wrong

Must be:

```cpp
delete[] arr;
```

---

# **<span style="color:#00E5FF">Object Allocation Example</span>**

```cpp
class Student
{
public:
    Student()
    {
        std::cout << "Created\n";
    }

    ~Student()
    {
        std::cout << "Destroyed\n";
    }
};
```

---

## **Allocate**

```cpp
Student* s = new Student();
```

Output:

```text
Created
```

---

## **Delete**

```cpp
delete s;
```

Output:

```text
Destroyed
```

---

# **<span style="color:#FFEA00">Difference Between C and C++ DMA</span>**

| Feature            | malloc/calloc | new    |
| ------------------ | ------------- | ------ |
| Constructor Call   | ❌            | ✔      |
| Destructor Call    | ❌            | ✔      |
| Type Safety        | Weak          | Strong |
| Cast Required      | Yes           | No     |
| Object Support     | No            | Yes    |
| Exception Handling | No            | Yes    |

---

# **<span style="color:#00E5FF">Modern C++ Best Practice</span>**

In modern C++:

```text
Avoid raw new/delete whenever possible
```

---

## **Why?**

Raw pointers cause:

- Memory leaks
- Double delete
- Dangling pointers
- Ownership confusion

---

# **<span style="color:#FFEA00">Use Smart Pointers Instead</span>**

---

## **std::unique_ptr**

```cpp
#include <memory>

auto ptr =
    std::make_unique<int>(10);
```

---

### Benefits

```text
Automatic cleanup
No delete required
```

---

### Example

```cpp
{
    auto ptr =
        std::make_unique<int>(10);
}
```

Leaving scope:

```text
Memory automatically freed
```

---

# **<span style="color:#FFEA00">std::shared_ptr</span>**

Multiple owners.

```cpp
auto ptr =
    std::make_shared<int>(10);
```

---

Memory freed when:

```text
Last owner disappears
```

---

# **<span style="color:#00E5FF">Dynamic Memory Allocation Mechanism</span>**

When:

```cpp
new Student()
```

occurs:

---

## **Step 1**

Compiler generates:

```cpp
operator new(sizeof(Student))
```

---

## **Step 2**

Allocator searches heap.

---

## **Step 3**

Memory block reserved.

---

## **Step 4**

Constructor runs.

---

## **Step 5**

Address returned.

---

### Visualization

```text
Heap

+------------------+
| Student Object   |
+------------------+

         ↑
         |
        ptr
```

---

# **<span style="color:#FFEA00">When Should You Use DMA?</span>**

---

## **Use Case 1: Unknown Size**

```cpp
int n;
cin >> n;
```

Need:

```cpp
n elements
```

---

## **Use Case 2: Long Lifetime**

Object survives beyond function.

---

## **Use Case 3: Large Objects**

```cpp
100 MB dataset
```

Cannot safely fit on stack.

---

## **Use Case 4: Dynamic Data Structures**

Examples:

- Linked List
- Tree
- Graph
- Trie

---

# **<span style="color:#FF5733">When NOT to Use DMA</span>**

Avoid:

```cpp
new int;
```

for tiny temporary objects.

---

Instead:

```cpp
int x;
```

Use stack.

---

# **<span style="color:#00E5FF">Modern C++ Hierarchy (Most Important)</span>**

### Best

```cpp
std::vector
std::string
std::array
```

Containers manage memory.

---

### Good

```cpp
std::unique_ptr
std::shared_ptr
```

Automatic ownership.

---

### Acceptable

```cpp
new/delete
```

When absolutely necessary.

---

### Avoid

```cpp
malloc
calloc
realloc
free
```

in C++ object-oriented code.

---

# **<span style="color:#00FF9C">Performance Considerations</span>**

| Method      | Allocation Cost       | Safety |
| ----------- | --------------------- | ------ |
| Stack       | Very Fast             | High   |
| new/delete  | Slower                | Medium |
| unique_ptr  | Same as new/delete    | High   |
| shared_ptr  | Higher                | High   |
| malloc/free | Similar to new/delete | Low    |

---

# **<span style="color:#FFEA00">Best Practices</span>**

### Prefer

```cpp
std::vector
std::string
std::array
```

---

### Then

```cpp
std::unique_ptr
```

---

### Then

```cpp
std::shared_ptr
```

---

### Use raw `new/delete` only when:

- Building allocators
- Implementing containers
- Systems programming
- Legacy code

---

### Avoid

```cpp
malloc()
calloc()
realloc()
free()
```

for C++ objects because they bypass constructors and destructors.

---

# **<span style="color:#00FF9C">The Most Important Modern C++ Insight</span>**

In modern C++ (C++11 and later), professional code rarely looks like:

```cpp
Student* s = new Student();
delete s;
```

Instead it looks like:

```cpp
auto s = std::make_unique<Student>();
```

because modern C++ focuses on:

> **RAII (Resource Acquisition Is Initialization)**

where resources (memory, files, sockets, mutexes) are automatically released when objects go out of scope, eliminating most memory-management bugs.
