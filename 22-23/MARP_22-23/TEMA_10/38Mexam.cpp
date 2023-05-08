
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
const int INF = 1000000000;
/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso38Mexam() {

    // leer los datos de la entrada
    int P, S;
    cin >> P >> S;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> secciones(S);
    for (int i = 0; i < S; i++) 
        cin >> secciones[i];
    // resolver el caso posiblemente llamando a otras funciones
    /*
        debemos obtener el resultado pedido exacto con el menor numero de tiros posible
        casos base:
            0 puntos a conseguir: 0 posibilidades
            0 secciones disponibles: INF disparos
        resto de casos:
            se pueden repetir secciones, asi que hay que comprobar en la misma fila y en la anterior
            minimo[i][j] = min(minimo[i-1][j] , minimo[i][j-valor_seccion] si j <= valor_seccion
                            minimo[i-1][j] si j> valor_seccion
    */
    // escribir la solución
    vector<vector<int>> minimo(S + 1, vector<int>(P + 1, INF));
    //casos base
    for (int i = 0; i < S + 1; i++) {
        minimo[i][0] = 0;
    }
    //los casos base de la j estan inicializados al crear la matriz

    for (int i = 1; i < S + 1; i++) {
        int seccion = secciones[i - 1];
        for (int j = 1; j < P + 1; j++) {
            if (seccion <= j)
                minimo[i][j] = min(minimo[i][j - seccion]+1, minimo[i - 1][j]);
            else
                minimo[i][j] = minimo[i - 1][j];

           /* minimo[i][j] =
                seccion <= j ?
                min(minimo[i][j - seccion], minimo[i - 1][j]) :
                minimo[i - 1][j];*/
        }
    }
    if (minimo[S][P] == INF) {
        cout << "Imposible\n";
        return true;
    }
    cout << minimo[S][P] << ':';
    //reconstruimos la solucion desde atras para alante para saber qué secciones ha utilizado
    int j = P, i = S;
    while (j > 0) {
        int seccion = secciones[i - 1];
        if (seccion <= j && minimo[i][j] == minimo[i][j - seccion] + 1) {//te quedas con el de la izq [i][j-seccion]
            //solo compruebas en caso de que la seccion no sobrepase el valor que preguntas (j)
            //para que asi al hacer j-seccion no de un numero fuera de la matriz
            j -= seccion;
            cout << ' ' << seccion;
        }
        else {//te quedas con el de arriba [i-1][j]
            i--;
        }
    }
    cout << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main38MExam() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos38.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso38Mexam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
