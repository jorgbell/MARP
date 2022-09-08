
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martín
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

#include "Digrafo.h"

/*@ <answer>


@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Necronomicon {
	//usaremos BFS
public:
	Necronomicon(Digrafo const& g, int s) :
		visit(g.V(), false),
		ciclo(false),
		s(s)
	{
		bfs(g);
	}

	bool hayCiclo() const { return ciclo; }
	bool hayCamino(int v) const {
		return visit[v];
	}

private:
	vector<bool> visit;
	bool ciclo;
	int s;

	void bfs(Digrafo const& g) {
		queue<int> q;
		visit[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					visit[w] = true;
					q.push(w);
				}
				else //dado que es un programa lineal, el cuanto vuelva a alguno que ya ha sido visitado quiere decir que hay un bucle
					ciclo = true;
			}
		}
	}

};


bool resuelveCaso() {

	// leer los datos de la entrada
	int L;
	cin >> L;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo programa = Digrafo(L + 1); //sumamos una más para usarla como final del programa, el cual solo se puede llegar si está conectado con la última linea
	char inst;
	int salto;

	for (int i = 0; i < L; i++) {
		cin >> inst;
		switch (inst) {
		case 'A':
			programa.ponArista(i, i + 1);//podreos hacerlo siempre porque teneos un nodo fantasma que apunta al final del programa
			break;
		case 'J':
			cin >> salto;
			programa.ponArista(i, salto);
			break;
		case 'C':
			cin >> salto;
			programa.ponArista(i, salto);
			programa.ponArista(i, i + 1);//podreos hacerlo siempre porque teneos un nodo fantasma que apunta al final del programa
			break;
		}
	}
	// resolver el caso posiblemente llamando a otras funciones
	Necronomicon sol = Necronomicon(programa,0);

	// escribir la solución
	if (!sol.hayCamino(programa.V() - 1)) {
		cout << "NUNCA\n";
	}
	else {
		if (sol.hayCiclo()) {
			cout << "A VECES\n";
		}
		else
			cout << "SIEMPRE\n";
	}

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
