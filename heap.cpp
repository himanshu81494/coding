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
	int leftChild(int i)
	{
		return 2*i + 1;
	}
	int rightChild(int i)
	{
		return 2*i + 2;
	}
	void heapify(int i)
	{
		int l = leftChild(i);
		int r = rightChild(i);
		int largest = i;
		if(l<len && arr[l]>arr[largest])
			largest=l;
		if(r<len && arr[r]>arr[largest])
			largest=r;
		if(largest!=i)
		{
			swap(arr[i],arr[largest]);
			heapify(largest);
		}
	}
	void buildHeap()
	{
		for (int i = len/2-1; i>=0 ;--i)
			heapify(i);
	}
	bool insert(int a)
	{
		if(len==max_size)
			return false;
		arr[len++]=a;
		return true;
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
	myHeap.insert(7);
	myHeap.insert(18);
	myHeap.insert(11);
	myHeap.insert(5);
	myHeap.insert(34);
	myHeap.insert(4);
	printArr(myHeap);
	myHeap.buildHeap();
	printArr(myHeap);
	return 0;
}