#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int LCSubstring(string X,string Y,int m , int n)
{
	if ( (m == 0) || (n == 0) )
		return 0;
	
	if ( X[m - 1] == Y[n - 1] )
		return LCSubstring(X,Y,m - 1,n - 1) + 1;
	
	else
		return LCSubstring(X,Y,m,n - 1);
}
//USING DP
int LCSubstring(string X,string Y,int m , int n,auto &lookup)
{
	if ( (m == 0) || (n == 0) )
		return 0;
		
	string key = to_string(m) + "," + to_string(n);
	if(lookup.find(key) == lookup.end())
	{
		if ( X[m - 1] == Y[n - 1] )
			lookup[key] =  LCSubstring(X,Y,m - 1,n - 1) + 1;
		
		else
			lookup[key] =  LCSubstring(X,Y,m,n - 1);
	}
	return lookup[key];
}
//USING DP

//FINDING STRING USING TABLE
string LCSubstring_table(string X,string Y)
{
	int m = X.length(), n = Y.length(),max = 0,endingIndex = m;
	int lookup[m+1][n+1];
	for (int i = 1; i <= m; i++)
		lookup[i][0] = 0;
	for (int j = 1; j <= m; j++)
		lookup[0][j] = 0;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(X[i-1] == Y[j-1])
			{
				lookup[i][j] = lookup[i-1][j-1] + 1;
				
				if(lookup[i][j] > max)
				{
					max = lookup[i][j];
					endingIndex = i;
				}
			}
			else
				lookup[i][j] = 0;
			
		}
		
	}
	return X.substr(endingIndex-max,max);
}
//USING TABLE

int main()
{
	unordered_map<string,int> lookup;
	string X = "ABABC";
	string Y = "BABCA";
	
	//cout<<LCSubstring(X,Y,X.length(),Y.length());
	//cout<<LCSubstring(X,Y,X.length(),Y.length(),lookup);
	cout<<LCSubstring_table(X,Y);
}
