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

vvi conexiones;
vvi invconexiones;

vb porvisitar;
vi orden;

void recurs(int x){
    if (porvisitar[x]){
        porvisitar[x]=false;
        for (int y:conexiones[x]) recurs(y);
        orden.push_back(x);
    }
}

vvi componentes(){
    int n=conexiones.size();
    porvisitar=vb(n,true);
    
    for (int i=0;i<n;i++) recurs(i);

    porvisitar=vb(n,true);
    vvi comp(n);
    for (int j=n-1;j>=0;j--){
        int i=orden[j];
        queue<int> cola;
        cola.push(i);
        while (cola.size()){
            int x=cola.front();
            cola.pop();
            if (porvisitar[x]){
                porvisitar[x]=false;
                comp[i].push_back(x);
                for (int y:invconexiones[x]) cola.push(y);
            }
        }
    }
    return comp;
}

signed main(){
    int n,m,ind;
    cin >> n >> m >> ind;
    ind--;
    conexiones=vvi(n);
    invconexiones=vvi(n);
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        conexiones[a].push_back(b);
        invconexiones[b].push_back(a);
    }

    //cerr <<1;

    vvi comp=componentes();
    vi indcomp(n);
    for (int i=0;i<n;i++){
        int tamano=comp[i].size();
        for (int x:comp[i]) indcomp[x]=tamano;
    }
    
    //cerr <<1;

    vb contagiado(n,false); //aquellos que cojen el virus
    queue<int> cola;
    cola.push(ind);
    while (cola.size()){
        int x=cola.front();
        cola.pop();
        if (!contagiado[x]){
            contagiado[x]=true;
            for (int y:conexiones[x]) cola.push(y);
        }
    }

    vb megacontagiado(n,false); //aquellos que siguen con el virus aunque se elimine del original
    //queue<int> cola;
    for (int i=0;i<n;i++){
        if (contagiado[i] && indcomp[i]>=2) cola.push(i);
    }
    while (cola.size()){
        int x=cola.front();
        cola.pop();
        if (!megacontagiado[x]){
            megacontagiado[x]=true;
            for (int y:conexiones[x]) cola.push(y);
        }
    }
    

    //Primera pregunta
    if (megacontagiado==vb(n,false)) cout << "B\n";
    else{
        bool S=false;
        for (int i=0;i<n;i++){
            //if (!megacontagiado[i]) continue;
            cerr << i << ' ';
            int count=0;
            for (int y:invconexiones[i]) count+=megacontagiado[y];
            if (count>=2) S=true;
        }
        if (S) cout << "S\n";
        else cout << "G\n";
    }
    //Segunda pregunta
    int res=0;
    for (int i=0;i<n;i++) res+=(contagiado[i] && conexiones[i].size()==0);
    cout << res << ' ';
    //Ter//cera pregunta
    res=0;
    for (int i=0;i<n;i++) res+=(megacontagiado[i] && conexiones[i].size()==0);
    cout << res << '\n';
}