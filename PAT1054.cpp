#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
bool cmp(const pair<int,int> &pir1,const pair<int,int> &pir2)
{
    return pir1.second>pir2.second;
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    map<int,int> Map;
    int image;
    for(int i=0;i<N*M;i++)
    {
        scanf("%d",&image);
        if(Map.count(image))
        {
            Map[image]++;
        }
        else
        {
            Map[image]=1;
        }
    }
    vector<pair<int,int>> Vec(Map.begin(),Map.end());
    sort(Vec.begin(),Vec.end(),cmp);
    printf("%d",Vec[0].first);
    return 0;
}