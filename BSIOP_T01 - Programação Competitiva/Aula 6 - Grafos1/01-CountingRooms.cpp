//Link da questao
//https://cses.fi/problemset/task/1192
#include<bits/stdc++.h>
using namespace std;
inline void reads(string& x){char kk[1003]; scanf("%s",kk); x = kk;}

vector<string> g; 
vector<vector<bool>> passei;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int n, m;

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.emplace(i,j);
    passei[i][j] = true;
    while(!q.empty()){
        i = q.front().first; j = q.front().second;
        q.pop();
        for(int ni,nj,k=0;k<4;k++){
            ni = i+dx[k], nj = j+dy[k];
            if(out(ni,nj) || passei[ni][nj] || g[i][j] == '#')continue;
            q.emplace(ni,nj);
            passei[ni][nj] = true;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    g.assign(n,"");for(int i=0;i<n;i++)reads(g[i]);
    passei.assign(n,vector<bool>(m));

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(passei[i][j] || g[i][j] == '#')continue;
            ans++;
            bfs(i,j);
        }
    }
    printf("%d\n",ans);
}