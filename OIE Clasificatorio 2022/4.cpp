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
/**
ifstream inp("inp");
ofstream out("out");

#define cin inp
#define cout out
**/
int forma1(int n, int m, vvi v){
    pii centro={-1,-1};
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (v[i][j]!=0){
                centro=pii{i,j};
            }
        }
    }

    if (centro==pii{-1,-1}) return 0;

    vvi activado(n,vi(m,0));
    queue<pii> cola;
    cola.push(centro);

    while (cola.size()){
        pii x=cola.front();
        cola.pop();
        
        if (x.fi<0 || x.se<0 || x.fi>=n || x.se>=m || activado[x.fi][x.se] || v[x.fi][x.se]==0) continue;

        activado[x.fi][x.se]=1;

        if ((x.fi+x.se)%2==0){
            cola.push(pii{x.fi+1,x.se+1});
            cola.push(pii{x.fi+1,x.se});
            cola.push(pii{x.fi,x.se+1});
            cola.push(pii{x.fi-1,x.se-1});
            cola.push(pii{x.fi-1,x.se});
            cola.push(pii{x.fi,x.se-1});
        }
        else{
            cola.push(pii{x.fi+1,x.se-1});
            cola.push(pii{x.fi+1,x.se});
            cola.push(pii{x.fi,x.se+1});
            cola.push(pii{x.fi-1,x.se+1});
            cola.push(pii{x.fi-1,x.se});
            cola.push(pii{x.fi,x.se-1});
        }
    }

    int res=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (v[i][j]!=0 && !activado[i][j]){
                return -1;
            }
            
            if (v[i][j]==1 && (i+j)%2==0) res++;
            if (v[i][j]==2 && (i+j)%2==1) res++;
        }
    }

    return res;
}

int forma2(int n, int m, vvi v){
    //cerr << "------------\n";
    pii centro={-1,-1};
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (v[i][j]!=0){
                centro=pii{i,j};
            }
        }
    }

    if (centro==pii{-1,-1}) return 0;

    vvi activado(n,vi(m,0));
    queue<pii> cola;
    cola.push(centro);

    while (cola.size()){
        pii x=cola.front();
        cola.pop();
        
        if (x.fi<0 || x.se<0 || x.fi>=n || x.se>=m || activado[x.fi][x.se] || v[x.fi][x.se]==0) continue;

        //cerr << x.fi << ' ' << x.se << '\n';

        activado[x.fi][x.se]=1;

        if ((x.fi+x.se)%2==1){
            cola.push(pii{x.fi+1,x.se+1});
            cola.push(pii{x.fi+1,x.se});
            cola.push(pii{x.fi,x.se+1});
            cola.push(pii{x.fi-1,x.se-1});
            cola.push(pii{x.fi-1,x.se});
            cola.push(pii{x.fi,x.se-1});
        }
        else{
            cola.push(pii{x.fi+1,x.se-1});
            cola.push(pii{x.fi+1,x.se});
            cola.push(pii{x.fi,x.se+1});
            cola.push(pii{x.fi-1,x.se+1});
            cola.push(pii{x.fi-1,x.se});
            cola.push(pii{x.fi,x.se-1});
        }
    }

    int res=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (v[i][j]!=0 && !activado[i][j]){
                return -1;
            }
            
            if (v[i][j]==2 && (i+j)%2==0) res++;
            if (v[i][j]==1 && (i+j)%2==1) res++;
        }
    }

    return res;
}

signed main(){
    int t;
    cin >> t;
    while (t--){
        //cerr << "------------------------\n";
        int n,m;
        cin >> n >> m;
        vvi v(n,vi(m));

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin >> v[i][j];
                if (v[i][j]==0) v[i][j]=2;
                else if (v[i][j]==2) v[i][j]=0;
            }
        }

        int a=forma1(n,m,v);
        int b=forma2(n,m,v);

        if (a==-1) cout << b << '\n';
        else if (b==-1) cout << a << '\n';
        else cout <<min(a,b) << '\n';

        //cerr << forma1(n,m,v) << ' ' << forma2(n,m,v) << '\n';

        //cout << min(forma1(n,m,v),forma2(n,m,v)) << '\n';

    }
}