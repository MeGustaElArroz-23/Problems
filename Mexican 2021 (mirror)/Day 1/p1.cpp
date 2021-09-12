#include <bits/stdc++.h>

int N;
int vals[1005];
int preguntas;
bool solved;
const long double xx = 0.25;

void respuesta(int posMenor, int posMayor) {
  int mn = 1, mx = 1;
  for (int i = 2; i <= N; i++) {
    if (vals[i] < vals[mn]) mn = i;
    if (vals[i] > vals[mx]) mx = i;
  }
  if (posMenor != mn) {
    std::cerr << "Posicion " << posMenor << "no contiene al mínimo\n";
    std::cout << "0\n";
    exit(0);
  }
  if (posMayor != mx) {
    std::cerr << "Posicion " << posMenor << "no contiene al maximo\n";
    std::cout << "0\n";
    exit(0);
  }

  // Es correcto, pero calcula puntos
  std::cerr << "Correcto! Tu programa realizo " << preguntas << " preguntas\n";
  std::cerr << "Tu programa obtendría puntos por este caso :)\n";
  exit(0);
}

bool esMenor(int i, int j) {
	std::cerr<<"Has preguntado: "<<i<<' '<<j<<'\n';
  if (i < 1 or i > N) {
    std::cerr << "ERROR: El indice i = " << i
              << " es invalido. No está entre 1 y " << N << "\n";
    std::cout << "0\n";
    exit(0);
  }
  if (j < 1 or j > N) {
    std::cerr << "ERROR: El indice j = " << j
              << " es invalido. No está entre 1 y " << N << "\n";
    std::cout << "0\n";
    exit(0);
  }
  if (i == j) {
    std::cerr << "ERROR: El indice i no puede ser igual al indice j\n";
    std::cout << "0\n";
    exit(0);
  }
  preguntas++;
  if (preguntas > N * N) {
    std::cout << "Preguntas fue llamado más de N^2 veces.\n";
    std::cout << "0\n";
    exit(0);
  }
  return vals[i] < vals[j];
}




#include <bits/stdc++.h>

//#include "extremos.h"

using namespace std;

#define vi vector<int>

void debug(vi v){
	for (int x:v) cerr << x<< ' ';
	cerr << '\n';
}

//bool cmp(int a, int b){return esMenor(a,b);}

void buscaExtremos(int n) {
	if (n==1){
		respuesta(1,1);
		return;
	}
	int m=n/2;
	vi posiblemenor(m);
	vi posiblemayor(m);
	for (int i=0;i<m;i++){
		if (esMenor(2*i+1,2*i+2)){
			posiblemenor[i]=2*i+1;
			posiblemayor[i]=2*i+2;
		}
		else{
			posiblemenor[i]=2*i+2;
			posiblemayor[i]=2*i+1;
		}
	}

	if (n%2){
		posiblemenor.push_back(n);
		posiblemayor.push_back(n);
		m++;
	}

	int menor=posiblemenor[0];
	for (int i=1;i<m;i++){
		if (esMenor(posiblemenor[i],menor)) menor=posiblemenor[i];
	}
	int mayor=posiblemayor[0];
	for (int i=1;i<m;i++){
		if (!esMenor(posiblemayor[i],mayor)) mayor=posiblemayor[i];
	}
	respuesta(menor,mayor);
}








int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) std::cin >> vals[i];

  buscaExtremos(N);
  return 0;
}
