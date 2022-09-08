
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int voraz(vector<int> tropasCity, vector<int>tropasDefensas) {

	int exitos = 0;
	int i = 0; //contador ciudad
	int j = 0; //contador defensas
	while (i < tropasDefensas.size()) {
		if (tropasDefensas[i] >= tropasCity[j]) { //se puede defender esta ciudad
			exitos++;
			j++;
		}
		i++;
	}
	return exitos;	
}

bool resuelveCaso() {

	int N; //num ciudades y equipos defensores
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> tropasCity;
	vector<int> tropasDefensas;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		tropasCity.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		tropasDefensas.push_back(x);
	}
	sort(tropasCity.begin(), tropasCity.end());
	sort(tropasDefensas.begin(), tropasDefensas.end());
	// escribir la solución

	cout << voraz(tropasCity, tropasDefensas) << endl;
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
