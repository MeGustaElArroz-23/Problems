#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

//ifstream input("input.txt");
//ofstream output("output.txt");

//#define cin input
//#define cout output

ll pot2(ll x){
    return ((int) 1) << x;
}

long long riciclo(int n, int m, vector<int> P, vector<int> xd){
    vi w;
    for (int x:xd) w.push_back(x);
    
    vi v(32,0);
    for (ll x:P){
        for (ll i=0;i<32;i++){
            v[i]+=x%2;
            x/=2;
        }
    }
    ll res=0;
    for (ll i=0;i<32;i++){
        ll ac=pot2(i)*v[i];
        for (ll j=0;j<=min(i,(ll)m);j++){
            //cerr << j << '\n';
            if (w[j]*pot2(j)<=ac){
                res+=w[j];
                ac-=w[j]*pot2(j);
                w[j]=0;
            }
            else{
                res+=ac/pot2(j);
                w[j]-=ac/pot2(j);
                break;
            }
        }
    }
    return res;
}

