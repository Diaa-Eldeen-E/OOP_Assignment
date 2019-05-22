#ifndef MATRIX_H
#define MATRIX_H

#include "../problem-1/array.h"

#include <iostream>
#include <cmath>
using namespace std;


template <typename any > class matrix : public array<any>
{
private:
	int n, m;
	any **a;
public:
	//constructors
	matrix()  { n = 1; m = 1; a = new any*[1]; a[0] = new any[1]; } // default constructor  creates a single element matrix
	matrix(int r, int c);
	matrix(matrix &mat);
	matrix(int r, int c, any**mat);
	//getters
	int getN();
	int getM();
	any** getA();
	//setters
	void setN(int);
	void setM(int);
	void setA(any**);
	//functions
	void setElement(int, int, any);  //set element at a certain position(`i`, `j`)
	any  getElement(int, int);   //get element at a certain position
	matrix matrixTranspose();
	matrix matrixInverse();
	void elementsPrint();
	//operators
	//unary operators
	matrix& operator~();    // transpose operator  
	//binary operators
	matrix& operator^(int p);    // power operator
	// object matrix in the RHS
	matrix operator=(matrix rhs);   // equal operator
	matrix operator+(matrix rhs);   // plus operator
	matrix operator-(matrix rhs);   // minus operator
	matrix operator*(matrix rhs);   // multiply operator
	matrix operator/(matrix rhs);   // divide operator
	matrix& operator+=(matrix rhs);   // += operator
	matrix& operator-=(matrix rhs);   // -= operator
	matrix& operator*=(matrix rhs);   // *= operator
	matrix& operator/=(matrix rhs);   // /= operator
	// normal c++ matrix in the RHS
	matrix operator=(any** rhs);   // equal operator
	matrix operator+(any** rhs);   // plus operator
	matrix operator-(any**  rhs);   // minus operator
	matrix operator*(any**  rhs);   // multiply operator
	matrix operator/(any**  rhs);   // divide operator
	matrix& operator+=(any**  rhs);   // += operator
	matrix& operator-=(any**  rhs);   // -= operator
	matrix& operator*=(any**  rhs);   // *= operator
	matrix& operator/=(any**  rhs);   // /= operator


	// normal c++ matrix in the LHS
	// Those must be defined here because of the template class
	friend matrix operator+(any** lhs, matrix rhs)   // plus operator
	{
		any** result = new any*[rhs.n];
		for (int i = 0; i < rhs.n; i++)
		{
			result[i] = new any[rhs.m];
			for (int j = 0; j < rhs.m; j++)  result[i][j] = lhs[i][j] + rhs.a[i][j];
		}
		return matrix<any>(rhs.n, rhs.m, result);
		for (int i = 0; i < rhs.n; i++) delete result[i];
		delete[] result;
	}
	friend matrix operator-(any** lhs, matrix rhs)   // minus operator
	{
		any** result = new any*[rhs.n];
		for (int i = 0; i < rhs.n; i++)
		{
			result[i] = new any[rhs.m];
			for (int j = 0; j < rhs.m; j++)  result[i][j] = lhs[i][j] - rhs.a[i][j];
		}
		return matrix<any>(rhs.n, rhs.m, result);
		for (int i = 0; i < rhs.n; i++) delete result[i];
		delete[] result;
	}
	// this multiply works only for n= rhs.n and m = rhs.m  
	friend matrix operator*(any** lhs, matrix rhs)   // multiply operator
	{
		any ** result = new any *[rhs.n];
		for (int i = 0; i < rhs.n; i++)
		{
			result[i] = new any[rhs.m];
			for (int j = 0; j < rhs.m; j++)
			{
				result[i][j] = 0;
				for (int k = 0; k<rhs.m; k++)  result[i][j] += lhs[i][k] * rhs.a[k][j];
			}
		}
		return matrix<any>(rhs.n, rhs.m, result);
		for (int i = 0; i < rhs.n; i++) delete result[i];
		delete[] result;
	}
	friend matrix operator/(any** lhs, matrix rhs)   // divide operator
	{
		return  lhs * rhs.matrixInverse();
	}


	// object array in the RHS
	matrix<any> operator*(array<any> arr);
	matrix<any> operator*=(array<any> arr);


	// input , output operators 
	// Those must be defined here because of the template class
	friend ostream& operator<< (ostream& out, const matrix&mat)  // cout
	{

		for (int i = 0; i < mat.n; i++)
		{
			for (int j = 0; j < mat.m; j++) out << " " << mat.a[i][j] << " ";
			cout << endl;
		}

		return out;
	}
	friend istream& operator>> (istream & in, matrix &mat)  // cin
	{
		for (int i = 0; i < mat.n; i++)
		{
			for (int j = 0; j < mat.m; j++)
			{
				cout << "ObjectMatrix [" << i << "] [" << j << "] : ";
				in >> mat.a[i][j];
			}
		}
		return in;
	}

	//destructor
	~matrix();
};

	// functions for getting the inverse of the matrix
	template <class any > any determinant(any **matrix, int size);
	template <class any> any** transpose(any **matrix, any **matrix_cofactor, int size);
	template <class any> any** cofactor(any **matrix, int size);

#endif
