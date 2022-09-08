
/*@ <answer>
*
* Nombre y Apellidos: Jorge Belo Martín
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

	Sabiendo el numero de musicos y el numero total de partituras, hay que dividir en atriles
	Tienen mas prioridad el grupo con mayor numero de instrumentos
	La prioridad es igual al numero de musicos entre el numero de partituras
	El numero de partituras que se le da a cada grupo = numero de subgrupos por cada grupo
	Se reparte una partitura a cada grupo y despues las que sobren se comprueban la prioridad
	Prioridad: NumMusicosGrupo/NumPartiturasActuales
		Ej: 8 musicos tienen una partitura -> prioridad de 8, le damos otra, pasa a tener prioridad de 4
			5 musicos tienen una partitura
	si hay muchas mas partituras que musicos y todos ya tienen 1 partitura, hay que acabar

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct atril {
	int numInstrumentos;
	int numPartituras;
};

bool operator<(const atril& a, const atril& b) {
	int prioridadA = a.numInstrumentos / a.numPartituras + (a.numInstrumentos%a.numPartituras > 0);
	int prioridadB = b.numInstrumentos / b.numPartituras + (b.numInstrumentos % b.numPartituras > 0);
	
	return prioridadA < prioridadB;

}
bool operator>(const atril& a, const atril& b) {
	return b < a;
}

int resolver10(int partiturasRestantes, priority_queue<atril> queue) {

	while (partiturasRestantes > 0) {
		atril a = queue.top();
		if (a.numInstrumentos == a.numPartituras)
			return 1;
		queue.pop();
		queue.push({ a.numInstrumentos, a.numPartituras + 1 });
		partiturasRestantes--;
	}
	atril masConcurrido = queue.top();
	return masConcurrido.numInstrumentos / masConcurrido.numPartituras + (masConcurrido.numInstrumentos % masConcurrido.numPartituras > 0);
	

}

bool resuelveCaso10() {

	// leer los datos de la entrada
	int p, n; //n= num instrumentos distintos
	cin >> p >> n;
	if (!std::cin)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	priority_queue<atril> queue;
	for (int i = 0; i < n; i++) {
		int nInstrumentos;
		cin >> nInstrumentos;
		queue.push({ nInstrumentos, 1 });
	}
	// escribir la solución
	cout << resolver10(p - n, queue) << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos10.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso10());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
