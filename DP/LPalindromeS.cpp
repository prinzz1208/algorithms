#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#define N 25
using namespace std;
int lookup[N][N];

int LPS(string X,int m,int n)
{
	
	if(m > n)
		return 0;
	if(m == n)
		return 1;
	
	if(X[m] == X[n])
		return LPS(X,m + 1,n - 1) + 2;
	
	return max(LPS(X,m + 1,n),LPS(X,m,n - 1));
}

//USING DP
int LPS(string X,int m,int n,auto &lookup)
{
	if(m > n)
		return 0;
	if(m == n)
		return 1;
	
	string key = to_string(m) + "|" + to_string(n);
	if(lookup.find(key) == lookup.end())
	{
		if(X[m] == X[n])
			lookup[key] = LPS(X,m + 1,n - 1) + 2;
		else
			lookup[key] = max(LPS(X,m + 1,n,lookup),LPS(X,m,n - 1,lookup));
	}
	return lookup[key];
}
//USING DP

//USING table
string LPS(string X,string Y,int m,int n)
{
	if(m == 0 || n == 0)
		return string("");
	if(X[m - 1] == Y[n - 1])
		return LPS(X,Y,m - 1,n -1) + X[m-1];
	
	if(lookup[m-1][n] > lookup[m][n-1])
		return LPS(X,Y,m - 1,n);

	return LPS(X,Y,m,n - 1);	
}
int LCS(string X,string Y,int n)
{
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <= n; j++)
		{
			if(X[i-1] == Y[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			
			else
				lookup[i][j] = max(lookup[i][j-1],lookup[i-1][j]);
		}
	
	return lookup[n][n];
}
//USING table
int main()
{
	string X = "ABBDCACB";
	string Y = X;
	reverse(Y.begin(),Y.end());
	int n = X.length();
	//unordered_map<string,int> lookup;
	//cout<<LCS(X,Y,n)<<endl;
	//cout<<LPS(X,Y,n,n);
	//cout<<LPS(X,0,n,lookup);
	
}
