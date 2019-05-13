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


// this is for template implementation to work
// to avoid all this coming code ... we should put the class declaration and defination in one file (not separated)

template array<int>::array(int);
template array<double>::array(int);
template array<float>::array(int);
template array<char>::array(int);
template array<unsigned int>::array(int);
template array<short int>::array(int);
template array<unsigned short int>::array(int);
template array<long int>::array(int);
template array<unsigned long int>::array(int);
template array<long long int>::array(int);
template array<unsigned long long int>::array(int);
template array<signed char>::array(int);
template array<unsigned char>::array(int);

template array<int>::array(array &);
template array<double>::array(array &);
template array<float>::array(array &);
template array<char>::array(array &);
template array<unsigned int>::array(array &);
template array<short int>::array(array &);
template array<unsigned short int>::array(array &);
template array<long int>::array(array &);
template array<unsigned long int>::array(array &);
template array<long long int>::array(array &);
template array<unsigned long long int>::array(array &);
template array<signed char>::array(array &);
template array<unsigned char>::array(array &);

template array<int>::array(int r, int*);
template array<double>::array(int r, double*);
template array<float>::array(int r, float*);
template array<char>::array(int r, char*);
template array<unsigned int>::array(int r, unsigned int*);
template array<short int>::array(int r, short int*);
template array<unsigned short int>::array(int r, unsigned short int*);
template array<long int>::array(int r, long int*);
template array<unsigned long int>::array(int r, unsigned long int*);
template array<long long int>::array(int r, long long int*);
template array<unsigned long long int>::array(int r, unsigned long long int*);
template array<signed char>::array(int r, signed char*);
template array<unsigned char>::array(int r, unsigned char*);

template void array<int>::setN(int);
template void array<double>::setN(int);
template void array<float>::setN(int);
template void array<char>::setN(int);
template void array<unsigned int>::setN(int);
template void array<short int>::setN(int);
template void array<unsigned short int>::setN(int);
template void array<long int>::setN(int);
template void array<unsigned long int>::setN(int);
template void array<long long int>::setN(int);
template void array<unsigned long long int>::setN(int);
template void array<signed char>::setN(int);
template void array<unsigned char>::setN(int);

template void array<int>::setA(int*);
template void array<double>::setA(double*);
template void array<float>::setA(float*);
template void array<char>::setA(char*);
template void array<unsigned int>::setA(unsigned int*);
template void array<short int>::setA(short int*);
template void array<unsigned short int>::setA(unsigned short int*);
template void array<long int>::setA(long int*);
template void array<unsigned long int>::setA(unsigned long int*);
template void array<long long int>::setA(long long int*);
template void array<unsigned long long int>::setA(unsigned long long int*);
template void array<signed char>::setA(signed char*);
template void array<unsigned char>::setA(unsigned char*);

template int array<int>::getN() const;
template int array<double>::getN() const;
template int array<float>::getN() const;
template int array<char>::getN() const;
template int array<unsigned int>::getN() const;
template int array<short int>::getN() const;
template int array<unsigned short int>::getN() const;
template int array<long int>::getN() const;
template int array<unsigned long int>::getN() const;
template int array<long long int>::getN() const;
template int array<unsigned long long int>::getN() const;
template int array<signed char>::getN() const;
template int array<unsigned char>::getN() const;


template int* array<int>::getA() const;
template double* array<double>::getA() const;
template float* array<float>::getA() const;
template char* array<char>::getA() const;
template unsigned int* array<unsigned int>::getA() const;
template short int* array<short int>::getA() const;
template unsigned short int* array<unsigned short int>::getA() const;
template long int* array<long int>::getA() const;
template unsigned long int* array<unsigned long int>::getA() const;
template long long int* array<long long int>::getA() const;
template unsigned long long int* array<unsigned long long int>::getA() const;
template signed char* array<signed char>::getA() const;
template unsigned char* array<unsigned char>::getA() const;

template void array<int>::setElement(int, int T);
template void array<double>::setElement(int, double T);
template void array<float>::setElement(int, float T);
template void array<char>::setElement(int, char T);
template void array<unsigned int>::setElement(int, unsigned int T);
template void array<short int>::setElement(int, short int T);
template void array<unsigned short int>::setElement(int, unsigned short int T);
template void array<long int>::setElement(int, long int T);
template void array<unsigned long int>::setElement(int, unsigned long int T);
template void array<long long int>::setElement(int, long long int T);
template void array<unsigned long long int>::setElement(int, unsigned long long int T);
template void array<signed char>::setElement(int, signed char T);
template void array<unsigned char>::setElement(int, unsigned char T);

