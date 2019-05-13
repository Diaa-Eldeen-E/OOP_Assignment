## Problem 2
A matrix is a 2-dimensional array.
Design and implement a `matrix` class that inherits from the `array` class.
The class should accept any type for array elements, i.e. use templates.
The class should have the members below.

> **Hint**: Some member functions of the `array` class should be `virtual`

**Member Variables**:
- `a` : pointer to the matrix (2-D array)
- `n` : number of rows
- `m` : number of columns

**Member Functions**:
- Constructor that takes `n` and `m` as arguments and creates the matrix
- Copy constructor that takes another array object and copies elements of that array
- Copy constructor that takes a 2-D array, creates and copies the array elements into the new object
- Destructor that deletes the matrix from memory
- Getters and setters
- Function to add/set element at a certain position (`i`, `j`)
- Function to get element at a certain position
- Function to transpose a square matrix
- Function to find inverse of a square matrix
- Function to print elements of the matrix

**Operators**:

For:
```
matrix<int> a(n1,m1);
matrix<int> b(n2,m2);
array<int> c(n3);
int x[n4][m4];
```
The user should be able to do the following operations:

```
~a; // matrix transpose (only if square)

a ^ 2; // power

a + b; // matrices must be of same size
a + x;
x + a;

a - b; // matrices must be of same size
a - x;
x - a;

a * b; // inner dimensions must agree, i.e. m1 == n2
a * c;
a * x;
x * a;

a / b; // a * b.inverse()
a / x;
x / a;

a += b;
a += x;

a -= b;
a -= x;

a *= b;
a *= c;
a *= x;

a /= b;
a /= x;

cin >> a; // read all elements of a
cout << a;  // print elements of a
```
##### Your code should check for validity conditions, e.g.:
- Position (`i`, `j`) is within the dimensions of the matrix (`n`, `m`)
- Sizes of matrices to be added/subtracted must be the same
- Inner dimensions of matrices to be multiplied must be the same
- Perform transpose/inverse on square matrix only