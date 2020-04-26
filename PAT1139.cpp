#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<math.h>
using namespace std;
unordered_map<int,bool> Map;
typedef struct node
{
    int a,b;
    node(int x1,int x2):a(x1),b(x2){}
}node;
bool cmp(const node& n1,const node& n2)
{
    if(n1.a!=n2.a)
    {
        return n1.a<n2.a;
    }
    else
    {
        return n1.b<n2.b;
    }
}
int main()
{
    int N,M,K;
    scanf("%d%d",&N,&M);
    string p1,p2;
    vector<int> v[10000];
    vector<node> ans;
    for(int i=0;i<M;i++)
    {
        cin>>p1>>p2;
        if(p1.length()==p2.length())
        {
            v[abs(stoi(p1))].push_back(abs(stoi(p2)));
            v[abs(stoi(p2))].push_back(abs(stoi(p1)));
        }
        Map[10000*abs(stoi(p1))+abs(stoi(p2))]=Map[10000*abs(stoi(p2))+abs(stoi(p1))]=true;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        ans.clear();
        cin>>p1>>p2;
        for(int k1=0;k1<v[abs(stoi(p1))].size();k1++)
        {
            for(int k2=0;k2<v[abs(stoi(p2))].size();k2++)
            {
                if(abs(v[abs(stoi(p1))][k1])==abs(stoi(p2))||abs(v[abs(stoi(p2))][k2])==abs(stoi(p1)))
                {
                    continue;
                }
                if(Map[10000*abs(v[abs(stoi(p1))][k1])+abs(v[abs(stoi(p2))][k2])]==true)
                {
                    ans.push_back(node(abs(v[abs(stoi(p1))][k1]),abs(v[abs(stoi(p2))][k2])));
                }    
            }
        }
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size();i++)
        {
            printf("%04d %04d\n",ans[i].a,ans[i].b);
        }
    }
    return 0;
}