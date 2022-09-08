
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

Debemos sacar el numero minimo de pasadizos que es necesario construir para conectar todas las casas con el mar.
Tenemos el tamaño con inicio y fin de cada uno de los edificios
Si ordenamos los inicios de menor a mayor fin, podemos ir comprobando uno a uno si su inicio es menor que el fin del siguiente
Ejempplo:
    1-4
    2-10
    6-15
    12-20
    Iteraciones:
        1-4 es un puente ya
        1-4 entra en el rango de 2-10? SÍ porque 2<4 -> no sumamos un tunel. Quitamos este y nos quedamos con el que tenga menor final
        6-15 entra en el rango de 1-4? No, creamos nuevo puente y nos quedamos con el actual
        Asi consecutivamente

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso35() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N==0)
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
    std::ifstream in("casos35.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso35());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
