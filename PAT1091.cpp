#include<iostream>
#include<stack>
using namespace std;
int matrix[77161][129];
int note[77161][129];
int M,N,L,T;
int caculate_volume()
{
    fill(note[0],note[0]+77161*129,0);
    stack<int> S;
    int ans=0;
    for(int i=0;i<M*L;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(note[i][j]==0&&matrix[i][j]==1)
            {
                S.push(i*N+j);
                int region=0;
                while(!S.empty())
                {
                    int t1=S.top()/N;
                    int t2=S.top()%N;
                    S.pop();
                    if(note[t1][t2]==0&&matrix[t1][t2]==1)
                    {
                        region+=1;
                        if(t1<(L-1)*M)
                            S.push((t1+M)*N+t2);
                        if(t1>=M)
                            S.push((t1-M)*N+t2);
                        if(t1%M>0)
                            S.push((t1-1)*N+t2);
                        if(t1%M<M-1)
                            S.push((t1+1)*N+t2);
                        if(t2>0)
                            S.push(t1*N+t2-1);
                        if(t2<N-1)
                            S.push(t1*N+t2+1);
                    }
                    note[t1][t2]=1;
                }
                if(region>=T)
                    ans+=region;
            }
            note[i][j]=1;
        }
    }
    return ans;
}
int main()
{
    scanf("%d %d %d %d",&M,&N,&L,&T);
    int ans=0;
    for(int j=0;j<M*L;j++)
    {
        for(int k=0;k<N;k++)
        {
            scanf("%d",matrix[j]+k);
        }
    }
    ans+=caculate_volume();
    cout<<ans;
    return 0;
}