#include <bits/stdc++.h>

#define TAB '\t'
#define pb push_back
#define vi vector<int>
#define FEI(el,s) for(int el : s)
#define FEC(el,s) for(char el : s)
#define FES(el,s) for(string el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define NL cout<<'\n';
#define TEST(string) cout<<string
#define ll long long int

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int b, n, m, in;
	cin >> b; cin >> n; cin >> m; 
	
	vi kb; vi usb;
	FOR(i,0,n) {
		cin >> in;
		kb.pb(in);
	}
	
	FOR(i,0,m) {
		cin >> in;
		usb.pb(in);
	}
	sort(kb.begin(), kb.end(), greater<int>());
	sort(usb.begin(), usb.end(), greater<int>());
	
	int max = 0;
	FEI(el1 , kb){
		FEI(el2, usb){
			int tot = el1 + el2;
			if(tot <= b && tot > max){
				max = tot;
			}				
		}
	}
	max == 0 ? TEST(-1) : TEST(max);
	
}
