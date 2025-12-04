#include <iostream>
#include <queue>
#include<climits>
using namespace std;
void sortQueue(queue<int>& q) 
{
    int size=q.size();
    for (int i=0;i<size;i++)
    {
        int min=INT_MAX;
        for(int j=0;j<size;j++)
        {
            int curr=q.front();
            q.pop();
            if(j<size-i && curr<min)
            min=curr;
            q.push(curr);
        }
        for(int j=0;j<size;j++)
        {
            int curr=q.front();
            q.pop();
            if(curr==min && j<size-i)
            {continue;}
            q.push(curr);
        }
        q.push(min);
    }
    return;
}
int main() 
{
    queue<int> q;
    int size,num;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    cout<<"Enter the ellemnts: ";
    for(int i=0;i<size;i++)
    {
        cin>>num;
        q.push(num);
    }
    sortQueue(q);
    cout<<"Sorted queue: ";
    while (!q.empty()) 
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}