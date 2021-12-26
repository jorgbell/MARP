
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int voraz(vector<int> tallasChild, vector<int>tallasCamisetas) {

	int reutilizadas = 0;
	int i = 0; //contador ninos
	int j = 0; //contador camisetas
	int diff; //diferencia entre las talllas
	while (i < tallasChild.size() && j<tallasCamisetas.size()) {
		diff = tallasCamisetas[j] - tallasChild[i];
		if (diff >=0 && diff <=1) { //si la camiseta es mayor o igual Y no se pasa de una talla como maximo
			reutilizadas++;
			i++; //si ya le asignaste a un niño una camiseta, pasas al siguiente
		}
		j++; //siempre se pasa a comprobar la siguiente camiseta
	}

	return tallasChild.size()-reutilizadas; //numero de niños - num camisetas reutilizadas = numero de camisetas a comprar
}

bool resuelveCaso() {

	int N, M; //num ninos y num camisetas
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	cin >> M;
	vector<int> tallasChild;
	vector<int> tallasCamisetas;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		tallasChild.push_back(x);
	}
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		tallasCamisetas.push_back(x);
	}
	sort(tallasChild.begin(), tallasChild.end());
	sort(tallasCamisetas.begin(), tallasCamisetas.end());
	// escribir la solución

	cout << voraz(tallasChild, tallasCamisetas) << endl;
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
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
