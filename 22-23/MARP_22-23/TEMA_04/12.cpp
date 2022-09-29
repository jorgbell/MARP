
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín y Tomás López Antón
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

bool resuelveCaso12() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0)
        return false;

    priority_queue<int, vector<int>, std::greater<int>> pajaros;
    pajaros.push(N);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pajaros.push(a); pajaros.push(b);
        priority_queue<int, vector<int>, std::greater<int>> alt(pajaros);
        for (int i = 0; i < alt.size() / 2; i++) {
            alt.pop();
        }
        cout << alt.top() << " ";

    }
    // escribir la solución
    

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos12.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso12());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
