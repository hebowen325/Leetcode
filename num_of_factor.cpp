#include<iostream>
#include<math.h>
#include<map>
#include<vector>
using namespace std;
const int MAXN=sqrt(1e9)+1;
vector<int> prime;
int isprime[MAXN]={0};
void Caculate_prime()
{
    for(int i=2;i<MAXN;i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<MAXN;j+=i)
            {
                isprime[j]=1;
            }
            prime.push_back(i);
        }
    }
}
int main()
{
    Caculate_prime();
    int N;
    int tmp;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tmp);
            map<int,int> Map;
            for(int j=0;j<prime.size()&&tmp!=1;j++)
            {
                if(tmp%prime[j]==0)
                {
                    Map[prime[j]]++;
                    tmp/=prime[j];
                    j--;
                }
            }
            int ans=1;
            map<int,int>::iterator Iter=Map.begin();
            while(Iter!=Map.end())
            {
                ans*=(Iter->second+1);
                Iter++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}