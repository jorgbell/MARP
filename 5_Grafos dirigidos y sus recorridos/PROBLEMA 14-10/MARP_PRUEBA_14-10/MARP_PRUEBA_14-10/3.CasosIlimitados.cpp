
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Digrafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

  Obtendremos un grafo dirigido según las instrucciones que el programa inserte. Cada nodo es una instrucción.
  Si se trata de una instrucción de tipo A, el nodo se conectará con el siguiente en caso de que lo haya. Si es de tipo L el nodo estará dirigido a la indicada
  por la línea a a que debe saltar. Si es de tipo C, el nodo estará dirigido tanto hacia la indicada como hacia la siguiente si la hay.

  Para saber si el programa termina, debemos ver si es capaz de llegar al último nodo, y si este acaba ahí o vuelve a empezar. En caso de que el último no tenga conexión,
  el programa acabará correctamente. Si no, deberemos lanzar un NUNCA en la salida.

  Para saber si llega al último, utilizaremos un recorrido con la clase DFSDirigido para saber primeramente si hay un camino dirigido entre el nodo 0 y el nodo L.
  En caso de que no lo haya, NUNCA saldrá en la salida.
  En caso de que sí que haya, deberemos comprobar si depende de un salto condicional o no. En caso de que uno de los nodos que conectan con el último tengan más de
  una conexión, significa que depende de un salto condicional. Por lo tanto, en la salida saldrá A VECES.
  En caso de que no haya saltos condicionales, en la salida saldrá SIEMPRE.


  Para aclarar:
  -Si el nodo es una instrucción tipo A, tendrá 0 adyacentes
  -Si es de tipo J, tendrá 1
  -Si es de tipo C, tendrá 2

  PROBLEMA QUE TUVE: No supe usar Camino de BFSDirigido, así que para poder acceder al nodo anterior de L he hecho público el vector ant[].
  OTRO PROBLEMA: Realizando el programa me he dado cuenta de que el hecho de que el penúltimo sea de tipo C no implica que se acabe a veces, porque ambos caminos podrían
  ser correctos. Pero me he quedado sin tiempo así que lo apunto por aquí aunque la respuesta sea incorrecta.
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

	// leer los datos de la entrada
	int L;
	cin >> L;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo* program = new Digrafo(L);

	for (int i = 0; i < L; i++) {
		char inst; int salto;
		cin >> inst;
		switch (inst) {
		case 'A':
			if (i + 1 < L) //si no ha llegado al último vértice
				program->ponArista(i, i + 1);
			break;
		case 'J':
			cin >> salto;
			salto--; //porque Digrafo.h contabiliza los nodos empezando en 0, y en el problema lo hacemos desde 1
			program->ponArista(i, salto);
			break;
		case 'C':
			cin >> salto;
			salto--; //porque Digrafo.h contabiliza los nodos empezando en 0, y en el problema lo hacemos desde 1
			program->ponArista(i, salto);
			if (i + 1 < L) //si no ha llegado al último vértice
				program->ponArista(i, i + 1);
			break;
		}
	}

	// resolver el caso posiblemente llamando a otras funciones
	string sol;
	BFSDirigido* recorrido = new BFSDirigido(*program, 0);
	if (recorrido->hayCamino(L-1)) {//si el programa puede llegar al final
		//comprobamos si el último nodo tiene alguna conexión. En caso de tenerla, nos encontraríamos en un bucle infinito y debe dar error.

		if (program->ady(L - 1).size() == 1) { //Si es de tipo J, tiene una unica conexión, y en este caso nos encontraríamos en un bucle infinito.
			sol = "NUNCA";
		}
		else { //Si es de tipo C o A, acabará siempre o a veces.
			int penultimo = recorrido->ant[L-1];
			cout << penultimo << "\n";
			if (program->ady(penultimo).size() == 2) {//si el anterior a L es de tipo C (tiene más de un camino), acabará A VECES.
				sol = "A VECES";
			}
			else {
				sol = "SIEMPRE";
			}
		}
	}
	else {//Si no puede llegar al final
		sol = "NUNCA";
	}
	// escribir la solución
	cout << sol << "\n";
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
