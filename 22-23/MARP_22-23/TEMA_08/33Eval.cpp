
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín y Tomás López Antón
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Tenemos que maximizar la cantidad de puntos de diferencia que pueden conseguir los broncos de boston.
Para ello, lo que debemos hacer es ordenar de mayor a menor los puntos de los broncos de boston, que estan desordenados
Los de los rivales ordenarlos de menor a mayor
Parar cuando los puntos de los rivales sean mayores que los de los broncos de boston


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int voraz33(vector<int>resRivales, vector<int>resBroncos, int nPartidos) {
	int puntos = 0;
	int i = 0;
	bool end = false;
	while (!end) {
		int diff = resBroncos[i] - resRivales[i];
		if (i >= nPartidos || diff <= 0) { //condicion para salir del bucle: ya no hay más o la diferencia es negativa
			end = true;
			break;
		}
		puntos += diff;
		i++;
	}
	return puntos;
}

bool resuelveCaso33() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N <= 0)  // fin de la entrada
		return false;
	vector<int>resRivales(N);
	vector<int>resBroncos(N);
	for (int i = 0; i < N; i++)
		cin >> resRivales[i];
	for (int i = 0; i < N; i++)
		cin >> resBroncos[i];
	// resolver el caso posiblemente llamando a otras funciones
	sort(resRivales.begin(), resRivales.end());
	sort(resBroncos.begin(), resBroncos.end(), greater<int>());
	// escribir la solución
	cout << voraz33(resRivales, resBroncos, N) << '\n';
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main33eval() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos33.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso33());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
