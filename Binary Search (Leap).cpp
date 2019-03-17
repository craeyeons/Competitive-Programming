#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, tar;
    cin >> n >> tar;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int pos = 0;
    for(int add = n/2; add >= 1; add/=2){
        if(pos+add < n && arr[pos+add] <= tar) pos += add;
    }

    if (arr[pos] == tar){
        //
    }
}
