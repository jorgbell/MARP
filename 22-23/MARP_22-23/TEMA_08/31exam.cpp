
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using mQueue = priority_queue<int, vector<int>, std::greater<int>>;

int voraz31(mQueue jugadores, mQueue camisetas) {
    int compra = jugadores.size();
    while (!jugadores.empty() && !camisetas.empty()) {
        int j = jugadores.top(); int c = camisetas.top(); camisetas.pop();        
        int diff = c - j;
        if (diff > 1)
            return compra;
        if (diff >= 0 && diff <= 1) {
            compra--; jugadores.pop();
        }
    }
    return compra;
}

bool resuelveCaso31exam() {

    // leer los datos de la entrada
    int jugadores, camisetas;
    cin >> jugadores >> camisetas;
    if (!std::cin)  // fin de la entrada
        return false;
    mQueue pqjugadores, pqcamisetas;
    for (int i = 0; i < jugadores; i++) {
        int x; cin >> x; pqjugadores.push(x);
    }
    for (int i = 0; i < camisetas; i++) {
        int x; cin >> x; pqcamisetas.push(x);
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << voraz31(pqjugadores, pqcamisetas) << '\n';
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main31() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos31.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso31exam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
