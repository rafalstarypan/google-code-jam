#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 1A
    Problem name: Square dance
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1355
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, m;
ll a[105][105];
int plays[105][105];

vector<ll> findAdj(int r, int c, int xd) {
    vector<ll> res;
    for (int i = r-1; i >= 1; i--) {
        if (plays[i][c] >= xd) {
            res.push_back(a[i][c]);
            break;
        }
    }
    for (int i = r+1; i <= n; i++) {
        if (plays[i][c] >= xd) {
            res.push_back(a[i][c]);
            break;
        }
    }
    for (int i = c-1; i >= 1; i--) {
        if (plays[r][i] >= xd) {
            res.push_back(a[r][i]);
            break;
        }
    }
    for (int i = c+1; i <= m; i++) {
        if (plays[r][i] >= xd) {
            res.push_back(a[r][i]);
            break;
        }
    }

    return res;
}

ll getAvg(vector<ll> v) {
    if (v.empty()) return 0LL;
    ll sum = 0LL;
    for (auto it: v) sum += it;

    return sum;
}

void solve() {
    cin >> n >> m;
    ll ans = 0LL;
    ll sum = 0LL;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
            plays[i][j] = inf;
        }
    }

    ans = sum;
    int xd = 1;
    while (true) {
        bool stop = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (plays[i][j] < xd) continue;
                vector<ll> adj = findAdj(i, j, xd);
                if (getAvg(adj) > a[i][j] * (ll)adj.size()) {
                    sum -= a[i][j];
                    plays[i][j] = xd;
                    stop = false;
                }
            }
        }
        if (stop) break;
        ans += sum;
        xd++;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }


    return 0;
}
