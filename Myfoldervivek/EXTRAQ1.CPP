#include<iostream>
using namespace std;
int main()
{
    int size,k,count=0;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the ellements of array:\n";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Enter the value of k: ";
    cin>>k;
    bool found=false;
    cout<<"First two numbers to satisfy this condition: ";
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]-arr[j]==k || arr[j]-arr[i]==k)
            {
                cout<<arr[i]<<" & "<<arr[j];
                found=true;
                break;
            }
        }
        if(found)
        break;
    }
    return 0;
}