
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll t, m, n;
ll k = 0;

int main()
{
	cin >> t;
	m = t; n = t;
	ll ar[m][n];
	for (ll i = 0; i < m; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			ll x = 0;
			cin >> x;
			
			ar[i][j] = x;
		}
		
	}
	
	
	
	vector<ll> v[m];

	for (ll a = 0,b = 0,p = m,q = n; a < p || b < q; a++,b++,p--,q--)
	{
		for (ll j = b; j < q; j++)			//FISRT ROW
			v[a].push_back(ar[a][j]);
		
		
		for (ll i = a+1; i < p; i++)		//LAST COLUMN
			v[a].push_back(ar[i][q-1]);
		
		for (ll j = q-2; j >= b; j--)
			v[a].push_back(ar[p-1][j]);		//LAST ROW
		
		
		for (ll i = p-2; i > a; i--)		//FIRST COLUMN
			v[a].push_back(ar[i][b]);
		k++;
	}

	for (ll i = 0; i < m; i++)
	{
		for(ll j : v[i])
			cout << j << " ";
		
	}
	
	
}

