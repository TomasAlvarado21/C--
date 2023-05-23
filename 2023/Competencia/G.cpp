#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 3e5 + 5;
const int INF = 0x3f3f3f3f;

struct edge {
    int to;
    int cost;
};

int n, m, k;
vector<edge> G[maxn];
int d[maxn];
int in[maxn], tmp[maxn];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    fill(d, d + n + 1, INF);
    d[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto [dist, v] = q.top();
        q.pop();
        if (d[v] != dist) continue;
        for (const auto& e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                in[e.to] = 1;
                q.push({d[e.to], e.to});
            } else if (d[e.to] == d[v] + e.cost) {
                in[e.to]++;
            }
        }
    }
}

int main() {
    int MaxAutopistas = 0;
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        int cost;
        cin >> u >> v >> cost;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    while (k--) {
        int u;
        int cost;
        cin >> u >> cost;
        if (!tmp[u]) {
            tmp[u] = cost;
        } else {
            tmp[u] = min(tmp[u], cost);
            MaxAutopistas++;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (!tmp[i]) continue;
        G[i].push_back({1, tmp[i]});
        G[1].push_back({i, tmp[i]});
    }
    dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        if (tmp[i]) {
            if (tmp[i] > d[i]) {
                MaxAutopistas++;
            } else if (tmp[i] == d[i] && in[i] > 1) {
                MaxAutopistas++;
            }
        }
    }
    cout << MaxAutopistas << endl;
    return 0;
}
