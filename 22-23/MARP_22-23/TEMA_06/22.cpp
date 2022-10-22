
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martin
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
#include "GrafoValorado.h"
/*@ <answer>

Tenemos un grafo valorado cuyas aristas tienen el valor de la anchura del camion.
Tenemos un camion con umbral x y tenemos que ver si es posible que pueda llegar de un punto concoreto a otro
Para ello hacemos un dfs pero no es necesario un ARM porque tampoco nos estan pidiendo nada de que tenga el menor tama�o ni nada
Solo saber si es posible visitar un vertice V desde el origen teniendo en cuenta el umbral


@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

class Ciudad {
public:
	Ciudad(GrafoValorado<int> const& g, int s, int tam) : visit(g.V(), false), s(s) {
		dfs(g, s, tam);
	}

	void hayCamino(int destino) {
		if (visit[destino])
			cout << "SI\n";
		else
			cout << "NO\n";
	}
private:

	vector<bool> visit;
	int s;
	void dfs(GrafoValorado<int> const& G, int v, int umbral) {
		visit[v] = true;
		for (auto a : G.ady(v)) {
			if (a.valor() >= umbral) {
				int w = a.otro(v);
				if (!visit[w])
					dfs(G, w, umbral);
			}
		}
	}
};

bool resuelveCaso22() {

	// leer los datos de la entrada
	GrafoValorado<int> g = GrafoValorado<int>(cin, 1);
	if (!std::cin)  // fin de la entrada
		return false;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		Ciudad c = Ciudad(g, a - 1, v);
		c.hayCamino(b - 1);
	}


	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main22() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos22.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso22());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
