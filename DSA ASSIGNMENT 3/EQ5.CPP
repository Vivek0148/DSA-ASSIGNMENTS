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
    stack<int> help;
    bool possible=true;
    cout<<"Enter the ellements of array: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    int expec=1;
    int i=0;
    int k=0;
    while(i<size)
    {
        if(arr[i]==expec)
        {
            res[k++]=expec;
            expec++;
            while(!help.empty() && help.top()==expec)
            {
                res[k++]=expec;
                expec++;
                help.pop();
            }
        }
        else
        {
            if(help.empty() || help.top()>arr[i])
            help.push(arr[i]);
            else
            {
                possible=false;
                break;
            }
        }
        i++;
    }
    if(possible)
    {
        cout<<"Yes! it's posible.\nSorted array: ";
        for(int i=0;i<size;i++)
        cout<<res[i]<< " ";

        cout<<endl;
    }
    else
    cout<<"Not possible!\n";
    return 0;
}