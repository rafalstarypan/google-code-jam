#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Qualification Round
	Problem name: Cheating detection
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1155
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

const int ROWS = 100;
const int COLS = 10000;

string a[105];

void solve() {
	for (int i = 0; i < ROWS; i++) {
		cin >> a[i];
	}
	
	vector<PII> cand;
	
	for (int i = 0; i < ROWS; i++) {
		int cnt = 0;
		for (int j = 0; j < COLS; j++) {
			if (a[i][j] == '1') cnt++;
		}
		
		if (cnt >= 4500) cand.emplace_back(cnt, i);
	}
	
	sort(cand.rbegin(), cand.rend());
	
	vector<PII> questions;	// (wrong answers, id)
	
	for (int i = 0; i < COLS; i++) {
		int cnt = 0;
		for (int j = 0; j < ROWS; j++) {
			if (a[j][i] == '0') cnt++;
		}
		questions.emplace_back(cnt, i);
	}
	
	sort(questions.rbegin(), questions.rend());
	
	int tmp = inf;
	int who = -1;
	
	for (int i = 0; i < cand.size(); i++) {
		int x = cand[i].second;
		int hard = 0;
		
		for (int j = 0; j < 10; j++) {
			int id = questions[j].second;
			if (a[x][id] == '1') hard++;
		}
		
		//cout << "D: " << x << " -> " << hard << '\n';
		
		if (abs(hard - 5) < tmp) {
			tmp = abs(hard - 5);
			who = x;
		}
	}
	
	cout << who + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int T, P; cin >> T >> P;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	
	
    return 0;
}
