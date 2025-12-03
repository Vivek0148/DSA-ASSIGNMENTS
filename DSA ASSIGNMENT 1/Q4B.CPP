#include <iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2;
    cout << "Enter the row size of the array 1st : ";
    cin >> r1;
    cout << "Enter the column size of the array 1st: ";
    cin >> c1;
    int arr1[r1][c1];
    cout << "Enter the elements of the array 1:\n";
    for (int i = 0; i<r1; i++)
    {
        for(int j=0;j<c1;j++)
        cin >> arr1[i][j];
    }
    cout << "Enter the row size of the array 2nd : ";
    cin >> r2;
    cout << "Enter the column size of the array 2nd: ";
    cin >> c2;
    int arr2[r2][c2];
    cout << "Enter the elements of the array 2:\n";
    for (int i = 0; i<r2; i++)
    {
        for(int j=0;j<c2;j++)
        cin >> arr2[i][j];
    }
    if(c1!=r2)
    cout<<"Matrix Multiplication not possible";
    int res[r1][c2];
    cout<<"The multiplied array=\n";
    for (int i=0;i<r1;i++)
    {
        for (int j=0;j<c2;j++)
        {
            res[i][j]=0;
            for(int k=0;k<c1;k++)
            {
            res[i][j]=res[i][j]+arr1[i][k]*arr2[k][j];
            }
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}