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

