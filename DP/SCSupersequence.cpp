#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define MAX 25
int lookup[MAX][MAX];
using namespace std;
int SCS(string X,string Y,int m,int n)
{
	if( m == 0 || n == 0)
		return m+n;
		
	if(X[m-1] == Y[n-1])
		return SCS(X,Y,m - 1,n - 1)+1;
	
	return min(SCS(X,Y,m - 1,n) + 1,SCS(X,Y,m,n - 1) + 1);
}
//USING DP
int SCS(string X,string Y,int m,int n,auto &lookup)
{
	if( m == 0 || n == 0)
		return m+n;
		
	string key = to_string(m) + "|" + to_string(n);
	if(lookup.find(key) == lookup.end())
	{
	
		if(X[m-1] == Y[n-1])
			lookup[key] = SCS(X,Y,m - 1,n - 1)+1;
		
		else
			lookup[key] = min(SCS(X,Y,m - 1,n) + 1,SCS(X,Y,m,n - 1) + 1);	
	} 
	return lookup[key];
}
//USING DP
//SCS strings
string SCS_string(string X,string Y,int m,int n)
{
	if( m == 0)
		return Y.substr(0,n);
	else if( n == 0)
		return X.substr(0,m);
	
	if( X[m-1] == Y[n-1])
		return SCS_string(X,Y,m - 1,n - 1) + X[m-1];
	
	if(lookup[m-1][n] < lookup[m][n-1])
		return SCS_string(X,Y,m - 1,n) + X[m-1];
	else
		return SCS_string(X,Y,m,n - 1) + Y[n-1];
}
vector<string> SCS_strings(string X, string Y, int m, int n)
{
	// if we have reached the end of first string, create a vector
	// containing second substring and return
	if (m == 0)
	{
		vector<string> v;
		v.push_back(Y.substr(0, n));
		return v;
	}

	// if we have reached the end of second string, create a vector
	// containing first substring and return
	else if (n == 0)
	{
		vector<string> v;
		v.push_back(X.substr(0, m));
		return v;
	}

	// if last character of X and Y is same, it should occur
	// only one time in SSC
	if (X[m - 1] == Y[n - 1])
	{
		// find all SCS of substring X[0..m-2], Y[0..n-2]
		vector<string> scs = SCS_strings(X, Y, m - 1, n - 1);

		// append current character X[m - 1] or Y[n - 1] to all SCS of
		// substring X[0..m-2] and Y[0..n-2]

		for (string &str : scs)		// don't remove &
			str.push_back(X[m - 1]);

		return scs;
	}

	// we reach here when the last character of X and Y don't match

	// if top cell of current cell has less value than the left cell,
	// then append current character of string X to all SCS of
	// substring X[0..m-2], Y[0..n-1]

	if (lookup[m - 1][n] < lookup[m][n - 1])
	{
		vector<string> scs = SCS_strings(X, Y, m - 1, n);

		for (string &str : scs)		// don't remove &
			str.push_back(X[m - 1]);

		return scs;
	}

	// if left cell of current cell has less value than the top cell,
	// then append current character of string Y to all SCS of
	// substring X[0..m-1], Y[0..n-2]

	if (lookup[m][n - 1] < lookup[m - 1][n])
	{
		vector<string> scs = SCS_strings(X, Y, m, n - 1);

		for (string &str : scs)		// don't remove &
			str.push_back(Y[n - 1]);

		return scs;
	}

	// if top cell value is same as left cell, then go in both
	// top and left directions

	// append current character of string X to all SCS of
	// substring X[0..m-2], Y[0..n-1]
	vector<string> top = SCS_strings(X, Y, m - 1, n);
	for (string &str : top)		// don't remove &
			str.push_back(X[m - 1]);

	// append current character of string Y to all SCS of
	// substring X[0..m-1], Y[0..n-2]
	vector<string> left = SCS_strings(X, Y, m, n - 1);
	for (string &str : left)		// don't remove &
		str.push_back(Y[n - 1]);

	// merge two vectors and return
	top.insert(top.end(), left.begin(), left.end());
	// copy(left.begin(), left.end(), back_inserter(top));

	return top;
}
int SCS(string X,string Y)
{
	int m = X.length(),n = Y.length();
	for (int i = 0; i <=m; i++)
		lookup[i][0] = i;
	for (int j = 0; j <=n; j++)
		lookup[0][j] = j;
	
	for (int i = 1; i <=m; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			
			if(X[i-1] == Y[j-1])vector<string> SCS(string X, string Y, int m, int n)
{
	// if we have reached the end of first string, create a vector
	// containing second substring and return
	if (m == 0)
	{
		vector<string> v;
		v.push_back(Y.substr(0, n));
		return v;
	}

	// if we have reached the end of second string, create a vector
	// containing first substring and return
	else if (n == 0)
	{
		vector<string> v;
		v.push_back(X.substr(0, m));
		return v;
	}

	// if last character of X and Y is same, it should occur
	// only one time in SSC
	if (X[m - 1] == Y[n - 1])
	{
		// find all SCS of substring X[0..m-2], Y[0..n-2]
		vector<string> scs = SCS(X, Y, m - 1, n - 1);

		// append current character X[m - 1] or Y[n - 1] to all SCS of
		// substring X[0..m-2] and Y[0..n-2]

		for (string &str : scs)		// don't remove &
			str.push_back(X[m - 1]);

		return scs;
	}

	// we reach here when the last character of X and Y don't match

	// if top cell of current cell has less value than the left cell,
	// then append current character of string X to all SCS of
	// substring X[0..m-2], Y[0..n-1]

	if (lookup[m - 1][n] < lookup[m][n - 1])
	{
		vector<string> scs = SCS(X, Y, m - 1, n);

		for (string &str : scs)		// don't remove &
			str.push_back(X[m - 1]);

		return scs;
	}

	// if left cell of current cell has less value than the top cell,
	// then append current character of string Y to all SCS of
	// substring X[0..m-1], Y[0..n-2]

	if (lookup[m][n - 1] < lookup[m - 1][n])
	{
		vector<string> scs = SCS(X, Y, m, n - 1);

		for (string &str : scs)		// don't remove &
			str.push_back(Y[n - 1]);

		return scs;
	}

	// if top cell value is same as left cell, then go in both
	// top and left directions

	// append current character of string X to all SCS of
	// substring X[0..m-2], Y[0..n-1]
	vector<string> top = SCS(X, Y, m - 1, n);
	for (string &str : top)		// don't remove &
			str.push_back(X[m - 1]);

	// append current character of string Y to all SCS of
	// substring X[0..m-1], Y[0..n-2]
	vector<string> left = SCS(X, Y, m, n - 1);
	for (string &str : left)		// don't remove &
		str.push_back(Y[n - 1]);

	// merge two vectors and return
	top.insert(top.end(), left.begin(), left.end());
	// copy(left.begin(), left.end(), back_inserter(top));

	return top;
}
				lookup[i][j] = lookup[i-1][j-1] + 1; 
			else
				lookup[i][j] = min(lookup[i-1][j] + 1,lookup[i][j-1] + 1);
		}
		
	}
	return lookup[m][n];
	
}
//SCS strings
int main()
{
	string X = "ABCBDAB";	
	string Y = "BDCABA";
	unordered_map<string,int> lookup;
	cout<<SCS(X,Y)<<endl;	
	auto v = SCS_strings(X,Y,X.length(),Y.length());
	for(string str:v)
		cout<<str<<endl;
}

