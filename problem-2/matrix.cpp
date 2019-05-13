#include "matrix.h"

// Put your class definition here
/*The program crashes when an error message happens because there is no return
(i couldnt return 0 to a ** or an object return type) */


/* functions for getting inverse which i got from searching on the internet so its not totaly mine :D
i modified a alot of it though.
*/
//function to get the matrix determinant
template <class any> any determinant(any **matrix, int size)
{
	any **elementCofactor = new any*[size];
	for (int i = 0; i < size; i++) 	elementCofactor[i] = new any[size];
	any  det = 0;
	int elementSign = 1;
	int m, n;

	if (size == 1)   return (matrix[0][0]);
	else
	{
		for (int c = 0; c < size; c++)   // loop for cofactor matrices
		{
			m = 0;  n = 0;   // to get elementCofactor elements
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (i != 0 && j != c)
					{
						elementCofactor[m][n] = matrix[i][j];
						if (n < (size - 2))  n++;
						else   { n = 0;  m++; }
					}
				}
			}
			det += elementSign * (matrix[0][c] * determinant(elementCofactor, size - 1)); // multiply every element in the first row with its cofactor matrix determinant
			elementSign *= -1;
		}
	}
	return det;
}

//Finding transpose of cofactor matrix
template <class any> any** transpose(any **matrix, any **matrix_cofactor, int size)
{
	any d;
	any **m_transpose = new any*[size];
	any **m_inverse = new any*[size];
	for (int t = 0; t < size; t++)
	{
		m_transpose[t] = new any[size];
		m_inverse[t] = new any[size];
	}
	for (int i = 0; i<size; i++)  for (int j = 0; j<size; j++)   m_transpose[i][j] = matrix_cofactor[j][i];

	d = determinant(matrix, size);

	for (int i = 0; i<size; i++)  for (int j = 0; j<size; j++)   m_inverse[i][j] = m_transpose[i][j] / d;

	return m_inverse;
}

//function to get cofactor matrix
template <class any> any** cofactor(any **matrix, int size)
{
	any** matrixInverse = new any*[size]; for (int i = 0; i < size; i++) matrixInverse[i] = new any[size];
	any** elementCofactor = new any*[size];
	any** matrix_cofactor = new any*[size];
	for (int t = 0; t < size; t++)
	{
		elementCofactor[t] = new any[size];
		matrix_cofactor[t] = new any[size];
	}
	int  m, n;
	for (int q = 0; q<size; q++)
	{
		for (int p = 0; p<size; p++)
		{
			m = 0;
			n = 0;
			for (int i = 0; i<size; i++)
			{
				for (int j = 0; j<size; j++)
				{
					if (i != q && j != p)
					{
						elementCofactor[m][n] = matrix[i][j];
						if (n<(size - 2))   n++;
						else      { n = 0; m++; }
					}
				}
			}
			matrix_cofactor[q][p] = pow(-1.0, q + p) * determinant(elementCofactor, size - 1);
		}
	}
	matrixInverse = transpose(matrix, matrix_cofactor, size);
	return matrixInverse;
}
//  matrix inverse code ends here


//constructors
template <class any> matrix<any>::matrix(int r, int c)     // create an empty matrix
{
	n = r; m = c;
	a = new any*[n];
	for (int i = 0; i < n; i++)  a[i] = new any[m];
}

template <class any> matrix<any>::matrix(matrix &mat)     // copy matrix from another object    
{
	n = mat.n; m = mat.m;
	a = new any*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new any[m];
		for (int j = 0; j < m; j++)  a[i][j] = mat.a[i][j];
	}
}

template <class any> matrix<any>::matrix(int r, int c, any**mat)       // copy normal c++ matrix
{
	n = r; m = c;
	a = new any*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new any[m];
		for (int j = 0; j < m; j++)  a[i][j] = mat[i][j];
	}
}

//getters
template <class any> int matrix<any>::getN()  { return n; } // get n 
template <class any> int matrix<any>::getM()  { return m; } // get m
template <class any> any** matrix<any>::getA()  { return a; } // get matrix
//setters
template <class any> void matrix<any>::setN(int r)      //set n 
{
	n = r;
	a = new any*[n];
	for (int i = 0; i < n; i++)  a[i] = new any[m];
}
template <class any> void matrix<any>::setM(int c)     //set m 
{
	m = c;
	a = new any*[n];
	for (int i = 0; i < n; i++)  a[i] = new any[m];
}
template <class any> void matrix<any>::setA(any**mat)         //set matrix
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)  a[i][j] = mat[i][j];
	}
}
//functions
template <class any> void matrix<any>::setElement(int r, int c, any T) { a[r][c] = T; }  //set element at a certain position
template <class any> any  matrix<any>::getElement(int r, int c) { return a[r][c]; }  //get element at a certain position
template <class any> matrix<any> matrix<any>::matrixTranspose()       // get the matrix transpose          
{
	if (n == m)
	{
		any**Transpose = new any*[n];
		for (int i = 0; i < n; i++)
		{
			Transpose[i] = new any[n];
			for (int j = 0; j < m; j++)  Transpose[i][j] = a[j][i];
		}
		a = Transpose;
		return *this;
		for (int i = 0; i < n; i++) delete Transpose[i];
		delete[] Transpose;
	}
	else cerr << "The matrix must be squared (n=m)" << endl;
}

