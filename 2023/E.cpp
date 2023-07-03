#include <iostream>

using namespace std;

long long calculate_phi(int n) {
    long long result = n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

long long calculate_sum(int n) {
    long long result = 0;

    for (int i = 1; i <= n; i++) {
        result += calculate_phi(i) * (n / i) * i;
    }

    return result;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        } else {
            long long result = calculate_sum(n);
            cout << result << endl;
        }
    }
    return 0;
}
