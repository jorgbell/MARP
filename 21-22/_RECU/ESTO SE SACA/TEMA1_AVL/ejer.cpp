
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
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

 Un AVL es un arbol que tiene que comprobar que:
    -este equilibrado (la diferencia entre las alturas de sus dos hijos es como mucho 1)
    -el valor almacenado en la raíz tiene que ser estrictamente mayor que los de la izq y menor que los de la der
Hacer un método para comprobar cada una de esas cosas
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int altura(bintree<int> tree) {
    //comprueba la altura del arbol
    if (tree.empty())
        return 0;
    int left = altura(tree.left());
    int right = altura(tree.right());

    return max(left, right) + 1;
    
}


bool esABB(bintree<int> tree, int minValue, int maxValue) {
    //método recursivo que comprueba si cada subarbol es abb comparando los valores minimos y maximos que deberian llegar los hijos
    // ejemplo: el hijo izquierdo SIEMPRE tiene que ser menor que la raiz, el hijo derecho SIEMPRE mayor que la raiz
    // en cada llamada se actualiza en cada lado el valor minimo al que deben llegar y es lo primero que se comprueban
    //el valor del hijo izquierdo debe ser mayor que el 


    //CASO BASE
    if (tree.empty())
        return true;
    if (tree.root() < minValue || tree.root() > maxValue)
        return false; //en caso de ocurrir esto será un arbol erroneo
    //llamada recursiva
    return (esABB(tree.left(), minValue, tree.root() - 1) &&
        esABB(tree.right(), tree.root() + 1, maxValue));


    
}


bool resolverArbol(bintree<int> tree) {
    //este metodo resuelve el problema: hace ambas comprobaciones del AVl

    //CASO BASE:
    if (tree.empty())
        return true; //uno vacío siempre será AVL
    //primero comprueba si es ABB comparando los valores de la raiz
    if (!esABB(tree, INT_MIN, INT_MAX))
        return false;

    //ahora debe comprobar si este arbol tiene altura con diferencia 1, en caso de tenerlo, comprueba si el resto de subarboles (llamada recursiva) son AVL tambien
        //comprueba la altura de todos los subarboles
    int left = altura(tree.left());
    int right = altura(tree.right());

    int diff = abs(right-left);

    return (diff <= 1) && resolverArbol(tree.left()) && resolverArbol(tree.right());
}


void resuelveCaso() {

    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1); //caracter con el que indicamos qué es un vacío
    // resolver el caso posiblemente llamando a otras funciones
    if (resolverArbol(tree))
        // escribir la solución
        cout << "SI\n";
    else
        cout << "NO\n";

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
