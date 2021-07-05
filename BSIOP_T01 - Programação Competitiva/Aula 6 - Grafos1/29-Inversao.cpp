//Link da questao
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1550
#include<bits/stdc++.h>
using namespace std; 
typedef vector<vector<int>> graph;

int reverse(int x){
    int rev = 0;
    while(x){
        rev = rev*10 + x%10;
        x/=10;
    }
    return rev;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        unordered_map<int,int> distance;
        queue<int> q;
        int a, b; scanf("%d%d",&a,&b);

        distance[a] = 0;
        q.emplace(a);
        int ans = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            int dist = distance[x];

            int x1 = x + 1;
            int x2 = reverse(x);
            if(x1 == b || x2 == b){
                ans = dist+1;
                break;
            }
            if(!distance.count(x1)){
                q.emplace(x1);
                distance[x1] = dist + 1;
            }
            if(!distance.count(x2)){
                q.emplace(x2);
                distance[x2] = dist + 1;
            }
        }
        printf("%d\n",ans);
    }
}