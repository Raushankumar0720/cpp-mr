# 📘 Constructors in C++

A complete, practical guide to **C++ constructors**, covering syntax, behavior, memory flow, and interview-critical rules.

This guide focuses on:

✅ Internal working  
✅ Performance impact  
✅ Memory management  
✅ Interview preparation  
✅ Industry best practices  

---

## 📑 Table of Contents

1. [Introduction](#introduction)
2. [Constructor Basics](#constructor-basics)
3. [Object Creation Flow](#object-creation-flow)
4. [Types of Constructors](#types-of-constructors)
   - [Default Constructor](#default-constructor)
   - [Parameterized Constructor](#parameterized-constructor)
   - [Copy Constructor](#copy-constructor)
   - [Move Constructor](#move-constructor)
5. [Constructor Selection Process](#constructor-selection-process)
6. [Memory & Resource Flow](#memory--resource-flow)
7. [Rule of Three & Rule of Five](#rule-of-three--rule-of-five)
8. [Common Mistakes](#common-mistakes)
9. [Interview Notes](#interview-notes)
10. [Summary](#summary)

---

# Introduction

In C++, **constructors** are special member functions that initialize objects.

They are responsible for:

✔ Allocating memory  
✔ Initializing variables  
✔ Acquiring resources  
✔ Ensuring object validity  

⚠ Without constructors, C++ programs become unsafe and unreliable.

---

# Constructor Basics

### Key Properties

A constructor:

✅ Has same name as class  
✅ Has NO return type  
✅ Runs automatically  
✅ Initializes data members  

Example:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "Constructor called";
    }
};
Object Creation Flow

When this line executes:

A obj;

C++ internally performs:

Execution Steps
1 → Allocate Memory
2 → Call Constructor
3 → Initialize Members
4 → Object Ready
Flow Diagram
+---------+
|  new A  |
+---------+
     |
     v
+--------------+
| Allocate RAM |
+--------------+
     |
     v
+------------------+
| Call Constructor |
+------------------+
     |
     v
+-------------+
| Object Ready|
+-------------+

⚠ Constructor is called after memory allocation.

Types of Constructors

C++ provides four major constructor types:

Type	Purpose
Default	Basic initialization
Parameterized	Custom initialization
Copy	Duplicate objects
Move	Transfer resources
Default Constructor
Definition

Automatically created when no constructor is defined.

class A {
};

Usage:

A obj;
Flow
A obj
  ↓
Default Constructor
  ↓
Object Created

⚠ If any constructor exists → default is NOT generated.

Parameterized Constructor
Definition

Allows passing values during object creation.

class A {
public:
    int x;

    A(int val) {
        x = val;
    }
};

Usage:

A obj(10);
Flow
A(10)
  ↓
x = 10
  ↓
Object Ready

⚠ Blocks compiler from creating default constructor.

Copy Constructor
Definition

Creates a new object from an existing object.

class A {
public:
    int x;

    A(int v) {
        x = v;
    }

    A(const A& obj) {
        x = obj.x;
    }
};

Usage:

A a1(10);
A a2(a1);
Copy Flow
a1 --------+
           |
           v
     Copy Constructor
           |
           v
          a2
Called When

✅ Pass by value
✅ Return by value
✅ Initialize from another object

⚠ Must use const reference.

Move Constructor
Definition

Transfers ownership instead of copying.

Introduced in C++11.

#include <utility>

class A {
public:
    int* data;

    A(int v) {
        data = new int(v);
    }

    A(A&& obj) {
        data = obj.data;
        obj.data = nullptr;
    }
};

Usage:

A obj(move(temp));
Move Flow
temp.data -----> obj.data
      |
      v
   nullptr
Benefits

✅ Faster
✅ Less memory
✅ No duplication

⚠ Essential for performance-critical code.

Constructor Selection Process

Compiler selects constructor based on arguments.

A obj;           // Default
A obj(5);        // Parameterized
A obj(a1);       // Copy
A obj(move(x));  // Move
Resolution Logic
Check Parameters
      ↓
Exact Match?
      ↓
Select Constructor
Memory & Resource Flow
Without Move (Copy)
Object A --> Copy --> Object B
   |                 |
  Heap              Heap

❌ Two memory blocks
❌ Slower

With Move
Object A ----> Object B
   |
 nullptr

✅ One memory block
✅ Faster

Rule of Three & Rule of Five
Rule of Three

If class manages resources → define:

1️⃣ Destructor
2️⃣ Copy Constructor
3️⃣ Copy Assignment

Rule of Five (C++11+)

Add:

4️⃣ Move Constructor
5️⃣ Move Assignment

Structure
+-------------------+
| Destructor        |
| Copy Constructor  |
| Copy Assignment   |
| Move Constructor  |
| Move Assignment   |
+-------------------+

⚠ Ignoring this causes memory bugs.

Common Mistakes

❌ Missing const in copy constructor
❌ Memory leaks
❌ Shallow copy
❌ No move constructor
❌ Double delete
❌ Raw pointer misuse

Wrong
A(A& obj); // ❌
Correct
A(const A& obj); // ✅
Interview Notes

Prepare answers for:

✔ Copy vs Move
✔ Why move is faster
✔ Rule of Five
✔ RAII
✔ Resource management

Common Question

Why move constructor is needed?

Answer:

To eliminate unnecessary deep copies and improve performance.

Summary
Feature	Purpose
Constructor	Initialize object
Default	Basic setup
Parameterized	Custom setup
Copy	Duplicate
Move	Transfer
Rule of Five	Resource safety