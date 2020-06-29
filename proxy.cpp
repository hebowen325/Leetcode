#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    set<string> s1,s2;
    string tmp;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            s1.insert(tmp);
        }
        scanf("%d",&m);
        s2=s1;
        int ans=0;
        for(int j=0;j<m;j++)
        {
            cin>>tmp;
            if(find(s2.begin(),s2.end(),tmp)!=s2.end())
            {
                s2.erase(find(s2.begin(),s2.end(),tmp));
                if(s2.size()==0)
                {
                    if(s1.size()==1)
                    {
                        printf("-1\n");
                    }
                    else
                    {
                        ans++;
                        s2=s1;
                    }
                }
            }
        }
    }
    return 0;
}