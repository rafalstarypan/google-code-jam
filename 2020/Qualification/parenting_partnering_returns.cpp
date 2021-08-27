#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Qualification Round
    Problem name: Parenting Partnering Returns
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
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

struct Event {
    int pos;
    int type;
    int id;
};

bool comp(Event e1, Event e2) {
    if (e1.pos != e2.pos) return e1.pos < e2.pos;
    return e1.type > e2.type;
}

void solve() {
    int n; cin >> n;
    vector<char> ans(n+1);
    vector<Event> events;
    set<char> guys;
    guys.insert('C');
    guys.insert('J');

    for (int i = 1; i <= n; i++) {
        int s, e;
        cin >> s >> e;
        events.push_back({s, -1, i});
        events.push_back({e, 1, i});
    }
    sort(events.begin(), events.end(), comp);
    map<int, char> mp;


    for (int i = 0; i < 2*n; i++) {
        int pos = events[i].pos;
        int type = events[i].type;
        int id = events[i].id;

        if (type == -1) {
            if (guys.empty()) {
                cout << "Impossible\n";
                return;
            }
            char who = *guys.begin();
            guys.erase(guys.begin());
            ans[id] = who;
            mp[id] = who;
            continue;
        }

        guys.insert(mp[id]);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
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