template <class any> matrix<any> matrix<any>::matrixInverse()  // get the matrix inverse
{

	if (n == m)
	{
		a = cofactor(a, n);
		return *this;
	}
	else cerr << "The matrix must be squared (n=m)" << endl;

}

template <class any> void matrix<any>::elementsPrint()     // print the matrix elements
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << " " << a[i][j] << " ";
		cout << endl;
	}
}

//operators
//unary operators
template <class any> matrix<any>& matrix<any>::operator~()    // transpose operator  
{
	*this = matrixTranspose();
	return *this;
}

//binary operators
template <class any> matrix<any>& matrix<any>::operator^(int p)    // power operator
{
	for (int i = 0; i < n; i++) for (int j = 0; j<m; j++)  a[i][j] = pow(a[i][j], p);
	return*this;
}

// object matrix in the RHS
template <class any> matrix<any> matrix<any>::operator=(matrix<any> rhs)  // equal operator
{
	n = rhs.n;
	m = rhs.m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = rhs.a[i][j];
	return*this;
}
template <class any> matrix<any> matrix<any>::operator+(matrix rhs)   // plus operator
{
	if (n == rhs.n && m == rhs.m)
	{
		any ** result = new any *[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new any[m];
			for (int j = 0; j < m; j++) { result[i][j] = a[i][j] + rhs.a[i][j]; }
		}
		return matrix<any>(n, m, result);
		for (int i = 0; i < n; i++) delete result[i];
		delete[] result;
	}
	else  cerr << "The added matrices must be of the same size" << endl;
}

template <class any> matrix<any> matrix<any>::operator-(matrix<any> rhs)   // minus operator
{
	if (n == rhs.n && m == rhs.m)
	{
		any ** result = new any *[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new any[m];
			for (int j = 0; j < m; j++) result[i][j] = a[i][j] - rhs.a[i][j];
		}
		return matrix<any>(n, m, result);
		for (int i = 0; i < n; i++) delete result[i];
		delete[] result;
	}
	else  cerr << "The subtracted matrices must be of the same size" << endl;
}
template <class any> matrix<any> matrix<any>::operator*(matrix<any> rhs)   // multiply operator
{
	if (m == rhs.n)
	{
		any ** result = new any *[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new any[rhs.m];
			for (int j = 0; j < rhs.m; j++)
			{
				result[i][j] = 0;
				for (int k = 0; k < m; k++)  result[i][j] += a[i][k] * rhs.a[k][j];
			}
		}
		return matrix<any>(n, rhs.m, result);
		for (int i = 0; i < n; i++) delete result[i];
		delete[] result;
	}
	else cerr << "The inner dimensions of the multiplied matrices must be equal" << endl;

}
template <class any> matrix<any> matrix<any>::operator/(matrix<any> rhs)   // divide operator
{
	return  *this * rhs.matrixInverse();
}
template <class any> matrix<any>& matrix<any>::operator+=(matrix<any> rhs)   // += operator
{
	if (n == rhs.n && m == rhs.m)
	{
		for (int i = 0; i < n; i++)  for (int j = 0; j < m; j++) a[i][j] = a[i][j] + rhs.a[i][j];
		return *this;
	}
	else  cerr << "The added matrices must be of the same size" << endl;
}
template <class any> matrix<any>& matrix<any>::operator-=(matrix<any> rhs)   // -= operator
{
	if (n == rhs.n && m == rhs.m)
	{
		for (int i = 0; i < n; i++)  for (int j = 0; j < m; j++) a[i][j] = a[i][j] - rhs.a[i][j];
		return *this;
	}
	else  cerr << "The subtracted matrices must be of the same size" << endl;
}
template <class any> matrix<any>& matrix<any>::operator*=(matrix<any> rhs)   // *= operator
{
	if (m == rhs.n)
	{
		any ** result = new any *[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new any[rhs.m];
			for (int j = 0; j < rhs.m; j++)
			{
				result[i][j] = 0;
				for (int k = 0; k < m; k++)  result[i][j] += a[i][k] * rhs.a[k][j];
			}
		}
		*this = matrix(n, rhs.m, result);
		return *this;
		for (int i = 0; i < n; i++) delete result[i];
		delete[] result;
	}
	else cerr << "The inner dimensions of the multiplied matrices must be equal" << endl;
}
template <class any> matrix<any>& matrix<any>::operator/=(matrix<any> rhs)   // /= operator
{
	*this = *this * rhs.matrixInverse();
	return *this;
}

