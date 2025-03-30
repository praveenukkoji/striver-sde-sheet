// easy
// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

// tc :
// push : O(1)
// pop  : O(1)

//sc : O(n)

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    // Your Code
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top == -1) {
        return -1;
    }
    
    return arr[top--];
}