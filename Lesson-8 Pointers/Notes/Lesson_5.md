# **<span style="color:#00E5FF">Pitfalls of Pointers in C++</span>**

Pointers are powerful because they give direct access to memory.

Unfortunately, this also means:

> A small mistake can corrupt memory, crash the program, leak resources, or create security vulnerabilities.

Most pointer bugs occur because the programmer loses track of:

- Ownership
- Lifetime
- Validity
- Bounds

---

# **<span style="color:#FFEA00">Overview of Major Pointer Pitfalls</span>**

| Pitfall                   | Description                          |
| ------------------------- | ------------------------------------ |
| Null Pointer Dereference  | Accessing memory through nullptr     |
| Dangling Pointer          | Pointer refers to destroyed memory   |
| Wild Pointer              | Uninitialized pointer                |
| Memory Leak               | Allocated memory never freed         |
| Double Delete             | Freeing same memory twice            |
| Use After Free            | Using memory after deletion          |
| Out-of-Bounds Access      | Reading/Writing outside allocation   |
| Pointer Arithmetic Errors | Incorrect address calculations       |
| Returning Local Address   | Returning pointer to stack memory    |
| Ownership Confusion       | Multiple owners managing same memory |
| Invalid Type Casting      | Treating memory as wrong type        |

---

# **<span style="color:#00E5FF">1. Null Pointer Dereference</span>**

---

## **What Happens?**

Pointer contains:

```cpp
nullptr
```

but is dereferenced.

---

## **Example**

```cpp
int* ptr = nullptr;

*ptr = 10;
```

---

## **Dry Run**

### Step 1

```cpp
ptr = nullptr;
```

Memory:

```text
ptr
 |
 v
NULL
```

---

### Step 2

```cpp
*ptr = 10;
```

Program attempts:

```text
Write to address 0
```

---

### Result

```text
Segmentation Fault
Access Violation
Program Crash
```

---

## **Prevention**

```cpp
if(ptr)
{
    *ptr = 10;
}
```

Or better:

```cpp
std::unique_ptr
```

---

# **<span style="color:#00E5FF">2. Wild Pointer</span>**

---

## **What Happens?**

Pointer declared but not initialized.

---

## **Example**

```cpp
int* ptr;

*ptr = 100;
```

---

## **Dry Run**

### Step 1

```cpp
int* ptr;
```

Memory:

```text
ptr = ?
```

Contains garbage.

Maybe:

```text
0x12345678
```

---

### Step 2

```cpp
*ptr = 100;
```

Program writes to random memory.

---

### Result

```text
Undefined Behavior
```

Could:

- Crash
- Corrupt memory
- Seem to work

---

## **Prevention**

Always initialize:

```cpp
int* ptr = nullptr;
```

---

# **<span style="color:#00E5FF">3. Dangling Pointer</span>**

---

## **What Happens?**

Pointer points to memory that no longer exists.

---

## **Example**

```cpp
int* ptr;

{
    int x = 10;
    ptr = &x;
}

cout << *ptr;
```

---

## **Dry Run**

### Inside Block

```text
Stack

+-----+
| x=10|
+-----+
```

Pointer:

```text
ptr ---> x
```

---

### Block Ends

```text
x destroyed
```

Stack memory reclaimed.

---

### Pointer Still Exists

```text
ptr ---> invalid memory
```

---

### Access

```cpp
*ptr
```

Undefined Behavior.

---

## **Prevention**

Never return/store addresses of local variables.

Use:

```cpp
std::unique_ptr
```

or

```cpp
return by value
```

---

# **<span style="color:#00E5FF">4. Memory Leak</span>**

---

## **What Happens?**

Allocated memory becomes unreachable.

---

## **Example**

```cpp
int* ptr = new int(10);

ptr = new int(20);
```

---

## **Dry Run**

### First Allocation

```text
Heap

1000 -> 10
```

Pointer:

```text
ptr -> 1000
```

---

### Second Allocation

```text
Heap

1000 -> 10
2000 -> 20
```

Pointer:

```text
ptr -> 2000
```

---

### Problem

Address:

```text
1000
```

lost forever.

Cannot delete it.

---

## **Result**

Memory leak.

---

## **Prevention**

Use:

```cpp
std::unique_ptr
```

or

```cpp
delete ptr;
```

before overwriting.

---

# **<span style="color:#00E5FF">5. Double Delete</span>**

---

## **Example**

```cpp
int* ptr = new int(10);

delete ptr;
delete ptr;
```

---

## **Dry Run**

### First Delete

Memory returned.

```text
Heap block freed
```

---

