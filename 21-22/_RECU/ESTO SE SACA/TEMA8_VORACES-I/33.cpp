
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

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Hora de comienzo y duraci�n. Objetivo: maximizar el numero de peliculas vistas en 24h.
Ordenar las pelis seg�n la hora de finalizaci�n e ir eligiendo la siguiente que se pueda ver maximizara el numero de peliculas

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso33() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N==0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main33() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos33.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso33());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
