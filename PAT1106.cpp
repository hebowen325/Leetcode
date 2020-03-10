#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int price_count[110001];
int retail_count[110001]={0};
int main()
{
    int N;
    double P,R;
    scanf("%d %lf %lf",&N,&P,&R);
    vector<int>* Vec=new vector<int> [N];
    int K,tmp;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&K);
        if(K==0)
        {
            retail_count[i]=1;
        }
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp);
            Vec[i].push_back(tmp);
        }
    }
    vector<int> Vec1;
    vector<int> Vec2;
    Vec2.push_back(0);
    price_count[0]=0;
    while(!Vec2.empty())
    {
        Vec1=Vec2;
        Vec2.clear();
        for(int i=0;i<Vec1.size();i++)
        {
            int t=Vec1[i];
            for(int j=0;j<Vec[t].size();j++)
            {
                price_count[Vec[t][j]]=price_count[t]+1;
                Vec2.push_back(Vec[t][j]);
            }
        }
    }
    int least=999999;
    int leastcount=0;
    for(int i=0;i<N;i++)
    {
        if(retail_count[i]==1)
        {
            if(least>price_count[i])
            {
                least=price_count[i];
                leastcount=1;
            }
            else if (least==price_count[i])
            {
                leastcount++;
            }
        }
    }
    printf("%.4lf %d",P*pow(1+R/100,least),leastcount);
    return 0;
}