
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

using myQueue = priority_queue<int64_t, vector<int64_t>, greater<int64_t>>;

int64_t resolver(myQueue sumandos) {

	int64_t esfuerzo = 0;

	while (sumandos.size() >1 ) {
		int64_t a = sumandos.top(); sumandos.pop();
		int64_t b = sumandos.top(); sumandos.pop();
		esfuerzo += (a+b);
		sumandos.push(a + b);
	}
	return esfuerzo;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	myQueue sumandos;
	for (int i = 0; i < N; i++) {
		int64_t n;
		cin >> n;
		sumandos.push(n);
	}
	// escribir la solución
	cout << resolver(sumandos) << endl;
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
