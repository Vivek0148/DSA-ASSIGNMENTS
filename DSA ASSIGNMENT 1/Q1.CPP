#include<iostream>
using namespace std;
int n=0;
int arr[100];
void create() 
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    cin >> arr[i];
}
void display() 
{
    if (n == 0) 
    {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements:"<<endl;
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
}
void insertellement()
{
    int num,pos;
    cout<<"Enter the number to be added: ";
    cin>>num;
    cout<<"Enter the index where it has to be inserted: ";
    cin>>pos;
    if(pos<0 || pos>n)
    {
        cout<<"Wrong position";
        return;
    }
    for(int i=n;i>pos;i--)
    arr[i]=arr[i-1];

    arr[pos]=num;
    n++;
    return;
}
void deleteellement()
{
    if (n == 0) 
    {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout<<"Enter the position from which number to be deleted: ";
    if (pos < 0 || pos >= n) 
    {
        cout << "Wrong position.\n";
        return;
    }
    cin>>pos;
    for(int i=pos;i<n-1;i++)
    arr[i]=arr[i+1];
    n--;
}
void search()
{
    if (n == 0) 
    {
        cout << "Array is empty"<<endl;
        return;
    }
    int num;
    cout<<"Enter the number to be searched in the array: ";
    cin>>num;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            cout<<"Ellement found at index: "<<i;
            found=true;
            break;
        }
    }
    if(!found)
    cout<<"Ellement not found";
    return;
}
int main()
{
    int choice;
    do
    {
        cout<<"Enter 1 to create a array"<<endl<<"Enter 2 to Display the array"<<endl<<"Enter 3 to insert a number in array"<<endl<<"Enter 4 to delete a number in array"<<endl<<"Enter 5 for Linear Search an ellement in an array"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            insertellement();
            break;
            case 4:
            deleteellement();
            break;
            case 5:
            search();
            break;
            case 6:
            cout<<"Exiting.......";
            break;
            default: 
            cout << "Invalid choice!\n";
        }
    }
    while(choice!=6);
    return 0;
}