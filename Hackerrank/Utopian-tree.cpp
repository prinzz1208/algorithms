#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fop first
#define sop second
#define ll long long int
#define vi vector<ll>
#define vs vector<string>
#define print(a) cout << a

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test(string,a) cout<<string<<a

#define FEI(el,s) for(int el : s)
#define FOR(index,a,n) for (ll index = a; index < n; index++)
#define FORD(index,a,n) for (ll index = a; index >= n; index--)
#define NL cout<<"\n"
#define TAB '\t'

int utopianTree(int n) {
	int ans = 1;
	if (n == 0)
		return 1;
	else{
		
		FOR(i,1,n+1){
			if( (i-1)%2 == 0)
				ans *= 2;
			else
				ans++;
		}
	}
	return ans;
}

int main()
{
	sync;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		print(utopianTree(n));
		NL;
	}

}
