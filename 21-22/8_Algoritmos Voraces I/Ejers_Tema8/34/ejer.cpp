
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

int voraz(vector<int>resRivales, vector<int>resBroncos, int nPartidos) {
	int puntos = 0;
	int i = 0;
	bool end = false; 
	while (!end) {
		int diff = resBroncos[i] - resRivales[i];
		if (i >= nPartidos || diff<=0) { //condicion para salir del bucle: ya no hay m�s o la diferencia es negativa
			end = true;
			break;
		}
		puntos += diff;
		i++;
	}
	return puntos;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N <= 0)  // fin de la entrada
		return false;
	vector<int>resRivales(N);
	vector<int>resBroncos(N);
	for (int i = 0; i < N; i++)
		cin >> resRivales[i];
	for (int i = 0; i < N; i++)
		cin >> resBroncos[i];
	// resolver el caso posiblemente llamando a otras funciones
	sort(resRivales.begin(), resRivales.end());
	sort(resBroncos.begin(), resBroncos.end(), greater<int>());
	// escribir la soluci�n
	cout << voraz(resRivales, resBroncos, N) << '\n';
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
