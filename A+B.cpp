#include<iostream>
#include<string>
using namespace std;
string convert(int x,int m)
{
  string ans;
  do
  {
    string tmp(1,'0'+x%m);
    ans=tmp+ans;
    x/=m;
  }while (x!=0);
  return ans;
}

string add(string A,string B,int m)
{
    string ans(max(A.length(),B.length())+1,'0');
    int carry=0;
    for(int i=0;i<max(A.length(),B.length());i++)
    {
        if(i<A.length()&&i<B.length())
        {
            int current=A[A.length()-1-i]-'0'+B[B.length()-1-i]-'0'+carry;
            ans[ans.length()-1-i]=current%m+'0';
            carry=current/m;
        }
        else if(i<A.length())
        {
            int current=A[A.length()-1-i]-'0'+carry;
            ans[ans.length()-1-i]=current%m+'0';
            carry=current/m;
        }
        else
        {
            int current=B[B.length()-1-i]-'0'+carry;
            ans[ans.length()-1-i]=current%m+'0';
            carry=current/m;
        }
    }
    if(carry!=0)
    {
        ans[0]='1';
        return ans;
    }
    else
    {
        return ans.substr(1);
    }
}
int main()
{
    int m,A,B;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
        {
            break;
        }
        else
        {
            scanf("%d%d",&A,&B);
            string a=convert(A,m);
            string b=convert(B,m);
            string ans=add(a,b,m);
            cout<<ans<<endl;
        }
    }
    return 0;
}