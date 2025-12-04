#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    queue<int> source;
    queue<int> res;
    stack<int> help;
    int size,num;
    int expected=1;
    bool possible=true;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    cout<<"Enter the ellemnts: ";
    for(int i=0;i<size;i++)
    {
        cin>>num;
        source.push(num);
    }
    while(!source.empty())
    {
        int curr=source.front();
        source.pop();
        if(curr==expected)
        {
            res.push(expected);
            expected++;
            if(!help.empty() && help.top()==expected)
            {
                res.push(expected);
                help.pop();
                expected++;
            }
        }
        else
        {
            if(help.empty() || help.top()>curr)
            help.push(curr);

            else
            {
                possible=false;
                break;
            }
        }
    }
    if(possible)
    {
        cout<<"Yes! it's posible.\nSorted queue: ";
        for(int i=0;i<size;i++)
        {
            cout<<res.front()<< " ";
            res.pop();
        }
        cout<<endl;
    }
    else
    cout<<"Not possible!\n";
    return 0;
}