
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martín
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
using myQueue = std::priority_queue<Arista<int>, std::vector<Arista<int>>, std::greater<Arista<int>>>;
class ConstruirPuentes {
public:
	ConstruirPuentes(GrafoValorado<int> const& g) :
		coste(0),
		visit(vector<bool>(g.V(), false)),
		conexo(false),
		todosV(false)
	{
		ARM_Kruskal(g);
	}

	int getCoste() const& { return coste; }
	bool todosVertices()const { return todosV; }
	bool esConexo() const { return conexo; }
private:
	vector<Arista<int>> ARM;
	int coste;
	bool conexo;
	vector<bool> visit;
	bool todosV;

	void ARM_Kruskal(GrafoValorado<int> const& g) {
		myQueue q;
		auto aristas = g.aristas();
		for (int i = 0; i < aristas.size(); ++i) {
			q.push(aristas[i]);
		}
		ConjuntosDisjuntos cjts(g.V());
		while (!q.empty()) {
			auto a = q.top(); q.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjts.unidos(v, w)) {
				cjts.unir(v, w);
				ARM.push_back(a);
				coste += a.valor();
				visit[v] = visit[w] = true;
				if (ARM.size() == g.V() - 1) break;
			}
		}
		if (cjts.num_cjtos() == 1) conexo = true;
		if (cjts.cardinal(0) == g.V()) todosV = true;
	}
};


bool resuelveCaso() {

	// leer los datos de la entrada
	int V, E;
	cin >> V >> E;
	if (!std::cin)
		return false;

	GrafoValorado<int> archipelago = GrafoValorado<int>(V);
	int a, b, c;
	for (int i = 0; i < E; ++i) {
		std::cin >> a >> b >> c;
		archipelago.ponArista(Arista<int>(a - 1, b - 1, c));
	}
	ConstruirPuentes solucion = ConstruirPuentes(archipelago);
	if (solucion.esConexo() && solucion.todosVertices()) std::cout << solucion.getCoste() << '\n';
	else std::cout << "No hay puentes suficientes\n";

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
