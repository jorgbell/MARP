/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Jorge Bello Martín
  * Estudiante 2: Tomás López Antón
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Escribe también una demostración que justifique que tu solución encuentra
 siempre soluciones óptimas.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>



bool resuelveCaso39() {

	int N, PMax, PMin;
	cin >> N >> PMax >> PMin;
	if (!cin)  return false;

	if (N == 0)
		return false;

	vector<int> potTipo;
	vector<int> costTipo;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		potTipo.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		costTipo.push_back(a);
	}

	// leer el resto del caso y resolverlo
	Matriz<EntInf> pot(N + 1, PMax + 1, Infinito);

	pot[0][0] = 0;

	for (int i = 1; i <= PMax; i++) {
		pot[i][0] = Infinito;
	}
	for (int j = 1; j <= N; j++) {
		pot[0][j] = 0;
	}

	//for (int i = 0; i <= PMax; i++) {
	//	for (int j = 1; j <= N; ++j) {
	//		pot[i][j] = potTipo[i] > j ?
	//			pot[i - 1][j] :
	//			pot[i][j] = min(pot[i - 1][j], pot[i][j - puntos[i]] + 1);

	//		if (pot[i][j] < Infinito)
	//			cout << disparos[i][j] << " ";
	//		else
	//			cout << ". ";
	//	}
	//}



	return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main39() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos39.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso39());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// system("PAUSE");
#endif
	return 0;
}
