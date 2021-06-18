//Link da questao
//https://neps.academy/br/exercise/255
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    vector<int> v(n); for(int &x : v)scanf("%d",&x);
    int sum; scanf("%d",&sum);
    int a, b;
    for(int x : v){
        if(binary_search(v.begin(),v.end(),sum-x)){
            a = x, b = sum-x;
            break;
        }
    }
    printf("%d %d\n",a,b);
}