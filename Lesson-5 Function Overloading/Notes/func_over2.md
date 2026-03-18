### 🔍 Code Recap:

```cpp
void add(float, float);
void add(int, float);

int main()
{
    add(4, 4);       // Case 1 ✅
    add(4.0f, 4);    // Case 2 ✅
    add(4.0, 4);     // Case 3 ❌ Ambiguity
}
```

---

### ✅ Case-wise Behavior

| Case           | Types Passed  | Chosen Function     | Why                                   |
| -------------- | ------------- | ------------------- | ------------------------------------- |
| `add(4, 4)`    | `int, int`    | `add(int, float)`   | 1 int→float (better than 2 conv)      |
| `add(4.0f, 4)` | `float, int`  | `add(float, float)` | 1 int→float (better than 1 float→int) |
| `add(4.0, 4)`  | `double, int` | ❌ Ambiguous        | Both require 2 standard conversions   |

---

### 🧠 C++ Overload Resolution Rules (Simplified)

C++ chooses the best match using the following **conversion ranking (from best to worst)**:

1. ✅ **Exact match**
2. 🟢 **Promotion** (e.g., `char → int`)
3. 🟡 **Standard conversion** (e.g., `int → float`, `double → int`)
4. 🟠 **User-defined conversion**
5. 🔴 **Ellipsis (`...`)**

If two or more candidates require the **same level of conversion**, the call is **ambiguous** ❌.

---

### 📌 Thumb Rule for Ambiguity in Function Overloading

> ✅ **If two or more overloads require the same number and kind of standard conversions, and neither is a strictly better match, the call is ambiguous.**

🔁 **Avoid ambiguity** by:

- Matching argument types exactly
- Using suffixes (`f` for `float`, `u` for `unsigned`, etc.)
- Not mixing `int`, `float`, `double` without clear intent

---

### ✅ Summary Table

| Function            | Accepts                                         |
| ------------------- | ----------------------------------------------- |
| `add(int, float)`   | Best for `int, int` or `int, float`             |
| `add(float, float)` | Best for `float, int` or `float, float`         |
| `add(double, int)`  | Not declared → ambiguity when `double` involved |

---
