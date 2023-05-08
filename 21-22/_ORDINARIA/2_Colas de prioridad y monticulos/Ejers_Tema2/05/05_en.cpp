
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

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

struct Paciente {
    string name;
    int64_t damage;
    int64_t order;
};

bool operator>(const Paciente& a, const Paciente& b) {
    return a.damage > b.damage || (a.damage == b.damage && a.order < b.order); //en caso de ser iguales, si A entr� primero que B se atiende a A
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
    //resolver la solucion y a�adir pacientes
    for (int i = 0; i < nEvents; i++) {
        char type;
        cin >> type;
        if (type == 'I') { //a�adimos un paciente
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
