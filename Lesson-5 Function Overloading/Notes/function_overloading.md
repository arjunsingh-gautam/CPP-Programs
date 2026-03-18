# ✅ **1. What is function overloading?**

You can create many functions with the **same name**, as long as they have **different parameters**:

```cpp
void fun(int);
void fun(double);
void fun(int, int);
```

When you call `fun(...)`, the compiler must decide **which one fits best**.

---

# ✅ **2. How does the compiler choose? (Simple Explanation)**

Think of this as the compiler doing _three steps_:

---

# **STEP 1: Find all functions with the same name**

If you write:

```cpp
fun(5);
```

Compiler looks for **all functions named `fun`**.

Suppose these exist:

```cpp
void fun(int);
void fun(double);
void fun(char);
```

All 3 are candidates.

---

# **STEP 2: Remove functions that absolutely DO NOT match**

Compiler checks which ones can accept an `int`.

- `fun(int)` → perfect match
- `fun(double)` → possible (int → double)
- `fun(char)` → possible (int → char)

All 3 are still acceptable.

(If one had `fun(string)` → impossible, removed)

---

# **STEP 3: Pick the "best match"**

Compiler chooses the function that requires the **least amount of conversion**.

Priority:

1. **Exact match** (best)
2. **Small promotion** (char → int, float → double)
3. **Normal conversion** (int → double, double → int)
4. **User-defined conversion** (very expensive)
5. **Ellipsis `...`** (worst)

So for:

```cpp
fun(5);
```

`fun(int)` wins because it is an **exact match**.

---

# 🎯 **When does compiler say AMBIGUOUS?**

When **two or more functions are equally good** choices.

Example:

```cpp
void fun(long);
void fun(double);

fun(5);  // ambiguous?
```

`5` is an `int`.

- `int → long` (normal conversion)
- `int → double` (normal conversion)

Both are **equally good**, so compiler cannot decide → ❌ ambiguous error.

---

# 🎯 **Another ambiguous example**

```cpp
void fun(char);
void fun(short);

fun(5);   // int
```

Conversions:

- int → char (narrowing)
- int → short (narrowing)

Both same cost → ❌ ambiguous.

---

# 🎯 **Ambiguity with default arguments**

```cpp
void fun(int a, int b = 10);
void fun(int a);

fun(5);  // ambiguous
```

Why?

- `fun(5)` matches perfectly
- `fun(5,10)` also matches perfectly

Compiler sees _two equally good_ options → ❌ ambiguous.

---

# 🎯 **Ambiguity with references**

```cpp
void fun(int&);
void fun(const int&);

const int x = 10;
fun(x);  // both match because x is const
```

Both are perfect matches → ❌ ambiguous.

---

# 🎯 **Ambiguity with templates**

```cpp
void fun(int);
template<typename T>
void fun(T);

fun(5);  // calls non-template fun(int)
```

But:

```cpp
template<typename T> void fun(T);
template<> void fun<int>(int);

fun(5);  // two equal matches → ambiguous
```

---

# 💡 **Summary in one line**

The compiler selects the overloaded function by picking the one that needs the **least amount of conversion**.
If two or more are equally good, the call is **ambiguous** and the compiler errors.

---
