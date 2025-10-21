#include<iostream>
using namespace std;
class Stack{
int *arr;

int capacity;

int top;

public:

Stack(int cap){
    capacity =cap;
    arr = new int [capacity];
    top = -1;
}


void push(int x)
{
    if(top == capacity-1)
    {
        cout<<"stack overfolw";
        return;
    }
    arr[++top]  = x;

}

int pop()
{
    if(top =-1)
    {
        cout<<"Stack underflow";
        return -1;
    }
    return arr[top--];
}

int peek()
{
     if(top =-1)
    {
        cout<<"Stack underflow";
        return -1;
    }

    return arr[top];

}

bool isEmplty(){
    return top == -1;

}

bool isFull()
{
    return top = capacity-1;
}

};
int main()
{

    Stack s;

    s.push(10);









    
}