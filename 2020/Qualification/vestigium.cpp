#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Qualification Round
    Problem name: Vestigium
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
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

int n;
int a[105][105];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        k += a[i][i];
    }
    int r = 0;
    int c = 0;

    for (int i = 0; i < n; i++) {
        set<int> cnt;
        for (int j = 0; j < n; j++) {
            cnt.insert(a[i][j]);
        }
        if (cnt.size() != n) r++;
    }

    for (int i = 0; i < n; i++) {
        set<int> cnt;
        for (int j = 0; j < n; j++) {
            cnt.insert(a[j][i]);
        }
        if (cnt.size() != n) c++;
    }

    cout << k << " " << r << " " << c << "\n";
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
