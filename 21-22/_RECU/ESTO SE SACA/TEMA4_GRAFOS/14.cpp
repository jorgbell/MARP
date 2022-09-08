
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martín
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Un usuario envía la info a todos sus adyacentes y este se la envia a su vez a todos sus adyacentes
Si hacemos un recorrido entero desde el origen usando como origen todos los vertices,
podemos llevar un contador de cuantos amigos hay en ese grupo y hacer un cout
O tambien hacer caminos y despues consultar el tamaño de ls caminos

CORRECCION

No hay que recorrerlos todos, hay que pensar en componentes conexas
Una componente conexa es un grupo de vertices unidos
Si no se ha visitado alguno es una nueva componente conexa
Hay que visitar todas las componentes conexas
@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


class RedSocial {
public:
    RedSocial(Grafo const& g) : visit(g.V(), false), tamsComponentesConexas(g.V()), tablaComponentesConexas(g.V()) {
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {//solo visitamos las que no se hayan visto ya
                int acumulador = 1; //sabe la noticia minimo el mismo
                dfs(g, i, &acumulador, i);
                tamsComponentesConexas[i] = acumulador;
            }
        }  
    }

    int expandeNoticia(int v) { return tamsComponentesConexas[tablaComponentesConexas[v]]; }

private:
    vector<bool>visit;
    vector<int> tamsComponentesConexas; //vector que guarda un elemento por cad auna de las componentes conexas y en ese elemento guarda su tamaño
    vector<int> tablaComponentesConexas; //relaciona cada uno de los vertices con su indice en el vector de tamaños de componentes conexas
    
    void dfs(Grafo const& g, int v, int* acumulador, int compConx) {
        visit[v] = true;
        tablaComponentesConexas[v] = compConx;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                *acumulador = *acumulador + 1;
                dfs(g, w, acumulador, compConx);
            }
        }
    }



};


bool resuelveCaso18() {

    // leer los datos de la entrada
    int nUsers, nGrupos;
    cin >> nUsers >> nGrupos;
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo g = Grafo(nUsers);
    for (int i = 0; i < nGrupos; i++) {
        int m;
        cin >> m;
        if (m >= 1) {
            int prim;
            cin >> prim;
            for (int j = 1; j < m; j++) {
                int user;
                cin >> user;
                g.ponArista(prim - 1, user - 1); //contamos a partir de ID 1
            }
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    RedSocial red = RedSocial(g);
    for (int i = 0; i < nUsers; i++) {
        cout << red.expandeNoticia(i) << " ";
    }
    // escribir la solución
    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos14.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso18());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
