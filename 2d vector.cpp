#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> vect{ { 1, 2, 3 }, 
                               { 4, 5, 6 }, 
                               { 7, 8, 9 } }; 
                          
    auto v = vect[0];
    reverse(v.begin(),v.end());
    int k = 2;
    rotate(vect[0].begin(), vect[0].begin()+k, vect[0].end());

	//int firsRow = 0;
	int m = 3, n = 3;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; i++)
		{
			
		}
		
	}
	
	
	
}
