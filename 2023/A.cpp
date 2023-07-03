#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> criba(int n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    vector <long long> primos;
    
    for (int i = 1; i <= n; i++){
        if (is_prime[i]){
            primos.push_back(i);
        }
    }

    return primos;
}





vector<int> getValuesLessThan(vector<int>& lst, int x) {
    vector<int> result;
    for (int num : lst) {
        if (num < x) {
            result.push_back(num);
        } else {
            break; // La lista está ordenada, no es necesario seguir recorriendo
        }
    }
    return result;
}

vector<int> sieve_with_3_divisors(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> numbers_with_3_divisors;
    for (int i = 2; i <= n; i++) {
        int count_divisors = 0;
        int sqrt_i = int(sqrt(i));
        if (is_prime[sqrt_i] && sqrt_i * sqrt_i == i) {
            numbers_with_3_divisors.push_back(i);
        }
    }

    return numbers_with_3_divisors;
}

int count_values_greater_than(vector<int>& lst, int x) {
    int count = 0;
    for (int num : lst) {
        if (num > x) {
            count++;
        }
    }
    return count;
}

int busqueda(vector<long long>& lst, long long x){
    int izq = 0;
    int der = lst.size()-1;

    while (izq < der){
        int med = (izq + der)/2;
        if (lst[med] * lst[med] > x){
            der = med;
        }
        else{
            izq = med + 1;
        }
    }

    return der;
    
}


int main() {
    vector <long long> primos = criba(100100);
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++){
        long long N,K;
        cin >> N;
        cin >> K;
        int a1 = busqueda(primos, N);
        int a2 = busqueda(primos, K);
        cout << a1 << " " << max(a1 - a2, 0) << endl;
    }

}
