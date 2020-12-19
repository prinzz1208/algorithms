#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
//int arr[6][6]{
	//-9, -9, -9,  1, 1, 1,
	 //0, -9,  0,  4, 3, 2,
	//-9, -9, -9,  1, 2, 3,
	 //0,  0,  8,  6, 6, 0,
	 //0,  0,  0, -2, 0, 0,
	 //0,  0,  1,  2, 4, 0
//};

int arr[6][6];
FOR(i,0,6)
	FOR(j,0,6){
		cin>>arr[i][j];
	}
	
//FOR(i,0,6) {
	//FOR(j,0,6) {
		//print(arr[i][j]);
	//}
	//NL;
//}

vector<pair<int,int>> p
{
	mp(-1,-1),mp(-1,0),mp(-1,1),
			mp(0,0),
	mp(1,-1),mp(1,0),mp(1,1)
};
	
vi all;
FOR(i,1,5) {
	FOR(j,1,5) {
		int sum=0;
		for( pair<int,int> t: p){
			sum += arr[i - t.first][j - t.second];
		}
		all.pb(sum);
	}
}
//FEI(el , all) print(el)<<TAB;
cout<<*max_element(all.begin(),all.end());

}
