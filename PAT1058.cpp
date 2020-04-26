#include<iostream>
using namespace std;
int main()
{
    int a[3],b[3];
    scanf("%d.%d.%d",a,a+1,a+2);
    scanf("%d.%d.%d",b,b+1,b+2);
    int c[3];
    c[2]=a[2]+b[2];
    c[1]=a[1]+b[1]+c[2]/29;
    c[2]%=29;
    c[0]=a[0]+b[0]+c[1]/17;
    c[1]%=17;
    printf("%d.%d.%d",c[0],c[1],c[2]);
    return 0;
}