#include <bits/stdc++.h>

#define TAB '\t'
#define pb push_back
#define vi vector<int>
#define FEI(el,s) for(int el : s)
#define FEC(el,s) for(char el : s)
#define FES(el,s) for(string el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define NL cout<<endl
#define TEST(string) cout<<string
#define ll long long int

using namespace std;

int main()
{
	
	int total = 0, valleyCount = 0;
	
	int n = 0;
	bool first = true;
	cin >> n;
	string str;
	cin >> str;

	FE<string>(In , str){
	
		if(In == 'U' && (total + 1) == 0) valleyCount++;
		(In == 'U') ? total++ : total--;

	}
	TEST("VALLEY COUNT:")<<valleyCount;
}
