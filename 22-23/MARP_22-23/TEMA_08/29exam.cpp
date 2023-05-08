
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

Tenemos agujeros que estan en posiciones X medidos desde el comienzo de la manguera
Debemos ver cual es el numero minimo de parches de longitud L que debemos comprar

Un parche puede tapar L cm te manguera, teniendo un vector ordenado, debemos ir comprobando  cuantos se pueden cubrir 

Debemos ordenar el vector según una prioridad. La prioridad debe ser la diferencia
entre el agujero actual y el siguiente

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>



int voraz(priority_queue<int> pq, int L) {
    return 0;
}

bool resuelveCaso29exam() {

    // leer los datos de la entrada
    int N, L;
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;
    priority_queue<int> pq;
    if (N == 1) {
        int x; cin >> x; pq.push(x);
    }
    else{
        int a, b; cin >> a; N--;
        while (N > 0) {
            cin >> b;
            pq.push(b - a);
            a = b;
            N--;
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << voraz(pq, L) << '\n';
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main29exam() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos29.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso29exam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
