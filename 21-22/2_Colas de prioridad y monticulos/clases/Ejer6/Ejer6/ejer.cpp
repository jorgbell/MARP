
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Mart�n
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */

struct Tarea {
    bool repite;
    int ini, fin, periodo;
};

struct compara {
    bool operator()(Tarea const& a, Tarea const& b) {
        return b.ini < a.ini;
    }
};

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelve() {

    // leer los datos de la entrada
    int N, M, T;
    cin >> N >> M >> T;

    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<Tarea, vector<Tarea>, compara> cola;
    int ini, fin, interv;
    for (int i = 0; i < N; ++i) {
        cin >> ini >> fin;
        cola.push({ false,ini,fin,0 });
    }
    for (int i = 0; i < M; ++i) {
        cin >> ini >> fin >> interv;
        cola.push({true,ini,fin,interv});

    }

    bool conflicto = false;

    while (!conflicto && !cola.empty() && cola.top().ini < T){
        auto [repite,ini,fin,periodo] /*sig*/ = cola.top(); cola.pop();

        conflicto = ini < ocupado;

        ocupado = fin;

        if (repite)
            cola.push({ true,ini + periodo,fin + periodo,periodo });
    }

    if (conflicto)
        cout << "SI\N";
    else
        cout << "NO\N";



    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelve());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
