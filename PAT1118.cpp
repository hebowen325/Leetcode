#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int picture_for_birds[100001];
vector<vector<int>> Vec;
int cache[100001]={0};
void belong_to_tree(int a1,int a2)
{
    for(int i=0;i<Vec[a2].size();i++)
    {
        Vec[a1].push_back(Vec[a2][i]);
        picture_for_birds[Vec[a2][i]]=a1;
    }
    Vec.erase(Vec.begin()+a2);
}
int main()
{
    int N,num,K,max;
    max=0;
    scanf("%d",&N);
    fill(picture_for_birds,picture_for_birds+100001,-1);
    for(int i=0;i<N;i++)
    {
        int flag=-1;
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            scanf("%d",cache+j);
            if(max<cache[j])
            {
                max=cache[j];
            }
            if(picture_for_birds[cache[j]]!=-1)
            {
                if(flag==-1)
                {
                    flag=picture_for_birds[cache[j]];
                }
                else if(flag<picture_for_birds[cache[j]])
                {
                    belong_to_tree(flag,picture_for_birds[cache[j]]);
                }
                else if(flag>picture_for_birds[cache[j]])
                {
                    belong_to_tree(picture_for_birds[cache[j]],flag);
                    flag=picture_for_birds[cache[j]];
                }
            }
        }
        if(flag==-1&&num>0)
        {
            vector<int> tmp(cache,cache+num);
            Vec.push_back(tmp);
            for(int j=0;j<num;j++)
            {
                picture_for_birds[cache[j]]=Vec.size()-1;
            }
        }
        else if(num>0)
        {
            for(int j=0;j<num;j++)
            {
                Vec[flag].push_back(cache[j]);
                picture_for_birds[cache[j]]=flag;
            }
        }
    }
    scanf("%d",&K);
    int num1;
    printf("%d %d\n",Vec.size(),max);
    for(int i=0;i<K;i++)
    {
        scanf("%d %d",&num,&num1);
        if(picture_for_birds[num]==picture_for_birds[num1])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}