// normal c++ matrix in the RHS
template <class any> matrix<any> matrix<any>::operator=(any** rhs)    // equal operator
{
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = rhs[i][j];
	return *this;
}
template <class any> matrix<any> matrix<any>::operator+(any** rhs)   // plus operator
{
	any ** result = new any *[n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new any[m];
		for (int j = 0; j < m; j++) result[i][j] = a[i][j] + rhs[i][j];
	}
	return matrix<any>(n, m, result);
	for (int i = 0; i < n; i++) delete result[i];
	delete[] result;
}
template <class any> matrix<any> matrix<any>::operator-(any**  rhs)   // minus operator
{
	any ** result = new any *[n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new any[m];
		for (int j = 0; j < m; j++) result[i][j] = a[i][j] - rhs[i][j];
	}
	return matrix<any>(n, m, result);
	for (int i = 0; i < n; i++) delete result[i];
	delete[] result;
}
/* this multiply works only for n= rhs.n and m = rhs.m  because i need to know the RHS matrix s' rows and columns in order to
make it a general function .... i didnt know how to get the RHS matrix s' number of rows and columns  */
template <class any> matrix<any> matrix<any>::operator*(any**  rhs)   // multiply operator
{
	any ** result = new any *[n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new any[m];
		for (int j = 0; j < m; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k<m; k++)  result[i][j] += a[i][k] * rhs[k][j];
		}
	}
	return matrix<any>(n, m, result);
	for (int i = 0; i < n; i++) delete result[i];
	delete[] result;
}
template <class any> matrix<any> matrix<any>::operator/(any**  rhs)   // divide operator     
{
	return  *this * cofactor(rhs, m);
}
template <class any> matrix<any>& matrix<any>::operator+=(any**  rhs)   // += operator
{
	for (int i = 0; i < n; i++)  for (int j = 0; j < m; j++) a[i][j] = a[i][j] + rhs[i][j];
	return*this;
}
template <class any> matrix<any>& matrix<any>::operator-=(any**  rhs)   // -= operator
{
	for (int i = 0; i < n; i++)  for (int j = 0; j < m; j++) a[i][j] = a[i][j] - rhs[i][j];
	return*this;
}
template <class any> matrix<any>& matrix<any>::operator*=(any**  rhs)   // *= operator    
{
	any ** result = new any *[n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new any[m];
		for (int j = 0; j < m; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k<m; k++)  result[i][j] += a[i][k] * rhs[k][j];
		}
	}
	*this = matrix(n, m, result);
	return *this;
	for (int i = 0; i < n; i++) delete result[i];
	delete[] result;
}
template <class any> matrix<any>& matrix<any>::operator/=(any**  rhs)   // /= operator
{
	*this = *this * cofactor(rhs, m);
	return*this;
}

// for an object array in the RHS
template <class any> matrix<any> matrix<any>::operator*(array<any> arr)      //matrix * array
{
	if (m == 1)
	{
		any ** result = new any *[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new any[arr.getN()];
			for (int j = 0; j < arr.getN(); j++)  result[i][j] = a[i][0] * arr.getElement(j);
		}
		return matrix<any>(n, arr.getN(), result);
		for (int i = 0; i < n; i++) delete result[i];
		delete[] result;
	}
	else cerr << "The inner dimensions of the multiplied matrices must be equal" << endl;
}

template <class any> matrix<any> matrix<any>::operator*=(array<any> arr)        //matrix *= array
{
	if (m == 1)
	{
		any ** result = new any *[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = new any[arr.getN()];
			for (int j = 0; j < arr.getN(); j++)  result[i][j] = a[i][0] * arr.getElement(j);
		}
		m = n;
		a = result;
		return *this;
		for (int i = 0; i < n; i++) delete result[i];
		delete[] result;
	}
	else cerr << "The inner dimensions of the multiplied matrices must be equal" << endl;
}

//destructor
template <class any> matrix<any>::~matrix() { for (int i = 0; i < n; i++) delete a[i]; delete[]a; }





// this is for template implementation to work
// to avoid all this coming code ... we should put the class declaration and defination in one file (not separated)

template matrix<int>::matrix(int r, int c);
template matrix<double>::matrix(int r, int c);
template matrix<float>::matrix(int r, int c);
template matrix<char>::matrix(int r, int c);
template matrix<unsigned int>::matrix(int r, int c);
template matrix<short int>::matrix(int r, int c);
template matrix<unsigned short int>::matrix(int r, int c);
template matrix<long int>::matrix(int r, int c);
template matrix<unsigned long int>::matrix(int r, int c);
template matrix<long long int>::matrix(int r, int c);
template matrix<unsigned long long int>::matrix(int r, int c);
template matrix<signed char>::matrix(int r, int c);
template matrix<unsigned char>::matrix(int r, int c);

template matrix<int>::matrix(matrix &mat);
template matrix<double>::matrix(matrix &mat);
template matrix<float>::matrix(matrix &mat);
template matrix<char>::matrix(matrix &mat);
template matrix<unsigned int>::matrix(matrix &mat);
template matrix<short int>::matrix(matrix &mat);
template matrix<unsigned short int>::matrix(matrix &mat);
template matrix<long int>::matrix(matrix &mat);
template matrix<unsigned long int>::matrix(matrix &mat);
template matrix<long long int>::matrix(matrix &mat);
template matrix<unsigned long long int>::matrix(matrix &mat);
template matrix<signed char>::matrix(matrix &mat);
template matrix<unsigned char>::matrix(matrix &mat);

