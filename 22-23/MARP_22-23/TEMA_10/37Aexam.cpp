
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000; // Para coste y mínimo número de varillas a usar.


/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct cordel {
	int coste;
	int longitud;
};

long long int formas(vector<cordel> v, int N, int L) {
	//formas
	//rellenamos la tabla
	vector<vector<long long int>> formas(N + 1, vector<long long int>(L + 1, 0)); //iniciamos todos los valores a 0
	//rellenamos los casos base
	for (int i = 0; i < N + 1; i++) {
		formas[i][0] = 1; //primera columna a 1: solo hay una forma de hacer una cuerda de tamaño 0
	}

	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		posible[i][j] += posible[i-1][j] + posible[i-1][j-longitud cuerda]
	si longitud cuerda < longitud pedida, no podemos usarla,
		posible[i][j] = posible[i-1][j]
	*/

	for (int i = 1; i < N + 1; ++i) {
		//recorremos las filas
		for (int j = 1; j < L + 1; ++j) {
			//recorremos las columnas
			formas[i][j] =
				v[i - 1].longitud <= j ? //el cordel que vamos a usar es mayor de la longitud necesaria,
				(formas[i - 1][j] + formas[i - 1][j - v[i - 1].longitud]) :
				formas[i - 1][j]; //el de encima
		}
	}

	return formas[N][L];
}

int minCord(vector<cordel> v, int N, int L) {
	//MINIMO NUMERO DE CORDELES
	//rellenamos la tabla
	vector<vector<int>> minCord(N + 1, vector<int>(L + 1, INF)); //iniciamos todos los valores a +inf
	//rellenamos los casos base
	for (int i = 0; i < N + 1; i++) {
		minCord[i][0] = 0; //primera columna a 0: el minimo numero de cordeles para un tamaño 0 es 0
	}

	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		posible[i][j] += min(posible[i-1][j], posible[i-1][j-longitud cuerda])
	si longitud cuerda < longitud pedida, no podemos usarla,
		posible[i][j] = posible[i-1][j]
	*/

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < L + 1; j++) {
			//recorremos las columnas
			minCord[i][j] =
				v[i - 1].longitud <= j ?
				min(minCord[i - 1][j],
					minCord[i - 1][j - v[i - 1].longitud] + 1) :
				minCord[i - 1][j];

		}
	}

	return minCord[N][L];
}

int minCoste(vector<cordel> v, int N, int L) {

	//MINIMO COSTE
	//rellenamos la tabla
	vector<vector<int>> minCoste(N + 1, vector<int>(L + 1, INF)); //iniciamos todos los valores a +inf
	//rellenamos los casos base
	for (int i = 0; i < N + 1; i++) {
		minCoste[i][0] = 0; //primera columna a 0: el minimo coste lo marcamos como 0
	}

	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		minCoste[i][j] +=  min(c.coste + minCoste[i-1][j], minCoste[i-1][j-longitud cuerda])
	si longitud cuerda < longitud pedida, no podemos usarla,
		minCoste[i][j] = minCoste[i-1][j]
	*/

	for (int i = 1; i < N + 1; i++) {
		//recorremos las filas
		for (int j = 1; j < L + 1; j++) {
			//recorremos las columnas
			minCoste[i][j] =
				v[i - 1].longitud <= j ?
				min(minCoste[i - 1][j],
					v[i - 1].coste + minCoste[i - 1][j - v[i - 1].longitud]) :
				minCoste[i - 1][j];
		}
	}

	return minCoste[N][L];
}


bool posible(vector<cordel> v, int N, int L) {
	//rellenamos la tabla
	vector<vector<bool>> posible(N + 1, vector<bool>(L + 1, false)); //iniciamos todos los valores a false
	//preguntamos si es posible (se puede hacer una cometa con estos cordeles?)
		//rellenamos los casos base
	for (int i = 0; i < N + 1; i++) {
		posible[i][0] = true; //primera columna a true: siempre se podra hacer una cuerda de tamaño 0
	}
	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		posible[i][j] = posible[i-1][j] || posible[i-1][j-longitud cuerda]
	si longitud cuerda < longitud pedida, no podemos usarla,
		posible[i][j] = posible[i-1][j]
	*/

	for (int i = 1; i < N + 1; ++i) {
		cordel cord = v[i - 1];
		for (int j = 1; j < L + 1; ++j) {
			if (cord.longitud > j)
				posible[i][j] = posible[i - 1][j];
			else
				posible[i][j] = posible[i - 1][j] || posible[i - 1][j - cord.longitud];
		}
	}

	return posible[N][L];
}

bool resuelveCaso37a() {

	// leer los datos de la entrada
	int N, L;
	cin >> N >> L;
	if (!std::cin)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	vector<cordel> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i].longitud >> v[i].coste;
	}

	if (!posible(v,N,L)) {
		cout << "NO\n";
		return true;
	}

	cout << "SI ";
	cout << formas(v, N, L) << ' ' << minCord(v, N, L) << ' ' << minCoste(v,N,L) << '\n';
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main37Aexam() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos37a.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso37a());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
