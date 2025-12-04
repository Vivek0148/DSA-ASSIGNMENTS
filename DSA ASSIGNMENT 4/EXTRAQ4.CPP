#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int Lunch(queue <int> student,stack <int> sandwich)
{
    int size=student.size();
    int i=0;
    while(i<size)
    {
        if(student.front()==sandwich.top())
        {
            student.pop();
            sandwich.pop();
            return Lunch(student,sandwich);
        }
        else
        {
            student.push(student.front());
            student.pop();
        }
        i++;
    }
    return student.size();
}
int main()
{
    queue <int> student;
    stack <int> sandwich;
    int size,num;
    cout<<"Enter the number of students(or sandwich): ";
    cin>>size;
    cout<<"Enter student preference(1 for circular and 0 for square): ";
    for(int i=0;i<size;i++)
    {
        cin>>num;
        student.push(num);
    }
    cout<<"Enter sandwich sequence(1 for circular and 0 for square): ";
    for(int i=0;i<size;i++)
    {
        cin>>num;
        sandwich.push(num);
    }
    stack<int>rst;
    while(sandwich.size()>0)
    {
        rst.push(sandwich.top());
        sandwich.pop();
    }
    sandwich=rst;
    int count=Lunch(student,sandwich);
    cout<<"Number of stundents remained unable to eat: "<<count;
    return 0;
}