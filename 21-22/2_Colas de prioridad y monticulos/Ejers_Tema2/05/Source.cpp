
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
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

struct Paciente {
    string name;
    int64_t damage;
    int64_t order;
};

bool operator>(const Paciente& a, const Paciente& b) {
    return a.damage > b.damage || (a.damage == b.damage && a.order < b.order); //en caso de ser iguales, si A entró primero que B se atiende a A
}
bool operator<(const Paciente& a, const Paciente& b) {
    return b > a;
}

using myQueue = priority_queue<Paciente, vector<Paciente>, less<Paciente>>;

bool resuelveCaso() {

    // leer los datos de la entrada
    int nEvents;
    cin >> nEvents;
    if (nEvents == 0)  // fin de la entrada
        return false;
    myQueue pacientes;
    //resolver la solucion y añadir pacientes
    for (int i = 0; i < nEvents; i++) {
        char type;
        cin >> type;
        if (type == 'I') { //añadimos un paciente
            string name;
            int64_t damage;
            cin >> name >> damage;
            pacientes.push({ name,damage,i });
        }
        if (type == 'A') {
            cout << pacientes.top().name << endl;
            pacientes.pop();
        }
    }
    //separador
    cout << "---" << endl;
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
