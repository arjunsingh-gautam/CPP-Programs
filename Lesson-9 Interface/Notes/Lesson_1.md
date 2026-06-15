# **<span style="color:#00E5FF">Interface Files (.hpp/.h) and Implementation Files (.cpp) in C++</span>**

One of the biggest shifts from writing small C++ programs to building large software systems is learning to separate:

```text
What a component does
from
How a component does it
```

This is exactly why C++ uses:

```text
Header File (.hpp/.h)
+
Source File (.cpp)
```

---

# **<span style="color:#FFEA00">The Fundamental Problem</span>**

Suppose you're building a large application.

```text
Banking System

├── Account
├── Customer
├── Transaction
├── Loan
├── Payment
└── Database
```

Imagine all code is written inside:

```cpp
main.cpp
```

Eventually:

```text
50,000+
100,000+
500,000+ lines
```

become impossible to manage.

We need modularity.

---

# **<span style="color:#FFEA00">First Principle: Interface vs Implementation</span>**

Think about driving a car.

You know:

```text
Steering Wheel
Brake
Accelerator
Gear
```

You do NOT need to know:

```text
Engine Timing
Fuel Injection
Transmission Internals
```

---

### Driver's View

```text
What the car can do
```

This is:

```text
Interface
```

---

### Mechanic's View

```text
How the car works internally
```

This is:

```text
Implementation
```

---

C++ follows the same philosophy.

---

# **<span style="color:#00E5FF">What is an Interface File (.hpp)?</span>**

An interface file contains:

```text
Declarations
```

It tells the compiler:

```text
What exists
What functions are available
What classes exist
```

but not how they work.

---

## **Example</span>**

### Math.hpp

```cpp
#ifndef MATH_HPP
#define MATH_HPP

class Math
{
public:

    int add(int a, int b);

    int subtract(int a, int b);
};

#endif
```

---

This file says:

```text
There is a class called Math

It contains:

add()
subtract()
```

But it does NOT show implementation.

---

# **<span style="color:#00E5FF">What is an Implementation File (.cpp)?</span>**

Contains:

```text
Actual definitions
```

---

### Math.cpp

```cpp
#include "Math.hpp"

int Math::add(int a, int b)
{
    return a + b;
}

int Math::subtract(int a, int b)
{
    return a - b;
}
```

---

Now compiler knows:

```text
How add works
How subtract works
```

---

# **<span style="color:#FFEA00">Why Separate Interface and Implementation?</span>**

---

## **Reason 1: Encapsulation</span>**

Users only see:

```cpp
int add(int,int);
```

Not:

```cpp
Complex internal algorithm
```

---

## **Reason 2: Faster Compilation</span>**

Suppose:

```text
100 source files
```

depend on:

```cpp
Math.hpp
```

---

If you modify:

```cpp
Math.cpp
```

only:

```text
Math.cpp
```

needs recompilation.

---

If everything lived in headers:

```text
Many files recompiled
```

---

## **Reason 3: Team Development</span>**

Team A:

```text
Writes interface
```

Team B:

```text
Uses interface
```

without knowing implementation.

---

# **<span style="color:#00E5FF">Internal Working of .hpp and .cpp</span>**

---

## **Header Files Are Not Compiled Alone</span>**

Many beginners think:

```text
Header file = compiled
```

Wrong.

---

Compiler compiles:

```text
.cpp files only
```

---

Suppose:

```cpp
#include "Math.hpp"
```

---

Preprocessor literally replaces:

```cpp
#include "Math.hpp"
```

with contents of file.

---

### Example

Before preprocessing:

```cpp
#include "Math.hpp"

int main()
{
}
```

---

After preprocessing:

```cpp
class Math
{
public:
    int add(int,int);
};

int main()
{
}
```

---

Header is copied into source.

---

# **<span style="color:#FFEA00">Compilation Pipeline</span>**

Suppose:

```text
main.cpp
Math.cpp
Math.hpp
```

---

## **Step 1: Preprocessing</span>**

```cpp
#include "Math.hpp"
```

expanded.

---

## **Step 2: Compilation</span>**

Compiler creates:

```text
main.o
Math.o
```

(Object Files)

---

## **Step 3: Linking</span>**

Linker resolves:

```text
Math::add()
```

references.

---

Produces:

```text
a.out
program.exe
```

---

# **<span style="color:#00E5FF">How to Write Good Header Files</span>**

---

# **<span style="color:#00FF9C">Good Practice #1: Only Declarations</span>**