template matrix<int>::matrix(int r, int c, int**mat);
template matrix<double>::matrix(int r, int c, double**mat);
template matrix<float>::matrix(int r, int c, float**mat);
template matrix<char>::matrix(int r, int c, char**mat);
template matrix<unsigned int>::matrix(int r, int c, unsigned int**mat);
template matrix<short int>::matrix(int r, int c, short int**mat);
template matrix<unsigned short int>::matrix(int r, int c, unsigned short int**mat);
template matrix<long int>::matrix(int r, int c, long int**mat);
template matrix<unsigned long int>::matrix(int r, int c, unsigned long int**mat);
template matrix<long long int>::matrix(int r, int c, long long int**mat);
template matrix<unsigned long long int>::matrix(int r, int c, unsigned long long int**mat);
template matrix<signed char>::matrix(int r, int c, signed char**mat);
template matrix<unsigned char>::matrix(int r, int c, unsigned char**mat);

template int matrix<int>::getN();
template int matrix<double>::getN();
template int matrix<float>::getN();
template int matrix<char>::getN();
template int matrix<unsigned int>::getN();
template int matrix<short int>::getN();
template int matrix<unsigned short int>::getN();
template int matrix<long int>::getN();
template int matrix<unsigned long int>::getN();
template int matrix<long long int>::getN();
template int matrix<unsigned long long int>::getN();
template int matrix<signed char>::getN();
template int matrix<unsigned char>::getN();

template int matrix<int>::getM();
template int matrix<double>::getM();
template int matrix<float>::getM();
template int matrix<char>::getM();
template int matrix<unsigned int>::getM();
template int matrix<short int>::getM();
template int matrix<unsigned short int>::getM();
template int matrix<long int>::getM();
template int matrix<unsigned long int>::getM();
template int matrix<long long int>::getM();
template int matrix<unsigned long long int>::getM();
template int matrix<signed char>::getM();
template int matrix<unsigned char>::getM();

template int** matrix<int>::getA();
template double** matrix<double>::getA();
template float** matrix<float>::getA();
template char** matrix<char>::getA();
template unsigned int** matrix<unsigned int>::getA();
template short int** matrix<short int>::getA();
template unsigned short int** matrix<unsigned short int>::getA();
template long int** matrix<long int>::getA();
template unsigned long int** matrix<unsigned long int>::getA();
template long long int** matrix<long long int>::getA();
template unsigned long long int** matrix<unsigned long long int>::getA();
template signed char** matrix<signed char>::getA();
template unsigned char** matrix<unsigned char>::getA();

template void matrix<int>::setN(int);
template void matrix<double>::setN(int);
template void matrix<float>::setN(int);
template void matrix<char>::setN(int);
template void matrix<unsigned int>::setN(int);
template void matrix<short int>::setN(int);
template void matrix<unsigned short int>::setN(int);
template void matrix<long int>::setN(int);
template void matrix<unsigned long int>::setN(int);
template void matrix<long long int>::setN(int);
template void matrix<unsigned long long int>::setN(int);
template void matrix<signed char>::setN(int);
template void matrix<unsigned char>::setN(int);

template void matrix<int>::setM(int);
template void matrix<double>::setM(int);
template void matrix<float>::setM(int);
template void matrix<char>::setM(int);
template void matrix<unsigned int>::setM(int);
template void matrix<short int>::setM(int);
template void matrix<unsigned short int>::setM(int);
template void matrix<long int>::setM(int);
template void matrix<unsigned long int>::setM(int);
template void matrix<long long int>::setM(int);
template void matrix<unsigned long long int>::setM(int);
template void matrix<signed char>::setM(int);
template void matrix<unsigned char>::setM(int);

template void matrix<int>::setA(int**);
template void matrix<double>::setA(double**);
template void matrix<float>::setA(float**);
template void matrix<char>::setA(char**);
template void matrix<unsigned int>::setA(unsigned int**);
template void matrix<short int>::setA(short int**);
template void matrix<unsigned short int>::setA(unsigned short int**);
template void matrix<long int>::setA(long int**);
template void matrix<unsigned long int>::setA(unsigned long int**);
template void matrix<long long int>::setA(long long int**);
template void matrix<unsigned long long int>::setA(unsigned long long int**);
template void matrix<signed char>::setA(signed char**);
template void matrix<unsigned char>::setA(unsigned char**);

template void matrix<int>::setElement(int, int, int T);
template void matrix<double>::setElement(int, int, double T);
template void matrix<float>::setElement(int, int, float T);
template void matrix<char>::setElement(int, int, char T);
template void matrix<unsigned int>::setElement(int, int, unsigned int T);
template void matrix<short int>::setElement(int, int, short int T);
template void matrix<unsigned short int>::setElement(int, int, unsigned short int T);
template void matrix<long int>::setElement(int, int, long int T);
template void matrix<unsigned long int>::setElement(int, int, unsigned long int T);
template void matrix<long long int>::setElement(int, int, long long int T);
template void matrix<unsigned long long int>::setElement(int, int, unsigned long long int T);
template void matrix<signed char>::setElement(int, int, signed char T);
template void matrix<unsigned char>::setElement(int, int, unsigned char T);

template int matrix<int>::getElement(int, int);
template double matrix<double>::getElement(int, int);
template float matrix<float>::getElement(int, int);
template char matrix<char>::getElement(int, int);
template unsigned int matrix<unsigned int>::getElement(int, int);
template short int matrix<short int>::getElement(int, int);
template unsigned short int matrix<unsigned short int>::getElement(int, int);
template long int matrix<long int>::getElement(int, int);
template unsigned long int matrix<unsigned long int>::getElement(int, int);
template long long int matrix<long long int>::getElement(int, int);
template unsigned long long int matrix<unsigned long long int>::getElement(int, int);
template signed char matrix<signed char>::getElement(int, int);
template unsigned char matrix<unsigned char>::getElement(int, int);

