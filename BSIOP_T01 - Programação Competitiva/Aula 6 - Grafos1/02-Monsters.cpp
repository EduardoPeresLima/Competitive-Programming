//Link da questao
//https://cses.fi/problemset/task/1194
#include<bits/stdc++.h>
using namespace std; 
const int INF = 1e9+7;
typedef vector<string> graph;
inline void reads(string& x){char kk[1004]; scanf("%s",kk); x = kk;}

int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
vector<vector<int>> tMe, tMonster;
vector<vector<pair<int,int>>> pai;
graph g;

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

void bfs(bool isMonster, vector<pair<int,int>> inicio){
    vector<vector<bool>> passei(n,vector<bool>(m));
    queue<pair<int,int>> q;
    int i, j;
    for(pair<int,int> p : inicio){
        tie(i,j) = p;
        q.emplace(i,j);
        passei[i][j] = true;
        if(isMonster)tMonster[i][j] = 0;
        else tMe[i][j] = 0;
    }

    while(!q.empty()){
        tie(i,j) = q.front(); q.pop();
        for(int k=0;k<4;k++){
            int ni = i+dx[k], nj = j+dy[k];
            if(out(ni,nj) || passei[ni][nj] || g[ni][nj] == '#')continue;
            passei[ni][nj] = true;
            q.emplace(ni,nj);

            if(isMonster) tMonster[ni][nj] = tMonster[i][j] + 1;
            else {
                tMe[ni][nj] = tMe[i][j] + 1;
                pai[ni][nj] = {i,j};
            }
        }
    }
}
bool canEndHere(int i, int j){
    return tMe[i][j] != INF && tMe[i][j] < tMonster[i][j];
}
pair<int,int> getEndPos(){
    for(int i=0;i<n;i++){
        if(canEndHere(i,0))return {i,0};
        else if(canEndHere(i,m-1)) return {i,m-1};
    }
    for(int j=0;j<m;j++){
        if(canEndHere(0,j))return{0,j};
        else if(canEndHere(n-1,j))return {n-1,j};
    }
    return {-1,-1};
}
string recover(pair<int,int> ini, pair<int,int> fim){
    string ans;
    pair<int,int> before, delta;
    while(fim != ini){
        before = pai[fim.first][fim.second];
        delta = {fim.first - before.first, fim.second - before.second};
        if(delta.first) ans += delta.first>0?'D':'U';
        else ans += delta.second>0?'R':'L';
        fim = before;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);

    g.resize(n); for(string &s : g)reads(s);
    tMe.assign(n,vector<int>(m,INF));
    tMonster.assign(n,vector<int>(m,INF));
    pai.assign(n,vector<pair<int,int>>(m));

    pair<int,int> ini, fim;
    vector<pair<int,int>> monstersIni;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] == 'A')ini = {i,j};
            else if(g[i][j] == 'M') monstersIni.emplace_back(i,j);
        }
    }
    bfs(false,{ini});
    bfs(true,monstersIni);
    fim = getEndPos();
    if(fim == make_pair(-1,-1))printf("NO\n");
    else{
        printf("YES\n");
        string ans =  recover(ini, fim);
        printf("%d\n%s\n",(int)ans.size(),ans.data());
    }
}