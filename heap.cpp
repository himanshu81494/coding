#include <iostream>
#include <cstring>
using namespace std;

class heap
{
	int *arr;
	int max_size;
	int len;
public:
	heap(int n):max_size(n)
	{
		len=0;
		arr = new int[n];
		memset(arr,0,sizeof(int)*max_size);
	}
	~heap()
	{
		delete [] arr;
	}
	friend printArr(heap &obj)
	{
		for (int i = 0; i < obj.len; ++i)
			cout<<obj.arr[i]<<" ";
	}
};

int main(int argc, char const *argv[])
{
	heap myHeap(10);
	printArr(myHeap);
	return 0;
}