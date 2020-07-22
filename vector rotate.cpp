#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int ar[4][4] = {{8,7,3,4},
					{1,2,3,6},
					{5,1,8,9},
					{3,4,2,5}};
	
	int m = 4, n = 4;
	vector<int> v[m/2];
	int k = 0,l = 0;

	for (int a = 0,b = 0,p = m,q = n; a < p || b < q; a++,b++,p--,q--)
	{
		for (int j = b; j < q; j++)			//FISRT ROW
			v[a].push_back(ar[a][j]);
		
		
		for (int i = a+1; i < p; i++)		//LAST COLUMN
			v[a].push_back(ar[i][q-1]);
		
		for (int j = q-2; j >= b; j--)
			v[a].push_back(ar[p-1][j]);		//LAST ROW
		
		
		for (int i = p-2; i > a; i--)		//FIRST COLUMN
			v[a].push_back(ar[i][b]);
		k++;
	}

	int rot = 2;

    for (int i = 0; i < m/2; i++)
	{
		rotate(v[i].begin(), v[i].begin()+rot, v[i].end());
	}
	
	cout<<endl;
	
	
	cout<<endl;
	k = 0; l = 0;
	for (int a = 0,b = 0,p = m,q = n; a < p || b < q; a++,b++,p--,q--)
	{
		for (int j = b; j < q; j++,l++)			//FISRT ROW
			(ar[a][j]) = v[k][l];
		
		
		for (int i = a+1; i < p; i++,l++)		//LAST COLUMN
			(ar[i][q-1]) = v[k][l];
		
		for (int j = q-2; j >= b; j--,l++)		//LAST ROW
			(ar[p-1][j]) = v[k][l];		
		
		
		for (int i = p-2; i > a; i--,l++)		//FIRST COLUMN
			(ar[i][b]) = v[k][l];
		k++;
		l = 0;
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

