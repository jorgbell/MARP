
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

    /* posible(i,j) = es posible formar una varilla de longitud j con las varillas de la 1 a la i
     posible(0,j) = false
     posible(i,0) = true;
     posible(i,j) = l_i <= j ? (posible(i-1,j-l_i) or posible(i-1,j)) : posible(i-1,j)
     */

    vector<vector<bool> > posible(N+1, vector<bool>(L+1));
    for (int i = 0; i <= N; ++i) {
        posible[i][0] = true;
    }
    for (int j = 1; j <= L; ++j) {
        posible[0][j] = false;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= L; ++j) {
            posible[i][j] = varillas[i].longitud <= j ?
                            posible[i-1][j-varillas[i].longitud] || posible[i-1][j] :
                            posible[i-1][j];
        }
    }

    if (posible[N][L]) {
        cout << "SI";

        /* formas(i,j) = nº de maneras de formar una varilla de longitud j
                         con las varillas de la 1 a la i
         formas(0,j) = 0
         formas(i,0) = 1

         formas(i,j) = formas(i-1,j-l_i) + formas(i-1,j)  si l_i <= j
                     = formas(i-1,j)   si l_i > j
         */

        vector<vector<long long int> > formas(N+1, vector<long long int>(L+1));
        for (int i = 0; i <= N; ++i) {
            formas[i][0] = 1;
        }
        for (int j = 1; j <= L; ++j) {
            formas[0][j] = 0;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= L; ++j) {
                formas[i][j] = varillas[i].longitud <= j ?
                               (formas[i-1][j-varillas[i].longitud] + formas[i-1][j]) :
                               formas[i-1][j];
            }
        }
        cout << ' ' << formas[N][L];

    /* minnum(i,j) = mínimo nº de varillas para formar una varilla de longitud j
                 con las varillas de la 1 a la i
     minnum(0,j) = infinito
     minnum(i,0) = 0

     minnum(i,j) = min(minnum(i-1,j-l_i) + 1, minnum(i-1,j))   si  l_i <= j
                 = minnum(i-1,j)   si l_i > j
     */

    vector<vector<int> > minnum(N+1, vector<int>(L+1));
    for (int i = 0; i <= N; ++i) {
        minnum[i][0] = 0;
    }
    for (int j = 1; j <= L; ++j) {
        minnum[0][j] = INF;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= L; ++j) {
            minnum[i][j] = varillas[i].longitud <= j ?
                           min(minnum[i-1][j-varillas[i].longitud] + 1, minnum[i-1][j]) :
                           minnum[i-1][j];
        }
    }

    cout << ' ' << minnum[N][L];

    /* mincost(i,j) = mínimo coste para formar una varilla de longitud j
                  con las varillas de la 1 a la i
 mincost(0,j) = infinito
 mincost(i,0) = 0

 mincost(i,j) = min(mincost(i-1,j-l_i) + c_i, mincost(i-1,j))  si l_i <= j
              = mincost(i-1,j)    si l_i > j
 */

    vector<vector<int> > mincost(N+1, vector<int>(L+1));
    for (int i = 0; i <= N; ++i) {
        mincost[i][0] = 0;
    }
    for (int j = 1; j <= L; ++j) {
        mincost[0][j] = INF;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= L; ++j) {
            mincost[i][j] = varillas[i].longitud <= j ?
                            min(mincost[i-1][j-varillas[i].longitud] + varillas[i].precio, mincost[i-1][j]) :
                            mincost[i-1][j];
        }
    }
    cout << ' ' << mincost[N][L] << endl;
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
