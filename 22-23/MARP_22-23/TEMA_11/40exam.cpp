
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct cofre {
	int valor;
	int distancia;
	int tiempoInmersion;
};

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso40exam() {

	// leer los datos de la entrada
	int T, N;
	cin >> T >> N;
	if (!std::cin)  // fin de la entrada
		return false;

	vector<cofre> cofres(N);
	for (int i = 0; i < N; i++) {
		cin >> cofres[i].distancia >> cofres[i].valor;
		cofres[i].tiempoInmersion = 3* cofres[i].distancia;
	}
	// resolver el caso posiblemente llamando a otras funciones
	vector<vector<int>> maxOro(N + 1, vector<int>(T + 1, -1));
	//casos bases: inicializados con el vector ([i][0] = 0; [0][j] = 0)
	for (int i = 0; i < N + 1; i++) {
		maxOro[i][0] = 0;
	}
	for (int j = 1; j< T + 1; j++) {
		maxOro[0][j] = 0;
	}
	for (int i = 1; i < N + 1; i++) {
		cofre c = cofres[i - 1];
		for (int j = 1; j < T + 1; j++) {
			if (c.tiempoInmersion <= j)
				maxOro[i][j] = max(maxOro[i - 1][j],
					maxOro[i - 1][j - c.tiempoInmersion] + c.valor);
			else//descartamos
				maxOro[i][j] = maxOro[i - 1][j];
		}
	}

	//reconstruimos la solucion para ver cuantos cofres se pueden conseguir
	int i = N; int j = T;
	stack<cofre> s;
	while (i > 0 && j > 0) {
		cofre c = cofres[i - 1];
		if (c.tiempoInmersion <= j && maxOro[i][j] == maxOro[i - 1][j-c.tiempoInmersion] + c.valor) {
			j -= c.tiempoInmersion;
			s.push(c);
		}
		i--;
	}
	cout << maxOro[N][T] << '\n' << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top().distancia << ' ' << s.top().valor << '\n';
		s.pop();
	}
	cout << "---\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos40.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso40exam());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
