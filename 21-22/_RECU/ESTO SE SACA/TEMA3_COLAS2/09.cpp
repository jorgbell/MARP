
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Cuantas horas de vuelo realizaran entre todos los drones cada sabado antes de que se agoten las pilas de las cajas?
cada sabado se cogen las dos pilas mas cargadas y se colocan en los drones, consecutivamente hasta llenar todos los drones que se puedan llenar
el dron volará lo que le permita la menor de sus pilas (eje: si una vuela 2 y otra 5, volará 2 y guardas la otra)
el resultado de cada sabado es las horas sumadas de cada uno de los drones

usamos dos colas de prioridad segun el tipo de pilas. cuando echamos a volar, hacemos dos pop(), y guardaremos las pilas que queden al acabar
asi consecutivamente haciendo sabados hasta que no queden pilas y no haya más sabados

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Pila {
    int64_t carga;
    int64_t tipo; //0 pilas 9V, 1 pilas 1.5V
};

bool operator<(const Pila& a, const Pila& b) {
    return a.carga < b.carga;
}
bool operator>(const Pila& a, const Pila& b) {
    return b < a;
}


void resolver9(priority_queue<Pila> pilas9V, priority_queue<Pila> pilas1_5V, int nDrones) {
    //cada bucle es un sabado
    //guardamos en un array de pilas usadas para meterlas al final, porque si las vamos metiendo según
    //se gastan no es lo que nos piden realmente
    vector<Pila> usadas;
    while (!pilas9V.empty() && !pilas1_5V.empty()) {
        int sabado = 0;
        int i = 0;
        while (i < nDrones) {
            if (pilas9V.empty() || pilas1_5V.empty())
                break;
            int p9 = pilas9V.top().carga; pilas9V.pop();
            int p1_5 = pilas1_5V.top().carga; pilas1_5V.pop();

            if (p9 < p1_5) { //te guardas la de 1.5V y gastas la de 9V
                int resto = p1_5 - p9;
                if(resto>0)
                    usadas.push_back({resto, 1 });

                sabado += p9;
            }
            else {
                int resto = p9-p1_5;
                if (resto > 0)
                    usadas.push_back({ resto, 0 });
                sabado += p1_5;
            }  
            i++;
        }
        cout << sabado << " ";
        for (Pila p : usadas) {
            if (p.tipo == 0)
                pilas9V.push(p);
            else
                pilas1_5V.push(p);
        }
        usadas.clear();
    }
}

bool resuelveCaso9() {

    // leer los datos de la entrada
    int nDrones, n9V, n1_5V;
    cin >> nDrones >> n9V >> n1_5V;
    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<Pila> pilas9V;
    priority_queue<Pila> pilas1_5V;
    for (int i = 0; i < n9V; i++) {
        int n;
        cin >> n;
        pilas9V.push({ n, 0 });
    }
    for (int i = 0; i < n1_5V; i++) {
        int n;
        cin >> n;
        pilas1_5V.push({n,1});
    }
    // resolver el caso posiblemente llamando a otras funciones
    resolver9(pilas9V, pilas1_5V, nDrones);
    // escribir la solución
    cout << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main9() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos9.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso9());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
