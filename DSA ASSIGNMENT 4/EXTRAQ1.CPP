#include <iostream>
#include <queue>
using namespace std;
int main() 
{
    int num;
    queue<string> q;
    cout<<"Enter number: ";
    cin>>num;
    cout<<"Binary numbers from 1 to "<<num<<": ";
    q.push("1");
    for (int i=1;i<=num;i++)
    {
        string curr=q.front();
        q.pop();
        cout<<curr<<" ";
        q.push(curr+"0");
        q.push(curr+"1");
    }
    cout<<endl;
    return 0;
}