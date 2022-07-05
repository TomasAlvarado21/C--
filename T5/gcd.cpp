#include <bits/stdc++.h>
using namespace std;
#include <map>

vector<int> primos(1.5*1e7 + 1,0);
void criba(){
    primos[1] = 1;
    for (int i = 1; i < 1.5*1e7 +1; i++){
        if (primos[i] == 0){
            for (int j = i; j < 1.5*1e7 +1; j += i){
                if(primos[j]==0){
                    primos[j] = i;
                }
            }
        }    
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    criba();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int g = arr[0];

    for (int i = 1; i < n; i++){
        g = __gcd(g, arr[i]);
    }
    for (int i = 0; i < n; i++){
        arr[i] /= g;
    }
    

    int result = 0;
    unordered_map<int,int> mapa_primos;
    for (int i = 0; i < n; i++) {
        int j = arr[i];
        unordered_set<int> factores;
        while (j != 1) {
            int k = primos[j];
            factores.insert(k);
            j /= k;
        }
        for(auto factor: factores) mapa_primos[factor]++;
    }
    if(mapa_primos.size()){
        for (auto it = mapa_primos.begin(); it != mapa_primos.end(); it++) {
            if (it->second > result) result = it->second;
            }
            cout << n - result << endl;
    } 
    else {
        cout << -1 << endl;
    }
}