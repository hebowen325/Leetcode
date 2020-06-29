#include<iostream>
#include "limits.h"
#include<string>
#include<algorithm>
using namespace std;
int dis[1100][1100];
int G[1100][1100];
int N;
int getid(string ID)
{
    if(ID[0]=='G')
    {
        return stoi(ID.substr(1,ID.length()-1))+N;
    }
    return stoi(ID);
}
int main()
{
    int M,K,D;
    scanf("%d %d %d %d",&N,&M,&K,&D);
    fill(dis[0],dis[0]+1100*1100,INT_MAX);
    fill(G[0],G[0]+1100*1100,INT_MAX);
    for(int i=0;i<K;i++)
    {
        string house1,house2;
        cin>>house1>>house2;
        int distance,h1,h2;
        cin>>distance;
        h1=getid(house1);
        h2=getid(house2);
        if(h1==h2)
        {
            continue;
        }
        if(distance<G[h1][h2])
        {
            G[h1][h2]=distance;
        }
        if(distance<G[h2][h1])
        {
            G[h2][h1]=distance;
        }
    }
    for(int i=N+1;i<=N+M;i++)
    {
        dis[i][i]=0;
        int sign[1100];
        fill(sign,sign+1100,0);
        for(int k=1;k<=M+N;k++)
        {
            int u=-1;
            int min_len=INT_MAX;
            for(int j=1;j<=N+M;j++)
            {
                if(dis[i][j]<min_len&&sign[j]==0)
                {
                    u=j;
                    min_len=dis[i][j];
                }
            }
            if(u==-1)
            {
                break;
            }
            sign[u]=1;
            for(int j=1;j<=N+M;j++)
            {
                if(G[u][j]!=INT_MAX&&dis[i][j]>dis[i][u]+G[u][j])
                {
                    dis[i][j]=dis[i][u]+G[u][j];
                }
            }
        }
    }
    int index=-1;   
    bool flag=true;
    int min_dis=INT_MIN;
    int sum_dis;
    for(int i=N+1;i<=N+M;i++)
    {
        int min_len=INT_MAX;
        int total=0;
	    flag=true;
        for(int j=1;j<=N;j++)
        {
            if(dis[i][j]>D)
            {
                flag=false;
                break;
            }
            if(min_len>dis[i][j])
            {
                min_len=dis[i][j];
            }
            total+=dis[i][j];
        }
        if(flag==false)
        {
            continue;
        }
        if(min_dis<min_len)
        {
            index=i-N;
            min_dis=min_len;
            sum_dis=total;
        }
        else if(min_dis==min_len&&total<sum_dis)
        {
            index=i-N;
            sum_dis=total;
        }
    }
    if(index==-1)
    {
        cout<<"No Solution";
    }
    else
    {
        printf("G%d\n",index);
        float num1=min_dis;
        float avg=float(sum_dis)/N;
        printf("%.1f %.1f",num1,avg);
    }
    return 0;
}