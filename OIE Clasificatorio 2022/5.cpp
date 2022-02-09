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

bool ask(vb v){ //distinto
    cout << "? ";
    for (bool x:v){
        if (x) cout << "2 ";
        else cout << "1 ";
    }
    cout << endl;
    char c;
    cin >> c;
    return c=='d';
}

signed main(){
    int n;
    cin >> n;
    int axorb=0;
    int pot=1;
    while (pot<=n){
        vb v(n);
        for (int i=1;i<=n;i++){
            v[i-1]= (i%(2*pot)!=i%pot);
        }
        if (ask(v)) axorb+=pot;
        pot*=2;
    }

    vb canbecan(2*n+1,1);
    vi candidates;
    for (int i=1;i<=n;i++){
        if (canbecan[i]){
            canbecan[i^axorb]=0;
            candidates.push_back(i);
        }
    }

    while (candidates.size()>1){
/**
        cerr << "candidates: ";
        for (int x:candidates) cerr << x << ' ';
        cerr << endl;
**/
        vi group1;
        vi group2;
        for (int i=0;i<candidates.size();i++){
            if (i%2) group1.push_back(candidates[i]);
            else group2.push_back(candidates[i]);
        }
        vb v(n,0);
        for (int x:group2) v[x-1]=1;

        if (ask(v)) candidates=group2;
        else candidates=group1;
    }

    cout << "! " << candidates[0] << ' ' << (candidates[0]^axorb) << endl;   
}