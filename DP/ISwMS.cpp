//Increasing Subsequence with maximum sum
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int ISMS(int arr[], int i,int n,int prev,int sum)
{
	if(i == n)
		return sum;
	
	int incl = sum;
	if(arr[i] > prev )
		 incl = ISMS(arr,i + 1,n,arr[i],sum + arr[i]);
	
	return max(ISMS(arr,i + 1,n,prev,sum),incl);
}
// Iterative function to print increasing subsequence with the maximum sum
void printMSIS(int arr[], int n)
{
	// MSIS[i] stores the increasing subsequence having maximum sum
	// that ends with arr[i]
	vector<int> MSIS[n];
	MSIS[0].push_back(arr[0]);

	// sum[i] stores the maximum sum of the increasing subsequence
	// that ends with arr[i]
	int sum[n] = { 0 };
	sum[0] = arr[0];

	// start from second element in the array
	for (int i = 1; i < n; i++)
	{
		// do for each element in subarray arr[0..i-1]
		for (int j = 0; j < i; j++)
		{
			// find increasing subsequence with maximum sum that ends with
			// arr[j] where arr[j] is less than the current element arr[i]

			if (sum[i] < sum[j] && arr[i] > arr[j])
			{
				MSIS[i] = MSIS[j];		// update increasing subsequence
				sum[i] = sum[j];		// update maximum sum
			}
		}

		// include current element in increasing subsequence
		MSIS[i].push_back(arr[i]);

		// add current element to maximum sum
		sum[i] += arr[i];
	}

	// uncomment below lines to print contents of vector MSIS
	/* for (int i = 0; i < n; i++)
	{
		cout << "MSIS[" << i << "] - ";
		for (int j : MSIS[i])
			cout << j << " ";
		cout << endl;
	} */

	// j will contain index of MSIS
	int j = 0;
	for (int i = 1; i < n; i++)
		if (sum[i] > sum[j])
			j = i;

	// print MSIS
	for (int i : MSIS[j])
		cout << i << " ";
}

int main()
{
	int ar[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11};
	int n = sizeof(ar)/sizeof(ar[0]);
	cout<<ISMS(ar,0,n,INT_MIN,0);
}
