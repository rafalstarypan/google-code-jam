#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Round 1B
	Problem name: Digit blocks
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae37b
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
const int inf = 2e9;
const ll MOD = 1000000007LL;

int T, N, B;
ll P;
map<int, int> mp;

void solve() {
	vector<int> now(N+1, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < B; j++) {
			int D; cin >> D;
			if (D == -1) return;
			
			vector<PII> a;
			for (int k = 1; k <= N; k++) {
				if (now[k] < B) {
					a.emplace_back(now[k], k);
				}
			}
			sort(a.rbegin(), a.rend());
			int id = a.back().second;
			if (D > 0) {
				int pos = mp[D];
				if (pos < a.size()) id = a[pos].second;
			}
			
			cout << id << endl;
			now[id]++;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> T >> N >> B >> P;
	
	int pos = 8;
	for (int i = 1; i < 10; i++) {
		mp[i] = pos;
		pos--;
	}
	
	for (int tt = 1; tt <= T; tt++) {
		solve();
	}
	
	int res; cin >> res;
	if (res == -1) assert(false);
	
    return 0;
}
