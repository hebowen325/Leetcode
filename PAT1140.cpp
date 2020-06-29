#include<iostream>
using namespace std;
string look_and_say(string tmp)
{
    string ans(100000,0);
    ans[0]=tmp[0];
    int count=1,C=1;
    for(int i=1;tmp[i]!=0;i++)
    {
        if(tmp[i]!=tmp[i-1])
        {
            if(count<10)
            {
                ans[C++]='0'+count;
            }
            else
            {
                ans[C++]='0'+count/10;
                ans[C++]='0'+count%10;
            }
            ans[C++]=tmp[i];
            count=1;
        }
        else
        {
            count++;
        }
    }
    if(count<10)
    {
        ans[C++]='0'+count;
    }
    else
    {
        ans[C++]='0'+count/10;
        ans[C++]='0'+count%10;
    }
    return ans;
}
int main()
{
    int D,N;
    scanf("%d%d",&D,&N);
    string ans(10000,0);
    ans[0]='0'+D;
    for(int i=1;i<N;i++)
    {
        ans=look_and_say(ans);
    }
    cout<<ans;
    return 0;
}