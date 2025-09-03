#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);    

    int n;
    cin >> n;                  // Beolvassuk az elemek számát
    vector<int> sor(n + 1);    // A sorozat tárolása (1-től indexelve)
    vector<bool> lehet(n + 1, true); // Jelzőtömb: igaz, ha az adott indexről még lehet indulni

    for (int i = 1; i <= n; i++)
        cin >> sor[i];          // Beolvassuk a sorozat elemeit

    for (int i = 1; i <= n; i++) {
        int x = sor[i];
        // Ellenőrizzük, hogy a lépés érvényes és az induló pozíció használható-e
        if (x != 0 && x + i > 0 && x + i <= n && lehet[i]) {
            set<int> s;          // Tároljuk az eddig bejárt indexeket
            int idx = i;

            // Követjük a lépéseket, amíg érvényes a pozíció
            while (sor[idx] != 0 && idx > 0 && idx <= n && lehet[idx]) {
                if (s.count(idx)) {   // Ha ciklust találunk
                    cout << i << " " << s.size() << endl; // Kiírjuk a kezdőindexet és a ciklus hosszát
                    return 0;
                }
                s.insert(idx);        // Index hozzáadása a bejárt indexekhez
                idx += sor[idx];      // Következő lépés
            }

            // Jelöljük az összes bejárt indexet, hogy ne indítsunk onnan újra
            for (int j : s) lehet[j] = false;
        } else lehet[i] = false;       // Érvénytelen kezdőpont
    }

    cout << "Nincs" << endl;          // Ha nem találunk ciklust
    return 0;
}

/*
12
-1 2 2 5 1 2 0 -2 1 1 1 0
*/
