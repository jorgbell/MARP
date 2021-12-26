
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
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

struct Investigacion {
	int ini;
	int fin;
};

bool operator<(Investigacion const& a, Investigacion const& b) {
	return a.ini < b.ini;
}

int voraz(vector<Investigacion> investigaciones, int C, int F) {

	int nInvestigaciones = 0;
	int i = 0;
	int max = -1;
	Investigacion act = investigaciones[0];
	while (i < investigaciones.size() && C < F) {
		//Escoge el que, empezando en C o antes, acabe lo más tarde posible
		if (act.ini <= C && act.fin > max) {
			max = act.fin;
			i++;
		}
		//Si ya no hay mas posibilidades de escoger uno mejor antes, debe comprobar el siguiente intervalo
		else {
			nInvestigaciones++;
		}
		act = investigaciones[i];
	}
	C = max;
	nInvestigaciones++;

	return nInvestigaciones;

}

bool resuelveCaso() {

	// leer los datos de la entrada
	int C, F, N;
	cin >> C >> F >> N;
	if (C == 0 && N == 0 && F == 0)  // fin de la entrada
		return false;
	vector<Investigacion> investigaciones(N);

	for (int i = 0; i < N; i++) {
		cin >> investigaciones[i].ini >> investigaciones[i].fin;
	}
	// resolver el caso posiblemente llamando a otras funciones
	sort(investigaciones.begin(), investigaciones.end(), std::less<Investigacion>());
	// escribir la solución
	int sol = voraz(investigaciones, C, F);
	if (sol == N || sol == -1)
		cout << "Imposible" << endl;
	else
		cout << sol;
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
