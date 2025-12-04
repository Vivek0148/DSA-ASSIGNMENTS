#include<iostream>
using namespace std;
int main()
{
    string str1,str2;
    cout<<"Enter two strings one by one(small letters): ";
    cin>>str1>>str2;
    if(str1.length()!=str2.length())
    cout<<"Not an anagram\n";
    else
    { 
        bool check=true;
        int freq1[26]={0};
        int freq2[26]={0};
        for(int i=0;i<str1.length();i++)
        {
            freq1[(str1[i]-'a')]++;
            freq2[(str2[i]-'a')]++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=freq2[i])
            check=false;
        }
        if (check)
        cout<<"Anagram\n";
        else
        cout<<"Not an anagram\n";
    }
}