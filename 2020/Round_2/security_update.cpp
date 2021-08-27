#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 2
    Problem name: Security Update
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019ffb9/000000000033871f
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 2e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 998244353LL;

int n, m;
vector<PII> G[105];
int val[105];
bool vis[105];
int ans[1005];
int t[105], from[105], lastEdge[105]; // time before node i got update

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        vis[i] = false;
    }
    for (int i = 1; i <= m; i++) {
        ans[i] = 0;
    }

    for (int i = 2; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    int updated = 0;
    int lastTime = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;  // number of nodes before, node's id
    pq.push(make_pair(0, 1));
    vis[1] = true;

    while (!pq.empty()) {
        int x = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (v != 1) {
            int toPar = t[from[v]]; // time to reach parent
            int edge = lastEdge[v];
            if (x < updated) {
                ans[edge] = lastTime - toPar;
                t[v] = lastTime;
            } else {
                ans[edge] = (lastTime - toPar) + 1;
                lastTime++;
                t[v] = lastTime;
            }
        }

        updated++;
        for (PII e: G[v]) {
            int to = e.first;
            int id = e.second;
            if (vis[to]) continue;
            vis[to] = true;
            from[to] = v;
            lastEdge[to] = id;
            pq.push({-val[to], to});
        }
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0) ans[i] = M;
        cout << ans[i] << " ";
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }


    return 0;
}
