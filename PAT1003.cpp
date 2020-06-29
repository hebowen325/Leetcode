#include<iostream>
#include<vector>
#include"limits.h"
#include<algorithm>
using namespace std;
struct Node
{
    int precity;
    int city;
    int length;
    Node(int PreCity,int City,int Length)
    {
        precity=PreCity;
        city=City;
        length=Length;
    }
};

void Insert(vector<Node*>& Vector,Node* tmp)
{
    for(int i=0;i<Vector.size();i++)
    {
        if(tmp->length<Vector[i]->length)
        {
            Vector.insert(Vector.begin()+i,tmp);
            return ;
        }
    }
    Vector.insert(Vector.end(),tmp);
    return ;
}
int num_of_ans(vector<int>* pre,int i,int city1)
{
    int ans=0;
    for(int j=0;j<pre[i].size();j++)
    {
        if(pre[i][j]!=city1)
        {
            ans+=num_of_ans(pre,pre[i][j],city1);
        }
        else
        {
            ans+=1;
        }
    }
    return ans;
}
int max_team(vector<int>*pre,int* number_of_team,int i,int city1)
{
    int ans=0;
    if(i==city1)
    {
        return number_of_team[i];
    }
    for(int j=0;j<pre[i].size();j++)
    {
        if(ans<max_team(pre,number_of_team,pre[i][j],city1))
        {
            ans=max_team(pre,number_of_team,pre[i][j],city1);
        }
    }
    return ans+number_of_team[i];

}
int main()
{
    int N,M,C1,C2,city1,city2,Dist;
    cin>>N;
    cin>>M;
    cin>>C1;
    cin>>C2;
    int* number_of_team=new int[N];
    int number_of_road=0;
    for(int i=0;i<N;i++)
    {
        cin>>number_of_team[i];
    }
    int** dist=new int*[N];
    int* length=new int[N];
    vector<int>* pre=new vector<int> [N];
    for(int i=0;i<N;i++)
    {
        length[i]=INT_MAX;
        dist[i]=new int [N];
        for(int j=0;j<N;j++)
        {
            dist[i][j]=-1;
        }
    }
    for(int i=0;i<M;i++)
    {
        cin>>city1;
        cin>>city2;
        cin>>Dist;
        dist[city1][city2]=dist[city2][city1]=Dist;
    }
    vector<Node*> Vector;
    length[C1]=0;
    Node* ptr=new Node(C1,C1,0);
    Vector.push_back(ptr);
    Node* tmp;
    int minimum=INT_MAX;
    while(!Vector.empty())
    {
        ptr=Vector[0];
        Vector.erase(Vector.begin());
		if(length[ptr->city]<ptr->length||ptr->length>minimum)
        {
            continue;
        }
        else
        {
            if(find(pre[ptr->city].begin(),pre[ptr->city].end(),ptr->precity)==pre[ptr->city].end())
            {
                pre[ptr->city].push_back(ptr->precity);
                length[ptr->city]=ptr->length;
            }
            if(ptr->city==C2)
            {
                minimum=ptr->length;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[ptr->city][i]!=-1&&length[ptr->city]+dist[ptr->city][i]<=length[i])
            {
                length[i]=length[ptr->city]+dist[ptr->city][i];
                tmp=new Node(ptr->city,i,length[i]);
                Insert(Vector,tmp);
            }
        }
    }
	cout<<num_of_ans(pre,C2,C1)<<" ";
    cout<<max_team(pre,number_of_team,C2,C1);
    return 0;
}