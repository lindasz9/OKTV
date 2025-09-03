#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int n;
vector<int> sor(MAXN); // A sorozat, amit rendezni akarunk

// Függvény ciklusok feloldására
void solve(set<int> cycle, vector<pair<int, int>>& res) {
    int fst = *cycle.begin(), snd = *cycle.rbegin(); // Első és utolsó elem
    swap(sor[fst], sor[snd]);                        // Elemcsere
    res.push_back({fst, snd});                       // Csere mentése

    if (cycle.size() == 2) return;                  // Ha csak 2 elem, kész

    auto c = cycle;
    if (sor[fst] == fst) {                          // Ha az első elem már jó helyen
        c.erase(find(c.begin(), c.end(), fst));
        solve(c, res);                              // Folytatás a maradék ciklussal
    } else if (sor[snd] == snd) {                   // Ha az utolsó elem jó helyen
        c.erase(find(c.begin(), c.end(), snd));
        solve(c, res);
    } else {                                        // Két kisebb ciklusra bontás
        vector<bool> vis(n + 1);
        vector<set<int>> cyc2;
        for (int i : c) {
            if (!vis[i]) {
                int x = i;
                set<int> s;
                do {
                    s.insert(x);
                    vis[x] = true;
                    x = sor[x];
                } while (x != i);
                cyc2.push_back(s);
            }
        }
        solve(cyc2[0], res);
        solve(cyc2[1], res);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n; // Sorozat hossza
    
    for (int i = 1; i <= n; i++) {
        cin >> sor[i]; // Sorozat beolvasása
    }

    vector<bool> vis(n + 1);
    vector<set<int>> cycles; // Ciklusok tárolása

    // Ciklusok megtalálása a sorozatban
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && sor[i] != i) {
            int x = i;
            set<int> s;
            do {
                s.insert(x);
                vis[x] = true;
                x = sor[x];
            } while (x != i);
            cycles.push_back(s);
        }
    }

    vector<pair<int, int>> cycres; // Minden csere tárolása
    for (int i = 0; i < cycles.size(); i++) {
        vector<pair<int, int>> res;
        solve(cycles[i], res);           // Ciklus feloldása
        for (auto& p : res) cycres.push_back(p);
    }

    // Csere párok rendezése a távolság szerint
    sort(cycres.begin(), cycres.end(), [] (auto& a, auto& b) {
        return abs(a.first - a.second) < abs(b.first - b.second);
    });

    cout << cycres.size() << endl;
    for (auto& p : cycres) cout << p.first << " " << p.second << endl;

    return 0;
}
/*
5
5 2 3 1 4
5
4 2 5 1 3
*/
