


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 1000000000;

bool resuelveCaso() {
    int V, S;
    cin >> V >> S;
    if (!cin)
        return false;

    vector<int> puntos(S + 1); // 1-based
    for (int i = 1; i <= S; ++i) {
        cin >> puntos[i];
    }

    // las puntuaciones nos las dan ordenadas de menor a mayor,
    // si no habría que ordenarlas para recuperar la solución deseada

    vector<vector<int>> disparos(S + 1, vector<int>(V + 1, INF));
    for (int i = 0; i <= S; ++i)
        disparos[i][0] = 0;
    /*
    disparos(i,j) = número de disparos para conseguir la puntuación j
    si podemos utilizar los sectores del 1 al i


    disparos(0,j) = INF si j > 0
    disparos(i,0) = 0
    disparos(i,j) = disparos(i-1, j)  si puntos[i] > j
    disparos(i,j) = min(disparos(i-1, j),
                     disparos(i, j - puntos[i]) + 1)

    */

    int i;

    i = 0;
    for (int j = 0; j <= V; ++j){
        if( disparos[i][j] < INF)
            cout <<  disparos[i][j] << " ";
        else
            cout << ". ";
    }
    cout << endl;
    i = 1;
    cout << "  ";
    for (int j = 1; j <= V; ++j) {
        if (puntos[i] > j)
            disparos[i][j] = disparos[i - 1][j];
        else
            disparos[i][j] = min(disparos[i - 1][j], disparos[i][j - puntos[i]] + 1);

        if( disparos[i][j] < INF)
            cout <<  disparos[i][j] << " ";
        else
            cout << ". ";
    }

    cout << endl;
    i = 2;
    cout << "  ";
    for (int j = 1; j <= V; ++j) {
        if (puntos[i] > j)
            disparos[i][j] = disparos[i - 1][j];
        else
            disparos[i][j] = min(disparos[i - 1][j], disparos[i][j - puntos[i]] + 1);

        if( disparos[i][j] < INF)
            cout <<  disparos[i][j] << " ";
        else
            cout << ". ";
    }
    return false;
    for (int i = 1; i <= S; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (puntos[i] > j)
                disparos[i][j] = disparos[i - 1][j];
            else
                disparos[i][j] = min(disparos[i - 1][j], disparos[i][j - puntos[i]] + 1);
        }
    }
    int valor = disparos[S][V];
    if (valor == INF) { // no es posible conseguir la puntuación V
        cout << "Imposible\n";
    } else {
        cout << valor << ':';
        // reconstruir solución, se prefieren puntuaciones altas
        int i = S, j = V;
        while (j > 0) {
            if (puntos[i] <= j && disparos[i][j] == disparos[i][j - puntos[i]] + 1) {
                // usamos un disparo más del sector i
                cout << ' ' << puntos[i];
                j -= puntos[i];
            } else { // descartamos el sector i
                --i;
            }
        }
        cout << '\n';
    }
    return true;

}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("../casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
