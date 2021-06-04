//Link da questao
//https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; scanf("%d%d", &n,&x);
	map<int,int> has;
	int a = -1, b = -1;
	for(int v,i=1;i<=n;i++){
		scanf("%d",&v);
		if(has[x-v])a = has[x-v], b = i;
		has[v] = i;
	}
	if(a == -1)printf("IMPOSSIBLE\n");
	else printf("%d %d",a,b);
}