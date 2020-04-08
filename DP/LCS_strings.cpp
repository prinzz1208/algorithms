#include <iostream>
#include <string>
#include <vector>
#include <set>
#define MAX 20
using namespace std;

int lookup[MAX][MAX];

vector<string> LCS(string X,string Y,int m,int n)
{
	if((m == 0) || (n == 0))
	{
		vector<string> v(1);
		return v;
	}
	if( X[m-1] == Y[n-1])
	{
		vector<string> lcs = LCS(X,Y,m - 1,n - 1);
		for (string &str : lcs)
		{
			str.push_back(X[m-1]);
		} 
		return lcs;
	}
	
	if(lookup[m - 1][n] > lookup[m][n - 1])
		return LCS(X,Y,m - 1,n);
	
	if(lookup[m][n - 1] > lookup[m - 1][n])
		return LCS(X,Y,m,n - 1);
	
	vector<string> top = LCS(X,Y,m,n - 1);
	vector<string> left = LCS(X,Y,m - 1,n);
	
	top.insert(top.end(),left.begin(),left.end());
	
	
	return top;

}
//USING TABLE
int LCS_table(string X, string Y, int m , int n)
{

	// lookup table stores solution to already computed sub-problems
	// i.e. lookup[i][j] stores the length of LCS of substring
	// X[0..i-1] and Y[0..j-1]

	// first column of the lookup table will be all 0
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;

	// first row of the lookup table will be all 0
	for (int j = 0; j <= n; j++)
		lookup[0][j] = 0;

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
		int LCS_table(string X, string Y, int m , int n)
{

	// lookup table stores solution to already computed sub-problems
	// i.e. lookup[i][j] stores the length of LCS of substring
	// X[0..i-1] and Y[0..j-1]

	// first column of the lookup table will be all 0
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;

	// first row of the lookup table will be all 0
	for (int j = 0; j <= n; j++)
		lookup[0][j] = 0;

	// fill the lookup table in bottom-up manner
	for (	// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			// else if current character of X and Y don't match
			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}

	// LCS will be last entry in the lookup table
	return lookup[m][n];
}

set<string> LCS(string X,string Y)
{
	int m = X.length(), n = Y.length();
	
	//fill the lookup table
	LCS_table(X,Y,m,n);
	
	vector<string> v = LCS(X,Y,m,n);
	
	//set<string> s(make_move_iterator(v.begin()),make_move_iterator(v.end()));
	set<string> s(v.begin(),v.end());
	return s;
}
//USING TABLE
int main()
{
	string X = "ABCBDAB";
	string Y = "BDCABA";
	set<string> lcs = LCS(X,Y);
	for( string str : lcs)
	{
		cout<<str<<endl;
	}

}

