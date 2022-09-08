
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martin
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#include "GrafoValorado.h"

/*@ <answer>

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

class CaminosPosibles {
public:
	CaminosPosibles(GrafoValorado<int>const& g,int origen, int destino, int camion) :
		visit(g.V(), false),
		camino(false) {
		dfs(g, origen, destino, camion);
	}
	bool hayCamino() const& { return camino; }
private:
	vector<bool> visit;
	bool camino;
	void dfs(GrafoValorado<int> const& G, int v, int end, int umbral) {
		visit[v] = true;
		for (auto a : G.ady(v)) {
			if (camino)
				return;
			if (a.valor() >= umbral) {
				int w = a.otro(v);
				if (w == end) {
					camino = true;
					return;
				}
				if (!visit[w])
					dfs(G, w, end, umbral);
			}
		}
	}
};


bool resuelveCaso() {

	// leer los datos de la entrada
	GrafoValorado<int> ciudad = GrafoValorado<int>(cin,1);
	if (!std::cin)  // fin de la entrada
		return false;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int origen, destino, camion;
		cin >> origen >> destino >> camion;
		CaminosPosibles solK = CaminosPosibles(ciudad, origen-1, destino-1, camion);
		if (solK.hayCamino())
			cout << "SI\n";
		else
			cout << "NO\n";
	}


	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
