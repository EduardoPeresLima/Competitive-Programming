//Link da questao
//https://neps.academy/br/exercise/548
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    int fim = sqrt(n);
    set<pair<int,int>> ans;
    for(int i=1;i<=fim;i++){
        if((n-1-i)%(2*i + 1)==0){
            int x = i, y = (n-1-i)/(2*i + 1);
            ans.emplace(min(x,y),max(x,y));
        }
    }
    printf("%d\n",(int)ans.size());
}