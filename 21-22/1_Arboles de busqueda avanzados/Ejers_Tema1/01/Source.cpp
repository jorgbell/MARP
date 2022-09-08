
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int treeHeight(const bintree<int>& tree) {
	if (tree.empty())
		return 0;
	int left = treeHeight(tree.left());
	int right = treeHeight(tree.right());
	return max(left,right) + 1;
}


bool esABB(const bintree<int>& tree, int minValue, int maxValue) {

	if (tree.empty())
		return true;
	if (tree.root() < minValue || tree.root() > maxValue) { //tiene que ser mayor que el minimo posible, y menor que el maximo posible
		return false;
	}
	//Comrpobamos el hijo izquierdo y el hijo derecho.
	//El hijo izquierdo debe ser COMO MINIMO cualquier numero y COMO MAXIMO -1 del valor de la raiz actual.
	//El hijo derecho debe ser COMO MINIMO +1 de la raiz actual y COMO MAXIMO cualquier numero.
	return esABB(tree.left(), minValue, tree.root() - 1) && esABB(tree.right(), tree.root() + 1, maxValue);

}


bool esAVL(bintree<int> tree) {
	//comprobar si es arbol binario de busqueda
	//El valor de la raiz de cada subarbol tiene que ser mayor que el de la izq y menor que el de la derecha
//comprobar si las alturas es de un avl
	//Para todo subarbol, la diferencia de altura entre sus dos hijos debe ser al menos de 1
	
	if (tree.empty())
		return true;
	if (!esABB(tree, INT_MIN, INT_MAX))
		return false;


	int left = treeHeight(tree.left());
	int right = treeHeight(tree.right());
	return abs(right - left) <= 1 && esAVL(tree.left()) && esAVL(tree.right());

}

void resuelveCaso() {

	// leer los datos de la entrada
	bintree<int> tree = leerArbol(-1);
	// resolver el caso posiblemente llamando a otras funciones
	if (esAVL(tree))
		cout << "SI\n";
	else
		cout << "NO\n";
	// escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("in.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
