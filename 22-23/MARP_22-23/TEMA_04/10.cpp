
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

Un grafo es un arbol libre si es aciclico y conexo (todo par de vertices esta conectado
por un unico camino)
Para ello hay que hacer un recorrido dfs e ir sumando en un contador
Si el contador despues de hacer un dfs es igual que el numero de vertices
Esta conectado por un unico camino

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ArbolLibre {
public:
	ArbolLibre(Grafo const& g, int s) : visit(g.V(), false),
		s(s) {
		cont = 0;
		dfs(g, s);
	}
	int getVisitedCount() { return cont; }

private:
	vector<bool> visit;
	int s;
	int cont; //cuenta cuantos vertices hay desde el origen

	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		cont++;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				dfs(G, w);
			}
		}
	}

};


bool resuelveCaso10() {

	// leer los datos de la entrada
	Grafo g = Grafo(cin, 0);
	if (!std::cin)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	if (g.A() != g.V() - 1) { //si no tiene exactamente 1 arista menos que vertices, no es aciclico
		cout << "NO" << "\n";
		return true;
	}
	ArbolLibre arbol = ArbolLibre(g, 0);
	// escribir la solución
	if (arbol.getVisitedCount() != g.V()) {
		cout << "NO" << "\n";
		return true;
	}
	cout << "SI" << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main10() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos10.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso10());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
