
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
const int INF = 1000000000;

struct Varilla {
    int longitud;
    int precio;
};

bool resuelveCaso37A() {

    // leer los datos de la entrada
    int N, L;
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<Varilla> varillas(N + 1);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i <= N; ++i) {
        cin >> varillas[i].longitud >> varillas[i].precio;
    }
    vector<vector<bool>> posible(N + 1, vector<bool>(L + 1));
    // escribir la solución
    for (int i = 0; i <= N; i++)
        posible[i][0] = true;
    for (int j = 1; j <= L; j++)
        posible[0][j] = false;

    int i = 1;
    for (int j = 1; j <= L; j++) {
        posible[i][j] = varillas[i].longitud <= j ?
            posible[i - 1][j - varillas[i].longitud] || //coger la varilla
            posible[i - j][j] : //no coger la varilla
            posible[i - j][j]; //no coger la varilla
    }

    if (posible[N][L]) {
        cout << "YES" << endl;
        //coste minimo
        vector<vector<int>> minimo(N + 1, vector<int>(L + 1));

        for (int i = 0; i <= N; i++)
            minimo[i][0] = 0;
        for (int j = 1; j <= L; j++)
            minimo[0][j] = INF;


        for (int i = 0; i <= N; i++) {
            posible[i][0] = 0;
            for (int j = 1; j <= L; j++) {
                minimo[i][j] = varillas[i].longitud <= j ?
                    min(minimo[i - 1][j - varillas[i].longitud] + varillas[i].precio,
                    minimo[i - j][j])
                    : minimo[i - 1][j];
                    
            }
        }

        cout << minimo[N][L] << endl;


    }
    else
        cout << "nope" << endl;


    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main37A() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso37A());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
