#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second
/**
ifstream inp("in");
ofstream out("out");

#define cin inp
#define cout out
**/
signed main(){
    int n;
    cin >> n;
    vi v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    //for (int i=0;i<n;i++) v[i]--;

    vi ind(n+1);
    for (int i=0;i<n;i++) ind[v[i]]=i;

    vvi addHI(n+1);
    vvi remHI(n+1);
    vvi addLO(n+1);
    vvi remLO(n+1);

    //calc LO

    vi incr;
    incr.push_back(ind[1]);
    addLO[1].push_back(ind[1]);

    for (int i=2;i<=n;i++){
        while (incr.size() && incr[incr.size()-1]>ind[i]){
            remLO[i].push_back(incr[incr.size()-1]);
            incr.pop_back();
        }
        addLO[i].push_back(ind[i]);
        incr.push_back(ind[i]);

    }

    //calc HI

    incr=vi(0);
    incr.push_back(ind[n]);
    remHI[n].push_back(ind[n]);

    for (int i=n-1;i>=1;i--){
        while (incr.size() && incr[incr.size()-1]>ind[i]){
            addHI[i].push_back(incr[incr.size()-1]);
            incr.pop_back();
        }
        remHI[i].push_back(ind[i]);
        incr.push_back(ind[i]);

    }

    //solve

    set<pair<int,string>> ac;
    for (int x:incr) ac.insert(pair<int,string>{x,"HI"});

    cout << "0\n";

    int res=0;

    for (int i=1;i<=n;i++){

        //cerr << "a";

        for (int x:addHI[i]){
            ac.insert(pair<int,string>{x,"HI"});
            auto it=ac.find(pair<int,string>{x,"HI"});
            if (it==ac.begin()){
                it++;
                if (it!=ac.end() && (*it).se=="LO") res++;
            }
            else{
                it--;
                if ((*it).se=="LO"){
                    it++;it++;
                    if (it!=ac.end() && (*it).se=="LO") res++;
                }
            }
        }

        //cerr << "b";

        for (int x:remHI[i]){
            auto it=ac.find(pair<int,string>{x,"HI"});
            if (it==ac.begin()){
                it++;
                if (it!=ac.end() && (*it).se=="LO") res--;
            }
            else{
                it--;
                if ((*it).se=="LO"){
                    it++;it++;
                    if (it!=ac.end() && (*it).se=="LO") res--;
                }
            }
            ac.erase(pair<int,string>{x,"HI"});
        }

        //cerr << "c";

        for (int x:addLO[i]){
            ac.insert(pair<int,string>{x,"LO"});
            auto it=ac.find(pair<int,string>{x,"LO"});
            if (it==ac.begin()){
                continue;
            }
            else{
                it++;
                if (it==ac.end() || (*it).se=="HI"){
                    it--;it--;
                    if ((*it).se=="HI") res++;
                }
            }
        }

        //cerr << "d";

        for (int x:remLO[i]){
            auto it=ac.find(pair<int,string>{x,"LO"});
            if (it==ac.begin()){
                ;
            }
            else{
                it++;
                if (it==ac.end() || (*it).se=="HI"){
                    it--;it--;
                    if ((*it).se=="HI") res--;
                }
            }
            ac.erase(pair<int,string>{x,"LO"});
        }

        cout << res << '\n';
    }
}