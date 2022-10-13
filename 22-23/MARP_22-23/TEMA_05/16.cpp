
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Hay que realizar una ordenacion topologica. Tambien hay que comprobar que sea aciclico porque si no no sera posible.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

class Tareas {
public:
	Tareas(Digrafo const& g) : visit(g.V(), false),
		apilado(g.V(), false), hayciclo(false) {
		for (int v = 0; v < g.V(); ++v)
			if (!visit[v])
				dfs(g, v);
	}
	bool hayCiclo() const { return hayciclo; }
	// devuelve la ordenaci�n topol�gica
	std::deque<int> const& orden() const {
		return _orden;
	}
private:
	std::vector<bool> visit; // visit[v] = �se ha alcanzado a v en el dfs?
	std::vector<bool> apilado; // apilado[v] = �est� el v�rtice v en la pila?
	std::deque<int> _orden; // ordenaci�n topol�gica

	bool hayciclo;

	void dfs(Digrafo const& g, int v) {
		apilado[v] = true;
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (hayciclo) // si hemos encontrado un ciclo terminamos
				return;
			if (!visit[w])  // encontrado un nuevo v�rtice, seguimos
				dfs(g, w);
			else if (apilado[w]) { // hemos detectado un ciclo
				hayciclo = true;
				//no recuperamos el ciclo porque no es necesario
			}
		}
		apilado[v] = false;
		_orden.push_front(v);
	}
};

bool resuelveCaso16() {

	// leer los datos de la entrada
	Digrafo g = Digrafo(cin, 1);
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	Tareas t = Tareas(g);
	if (t.hayCiclo()) {
		cout << "Imposible" << "\n";
		return true;
	}

	auto orden = t.orden();

	while (!orden.empty()) {
		int n = orden.front() + 1; orden.pop_front();
		cout << n << " ";
	}
	cout << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main16() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos16.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso16());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
