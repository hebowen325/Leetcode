#include<iostream>
using namespace std;
int preorder[50001];
int inorder[50001];
int find_ans(int preleft,int preright,int inleft,int inright)
{
    if(preleft==preright)
    {
        return preorder[preleft];
    }
    int count;
    for(count=inleft;inorder[count]!=preorder[preleft];count++);
    if(count>inleft)
    {
        return find_ans(preleft+1,preleft+1+count-1-inleft,inleft,count-1);
    }
    else
    {
        return find_ans(preleft+1,preright,inleft+1,inright);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",preorder+i);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",inorder+i);
    }
    printf("%d",find_ans(0,N-1,0,N-1));
    return 0;
}