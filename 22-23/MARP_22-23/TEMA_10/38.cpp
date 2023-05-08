
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 1000000;

bool resuelveCaso38() {

	int V, S;
	cin >> V >> S;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> puntos(S + 1);

	/*
	* disparos(i,j) numero de disparos para conseguir la puntuacion j, usando las secciones del 1 al i
	*
	* RECURSION:
		disparos(i,j) = puntos[i] > j?
						disparos(i-1,j) #me salto el dardo
						:
						min(disparos(i-1,j), disparos(i,j-puntos[i])+1)

	CASO BASE:
		disparos(0, j) = INF
		disparos(i,0) = 0;



	*/

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main38() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos38.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso38());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
