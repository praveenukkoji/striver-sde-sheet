// level - medium
// https://www.naukri.com/code360/problems/sort-a-stack_985275

// tc : O(n * logn)
// sc : O(n)

#include <bits/stdc++.h> 
void sortStack(stack<int> &st)
{
	// Write your code here
	vector<int> elements;
	while(!st.empty()) {
		elements.push_back(st.top());
		st.pop();
	}

	sort(elements.begin(), elements.end());
	for(int& ele: elements) {
		st.push(ele);
	}
}

// tc : O(n^2)
// sc : O(n) recursion space

#include <bits/stdc++.h> 
void insertAtCorrectPosition(stack<int>& s, int t){
	if(s.empty() || t > s.top()) {
		s.push(t);
		return;
	}

	int ele = s.top();
	s.pop();

	insertAtCorrectPosition(s, t);

	s.push(ele);
}

void sort(stack<int>& s) {
	if(s.empty()) return;

	int temp = s.top();
	s.pop();

	sort(s);

	insertAtCorrectPosition(s, temp);
}


void sortStack(stack<int> &stack)
{
	// Write your code here
	sort(stack);
}