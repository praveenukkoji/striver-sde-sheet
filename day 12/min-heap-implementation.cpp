// level - medium
// https://www.naukri.com/code360/problems/min-heap_4691801

#include <bits/stdc++.h>

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return (2*i)+1;
}

int right(int i) {
    return (2*i)+2;
}

void heapify(vector<int>& heap, int i, int size) {
    int l = left(i);
    int r = right(i);

    int smallest = i;

    if(l < size && heap[l] < heap[smallest]) {
        smallest = l;
    }

    if(r < size && heap[r] < heap[smallest]) {
        smallest = r;
    }

    if(smallest == i) {
        return;
    }
    else {
        swap(heap[smallest], heap[i]);
        heapify(heap, smallest, size);
    }
}

void insert(vector<int>& heap, int& size, int val) {
    heap[size] = val;
    int i = size;
    size++;

    while(i > 0 && heap[i] < heap[parent(i)]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int remove(vector<int>& heap, int& size) {
    if(size == 1) {
        size--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify(heap, 0, size);
    return root;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    int size = 0;
    vector<int> heap(n), ans;

    for(int i=0;i<n;i++) {
        if(q[i][0] == 0) {
            insert(heap, size, q[i][1]);
        }
        else {
            ans.push_back(remove(heap, size));
        }
    }

    return ans;
}
