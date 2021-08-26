#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Round 1B
	Problem name: Subtransmutation
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae4aa
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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> wanted(50, 0);
	for (int i = 1; i <= n; i++) {
		cin >> wanted[i];
	}
	
	for (int i = n; i <= 40; i++) {
		vector<int> cnt(50, 0);
		cnt[i] = 1;
		while (true) {
			bool change = false;
			
			for (int j = i; j > 1; j--) {
				if (cnt[j] > 0 && cnt[j] > wanted[j]) {
					cnt[j]--;
					if (j-a > 0) cnt[j-a]++;
					if (j-b > 0) cnt[j-b]++;
					change = true;
				}
			}
			
			
			bool ok = true;
			for (int j = 1; j <= n; j++) {
				if (cnt[j] < wanted[j]) {
					ok = false;
					break;
				}
			}
			
			if (ok) {
				cout << i << '\n';
				return;
			}
			
			if (!change) break;
		}
	}
	
	cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	
	
    return 0;
}
