
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 1000000000; // Para coste y mínimo número de varillas a usar.

struct Varilla {
    int longitud;
    int precio;
};

bool resuelveCaso() {
    int N, L;
    cin >> N >> L;

    if (!cin) {
        return false;
    }

    // leemos la información de las varillas
    vector<Varilla> varillas(N+1);  // 1 - based
    for (int i = 1; i <= N; ++i) {
        cin >> varillas[i].longitud >> varillas[i].precio;
    }

    vector<bool> posible(L+1, false);
    posible[0] = true;

    for (int i = 1; i <= N; ++i) {
        for (int j = L; j >= varillas[i].longitud; --j) {
            posible[j] = posible[j-varillas[i].longitud] || posible[j];
        }
    }

    if (posible[L]) {

        cout << "SI";
        vector<long long int> formas(L+1, 0);
        // resto
        formas[0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = L; j >= varillas[i].longitud; --j) {
                formas[j] = formas[j-varillas[i].longitud] + formas[j];
            }
        }
        cout << ' ' << formas[L];

        vector<int> minnum(L+1, INF);
        // resto
        minnum[0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = L; j >= varillas[i].longitud; --j) {
                minnum[j] = min(minnum[j-varillas[i].longitud] + 1, minnum[j]);
            }
        }
        cout << ' ' << minnum[L];

        vector<int> mincost(L+1, INF);
        // resto
        mincost[0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = L; j >= varillas[i].longitud; --j) {
                mincost[j] = min(mincost[j-varillas[i].longitud] + varillas[i].precio, mincost[j]);
            }
        }
        cout << ' ' << mincost[L] << endl;
    } else {
        cout << "NO\n";
    }
    return true;
}



int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("../casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
