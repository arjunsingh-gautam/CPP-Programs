# **<span style="color:#00E5FF">Smart Pointer Syntax, Initialization, Usage, and Internal Working</span>**

Before diving into syntax, remember:

> Smart pointers are not "better pointers".

They are:

```text
Pointer
+
Ownership Rules
+
Automatic Cleanup
```

The three smart pointers solve three different ownership problems:

| Smart Pointer | Ownership Model         |
| ------------- | ----------------------- |
| `unique_ptr`  | Single owner            |
| `shared_ptr`  | Multiple owners         |
| `weak_ptr`    | Observer (no ownership) |

---

# **<span style="color:#FFEA00">1. std::unique_ptr</span>**

---

## **What Problem Does It Solve?</span>**

Suppose you own a car.

```text
Owner = You
```

Only one legal owner exists.

If ownership transfers:

```text
You lose ownership
New person becomes owner
```

This is exactly how `unique_ptr` works.

---

# **<span style="color:#00E5FF">Syntax of unique_ptr</span>**

```cpp
std::unique_ptr<int> ptr;
```

Breakdown:

```cpp
std::unique_ptr
```

Smart pointer type.

---

```cpp
<int>
```

Object type managed.

---

```cpp
ptr
```

Variable name.

---

# **<span style="color:#FFEA00">Best Initialization Method</span>**

```cpp
auto ptr = std::make_unique<int>(10);
```

---

### Internal Steps

#### Step 1

Allocate heap memory.

```text
Heap

[10]
```

---

#### Step 2

Store address.

```text
unique_ptr
      |
      v

Heap
[10]
```

---

#### Step 3

Remember ownership.

```text
ptr owns object
```

---

# **<span style="color:#FFEA00">Alternative Initialization</span>**

Less preferred:

```cpp
std::unique_ptr<int> ptr(new int(10));
```

Works.

But modern C++ prefers:

```cpp
std::make_unique()
```

---

# **<span style="color:#FFEA00">Using unique_ptr</span>**

```cpp
auto ptr = std::make_unique<int>(10);

std::cout << *ptr;
```

Output:

```text
10
```

---

## **Member Access</span>**

```cpp
ptr->method();
```

Just like raw pointers.

---

# **<span style="color:#FFEA00">Ownership Transfer (Move)</span>**

```cpp
auto p1 =
    std::make_unique<int>(10);

auto p2 =
    std::move(p1);
```

---

Before:

```text
p1 ---> object
```

---

After:

```text
p1 ---> nullptr

p2 ---> object
```

Ownership transferred.

---

# **<span style="color:#00FF9C">Simple Example</span>**

```cpp
#include <memory>
#include <iostream>

int main()
{
    auto ptr =
        std::make_unique<int>(100);

    std::cout << *ptr;
}
```

When scope ends:

```text
Destructor runs
delete automatically called
```

---

# **<span style="color:#00FF9C">Best Practices</span>**

Use `unique_ptr`:

- By default
- Whenever there is one owner

Think:

```text
unique_ptr first
shared_ptr only if necessary
```

---

---

# **<span style="color:#00E5FF">2. std::shared_ptr</span>**

---

## **What Problem Does It Solve?</span>**

Imagine a Netflix account.

```text
Multiple family members use same account
```

Ownership is shared.

Account should be deleted only when:

```text
Last member leaves
```

This is `shared_ptr`.

---

# **<span style="color:#00E5FF">Syntax of shared_ptr</span>**

```cpp
std::shared_ptr<int> ptr;
```

---

# **<span style="color:#FFEA00">Best Initialization</span>**

```cpp
auto ptr =
    std::make_shared<int>(10);
```

---

# **<span style="color:#FFEA00">Internal Working</span>**

When created:

```text
Control Block

count = 1

      |
      v

Heap Object
```

---

## **Create Another Owner</span>**

```cpp
auto p2 = ptr;
```

Now:

```text
count = 2
```

---

## **Destroy One Owner</span>**

```text
count = 1
```

Object still alive.

---

## **Destroy Last Owner</span>**

```text
count = 0
```

Now:

```text
delete object
delete control block
```

---

# **<span style="color:#00FF9C">Simple Example</span>**

```cpp
#include <memory>
#include <iostream>

int main()
{
    auto p1 =
        std::make_shared<int>(50);

    auto p2 = p1;

    std::cout
        << p1.use_count();
}
```

Output:

```text
2
```

---

# **<span style="color:#00FF9C">Best Practices</span>**

Use only when:

```text
Multiple genuine owners exist
```

Avoid:

```text
shared_ptr everywhere
```

because:

```text
Reference counting has overhead
```

---

---

# **<span style="color:#00E5FF">3. std::weak_ptr</span>**

This is the hardest smart pointer to understand.

---

