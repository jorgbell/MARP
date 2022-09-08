
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool resuelveCaso() {

	// leer los datos de la entrada
	//int N, int M;
	//cin >> N >> M;
	//Parece que Grafo lee el problema con un flujo como el del .txt??
	Grafo *g = new Grafo(cin);		//los vértices del grafo son los usuarios de la red
	if (!std::cin)  // fin de la entrada
		return false;
	//for (int i = 0; i < M; i++) {
	//	int miembros;
	//	cin >> miembros;
	//	//Aqui hay que leer los nodos. Hay que unir en el grafo los id de los miembros de este grupo.
	//	//Después, hay que mirar cada miembro (cada vértice) y comprobar cuantas aristas tiene. El número de aristas es el número de usuarios al que está conectado.
	//	//Sumando el número de aristas del vértice i-ésimo, tenemos el número de usuarios que se enterarán de la noticia.
	//	//Un vértice (miembro) puede formar parte de varios grupos, por lo que varios grupos de usuarios se enterarán de la noticia si es el caso.

	//}

	// resolver el caso posiblemente llamando a otras funciones

	// escribir la solución

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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
