
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int voraz(list<int> cola, int N, int maxPeso) {
    int numSillas = 0;;
    while (!cola.empty()) {
        int min = cola.back(); cola.pop_back(); numSillas++; //se suma la silla del actual, que como minimo estará esta
        auto it = cola.begin();
        while (it != cola.end()) {
            int greater = *it;
            if (min + greater <= maxPeso) { //si caben ambos, se quitan ambos
                cola.erase(it);
                it = cola.end();
            }
            else {
                cola.erase(it); //esta persona tendrá que ir sola
                it = cola.begin();
                numSillas++;
            }
        }
    }
    return numSillas;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int maxPeso,N;
    cin >> maxPeso>>N;
    if (!std::cin)  // fin de la entrada
        return false;
    list<int> cola;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cola.push_back(n);
    }
    // escribir la solución
    cola.sort(std::greater<int>());
    cout << voraz(cola, N, maxPeso) << endl;
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
