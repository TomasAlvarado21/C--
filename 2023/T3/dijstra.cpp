// hay que encontrar el camino mas corto entre el valor 1 y el n
// hay que tomar en cuenta que uno de los pesos de las aristas se puede dividir en 2 pero solo una vez
// creamos un grafo duplicando del original y conectamos el grafo original con el duplicado
// u puede ir de -> (u,0) y (u,1)
// (u,v,w) -> ((u,0), (v,0), w) o ((u,1), (v,1), w) o ((u,0), (v,1), w/2)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)

int main(){
	int n, m; cin >> n >> m;

	// adj[i] = {{u1, w1}, {u2,w2}, ...} ahora se guarda el peso de la arista también (w)
	vector <vector <pair<int,ll>>> adj(n); 
	for(int i=0; i<m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; // quizá haya que restarle uno si están indexados de uno
		v--;
		adj[u].push_back({v, w}); // arista {u,v} con peso w
		adj[v].push_back({u, w}); // arista {v,u} con peso w
	}

	using state = pair<ll,int>; // esto es para escribir state en vez de pair<ll,int>
	// cola de prioridad que entrega el menor
	priority_queue <state, vector<state>, greater<state>> pq;
	// vector de distancias, inicializamos en INF
	vector <ll> dist(n, INF);

	pq.push({0,0});
	dist[0] = 0;

	while(!pq.empty()){
		auto [peso_camino, u] = pq.top(); // C++17 (structured binding)
		pq.pop();

		if(peso_camino != dist[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este

		for(auto [v, w] : adj[u]){ // [v,w] de C++17
			// para cada vecino v de u con peso w
			if(peso_camino + w < dist[v]){
				// encontramos un mejor camino hacia v! actualizamos
				// su distancia y lo agregamos a la cola
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
			}
		}
	}

	// las distancias finales están en "dist"

    	
	return 0;
}