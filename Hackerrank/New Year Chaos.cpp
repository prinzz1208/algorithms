#include <bits/stdc++.h>

#define pb push_back
#define print(s) cout<<s
#define nl cout<<'\n';
#define tab '\t'
#define ll long long int
#define vi vector<int>
#define vl vector<ll>

#define FOR(i,a,n) for (int i = (a); i < n; i++)
#define FEL(el,s) for (ll el : s)
#define FEI(el,s) for (int el : s)
#define FES(el,s) for (string el : s)
#define FEC(el,s) for (char el : s)


using namespace std;

int bubsort(vi a,int n) {
	int ct = 0;
   
   
    FOR(i , 0 , n ){
		

        bool swap = false;
            
        FOR(j , 0, n - 1 - i) {			
			//print("a[j] ")<<a[j]<<tab;
			//print("a[j+1] ")<<a[j+1]<<tab;
			//nl
			if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
				ct++;
				swap = true;
				//print("count:")<<ct;

            }
        }
    
        
		
        if (swap == false) 
        {
			break;
		}
    }
    return(ct);
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int testCases; cin >> testCases;
    ll n = 0;
    
    FOR(i,0,testCases) {
        cin >> n;
        bool chaotic = false;
        vi a(n);
        
        FOR(j,0,n){ 
            cin>>a[j];
			if(!chaotic){
				if( a[j] - (j+1) >= 3) chaotic = true;
			}
        }
        
        //if(chaotic) cout<<("Too chaotic") ;
		if(chaotic) print("Too chaotic");
		else print(bubsort(a,n));
        nl;
        //nl

    }
    
}
