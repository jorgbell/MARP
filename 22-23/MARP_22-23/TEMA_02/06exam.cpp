
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;


/*@ <answer>

tareas unicas y periodicas
cada tarea tiene un comienzo c y una finalizacion f, ocupando f-c
las periodicas se añaden en el instante de finalizacion + T (ej: 100)

comprobar si el calendario esta libre de conflictos. Hay conflictos si se superponen.

tenemos que contar las tareas que sean desde el instante 0 hasta T.
hacer una cola que ordene un struct tarea de menor a mayor, siendo menor si su inicio es menor.
Se añaden tantas tareas como quepan en el tiempo total que piden.
Una vez añadidas todas, hacemos pop de las primeras, comparamos si hay un conflicto y continuamos

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Tarea {
	int ini;
	int fin;
	int periodicidad;
};

bool operator<(Tarea const& a, Tarea const& b) {
	return (a.ini < b.ini );
}
bool operator>(Tarea const& a, Tarea const& b) {
	return b < a;
}

using mQueue = priority_queue<Tarea, vector<Tarea>, std::greater<Tarea>>;

std::string conflicto(mQueue pq) {
	while (pq.size() > 1) {
		Tarea actual = pq.top(); pq.pop();
		Tarea siguiente = pq.top();
		if (siguiente.ini < actual.fin)
			return "SI\n";
	}
	return "NO\n";
}


bool resuelveCaso06exam() {

	// leer los datos de la entrada
	int N, M, T; //0..T
	cin >> N >> M >> T;
	if (!std::cin)  // fin de la entrada
		return false;

	mQueue pq;
	//añade las tareas unicas
	for (int i = 0; i < N; i++) {
		int ini, fin;
		cin >> ini >> fin;
		pq.push({ ini,fin,-1 });
	}
	//añade las tareas periodicas dentro del plazo que se requiere
	for (int i = 0; i < M; i++) {
		int ini, fin, t;
		cin >> ini >> fin >> t;
		while (ini < T) {
			pq.push({ ini,fin,t });
			ini += t; fin += t;
		}
	}
	cout << conflicto(pq);

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos06.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso06exam());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
