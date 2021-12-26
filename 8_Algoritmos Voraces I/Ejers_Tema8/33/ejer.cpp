
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


struct pelicula {
	int ini; //hora del dia (expresada en minutos que han pasado desde las 00) en la que empieza
	int fin; //inicio + duracion de la peli
};

class Comparador {
public:
	bool operator()(pelicula a, pelicula b) { return a.fin < b.fin; }
};

int voraz(vector<pelicula> pelisVector) {
	int nPelis = 1; //siempre podra ver como minimo una pelicula
	int margen = pelisVector[0].fin + 10; //inicializamos
	for (int i = 1; i < pelisVector.size(); i++) {
		if (pelisVector[i].ini >= margen) { //margen de 10 minutos
			//la peli proxima empieza como muy pronto 10 minutos despu�s de que acabe la actual
			//podemos verla
			nPelis++;
			margen = pelisVector[i].fin + 10;
		}
	}
	// escribir la soluci�n
	return nPelis;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0)
		return false;
	int h, min, duracion; char c;
	vector<pelicula> pelisVector(N);
	for (int i = 0; i < N; i++) {
		cin >> h >> c >> min >> duracion;
		pelisVector[i].ini = h * 60 + min;
		pelisVector[i].fin = pelisVector[i].ini + duracion;
	}
	// resolver el caso posiblemente llamando a otras funciones
	sort(pelisVector.begin(), pelisVector.end(), Comparador());
	
	cout << voraz(pelisVector) << '\n';
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
