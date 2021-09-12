#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb libres
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

ifstream in("6.in");
ofstream out("6.out");

void solve(){
    int n,m;
    cin >> n >> m;
    vvi v(n,vi(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cin >> v[i][j];
        random_shuffle(v[i].begin(),v[i].end());
    }
    
    int intentos=50000000/(n*m);
    if (m==10000){
        vvi sol(n);
        for (int i=0;i<10;i++){
            intentos=(int) 40000000/(n*m);
            vii parejas;
            for (int j=0;j<n;j++){
                for (int k=0;k<1000;k++){
                    //cerr << k <<' '<< k+1000*i<<'\n';
                    parejas.push_back(pii{j,v[j][k+1000*i]});
                }
            }
            while (intentos--){
                //cerr<<intentos<<'\n';
                random_shuffle(parejas.begin(),parejas.end());
                vii res;
                vii newparejas;
                vb filaslibres(n,true);
                vb numeroslibres(n+1,true);
                for (pii x:parejas){
                    if (filaslibres[x.fi] && numeroslibres[x.se]){
                        filaslibres[x.fi]=0;
                        numeroslibres[x.se]=0;
                        res.push_back(x);
                    }
                    else newparejas.push_back(x);
                }
                if (res.size()==n){
                    for (pii x:res){
                        sol[x.fi].push_back(x.se);
                    }
                    parejas=newparejas;
                }
            }
            for (pii x:parejas){
                sol[x.fi].push_back(x.se);
            }

        }
        
        for (int i=0;i<n;i++){
            for (int x:sol[i]) cout << x << ' ';
            cout << '\n';
        }
        return;
    }
    
    vii parejas;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) parejas.push_back(pii{i,v[i][j]});
    }

    vvi sol(n);


    while (intentos--){
        random_shuffle(parejas.begin(),parejas.end());
        vii res;
        vii newparejas;
        vb filaslibres(n,true);
        vb numeroslibres(n+1,true);
        for (pii x:parejas){
            if (filaslibres[x.fi] && numeroslibres[x.se]){
                filaslibres[x.fi]=0;
                numeroslibres[x.se]=0;
                res.push_back(x);
            }
            else newparejas.push_back(x);
        }
        if (res.size()==n){
            for (pii x:res){
                sol[x.fi].push_back(x.se);
            }
            parejas=newparejas;
        }
    }
    for (pii x:parejas){
        sol[x.fi].push_back(x.se);
    }

    for (int i=0;i<n;i++){
        for (int x:sol[i]) cout << x << ' ';
        cout << '\n';
    }
}

signed main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
