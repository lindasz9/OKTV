#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;             // n: rendelések száma, p: leves idő, q: főétel idő
    vector<int> t(n + 1);           // Időpontok
    vector<char> c(n + 1);          // Típusok: F, M, L
    for (int i = 1; i <= n; i++) cin >> t[i] >> c[i]; // Beolvasás

    int lastsoup = 0, id = 0;       // lastsoup: utolsó leves vége, id: főétel indexe
    vector<int> maindishes, ans(n + 1); // maindishes: főételek indexei, ans: befejezési idők

    for (int i = 1; i <= n; i++) {
        // Főételek feldolgozása, amik időben már befejeződhetnek
        if (lastsoup <= t[i]) {
            while (id < maindishes.size() && t[maindishes[id]] + q <= t[i]) {
                ans[maindishes[id]] = max(lastsoup, t[maindishes[id]] + q);
                id++;
            }
        }

        // Leves esetén frissítjük a lastsoup időt és az ans tömböt
        if (c[i] != 'F') lastsoup = ans[i] = t[i] + p;

        // Főétel esetén eltároljuk az indexét
        if (c[i] != 'L') maindishes.push_back(i);
    }

    // Eredmények kiírása
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;

    return 0;
}
/*
3 2 3
0 F
2 M
5 L
*/
