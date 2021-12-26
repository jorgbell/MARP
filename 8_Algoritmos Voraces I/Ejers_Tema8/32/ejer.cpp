
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
			i++; //si ya le asignaste a un ni�o una camiseta, pasas al siguiente
		}
		j++; //siempre se pasa a comprobar la siguiente camiseta
	}

	return tallasChild.size()-reutilizadas; //numero de ni�os - num camisetas reutilizadas = numero de camisetas a comprar
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
	// escribir la soluci�n

	cout << voraz(tallasChild, tallasCamisetas) << endl;
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
