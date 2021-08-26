#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Qualification Round
	Problem name: Moons and umbrellas
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
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
int X, Y;
string s;
int dp[1005][2];

void solve() {
	cin >> X >> Y >> s;
	s = '#' + s;
	n = s.size();
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i][1] = inf;
	}
	
	for (int i = 1; i < n; i++) {
		if (s[i] == 'C' || s[i] == '?') {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
		}
		if (s[i] == 'J' || s[i] == '?') {
			dp[i][1] = min(dp[i-1][0] + X, dp[i-1][1]);
		}
	}
	
	cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
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
