#include <iostream>
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int LIS(int arr[], int i,int n,int prev)
{
	if(i == n)
		return 0;
		
	int exc = LIS(arr,i + 1,n,prev);
	
	int incl = 0;
	if(arr[i] > prev)
		incl = 1 + LIS(arr,i + 1,n,arr[i]);
	
	return max(exc,incl);
}

//USING DP
int LIS(int arr[],int i,int n,int prev,auto &lookup)
{
	if(i == n)
		return 0;
	
	
	string key1 = "exc";
	key1.append("|" + to_string(i));
	string key2 = "inc";
	key2.append("|" + to_string(i));

	
	int exc = 0;
	if(lookup.find(key1) == lookup.end())
		lookup[key1] = LIS(arr,i + 1,n,prev);

	exc = lookup[key1];
	
	int incl = 0;
	if(lookup.find(key2) == lookup.end() && arr[i] > prev)
		lookup[key2] = 1 + LIS(arr,i + 1,n,arr[i]);
	
	incl = lookup[key2];
	return max(exc,incl);
}
//USING DP

int LIS(int arr[],int n)
{
	int L[n] = { 0 };
	L[0] = 1;
	
for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if( arr[i] > arr[j] && L[j] > L[i])
				L[i] = L[j];
		}
		L[i]++;
	}
	
	int j = INT_MIN;
	for( int x: L)
		j = max(j,x);
	
	return j;
		
}

//to print all LIS
void LIS2(int arr[],int n)
{
	vector<int> L[n];
	L[0].push_back(arr[0]);
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if( arr[i] > arr[j] && L[j].size() > L[i].size())
				L[i] = L[j];
		}
		L[i].push_back(arr[i]);
	}
	
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if(L[j].size() < L[i].size())
			j = i;
	}
	
	for(int x : L[j])
		cout<<x<<" ";
		
}
//to print all LIS

int main()
{
	
	unordered_map<string,int> lookup;
	int ar[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
	int n = sizeof(ar)/sizeof(ar[0]);
	//cout<<LIS(ar,0,n,INT_MIN,lookup);
	//cout<<LIS(ar,sizeof(ar)/sizeof(ar[0]));
	LIS2(ar,n);

}
