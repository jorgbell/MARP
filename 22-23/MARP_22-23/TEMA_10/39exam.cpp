
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

const int INF = 100000000;

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Bombilla {
    int precio;
    int potencia;
};

bool operator <(const Bombilla& a, const Bombilla& b) {
    return a.potencia < b.potencia;
}
bool operator>(const Bombilla& a, const Bombilla& b) {
    return b < a;
}


bool resuelveCaso39Mexam() {

    // leer los datos de la entrada
    int N, Pmin, Pmax;
    cin >> N >> Pmax >> Pmin;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<Bombilla> bombillas(N);
    for (int i = 0; i < N; i++) {
        cin >> bombillas[i].potencia;
    }
    for (int i = 0; i < N; i++) {
        cin >> bombillas[i].precio;
    }
    // resolver el caso posiblemente llamando a otras funciones
    //las ordenamos segun la potencia para realizar la matriz
    //sort(bombillas.begin(), bombillas.end(), std::greater<Bombilla>());
    
    //usamos un vector en lugar de una matriz debido a que nos da igual si las bombillas usadas son de una potencia o de otra, solo nos interesa acumular su precio
    vector<int> minCoste(Pmax + 1, INF);
    minCoste[0] = 0;
    for (int i = 0; i < N; i++) {
        //por cada tipo de bombilla
        Bombilla bomb = bombillas[i];
        for (int j = bomb.potencia; j < Pmax + 1; j++) {
            minCoste[j] = min(minCoste[j - bomb.potencia] + bomb.precio,
                minCoste[j]);
        }
    }
    //una vez rellenadas todas las posibles potencias con su coste optimo, debemos comprobar cual de las que se encuentran en el rango pmin-pmax es la mas optima
    //porque en este problema el resultado no es minCoste[Pmax] sino alguna en el rango de minCoste[Pmin-Pmax]
    int costeOptimo = minCoste[Pmin]; //comenzamos contando por el Pmin
    int potenciaOptima = Pmin;
    //comprobamos desde Pmin hasta Pmax
    for (int i = Pmin+1; i < Pmax+1; i++) {
        if (costeOptimo > minCoste[i]) {
            costeOptimo = minCoste[i];
            potenciaOptima = i;
        }
    }
    //si el costeOptimo = infinito, significa que no ha habido ningun coste en el rango necesario que sea posible, ya que en caso de ser asi, habria escogido uno menor
    if (costeOptimo == INF) {
        cout << "IMPOSIBLE\n";
        return true;
    }
    cout << costeOptimo << ' ' << potenciaOptima << '\n';
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos39.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso39Mexam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
