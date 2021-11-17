#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll,ll>
#define vii vector<pii>
#define vvii vector<vii>
#define fi first
#define se second

/**
ifstream input("input.txt");
ofstream output("output.txt");

#define cin input
#define cout output
**/

long long smaltisci(int n, int m, vector<int> in, vector<vector<int>> out){
    vi dp(n,-1);
    vvii ant(n); //(vertice anterior, # de apariciones)
    vi finales;
    vi charge(m); //numero de siguientes que falta calcular para añadir vértice

    for (ll i=0;i<m;i++){
        charge[i]=out[i].size();

        if (out[i].size()==0) finales.push_back(in[i]);

        for (ll x:out[i]){
            if (ant[x].size()==0 || ant[x][ant[x].size()-1].fi!=i) ant[x].push_back(pii{i,1});
            else ant[x][ant[x].size()-1].se++;
        }
    }


    priority_queue<pii> cola;
    
    for (ll x:finales) cola.push(pii{-1,x});

    while (cola.size()){
        pii x=cola.top();
        cola.pop();
        
        //cerr <<x.fi << ' ' << x.se << '\n';

        if (dp[x.se]==-1){
            dp[x.se]=-x.fi;

            for (pii w:ant[x.se]){
                charge[w.fi]-=w.se;

                if (charge[w.fi]==0){ //ya hemos calculado todos sus sucesores
                    ll res=0;
                    for (ll y:out[w.fi]) res+=dp[y];
                    cola.push(pii{-res-1,in[w.fi]});
                }
            }
        }
    }

    return dp[0];
}
/**
int main() {
  int N, M;

  cin >> N >> M;

  vector<int> A(M), K(M);
  vector<vector<int>> B(M);

  for (int i = 0; i < M; i++) {
    cin >> A[i] >> K[i];

    B[i].resize(K[i]);
    for (int j = 0; j < K[i]; j++) {
      cin >> B[i][j];
    }
  }

  cout << smaltisci(N, M, A, B) << "\n";
}
**/

