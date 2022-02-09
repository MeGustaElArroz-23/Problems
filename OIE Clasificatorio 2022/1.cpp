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
signed main(){
    int t;
    cin >> t;
    while (t--){
        int n1,n2,n3,n4;
        vi v1,v2,v3,v4;
        
        cin >> n1;
        v1=vi(n1);
        for (int i=0;i<n1;i++) cin >> v1[i];

        cin >> n2;
        v2=vi(n2);
        for (int i=0;i<n2;i++) cin >> v2[i];

        cin >> n3;
        v3=vi(n3);
        for (int i=0;i<n3;i++) cin >> v3[i];

        cin >> n4;
        v4=vi(n4);
        for (int i=0;i<n4;i++) cin >> v4[i];

        sort(v1.begin(),v1.end());

        int suma=v1[n1-1];

        vii v;

        for (int x:v2) v.push_back(pii{x,2});
        for (int x:v3) v.push_back(pii{x,1});
        for (int x:v4) v.push_back(pii{x,0});

        sort(v.begin(),v.end());

        int defensas=0, medios=0, delanteros=0;
        for (int i=v.size()-10;i<v.size();i++){
            suma+=v[i].fi;
            if (v[i].se==2) defensas++;
            if (v[i].se==1) medios++;
            if (v[i].se==0) delanteros++;
        }

        cout << suma << ' ' << defensas << '-' << medios << '-' << delanteros << '\n'; 
    }
}