template matrix<int> matrix<int>::matrixTranspose();
template matrix<double> matrix<double>::matrixTranspose();
template matrix<float> matrix<float>::matrixTranspose();
template matrix<char> matrix<char>::matrixTranspose();
template matrix<unsigned int> matrix<unsigned int>::matrixTranspose();
template matrix<short int> matrix<short int>::matrixTranspose();
template matrix<unsigned short int> matrix<unsigned short int>::matrixTranspose();
template matrix<long int> matrix<long int>::matrixTranspose();
template matrix<unsigned long int> matrix<unsigned long int>::matrixTranspose();
template matrix<long long int> matrix<long long int>::matrixTranspose();
template matrix<unsigned long long int> matrix<unsigned long long int>::matrixTranspose();
template matrix<signed char> matrix<signed char>::matrixTranspose();
template matrix<unsigned char> matrix<unsigned char>::matrixTranspose();

template matrix<int> matrix<int>::matrixInverse();
template matrix<double> matrix<double>::matrixInverse();
template matrix<float> matrix<float>::matrixInverse();
template matrix<char> matrix<char>::matrixInverse();
template matrix<unsigned int> matrix<unsigned int>::matrixInverse();
template matrix<short int> matrix<short int>::matrixInverse();
template matrix<unsigned short int> matrix<unsigned short int>::matrixInverse();
template matrix<long int> matrix<long int>::matrixInverse();
template matrix<unsigned long int> matrix<unsigned long int>::matrixInverse();
template matrix<long long int> matrix<long long int>::matrixInverse();
template matrix<unsigned long long int> matrix<unsigned long long int>::matrixInverse();
template matrix<signed char> matrix<signed char>::matrixInverse();
template matrix<unsigned char> matrix<unsigned char>::matrixInverse();

template void matrix<int>::elementsPrint();
template void matrix<double>::elementsPrint();
template void matrix<float>::elementsPrint();
template void matrix<char>::elementsPrint();
template void matrix<unsigned int>::elementsPrint();
template void matrix<short int>::elementsPrint();
template void matrix<unsigned short int>::elementsPrint();
template void matrix<long int>::elementsPrint();
template void matrix<unsigned long int>::elementsPrint();
template void matrix<long long int>::elementsPrint();
template void matrix<unsigned long long int>::elementsPrint();
template void matrix<signed char>::elementsPrint();
template void matrix<unsigned char>::elementsPrint();

template matrix<int>& matrix<int>::operator~();
template matrix<double>& matrix<double>::operator~();
template matrix<float>& matrix<float>::operator~();
template matrix<char>& matrix<char>::operator~();
template matrix<unsigned int>& matrix<unsigned int>::operator~();
template matrix<short int>& matrix<short int>::operator~();
template matrix<unsigned short int>& matrix<unsigned short int>::operator~();
template matrix<long int>& matrix<long int>::operator~();
template matrix<unsigned long int>& matrix<unsigned long int>::operator~();
template matrix<long long int>& matrix<long long int>::operator~();
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator~();
template matrix<signed char>& matrix<signed char>::operator~();
template matrix<unsigned char>& matrix<unsigned char>::operator~();

template matrix<int>& matrix<int>::operator^(int p);
template matrix<double>& matrix<double>::operator^(int p);
template matrix<float>& matrix<float>::operator^(int p);
template matrix<char>& matrix<char>::operator^(int p);
template matrix<unsigned int>& matrix<unsigned int>::operator^(int p);
template matrix<short int>& matrix<short int>::operator^(int p);
template matrix<unsigned short int>& matrix<unsigned short int>::operator^(int p);
template matrix<long int>& matrix<long int>::operator^(int p);
template matrix<unsigned long int>& matrix<unsigned long int>::operator^(int p);
template matrix<long long int>& matrix<long long int>::operator^(int p);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator^(int p);
template matrix<signed char>& matrix<signed char>::operator^(int p);
template matrix<unsigned char>& matrix<unsigned char>::operator^(int p);

