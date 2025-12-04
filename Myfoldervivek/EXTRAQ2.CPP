#include <iostream>
#include <string>
using namespace std;
bool isSubstring(const string &small, const string &big) 
{
    if (small.size()>big.size())
    return false;
    for (int i=0;i<=big.size()-small.size();i++) 
    {
        bool match=true;
        for (int j=0;j<small.size();j++) 
        {
            if (big[i+j]!=small[j]) 
            {
                match=false;
                break;
            }
        }
        if(match) 
        return true;
    }
    return false;
}
int main() 
{
    string str;
    cout<<"Enter the string: ";
    cin >> str;
    int n = str.size();
    bool found=false;
    for (int i = 1; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            string part1 = str.substr(0, i);
            string part2 = str.substr(i, j - i);
            string part3 = str.substr(j);
            if (part1.empty() || part2.empty() || part3.empty())
            continue;
            if (isSubstring(part1, part2) && isSubstring(part1, part3))
            found=true;
            if (isSubstring(part2, part1) && isSubstring(part2, part3))
            found=true;
            if (isSubstring(part3, part1) && isSubstring(part3, part2))
            found=true;
        }
    }
    if(!found)
    cout<<"It can't be split\n";
    else
    cout<<"Yes it can be split\n";
    return 0;
}