#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 1C
    Problem name: Oversized Pancake Choppers
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/00000000003172d1
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
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    map<ll, int> mp;
    int maxCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        maxCnt = max(maxCnt, mp[a[i]]);
    }
    sort(a.begin(), a.end());

    int ans = d-1;

    if (d == 2) {
        if (maxCnt >= 2) ans = 0;
        else ans = 1;
    }

    if (d == 3) {
        if (maxCnt >= 3) {
            ans = 0;
        } else if (maxCnt == 2) {
            for (int i = 0; i < n-2; i++) {
                ll x = a[i];
                if (mp[x] == 2) {
                    ans = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ll x = a[i];
            if (mp.count(2*x)) {
                ans = min(ans, 1);
                break;
            }
        }
    }

    cout << ans << "\n";
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
