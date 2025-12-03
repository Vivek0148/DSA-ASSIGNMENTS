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
    int transpose[c][r];
    for (int i = 0; i < r; i++)
    {
        for(int j=0;j<c;j++)
        transpose[j][i]=arr[i][j];
    }
    cout<<"Transpose="<<endl;
    for (int i = 0; i<c; i++)
    {
        for(int j=0;j<r;j++)
        cout<< transpose[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}