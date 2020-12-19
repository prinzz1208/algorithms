#include <iostream>
#include <climits>
#include <string>
#include <list>
#include <vector>
using namespace std;

int LBS(int arr[],int n)
{
	int I[n] = { 0 };
	int D[n] = { 0 };
	I[0] = 1;
	D[0] = 1;
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if( arr[i] > arr[j] && I[j] > I[i])
				I[i] = I[j];
		}
		I[i]++;
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if( arr[i] < arr[j] && D[j] > D[i])
				D[i] = D[j];
		}
		D[i]++;
	}
	
	int p = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int temp = D[i] + I[i] + 1;
		if(temp > p )
			p = temp;
	}
	
	return p;
		
}

//to print all LBS
void LBS2(int arr[],int n)
{
	list<int> I[n+1];
	list<int> D[n+1];
	I[0].push_back(arr[0]);
	D[n].push_front(arr[n]);
	
	for (int i = 1; i <=n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if( arr[i] > arr[j] && I[j].size() > I[i].size())
				I[i] = I[j];
		}
		I[i].push_back(arr[i]);
	}

	for (int i = n - 1 ; i >=0; i--)
	{
		for (int j = n; j > i; j--)
		{
			if( arr[i] > arr[j] && D[j].size() > D[i].size())
				D[i] = D[j];
		}
		D[i].push_front(arr[i]);
	}
	//for (int i = 0; i <= n; i++)
	//{
		//cout << "LIS[" << i << "] - ";
		//for (int j : I[i])
			//cout << j << " ";

		//cout << "\t\tLDS[" << i << "] - ";
		//for (int j : D[i])
			//cout << j << " ";
		//cout << endl;
	//} 
	int peak = 0;
	for (int i = 0; i < n; i++)
	{
		if ((I[i].size() + D[i].size()) > (I[peak].size() + D[peak].size()))
			peak = i;
	}
	
	for(int x : I[peak])
		cout<<x<<" ";

	D[peak].pop_front();
	
	for(int x : D[peak])
		cout<<x<<" ";
	
	
		
}
//to print all LBS

int main()
{
	
	int ar[] = {4,2,5,9,7,6,10,3,1};
	int n = sizeof(ar)/sizeof(ar[0]);
	//cout<<LIS(ar,0,n,INT_MIN,lookup);
	LBS2(ar,n);
	//LIS2(ar,n);

}

