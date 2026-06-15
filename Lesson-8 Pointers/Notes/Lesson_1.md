# **<span style="color:#00E5FF">Static vs Dynamic Memory Allocation in C++</span>**

This topic is much deeper than:

> "Static = stack, Dynamic = heap"

To truly understand it, you need to understand:

1. Program memory layout
2. Compiler responsibilities
3. OS responsibilities
4. Runtime memory management
5. Lifetime management

---

# **<span style="color:#FFEA00">What is Memory Allocation?</span>**

Memory allocation means:

> Reserving a region of RAM for storing data.

Before a variable can hold a value:

```cpp
int x = 10;
```

memory must be reserved for it.

The question is:

> Who decides the size, location, and lifetime of that memory?

The answer determines whether allocation is static or dynamic.

---

# **<span style="color:#00E5FF">High-Level Difference</span>**

| Property              | Static Allocation                                                | Dynamic Allocation    |
| --------------------- | ---------------------------------------------------------------- | --------------------- |
| Allocation time       | Before program execution or fixed at compile/runtime scope entry | During execution      |
| Size known beforehand | Yes                                                              | Not necessarily       |
| Managed by            | Compiler/runtime stack mechanism                                 | Heap allocator        |
| Lifetime              | Predetermined                                                    | Programmer-controlled |
| Speed                 | Very fast                                                        | Slower                |
| Flexibility           | Low                                                              | High                  |

---

# **<span style="color:#FFEA00">Program Memory Layout</span>**

A typical C++ process looks like:

```text
+----------------------+
| Code/Text Segment    |
+----------------------+
| Global/Data Segment  |
+----------------------+
| BSS Segment          |
+----------------------+
| Heap                 |
|        ↑             |
|        ↑ grows       |
|                      |
|                      |
|        ↓ grows       |
| Stack                |
+----------------------+
```

---

## **<span style="color:#00FF9C">Text Segment</span>**

Stores machine instructions.

```cpp
void func()
{
}
```

Compiled code goes here.

---

## **<span style="color:#00FF9C">Data Segment</span>**

Stores initialized global/static variables.

```cpp
int global = 10;
```

---

## **<span style="color:#00FF9C">BSS Segment</span>**

Stores uninitialized global/static variables.

```cpp
int global;
```

---

## **<span style="color:#00FF9C">Stack</span>**

Stores:

- Local variables
- Function parameters
- Return addresses
- Stack frames

---

## **<span style="color:#00FF9C">Heap</span>**

Stores dynamically allocated memory.

```cpp
new int(10);
```

---

# **<span style="color:#00E5FF">Static Memory Allocation</span>**

---

## **<span style="color:#FFEA00">Definition</span>**

Memory size and lifetime are known before execution of the allocation decision.

Examples:

```cpp
int x;
```

```cpp
int arr[100];
```

```cpp
static int count;
```

```cpp
global variables
```

---

## **<span style="color:#FFEA00">Compiler's Role</span>**

Compiler knows:

```cpp
int x;
```

requires:

```text
4 bytes
```

So it generates code that reserves those bytes automatically.

---

## **<span style="color:#FFEA00">Stack Allocation Example</span>**

```cpp
void func()
{
    int x;
    int y;
}
```

---

### During Compilation

Compiler calculates:

```text
x = 4 bytes
y = 4 bytes
```

Total:

```text
8 bytes
```

Compiler generates instructions:

```assembly
sub rsp, 8
```

Meaning:

```text
Reserve 8 bytes on stack
```

---

### When Function Returns

```assembly
add rsp, 8
```

Memory automatically reclaimed.

---

## **<span style="color:#00FF9C">Key Property</span>**

No allocator needed.

No searching.

No bookkeeping.

Just move stack pointer.

---

# **<span style="color:#00E5FF">How Stack Memory Works Internally</span>**

Suppose:

```cpp
void func()
{
    int a;
    int b;
}
```

Stack:

```text
Before call

+---------+
|         |
+---------+

After call

+---------+
| b       |
+---------+
| a       |
+---------+
```

Function exits:

```text
Stack pointer restored
```

Memory effectively disappears instantly.

---

# **<span style="color:#FFEA00">Characteristics of Static/Stack Allocation</span>**

### Advantages

```text
O(1) allocation
O(1) deallocation
Excellent cache locality
No fragmentation
```

---

### Disadvantages

```text
Fixed size
Limited stack space
Lifetime not flexible
```

---

# **<span style="color:#00E5FF">Dynamic Memory Allocation</span>**

---

## **<span style="color:#FFEA00">Definition</span>**

Memory requested while program is running.

```cpp
int* p = new int(10);
```

Compiler cannot know:

