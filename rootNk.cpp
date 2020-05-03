#include<iostream>
using namespace std;
int k_sum(int x,int k)
{
    while(x>=k)
    {
        int ans=0;
        do
        {
            ans+=x%k;
            x/=k;
        }while(x>0);
        x=ans;
    }
    return x;
}

string two_convert(int k)
{
    string ans(32,'0');
    int i=31;
    do
    {
        ans[i]+=k%2;
        k/=2;
        i--;
    }while(k>0);
    for(i=0;ans[i]=='0';i++);
    return ans.substr(i);
}
int main()
{
    int x,y,k;
    while(scanf("%d %d %d",&x,&y,&k)!=EOF)
    {
        int ans=1;
        x=k_sum(x,k);
        string tmp=two_convert(y);
        for(int i=tmp.size()-1;i>=0;i--)
        {
            if(tmp[i]=='1')
            {
                ans=k_sum(ans*x,k);
            }
            x=k_sum(x*x,k);
        }
        printf("%d\n",ans);
        return 0;
    }
}