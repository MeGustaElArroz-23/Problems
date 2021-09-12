#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

signed main(){
    int n,m,k;
    cin >> n >> m >> k;
    vi iniciales(k);
    for (int i=0;i<k;i++) cin >> iniciales[i];
    for (int i=0;i<k;i++) iniciales[i]--;
    vvi conexiones(n);
    while (m--){
        int a,b;
        cin >> a >> b;
        conexiones[a-1].push_back(b-1);
    }
    //MÍNIMO
    vb infectadas(n,false);
    for (int x:iniciales){
        infectadas[x]=true;
        for (int y:conexiones[x]) infectadas[y]=true;
    }
    int res=0;
    for (bool x:infectadas) res+=x;
    cout << res << ' ';
    //MÁXIMO
    infectadas=vb(n,false);
    queue<int> cola;
    for (int x:iniciales) cola.push(x);
    while (cola.size()){
        int x=cola.front();
        cola.pop();
        if (!infectadas[x]){
            infectadas[x]=1;
            for (int y:conexiones[x]) cola.push(y);
        }
    }
    res=0;
    for (bool x:infectadas) res+=x;
    cout << res << '\n';
}