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
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define FORD(index,a,n) for (ll index = a; index >= n; index--)
#define NL cout<<"\n"
#define TAB '\t'

int main()
{
	sync;
	int n; cin >> n;
	int a[n],ans[n] = {0};
	FOR(i,0,n){
		cin >> a[i];
	}
	FOR(i,0,n-1){
		if( a[i] > a[i+1] ){
			//test("ans[i]:",ans[i]); NL;
			if ( ans[i+1] == 0 )
				ans[i+1]++;
			if(ans[i] <= ans[i+1])
				ans[i] = ans[i+1] + 1;
		}
		else if( a[i] < a[i+1] ){
			//test("ans[i+1]:",ans[i+1]); NL;
			if ( ans[i] == 0 )
				ans[i]++;
			if(ans[i+1] <= ans[i])
				ans[i+1] = ans[i] + 1;
		}else{
			if ( ans[i+1] == 0 )
				ans[i+1]++;
			if ( ans[i] == 0 )
				ans[i]++;
		}
	}
	FEI(el,ans){
		print(el)<<TAB;
	}
	NL;
	print(accumulate(ans,ans+n,0));
	

}
