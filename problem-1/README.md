## Problem 1
Design and implement an `array` class.
The class should accept any type for array elements, i.e. use templates.
The class should have the members below.
Make sure to use appropriate data types and access modifiers.

**Member Variables**:
- `a` : pointer to the array
- `n` : size of the array

**Member Functions**:
- Constructor that takes array size as an argument and creates an array of that size
- Copy constructor that takes another array object and copies elements of that array
- Copy constructor that takes a C++ array, creates and copies the array elements into the new object
- Destructor that deletes the array from memory
- Getters and setters
- Function to add/set an element at certain index
- Function to get element at certain index
- Function to find average of the array
- Function to print elements of the array

**Operators**:

For:
```
array<int> a(n1);
array<int> b(n2);
int x[n3];
```
The user should be able to do the following operations:

```
-a; // negate all elements

a + b;
a + x;
x + a;

a - b;
a - x;
x - a;

a * b; // element by element multiplication
a * x;
x * a;

a / b; // element by element division
a / x;
x / a;

a += b;
a += x;

a -= b;
a -= x;

a *= b;
a *= x;

a /= b;
a /= x;

cout << a[5]; // operator[]

cin >> a; // read elements of a
cout << a;  // print elements of a
```

