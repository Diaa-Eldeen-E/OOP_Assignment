#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <class any> class array
{
private:
	int n;
	any *a;
public:
	//constructors
	array()  { n = 1; a = new any[1]; } // default constructor
	array(int m);
	array(array &objectArray);
	array(int m, any *arr);
	//setters
	void setN(int);
	void setA(any *);
	//getters
	int getN() const;
	any* getA() const;
	// functions
	void setElement(int, any T);
	any getElement(int);
	double arrayAverage();
	void elementsPrint();
	//operators
	array& operator-();        // negate all elements
	// for object array in the RHS
	array operator=(array rhs);  // equal operator
	array operator+(array rhs);  // plus operator
	array operator-(array rhs);  // minus operator
	array operator*(array rhs);  // multiplying operator
	array operator/(array rhs);  // dividing operator
	array& operator+=(array rhs);  // += operator
	array& operator-=(array rhs);  // -= operator
	array& operator*=(array rhs);  // *= operator
	array& operator/=(array rhs);  // /= operator
	//  normal c++ array in the RHS
	array operator=(any * rhs);  // equal operator
	array operator+(any * rhs);  // plus operator
	array operator-(any * rhs);  // minus operator
	array operator*(any * rhs);  // multiplying operator
	array operator/(any * rhs);  // dividing operator
	array& operator+=(any * rhs);  // += operator
	array& operator-=(any * rhs);  // -= operator
	array& operator*=(any * rhs);  // *= operator
	array& operator/=(any * rhs);  // /= operator

	// normal c++ array in the LHS
	// Those must be defined here because of the template class
	friend array operator+(any* lhs, array rhs)  // for x+a
	{
		any* result = new any[rhs.n];
		for (int i = 0; i < rhs.n; i++) { result[i] = lhs[i] + rhs.a[i]; }
		return array(rhs.n, result);
		delete result;
	}
	friend array operator-(any* lhs, array rhs)  // for x-a
	{
		any* result = new any[rhs.n];
		for (int i = 0; i < rhs.n; i++) { result[i] = lhs[i] - rhs.a[i]; }
		return array(rhs.n, result);
		delete result;
	}
	friend array operator*(any* lhs, array rhs)  // for x*a
	{
		any* result = new any[rhs.n];
		for (int i = 0; i < rhs.n; i++) { result[i] = lhs[i] * rhs.a[i]; }
		return array(rhs.n, result);
		delete result;
	}
	friend array operator/(any* lhs, array rhs)  // for x/a
	{
		any* result = new any[rhs.n];
		for (int i = 0; i < rhs.n; i++) { result[i] = lhs[i] / rhs.a[i]; }
		return array(rhs.n, result);
		delete result;
	}


	// input , output operators 
	any operator[](int index);  // [] operator

	// Those must be defined here because of the template class
	friend istream& operator>>(istream& in, array &arr)    //cin
	{
		for (int i = 0; i < arr.n; i++)
		{
			cout << "ObjectArray [" << i << "] : ";
			in >> arr.a[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const  array &arr)    //cout
	{
		for (int i = 0; i < arr.n; i++)  out << arr.a[i] << " ";
		return out;
	}
	//destructor 
	virtual ~array();

};
#endif
