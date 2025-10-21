//Implement Queue using Two Stacks

#include<iostream>
#include<stack>
using namespace std;
class myQueue{
stack<int> s1,s2;
public:

void enqueue(int x)
{
    s1.push(x);
}

void dequeue()
{
    if(s1.empty() && s2.empty())
    {
        return;
    }

    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}

int front()
{
    if(!s2.empty()){return s2.top();}

    if(!s1.empty()){
        while(!s1.empty())
        {
            s2.push(s1.top());

            s1.pop();
        }
        int x =s2.top();
        return x;
    }
    return -1;

}
int size()
{
    return s1.size() +s2.size();
}
};
int main()
{
    myQueue q;

    q.enqueue(10);

    q.enqueue(70);

    q.dequeue();

    cout<<"Front: "<<q.front();
cout<<"Size is"<<q.size();

}