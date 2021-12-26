
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int voraz(list<int> pilas, int nPilas, int vCoche) {
	int numCoches = 0;
	while (!pilas.empty()) {
		//nunca ser� impar, ya que si queda una pila suelta, al escogerla como pila m�xima la lista se vaciar�
		int max = pilas.back(); pilas.pop_back();
		auto it = pilas.begin(); //iterador para recorrer de menor a mayor
		while (it!=pilas.end()) {
			if (max + *it >= vCoche) {
				numCoches++;
				pilas.erase(it);
				it = pilas.end();
			}
			else {
				pilas.erase(it);
				it = pilas.begin();
			}
		}
	}

	return numCoches;
}

void resuelveCaso() {

	// leer los datos de la entrada
	int nPilas, vCoche;
	cin >> nPilas >> vCoche;

	list<int> pilas;
	for (int i = 0; i < nPilas; i++) {
		int v;
		cin >> v;
		pilas.push_back(v);
	}
	// resolver el caso posiblemente llamando a otras funciones
	pilas.sort();
	// escribir la soluci�n
	cout << voraz(pilas, nPilas, vCoche) << '\n';
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
