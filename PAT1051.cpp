#include<iostream>
#include<stack>
using namespace std;
bool JudgePopSequence(int* sequence,int N,int MaxSize)
{
    stack<int> Stack;
    int border=1;
    int i;
    int* flag=new int [N];
    fill(flag,flag+N,1);
    for(i=0;i<N;i++)
    {
        if(sequence[i]<border)
        {
            if(flag[sequence[i]]==1&&Stack.size()>0&&Stack.top()==sequence[i])
            {
                Stack.pop();
                flag[sequence[i]]=0;
            }
            else
            {
                return false;
            }
        }
        else
        {
            for(int j=border;j<sequence[i];j++)
            {
                Stack.push(j);
            }
            if(Stack.size()+1>MaxSize)
            {
                return false;
            }
            flag[sequence[i]]=0;
            border=sequence[i]+1;
        }
        if(border==N+1)
        {
            i++;
            break;
        }
    }
    while(i<N)
    {
        if(flag[sequence[i]]==1&&Stack.size()>0&&Stack.top()==sequence[i])
        {
            Stack.pop();
            flag[sequence[i]]=0;
        }
        else
        {
            return false;
        }
        i++;
    }
    return true;
}
int main()
{
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    int *sequence=new int [N];
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&sequence[j]);
        }
        if(JudgePopSequence(sequence,N,M)==true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}