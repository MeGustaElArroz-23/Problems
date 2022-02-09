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

        int a,b;
        cin >> a >> b;

        //cout << a*b-a-b << '\n';

        if (a%2==0 || b%2==0) cout << a+b << '\n';
        else cout << max(a,b)-min(a,b) << '\n';
    }
}