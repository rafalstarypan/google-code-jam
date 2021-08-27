#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Qualification Round
    Problem name: Nesting Depth
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
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

void solve() {
    string s; cin >> s;
    int n = s.size();
    string ans = "";
    int curDepth = 0;

    for (int i = 0; i < n; i++) {
        int d = s[i]-'0';
        char c;
        if (d > curDepth) c = '(';
        else c = ')';
        for (int j = 0; j < abs(d-curDepth); j++) {
            ans += c;
        }
        ans += s[i];
        curDepth = d;
    }
    for (int i = 0; i < curDepth; i++) {
        ans += ')';
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
