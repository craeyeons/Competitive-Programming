#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<long long> dist;
vector<int> par;
int n, m;

void bfs(int s, vector<vector<pair<int,int>>> adj){
    ll INF = ll(1e18);
    dist.assign(n+1, INF);
    par.assign(n+1, -1);

    dist[s] = 0; par[s] = -1;
    queue<int> q; q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            if(dist[v] >= INF){
                dist[v] = dist[u] + adj[u][i].second;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    int u, v, l;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> l;
        adj[u].push_back({v,l});
        adj[v].push_back({u,l});
    }

    int s; cin >> s;

    bfs(s, adj);
}
