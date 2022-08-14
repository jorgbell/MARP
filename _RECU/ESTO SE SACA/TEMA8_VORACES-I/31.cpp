
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Hay que maximizar el numero de exitos garantizados
Primero tenemos el numero de enemigos, despues el numero de defensas
Si ordenamos de menor a mayor ambos vectores podemos ajustar y elegir siempre el que mas se acerque a la ciudad que queremos vencer

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using myQueue = priority_queue<int, vector<int>, std::greater<int>>;

int resuelve31(myQueue enemigos, myQueue aliados) {
	int solucion = 0;
	//compara y cuenta cuantas se salvan
	while (!enemigos.empty() && !aliados.empty()) {
		int e = enemigos.top();
		int a = aliados.top();
		if (a >= e) {
			enemigos.pop();
			solucion += 1;
		}
		aliados.pop(); //SIEMPRE avanzamos aqui, puesto que si es menor que el de los enemigos, siempre sera menor que el resto de ciudades
	}
	return solucion;
}

bool resuelveCaso31() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	myQueue enemigos;
	myQueue aliados;
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		enemigos.push(n);
	}
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		aliados.push(n);
	}

	// escribir la solución
	cout << resuelve31(enemigos, aliados) << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main31() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos31.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso31());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
