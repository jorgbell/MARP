
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

Hay que maximizar el numero de coches que van a poder correr simultaneamente.
Cada coche necesita dos pilas que sumen V voltios, el mismo para todos los coches. Disponemos de N pilas cada una con X numero de voltios.
Para maximizar el numero de coches, tenemos que ordenar las pilas de menor a mayor y viceversa, y debemos coger una del principio y una del final y ver si suman V.
Habra que hacer el algoritmo hasta que nos quedemos con 1 o con 0 pilas

CORRECCION: No hace falta duplicar la informacion para ordenar dos veces, sino tenerlo una sola vez en una lista que podamos acceder al principio y al final con iteradores

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso38() {

    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos37.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso38());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
