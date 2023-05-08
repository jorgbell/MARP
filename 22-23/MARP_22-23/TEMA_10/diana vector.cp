
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 1000000000; // Para coste y mínimo número de varillas a usar.

/* tiradas(i,j) = es  posible alcanzar el valor v con con los dardos de la 1 a la i
 tiradas(0,j) = INF;
 tiradas(i,0) = 0;
 tiradas(i,j) = v_i <= j ? min(tiradas(i,j-v_i) + 1, tiradas(i-1,j))
 */

bool resuelveCaso() {
    int N, V;
    cin >> N >> V;

    if (!cin) {
        return false;
    }
    vector<int> dardos(V, 0);

    for (int i = 0; i < V; i++)
        cin >> dardos[i];

    vector<int> tiradas(N+1, INF);
    tiradas[0] = 0;

    for (int i = 0; i < V; ++i) {
        for (int j = dardos[i]; j <=N ; j++) {
            tiradas[j] = min(tiradas[j], tiradas[j - dardos[i]] + 1);
        }
    }




    if( tiradas[N] < INF){

        cout << tiradas[N] << ": ";
        vector<int> sol;
        int i = V, j = N;
        while(j > 0){
            if (dardos[i] <= j && tiradas[j] == tiradas[j - dardos[i]] + 1) {
                sol.push_back(dardos[i]);
                j -= dardos[i];
            }
            else{
                --i;
            }
        }
        for(int i = 0; i < sol.size(); i++){
            cout << sol[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Imposible\n";
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
