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
	ll arr[] = {0,2,3,1,1,7,7,4,7};
	ll n = 9, count = 0,mj_num = arr[0];
	
	FOR(i,0,n){
		if(arr[i] == mj_num) 
			count++;
			
		else{
			if ( --count == 0 )
				mj_num = arr[i];
			count++;
		}
	}
	//cout << count;
	NL;
	count = 0;
	FOR(i,0,n) {
		if(arr[i] == mj_num) count++;
	}
	count > n / 2 ? print("There is a majority number ") : print("No majority number");
	//cout << count;
}
