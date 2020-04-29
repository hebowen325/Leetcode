#include<iostream>
using namespace std;
int main()
{
    string a,b,c,d;
    int tmp;
    string arr[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin>>a>>b>>c>>d;
    int i;
    for(i=0;i<a.length()&&i<b.length();i++)
    {
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
        {
            cout<<arr[a[i]-'A']<<" ";
            i++;
            break;
        }
    }
    for(;i<a.length()&&i<b.length();i++)
    {
        if((a[i]==b[i])&&((a[i]>='A'&&a[i]<='N')||(a[i]>='0')&&(a[i]<='9')))
        {
            if(a[i]>='0'&&a[i]<='9')
            {
                tmp=a[i]-'0';
            }
            else
            {
                tmp=a[i]-'A'+10;
            }
            break;
        }
    }
    if(tmp>=10)
    {
        cout<<tmp<<":";
    }
    else
    {
        cout<<"0"<<tmp<<":";
    }
    for(i=0;i<c.length()&&i<d.length();i++)
    {
        if((c[i]==d[i])&&((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z')))
        {
            if(i<=9)
            {
                cout<<"0"<<i;
            }
            else
            {
                cout<<i;
            }
            break;
        }
    }
    return 0;
}