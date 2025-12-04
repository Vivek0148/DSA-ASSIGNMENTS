#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    int res[size];
    cout<<"Enter the ellements of the array: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    stack<int> small;
    for(int i=0;i<size;i++)
    {
        if(small.empty())
        {
            res[i]=-1;
            small.push(arr[i]);
        }
        else if(arr[i]>small.top())
        {
            res[i]=small.top();
            small.push(arr[i]);
        }
        else
        {
            while(!small.empty() && arr[i]<=small.top())
            small.pop();
            if(small.empty())
            res[i]=-1;
            else
            res[i]=small.top();
            small.push(arr[i]);
        }
    }
    cout<<"The resultant array: ";
    for(int i=0;i<size;i++)
    cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}