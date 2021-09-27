#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define vii vector<pii>
#define vvii vector<vii>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second

#define pib pair<int,bool>

ifstream in("input.txt");
ofstream out("output.txt");

signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int t;
    in >> t;
    for (int caso=1;caso<=t;caso++){
        int q;
        int n;
        in >> q >> n;

        multiset<pib> v;
        for (int i=0;i<n;i++){
            int x;
            in >> x;
            v.insert(pib(x,1));
        }

        int res=0;

        while (q--){
            //cerr << "-\n";
            multiset<pib> newv;
            for (int i=0;i<n;i++){
                int x;
                in >> x;
                auto it=v.find(pib{x,0});
                if (it!=v.end()){
                    newv.insert(pii{x,0});
                    v.erase(it);
                }
                else{
                    it=v.find(pib{x,1});
                    if (it!=v.end()){
                        newv.insert(pii{x,1});
                        v.erase(it);
                    }
                    else{ //no hay nadie con ese numero
                        newv.insert(pib{x,0});
                    }
                }
            }
            for (pib x:v){
                //cerr << x.fi <<' '<<x.se<<'\n';
                res+=(not x.se);
            }
            v=newv;
        }
        out <<"Case #" << caso << ": "<< res << '\n';
    }
}
