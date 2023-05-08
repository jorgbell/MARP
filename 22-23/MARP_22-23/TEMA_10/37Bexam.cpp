
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

long long int formasV(vector<cordel> v, int N, int L) {
	//formas
	//rellenamos la tabla
	vector<long long int> formas(L + 1, 0); //iniciamos todos los valores a 0
	//rellenamos los casos base
	formas[0] = 1; //primera columna a 1: solo hay una forma de hacer una cuerda de tamaño 0
	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		posible[i][j] += posible[i-1][j] + posible[i-1][j-longitud cuerda]
	si longitud cuerda < longitud pedida, no podemos usarla,
		posible[i][j] = posible[i-1][j]
	*/

	for (int i = N-1; i >=0; --i) {
		//recorremos las filas
		cordel cord = v[i];
		for (int j = L; cord.longitud <= j; --j) {
			//recorremos las columnas
			formas[j] = (formas[j] + formas[j - cord.longitud]);
		}
	}

	return formas[L];
}

int minCordV(vector<cordel> v, int N, int L) {
	//MINIMO NUMERO DE CORDELES
	//rellenamos la tabla
	vector<int> minCord(L+1, INF); //iniciamos todos los valores a +inf
	//rellenamos los casos base
	minCord[0] = 0; //primera columna a 0: el minimo numero de cordeles para un tamaño 0 es 0


	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		posible[i][j] += min(posible[i-1][j], posible[i-1][j-longitud cuerda])
	si longitud cuerda < longitud pedida, no podemos usarla,
		posible[i][j] = posible[i-1][j]
	*/

	for (int i = N - 1; i >= 0; --i) {
		cordel cord = v[i];
		for (int j = L; cord.longitud<=j ; --j) {
			//recorremos las columnas
			minCord[j] = min(minCord[j],
				minCord[j - cord.longitud] + 1);
		}
	}

	return minCord[L];
}

int minCosteV(vector<cordel> v, int N, int L) {

	//MINIMO COSTE
	//rellenamos la tabla
	vector<int> minCoste(L + 1, INF); //iniciamos todos los valores a +inf
	//rellenamos los casos base
	minCoste[0] = 0; //primera columna a 0: el minimo coste lo marcamos como 0
	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		minCoste[i][j] +=  min(c.coste + minCoste[i-1][j], minCoste[i-1][j-longitud cuerda])
	si longitud cuerda < longitud pedida, no podemos usarla,
		minCoste[i][j] = minCoste[i-1][j]
	*/

	for (int i = N-1; i >= 0; --i) {
		cordel cord = v[i];
		for (int j = L; j >= cord.longitud; --j) {
			//recorremos las columnas
			minCoste[j] = min(minCoste[j],
				cord.coste + minCoste[j - cord.longitud]);
		}
	}

	return minCoste[L];
}


bool posibleV(vector<cordel> v, int N, int L) {
	//rellenamos la tabla
	vector<bool> posible(L + 1, false); //iniciamos todos los valores a false
	//preguntamos si es posible (se puede hacer una cometa con estos cordeles?)
		//rellenamos los casos base
	posible[0] = true; //primera columna a true: siempre se podra hacer una cuerda de tamaño 0
	//rellenamos el resto de valores
	/*
	si longitud cuerda <= longitud pedida,
		posible[i][j] = posible[i-1][j] || posible[i-1][j-longitud cuerda]
	si longitud cuerda < longitud pedida, no podemos usarla,
		posible[i][j] = posible[i-1][j]
	*/
	for (int i = N-1; i >=0; --i) {
		cordel cord = v[i];
		int j = L;
		for (int j = L; j >= cord.longitud; --j) {
			posible[j] = posible[j] || posible[j - cord.longitud];
		}
	}

	return posible[L];
}

bool resuelveCaso37Bexam() {

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

	if (!posibleV(v, N, L)) {
		cout << "NO\n";
		return true;
	}

	cout << "SI ";
	cout << formasV(v, N, L) << ' ' << minCordV(v, N, L) << ' ' << minCosteV(v, N, L) << '\n';
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main37BExam() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos37B.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso37Bexam());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
