#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

#define piic pair<pii,char>
#define viic vector<piic>

set<piic> up;   //U
set<piic> der;  //R
set<piic> izq;  //L
set<piic> down; //D

piic move(piic a){
    int x=a.fi.fi;
    int y=a.fi.se;
    char c=a.se;
    if (c=='U'){
        auto it=up.lower_bound(piic{pii{x,y},'Z'});

        //cerr<<a.fi.fi<<' '<<a.fi.se<<' '<<a.se<<" --> ";
        //cerr<<(*it).fi.fi<<' '<<(*it).fi.se<<' '<<(*it).se<<"\n";

        //it++;
        if (it==up.end() || (*it).fi.fi!=x) return piic{pii{0,0},'X'};
        else return (*it);
    }
    else if (c=='D'){
        auto it=down.lower_bound(piic{pii{x,-y},'Z'});

        //cerr<<a.fi.fi<<' '<<a.fi.se<<' '<<a.se<<" --> ";
        //cerr<<(*it).fi.fi<<' '<<(*it).fi.se<<' '<<(*it).se<<"\n";
        //it++;
        if (it==down.end() || (*it).fi.fi!=x) return piic{pii{0,0},'X'};
        else{
            piic next=(*it);
            return piic{pii{next.fi.fi,-next.fi.se},next.se};
        }
    }
    else if (c=='R'){
        auto it=der.lower_bound(piic{pii{y,x},'Z'});

        //cerr<<a.fi.fi<<' '<<a.fi.se<<' '<<a.se<<" --> ";
        //cerr<<(*it).fi.fi<<' '<<(*it).fi.se<<' '<<(*it).se<<"\n";
        //it++;
        if (it==der.end() || (*it).fi.fi!=y) return piic{pii{0,0},'X'};
        else{
            piic next=(*it);
            return piic{pii{next.fi.se,next.fi.fi},next.se};
        }
    }
    else{
        auto it=izq.lower_bound(piic{pii{y,-x},'Z'});

        //cerr<<a.fi.fi<<' '<<a.fi.se<<' '<<a.se<<" --> ";
        //cerr<<(*it).fi.fi<<' '<<(*it).fi.se<<' '<<(*it).se<<"\n";
        //it++;
        if (it==izq.end() || (*it).fi.fi!=y) return piic{pii{0,0},'X'};
        else{
            piic next=(*it);
            return piic{pii{-next.fi.se,next.fi.fi},next.se};
        }
    }
}

map<piic,int> dp;

int compute(piic ac){
    if (ac==piic{pii{0,0},'X'}) return 0;
    else if (dp[ac]!=0) return dp[ac];
    else{
        ////cerr<<ac.fi.fi<<' '<<ac.fi.se<<' '<<ac.se<<"  "<<move(ac).fi.fi<<' '<<move(ac).fi.se<<' '<<move(ac).se<<'\n';
        dp[ac]=1000000000;
        dp[ac]=compute(move(ac))+1;
        return dp[ac];
    }
}

viic espejos;

signed main(){
    int n,filas,columnas;
    cin >> n >> filas >> columnas;
    for (int i=0;i<n;i++){
        char c;
        int x,y;
        cin >> c >> y >> x;
        espejos.push_back(piic{pii{x,y},c});
        if (c=='/'){
            up.insert(piic{pii{x,y},'R'});
            down.insert(piic{pii{x,-y},'L'});
            der.insert(piic{pii{y,x},'U'});
            izq.insert(piic{pii{y,-x},'D'});
        }
        else{
            up.insert(piic{pii{x,y},'L'});
            down.insert(piic{pii{x,-y},'R'});
            der.insert(piic{pii{y,x},'D'});
            izq.insert(piic{pii{y,-x},'U'});
        }
    }

    int q;
    cin >> q;
    while (q--){
        char c;
        int x,y;
        cin >> c >> y >> x;
        int sol;
        if (c=='N') sol=compute(piic{pii{x,y},'U'});
        if (c=='S') sol=compute(piic{pii{x,y},'D'});
        if (c=='E') sol=compute(piic{pii{x,y},'R'});
        if (c=='O') sol=compute(piic{pii{x,y},'L'});
        if (sol>=1000000000) cout << "-1\n";
        else cout << sol-1<<'\n';
    }
}