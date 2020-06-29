#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
bool cmp(const pair<char*,int*> &pir1,const pair<char*,int*> &pir2)
{
    if(pir1.second[1]!=pir2.second[1])
    {
        return pir1.second[1]>pir2.second[1];
    }
    else if(pir1.second[0]!=pir2.second[0])
    {
        return pir1.second[0]<pir2.second[0];
    }
    else 
    {
        return strcmp(pir1.first,pir2.first)<0;
    }
    
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    char* name;
    int age;
    int money;
    int* ptr;
    vector<pair<char*,int*>> Vec;
    pair<char*,int*> Pair;
    for(int i=0;i<N;i++)
    {
        name=new char [20];
        scanf("%s %d %d",name,&age,&money);
        ptr=new int [2];
        ptr[0]=age;
        ptr[1]=money;
        Pair.first=name;
        Pair.second=ptr;
        Vec.push_back(Pair);
    }
    sort(Vec.begin(),Vec.end(),cmp);
    int M;
    int Amax;
    int Amin;
    int count;
    for(int i=0;i<K;i++)
    {
        count=0;
        scanf("%d %d %d",&M,&Amin,&Amax);
        printf("Case #%d:\n",i+1);
        for(int j=0;j<Vec.size()&&count<M;j++)
        {
            if(Vec[j].second[0]>=Amin&&Vec[j].second[0]<=Amax)
            {
                printf("%s %d %d\n",Vec[j].first,Vec[j].second[0],Vec[j].second[1]);
                count++;
            }
        }
        if(!count)
        {
            printf("None\n");
        }
    }
    return 0;
}