#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    char Str[100000];
    string S1;
    string S2;
    string ans;
    map<char,int> Map;
    cin.getline(Str,100000);
    S1=string(Str);
    cin.getline(Str,100000);
    S2=string(Str);
    for(int i=0;i<S2.length();i++)
    {
        Map[S2[i]]=0;
    }
    for(int i=0;i<S1.length();i++)
    {
        if(!Map.count(S1[i]))
        {
            S2=string(1,S1[i]);
            ans=ans+S2;
        }
    }
    cout<<ans;
    return 0;
}