#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define vvii vector<vii>
#define fi first
#define se second
#define vb vector<bool>
#define vvb vector<vb>
/**
ifstream inp("in");
ofstream out("out");

#define cin inp
#define cout out
**/
bool solve(int n, int m, vvi v){
    //vvii pos(n, vi(m,-1));
    //cerr << "--------------------\n";

    for (int i=0;i<n;i++){ //check everyone is contiguous O(n^3)
        int lastseen=-1;
        for (int j=0;j<m;j++){
            for (int x:v[j]){
                if (x==i){
                    if (lastseen==-1 || lastseen==j-1 || lastseen==j) lastseen=j;
                    else return 0;
                }
            }
        }
    }

    //cerr << "First check passed\n";

    vvb isinside(n,vb(n,0));
    vvb isnotinside(n,vb(n,0));
    vvb isunder(n,vb(n,0));
    //vvb isseparate(n,vb(n,0));

    for (int a=0;a<n;a++){ //compute all the vvb O(n^3*m)
        for (int b=a+1;b<n;b++){
            for (int i=0;i<m;i++){
                string order="";
                for (int x:v[i]){
                    if (x==a) order.push_back('a');
                    if (x==b) order.push_back('b');
                }
                if (order=="abab" || order=="baba") return 0;
                if (order=="") continue;
                if (order=="aa") isnotinside[a][b]=1;
                if (order=="bb") isnotinside[b][a]=1;
                if (order=="aabb") isunder[a][b]=1;
                if (order=="bbaa") isunder[b][a]=1;
                if (order=="abba") isinside[b][a]=1;
                if (order=="baab") isinside[a][b]=1;
            }
        }
    }

    for (int a=0;a<n;a++){ //final comprovation
        for (int b=a+1;b<n;b++){
            if (isunder[a][b] && isunder[b][a]) return 0;
            if (isunder[a][b] && isinside[b][a]) return 0;
            if (isunder[a][b] && isinside[a][b]) return 0;

            if (isunder[b][a] && isinside[b][a]) return 0;
            if (isunder[b][a] && isinside[a][b]) return 0;

            if (isnotinside[a][b] && isinside[a][b]) return  0;
            if (isnotinside[b][a] && isinside[b][a]) return  0;

            if (isinside[a][b] && isinside[b][a]) return 0;
        }
    }
    return 1;
}

signed main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int m;
        cin >> m;
        vvi v(m);
        for (int i=0;i<m;i++){
            int k;
            cin >> k;
            while (k--){
                int x;
                cin >> x;
                v[i].push_back(x-1);
            }
        }
        if (solve(n,m,v)) cout << "YES\n";
        else cout << "NO\n";
    }
}