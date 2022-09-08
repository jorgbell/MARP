
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Mart�n
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;


/*@ <answer>

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

struct Pila {
	int energia;
	int tipo; //0 = 9V, 1 = 1.5V
};

bool operator<(const Pila& a, const Pila& b) {
	return a.energia < b.energia;
}
bool operator>(const Pila& a, const Pila& b) {
	return b < a;
}

void resolver(priority_queue<Pila> pilas0, priority_queue<Pila> pilas1, int nDrones) {
	//si quedan pilas, cogemos las dos pilas mas cargadas
	//sumamos las horas de vuelo a las del total
	//repetimos hasta hayamos usado todos los drones
	//a�adimos a las usadas si les queda energ�a
	//guardamos las pilas usadas de nuevo
	//fin del caso

	list<Pila> usadas;
	while (!pilas0.empty() && !pilas1.empty()) {
		int sabado = 0;
		int i = 0;
		while (i < nDrones) {
			if (pilas0.empty() || pilas1.empty())
				break;

			Pila p0 = pilas0.top();
			pilas0.pop();
			Pila p1 = pilas1.top();
			pilas1.pop();

			//sumas la energia y la a�ades a las usadas
			if (p0 > p1) {
				sabado += p1.energia;
				int restante = p0.energia - p1.energia;
				if (restante != 0)
					usadas.push_back({ restante , p0.tipo });
			}
			else {
				sabado += p0.energia;
				int restante = p1.energia - p0.energia;
				if (restante != 0)
					usadas.push_back({ restante , p1.tipo });
			}
			i++;
		}
		cout << sabado << " ";
		for (Pila p : usadas) {
			if (p.tipo == 0)
				pilas0.push(p);
			else
				pilas1.push(p);
		}
		usadas.clear();
	}

}

bool resuelveCaso() {

	// leer los datos de la entrada
	int nDrones, nPilas1, nPilas2;
	cin >> nDrones >> nPilas1 >> nPilas2;
	if (!std::cin)  // fin de la entrada
		return false;
	priority_queue<Pila> pilas0;
	priority_queue<Pila> pilas1;
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < nPilas1; i++) {
		int n;
		cin >> n;
		pilas0.push({ n,0 });
	}
	for (int i = 0; i < nPilas2; i++) {
		int n;
		cin >> n;
		pilas1.push({ n,1 });
	}
	//repetimos hasta que nos quedemos sin pares de pilas que usar
	resolver(pilas0, pilas1, nDrones);
	cout << '\n';
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
