
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

struct pelicula {
    int ini;
    int fin;
};
bool operator<(const pelicula& a, const pelicula& b) {
    return a.fin < b.fin;
}
bool operator >(const pelicula& a, const pelicula& b) {
    return b < a;
}
using mQueue = priority_queue<pelicula, vector<pelicula>, std::greater<pelicula>>;

int voraz32(mQueue pelis) {
    int numPelis = 0, minAct = 0;
    while (!pelis.empty()) {
        pelicula p = pelis.top(); pelis.pop();
        if (p.ini >= minAct) {
            numPelis++;
            minAct = p.fin + 10;
        }
    }
    return numPelis;
}

bool resuelveCaso32exam() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N==0)  // fin de la entrada
        return false;
    mQueue pelis;
    int h, min, dur; char c;
    for (int i = 0; i < N; i++) {
        cin >> h >> c >> min >> dur;
        int ini = (h * 60) + min;
        pelis.push({ ini,ini + dur });
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << voraz32(pelis) << '\n';
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main32() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos32.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso32exam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
