#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {34,89,23,77,45};
	vector<int> vi(arr,arr+5);
	return 0;	
}