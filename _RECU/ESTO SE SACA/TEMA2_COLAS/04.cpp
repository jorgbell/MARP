
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

 Cuando entra un nuevo usuario, su info saldrá con el valor X de periodo después.
 Será por tanto una cola de prioridad de minimos en las que se van ordenando segun el periodo
 En dicha cola se añaden primero los usuarios que se han registrado
 Cuando sacas uno, lo añades sumándole su x periodicidad (ej: si tiene 200, el nuevo tendrá 400)


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct user {
	int64_t id; //identificador
	int64_t period; //periodo fijo
	int64_t time; //tiempo hasta la siguiente entrega
};

bool operator<(const user& a, const user& b) {
	return(a.time < b.time ||
		(a.time == b.time) && a.id < b.id);
}
bool operator>(const user& a, const user& b) {
	return b < a;
}

using myQueue = priority_queue<user, vector<user>, greater<user>>;


void resolver4(myQueue queue, int64_t k) {
	for (int i = 0; i < k; i++) {
		user u = queue.top(); queue.pop();
		cout << u.id << '\n';
		queue.push({ u.id,u.period, u.period + u.time });
	}
}

bool resuelveCaso4() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0)
		return false;

	myQueue pq;

	for (int i = 0; i < N; i++) {
		int64_t id; int64_t period;
		cin >> id >> period;
		pq.push({ id,period, period+0}); //instante de tiempo inicial
	}
	int64_t nEnvios;
	cin >> nEnvios;
	// resolver el caso posiblemente llamando a otras funciones
	resolver4(pq, nEnvios);
	// escribir la solución
	cout << "---\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main4() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos4.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso4());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
