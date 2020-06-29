#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k=s.length()/3;
    while(s.length()+2-2*k>=k&&s.length()+2-2*k>=3)
    {
        k++;
    }
    k--;
    string tmp=string(s.length()-2*k,' ');
    for(int i=0;i<k-1;i++)
    {
        cout<<s[i]<<tmp<<s[s.length()-1-i]<<endl;
    }
    cout<<s.substr(k-1,s.length()+2-2*k);
    return 0;
}