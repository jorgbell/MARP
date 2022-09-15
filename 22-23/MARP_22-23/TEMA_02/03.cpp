
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Necesitamos conseguir el minimo esfuerzo para las sumas. Como se consigue?
	Esfuerzo = resultado de la suma de pares acumulados-> 1+2+3 = esfuerzo (1+2) + esfuerzo(3+3) = 3 + 6 = 9
	Si ordenamos de menor a mayor el esfuerzo será minimo -> 3+2 = 5 ; 5+1 = 6 -> esfuerzo = 5+6 = 11 --> 9<11

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using myQueue = priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>>;

int64_t resolverX(myQueue queue) {
	int64_t esfuerzo = 0;
	while (queue.size() > 1) {
		int64_t a = queue.top(); queue.pop();
		int64_t b = queue.top(); queue.pop();
		esfuerzo += (a + b);
		queue.push(a + b);
	}

	return esfuerzo;
}

bool resuelveCasoX() {

	// leer los datos de la entrada
	int64_t N;
	cin >> N;
	if (N == 0)
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	myQueue pq;
	for (int i = 0; i < N; i++) {
		int64_t k;
		cin >> k;
		pq.push(k);
	}
	// escribir la solución
	cout << resolverX(pq) << endl;
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main03() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos3.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCasoX());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
