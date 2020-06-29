#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"#";
    string a;
    string ans;
    int tmp;
    for(int i=0;i<3;i++)
    {
        cin>>a;
        tmp=0;
        for(int i=0;i<a.length();i++)
        {
            tmp*=10;
            tmp+=a[i]-'0';
        }
        if(tmp/13>=10)
        {
            a=string(1,'A'+tmp/13-10);
        }
        else
        {
            a=string(1,'0'+tmp/13);
        }
        ans=a;
        if(tmp%13>=10)
        {
            a=string(1,'A'+tmp%13-10);
        }
        else
        {
            a=string(1,'0'+tmp%13);
        }
        ans=ans+a;
        cout<<ans;
    }
}