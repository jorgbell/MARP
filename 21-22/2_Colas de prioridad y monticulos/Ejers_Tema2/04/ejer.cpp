
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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



struct User {
	int64_t ID;
	int64_t period;
	int64_t time;
};

bool operator<(const User& a, const User& b) {
	return a.time < b.time || (a.time == b.time && a.ID < b.ID);
}
bool operator>(const User& a, const User& b) {
	return b < a;
}

using myQueue = priority_queue< User, vector<User>, greater<User> >;

void resolver(myQueue users, int nMessages) {
	for (int i = 0; i < nMessages; i++) {
		User u = users.top(); users.pop();
		cout << u.ID << '\n';
		users.push({ u.ID, u.period, u.period + u.time });
	}
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int nUsers;
	cin >> nUsers;
	if (nUsers == 0)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones
	myQueue users;
	for (int i = 0; i < nUsers; i++) {
		int64_t ID, period;
		cin >> ID >> period;
		users.push({ ID,period, period});
	}
	int K;
	cin >> K;
	// escribir la soluci�n
	resolver(users, K);
	cout << "---\n";
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
