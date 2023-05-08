
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martín y Tomás López Antón
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Hay que minimizar el numero de sillas usadas para subir a la cima. Deben haber como maximo dos usuarios y no deben superar el peso maximo.
Para ello hay que ordenar de menor a mayor los usuarios y juntar el mas pesado con el menos pesado.
Si el mas pesado ocupa toda la silla, va solo y se saca de la lista. Lo mismo si se queda solo uno.
En caso contrario, coges al primero y el ultimo y los metes en la misma silla

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

int voraz(list<int> cola, int N, int maxPeso) {
    int numSillas = 0;;
    while (!cola.empty()) {
        int min = cola.back(); cola.pop_back(); numSillas++; //se suma la silla del actual, que como minimo estar� esta
        auto it = cola.begin();
        while (it != cola.end()) {
            int greater = *it;
            if (min + greater <= maxPeso) { //si caben ambos, se quitan ambos
                cola.erase(it);
                it = cola.end();
            }
            else {
                cola.erase(it); //esta persona tendr� que ir sola
                it = cola.begin();
                numSillas++;
            }
        }
    }
    return numSillas;
}

bool resuelveCaso36() {

    // leer los datos de la entrada

    int maxPeso, N;
    cin >> maxPeso >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    list<int> cola;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cola.push_back(n);
    }
    // escribir la soluci�n
    cola.sort(std::greater<int>());
    cout << voraz(cola, N, maxPeso) << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos36.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso36());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
