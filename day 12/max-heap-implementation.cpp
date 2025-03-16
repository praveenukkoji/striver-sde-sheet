// https://www.naukri.com/code360/problems/build-heap_975375

#include <bits/stdc++.h> 
int getParent(int i) {
	return (i-1)/2;
}
int getLeft(int i) {
	return 2*i+1;
}
int getRight(int i) {
	return 2*i+2;
}
void heapify(vector<int>& heap, int size, int ind) {
	int leftInd = getLeft(ind);
	int rightInd = getRight(ind);

	int largestInd = ind;

	if(leftInd < size && heap[leftInd] > heap[largestInd])
		largestInd = leftInd;
	
	if(rightInd < size && heap[rightInd] > heap[largestInd])
		largestInd = rightInd;
	
	if(largestInd != ind) {
		swap(heap[ind], heap[largestInd]);
		heapify(heap, size, largestInd);
	}
}
void insert(vector<int>& heap, int& size, int val) {
	heap[size] = val;
	int i = size;
	size++;

	while(i > 0 && heap[i] > heap[getParent(i)]) {
		swap(heap[i], heap[getParent(i)]);
		i = getParent(i);
	}

	heapify(heap, size, size-1);
}
void remove(vector<int>& heap, int& size) {
	if(size == 0) return;

	int root = heap[0];
	heap[0] = heap[size-1];
	size--;

	heapify(heap, size, 0);
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	// Write your code here 
	vector<int> heap(n);
	int size = 0;
	for(int i=0;i<n;i++) {
		insert(heap, size, arr[i]);
	}

	return heap;
}