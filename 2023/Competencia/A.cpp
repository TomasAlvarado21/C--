#include <iostream>
#include <map>

using namespace std;

bool esPosibleViajar(map<int, int>& estaciones, int inicio, int destino) {
    auto it_inicio = estaciones.lower_bound(inicio);
    auto it_destino = estaciones.lower_bound(destino);

    if (it_inicio == estaciones.end() || it_destino == estaciones.end())
        return false;

    if (it_inicio->first != inicio || it_destino->first != destino)
        return false;

    return it_inicio->second <= it_destino->second;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        map<int, int> estaciones;

        for (int i = 0; i < n; i++) {
            int estacion;
            cin >> estacion;
            estaciones[estacion] = i;
        }

        for (int i = 0; i < k; i++) {
            int inicio, destino;
            cin >> inicio >> destino;

            if (esPosibleViajar(estaciones, inicio, destino)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
