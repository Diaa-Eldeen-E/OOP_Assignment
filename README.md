###
# This is programming language course final assignment

A c++ class "matrix" that also inhierts from a class "array" 

both classes accept any data type e.g. int, double, etc. 

The "array" class can do the following:

* Creates an empty array object of size (n)
* Copies a c++ array into an object array
* Copies an object array into another object array
* Deletes the object array from the memory
* adds/sets an element at a certain index
* gets an element at a certain index
* finds the average of the array
* prints the elements of the array

OverLoaded operators for the "array" class

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

cin >> a; // reads all elements of a
cout << a;  // prints all elements of a

# ***************************************************************************

The "matrix" class inhierts from the "array" class and also can do the following:

* Creates an empty matrix object of size (n) * (m)

* Copies a c++ 2D array into an object matrix

* Copies an object matrix into another object matrix

* Deletes the object matrix from the memory

* adds/sets an element at a certain index ( i , j )

* gets an element at a certain index ( i , j )

* transposes a square matrix

* finds the inverse of a square matrix

* prints the elements of the matrix

OverLoaded operators for the "matrix" class

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

cin >> a; // reads all elements of a
cout << a;  // prints all elements of a
```