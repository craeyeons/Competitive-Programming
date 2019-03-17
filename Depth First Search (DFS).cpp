#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> dist;
vector<int> par;
stack<pair<int,int>> o;

void dfs(int s, vector<vector<pair<ll,ll>>> adj){
	for(auto x: adj[s]){
		if (par[x.first] == -1) {
			o.push({x.first,x.second});
			par[x.first] = s; dist[x.first] = (dist[s] + x.second);
		}
	}
	while(!o.empty()){
		int cur = o.top().first;
		o.pop();
		dfs(cur, adj);
	}
}

int main(){
	int n, m, u, v, l;
	cin >> n >> m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	dist.assign(n+1, ll(1e18));
	par.assign(n+1, -1);

	for(int i = 0; i < m; i++){
		cin >> u >> v >> l;
		adj[u].push_back({v,l});
		adj[v].push_back({u,l});
	}

	int s;
	cin >> s;
	par[s] = 0;
	dist[s] = 0;

	dfs(s, adj);
}
