#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second
#define vb vector<bool>

#define piic pair<pii,char>
#define viic vector<piic>

#define piiii pair<pii,pii>
#define viiii vector<piiii>

#define piii pair<pii,int>

viiii zonas;

bool setocan(piiii a, piiii b){
    //cerr<< a.fi.fi<<' '<<a.fi.se<<' '<<a.se.fi<<' '<<a.se.se<<", ";
    //cerr<< b.fi.fi<<' '<<b.fi.se<<' '<<b.se.fi<<' '<<b.se.se<<"\n";
    if (a.fi.fi==b.fi.se+1 && a.se.fi<=b.se.se+1 && a.se.se>=b.se.fi-1) return 1; //arriba
    if (b.fi.fi==a.fi.se+1 && b.se.fi<=a.se.se+1 && b.se.se>=a.se.fi-1) return 1; //abajo

    if (a.se.fi==b.se.se+1 && a.fi.fi<=b.fi.se+1 && a.fi.se>=b.fi.fi-1) return 1; //derecha
    if (b.se.fi==a.se.se+1 && b.fi.fi<=a.fi.se+1 && b.fi.se>=a.fi.fi-1) return 1; //izquierda

    //cerr<<"NO\n";

    return 0;
}

set<piii> l1r2;
set<piii> l2r2;
set<piii> r1l2;
set<piii> r2l2;

vi conectados(piiii x){
    vi res;
    {//derecha
        auto it=r1l2.lower_bound(piii{pii{x.se.se+1,x.fi.fi-1},-1});
        while (it!=r1l2.end() && (*it).fi.fi==x.se.se+1 && zonas[(*it).se].fi.fi<=x.fi.se+1) res.push_back((*it).se),it++;
    }
    {//izquierda
        auto it=r2l2.lower_bound(piii{pii{x.se.fi-1,x.fi.fi-1},-1});
        while (it!=r2l2.end() && (*it).fi.fi==x.se.fi-1 && zonas[(*it).se].fi.fi<=x.fi.se+1) res.push_back((*it).se),it++;
    }
    {//abajo
        auto it=l1r2.lower_bound(piii{pii{x.fi.se+1,x.se.fi-1},-1});
        while (it!=l1r2.end() && (*it).fi.fi==x.fi.se+1 && zonas[(*it).se].se.fi<=x.se.se+1) res.push_back((*it).se),it++;
    }
    {//izquierda
        auto it=l2r2.lower_bound(piii{pii{x.fi.fi-1,x.se.fi-1},-1});
        while (it!=l2r2.end() && (*it).fi.fi==x.fi.fi-1 && zonas[(*it).se].se.fi<=x.se.se+1) res.push_back((*it).se),it++;
    }
    return res;
}

//l1 fi.fi
//l2 fi.se
//r1 se.fi
//r2 se.se

signed main(){//ffcc
    int n,filas,columnas;
    cin >> n >> filas >> columnas;
    zonas=viiii(n);
    for (int i=0;i<n;i++){
        cin >> zonas[i].fi.fi >> zonas[i].se.fi >> zonas[i].fi.se >> zonas[i].se.se;
        l1r2.insert(piii{pii{zonas[i].fi.fi,zonas[i].se.se},i});
        l2r2.insert(piii{pii{zonas[i].fi.se,zonas[i].se.se},i});
        r1l2.insert(piii{pii{zonas[i].se.fi,zonas[i].fi.se},i});
        r2l2.insert(piii{pii{zonas[i].se.se,zonas[i].fi.se},i});
    }
    vb libre(n,true);
    int res=0;

    for (int i=0;i<n;i++){
        if (zonas[i].se.fi!=1) continue;

        //cerr<<i<<'\n';

        queue<int> cola;
        cola.push(i);
        bool T=false;
        while (cola.size()){
            int x=cola.front();
            cola.pop();
            if (libre[x]){
                //cerr<<"x:"<<x<<'\n';
                //cerr<< zonas[x].fi.fi<<' '<<zonas[x].fi.se<<' '<<zonas[x].se.fi<<' '<<zonas[x].se.se<<'\n';
                libre[x]=false;
                if (zonas[x].se.se==columnas) T=true;
                for (int y:conectados(zonas[x])) cola.push(y);
            }
        }
        res+=T;
    }
    cout << res << '\n';
}