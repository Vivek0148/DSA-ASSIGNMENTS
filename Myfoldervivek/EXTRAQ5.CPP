#include<iostream>
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
    int k=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        res[k++]=arr[i];

        else
        {
            res[k++]=0;
            if(k<size)
            res[k++]=0;
        }
    }
    cout<<"Modified array: ";
    for(int i=0;i<size;i++)
    {
        arr[i]=res[i];
        cout<<arr[i]<<" ";
    }
}