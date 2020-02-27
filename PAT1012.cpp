#include<iostream>
#include<vector>
#include<string>
#include"limits.h"
using namespace std;
int find_best_rank(int* score,int N,int place)
{
    int ans=0;
    for(int i=0;i<N;i++)
    {
        if(score[place]<score[i])
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    int N;
    int M;
    cin>>N;
    cin>>M;
    string* s_vector=new string [N];
    int* a_vector=new int [N];
    int* c_vector=new int [N];
    int* m_vector=new int [N];
    int* e_vector=new int [N];
    for(int i=0;i<N;i++)
    {
        cin>>s_vector[i];
        cin>>c_vector[i];
        cin>>m_vector[i];
        cin>>e_vector[i];
        a_vector[i]=(c_vector[i]+m_vector[i]+e_vector[i])/3;
    }
    string ID;
    int j;
    int rank[4];
    for(int i=0;i<M;i++)
    {
        cin>>ID;
        for(j=0;j<N;j++)
        {
            if(!s_vector[j].compare(ID))
            {
                break;
            }
        }
        if(j<N)
        {
            rank[0]=find_best_rank(a_vector,N,j);
            rank[1]=find_best_rank(c_vector,N,j);
            rank[2]=find_best_rank(m_vector,N,j);
            rank[3]=find_best_rank(e_vector,N,j);
            vector<int> Rank_best;
            int best=INT_MAX;
            int best_place;
            for(int i=0;i<4;i++)
            {
                if(best>rank[i])
                {
                    best=rank[i];
                    best_place=i;
                }
            }
            string word[4]={"A","C","M","E"};
            cout<<rank[best_place]+1<<" "<<word[best_place];
        }
        else
        {
            cout<<"N/A";
        }
        if(i!=M-1)
        {
            cout<<endl;
        }
    }
    return 0;
}