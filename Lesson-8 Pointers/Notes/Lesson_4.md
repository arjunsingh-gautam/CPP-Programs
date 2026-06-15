# **<span style="color:#00E5FF">Pointer Arithmetic in C++</span>**

Pointer arithmetic is one of the most misunderstood topics in C++.

Many beginners think:

```cpp
ptr + 1
```

means:

> "Add 1 byte to the address"

This is **wrong**.

The actual rule is:

> Pointer arithmetic operates in units of the pointed-to type, not bytes.

---

# **<span style="color:#FFEA00">Why Does Pointer Arithmetic Exist?</span>**

Imagine an array:

```cpp
int arr[5] = {10,20,30,40,50};
```

Memory:

```text
Address      Value

1000         10
1004         20
1008         30
1012         40
1016         50
```

Each `int` occupies:

```text
4 bytes
```

If:

```cpp
int* ptr = arr;
```

then:

```cpp
ptr
```

contains:

```text
1000
```

Now we need a way to move from one element to another.

This is the reason pointer arithmetic exists.

---

# **<span style="color:#00E5FF">Fundamental Formula</span>**

When compiler sees:

```cpp
ptr + n
```

it internally generates:

```text
new_address =
old_address +
(n × sizeof(type))
```

This is the most important rule.

---

# **<span style="color:#FFEA00">Operation 1 : Increment (++ptr or ptr++)</span>**

---

## **Example**

```cpp
int arr[3] = {10,20,30};

int* ptr = arr;
```

Assume:

```text
arr starts at 1000
sizeof(int)=4
```

Memory:

```text
1000 -> 10
1004 -> 20
1008 -> 30
```

---

## **Before Increment**

```text
ptr = 1000
```

---

## **Operation**

```cpp
ptr++;
```

Compiler internally:

```text
ptr =
1000 + sizeof(int)
```

becomes:

```text
ptr = 1004
```

---

## **After Increment**

```text
ptr points to second element
```

```cpp
*ptr
```

returns:

```text
20
```

---

# **<span style="color:#FFEA00">Operation 2 : Decrement (--ptr)</span>**

---

## **Example**

```cpp
ptr = &arr[2];
```

Address:

```text
1008
```

Operation:

```cpp
ptr--;
```

Internally:

```text
1008 - 4
```

Result:

```text
1004
```

Now points to:

```text
20
```

---

# **<span style="color:#FFEA00">Operation 3 : Addition (ptr + n)</span>**

---

## **Example**

```cpp
ptr = arr;
```

Address:

```text
1000
```

Operation:

```cpp
ptr + 3
```

Internally:

```text
1000 + (3 × 4)
```

Result:

```text
1012
```

Points to:

```text
arr[3]
```

---

## **Dry Run**

```cpp
int* ptr = arr;

cout << *(ptr + 3);
```

Compiler calculates:

```text
address =
1000 + 12
```

```text
address = 1012
```

Read value:

```text
40
```

---

# **<span style="color:#FFEA00">Operation 4 : Subtraction (ptr - n)</span>**

---

## **Example**

```cpp
ptr = &arr[4];
```

Address:

```text
1016
```

Operation:

```cpp
ptr - 2
```

Internally:

```text
1016 - (2 × 4)
```

Result:

```text
1008
```

Points to:

```text
arr[2]
```

---

# **<span style="color:#FFEA00">Operation 5 : Pointer Difference</span>**

This is the most interesting operation.

---

## **Example**

```cpp
int* p1 = &arr[4];
int* p2 = &arr[1];
```

Addresses:

```text
p1 = 1016
p2 = 1004
```

Operation:

```cpp
p1 - p2
```

---

### Internally

Compiler performs:

```text
(1016 - 1004)
/ sizeof(int)
```

becomes:

```text
12 / 4
```

Result:

```text
3
```

Meaning:

```text
3 elements apart
```

Not:

```text
12 bytes apart
```

---

# **<span style="color:#FFEA00">Operation 6 : Array Indexing</span>**

Most people don't know this.

---

## **Example**

```cpp
arr[3]
```

Internally becomes:

```cpp
*(arr + 3)
```

---

### Dry Run

```text
arr address = 1000

1000 + (3×4)
=
1012
```

