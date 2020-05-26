#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
 
int main(){
	int n, num[100010];
	scanf("%d", &n);
	int count = 0, re = n;
    int tmp;
	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
        num[tmp]=i;
		if (i > 0 && num[i] == i)
			re--;
	}
	int i = 1;
	while (re > 1){
		if (num[0] == 0){
			for (; i < n; i++){
				if (num[i] != i){
					swap(num[0], num[i]);
					count++;
					break;
				}
			}
		}
        swap(num[0],num[num[0]]);
        re--;
        count++;
	}
	printf("%d", count);
	return 0;
}