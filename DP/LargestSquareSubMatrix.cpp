#include <iostream>
#define M 8
#define N 6
using namespace std;

 
int LSSM ( int mat[M][N],int m ,int n, int &max_size)
{
	if( m == 0 || n == 0)
	{
		max_size = max(max_size,mat[m][n]);
		return mat[m][n];
	}
	
	int left = LSSM(mat,m,n - 1,max_size);
	int top = LSSM(mat,m - 1,n,max_size);
	int top_left = LSSM(mat,m - 1,n - 1,max_size);
	
	int size = 0;
	if( mat[m][n] != 0)
	{
		size = 1 + min(min(top,left),top_left);
	}
	
	max_size = max(size,max_size);
	return size;
	
}

int LSSM_table(int mat[M][N])
{
	int lookup[M][N];
	
	int max = 0;
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			lookup[i][j] = mat[i][j];
			if( i && j && mat[i][j])
				lookup[i][j] = min(min(lookup[i][j-1],lookup[i-1][j]),lookup[i-1][j-1]) + 1;
			
			if(max < lookup[i][j])
				max = lookup[i][j];
		}
		
	}
	
	return max;
}
int main()
{
	int mat[M][N] =
	{
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};

	// size stores the size of largest square sub-matrix of 1's
	// and it is passed by reference
	int size = 0;

	//LSSM(mat, M-1, N-1, size);

	//cout << "The size of largest square sub-matrix of 1's is " << size;
	cout << "The size of largest square sub-matrix of 1's is " << LSSM_table(mat);

	return 0;
}
