#include "array.h"

// Put your class definition here
template <class any> array<any>::array(int m)   // create an empty array
{
	n = m;
	a = new any[n];
}

template <class any> array<any>::array(array &objectArray)      // copy array from another object    
{
	n = objectArray.n;
	a = new any[n];
	for (int i = 0; i < n; i++)  { a[i] = objectArray.a[i]; }
}

template <class any> array<any>::array(int m, any *normalArray)  // copy normal c++ array
{
	n = m;
	a = new any[n];
	for (int i = 0; i < n; i++)  { a[i] = normalArray[i]; }
}

// setters
template <class any>  void array<any>::setN(int m)  { n = m; }    // set number of elements                  

template <class any> void array<any>::setA(any *arr)  //set array already created
{
	for (int i = 0; i < n; i++)  { a[i] = arr[i]; }
}
// getters
template <class any> any* array<any>::getA() const   { return a; }   // get the array

template <class any>  int array<any>::getN() const   { return n; }  // get the number of elements
//functions
template <class any> void array<any>::setElement(int index, any T)    { a[index] = T; }  // set an element in the array

template <class any> any array<any>::getElement(int index)            { return a[index]; }  // get an element from the array

template <class any> double array<any>::arrayAverage()     // get the array average
{
	double sum = 0;
	for (int i = 0; i < n; i++)  { sum += a[i]; }
	return (sum / n);
}
template <class any> void array<any>::elementsPrint()         // print the array elements
{
	for (int i = 0; i < n; i++)  { cout << a[i] << " "; }
}

//Unary operator
template <class any> array<any>& array<any>::operator-() // negate all elements
{
	for (int i = 0; i < n; i++) { a[i] = -(a[i]); }
	return*this;
}

// binary operators
// for an object array in the RHS
template <class any> array<any> array<any>::operator=(array rhs)  // equal operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++)  { a[i] = rhs.a[i]; }
	return *this;
	delete result;
}
template <class any> array<any> array<any>::operator+(array rhs)  // plus operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] + rhs.a[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any> array<any>::operator-(array rhs)  // minus operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] - rhs.a[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any> array<any>::operator*(array rhs)  // multiplying operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] * rhs.a[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any> array<any>::operator/(array rhs)  // dividing operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] / rhs.a[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any>& array<any>::operator+=(array rhs)  // += operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] + rhs.a[i]; }
	return*this;
}
template <class any> array<any>& array<any>::operator-=(array rhs)  // -= operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] - rhs.a[i]; }
	return*this;
}
template <class any> array<any>& array<any>::operator*=(array rhs)  // *= operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] * rhs.a[i]; }
	return*this;
}
template <class any> array<any>& array<any>::operator/=(array rhs)  // /= operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] / rhs.a[i]; }
	return*this;
}


// for a normal array in the RHS
template <class any> array<any> array<any>::operator=(any * rhs)  // equal operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { a[i] = rhs[i]; }
	return *this;
	delete result;
}
template <class any> array<any> array<any>::operator+(any * rhs)  // plus operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] + rhs[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any> array<any>::operator-(any * rhs)  // minus operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] - rhs[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any> array<any>::operator*(any * rhs)  // multiplying operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] * rhs[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any> array<any>::operator/(any * rhs)  // dividing operator
{
	any* result = new any[n];
	for (int i = 0; i < n; i++) { result[i] = a[i] / rhs[i]; }
	return array(n, result);
	delete result;
}
template <class any> array<any>& array<any>::operator+=(any * rhs)  // += operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] + rhs[i]; }
	return*this;
}
template <class any> array<any>& array<any>::operator-=(any * rhs)  // -= operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] - rhs[i]; }
	return*this;
}
template <class any> array<any>& array<any>::operator*=(any * rhs)  // *= operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] * rhs[i]; }
	return*this;
}
template <class any> array<any>& array<any>::operator/=(any * rhs)  // /= operator
{
	for (int i = 0; i < n; i++) { a[i] = a[i] / rhs[i]; }
	return*this;
}


template <class any> any array<any>::operator[](int index)  { return a[index]; }  // [] operator

// destructor
template <class any>  array<any>::~array() { delete a; }

