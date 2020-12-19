#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//WITHOUT USING DP
int LCS(string X,string Y,int m,int n)
{
	if( m == 0 || n == 0)
		return 0;
	
	if( X[m-1] == Y[n-1] )
		return LCS(X,Y,m-1,n-1) + 1;

	return max(LCS(X,Y,m,n-1),LCS(X,Y,m-1,n));

}
//WITHOUT USING DP

//USING DP
int LCS_dp(string X,string Y,int m,int n,auto &lookup)
{
	if( m == 0 || n == 0)
		return 0;
	
	string key = to_string(m) + "," + to_string(n);
	if(lookup.find(key) == lookup.end())
	{
		if( X[m-1] == Y[n-1] )
		{
			lookup[key] = LCS_dp(X,Y,m-1,n-1,lookup) + 1; 
		}
		else
			lookup[key] = max(LCS_dp(X,Y,m,n-1,lookup),LCS_dp(X,Y,m-1,n,lookup));
	}
	return lookup[key];

}
//USING DP

//USING TABLE
int LCS_table(string X, string Y)
{
	int m = X.length(), n = Y.length();

	// lookup table stores solution to already computed sub-problems
	// i.e. lookup[i][j] stores the length of LCS of substring
	// X[0..i-1] and Y[0..j-1]
	int lookup[m + 1][n + 1];

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
			// if current character of X and Y matches
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
//USING TABLE
int main()
{
	unordered_map<string,int> lookup;	
	string X = "ABCBDAB";
	string Y = "BDCABA";
	cout<<LCS_dp(X,Y,X.length(),Y.length(),lookup);

}