Good:

```cpp
class Logger
{
public:
    void log();
};
```

---

Bad:

```cpp
class Logger
{
public:

    void log()
    {
        // 500 lines
    }
};
```

---

Headers should be lightweight.

---

# **<span style="color:#00FF9C">Good Practice #2: Include Guards</span>**

Always:

```cpp
#ifndef LOGGER_HPP
#define LOGGER_HPP

...

#endif
```

---

Prevents:

```text
Multiple inclusion
```

errors.

---

Alternative:

```cpp
#pragma once
```

Modern and common.

---

# **<span style="color:#00FF9C">Good Practice #3: Minimize Includes</span>**

Bad:

```cpp
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
```

when unnecessary.

---

Include only what is needed.

---

# **<span style="color:#00FF9C">Good Practice #4: Prefer Forward Declaration</span>**

Instead of:

```cpp
#include "Engine.hpp"
```

sometimes:

```cpp
class Engine;
```

is enough.

---

Reduces compile time.

---

# **<span style="color:#FF5733">Bad Practices</span>**

---

## **Putting Everything in Header</span>**

```cpp
5000-line header
```

Compile times explode.

---

## **Using using namespace std;</span>**

Never put:

```cpp
using namespace std;
```

inside headers.

---

Reason:

Affects every file including it.

---

## **Including Unnecessary Headers</span>**

Creates dependency explosion.

---

# **<span style="color:#00E5FF">File Structure Example</span>**

---

## **Calculator.hpp</span>**

```cpp
#pragma once

class Calculator
{
public:

    int add(int a, int b);

    int multiply(int a, int b);
};
```

---

## **Calculator.cpp</span>**

```cpp
#include "Calculator.hpp"

int Calculator::add(int a, int b)
{
    return a + b;
}

int Calculator::multiply(int a, int b)
{
    return a * b;
}
```

---

## **main.cpp</span>**

```cpp
#include <iostream>
#include "Calculator.hpp"

int main()
{
    Calculator calc;

    std::cout
        << calc.add(10,20)
        << '\n';

    std::cout
        << calc.multiply(10,20)
        << '\n';
}
```

---

# **<span style="color:#00E5FF">How Include Paths Work</span>**

---

## **Local Header</span>**

```cpp
#include "Calculator.hpp"
```

Compiler searches:

```text
Current Directory
Configured Include Paths
```

---

## **System Header</span>**

```cpp
#include <vector>
```

Compiler searches:

```text
System Include Directories
```

---

# **<span style="color:#FFEA00">Recommended Project Structure</span>**

```text
Project/

├── include/
│   └── Calculator.hpp

├── src/
│   └── Calculator.cpp

├── main.cpp
```

---

Include:

```cpp
#include "Calculator.hpp"
```

and pass include directory during compilation.

---

# **<span style="color:#00E5FF">How to Compile</span>**

---

## **Linux / macOS (g++)</span>**

```bash
g++ main.cpp src/Calculator.cpp -Iinclude -o app
```

---

Explanation:

```text
main.cpp
```

Main program.

---

```text
src/Calculator.cpp
```

Implementation file.

---

```text
-Iinclude
```

Add include directory.

---

```text
-o app
```

Output executable.

---

Run:

```bash
./app
```

---

# **<span style="color:#00E5FF">How Visual Studio / CMake Handles It</span>**

Modern projects typically use:

- CMake
- Visual Studio
- CLion
- VS Code Tasks

The build system automatically:

1. Finds `.cpp` files
2. Sets include paths
3. Compiles
4. Links

---

# **<span style="color:#FFEA00">Header vs Source File Comparison</span>**

| Property          | Header (.hpp) | Source (.cpp)    |
| ----------------- | ------------- | ---------------- |
| Contains          | Declarations  | Definitions      |
| Compiled Directly | No            | Yes              |
| Included By       | Other files   | Usually not      |
| Purpose           | Interface     | Implementation   |
| Visibility        | Public        | Private/Internal |
| Compile Impact    | High          | Lower            |

---

# **<span style="color:#00FF9C">Most Important Insight</span>**

Think of a header file as a **contract** and a source file as the **implementation of that contract**.

The header answers:

```text
What services are available?
```

The source file answers:

```text
How are those services implemented?
```

Large-scale C++ software is built on this separation because it improves:

- Modularity
- Encapsulation
- Team collaboration
- Build times
- Maintainability

This interface/implementation separation is one of the foundational design principles behind professional C++ codebases.
