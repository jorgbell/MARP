/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Estudiante 1: Jorge Bello Martín
  * Estudiante 2: Tomás López Antón
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>

 Creamos una cola de prioridad basada en el número de cajas, cada una con un struct "caja" que posee
 el número de identificación y la cantidad de segundos que tardará en quedar libre. Esta cola esta ordenada 
 de forma que el primer valor sea el que tenga el menor número de segundos, quedando primera en caso de empate 
 la que tenga el número de identificación más bajo.

 Después leemos los datos de los clientes y los introducimos en una cola first in first out.

 Para resolver el caso, recorremos la cola de clientes, eliminando el primer elemento una vez leido su valor,
 y sumamos este valor al elemento más prioritario de nuestra cola de prioridad de cajas.

 Una vez la cola de clientes ha quedado vacía, nuestro metodo devuelve el numero de identificación del primer
 elemento de nuestra cola de prioridad.

 Siendo C el número de clientes y N el numero de cajas, el orden de complejidad de nuestra función de lectura
 "resuelveCaso" es O(C + N * logN) y el orden de complejidad de la función "resolver" es O(C * logN)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>


struct caja {
	int id;
	int tiempoTrabajo;
};

bool operator<(const caja& a, const caja& b) {
	return a.tiempoTrabajo < b.tiempoTrabajo ||
		((a.tiempoTrabajo == b.tiempoTrabajo) && (a.id < b.id));

}
bool operator>(const caja& a, const caja& b) {
	return b < a;
}

using mQueue = priority_queue<caja, vector<caja>, std::greater<caja>>;

int resolver07(mQueue cajas, queue<int> clientes) {
	while (!clientes.empty()) { //O(C)
		int actual = clientes.front(); clientes.pop(); //O(1)
		caja c = cajas.top(); cajas.pop(); //O(logN) //pilla la caja con mayor prioridad (la que antes se vaciara) 
		cajas.push({ c.id,c.tiempoTrabajo + actual }); //O(logN) //añade de nuevo a la cola con el tiempo del cliente sumado a su trabajo pendiente
	}
	return cajas.top().id; //O(1)
}

bool resuelveCaso07() {

	// leemos la entrada
	int N, C;
	cin >> N >> C;
	if (N == 0)
		return false;
	queue<int> clientes;
	for (int i = 0; i < C; i++) { //O(C)
		int a;
		cin >> a;
		clientes.push(a); //O(1)
	}
	mQueue cajas;
	for (int i = 0; i < N; i++) //O(N)
		cajas.push({ i+1,0 }); //O(logN)
	// leer el resto del caso y resolverlo
	
	cout << resolver07(cajas, clientes) << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos07.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso07());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
