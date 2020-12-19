

#include <bits/stdc++.h>

#define pb push_back
#define vi vector<int>
#define print(string) cout<<string
#define ll long long int

#define FEI(el,s) for(int el : s)
#define FEC(el,s) for(char el : s)
#define FES(el,s) for(string el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)

#define TAB '\t'
#define NL cout<<'\n';

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s, s2;
	ll n, numOfAs = 0,count = 0;
	cin >> s; cin >> n;
	
	FEC(el, s) if(el == 'a') numOfAs++;
	
	count = (n / s.size()) * numOfAs;

	FOR(i,0,(n % (int)s.size())){
		if(s[i] == 'a')	count++;
	}

	print(count);
	
}
