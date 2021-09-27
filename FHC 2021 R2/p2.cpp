#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define pii pair<int,int>
#define vii vector<pii>
#define vvii vector<vii>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second

ifstream in("input.txt");
ofstream out("output.txt");

int pot2(int x){
    return 1<<x;
}

void debug(vi v){
    for (int x:v) cerr << x << ' ';
    cerr<<'\n';
}
void debug(vvi v){
    for (vi x:v) debug(x);
    cerr<<'\n';
}

struct lca{
    int n;
    vvi hijos;
    vvi subir;

    vi camino;
    vi prof;

    stack<pii> st;

    void recurs(pii x){
        if (x.se==1){
            int ac=x.fi;
            camino.push_back(ac);
            prof[ac]=camino.size();
            for (int i=0;i<subir[ac].size();i++){
                subir[ac][i]=camino[max((int)0,(int)camino.size()-pot2(i)-1)];
            }
            st.push(pii{ac,0});
            for (int y:hijos[ac]) st.push(pii{y,1});
        }
        else camino.pop_back();
    }

    void recursion(){
        st.push(pii{0,1});
        while (st.size()){
            pii x=st.top();
            st.pop();
            recurs(x);
        }
    }

    lca(vvi v){
        n=v.size();
        hijos=v;
        subir=vvi(n,vi((int) log2(2*n)));
        prof=vi(n);

        ////////cerr<<"f";

        recursion();
    }

    int ancestor(int a, int b){
        ////cerr << "," << a << ' ' <<b<<'\n';
        if (prof[a]<prof[b]) swap(a,b);
        //int x=a;
        //int y=b;
        for (int i=subir[0].size()-1;i>=0;i--){
            if (prof[a]-prof[b]>pot2(i)) a=subir[a][i];
        }
        if (prof[a]!=prof[b]) a=subir[a][0];

        for (int i=subir[0].size()-1;i>=0;i--){
            if (subir[a][i]!=subir[b][i]){
                a=subir[a][i];
                b=subir[b][i];
            }
        }
        if (a!=b) {
            a=subir[a][0];
            b=subir[b][0];
        }
        return a;
    }

};

vvi conexiones;

vvi hijos;

void dfs(){
    queue<pii> cola;
    cola.push(pii{0,-1});
    while(cola.size()){
        int x=cola.front().fi;
        int ant=cola.front().se;
        cola.pop();
        for (int y:conexiones[x]){
            if (y==ant) continue;
            
            hijos[x].push_back(y);
            cola.push(pii{y,x});
        }
    }
}

vi arriba;

int res;

void dfs2(){
    stack<pii> st;
    st.push(pii{0,1});
    while(st.size()){
        pii x=st.top();
        st.pop();
        
        if (x.se==1){
            st.push( pii(x.fi,0) );
            for(int y:hijos[x.fi]) st.push(pii{y,1});
        }
        else {
            for (int y:hijos[x.fi]) arriba[x.fi]=max(arriba[x.fi],arriba[y]-1);
            res+=(arriba[x.fi]==0);
        }
    }
}

signed main(){
    int t;
    in >> t;
    ////////cerr << t << '\n';
    for (int caso=1;caso<=t;caso++){
        //cerr<<"------------------------\n";
        ////////cerr << "-\n" ;
        int n;
        in >> n;
        //cerr<<n<<'\n';

        arriba=vi(n,0);
        res=0;

        ////////cerr<<"b";

        conexiones=vvi(n);
        ////////cerr << n << '\n';
        for (int i=0;i<n-1;i++){
            int a,b;
            in >> a >> b;
            ////////cerr << a << ' ' << b << '\n';
            conexiones[a-1].push_back(b-1);
            conexiones[b-1].push_back(a-1);
        }
        ////////cerr<<"z";

        hijos=vvi(n);
        dfs();
        //debug(hijos);

        vvi id(n);
        for (int i=0;i<n;i++){
            int x;
            in >> x;
            id[x-1].push_back(i);
        }

        //debug(hijos);
        lca xd(hijos);
        //////cerr<<"a";

        ////cerr << "-\n";
        //(id);
        ////cerr<<"-\n";

        //debug(id);

        for (int i=0;i<n;i++){
            ////cerr <<"a";
            if (id[i].size()==0) continue;
            ////cerr <<"e";
            int sol=id[i][0];
            ////cerr <<"i";
            for (int j=1;j<id[i].size();j++){
                ////cerr << '\n'<<i<<' ' << j <<'\n';
                sol=xd.ancestor(sol,id[i][j]);
            }
            ////cerr <<"o";
            ////cerr << sol << ' ';
            for (int x:id[i]) arriba[x]=xd.prof[x]-xd.prof[sol];
            ////cerr <<"u";
        }
        //debug(arriba);
        ////cerr<<'\n';
        //debug(arriba);
        ////cerr<<"h";

        dfs2();

        out <<"Case #" << caso << ": "<< res-1 << '\n';
    }
}