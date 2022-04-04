#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



vector <vector <int>> grafo; // Declaramos el vector global para usarlo en la función
vector <bool> visitado; // Lo mismo con este
//vector <int> lista;
void dfs(int u){
	// u es el nodo actual
	visitado[u] = true;
	for(int v : grafo[u]){ // Iteramos sobre los vecinos "v" de "u" (es un for tipo python)
		if(!visitado[v]){
			// Si v no está visitado, llamamos DFS recursivamente sobre él
			dfs(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	/* El input consiste en n (numero de nodos) y m (numero de aristas), seguido de
	 * una linea por arista
	 *
	 * Formato:
	 * n m
	 * a b
	 * c d
	 * e f
	 * ...etc
	 * (a,b,c,d,e,f son nodos y cada línea indica una conexión entre ellos)
	 * Asumimos que los nodos están indexados desde cero, o sea están en [0, n-1]
	 */
	int n, m, e;
	cin >> n >> m;
	grafo.resize(n); // Cambiamos el tamaño a n
	
	
	
	
	for(int i=0; i<n-1; i++){ // Ciclo para leer las aristas

		int a;
		cin >> a;
		grafo[i].push_back(i+a); // Agregamos a b como vecino de a
		
		//grafo[b].push_back(a); // Si la arista es dirigida (de a->b pero no de b->a) comentamos esta linea
	}

	visitado.assign(n, false); // Assign es como resize pero también recibe el valor inicial

	dfs(0); // Llamamos a DFS desde el nodo cero
	
	/*for(int i=0; i<n; i++){
		cout << i;
	}*/
	if(visitado[m-1]){
		cout << "YES" << endl;
	} 
	else{
		cout << "NO" << endl;
	} 
	return 0;
}