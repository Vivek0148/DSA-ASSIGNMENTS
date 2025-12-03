#include <iostream>
using namespace std;
int main()
{
    int r,c;
    cout << "Enter the row size of the array: ";
    cin >> r;
    cout << "Enter the column size of the array: ";
    cin >> c;
    int arr[r][c];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i<r; i++)
    {
        for(int j=0;j<c;j++)
        cin >> arr[i][j];
    }
    for(int i=0;i<r;i++)
    {
        int sum=0;
        for (int j=0;j<c;j++)
        sum+=arr[i][j];
        cout<<"sum of "<<i+1<<" row= "<<sum;
        cout<<endl;
    }
    for(int i=0;i<c;i++)
    {
        int sum=0;
        for (int j=0;j<r;j++)
        sum+=arr[j][i];
        cout<<"sum of "<<i+1<<" column= "<<sum;
        cout<<endl;
    }
    return 0;
}