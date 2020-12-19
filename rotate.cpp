	#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int num = 0,rot = 0 ;
	cin>>num;
	cin>>rot;
	cout<<endl;
	int arr[abs(rot)] = {0} ,j = 0,p = 9;
	for (int i = 0; i < abs(rot); i++)
		arr[i] = 0;
	
	
	if(rot > 0)
	{
		//LEFT ROTATE
		for (int i = pow(10,p); i != 1 && j < rot ;i = pow(10,--p))
		{
			if( (num / i) != 0 )
			{
				int temp = num / i;
				//cout<<"temp:"<<temp<<endl;
				arr[j++] = temp;
				num -= i*temp;
			}
		}
		
		num *= pow(10,rot);
		for (int i = rot-1,j = 0; j <rot ; i--,j++)
		{
			num+=arr[j]*pow(10,i);
		}
		cout<<num;
		//LEFT ROTATE
	}
	else
	{
		rot = abs(rot);
		while( j < rot)
		{
			int temp = num%(int(pow(10,j + 1)));
			arr[j] = temp;
			//cout<<"\nj:"<<j;
			//cout<<"\narr[j]:"<<arr[j];
			
			j++;
			num -= temp;
		}
		
		num /= pow(10,abs(rot));
		//cout<<"\nnum:"<<num;
		while( int(num/(pow(10,--p))) == 0);
		
		
		
		//cout<<"\np:"<<p<<endl;

		//ERROR
		//cout<<"\narr:"<<arr[0];
		//ERROR

		for (int i = p+1,j = 0; j < (rot); j++,i-=2)
		{
			//cout<<"num:"<<num;
			
			num += arr[j] * pow(10,i+1);
			//cout<<arr[j] * pow(10,i)<<endl;
			//cout<<arr[j];
		}
		cout<<num;
	}
}
