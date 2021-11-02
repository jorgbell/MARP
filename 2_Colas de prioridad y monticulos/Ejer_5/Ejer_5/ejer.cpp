
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

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
    int gravedad;
    int orden;
};
//la ventaja de definir el menor es que luego en la cola de prioridad no hay que identificar que el comparador sea otro, porque STL usa de manera predefinida el menor
//La cola de la STL es una cola de m�ximos, por lo que dado un orden, va a considerar m�s prioritario el segundo argumento, por lo que
//Hay que valorar cuando B sea m�s prioritario, es decir, cuando tenga una gravedad mayor
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
        if (action == 'I') { //La acci�n a realizar es a�adir un nuevo paciente
            cin >> name >> val;
            q.push({ name, val, orden++ });
        }
        else { //La acci�n a realizar es tratar al paciente m�s prioritario
            cout << q.top().name << '\n';
            q.pop();
        }
    }
    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
