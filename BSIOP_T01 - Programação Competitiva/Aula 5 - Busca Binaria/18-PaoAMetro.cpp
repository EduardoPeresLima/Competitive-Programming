//Famoso pao a metro
//https://neps.academy/br/exercise/605
#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
bool f(int x){
    int cont = 0;
    for(int y : v)cont += y/x;
    return cont >= k;
}

int bb(){
    int lo = 0, hi = 1e9, mid;
    while(lo < hi){   
        mid = lo + ((hi-lo)>>1);
        if(f(mid))lo = mid+1;
        else hi = mid;
    }
    return lo-1;
}

int main(){
    scanf("%d%d",&k,&n);
    v.assign(n,0); for(int &x : v)scanf("%d",&x);
    printf("%d\n",bb());
}