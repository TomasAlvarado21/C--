#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<long long, int> x_count, y_count;
    map<pair<long long, long long>, int> xy_count;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;

        x_count[x]++;
        y_count[y]++;
        xy_count[make_pair(x, y)]++;
    }

    for (auto p : x_count) {
        int count = p.second;
        ans += (long long)count * (count - 1) / 2;
    }

    for (auto p : y_count) {
        int count = p.second;
        ans += (long long)count * (count - 1) / 2;
    }

    for (auto p : xy_count) {
        int count = p.second;
        ans -= (long long)count * (count - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
