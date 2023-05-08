
/*@ <answer>
*
* Nombre y Apellidos: Jorge Bello Martin
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;


/*@ <answer>
COLECCIONANDO COMICS:

el cliente de la fila que toque solo puede comprar la cima de la fila
tenemos las posiciones de los identificadores dentro de las pilas
se debe escoger la pila cuya cima tenga un menor identificador

cada cliente va a coger el que tenga menor identificador siempre. Por lo tanto, hay que ver cuál es el menor de todos los comics,
comprobar cuantos clientes van a pasar hasta que vaya a llegar a ese identificador
y ese puesto de la fila será la respuesta


@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct comic {
    int pilaID;
    int comicID;
};

bool operator<(comic const& a, comic const& b) {
    return a.comicID < b.comicID;
}
bool operator>(comic const& a, comic const& b) {
    return b < a;
}

using mQueue = priority_queue<comic, vector<comic>, std::greater<comic>>; //ordenaremos de menor a mayor

int resuelve09Exam(vector<stack<int>> pilas, int minID) {
    //este metodo debe devolver la posicion en la cola que debe meterse para conseguir el minID
    //meter las cimas de cada pila en un priority queue y quitar el top del stack correspondiente
    //cuando llegue al minID, parar
    bool encontrado = false;
    int cont = 0;
    mQueue pq;
    //metemos las primeras cimas
    for (int i = 0; i < pilas.size(); i++) {
        pq.push({ i,pilas[i].top() });
    }
    while (!encontrado) {
        //quitamos el que sea menor de todas las cimas y lo quitamos de su propio stack
        comic c = pq.top(); pq.pop(); 
        pilas[c.pilaID].pop();
        cont++; //sumamos uno al contador de la cola
        if (c.comicID == minID) encontrado = true; //en caso de encontrar el menor de todos, paramos
        else { //si aun no lo hemos encontrado, seguimos
            if(!pilas[c.pilaID].empty()) 
                pq.push({ c.pilaID,pilas[c.pilaID].top() });
        }
    }
    return cont;
}


bool resuelveCaso09exam() {

    // leer los datos de la entrada
    int N = 0; //numero de pilas
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<stack<int>> pilas;
    int minID = INT_MAX;
    for (int i = 0; i < N; i++) {
        stack<int> pila;
        int k; //numero de comics en la pila
        cin >> k;
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            pila.push(id);
            if (id < minID) minID = id;
        }
        pilas.push_back(pila);
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << resuelve09Exam(pilas, minID) << '\n';
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main09exam() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos09.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso09exam());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
