#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 2
    Problem name: Incremental House of Pancakes
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019ffb9/00000000003384ea
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

void solve() {
    int l, r;
    cin >> l >> r;
    int i = 1;

    while (true) {
        if (max(l, r) < i) break;
        if (l >= r) {
            l -= i;
        } else {
            r -= i;
        }
        i++;
    }

    cout << i-1 << " " << l << " " << r << "\n";
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
