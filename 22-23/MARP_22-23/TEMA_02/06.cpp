
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>
	Como lo que hay que hacer es solo mirar si esta libre de conflicto, hay que ordenarlas de inicio a fin y ya esta.
	Despues, comprobar todas las tareas hasta encontrar una que su fin sea mayor que el ini del siguiente
	Si es periodica, hay que a�adirla tantas veces como permita T

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


struct tarea {
	int ini;
	int fin;
	int repeticion;
};

bool operator<(const tarea& a, const tarea& b) {
	return (a.ini < b.ini);
}
bool operator>(const tarea& a, const tarea& b) {
	return b < a;
}

using mQueue = priority_queue<tarea, vector<tarea>, std::greater<tarea>>;

bool conflictos(mQueue agenda, int T) {
	//si la tarea es periodica, se a�adira de nuevo con un nuevo ini

	while (agenda.size()>1) {
		tarea actual = agenda.top(); agenda.pop();
		tarea siguiente = agenda.top();
		if (actual.fin < siguiente.ini)
			return false;
		else if (actual.repeticion > 0 && actual.repeticion + actual.ini <= T)
			agenda.push({ actual.ini + actual.repeticion, actual.fin + actual.repeticion, actual.repeticion });
	}
	return true;
}

bool resuelveCaso6() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!cin)
		return false;
	int M, T;
	cin >> M >> T;

	mQueue agenda;
	//lee las tareas unicas
	for (int i = 0; i < N; i++) {
		int ini, fin;
		cin >> ini >> fin;
		//a�ade las tareas
		agenda.push({ ini,fin,0 });
	}
	for (int i = 0; i < M; i++) {
		int ini, fin, period;
		cin >> ini >> fin >> period;
		//a�adir las tareas
		agenda.push({ ini,fin,period });
	}

	//comprueba si hay conflictos
	cout << (conflictos(agenda,T) ? "SI\n" : "NO\n");

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main06() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos06.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso6());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
