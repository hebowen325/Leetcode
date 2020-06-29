#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
bool Cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int N;
    vector<int> vector_positive[2];
    vector<int> vector_negative[2];
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        if(tmp>0)
        {   
            vector_positive[0].push_back(tmp);
        }
        else if(tmp<0)
        {
            vector_negative[0].push_back(tmp);
        }
    }
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        if(tmp>0)
        {   
            vector_positive[1].push_back(tmp);
        }
        else if(tmp<0)
        {
            vector_negative[1].push_back(tmp);
        }
    }
    sort(vector_positive[0].begin(),vector_positive[0].end(),cmp);
    sort(vector_positive[1].begin(),vector_positive[1].end(),cmp);
    sort(vector_negative[0].begin(),vector_negative[0].end(),Cmp);
    sort(vector_negative[1].begin(),vector_negative[1].end(),Cmp);
    int count=0;
    int ans=0;
    while(count<vector_positive[0].size()&&count<vector_positive[1].size())
    {
        ans+=vector_positive[0][count]*vector_positive[1][count];
        count++;
    }
    count=0;
    while(count<vector_negative[0].size()&&count<vector_negative[1].size())
    {
        ans+=vector_negative[0][count]*vector_negative[1][count];
        count++;
    }
    cout<<ans;
    return 0;
}