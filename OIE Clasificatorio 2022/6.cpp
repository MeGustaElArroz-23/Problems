#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define vb vector<bool>
#define fi first
#define se second

#define piiii pair<pii,pii>
#define viiii vector<piiii>
/**
ifstream inp("inp");
ofstream out("out");

#define cin inp
#define cout out
**/
bool estaencima(pii a, pii b, pii p){ //b a la derecha de a
    //cerr << a.fi << ' ' << a.se << ' ' << b.fi << ' ' << b.se << ' ' << p.fi << ' ' << p.se << ' ' << (p.se*(b.fi-a.fi)>a.se*(p.fi-a.fi)+b.se*(b.fi-p.fi)) << '\n';
    return (p.se*(b.fi-a.fi)>a.se*(b.fi-p.fi)+b.se*(p.fi-a.fi));
}

bool cmp(piiii a, piiii b){ //<
    pii a1=a.fi;
    pii a2=a.se;
    pii b1=b.fi;
    pii b2=b.se;

    //comparamos por senos

    if ((a2.se-a1.se)*(b1.fi-b2.fi)>(b2.se-b1.se)*(a1.fi-a2.fi)) return 1;
    if ((a2.se-a1.se)*(b1.fi-b2.fi)<(b2.se-b1.se)*(a1.fi-a2.fi)) return 0;

    //menor x

    if (a1.fi<b1.fi) return 1;
    if (a1.fi>b1.fi) return 0;

    //menor y

    if (a1.se<b1.se) return 1;
    if (a1.se>b1.se) return 0;

    return 0;

    //cerr << a1.fi << ' ' << a1.se << ' ' << b1.fi << ' ' << b1.se << '\n';

}

//arreglar cunado  el punto 0 tienen misma y

signed main(){
    int n;
    cin >> n;
    vii puntos(n);
    for (int i=0;i<n;i++) cin >> puntos[i].fi >> puntos[i].se;

    for (int i=0;i<n;i++) puntos[i].se*=-1;

    sort(puntos.begin(),puntos.end());

    for (int i=0;i<n;i++) puntos[i].se*=-1;

    vii quienlemata(n);

    vii convex;
    convex.push_back(puntos[0]);

    for (int ind=1;ind<n;ind++){
        pii ac=puntos[ind];

        while (convex.size()>1 && !estaencima(convex[convex.size()-2],ac,convex[convex.size()-1])) convex.pop_back();

        quienlemata[ind]=convex[convex.size()-1];
        convex.push_back(ac);
    }

    viiii orden;
    for (int i=1;i<n;i++) orden.push_back(piiii{puntos[i],quienlemata[i]});

    //for (piiii x:orden) cerr << x.fi.fi << ' ' << x.fi.se << ' ' << x.se.fi << ' ' << x.se.se << '\n';

    sort(orden.begin(),orden.end(),cmp);

    for (piiii x:orden) cout << x.fi.fi << ' ' << x.fi.se << '\n';
    //cout << puntos[0].fi << ' ' << puntos[0].se << '\n';
    cout << '\n';
}