#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

//ifstream input("input.txt");
//ofstream output("output.txt");

//#define cin input
//#define cout output

void debug(vi v){
    for (int x:v) cerr << x << ' ';
    cerr << '\n';
}

int pulisci(int n, int m, vector<string> mapa){
    vi x(n,0);
    vi y(m,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (mapa[i][j]=='1'){
                x[i]++;
                y[j]++;
            }
        }
    }
    int count=n+m;
    int resn=n;
    int resm=m;

    //debug(x);
    //debug(y);

    while ((count--) && (min(resn,resm)>0)){
        for (int i=0;i<n;i++){
            if (x[i]==-1) continue;
            if (x[i]==0){
                x[i]=-1;
                resn--;
            }
            if (x[i]==resm){
                x[i]=-1;
                resn--;
                for (int j=0;j<m;j++) if (y[j]!=-1) y[j]--;
            }
        }

        for (int i=0;i<m;i++){
            if (y[i]==-1) continue;
            if (y[i]==0){
                y[i]=-1;
                resm--;
            }
            if (y[i]==resn){
                y[i]=-1;
                resm--;
                for (int j=0;j<n;j++) if (x[j]!=-1) x[j]--;
            }
        }
    }

    return resn*resm;
}

