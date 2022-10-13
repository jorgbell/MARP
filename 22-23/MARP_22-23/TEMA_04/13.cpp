
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n y Tom�s L�pez Ant�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
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
using mQueue = priority_queue<int, vector<int>, std::greater<int>>;


void resolver13(priority_queue<int>&cola1, mQueue & cola2, int n) {
    int a = cola1.top();
    if (n > a)
        cola2.push(n);
    else
        cola1.push(n);

    int s1 = cola1.size(); int s2 = cola2.size();

    if (s1-s2 > 1) {
        int top = cola1.top(); cola1.pop(); cola2.push(top);
    }
    else if (s2-s1 > 1) {
        int top = cola2.top(); cola2.pop(); cola1.push(top);
    }

}


bool resuelveCaso13() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0)
        return false;

    priority_queue<int> cola1;
    cola1.push(N);
    mQueue cola2;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        resolver13(cola1, cola2, a);
        resolver13(cola1, cola2, b);
        cout << cola2.top() << " ";
    }
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main13() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos13.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso13());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
