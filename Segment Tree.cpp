#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegmentTree{
private:
    ll n;
    vector<ll> t;

    ll combine(ll a, ll b){
        return a + b;
    }

    /* --- ADDITIONAL POWER-UPS --- */

    // combine function for storing sorted segments
    void combine(vector<ll>& a, vector<ll>& b, vector<ll>& newV){
        newV.assign(a.size()+b.size(),0);

        merge(a.begin(),a.end(),b.begin(),b.end(),newV.begin());
    }
public: // every thing is 0-indexed, whereas query(k) is 1-indexed
    SegmentTree(vector<ll>& v){          // build tree
        n = v.size();
        t.assign(n << 1, 0);

        for (int i = 0; i < n; i++) t[n+i] = v[i];
        for (int i = n-1; i > 0; i--) t[i] = combine(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, ll val){          // set v[p] = val
        for (t[p+=n] = val; p >>= 1; ) t[p] = combine(t[p<<1],t[p<<1|1]);
    }
    ll query(int l, int r){              // query in range v[l,r)
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l&1) res = combine(res,t[l++]);
            if (r&1) res = combine(res,t[--r]);
        }
        return res;
    }
    ll ncquery(int l, int r){            // query for non-commutative combine function
        ll resl, resr;                   // initialized to be 0
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l&1) resl = combine(resl, t[l++]);
            if (r&1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }

    /* --- ADDITIONAL POWER-UPS --- */

    // query routine minimum prefix sum that is larger or equal to K, 1-indexed
    int query(int k) {
        if (t[1] < k)
            return -1;

        int p = 1;
        while (p < n)
            if (t[p<<=1] < k)
                k -= t[p++];
        return p - n + 1;
    }
};

int main(){

}
