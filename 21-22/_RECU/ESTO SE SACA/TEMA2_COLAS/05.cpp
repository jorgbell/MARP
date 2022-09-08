
/*@ <answer>
 *
 * Nombre y Apellidos:
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


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct paciente {
	string name;
	int64_t gravedad;
	int64_t orden; //"tiempo" que llevan esperando desde que ingresaron
};

bool operator<(const paciente& a, const paciente& b) {
	return (a.gravedad < b.gravedad ||
		(a.gravedad == b.gravedad && a.orden > b.orden));
}

bool operator>(const paciente& a, const paciente& b) {
	return b < a;
}

using mQueue = priority_queue<paciente, vector<paciente>, std::less<paciente>>;


bool resuelveCaso5() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0)
		return false;
	mQueue pq;

	for (int i = 0; i < N; i++) {
		char ev;
		cin >> ev;
		string n; int g;

		switch (ev) {
		case 'I':
			cin >> n >> g;
			pq.push({ n,g,i });
			break;
		case 'A':
			cout << pq.top().name +'\n';
			pq.pop();
			break;
		}
	}

	cout << "---\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos5.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso5());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
