#include <bits/stdc++.h>
using namespace std;

#define TAB '\t'
#define pb push_back
#define vi vector<int>
#define print(a) cout << a
#define ll long long int

#define FEI(el,s) for(int el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define NL cout<<endl
#define TEST(string) cout<<string


int main()
{
	int T,N; cin >> T;
	while ( T-- ) {
		cin >> N;
		int arr[N+1], exar[N+1] = {0};
		arr[0] = -1;
		arr[1] = 0;

		FOR(i,2,N + 1){
			//TEST(exar[arr[i-1]]); NL;
			if ( exar[arr[i-1]] == 0 ) {
				arr[i] = 0;
			} 
			else {
				arr[i] = (i - 1 ) - exar[arr[i-1]];
			}
			exar[arr[i-1]] = i-1;
		}
		int count = 0;
		FOR(i,1,N+1) {
			if( arr[i] == arr[N] ) count++;
		}
		//FEI(el, arr){
			//print(el) << TAB;
		//}
		cout << count;
	}
}

