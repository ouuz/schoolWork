#include <iostream>
#define N 10
using namespace std;

int main()
{
	int *Arr, i ,positive=0, negative=0;
	Arr = new int[N];

	cout<<"please input 10 int numbers:"<<"\n"<<endl;
	for(i = 0 ;i <N;i++)
	{
		cin >>Arr [i];
		if(Arr[i] > 0)
		positive ++;
		else if(Arr[i]< 0 )
		negative ++;
	}
	cout<<"positive="<<positive<<";"<<"negative="<<negative<<endl;
	return 0;
}
