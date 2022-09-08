
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
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

struct Paciente {
    string name;
    int gravedad;
    int orden;
};
//la ventaja de definir el menor es que luego en la cola de prioridad no hay que identificar que el comparador sea otro, porque STL usa de manera predefinida el menor
//La cola de la STL es una cola de máximos, por lo que dado un orden, va a considerar más prioritario el segundo argumento, por lo que
//Hay que valorar cuando B sea más prioritario, es decir, cuando tenga una gravedad mayor
bool operator<(Paciente const& a, Paciente const& b) {
    return b.gravedad > a.gravedad 
        || (a.gravedad == b.gravedad && b.orden < a.orden); //definimos el orden de llegada con 1 como el que llega primero
}

bool resuelveCaso() {

    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    int n;
    cin >> n;
    if (n == 0)
        return false;

    priority_queue<Paciente> q;
    char action; string name; int val; int orden = 0;
    
    while (n--) {
        cin >> action;
        if (action == 'I') { //La acción a realizar es añadir un nuevo paciente
            cin >> name >> val;
            q.push({ name, val, orden++ });
        }
        else { //La acción a realizar es tratar al paciente más prioritario
            cout << q.top().name << '\n';
            q.pop();
        }
    }
    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