# **<span style="color:#FFEA00">Problem That weak_ptr Solves</span>**

Let's build two objects.

---

## **Person A Owns Person B</span>**

```text
A ---> B
```

---

## **Person B Owns Person A</span>**

```text
B ---> A
```

---

Now:

```text
A reference count = 1
B reference count = 1
```

---

Even if nobody outside uses them:

```text
Counts never become 0
```

Memory leak.

---

# **<span style="color:#FF5733">This is Circular Reference</span>**

Visualization:

```text
+---------+
|    A    |
+---------+
     |
     v

+---------+
|    B    |
+---------+
     |
     v

Back to A
```

Each object keeps the other alive forever.

---

# **<span style="color:#00E5FF">Real Example</span>**

```cpp
class B;

class A
{
public:
    std::shared_ptr<B> bptr;
};

class B
{
public:
    std::shared_ptr<A> aptr;
};
```

Problem:

```text
A owns B
B owns A
```

Neither dies.

---

# **<span style="color:#FFEA00">How weak_ptr Fixes This</span>**

Change one side:

```cpp
class B
{
public:
    std::weak_ptr<A> aptr;
};
```

---

Now:

```text
A owns B
```

But:

```text
B only observes A
```

---

Reference count:

```text
A count = 1
B count = 1
```

No circular ownership.

---

When last shared owner disappears:

```text
A destroyed
B destroyed
```

Correct.

---

# **<span style="color:#FFEA00">Analogy for weak_ptr</span>**

Imagine Instagram.

---

### shared_ptr

You own a house.

Ownership counts.

---

### weak_ptr

You only know the address.

You do not own the house.

If house is demolished:

```text
You lose access
```

but demolition is not prevented.

---

This is exactly what `weak_ptr` does.

---

# **<span style="color:#00E5FF">Syntax of weak_ptr</span>**

```cpp
std::weak_ptr<int> weak;
```

---

## **Initialization</span>**

```cpp
auto shared =
    std::make_shared<int>(10);

std::weak_ptr<int> weak =
    shared;
```

---

Notice:

```text
Reference count unchanged
```

---

# **<span style="color:#FFEA00">How To Access Object</span>**

Cannot do:

```cpp
*weak;
```

---

Must first:

```cpp
auto temp =
    weak.lock();
```

---

If object still exists:

```text
lock()
```

returns:

```cpp
shared_ptr
```

---

Otherwise:

```text
nullptr
```

---

Example:

```cpp
if(auto temp = weak.lock())
{
    std::cout << *temp;
}
```

---

# **<span style="color:#00FF9C">Simple Example</span>**

```cpp
auto shared =
    std::make_shared<int>(100);

std::weak_ptr<int> weak =
    shared;

if(auto p = weak.lock())
{
    std::cout << *p;
}
```

Output:

```text
100
```

---

# **<span style="color:#FFEA00">Complete Comparison</span>**

| Feature                 | unique_ptr | shared_ptr | weak_ptr    |
| ----------------------- | ---------- | ---------- | ----------- |
| Ownership               | Single     | Shared     | None        |
| Copyable                | No         | Yes        | Yes         |
| Movable                 | Yes        | Yes        | Yes         |
| Auto Cleanup            | Yes        | Yes        | No          |
| Ref Count               | No         | Yes        | No increase |
| Circular Reference Safe | Yes        | No         | Yes         |

---

# **<span style="color:#00FF9C">Best Practices</span>**

---

## **Use unique_ptr By Default</span>**

```cpp
auto p =
    std::make_unique<T>();
```

Most common.

---

## **Use shared_ptr Only If Ownership Is Truly Shared</span>**

Ask:

```text
Do multiple objects own this resource?
```

If no:

```text
Do not use shared_ptr
```

---

## **Use weak_ptr For Observer Relationships</span>**

Examples:

- Parent-child graphs
- GUI widgets
- Observer pattern
- Caches

---

## **Always Prefer make_unique / make_shared</span>**

Good:

```cpp
std::make_unique<T>()
std::make_shared<T>()
```

Avoid:

```cpp
new T
```

directly.

---

# **<span style="color:#FF5733">Common Beginner Mistake</span>**

Many beginners think:

```text
weak_ptr = weaker shared_ptr
```

Wrong.

---

Actual meaning:

```text
shared_ptr = ownership

weak_ptr = observation
```

A `weak_ptr` is not about weak ownership.

It is about:

> **No ownership at all.**

---

# **<span style="color:#00FF9C">The Most Important Insight</span>**

Think of smart pointers not as pointers, but as **ownership models**:

- `unique_ptr` → "I own it."
- `shared_ptr` → "We own it."
- `weak_ptr` → "I know about it, but I don't own it."

Once you understand ownership rather than syntax, the behavior of every smart pointer becomes intuitive.
