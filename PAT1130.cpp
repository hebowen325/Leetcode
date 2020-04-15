#include<iostream>
using namespace std;
int Nodes[21][2];
string val[21];
int N;
string recursion_ans(int num)
{
    string ans;
    if(Nodes[num][0]!=-1)
    {
        ans=recursion_ans(Nodes[num][0]);
    }
    ans=ans+val[num];
    if(Nodes[num][1]!=-1)
    {
        ans=ans+recursion_ans(Nodes[num][1]);
    }
    if(Nodes[num][0]!=-1||Nodes[num][1]!=-1)
    {
        ans='('+ans+')';
    }
    return ans;
}
int main()
{
    scanf("%d",&N);
    int sum=N*(N+1)/2;
    for(int i=1;i<=N;i++)
    {
        cin>>val[i];
        scanf("%d %d",Nodes[i],Nodes[i]+1);
        if(Nodes[i][0]!=-1)
        {
            sum-=Nodes[i][0];
        }
        if(Nodes[i][1]!=-1)
        {
            sum-=Nodes[i][1];
        }
    }
    if(recursion_ans(sum)[0]=='(')
    {
        cout<<recursion_ans(sum).substr(1,recursion_ans(sum).length()-2);
    }
    else
    {
        cout<<recursion_ans(sum);
    }
    return 0;
}