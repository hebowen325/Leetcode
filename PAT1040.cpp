#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int maximum=1;
    int j;
    for(int i=1;i<str.length();i++)
    {
        if(str[i-1]==str[i+1])
        {
            for(j=1;i-j>=0&&i+j<str.length();j++)
            {
                if(str[i-j]!=str[i+j])
                {
                    break;
                }
            }
            if(maximum<2*j-1)
            {
                maximum=2*j-1;
            }
        }
        if(str[i]==str[i-1])
        {
            for(j=0;i-j-1>=0&&i+j<str.length();j++)
            {
                if(str[i-j-1]!=str[i+j])
                {
                    break;
                }
            }
            if(maximum<2*j)
            {
                maximum=2*j;
            }
        }
    }
    cout<<maximum;
    return 0;
}