
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martín
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Un vertice es sumidero si a el entran todos pero no sale ninguno.
AKA si el grado de salida es 0 y el de entrada es V-1.
Para ello hay que recorrer todos los vértices y comprobar primero si tiene grado de salida 0, si es así, despues comprobar el grado de entrada
Esto lo podemos hacer metiendo a mano las aristas y vertices y acumulando en un vector de tamaño v-1 los grados de entrada-salida


@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso18() {

	int v, a;
	cin >> v >> a;
	// leer los datos de la entrada
	if (!std::cin)  // fin de la entrada
		return false;


	//en caso de haber suficientes aristas como para que haya un sumidero, contamos
	Digrafo g = Digrafo(v);
	vector<int> entrada(v, 0);
	for (int i = 0; i < a; i++) {
		int from, to;
		cin >> from >> to;
		g.ponArista(from, to);
		entrada[to] += 1;
	}
	//los grafdos de salida se pueden contar mirando el numero de adyacentes
	int i = 0;
	while (i < v) {
		int gradoSalida = g.ady(i).size();
		if (gradoSalida == 0 && entrada[i] == v - 1) {
			cout << "SI " << i << "\n";
			return true;
		}
		i++;
	}

	//en otro caso, no hay
	cout << "NO" << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main18() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos18.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso18());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
