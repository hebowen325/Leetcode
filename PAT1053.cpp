#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int* weight;
bool cmp(const int &a,const int &b)
{
    return weight[a]>weight[b];
}

string num_to_str(int num)
{
    string ans;
    string tmp;
    do
    {
        tmp=string(1,'0'+num%10);
        ans=tmp+ans;
        num/=10;
    }
    while(num!=0);
    return ans;
}
void traverse_tree(int id,map<int,vector<int>> Map,int S,string ans)
{
    if(weight[id]==S&&!Map.count(id))
    {
        cout<<ans<<" "<<S<<endl;
    }
    else if(weight[id]<=S)
    {
        ans=ans+" "+num_to_str(weight[id]);
        for(int i=0;i<Map[id].size();i++)
        {
            traverse_tree(Map[id][i],Map,S-weight[id],ans);
        }
    }
}

int main()
{
    int N,M,S;
    scanf("%d %d %d",&N,&M,&S);
    weight=new int [N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&weight[i]);
    }
    map<int,vector<int>> Map;
    vector<int> Vec;
    int id,num,node;
    for(int i=0;i<M;i++)
    {
        Vec.clear();
        scanf("%d %d",&id,&num);
        for(int j=0;j<num;j++)
        {
            scanf("%d",&node);
            Vec.push_back(node);
        }
        sort(Vec.begin(),Vec.end(),cmp);
        Map[id]=Vec;
    }
    if(S==weight[0])
    {
        cout<<S;
    }
    else if(S>weight[0])
    {
        for(int i=0;i<Map[0].size();i++)
        {
            traverse_tree(Map[0][i],Map,S-weight[0],num_to_str(weight[0]));
        }
    }
    return 0;
}