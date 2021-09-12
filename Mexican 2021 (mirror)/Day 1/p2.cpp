#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

const int mod=1000000007;

const int max_k=1000001;

signed main(){
    vii par(max_k);
    par[1]=pii{1,0};
    par[2]=pii{0,1};
    for (int i=3;i<max_k;i++) par[i]=pii{(par[i-1].fi+par[i-2].fi)%mod,(par[i-1].se+par[i-2].se)%mod};

    int q;
    cin >> q;
    while (q--){
        int a,b,k;
        cin >> a >> b >> k;
        cout << (a*par[k].fi+b*par[k].se)%mod<<'\n';
    }
}