### Second Delete

Allocator receives:

```text
Free already-freed memory
```

---

## **Result**

Possible:

- Crash
- Heap corruption
- Undefined Behavior

---

## **Prevention**

Immediately:

```cpp
delete ptr;
ptr = nullptr;
```

Better:

```cpp
std::unique_ptr
```

---

# **<span style="color:#00E5FF">6. Use After Free</span>**

---

## **Example**

```cpp
int* ptr = new int(10);

delete ptr;

cout << *ptr;
```

---

## **Dry Run**

### Before Delete

```text
ptr -> heap object
```

---

### After Delete

```text
memory released
```

---

### Pointer Still Contains Address

```text
ptr -> old address
```

---

### Dereference

```cpp
*ptr
```

Accessing invalid memory.

---

## **Result**

Undefined Behavior.

---

## **Prevention**

```cpp
delete ptr;
ptr = nullptr;
```

---

# **<span style="color:#00E5FF">7. Out-of-Bounds Access</span>**

---

## **Example**

```cpp
int arr[5];

arr[10] = 100;
```

---

## **Dry Run**

Memory:

```text
arr[0]
arr[1]
arr[2]
arr[3]
arr[4]
```

Valid addresses only.

---

### Access

```cpp
arr[10]
```

Compiler calculates:

```text
base + 10*sizeof(int)
```

Beyond allocated memory.

---

## **Result**

Memory corruption.

---

## **Prevention**

Use:

```cpp
std::vector
```

or bounds checking.

---

# **<span style="color:#00E5FF">8. Returning Address of Local Variable</span>**

---

## **Example**

```cpp
int* func()
{
    int x = 10;
    return &x;
}
```

---

## **Dry Run**

### Inside Function

```text
Stack

x = 10
```

---

### Return

```text
Function exits
Stack frame destroyed
```

---

### Returned Pointer

Points to destroyed memory.

---

## **Result**

Dangling pointer.

---

## **Prevention**

Return:

```cpp
int
```

or

```cpp
std::unique_ptr<int>
```

---

# **<span style="color:#00E5FF">9. Ownership Confusion</span>**

---

## **Example**

```cpp
int* ptr = new int(10);

int* p1 = ptr;
int* p2 = ptr;
```

---

### Question

Who deletes?

```cpp
delete p1;
```

or

```cpp
delete p2;
```

---

If both:

```cpp
delete p1;
delete p2;
```

Double delete.

---

## **Prevention**

Use:

```cpp
std::unique_ptr
```

or

```cpp
std::shared_ptr
```

---

# **<span style="color:#00E5FF">10. Pointer Arithmetic Mistakes</span>**

---

## **Example**

```cpp
int arr[5];

int* ptr = arr;

ptr += 10;
```

---

### Dry Run

Compiler computes:

```text
base + 10*sizeof(int)
```

Outside array.

---

### Access

```cpp
*ptr
```

Undefined Behavior.

---

## **Prevention**

Never exceed:

```cpp
[arr, arr + size]
```

range.

---

# **<span style="color:#FFEA00">Why Are Pointer Bugs So Dangerous?</span>**

Because pointers bypass safety mechanisms.

Example:

```cpp
arr[1000000]
```

Compiler usually cannot detect:

```text
Invalid memory access
```

at compile time.

Program compiles successfully.

Fails only at runtime.

---

# **<span style="color:#FF5733">Modern C++ Solution</span>**

Many pointer bugs disappear when using:

### Instead of

```cpp
new
delete
```

use:

```cpp
std::unique_ptr
```

---

### Instead of

```cpp
raw arrays
```

use:

```cpp
std::vector
```

---

### Instead of

```cpp
char*
```

use:

```cpp
std::string
```

---

# **<span style="color:#00FF9C">Best Practices</span>**

### Always

```cpp
int* ptr = nullptr;
```

---

### Prefer

```cpp
std::unique_ptr
```

over raw ownership.

---

### Prefer

```cpp
std::vector
```

over manual arrays.

---

### Avoid

```cpp
new/delete
```

unless absolutely necessary.

---

### After delete

```cpp
ptr = nullptr;
```

---

### Never

```cpp
return &local_variable;
```

---

# **<span style="color:#00E5FF">Most Important Insight</span>**

Almost every pointer bug can be traced back to violating one of these three rules:

1. **Lifetime Rule**
   - Is the object still alive?

2. **Ownership Rule**
   - Who is responsible for deleting it?

3. **Bounds Rule**
   - Are we staying inside valid memory?

If you can answer those three questions correctly for every pointer, most pointer-related bugs disappear.
