
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;


/*@ <answer>

hay tantos equipos como ciudades. Una victoria = >= efectivos de defensa que el enemigo
Hay que maximizar el numero de victorias
Crear dos colas de prioridad, una para los atacantes, otra para los defensores.
Un equipo por cada ciudad.
Ordenamos las colas de la misma manera

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
using myQueue = priority_queue<int, vector<int>, std::greater<int>>;


int voraz(myQueue enemigos, myQueue aliados) {
    int solucion = 0;
    //compara y cuenta cuantas se salvan
    while (!enemigos.empty() && !aliados.empty()) {
        int e = enemigos.top();
        int a = aliados.top();
        if (a >= e) {
            enemigos.pop();
            solucion += 1;
        }
        aliados.pop(); //SIEMPRE avanzamos aqui, puesto que si es menor que el de los enemigos, siempre sera menor que el resto de ciudades
    }
    return solucion;
}

bool resuelveCaso30exam() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    myQueue enemigos;
    myQueue aliados;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        enemigos.push(n);
    }
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        aliados.push(n);
    }

    // escribir la soluci�n
    cout << voraz(enemigos, aliados) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main30() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos30.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso30exam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
