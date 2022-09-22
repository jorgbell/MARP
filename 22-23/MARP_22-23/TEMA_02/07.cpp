/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Estudiante 1: Jorge Bello Mart�n
  * Estudiante 2: Tom�s L�pez Ant�n
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>

 Creamos una cola de prioridad basada en el n�mero de cajas, cada una con un struct "caja" que posee
 el n�mero de identificaci�n y la cantidad de segundos que tardar� en quedar libre. Esta cola esta ordenada 
 de forma que el primer valor sea el que tenga el menor n�mero de segundos, quedando primera en caso de empate 
 la que tenga el n�mero de identificaci�n m�s bajo.

 Despu�s leemos los datos de los clientes y los introducimos en una cola first in first out.

 Para resolver el caso, recorremos la cola de clientes, eliminando el primer elemento una vez leido su valor,
 y sumamos este valor al elemento m�s prioritario de nuestra cola de prioridad de cajas.

 Una vez la cola de clientes ha quedado vac�a, nuestro metodo devuelve el numero de identificaci�n del primer
 elemento de nuestra cola de prioridad.

 Siendo C el n�mero de clientes y N el numero de cajas, el orden de complejidad de nuestra funci�n de lectura
 "resuelveCaso" es O(C + N * logN) y el orden de complejidad de la funci�n "resolver" es O(C * logN)
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
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
		cajas.push({ c.id,c.tiempoTrabajo + actual }); //O(logN) //a�ade de nuevo a la cola con el tiempo del cliente sumado a su trabajo pendiente
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
