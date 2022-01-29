
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Mart�n
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#include "Digrafo.h"

/*@ <answer>

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>


class OrdenaTareas {
	//ordenacion topologica
public:
	OrdenaTareas(Digrafo const& g) :
		visit(g.V(), false),
		apilado(g.V(), false),
		ciclo(false)
	{
		for (int v = 0; v < g.V(); v++) {
			if (!visit[v]) //por cada componente conexa
				dfs(g, v);
		}
	}

	bool hayCiclo() const { return ciclo; }
	deque<int> const& getOrden() const {
		return orden;
	}

private:
	vector<bool> visit;
	deque<int> orden;
	//vector<int> ant; //no lo necesitamos ya que no necesitamos reconstruir el ciclo
	vector<bool> apilado;
	bool ciclo;

	void dfs(Digrafo const& g, int v) {
		apilado[v] = true; //est� llamandose, hasta que no se acabe no lo quitaremos del vector para asi saber si hay ciclo o no
		visit[v] = true; //lo acabamos de visitar
		for (int w : g.ady(v)) {
			if (hayCiclo()) //terminaremos la llamada si hemos encontrado un ciclo
				return;
			if (!visit[w]) { //seguimos mirando el resto de vertices
				dfs(g, w);
			}
			else if (apilado[w]) { //hemos detectado un ciclo que aun no se ha marcado
				ciclo = true; //aqui recuperariamos el ciclo pero no nos interesa en este problema
			}
		}
		apilado[v] = false; //hemos acabado su llamada y negamos la posibilidad de haber ciclos
		orden.push_front(v); //a�adimos al orden una vez hemos acabado todas las llamadas recursivas
	}

};



bool resuelveCaso() {

	// leer los datos de la entrada
	Digrafo tareas = Digrafo(cin,1);
	if (!std::cin)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	OrdenaTareas sol = OrdenaTareas(tareas);
	// escribir la soluci�n
	if (sol.hayCiclo())
		cout << "Imposible\n";
	else {
		deque<int> ordenFinal = sol.getOrden();
		while (!ordenFinal.empty()) {
			int n = ordenFinal.front(); ordenFinal.pop_front();
			cout << n +1<< " ";
		}
		cout << '\n';
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
