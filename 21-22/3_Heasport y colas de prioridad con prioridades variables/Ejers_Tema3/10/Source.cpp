
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct Atril {
    int numMusicos;
    int partituras = 1; //se inicializa a 1 porque minimo tienen que tener una partitura
};

bool operator<(const Atril& a, const Atril& b) {
    int prioridadA = a.numMusicos / a.partituras + (a.numMusicos%a.partituras>0);
    int prioridadB = b.numMusicos / b.partituras + (b.numMusicos % b.partituras>0);

    return prioridadA < prioridadB;
}

int resolver(priority_queue<Atril> orquesta, int numPartituras) {
    
    while (numPartituras > 0) {
        Atril a = orquesta.top();  
        if (a.numMusicos == a.partituras)
            return 1;
        orquesta.pop();
        orquesta.push({ a.numMusicos, a.partituras + 1 });
        numPartituras--;
    }
    Atril masConcurrido = orquesta.top();
    int sol = masConcurrido.numMusicos / masConcurrido.partituras + (masConcurrido.numMusicos % masConcurrido.partituras > 0);
    return sol;
    

}

bool resuelveCaso() {

    // leer los datos de la entrada
    int P, N;
    cin >> P >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    priority_queue<Atril> orquesta;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        orquesta.push({ n });
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << resolver(orquesta, P-N) << '\n';
    // escribir la soluci�n

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