template int array<int>::getElement(int);
template double array<double>::getElement(int);
template float array<float>::getElement(int);
template char array<char>::getElement(int);
template unsigned int array<unsigned int>::getElement(int);
template short int array<short int>::getElement(int);
template unsigned short int array<unsigned short int>::getElement(int);
template long int array<long int>::getElement(int);
template unsigned long int array<unsigned long int>::getElement(int);
template long long int array<long long int>::getElement(int);
template unsigned long long int array<unsigned long long int>::getElement(int);
template signed char array<signed char>::getElement(int);
template unsigned char array<unsigned char>::getElement(int);

template double array<int>::arrayAverage();
template double array<double>::arrayAverage();
template double array<float>::arrayAverage();
template double array<char>::arrayAverage();
template double array<unsigned int>::arrayAverage();
template double array<short int>::arrayAverage();
template double array<unsigned short int>::arrayAverage();
template double array<long int>::arrayAverage();
template double array<unsigned long int>::arrayAverage();
template double array<long long int>::arrayAverage();
template double array<unsigned long long int>::arrayAverage();
template double array<signed char>::arrayAverage();
template double array<unsigned char>::arrayAverage();

template void array<int>::elementsPrint();
template void array<double>::elementsPrint();
template void array<float>::elementsPrint();
template void array<char>::elementsPrint();
template void array<unsigned int>::elementsPrint();
template void array<short int>::elementsPrint();
template void array<unsigned short int>::elementsPrint();
template void array<long int>::elementsPrint();
template void array<unsigned long int>::elementsPrint();
template void array<long long int>::elementsPrint();
template void array<unsigned long long int>::elementsPrint();
template void array<signed char>::elementsPrint();
template void array<unsigned char>::elementsPrint();

template array<int>& array<int>::operator-();
template array<double>& array<double>::operator-();
template array<float>& array<float>::operator-();
template array<char>& array<char>::operator-();
template array<short int>& array<short int>::operator-();
template array<long int>& array<long int>::operator-();
template array<long long int>& array<long long int>::operator-();
template array<signed char>& array<signed char>::operator-();

template array<int> array<int>::operator=(array rhs);
template array<double> array<double>::operator=(array rhs);
template array<float> array<float>::operator=(array rhs);
template array<char> array<char>::operator=(array rhs);
template array<unsigned int> array<unsigned int>::operator=(array rhs);
template array<short int> array<short int>::operator=(array rhs);
template array<unsigned short int> array<unsigned short int>::operator=(array rhs);
template array<long int> array<long int>::operator=(array rhs);
template array<unsigned long int> array<unsigned long int>::operator=(array rhs);
template array<long long int> array<long long int>::operator=(array rhs);
template array<unsigned long long int> array<unsigned long long int>::operator=(array rhs);
template array<signed char> array<signed char>::operator=(array rhs);
template array<unsigned char> array<unsigned char>::operator=(array rhs);

template array<int> array<int>::operator+(array rhs);
template array<double> array<double>::operator+(array rhs);
template array<float> array<float>::operator+(array rhs);
template array<char> array<char>::operator+(array rhs);
template array<unsigned int> array<unsigned int>::operator+(array rhs);
template array<short int> array<short int>::operator+(array rhs);
template array<unsigned short int> array<unsigned short int>::operator+(array rhs);
template array<long int> array<long int>::operator+(array rhs);
template array<unsigned long int> array<unsigned long int>::operator+(array rhs);
template array<long long int> array<long long int>::operator+(array rhs);
template array<unsigned long long int> array<unsigned long long int>::operator+(array rhs);
template array<signed char> array<signed char>::operator+(array rhs);
template array<unsigned char> array<unsigned char>::operator+(array rhs);

template array<int> array<int>::operator-(array rhs);
template array<double> array<double>::operator-(array rhs);
template array<float> array<float>::operator-(array rhs);
template array<char> array<char>::operator-(array rhs);
template array<unsigned int> array<unsigned int>::operator-(array rhs);
template array<short int> array<short int>::operator-(array rhs);
template array<unsigned short int> array<unsigned short int>::operator-(array rhs);
template array<long int> array<long int>::operator-(array rhs);
template array<unsigned long int> array<unsigned long int>::operator-(array rhs);
template array<long long int> array<long long int>::operator-(array rhs);
template array<unsigned long long int> array<unsigned long long int>::operator-(array rhs);
template array<signed char> array<signed char>::operator-(array rhs);
template array<unsigned char> array<unsigned char>::operator-(array rhs);