template matrix<int> matrix<int>::operator=(matrix rhs);
template matrix<double> matrix<double>::operator=(matrix rhs);
template matrix<float> matrix<float>::operator=(matrix rhs);
template matrix<char> matrix<char>::operator=(matrix rhs);
template matrix<unsigned int> matrix<unsigned int>::operator=(matrix rhs);
template matrix<short int> matrix<short int>::operator=(matrix rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator=(matrix rhs);
template matrix<long int> matrix<long int>::operator=(matrix rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator=(matrix rhs);
template matrix<long long int> matrix<long long int>::operator=(matrix rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator=(matrix rhs);
template matrix<signed char> matrix<signed char>::operator=(matrix rhs);
template matrix<unsigned char> matrix<unsigned char>::operator=(matrix rhs);

template matrix<int> matrix<int>::operator+(matrix rhs);
template matrix<double> matrix<double>::operator+(matrix rhs);
template matrix<float> matrix<float>::operator+(matrix rhs);
template matrix<char> matrix<char>::operator+(matrix rhs);
template matrix<unsigned int> matrix<unsigned int>::operator+(matrix rhs);
template matrix<short int> matrix<short int>::operator+(matrix rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator+(matrix rhs);
template matrix<long int> matrix<long int>::operator+(matrix rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator+(matrix rhs);
template matrix<long long int> matrix<long long int>::operator+(matrix rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator+(matrix rhs);
template matrix<signed char> matrix<signed char>::operator+(matrix rhs);
template matrix<unsigned char> matrix<unsigned char>::operator+(matrix rhs);

template matrix<int> matrix<int>::operator-(matrix rhs);
template matrix<double> matrix<double>::operator-(matrix rhs);
template matrix<float> matrix<float>::operator-(matrix rhs);
template matrix<char> matrix<char>::operator-(matrix rhs);
template matrix<unsigned int> matrix<unsigned int>::operator-(matrix rhs);
template matrix<short int> matrix<short int>::operator-(matrix rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator-(matrix rhs);
template matrix<long int> matrix<long int>::operator-(matrix rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator-(matrix rhs);
template matrix<long long int> matrix<long long int>::operator-(matrix rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator-(matrix rhs);
template matrix<signed char> matrix<signed char>::operator-(matrix rhs);
template matrix<unsigned char> matrix<unsigned char>::operator-(matrix rhs);

template matrix<int> matrix<int>::operator*(matrix rhs);
template matrix<double> matrix<double>::operator*(matrix rhs);
template matrix<float> matrix<float>::operator*(matrix rhs);
template matrix<char> matrix<char>::operator*(matrix rhs);
template matrix<unsigned int> matrix<unsigned int>::operator*(matrix rhs);
template matrix<short int> matrix<short int>::operator*(matrix rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator*(matrix rhs);
template matrix<long int> matrix<long int>::operator*(matrix rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator*(matrix rhs);
template matrix<long long int> matrix<long long int>::operator*(matrix rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator*(matrix rhs);
template matrix<signed char> matrix<signed char>::operator*(matrix rhs);
template matrix<unsigned char> matrix<unsigned char>::operator*(matrix rhs);

template matrix<int> matrix<int>::operator/(matrix rhs);
template matrix<double> matrix<double>::operator/(matrix rhs);
template matrix<float> matrix<float>::operator/(matrix rhs);
template matrix<char> matrix<char>::operator/(matrix rhs);
template matrix<unsigned int> matrix<unsigned int>::operator/(matrix rhs);
template matrix<short int> matrix<short int>::operator/(matrix rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator/(matrix rhs);
template matrix<long int> matrix<long int>::operator/(matrix rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator/(matrix rhs);
template matrix<long long int> matrix<long long int>::operator/(matrix rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator/(matrix rhs);
template matrix<signed char> matrix<signed char>::operator/(matrix rhs);
template matrix<unsigned char> matrix<unsigned char>::operator/(matrix rhs);

template matrix<int>& matrix<int>::operator+=(matrix rhs);
template matrix<double>& matrix<double>::operator+=(matrix rhs);
template matrix<float>& matrix<float>::operator+=(matrix rhs);
template matrix<char>& matrix<char>::operator+=(matrix rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator+=(matrix rhs);
template matrix<short int>& matrix<short int>::operator+=(matrix rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator+=(matrix rhs);
template matrix<long int>& matrix<long int>::operator+=(matrix rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator+=(matrix rhs);
template matrix<long long int>& matrix<long long int>::operator+=(matrix rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator+=(matrix rhs);
template matrix<signed char>& matrix<signed char>::operator+=(matrix rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator+=(matrix rhs);

template matrix<int>& matrix<int>::operator-=(matrix rhs);
template matrix<double>& matrix<double>::operator-=(matrix rhs);
template matrix<float>& matrix<float>::operator-=(matrix rhs);
template matrix<char>& matrix<char>::operator-=(matrix rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator-=(matrix rhs);
template matrix<short int>& matrix<short int>::operator-=(matrix rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator-=(matrix rhs);
template matrix<long int>& matrix<long int>::operator-=(matrix rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator-=(matrix rhs);
template matrix<long long int>& matrix<long long int>::operator-=(matrix rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator-=(matrix rhs);
template matrix<signed char>& matrix<signed char>::operator-=(matrix rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator-=(matrix rhs);

template matrix<int>& matrix<int>::operator*=(matrix rhs);
template matrix<double>& matrix<double>::operator*=(matrix rhs);
template matrix<float>& matrix<float>::operator*=(matrix rhs);
template matrix<char>& matrix<char>::operator*=(matrix rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator*=(matrix rhs);
template matrix<short int>& matrix<short int>::operator*=(matrix rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator*=(matrix rhs);
template matrix<long int>& matrix<long int>::operator*=(matrix rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator*=(matrix rhs);
template matrix<long long int>& matrix<long long int>::operator*=(matrix rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator*=(matrix rhs);
template matrix<signed char>& matrix<signed char>::operator*=(matrix rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator*=(matrix rhs);

template matrix<int>& matrix<int>::operator/=(matrix rhs);
template matrix<double>& matrix<double>::operator/=(matrix rhs);
template matrix<float>& matrix<float>::operator/=(matrix rhs);
template matrix<char>& matrix<char>::operator/=(matrix rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator/=(matrix rhs);
template matrix<short int>& matrix<short int>::operator/=(matrix rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator/=(matrix rhs);
template matrix<long int>& matrix<long int>::operator/=(matrix rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator/=(matrix rhs);
template matrix<long long int>& matrix<long long int>::operator/=(matrix rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator/=(matrix rhs);
template matrix<signed char>& matrix<signed char>::operator/=(matrix rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator/=(matrix rhs);

template matrix<int> matrix<int>::operator=(int** rhs);
template matrix<double> matrix<double>::operator=(double** rhs);
template matrix<float> matrix<float>::operator=(float** rhs);
template matrix<char> matrix<char>::operator=(char** rhs);
template matrix<unsigned int> matrix<unsigned int>::operator=(unsigned int** rhs);
template matrix<short int> matrix<short int>::operator=(short int** rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator=(unsigned short int** rhs);
template matrix<long int> matrix<long int>::operator=(long int** rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator=(unsigned long int** rhs);
template matrix<long long int> matrix<long long int>::operator=(long long int** rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator=(unsigned long long int** rhs);
template matrix<signed char> matrix<signed char>::operator=(signed char** rhs);
template matrix<unsigned char> matrix<unsigned char>::operator=(unsigned char** rhs);

template matrix<int> matrix<int>::operator+(int** rhs);
template matrix<double> matrix<double>::operator+(double** rhs);
template matrix<float> matrix<float>::operator+(float** rhs);
template matrix<char> matrix<char>::operator+(char** rhs);
template matrix<unsigned int> matrix<unsigned int>::operator+(unsigned int** rhs);
template matrix<short int> matrix<short int>::operator+(short int** rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator+(unsigned short int** rhs);
template matrix<long int> matrix<long int>::operator+(long int** rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator+(unsigned long int** rhs);
template matrix<long long int> matrix<long long int>::operator+(long long int** rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator+(unsigned long long int** rhs);
template matrix<signed char> matrix<signed char>::operator+(signed char** rhs);
template matrix<unsigned char> matrix<unsigned char>::operator+(unsigned char** rhs);

template matrix<int> matrix<int>::operator-(int** rhs);
template matrix<double> matrix<double>::operator-(double** rhs);
template matrix<float> matrix<float>::operator-(float** rhs);
template matrix<char> matrix<char>::operator-(char** rhs);
template matrix<unsigned int> matrix<unsigned int>::operator-(unsigned int** rhs);
template matrix<short int> matrix<short int>::operator-(short int** rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator-(unsigned short int** rhs);
template matrix<long int> matrix<long int>::operator-(long int** rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator-(unsigned long int** rhs);
template matrix<long long int> matrix<long long int>::operator-(long long int** rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator-(unsigned long long int** rhs);
template matrix<signed char> matrix<signed char>::operator-(signed char** rhs);
template matrix<unsigned char> matrix<unsigned char>::operator-(unsigned char** rhs);

template matrix<int> matrix<int>::operator*(int** rhs);
template matrix<double> matrix<double>::operator*(double** rhs);
template matrix<float> matrix<float>::operator*(float** rhs);
template matrix<char> matrix<char>::operator*(char** rhs);
template matrix<unsigned int> matrix<unsigned int>::operator*(unsigned int** rhs);
template matrix<short int> matrix<short int>::operator*(short int** rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator*(unsigned short int** rhs);
template matrix<long int> matrix<long int>::operator*(long int** rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator*(unsigned long int** rhs);
template matrix<long long int> matrix<long long int>::operator*(long long int** rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator*(unsigned long long int** rhs);
template matrix<signed char> matrix<signed char>::operator*(signed char** rhs);
template matrix<unsigned char> matrix<unsigned char>::operator*(unsigned char** rhs);

template matrix<int> matrix<int>::operator/(int** rhs);
template matrix<double> matrix<double>::operator/(double** rhs);
template matrix<float> matrix<float>::operator/(float** rhs);
template matrix<char> matrix<char>::operator/(char** rhs);
template matrix<unsigned int> matrix<unsigned int>::operator/(unsigned int** rhs);
template matrix<short int> matrix<short int>::operator/(short int** rhs);
template matrix<unsigned short int> matrix<unsigned short int>::operator/(unsigned short int** rhs);
template matrix<long int> matrix<long int>::operator/(long int** rhs);
template matrix<unsigned long int> matrix<unsigned long int>::operator/(unsigned long int** rhs);
template matrix<long long int> matrix<long long int>::operator/(long long int** rhs);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator/(unsigned long long int** rhs);
template matrix<signed char> matrix<signed char>::operator/(signed char** rhs);
template matrix<unsigned char> matrix<unsigned char>::operator/(unsigned char** rhs);

template matrix<int>& matrix<int>::operator+=(int** rhs);
template matrix<double>& matrix<double>::operator+=(double** rhs);
template matrix<float>& matrix<float>::operator+=(float** rhs);
template matrix<char>& matrix<char>::operator+=(char** rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator+=(unsigned int** rhs);
template matrix<short int>& matrix<short int>::operator+=(short int** rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator+=(unsigned short int** rhs);
template matrix<long int>& matrix<long int>::operator+=(long int** rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator+=(unsigned long int** rhs);
template matrix<long long int>& matrix<long long int>::operator+=(long long int** rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator+=(unsigned long long int** rhs);
template matrix<signed char>& matrix<signed char>::operator+=(signed char** rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator+=(unsigned char** rhs);

template matrix<int>& matrix<int>::operator-=(int** rhs);
template matrix<double>& matrix<double>::operator-=(double** rhs);
template matrix<float>& matrix<float>::operator-=(float** rhs);
template matrix<char>& matrix<char>::operator-=(char** rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator-=(unsigned int** rhs);
template matrix<short int>& matrix<short int>::operator-=(short int** rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator-=(unsigned short int** rhs);
template matrix<long int>& matrix<long int>::operator-=(long int** rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator-=(unsigned long int** rhs);
template matrix<long long int>& matrix<long long int>::operator-=(long long int** rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator-=(unsigned long long int** rhs);
template matrix<signed char>& matrix<signed char>::operator-=(signed char** rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator-=(unsigned char** rhs);

template matrix<int>& matrix<int>::operator*=(int** rhs);
template matrix<double>& matrix<double>::operator*=(double** rhs);
template matrix<float>& matrix<float>::operator*=(float** rhs);
template matrix<char>& matrix<char>::operator*=(char** rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator*=(unsigned int** rhs);
template matrix<short int>& matrix<short int>::operator*=(short int** rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator*=(unsigned short int** rhs);
template matrix<long int>& matrix<long int>::operator*=(long int** rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator*=(unsigned long int** rhs);
template matrix<long long int>& matrix<long long int>::operator*=(long long int** rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator*=(unsigned long long int** rhs);
template matrix<signed char>& matrix<signed char>::operator*=(signed char** rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator*=(unsigned char** rhs);

template matrix<int>& matrix<int>::operator/=(int** rhs);
template matrix<double>& matrix<double>::operator/=(double** rhs);
template matrix<float>& matrix<float>::operator/=(float** rhs);
template matrix<char>& matrix<char>::operator/=(char** rhs);
template matrix<unsigned int>& matrix<unsigned int>::operator/=(unsigned int** rhs);
template matrix<short int>& matrix<short int>::operator/=(short int** rhs);
template matrix<unsigned short int>& matrix<unsigned short int>::operator/=(unsigned short int** rhs);
template matrix<long int>& matrix<long int>::operator/=(long int** rhs);
template matrix<unsigned long int>& matrix<unsigned long int>::operator/=(unsigned long int** rhs);
template matrix<long long int>& matrix<long long int>::operator/=(long long int** rhs);
template matrix<unsigned long long int>& matrix<unsigned long long int>::operator/=(unsigned long long int** rhs);
template matrix<signed char>& matrix<signed char>::operator/=(signed char** rhs);
template matrix<unsigned char>& matrix<unsigned char>::operator/=(unsigned char** rhs);

template matrix<int> matrix<int>::operator*(array<int> arr);
template matrix<double> matrix<double>::operator*(array<double> arr);
template matrix<float> matrix<float>::operator*(array<float> arr);
template matrix<char> matrix<char>::operator*(array<char> arr);
template matrix<unsigned int> matrix<unsigned int>::operator*(array<unsigned int> arr);
template matrix<short int> matrix<short int>::operator*(array<short int> arr);
template matrix<unsigned short int> matrix<unsigned short int>::operator*(array<unsigned short int> arr);
template matrix<long int> matrix<long int>::operator*(array<long int> arr);
template matrix<unsigned long int> matrix<unsigned long int>::operator*(array<unsigned long int> arr);
template matrix<long long int> matrix<long long int>::operator*(array<long long int> arr);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator*(array<unsigned long long int> arr);
template matrix<signed char> matrix<signed char>::operator*(array<signed char> arr);
template matrix<unsigned char> matrix<unsigned char>::operator*(array<unsigned char> arr);

template matrix<int> matrix<int>::operator*=(array<int> arr);
template matrix<double> matrix<double>::operator*=(array<double> arr);
template matrix<float> matrix<float>::operator*=(array<float> arr);
template matrix<char> matrix<char>::operator*=(array<char> arr);
template matrix<unsigned int> matrix<unsigned int>::operator*=(array<unsigned int> arr);
template matrix<short int> matrix<short int>::operator*=(array<short int> arr);
template matrix<unsigned short int> matrix<unsigned short int>::operator*=(array<unsigned short int> arr);
template matrix<long int> matrix<long int>::operator*=(array<long int> arr);
template matrix<unsigned long int> matrix<unsigned long int>::operator*=(array<unsigned long int> arr);
template matrix<long long int> matrix<long long int>::operator*=(array<long long int> arr);
template matrix<unsigned long long int> matrix<unsigned long long int>::operator*=(array<unsigned long long int> arr);
template matrix<signed char> matrix<signed char>::operator*=(array<signed char> arr);
template matrix<unsigned char> matrix<unsigned char>::operator*=(array<unsigned char> arr);
