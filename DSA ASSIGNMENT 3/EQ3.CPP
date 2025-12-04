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
    stack<int> big;
    for(int i=size-1;i>=0;i--)
    {
        if(big.empty())
        {
            res[i]=-1;
            big.push(arr[i]);
        }
        else if(arr[i]<big.top())
        {
            res[i]=big.top();
            big.push(arr[i]);
        }
        else 
        {
            while(!big.empty() && arr[i]>=big.top())
            big.pop();
            if(big.empty())
            res[i]=-1;
            else
            res[i]=big.top();

            big.push(arr[i]);
        }
    }
    cout<<"The resultant array: ";
    for(int i=0;i<size;i++)
    cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}