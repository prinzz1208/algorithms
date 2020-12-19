#include <bits/stdc++.h>

#define TAB '\t'
#define pb push_back
#define vi vector<int>
#define FEI(el,s) for(int el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define NL cout<<endl
#define TEST(string) cout<<string
#define ll long long int

using namespace std;

int gcd( int a, int b)
{
	 if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

ll lcm( vi arr)
{
	int ans = arr[0];
	FOR(i,1,(int)arr.size()) {
		ans = ( arr[i] * ans ) / (gcd(arr[i], ans));
	}
	return ans;
}

vi numbers;
int getTotalX(vector<int> a, vector<int> b) 
{
	int m = *max_element(a.begin(), a.end());
	int min2 = *min_element(b.begin(), b.end());
	ll LCM = lcm(a);
	for (int i = LCM; i <= min2; i += m)
	{
		bool temp = true;
		FEI(el , b) {
			if(el % i != 0 ) {
				temp = false;
				break;
			}
		}
		if (temp) numbers.pb(i);
	}
	
	FEI(el , numbers) {
		cout<<el<<TAB;
	}
}

int main() 
{
	getTotalX(vi{2,6}, vi{24,36});
}
