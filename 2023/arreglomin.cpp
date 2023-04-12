#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), c(n);
    multiset<int> b;

    // Leemos los arreglos a y b
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    // Construimos el arreglo c
    for (int i = 0; i < n; i++) {
        // Buscamos el primer elemento de b que sea mayor o igual a n - a[i]
        auto it = b.lower_bound(n - a[i]);
        // Si no encontramos ninguno, escogemos el menor elemento de b
        if (it == b.end()) {
            it = b.begin();
        }
        // Tomamos el elemento encontrado y lo eliminamos de b
        int bj = *it;
        b.erase(it);
        // Calculamos el valor de ci
        c[i] = (a[i] + bj) % n;
    }

    // Imprimimos el arreglo c
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    
    return 0;
}
