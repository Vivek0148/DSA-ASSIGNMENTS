#include <iostream>
#include <stack>
using namespace std;
class SpecialStack 
{
    stack<int> st;
    int minnum;
public:
    SpecialStack() {}
    void push(int x) 
    {
        if(st.empty()) 
        {
            st.push(x);
            minnum=x;
        } 
        else 
        {
            if(x>=minnum)
            st.push(x);
            else 
            {
                st.push(2*x-minnum);
                minnum=x;
            }
        }
    }
    void pop() 
    {
        if(st.empty()) 
        return;
        int t=st.top();
        st.pop();
        if (t<minnum)
        minnum=2*minnum-t;
    }
    int peek() 
    {
        if (st.empty()) 
        return -1;
        int t=st.top();
        if (t>=minnum) 
        return t;
        else 
        return minnum;
    }
    int getMin() 
    {
        if (st.empty()) 
        return -1;
        return minnum;
    }
};
int main() 
{
    SpecialStack s;
    int size,num;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    cout<<"Enter the ellements of stack: ";
    for(int i=0;i<size;i++)
    {
        cin>>num;
        s.push(num);
    }
    cout <<"Min: "<<s.getMin()<<endl;
    return 0;
}