template array<int> array<int>::operator*(array rhs);
template array<double> array<double>::operator*(array rhs);
template array<float> array<float>::operator*(array rhs);
template array<char> array<char>::operator*(array rhs);
template array<unsigned int> array<unsigned int>::operator*(array rhs);
template array<short int> array<short int>::operator*(array rhs);
template array<unsigned short int> array<unsigned short int>::operator*(array rhs);
template array<long int> array<long int>::operator*(array rhs);
template array<unsigned long int> array<unsigned long int>::operator*(array rhs);
template array<long long int> array<long long int>::operator*(array rhs);
template array<unsigned long long int> array<unsigned long long int>::operator*(array rhs);
template array<signed char> array<signed char>::operator*(array rhs);
template array<unsigned char> array<unsigned char>::operator*(array rhs);

template array<int> array<int>::operator/(array rhs);
template array<double> array<double>::operator/(array rhs);
template array<float> array<float>::operator/(array rhs);
template array<char> array<char>::operator/(array rhs);
template array<unsigned int> array<unsigned int>::operator/(array rhs);
template array<short int> array<short int>::operator/(array rhs);
template array<unsigned short int> array<unsigned short int>::operator/(array rhs);
template array<long int> array<long int>::operator/(array rhs);
template array<unsigned long int> array<unsigned long int>::operator/(array rhs);
template array<long long int> array<long long int>::operator/(array rhs);
template array<unsigned long long int> array<unsigned long long int>::operator/(array rhs);
template array<signed char> array<signed char>::operator/(array rhs);
template array<unsigned char> array<unsigned char>::operator/(array rhs);

