#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct family
{
    int ID;
    int num_of_people;
    double num_of_sets;
    double area;
    double avg_sets;
    double avg_area;
    family():ID(-1),num_of_people(0),num_of_sets(0.0),area(0.0) {}
}family;

typedef struct people
{
    int ID;
    double num_of_sets;
    double area;
    people () {}
}people;
int father[10000];
family f[10000];
people p[10000];
int visit[10000]={0};
int tt[8];
int find(int x)
{
    while(father[x]!=-1)
    {
        x=father[x];
    }
    return x;
}
void Union(int x1,int x2)
{
    int xa=find(x1);
    int xb=find(x2);
    if(xa<xb)
    {
        father[xb]=xa;
    }
    if(xb<xa)
    {
        father[xa]=xb;
    }
}
bool cmp(const family& f1,const family& f2)
{
    if(f1.avg_area!=f2.avg_area)
    {
        return f1.avg_area>f2.avg_area;
    }
    else
    {
        return f1.ID<f2.ID;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    fill(father,father+10000,-1);
    int k;
    for(int i = 0; i < N; i++) 
    {
        scanf("%d %d %d %d",tt,tt+1,tt+2,&k);
        visit[tt[0]]=1;
        if(tt[1]!=-1)
        {
            Union(tt[0],tt[1]);
            visit[tt[1]]=1;
        }
        if(tt[2]!=-1)
        {
            Union(tt[0],tt[2]);
            visit[tt[2]]=1;
        }
        for(int j=0;j<k;j++)
        {
            scanf("%d",tt+j+3);
            Union(tt[0],tt[j+3]);
            visit[tt[j+3]]=1;
        }
        p[i].ID=tt[0];
        scanf("%lf %lf",&p[i].num_of_sets,&p[i].area);
    }
    for(int i=0;i<N;i++)
    {
        f[find(p[i].ID)].ID=find(p[i].ID);
        f[find(p[i].ID)].num_of_sets+=p[i].num_of_sets;
        f[find(p[i].ID)].area+=p[i].area;
    }
    int count=0;
    vector<family> Vec;
    for(int i=0;i<10000;i++)
    {
        if(visit[i]==1)
        {
            f[find(i)].num_of_people++;
        }
    }
    for(int i=0;i<10000;i++)
    {
        if(f[i].ID!=-1)
        {
            f[i].avg_area=f[i].area/f[i].num_of_people;
            f[i].avg_sets=f[i].num_of_sets/f[i].num_of_people;
            Vec.push_back(f[i]);
        }
    }
    sort(Vec.begin(),Vec.end(),cmp);
    printf("%d\n",Vec.size());
    for(int i=0;i<Vec.size();i++)
    {
        printf("%04d %d %.3lf %.3lf\n",Vec[i].ID,Vec[i].num_of_people,Vec[i].avg_sets,Vec[i].avg_area);
    }
    return 0;
}