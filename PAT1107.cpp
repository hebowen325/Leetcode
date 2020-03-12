#include<iostream>
#include<algorithm>
using namespace std;
int hobbies[1001][1001];
int mark[1001]={0};
int curr_hobbies[1001];
int clusters[1000];
int num_of_clusters=0;
int main()
{
    int N,K,tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d:",&K);
        hobbies[i][0]=K;
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp);
            hobbies[i][j+1]=tmp;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(mark[i]==0)
        {
            fill(curr_hobbies,curr_hobbies+1001,0);
            for(int j=1;j<=hobbies[i][0];j++)
            {
                curr_hobbies[hobbies[i][j]]=1;
            }
            int num_of_people=1;
            for(int j=i+1;j<N;j++)
            {
                if(mark[j]==0)
                {
                    for(int k=1;k<=hobbies[j][0];k++)
                    {
                        if(curr_hobbies[hobbies[j][k]]==1)
                        {
                            num_of_people++;
                            mark[j]=1;
                            break;
                        }
                    }
                    if(mark[j]==1)
                    {
                        for(int k=1;k<=hobbies[j][0];k++)
                        {
                            curr_hobbies[hobbies[j][k]]=1;
                        }
                    }
                }
            }
            clusters[num_of_clusters++]=num_of_people;
            mark[i]=1;
        }
    }
    sort(clusters,clusters+num_of_clusters);
    printf("%d\n%d",num_of_clusters,clusters[num_of_clusters-1]);
    for(int i=num_of_clusters-2;i>=0;i--)
    {
        printf(" %d",clusters[i]);
    }
    return 0;
}