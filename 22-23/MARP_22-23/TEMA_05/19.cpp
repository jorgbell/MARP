
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

#include "Digrafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

Cuadricula de N x N casillas (N2 casillas)
Las serpientes van de arriba a abajo y las escaleras van de abajo a arriba
Una casilla solo puede ser extremo o de una serpiente o de una escalera aka dos nodos no estaran conectados con otros
La primera y la ultima nunca son extremos -> se suman siempre como minimo esos dos movimientos
Se tira un dado K y se avanza. Si se pisa un extremo out de una serpiente, se baja a la casilla con la que conecta, con la escalera al contrario

PROBLEMA: Cuantos movimientos habria que realizar para terminar la partida lo antes posible
AKA cual es el camino mas corto en un grafo dirigido para llegar desde el origen (1) hasta el destino (100)
Para hallar un camino mas corto hacemos recorrido en anchura
Devolver el tamaño del camino

Las conexiones son las que digan las serpientes y escaleras Y conexiones normales con cada uno de los tamaños del dado
Es decir, si el dado tiene 6 caras, la casilla i conecta con i+1,i+2,i+3,i+4, i+5,i+6
Y si alguno de esos coincide con una punta de serpiente o escalera, conectara con la que diga esa conexion
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CaminoMasCorto {
public:
	CaminoMasCorto(Digrafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), dist(g.V()), s(s) {
		bfs(g);
	}
	bool hayCamino(int v) const {
		return visit[v];
	}
	int distancia(int v) const {
		return dist[v];
	}

private:
	vector<bool> visit;
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
	int s;

	void bfs(Digrafo const& g) {
		std::queue<int> q;
		dist[s] = 0; visit[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
					q.push(w);
				}
			}
		}
	}
};

bool resuelveCaso19() {

	// leer los datos de la entrada
	int N, K, S, E;
	cin >> N >> K >> S >> E;
	if (N == 0 && K == 0 && S == 0 && E == 0)
		return false;
	int size = N * N;
	Digrafo g = Digrafo(size);
	vector<int> caminos(size, -1);
	//añade las aristas de serpientes y escaleras
	for (int i = 0; i < S + E; i++) {
		int from, to;
		cin >> from >> to;
		caminos[from - 1] = to - 1; //lo guardamos para añadirlo despues
	}
	//añade las aristas de los movimientos normales
	for (int i = 0; i < size - 1; i++) {//de 0 a 98, para meter desde 0 a 99

		int j = 0; //para recorrer el dado
		bool tope = false;
		while (!tope && j < K) {
			int to = i + j + 1; //casilla a la que alcanza la actual
			if (to > size - 1) //si se sale del tablero
				tope == true;
			else {
				//si puede llegar, añade uno ya sea serpiente escalera o normal
				if (caminos[to] != -1)
					g.ponArista(i, caminos[to]);
				else
					g.ponArista(i, to);
			}
			j++;
		}
	}
	// resolver el caso posiblemente llamando a otras funciones
	CaminoMasCorto sol = CaminoMasCorto(g, 0);
	//siempre habrá camino porque hay aristas entre todas las casillas
	cout << sol.distancia(size - 1) << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main19() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos19.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso19());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
