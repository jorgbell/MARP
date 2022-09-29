
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n y Tom�s L�pez Ant�n
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
    // escribir la soluci�n
    

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
