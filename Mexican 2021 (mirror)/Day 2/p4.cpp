#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second

const int INF=1000000001;

vi arreglartramo(int a, vi v, int b){
	int n=v.size();
	if (b-a-1<n) return vi{};

	for (int i=0;i<n;i++) v[i]-=i+1;
	b-=n+1;

	//buscamos la lis

	vii res(1,pii{a,-1}); //menor maximo con i numeros
	vi ant(n);

	for (int i=0;i<n;i++){
		pii x=pii{v[i],i};
		if (x.fi<a || x.fi>b) continue;
		//if (x>=res[minim]){
		//	res[minim]=x;
		//	continue;
		//}
		int l=0;
		int r=res.size();
		while (l!=r-1){
			int med=(l+r)/2;
			if (x>=res[med]) l=med;
			else r=med;
		}
		ant[i]=res[l].se;
		if (l==res.size()-1) res.push_back(pii{0,0});
		res[l+1]=x;
	}

	vb sequeda(n,false);

	int ac=res[res.size()-1].se;

	while (ac!=-1){
		sequeda[ac]=true;
		ac=ant[ac];
	}

	vi sol(n+1);
	sol[0]=a;
	for (int i=0;i<n;i++){
		if (sequeda[i]) sol[i+1]=v[i]+i+1;
		else sol[i+1]=sol[i]+1;
	}
	
	return sol;
}

signed main(){
	int n,k;
	cin >> n >> k;
	vi v(n);
	for (int i=0;i<n;i++) cin >> v[i];
	vb sequeda(n,false);
	for (int i=0;i<k;i++){
		int x;
		cin >> x;
		sequeda[x-1]=true;
	}
	int ant=-1;
	vi demomento;
	vi res;
	for (int i=0;i<n;i++){
		if (sequeda[i]){
			for (int x:arreglartramo(ant,demomento,v[i])) res.push_back(x);
			demomento=vi(0);
			ant=v[i];
		}
		else demomento.push_back(v[i]);
	}
	for (int x:arreglartramo(ant,demomento,INF)) res.push_back(x);
	if (res.size()!=n+1) cout << "-1\n";
	else{
		for (int i=0;i<n;i++) cout << res[i+1] << ' ';
		cout << '\n';
	}
}