template array<int>& array<int>::operator+=(array rhs);
template array<double>& array<double>::operator+=(array rhs);
template array<float>& array<float>::operator+=(array rhs);
template array<char>& array<char>::operator+=(array rhs);
template array<unsigned int>& array<unsigned int>::operator+=(array rhs);
template array<short int>& array<short int>::operator+=(array rhs);
template array<unsigned short int>& array<unsigned short int>::operator+=(array rhs);
template array<long int>& array<long int>::operator+=(array rhs);
template array<unsigned long int>& array<unsigned long int>::operator+=(array rhs);
template array<long long int>& array<long long int>::operator+=(array rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator+=(array rhs);
template array<signed char>& array<signed char>::operator+=(array rhs);
template array<unsigned char>& array<unsigned char>::operator+=(array rhs);

template array<int>& array<int>::operator-=(array rhs);
template array<double>& array<double>::operator-=(array rhs);
template array<float>& array<float>::operator-=(array rhs);
template array<char>& array<char>::operator-=(array rhs);
template array<unsigned int>& array<unsigned int>::operator-=(array rhs);
template array<short int>& array<short int>::operator-=(array rhs);
template array<unsigned short int>& array<unsigned short int>::operator-=(array rhs);
template array<long int>& array<long int>::operator-=(array rhs);
template array<unsigned long int>& array<unsigned long int>::operator-=(array rhs);
template array<long long int>& array<long long int>::operator-=(array rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator-=(array rhs);
template array<signed char>& array<signed char>::operator-=(array rhs);
template array<unsigned char>& array<unsigned char>::operator-=(array rhs);

template array<int>& array<int>::operator*=(array rhs);
template array<double>& array<double>::operator*=(array rhs);
template array<float>& array<float>::operator*=(array rhs);
template array<char>& array<char>::operator*=(array rhs);
template array<unsigned int>& array<unsigned int>::operator*=(array rhs);
template array<short int>& array<short int>::operator*=(array rhs);
template array<unsigned short int>& array<unsigned short int>::operator*=(array rhs);
template array<long int>& array<long int>::operator*=(array rhs);
template array<unsigned long int>& array<unsigned long int>::operator*=(array rhs);
template array<long long int>& array<long long int>::operator*=(array rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator*=(array rhs);
template array<signed char>& array<signed char>::operator*=(array rhs);
template array<unsigned char>& array<unsigned char>::operator*=(array rhs);

template array<int>& array<int>::operator/=(array rhs);
template array<double>& array<double>::operator/=(array rhs);
template array<float>& array<float>::operator/=(array rhs);
template array<char>& array<char>::operator/=(array rhs);
template array<unsigned int>& array<unsigned int>::operator/=(array rhs);
template array<short int>& array<short int>::operator/=(array rhs);
template array<unsigned short int>& array<unsigned short int>::operator/=(array rhs);
template array<long int>& array<long int>::operator/=(array rhs);
template array<unsigned long int>& array<unsigned long int>::operator/=(array rhs);
template array<long long int>& array<long long int>::operator/=(array rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator/=(array rhs);
template array<signed char>& array<signed char>::operator/=(array rhs);
template array<unsigned char>& array<unsigned char>::operator/=(array rhs);

template array<int> array<int>::operator=(int* rhs);
template array<double> array<double>::operator=(double* rhs);
template array<float> array<float>::operator=(float* rhs);
template array<char> array<char>::operator=(char* rhs);
template array<unsigned int> array<unsigned int>::operator=(unsigned int* rhs);
template array<short int> array<short int>::operator=(short int* rhs);
template array<unsigned short int> array<unsigned short int>::operator=(unsigned short int* rhs);
template array<long int> array<long int>::operator=(long int* rhs);
template array<unsigned long int> array<unsigned long int>::operator=(unsigned long int* rhs);
template array<long long int> array<long long int>::operator=(long long int* rhs);
template array<unsigned long long int> array<unsigned long long int>::operator=(unsigned long long int* rhs);
template array<signed char> array<signed char>::operator=(signed char* rhs);
template array<unsigned char> array<unsigned char>::operator=(unsigned char* rhs);

template array<int> array<int>::operator+(int* rhs);
template array<double> array<double>::operator+(double* rhs);
template array<float> array<float>::operator+(float* rhs);
template array<char> array<char>::operator+(char* rhs);
template array<unsigned int> array<unsigned int>::operator+(unsigned int* rhs);
template array<short int> array<short int>::operator+(short int* rhs);
template array<unsigned short int> array<unsigned short int>::operator+(unsigned short int* rhs);
template array<long int> array<long int>::operator+(long int* rhs);
template array<unsigned long int> array<unsigned long int>::operator+(unsigned long int* rhs);
template array<long long int> array<long long int>::operator+(long long int* rhs);
template array<unsigned long long int> array<unsigned long long int>::operator+(unsigned long long int* rhs);
template array<signed char> array<signed char>::operator+(signed char* rhs);
template array<unsigned char> array<unsigned char>::operator+(unsigned char* rhs);

template array<int> array<int>::operator-(int* rhs);
template array<double> array<double>::operator-(double* rhs);
template array<float> array<float>::operator-(float* rhs);
template array<char> array<char>::operator-(char* rhs);
template array<unsigned int> array<unsigned int>::operator-(unsigned int* rhs);
template array<short int> array<short int>::operator-(short int* rhs);
template array<unsigned short int> array<unsigned short int>::operator-(unsigned short int* rhs);
template array<long int> array<long int>::operator-(long int* rhs);
template array<unsigned long int> array<unsigned long int>::operator-(unsigned long int* rhs);
template array<long long int> array<long long int>::operator-(long long int* rhs);
template array<unsigned long long int> array<unsigned long long int>::operator-(unsigned long long int* rhs);
template array<signed char> array<signed char>::operator-(signed char* rhs);
template array<unsigned char> array<unsigned char>::operator-(unsigned char* rhs);

template array<int> array<int>::operator*(int* rhs);
template array<double> array<double>::operator*(double* rhs);
template array<float> array<float>::operator*(float* rhs);
template array<char> array<char>::operator*(char* rhs);
template array<unsigned int> array<unsigned int>::operator*(unsigned int*rhs);
template array<short int> array<short int>::operator*(short int* rhs);
template array<unsigned short int> array<unsigned short int>::operator*(unsigned short int* rhs);
template array<long int> array<long int>::operator*(long int* rhs);
template array<unsigned long int> array<unsigned long int>::operator*(unsigned long int* rhs);
template array<long long int> array<long long int>::operator*(long long int* rhs);
template array<unsigned long long int> array<unsigned long long int>::operator*(unsigned long long int* rhs);
template array<signed char> array<signed char>::operator*(signed char* rhs);
template array<unsigned char> array<unsigned char>::operator*(unsigned char* rhs);

template array<int> array<int>::operator/(int* rhs);
template array<double> array<double>::operator/(double* rhs);
template array<float> array<float>::operator/(float* rhs);
template array<char> array<char>::operator/(char* rhs);
template array<unsigned int> array<unsigned int>::operator/(unsigned int* rhs);
template array<short int> array<short int>::operator/(short int* rhs);
template array<unsigned short int> array<unsigned short int>::operator/(unsigned short int* rhs);
template array<long int> array<long int>::operator/(long int* rhs);
template array<unsigned long int> array<unsigned long int>::operator/(unsigned long int* rhs);
template array<long long int> array<long long int>::operator/(long long int* rhs);
template array<unsigned long long int> array<unsigned long long int>::operator/(unsigned long long int* rhs);
template array<signed char> array<signed char>::operator/(signed char* rhs);
template array<unsigned char> array<unsigned char>::operator/(unsigned char* rhs);

template array<int>& array<int>::operator+=(int* rhs);
template array<double>& array<double>::operator+=(double* rhs);
template array<float>& array<float>::operator+=(float* rhs);
template array<char>& array<char>::operator+=(char* rhs);
template array<unsigned int>& array<unsigned int>::operator+=(unsigned int* rhs);
template array<short int>& array<short int>::operator+=(short int* rhs);
template array<unsigned short int>& array<unsigned short int>::operator+=(unsigned short int* rhs);
template array<long int>& array<long int>::operator+=(long int* rhs);
template array<unsigned long int>& array<unsigned long int>::operator+=(unsigned long int* rhs);
template array<long long int>& array<long long int>::operator+=(long long int* rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator+=(unsigned long long int* rhs);
template array<signed char>& array<signed char>::operator+=(signed char* rhs);
template array<unsigned char>& array<unsigned char>::operator+=(unsigned char* rhs);

template array<int>& array<int>::operator-=(int* rhs);
template array<double>& array<double>::operator-=(double* rhs);
template array<float>& array<float>::operator-=(float* rhs);
template array<char>& array<char>::operator-=(char* rhs);
template array<unsigned int>& array<unsigned int>::operator-=(unsigned int* rhs);
template array<short int>& array<short int>::operator-=(short int* rhs);
template array<unsigned short int>& array<unsigned short int>::operator-=(unsigned short int* rhs);
template array<long int>& array<long int>::operator-=(long int* rhs);
template array<unsigned long int>& array<unsigned long int>::operator-=(unsigned long int* rhs);
template array<long long int>& array<long long int>::operator-=(long long int* rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator-=(unsigned long long int* rhs);
template array<signed char>& array<signed char>::operator-=(signed char* rhs);
template array<unsigned char>& array<unsigned char>::operator-=(unsigned char* rhs);

template array<int>& array<int>::operator*=(int* rhs);
template array<double>& array<double>::operator*=(double* rhs);
template array<float>& array<float>::operator*=(float* rhs);
template array<char>& array<char>::operator*=(char* rhs);
template array<unsigned int>& array<unsigned int>::operator*=(unsigned int* rhs);
template array<short int>& array<short int>::operator*=(short int* rhs);
template array<unsigned short int>& array<unsigned short int>::operator*=(unsigned short int* rhs);
template array<long int>& array<long int>::operator*=(long int* rhs);
template array<unsigned long int>& array<unsigned long int>::operator*=(unsigned long int* rhs);
template array<long long int>& array<long long int>::operator*=(long long int* rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator*=(unsigned long long int* rhs);
template array<signed char>& array<signed char>::operator*=(signed char* rhs);
template array<unsigned char>& array<unsigned char>::operator*=(unsigned char* rhs);

template array<int>& array<int>::operator/=(int* rhs);
template array<double>& array<double>::operator/=(double* rhs);
template array<float>& array<float>::operator/=(float* rhs);
template array<char>& array<char>::operator/=(char* rhs);
template array<unsigned int>& array<unsigned int>::operator/=(unsigned int* rhs);
template array<short int>& array<short int>::operator/=(short int* rhs);
template array<unsigned short int>& array<unsigned short int>::operator/=(unsigned short int* rhs);
template array<long int>& array<long int>::operator/=(long int* rhs);
template array<unsigned long int>& array<unsigned long int>::operator/=(unsigned long int* rhs);
template array<long long int>& array<long long int>::operator/=(long long int* rhs);
template array<unsigned long long int>& array<unsigned long long int>::operator/=(unsigned long long int* rhs);
template array<signed char>& array<signed char>::operator/=(signed char* rhs);
template array<unsigned char>& array<unsigned char>::operator/=(unsigned char* rhs);

template int array<int>::operator[](int index);
template double array<double>::operator[](int index);
template float array<float>::operator[](int index);
template char array<char>::operator[](int index);
template unsigned int array<unsigned int>::operator[](int index);
template short int array<short int>::operator[](int index);
template unsigned short int array<unsigned short int>::operator[](int index);
template long int array<long int>::operator[](int index);
template unsigned long int array<unsigned long int>::operator[](int index);
template long long int array<long long int>::operator[](int index);
template unsigned long long int array<unsigned long long int>::operator[](int index);
template signed char array<signed char>::operator[](int index);
template unsigned char array<unsigned char>::operator[](int index);
