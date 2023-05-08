
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;


/*@ <answer>
* Para conseguir una cola de medianas, sacamos una cola de mayor a menor y otra de menor a mayor.
* Siempre tendr�n una diferencia de un elemento.
* La mediana ser� el elemento top de la cola que tenga m�s elementos
* ejemplo:
* cola vacia-> insertamos 1
*	- se inserta en la cola de min
*	- balancea: todo bien
* insertamos 2
*	- se inserta en la cola de min -> 1,2
*	- balancea: hay una diferencia de 2, por lo que mete el de la cola que tiene mas numeros en la otra (el 1)
* insertamos 3:
*	- se inserta en la cola de max en caso de que sea mayor que el tope de esta. Si no, se inserta en la de mins.
*		- se inserta por lo tanto en la de max, 3>2
*			- min: 2,3
*			- max: 1
*
* sacamos la mediana: se saca el de la cola que tenga m�s elementos, si son iguales, sacas el de min
*
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

#include <queue>

class ColaMedianas
{
	// top es mayor
	using MinQueue = std::priority_queue<int, std::vector<int>, std::less<int>>;
	// top es menor
	using MaxQueue = std::priority_queue<int, std::vector<int>, std::greater<int>>;

	MinQueue min;
	MaxQueue max;

public:
	void insertar(int x) {
		if (!max.empty() && x > max.top())
			max.push(x);
		else
			min.push(x);

		balancea();
	}

	bool vacia() const {
		return min.empty() && max.empty();
	}

	int mediana() const {
		if (min.size() >= max.size()) // Utilizamos el valor de la cola con m�s elementos
			return min.top();
		else
			return max.top();
	}

	void quitarMediana() {
		if (min.size() >= max.size()) // Utilizamos el valor de la cola con m�s elementos
			min.pop();
		else
			max.pop();
	}

private:
	void balancea() {
		auto diff = (int)max.size() - (int)min.size();

		if (diff > 1) { // max tiene al menos 2 elementos mas que min
			if (max.empty())
				return;

			min.push(max.top());
			max.pop();
		}
		else if (diff < -1) { // min tiene al menos 2 elementos mas que max
			if (min.empty())
				return;

			max.push(min.top());
			min.pop();
		}
	}
};



bool resuelveCaso08exam() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	ColaMedianas cola;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (cola.vacia())
				cout << "ECSA ";
			else {
				cout << cola.mediana() << " ";
				cola.quitarMediana();
			}
		}
		else {
			cola.insertar(x);
		}
	}
	// resolver el caso posiblemente llamando a otras funciones
	cout << '\n';
	// escribir la soluci�n

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main08exam() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos08.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso08exam());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
