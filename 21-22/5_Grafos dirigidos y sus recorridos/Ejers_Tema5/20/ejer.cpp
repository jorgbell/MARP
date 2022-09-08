
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#include "Digrafo.h"

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


class CaminoMasCorto {
public:
    CaminoMasCorto(Digrafo const& g, int s) :
        visit(g.V(), false),
        ant(g.V()),
        dist(g.V()),
        s(s)
    {
        bfs(g);
    }
    //siempre habra camino y no necesitamos hacerlo, asi que no necesitaremos esas comprobaciones
    int distancia(int v) const {
        return dist[v];
    }

private:
    vector<bool> visit;
    vector<int> ant;
    vector<int>dist;
    int s;

    void bfs(Digrafo const& g) {
        queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v]+1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int N, K, S, E;
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0)  // fin de la entrada
        return false;
    Digrafo tablero = Digrafo(N * N);
    vector<int> paths(N * N, -1);
    for (int i = 0; i < S+E; i++) {
        int from, to;
        cin >> from >> to;
        paths[from - 1] = to - 1; //marca los caminos de serpientes y escaleras
    }
    //poner el resto de casillas normales
    for (int i = 0; i < N * N; i++) {
        int j = 1;
        bool max = false;
        while (!max && j <= K) {
            int actual = i + j;
            if (actual >= N * N) {
                max = true;
                break;
            }
            //si hemos guardado en el vector un camino posible, significa que al llegar a la casilla J en lugar de estar en J estará en la que indique su camino.
            //Si no hay camino alternativo posible, al llegar a J estará en J.
            if (paths[actual] != -1)
                tablero.ponArista(i, paths[actual]);
            else
                tablero.ponArista(i, actual);
            j++;
        }
    }
    //una vez puestas las aristas segun el tablero, debemos hayar el camino mas corto
    CaminoMasCorto sol = CaminoMasCorto(tablero,0);
    // resolver el caso posiblemente llamando a otras funciones
    cout << sol.distancia((N*N)-1)<<'\n';
    // escribir la solución

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
