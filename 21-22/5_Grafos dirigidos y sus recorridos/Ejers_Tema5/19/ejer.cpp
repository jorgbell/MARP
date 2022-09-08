
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Digrafo.h"

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo g = Digrafo(V);
    vector<int> gradosEntrada(V,0);
    for (int i = 0; i < A; i++) {
        int from, to;
        cin >> from >> to;
        g.ponArista(from, to);
        gradosEntrada[to] += 1;
    }
    // resolver el caso posiblemente llamando a otras funciones
    int i = 0;
    while (i < V) {
        int gradoSalida = g.ady(i).size();
        if (gradoSalida == 0 && gradosEntrada[i] == V - 1) {
            cout << "SI " << i << '\n';
            return true;
        }
        i++;
    }
    cout << "NO\n";
    // escribir la solución
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
