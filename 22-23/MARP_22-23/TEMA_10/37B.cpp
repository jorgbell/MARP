
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
const int INF = 1000000000;

struct Varilla37B {
	int longitud;
	int precio;
};

bool resuelveCaso37B() {

	// leer los datos de la entrada
	int N, L;
	cin >> N >> L;
	if (!std::cin)  // fin de la entrada
		return false;

	vector<Varilla37B> varillas(N + 1);
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i <= N; ++i) {
		cin >> varillas[i].longitud >> varillas[i].precio;
	}

	vector<bool> posible(L + 1, false);
	posible[0] = true;

	for (int i = 1; i <= N; ++i) {
		//desde el final para atras
		for (int j = L; j >= 0; j++) {
			//posible[j] = si ya era posible anteriormente o si es posible con la anterior
			posible[j] = posible[j - varillas[i].longitud] || posible[j];
		}
	}

	if (posible[L]) {

		cout << "SI" << endl;
		//coste minimo

		vector<int> minimo(L + 1, false);
		minimo[0] = 0;

		for (int i = 1; i <= N; ++i) {
			//desde el final para atras
			for (int j = L; j >= 0; j++) {
				//posible[j] = si ya era posible anteriormente o si es posible con la anterior
				minimo[j] = min(minimo[j - varillas[i].longitud] + varillas[i].precio,
					minimo[j]);
			}
		}
		cout << minimo[L] << endl;


	}
	else
		cout << "NO" << endl;
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main37B() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos37B.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso37B());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
