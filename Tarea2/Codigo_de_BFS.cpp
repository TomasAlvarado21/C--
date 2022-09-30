#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
	int n, m;
	cin >> n >> m;
	vector <vector <int>> grafo(n); // Lista de adyacencia: n vectores, uno con los vecinos de cada nodo
	
	for(int i=0; i<m; i++){ // Ciclo para leer las aristas
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b); // Agregamos a b como vecino de a
		grafo[b].push_back(a); // Si la arista es dirigida (de a->b pero no de b->a) comentamos esta linea
	}

	int INF = 1e9; // Lo importante del infinito que usen es que sea mayor a cualquier número del problema, debe ser mayor a todo

	vector <int> dist(n, INF); // Si algo está visitado, guardamos su distancia. Si no, infinito. Inicialmente nada está visitado.
	queue <int> cola; // Cola que usaremos para recorrer los nodos en el orden de BFS
	// Usaremos el cero como nodo inicial (pero podría ser cualquiera). La distancia a si mismo es cero y lo agregamos a la cola.
	dist[0] = 0;
	cola.push(0);

	while(!cola.empty()){ // Mientras la cola no esté vacía, iteramos
		int u = cola.front(); // Sacamos el nodo actual, el primero de la cola
		cola.pop(); // con pop quitamos u de la cola
		for(int v : grafo[u]){ // Recorremos a los vecinos "v" de "u" (arista u->v)
			if(dist[v] == INF){ // Si no está visitado, lo agregamos a la cola
				dist[v] = dist[u]+1; // La distancia será la distancia a "u" más 1
				cola.push(v);
			}
		}
	}
	for(int i=0; i<n; i++){
		if(dist[i] < INF)
			cout << "La distancia a " << i << " es " << dist[i] << endl;
		else
			cout << "No hay camino desde cero hasta " << i << endl;
	}
	
	return 0;
}