- when allocation happens
- how many allocations happen

---

## **<span style="color:#FFEA00">Where is it stored?</span>**

Heap.

---

# **<span style="color:#00E5FF">How Dynamic Allocation Works Internally</span>**

Consider:

```cpp
int* p = new int(10);
```

---

## **Step 1**

Compiler converts:

```cpp
new int(10)
```

roughly into:

```cpp
operator new(sizeof(int));
```

---

## **Step 2**

Runtime allocator receives request:

```text
Need 4 bytes
```

---

## **Step 3**

Allocator searches heap.

Example:

```text
Heap

+---------+
| free    |
+---------+
| used    |
+---------+
| free    |
+---------+
```

Find suitable block.

---

## **Step 4**

Allocator reserves block.

```text
Heap

+---------+
| used    |
+---------+
| used    |
+---------+
| free    |
+---------+
```

---

## **Step 5**

Returns address.

```cpp
p = 0x1000
```

---

## **Step 6**

Constructor runs (for objects).

```cpp
new MyClass()
```

Memory allocation first.

Constructor second.

---

# **<span style="color:#00E5FF">How `delete` Works</span>**

```cpp
delete p;
```

---

### Internally

1. Destructor executes
2. Memory returned to allocator
3. Allocator marks block free

---

# **<span style="color:#FFEA00">Heap Allocator Complexity</span>**

Unlike stack:

```text
Stack:
Move pointer
Done
```

Heap:

```text
Find free block
Split blocks
Merge blocks
Track metadata
Handle fragmentation
```

Much more work.

---

# **<span style="color:#00E5FF">Environment Difference</span>**

---

## **<span style="color:#FFEA00">Stack Environment</span>**

Managed by:

```text
CPU + compiler
```

Uses:

```text
Stack pointer register
```

Examples:

```text
RSP (x86-64)
SP (ARM)
```

---

## **<span style="color:#FFEA00">Heap Environment</span>**

Managed by:

```text
Runtime allocator
+
Operating System
```

Examples:

- malloc allocator
- glibc allocator
- jemalloc
- tcmalloc
- mimalloc

---

# **<span style="color:#00E5FF">Internal Cost Comparison</span>**

| Operation      | Stack     | Heap                      |
| -------------- | --------- | ------------------------- |
| Allocation     | O(1)      | Usually O(log n) or worse |
| Deallocation   | O(1)      | More expensive            |
| Fragmentation  | None      | Possible                  |
| Cache Locality | Excellent | Worse                     |
| Metadata       | None      | Required                  |

---

# **<span style="color:#FFEA00">Memory Fragmentation</span>**

Heap can become:

```text
+----+----+----+----+
|Use |Free|Use |Free|
+----+----+----+----+
```

Need:

```text
coalescing
splitting
free lists
```

Stack never has this problem.

---

# **<span style="color:#00E5FF">Compiler's Perspective</span>**

---

## **Stack Allocation**

Compiler knows:

```cpp
int x;
```

Size:

```text
4 bytes
```

Location:

```text
inside stack frame
```

Lifetime:

```text
function scope
```

Everything known.

---

## **Dynamic Allocation**

Compiler only knows:

```cpp
need memory later
```

Actual address:

```text
unknown until runtime
```

Lifetime:

```text
unknown
```

Must defer to allocator.

---

# **<span style="color:#FF5733">Performance Analysis</span>**

### Stack

```text
Allocation: ~1 CPU instruction
Deallocation: ~1 CPU instruction
```

---

### Heap

May involve:

```text
allocator locks
metadata updates
free-list search
OS interaction
```

Hundreds of CPU cycles or more.

---

# **<span style="color:#00FF9C">Best Use Cases</span>**

## **Use Stack When**

```cpp
int x;
std::array<int,100> arr;
```

- Small
- Fixed size
- Short lifetime

---

## **Use Heap When**

```cpp
vector<int> v(n);
```

- Large data
- Unknown size
- Long lifetime

---

# **<span style="color:#00E5FF">Most Important Insight</span>**

The real distinction is not:

> Stack vs Heap

The deeper distinction is:

| Static/Stack     | Dynamic/Heap      |
| ---------------- | ----------------- |
| Lifetime known   | Lifetime unknown  |
| Size known       | Size may vary     |
| Compiler-managed | Runtime-managed   |
| Deterministic    | Non-deterministic |
| Extremely fast   | More expensive    |

For low-latency systems and HFT, one of the biggest performance principles is:

> **Avoid unnecessary dynamic allocations.**

Many high-performance C++ systems spend enormous effort reducing heap allocations because heap management, cache misses, and fragmentation are often far more expensive than the actual business logic.
