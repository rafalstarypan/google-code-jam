#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 1C
    Problem name: Overexcited Fan
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/0000000000317409
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

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2 ) + abs(y1-y2);
}

void solve() {
    int x, y;
    string s;
    cin >> x >> y >> s;

    y *= -1;
    int curX = 0;
    int curY = 0;

    if (x == curX && y == curY) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') curY++;
        if (s[i] == 'S') curY--;
        if (s[i] == 'E') curX--;
        if (s[i] == 'W') curX++;
        int tmp = dist(x, y, curX, curY);
        if (tmp <= i+1) {
            cout << i+1 << "\n";
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
