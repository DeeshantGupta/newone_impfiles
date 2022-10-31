#include <bits/stdc++.h>
using namespace std;

// Function for printing the optimal
// parenthesization of a matrix chain product
void print(int i, int j, int n, int* bracket,
					char& name)
{
	// If only one matrix left in current segment
	if (i == j) {
		cout << name++;
		return;
	}

	cout << "(";

	// Recursively put brackets around subexpression
	// from i to bracket[i][j].
	// Note that "*((bracket+i*n)+j)" is similar to
	// bracket[i][j]
	print(i, *((bracket + i * n) + j), n,
					bracket, name);

	// Recursively put brackets around subexpression
	// from bracket[i][j] + 1 to j.
	print(*((bracket + i * n) + j) + 1, j, n,
					bracket, name);
	cout << ")";
}


void MCM(int p[], int n)
{
	/* For simplicity of the program, one extra
	row and one extra column are allocated in
		m[][]. 0th row and 0th column of m[][]
		are not used */
	int m[n][n];
	int bracket[n][n];

	/* m[i,j] = Minimum number of scalar multiplications
	needed to compute the matrix A[i]A[i+1]...A[j] =
	A[i..j] where dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (int i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j]
						+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;

					// Each entry bracket[i,j]=k shows
					// where to split the product arr
					// i,i+1....j for the minimum cost.
					bracket[i][j] = k;
				}
			}
		}
	}

	char name = 'A';

	cout << "\n Optimal Parenthesization is : ";
	print(1, n - 1, n, (int*)bracket, name);
	cout << "\n Optimal Cost is : " << m[1][n - 1];
}

// Driver code
int main()
{
    int n;
    cout<<"\n Size of array: ";
    cin>>n;
	int arr[100] ;
	cout<<"\n Enter the elements in an array ";
	for(int i=0; i<n; i++){
        cin>>arr[i];
	}
	MCM(arr, n);
	return 0;
}
