
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martín
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Debemos recorrer todo el grafo hasta que todos los vértices sean visitados
Ademas mientras lo recorres cada vez que visitas todos los adyacentes a un vertice apuntas el numero de vertices recorridos
Cuando se visite todo simplemente devolvemos ese maximo

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class GruposAmigos {

public:
	GruposAmigos(Grafo const& g) : visit(g.V(), false), maximo(0) {
		for (int i = 0; i < g.V(); i++) {
			int nAdys = 1; // siempre se conoce minimo a si mismo
			dfs(g, i, &nAdys);
			maximo = max(maximo, nAdys);
		}
	}
	int grupoMayor() { return maximo; }

private:
	vector<bool> visit;
	int maximo;

	void dfs(Grafo const& G, int v, int* nadys) {
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				*nadys = *nadys+1;
				dfs(G, w, nadys);
			}
		}
	}
};


bool resuelveCaso12() {

	// leer los datos de la entrada
	Grafo g = Grafo(cin, 1);
	// resolver el caso posiblemente llamando a otras funciones
	GruposAmigos grupo = GruposAmigos(g);
	// escribir la solución
	cout << grupo.grupoMayor() << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main12() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos12.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso12();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}