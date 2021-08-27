#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Qualification Round
    Problem name: Esab Atad
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
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

int B;
int a[105];

/*
    1 - flipping
    2 - complementing
    3 - reversing
    4 - nothing
*/

int samePair = -1;
int diffPair = -1;

int print(int x) {
    cout << x << endl;
    int res; cin >> res;
    return res;
}

void findPair(int i) {
    a[i] = print(i);
    a[B-i+1] = print(B-i+1);
    if (samePair == -1 && a[i] == a[B-i+1]) {
        samePair = i;
    }
    if (diffPair == -1 && a[i] != a[B-i+1]) {
        diffPair = i;
    }
}

void doFlip() {
    for (int i = 1; i <= B; i++) {
        a[i] ^= 1;
    }
}

void doReverse() {
    int i = 1;
    int j = B;
    while (i <= B/2) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void findChange() {
    bool comp = false;
    if (samePair != -1 && a[samePair] != print(samePair)) {
        comp = true;
    }
    if (samePair == -1) print(1);

    bool rev = comp;

    if (diffPair != -1 && a[diffPair] != print(diffPair)) {
        rev = !comp;
    }
    if (diffPair == -1) print(1);

    if (comp) {
        doFlip();
    }
    if (rev) {
        doReverse();
    }
}

void solve() {
    samePair = diffPair = -1;
    int c = 1;

    for (; c <= 5; c++) {
        findPair(c);
    }

    findChange();

    while (c <= B/2) {
        int i = 0;
        for (; i < 4 && c <= B/2; i++, c++) {
            findPair(c);
        }

        if (i == 4) {
            findChange();
        }
    }

    for (int i = 1; i <= B; i++) {
        cout << a[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T >> B;
    for (int t = 0; t < T; t++) {
        solve();
        char cor;
        cin >> cor;
        if (cor == 'N') {
            return 0;
        }
    }







    return 0;
}