Dereference:

```text
value at 1012
```

Result:

```text
40
```

---

# **<span style="color:#00E5FF">Why Compiler Uses sizeof(T)</span>**

Suppose:

```cpp
double* ptr;
```

Assume:

```text
sizeof(double)=8
```

---

### Increment

```cpp
ptr++
```

Internally:

```text
address += 8
```

---

### For char\*

```cpp
char* ptr;
```

Assume:

```text
sizeof(char)=1
```

Increment:

```text
address += 1
```

---

This allows:

```cpp
ptr++
```

to always move to the next object.

---

# **<span style="color:#FFEA00">Allowed Pointer Arithmetic Operations</span>**

| Operation   | Valid?         |
| ----------- | -------------- |
| ptr++       | ✔              |
| ptr--       | ✔              |
| ptr+n       | ✔              |
| ptr-n       | ✔              |
| ptr1-ptr2   | ✔              |
| ptr1 < ptr2 | ✔ (same array) |

---

# **<span style="color:#FF5733">Invalid Operations</span>**

---

## **Adding Two Pointers**

```cpp
ptr1 + ptr2;
```

Meaningless.

Compiler error.

---

## **Multiplying Pointer**

```cpp
ptr * 5;
```

Invalid.

---

## **Dividing Pointer**

```cpp
ptr / 2;
```

Invalid.

---

# **<span style="color:#00E5FF">Where Pointer Arithmetic is Used</span>**

---

## **1. Array Traversal</span>**

```cpp
for(int* p = arr;
    p < arr+5;
    ++p)
{
    cout << *p;
}
```

---

## **2. STL Iterator Implementation</span>**

`vector` iterators internally use pointer arithmetic.

```cpp
it + 5
```

works because of this concept.

---

## **3. Memory Allocators</span>**

Custom allocators:

```cpp
current += block_size;
```

---

## **4. Operating Systems</span>**

Kernel memory management.

---

## **5. Embedded Systems</span>**

Accessing memory-mapped hardware registers.

---

## **6. High Performance Libraries</span>**

Examples:

- BLAS
- NumPy backend
- Tensor libraries

---

# **<span style="color:#FF5733">Where We Should Avoid Pointer Arithmetic</span>**

---

## **Avoid in Application Code**

Instead of:

```cpp
int* p = arr;

*(p + 3)
```

prefer:

```cpp
arr[3]
```

More readable.

---

## **Avoid Crossing Array Bounds**

```cpp
ptr = arr + 1000;
```

when array size is:

```cpp
10
```

Undefined Behavior.

---

## **Avoid Pointer Arithmetic on Unknown Memory**

```cpp
char* p;
p += 100;
```

Dangerous.

---

# **<span style="color:#FFEA00">Common Bugs</span>**

---

## **Off-by-One Error**

```cpp
for(int* p = arr;
    p <= arr+size;
    ++p)
```

Accesses one element beyond array.

---

## **Out-of-Bounds Access**

```cpp
*(arr + 100)
```

when size is 10.

Undefined behavior.

---

## **Subtracting Different Arrays**

```cpp
int a[10];
int b[10];

&a[5] - &b[3];
```

Undefined behavior.

---

# **<span style="color:#00E5FF">Performance Analysis</span>**

---

## **Array Indexing**

```cpp
arr[i]
```

Compiler converts to:

```cpp
*(arr+i)
```

Same machine code.

---

## **Cost**

Both:

```cpp
arr[i]
```

and

```cpp
*(ptr+i)
```

are:

```text
O(1)
```

and usually compile to identical instructions.

---

# **<span style="color:#00FF9C">Most Important Insight</span>**

Pointer arithmetic is fundamentally:

> **Address arithmetic scaled by the size of the pointed-to type**

The compiler does **not** add raw bytes directly.

When it sees:

```cpp
ptr + n
```

it actually generates something conceptually equivalent to:

```cpp
reinterpret_cast<char*>(ptr)
+
n * sizeof(*ptr)
```

and then converts back to the original pointer type.

This scaling behavior is what allows pointer arithmetic to move correctly from one object to the next regardless of whether the object is an `int`, `double`, `struct`, or class.
