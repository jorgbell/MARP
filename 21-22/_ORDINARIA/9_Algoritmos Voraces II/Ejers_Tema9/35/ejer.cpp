
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

struct Hotel {
    int izq;
    int der;
};

//Para ordenar seg�n la posici�n de izquierda a derecha en el eje de coordenadas empezando desde 0
//el que acabe antes (su punto derecho sea menor) ir� primero
bool operator <(Hotel const& a, Hotel const& b) { return a.der < b.der; }

int voraz(vector<Hotel> hoteles, int N) {
    int tuneles = 1;//como minimo tendremos un unico tunel
    int i = 1; //contador para el vector de hoteles
    int finAct = hoteles[0].der; //donde acaba el hotel actual
    while (i < N) {
        Hotel h = hoteles[i]; //siguiente hotel a comprobar
        if (h.izq >= finAct) {
            tuneles++;
            finAct = hoteles[i].der;        
        }
        i++;
    }

    return tuneles;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)  // fin de la entrada
        return false;

    vector<Hotel> hoteles(N);
    for (int i = 0; i < N; i++) {
        cin >> hoteles[i].izq >> hoteles[i].der;
    }
    // resolver el caso posiblemente llamando a otras funciones
    sort(hoteles.begin(), hoteles.end(), std::less<Hotel>());
    // escribir la soluci�n
    cout << voraz(hoteles, N) << '\n';
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
