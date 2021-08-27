#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 1A
    Problem name: Pattern Matching
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
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

bool comp(string s1, string s2) {
    return s1.size() < s2.size();
}

int n;
vector<string> a(n);

void solve1() {
    int best = 0;
    string longest;

    for (int i = 0; i < n; i++) {
        if (a[i].size() > best) {
            best = a[i].size();
            longest = a[i];
        }
    }

    if (longest == "*") {
        cout << "A\n";
        return;
    }

    longest = longest.substr(1, string::npos);

    for (int i = 0; i < n; i++) {
        int s = a[i].size();
        if (s == 1) continue;
        string x = a[i].substr(1, string::npos);
        int diff = best - s;
        string tmp = longest.substr(diff, string::npos);
        if (tmp != x) {
            cout << "*\n";
            return;
        }
    }

    cout << longest << "\n";
}

void solve() {
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
         cin >> a[i];
    }

    bool sub1 = true;
    for (int i = 0; i < n; i++) {
        if (a[i][0] != '*') {
            sub1 = false;
            break;
        }
        int cnt = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == '*') cnt++;
        }
        if (cnt != 1) {
            sub1 = false;
            break;
        }
    }

    if (sub1) {
        solve1();
        return;
    }

    vector<string> pref, suff;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        int l = a[i].size();
        int r = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == '*') {
                l = j;
                break;
            }
            tmp += a[i][j];
        }
        if (tmp.size() > 0) pref.push_back(tmp);
        tmp = "";
        for (int j = a[i].size()-1; j >= 0; j--) {
            if (a[i][j] == '*') {
                r = j;
                break;
            }
            tmp += a[i][j];
        }
        if (l >= r) a[i] = "";
        else a[i] = a[i].substr(l, r-l+1);
        if (tmp.size() > 0) suff.push_back(tmp);
    }

    sort(pref.begin(), pref.end(), comp);
    sort(suff.begin(), suff.end(), comp);

    for (int i = 0; i < pref.size(); i++) {
        for (int j = i+1; j < pref.size(); j++) {
            string s = pref[i];
            string t = pref[j];
            int len = s.size();
            if (t.substr(0, len) != s) {
                cout << "*\n";
                return;
            }
        }
    }

    for (int i = 0; i < suff.size(); i++) {
        for (int j = i+1; j < suff.size(); j++) {
            string s = suff[i];
            string t = suff[j];
            int len = s.size();
            if (t.substr(0, len) != s) {
                cout << "*\n";
                return;
            }
        }
    }

    string last = "";
    if (!suff.empty()) {
        last = suff.back();
        reverse(last.begin(), last.end());
    }

    if (!pref.empty()) cout << pref.back();
    for (string s: a) {
        for (auto it: s) {
            if (it != '*') cout << it;
        }
    }
    cout << last << "\n";
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
