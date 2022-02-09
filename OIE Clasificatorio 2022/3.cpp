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
        //cerr << "-----------\n";
        int n;
        cin >> n;
        vi v(n);
        for (int i=0;i<n;i++) cin >> v[i];

        vi dpizqsub(n,0);
        vi dpizqbaj(n,0);

        for (int i=1;i<n;i++){
            if (v[i]>v[i-1]){
                dpizqsub[i]=dpizqsub[i-1];
                dpizqbaj[i]=dpizqbaj[i-1]+1;
            }
            if (v[i]<v[i-1]){
                dpizqsub[i]=dpizqsub[i-1]+1;
                dpizqbaj[i]=dpizqbaj[i-1];
            }
            if (v[i]==v[i-1]){
                dpizqsub[i]=dpizqsub[i-1];
                dpizqbaj[i]=dpizqbaj[i-1];
            }
        }

        vi dpdersub(n,0);
        vi dpderbaj(n,0);

        for (int i=n-2;i>=0;i--){
            if (v[i]>v[i+1]){
                dpdersub[i]=dpdersub[i+1];
                dpderbaj[i]=dpderbaj[i+1]+1;
            }
            if (v[i]<v[i+1]){
                dpdersub[i]=dpdersub[i+1]+1;
                dpderbaj[i]=dpderbaj[i+1];
            }
            if (v[i]==v[i+1]){
                dpdersub[i]=dpdersub[i+1];
                dpderbaj[i]=dpderbaj[i+1];
            }
        }

        int res=1000000000;
        for (int i=0;i<n;i++) res=min(res,min(dpizqsub[i]+dpdersub[i],dpizqbaj[i]+dpderbaj[i]));
        //for (int i=0;i<n;i++) cerr << dpizqsub[i] << ' ' << dpdersub[i] << ' ' << dpizqbaj[i] << ' ' << dpderbaj[i] << '\n';

        cout << res << '\n';
    }
    
}