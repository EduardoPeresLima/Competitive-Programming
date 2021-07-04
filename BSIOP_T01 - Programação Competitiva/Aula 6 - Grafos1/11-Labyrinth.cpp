//Link da questao
//https://cses.fi/problemset/task/1193
#include<bits/stdc++.h>
using namespace std; 
typedef vector<string> graph;
inline void reads(string& x){char kk[1004]; scanf("%s",kk); x = kk;}
int n, m, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool out(int i, int j){
    return i<0 || i>=n || j<0 || j>=m;
}

bool bfs(int i, int j, graph &g, vector<vector<pair<int,int>>> &pai){
    queue<pair<int,int>> q;
    q.emplace(i,j);
    g[i][j] = '#'; //marcar que ja passei
    while(!q.empty()){
        tie(i,j)= q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(out(ni,nj) || g[ni][nj] == '#')continue;
            pai[ni][nj] = {i,j};
            if(g[ni][nj] == 'B')return true;
            g[ni][nj] = '#'; //marcar que ja passei/coloquei na fila
            q.emplace(ni,nj);
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    graph g(n); for(int i=0;i<n;i++)reads(g[i]);
    vector<vector<pair<int,int>>> pai(n,vector<pair<int,int>>(m));

    bool can = true;
    pair<int,int> ini, fim;

    //Salva os pontos inicial e final, e ja verifica na bfs se eh possivel alcancar
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j] == 'A'){
                ini = {i,j};
                can &= bfs(i,j,g, pai);
            } 
            else if(g[i][j] == 'B') fim = {i,j};
        }
    
    if(can){ //Se for possivel alcancar
        printf("YES\n");
        /*
            Recupera resposta a partir do ponto final voltando pro comeco
            Na BFS, foi salvo o "pai" de cada ponto, ou seja, o ponto onde eu estava logo antes de vir para o ponto atual
            Ex: Se na BFS eu fui de {2,3} -> {2,4} -> {3,4}
            Entao pai[2][4] = {2,3} e pai[3][4] = {2,4}
        */
        string ans;
        while(fim != ini){
            pair<int,int> anterior = pai[fim.first][fim.second];
            pair<int,int> delta = {fim.first-anterior.first, fim.second - anterior.second};
            
            if(delta.first) ans += delta.first == 1? 'D':'U';
            else            ans += delta.second == 1?'R':'L';

            fim = anterior;
        }
        //Como a resposta foi recuperada do fim pro comeco, ela estah ao contrario, eh preciso reverter pra ajeitar 
        reverse(ans.begin(),ans.end()); 
        printf("%d\n%s\n",(int)ans.size(),ans.data());
    }
    else printf("NO\n");
}