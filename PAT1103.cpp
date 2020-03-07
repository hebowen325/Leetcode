#include<iostream>
#include<vector>
using namespace std;
int N,K,P,sum=0;
vector<int>result,temp;
void DFS(int num,int nowK,int nowSum,int nowPowSum){//DFS递归
    if(nowK>=K||nowPowSum>=N){
        if(nowK==K&&nowPowSum==N&&nowSum>sum){//当前序列的和比result的和大，更新相关信息
            result=temp;
            sum=nowSum;
        }
        return;
    }
    if(num>=1){
        temp.push_back(num);
        DFS(num,nowK+1,nowSum+num,nowPowSum+pow(num*1.0,P*1.0));//选择当前的数
        temp.pop_back();
        DFS(num-1,nowK,nowSum,nowPowSum);//没有选择当前的数，向更小的数进行选择
    }
}
int main(){
    scanf("%d%d%d",&N,&K,&P);
    DFS((int)pow(N*1.0,1.0/P)+1,0,0,0);//从P次根号下N从大到小进行选择
    if(result.size()==K){
        printf("%d = %d^%d",N,result[0],P);
        for(int i=1;i<result.size();++i)
            printf(" + %d^%d",result[i],P);
    }else
        printf("Impossible");
    return 0;
}