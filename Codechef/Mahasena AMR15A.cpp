#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define nl cout << endl
#define print(a) cout << a

#define FEI(el,s) for(ll el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define TAB '\t'
#define TEST(string,a) cout << string << a

bool even(ll n) {
	return (n % 2 == 0);
}

int main()
{
	int N; cin >> N;
	ll arr[N], lucky = 0, unlucky = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		even(arr[i]) ? lucky++ : unlucky++  ;
	}
	( lucky > unlucky) ? print("READY FOR BATTLE") : print("NOT READY");
	
	
	
}
