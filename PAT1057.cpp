#include<vector>
#include<stack>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn=1e5+2;
typedef struct Stack
{
    int c[maxn];
    int* arr;
    int top;
    Stack(int n): top(0)
	{
		arr = new int[n+1];
		memset(c, 0, sizeof(c));
	}
    int lowbit(int x)
    {
        return x&(-x);
    }
    void insert(int num)
    {
        arr[top++]=num;
        for(int i=num;i<maxn;i+=lowbit(i))
        {
            c[i]+=1;
        }
    }
    bool pop(int &num)
    {
        if(top==0)
        {
            return false;
        }
        else
        {
            num=arr[--top];
            for(int i=num;i<maxn;i+=lowbit(i))
            {
                c[i]-=1;
            }
            return true;
        }
    }
    int Sum(int x)
    {
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i))
        {
            ans+=c[i];
        }
        return ans;
    }
    bool findmedian(int &num)
    {
        int l=0,r=maxn-1,mid,target,res;
        if(top==0)
        {
            return false;
        }
        if(top%2==0)
        {
            target=top/2;
        }
        else
        {
            target=top/2+1;
        }
        while(l<r-1)
        {
            mid=(l+r)/2;
            res=Sum(mid);
            if(res<target)
            {
                l=mid;
            }
            else 
            {
                r=mid;
            }
        }
        num=l+1;
        return true;
    }
}Stack;

int main()
{
    int N;
    scanf("%d",&N);
    Stack s(N);
    char command[100];
    int num;
    for(int i=0;i<N;i++)
    {
        scanf("%s",command);
        switch(command[1])
        {
            case('u'):
            {
                scanf("%d",&num);
                s.insert(num);
                break;
            }
            case('e'):
            {
                if(s.findmedian(num))
                {
                    printf("%d\n",num);
                }
                else
                {
                    printf("Invalid\n");
                }
                break;
            }
            case('o'):
            {
                if(s.pop(num))
                {
                    printf("%d\n",num);
                }
                else
                {
                    printf("Invalid\n");
                }
                break;
            }
        }
    }
    return 0;
}