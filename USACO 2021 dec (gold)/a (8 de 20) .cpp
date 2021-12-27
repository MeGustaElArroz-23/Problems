#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define vvii vector<vii>
#define fi first
#define se second
#define vb vector<bool>
#define vvb vector<vb>

ifstream inp("in");
ofstream out("out");

#define cin inp
#define cout out

int auxt1(int l, int r, vii &v, int k){
    int men=min(v[l].se,v[r-1].se);
    for (int i=l+1;i<r-1;i++){
        if (v[i+1].fi-v[i-1].fi<=k || (i-l)%2==0) men=min(men,v[i].se);
    }
    return men;
}

int t1(int n, int k, vii v){
    int l=0;
    int res=0;
    for (int i=1;i<n;i++){
        if (v[i].fi-v[i-1].fi <= k) continue;
        else{
            if ((i-l)%2==1) res+=auxt1(l,i,v,k);
            l=i;
        }
    }
    if ((n-l)%2) res+=auxt1(l,n,v,k);
    return res;
}

int t2(int n, int k, vii v){
    v.push_back(pii{2000000002,0});
    vi nextcow(n);
    int ac=0;
    for (int i=0;i<n;i++){
        while (v[ac].fi-v[i].fi<=k) ac++;
        nextcow[i]=ac;
    }
    vi dp(n+1);
    dp[n]=0;

    for (int i=n-1;i>=0;i--){
        dp[i]=max(dp[i+1],dp[nextcow[i]]+v[i].se);
    }
    for (int i=0;i<n;i++) cerr << dp[i] << '\n';

    return dp[0];
}

signed main(){
    int t,n,k;
    cin >> t >> n >> k;
    vii v(n);
    for (int i=0;i<n;i++) cin >> v[i].fi >> v[i].se;

    if (t==1) cout << t1(n,k,v) << '\n';
    else cout << t2(n,k,v) << '\n';
}
