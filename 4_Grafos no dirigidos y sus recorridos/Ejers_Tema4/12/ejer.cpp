
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Grafo.h"

/*@ <answer>

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>


class GruposAmigos {
public:
	GruposAmigos(Grafo const& g) :visit(g.V(), false),
		bigger(0) {
		for (int v = 0; v < g.V(); v++) {
			if (!visit[v]) {
				int cont = 1; //cada grupo de amigos tiene como minimo una persona
				dfs(g, v, cont);
				bigger = max(bigger, cont);
			}
		}
	}

	int getBigger() { return bigger; }
private:
	vector<bool> visit;
	int bigger;
	//no necesita de origen porque tendremos que mirar para todas las personas de la ciudad
	//ni de anteriores porque no queremos reconstruir el grupo de amigos
	void dfs(Grafo const& g, int v, int& cont) {
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (!visit[w]) {
				cont += 1;
				dfs(g, w, cont);
			}
		}
	}

};


void resuelveCaso() {

	// leer los datos de la entrada
	Grafo ciudad = Grafo(cin,1);
	// resolver el caso posiblemente llamando a otras funciones
	GruposAmigos sol = GruposAmigos(ciudad);
	// escribir la soluci�n
	cout << sol.getBigger() << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("in.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
