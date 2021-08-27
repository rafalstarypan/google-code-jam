#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 1C
    Problem name: Overrandomized
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/00000000003179a1
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e4;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int U;

void solve() {
    cin >> U;
    vector<pair<ll, string>> a;
    vector<string> v;
    for (int i = 0; i < M; i++) {
            ll q;
            string r;
            cin >> q >> r;
            v.push_back(r);
            if (q <= 10) {
                a.push_back({q, r});
            }
    }

    if (U == 2) {
        vector<char> ans(10, '#');
        sort(a.begin(), a.end());
        set<char> used;

        for (auto p: a) {
            int x = p.first;
            string s = p.second;
            char c = s[0];
            if (x == 10 && s.size() == 2) {
                ans[0] = s[1];
                continue;
            }
            if (ans[x] != '#') continue;
            if (used.count(c)) continue;
            ans[x] = c;
            used.insert(c);
        }

        for (int i = 0; i < 10; i++) {
            cout << ans[i];
        }
        cout << "\n";
        return;
    }

    set<char> xd, firstLet;
    vector<char> ans(10);
    vector<pair<int, char>> cnt(26);

    for (int i = 0; i < 26; i++) {
        cnt[i] = make_pair(0, (char)(i+'A'));
    }

    for (auto s: v) {
        firstLet.insert(s[0]);
        cnt[s[0]-'A'].first++;
        for (auto c: s) {
            xd.insert(c);
        }
    }

    for (auto c: xd) {
        if (!firstLet.count(c)) {
            ans[0] = c;
            xd.erase(c);
            break;
        }
    }

    sort(cnt.rbegin(), cnt.rend());
    int pos = 0;

    for (int i = 1; i < 10; i++) {
        ans[i] = cnt[pos].second;
        pos++;
    }

    for (int i = 0; i < 10; i++) {
        cout << ans[i];
    }
    cout << "\n";
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
