
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

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"

/*@ <answer>

Hay que sacar el arm para saber cual de todos los puentes construir teniendo el minimo coste posible


@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

using myQueue = std::priority_queue<Arista<int>, std::vector<Arista<int>>, std::greater<Arista<int>>>;


class ARM {
public:

	ARM(GrafoValorado<int> const& g) : coste(0), visitaTodas(false), conexo(false) {
		myQueue pq;
		auto aristas = g.aristas();
		for (auto a : aristas)
			pq.push(a);
		ConjuntosDisjuntos cjtos(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste += a.valor();
				if (_ARM.size() == g.V() - 1) break;
			}
		}
		if (cjtos.num_cjtos() == 1) conexo = true;
		if (cjtos.cardinal(0) == g.V()) visitaTodas = true;
	}

	int costeARM() const {
		return coste;
	}
	std::vector<Arista<int>> const& getARM() const {
		return _ARM;
	}
	bool completo() { return visitaTodas; }
	bool hayCaminoUnico() { return conexo; }
private:
	std::vector<Arista<int>> _ARM;
	int coste;
	bool conexo;
	bool visitaTodas;
};


bool resuelveCaso23() {

	// leer los datos de la entrada
	GrafoValorado<int> milislotes = GrafoValorado<int>(cin, 1);
	if (!std::cin)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	if (milislotes.A() < milislotes.V() - 1) {
		cout << "No hay puentes suficientes\n";
		return true;
	}
	ARM sol = ARM(milislotes);
	if (!sol.completo() || !sol.hayCaminoUnico()) {
		cout << "No hay puentes suficientes\n";
		return true;
	}

	cout << sol.costeARM() << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos23.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso23());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
