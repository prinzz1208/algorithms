#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#define N 25
using namespace std;
int lookup[N][N];

int LRS(string X,int m,int n)
{
	
	if(m == 0 || n == 0)
		return 0;

	
	if(X[m-1] == X[n-1] && m != n)
		return LRS(X,m - 1,n - 1) + 1;
	
	return max(LRS(X,m - 1,n),LRS(X,m,n - 1));
}

//USING DP
int LRS(string X,int m,int n,auto &lookup)
{
	
	if(m == 0 || n == 0)
		return 0;

	
	string key = to_string(m) + "|" + to_string(n);
	if(lookup.find(key) == lookup.end())
	{
		if(X[m-1] == X[n-1] && m != n)
			lookup[key] = LRS(X,m - 1,n - 1,lookup) + 1;
		else
			lookup[key] = max(LRS(X,m - 1,n,lookup),LRS(X,m,n - 1,lookup));
	}
	return lookup[key];
}
//USING DP

//USING table
string LRS(string X,string Y,int m,int n)
{
	if(m == 0 || n == 0)
		return string("");
	if(X[m - 1] == Y[n - 1] && m != n)
		return LRS(X,Y,m - 1,n -1) + X[m-1];
	
	if(lookup[m-1][n] > lookup[m][n-1])
		return LRS(X,Y,m - 1,n);

	return LRS(X,Y,m,n - 1);	
}
int LRS(string X,string Y,int n)
{
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <= n; j++)
		{
			if(X[i-1] == Y[j-1] && i!=j)
				lookup[i][j] = lookup[i-1][j-1] + 1;
			
			else
				lookup[i][j] = max(lookup[i][j-1],lookup[i-1][j]);
		}
	
	return lookup[n][n];
}
//USING table
int main()
{
	string X = "ATACTCGGA";
	string Y = X;
	//reverse(Y.begin(),Y.end());
	int n = X.length();
	unordered_map<string,int> lookup;
	cout<<LRS(X,Y,n)<<endl;
	cout<<LRS(X,Y,n,n);
	//cout<<LRS(X,n,n,lookup);
	
}

