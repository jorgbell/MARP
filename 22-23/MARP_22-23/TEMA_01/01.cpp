
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martin
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

En el problema hay que averiguar si es un arbol AVL. Será AVL si:
	- es un arbol binario de busqueda EQUILIBRADO (para cada subarbol, la diferencia entre sus dos hijos es <=1)
	- ABB: el valor almacenado en la raiz es estrictamente mayor que los valores izq y menor que los der.
Deberemos hacer un metodo resolver() que determine si es o no AVL, y en él hacer llamadas a metodos auxiliares para ver si cumple las caracteristicas para cada subarbol.
CASOS BASE:
Un arbol vacio siempre es AVL
CASOS RECURSIVOS:
	-comprobar para cada arbol que sea ABB (arbol binario de busqueda)
	-si lo es, comprobar que sea equilibrado
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int altura(bintree<int> tree) {
	//CASO BASE: arbol vacio
	if (tree.empty())
		return 0;
	int alturaIzq = altura(tree.left());
	int alturaDer = altura(tree.right());

	return max(alturaIzq, alturaDer) + 1;
}

bool esABB(bintree<int> tree, int valorMin, int valorMax) {
	//la raiz debe ser MAYOR que el valorMin (los de la izquierda) y MENOR que valorMax (de la derecha)
	//CASO BASE: arbol vacio
	if (tree.empty())
		return true;
	//CASO BASE: inclumple ser ABB?
	if (tree.root() < valorMin || tree.root() > valorMax)
		return false;

	//llamadas recursivas
	return (
		esABB(tree.left(), valorMin, tree.root() - 1) &&
		esABB(tree.right(), tree.root() + 1, valorMax)
		);
}

bool resolverAVL(bintree<int> tree) {
	//caso base: es vacio?
	if (tree.empty())
		return true;
	//caso recursivo: comprobar si es ABB
	if (!esABB(tree, INT_MIN, INT_MAX))
		return false;

	//caso recursivo 2: comprobar alturas
	int left = altura(tree.left());
	int right = altura(tree.right());

	int diferencia = abs(left - right);
	
	return (diferencia <= 1) && resolverAVL(tree.left()) && resolverAVL(tree.right());

}

void resuelveCaso01() {

	// leer los datos de la entrada
	bintree<int> tree = leerArbol(-1);
	// resolver el caso posiblemente llamando a otras funciones
	if (resolverAVL(tree))
		cout << "SI\n";
	else
		cout << "NO\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main01() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos01.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso01();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
