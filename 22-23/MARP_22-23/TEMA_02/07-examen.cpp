
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

LA REINA DEL SUPER:
una linea por cliente, cada linea tiene los segundos que tardara en ser atendido.
Imprimir el numero de la caja en la que será atendido Ismael si se coloca al final.

cada caja tiene el id y los segundos que quedan para estar libre. 
en la fila unica, el siguiente cliente acabara yendo a la fila que le queden menos segundos.

usamos una pqueue para ordenar las cajas según el tiempo. De menor tiempo a mayor tiempo
cuando entra un nuevo numero de segundos, se sumara a la caja que tenga menor tiempo
La caja de ismael sera la que quede con menor tiempo

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Caja {
    int id;
    int t;
};

bool operator<(Caja const& a, Caja const& b) {
    return a.t < b.t || ((a.t == b.t) && a.id < b.id);
}
bool operator>(Caja const& a, Caja const& b) {
    return b < a;
}

using mQueue = priority_queue<Caja, vector<Caja>, std::greater<Caja>>;

bool resuelveCaso07exam() {

    // leer los datos de la entrada
    int C, N;
    cin >> N >> C;
    if (N==0 && C == 0)
        return false;

    mQueue q;
    for (int i = 0; i < N; i++) {
        q.push({ i+1,0 }); //id,tiempo
    }
    for (int i = 0; i < C; i++) {
        int t;
        cin >> t;
        Caja c = q.top(); q.pop();
        q.push({ c.id, c.t + t });
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << q.top().id<<'\n';
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main07exam() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos07.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso07exam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
