#include <bits/stdc++.h>

using namespace std;

int par[111111]; //initialize to -1;, also stores size(negative size);

int rt(int u){
    if(par[u] < 0) return u;
    return(par[u] = rt(par[u])); // path compression
}

void merge(int u, int v){
    u = rt(u); v = rt(v);
    if (u == v) return ;
    if (par[u] > par[v]) swap(u,v); // small to large, take note, negative size
    par[u] += par[v]; par[v] = u;
}

bool query(int u, int v){
    u = rt(u); v = rt(v);
    if(u == v) return true;
    return false;
}

int main(){
    memset(par,-1,sizeof(par));

}
