#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int temp[size];
    int days[size];
    cout<<"Enter the ellements of the array: ";
    for(int i=0;i<size;i++)
    cin>>temp[i];
    stack<int>hot;
    for(int i=size-1;i>=0;i--)
    {
        if(hot.empty())
        {
            days[i]=0;
            hot.push(i);
        }
        else if(temp[i]<temp[hot.top()])
        {
            days[i]=hot.top()-i;
            hot.push(i);
        }
        else 
        {
            while(!hot.empty() && temp[i]>=temp[hot.top()])
            hot.pop();
            if(hot.empty())
            days[i]=0;
            else
            days[i]=hot.top()-i;
            hot.push(i);
        }
    }
    cout<<"The resultant array of days: ";
    for(int i=0;i<size;i++)
    cout<<days[i]<<" ";
    cout<<endl;
    return 0;
}