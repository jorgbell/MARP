
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"

/*@ <answer>

El arbol sera libre cuando haya visitado todos sus vertices y ademas el numero de aristas sea igual a V-1. Esto significa que
habrá pasado por todos los pares de vertices una sola vez.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ArbolLibre {
public:
    ArbolLibre(Grafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), s(s) {
        dfs(g, s); //llamada inicial
    }

    bool hayCamino(int v) const {
        return visit[v];
    }

private:
    vector<bool> visit;
    vector<int> ant; //quizas no es necesario en esto
    int s;//origen

    void dfs(Grafo const& g, int v) {
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(g, w);
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    Grafo g = Grafo(cin);
    if (!std::cin)  // fin de la entrada
        return false;
    // resolver el caso posiblemente llamando a otras funciones
    ArbolLibre sol = ArbolLibre(g, 0);
    bool conexo = true;
    int i = 0;
    //comprobamos que haya visitado todos los vertices
    while (i < g.V() && conexo) {
        if (sol.hayCamino(i))
            i++;
        else
            conexo = false;
    }
    // escribir la solución
    //si los visito todos y ademas el numero de aristas es igual a v-1, es arbol libre. En caso contrario, no lo es.
    if (conexo && g.A() == g.V() - 1)
        cout << "SI\n";
    else
        cout << "NO\n";
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
