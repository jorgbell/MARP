
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

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Para saber a cuantas personas llega la noticia, entendemos los grupos de difusion de la noticia como componentes conexas.
Todos los vertices que difunden una noticia forman parte de la misma componente conexa.
Entendiendo esto, lo que debemos saber es qué tamaño tiene cada componente conexa, y a qué componente conexa pertenece cada vertice.
Para ello, recorreremos todos los vertices que hay en el grafo, y si aún no los hemos visitado, quiere decir que forman parte de una nueva componente conexa.
Si forman parte de una nueva componente conexa, es decir, un nuevo grupo de difusion, con el algoritmo dfs indicamos a qué componente conexa corresponde dicho vertice.
Con este mismo algoritmo comprobamos los nuevos vertices a los cuales el está conectado de manera recursiva y los vamos marcando como parte de la misma componente conexa.
Al final, el numero de veces que hacemos esta llamada recursiva, será el tamaño de dicha componente conexa.
Una vez cerrada una componente conexa, tenemos que comprobar el siguiente vertice que no se haya visitado aun, ya que formara parte de una nueva componente conexa.
Repetimos el proceso. Al final, podremos acceder a qué componente conexa pertenece el vertice v y qué tamaño tiene esa componente conexa.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class DifundirNoticia {
public:
	DifundirNoticia(Grafo const& g) :
		visit(g.V(), false),
		index_compConexas(g.V())
	{
		for (int i = 0; i < g.V(); i++) {
			if (!visit[i]) {
				//estamos recorriendo una nueva componente conexa.
				int tam = 1;//acumulador para saber el tamaño final de la componente conexa que estamos comprobando
				dfs(g, i, tam);
				tam_compConexas.push_back(tam);
			}	
		}
	}

	int getAllegados(int v) {
		//devuelve a cuantas personas les ha llegado la noticia si comienza desde el vertice v
		return tam_compConexas[index_compConexas[v]];
	}


private:
	vector<bool> visit;
	vector<int> tam_compConexas;
	vector<int> index_compConexas;
	void dfs(Grafo const& g, int v, int& tam) {
		visit[v] = true;
		index_compConexas[v] = tam_compConexas.size(); //se añade a la ultima componente conexa existente hasta el momento
		for (int w : g.ady(v)) {
			if (!visit[w]) {
				tam += 1;
				dfs(g, w,tam);
			}
		}
	}
};


bool resuelveCaso() {

	// leer los datos de la entrada
	int nUsers, nGroups;
	cin >> nUsers >> nGroups;
	if (!std::cin)  // fin de la entrada
		return false;
	Grafo grupos = Grafo(nUsers);
	for (int i = 0; i < nGroups; i++) {
		int groupSize;
		cin >> groupSize;
		if (groupSize >= 1) { //si es un grupo no vacio con minimo 1 persona
			int s; //origen del grupo
			cin >> s;
			for (int j = 1; j < groupSize; j++) { //empieza en 1 porque hemos leido ya el origen
				int user;
				cin >> user;
				grupos.ponArista(s - 1, user - 1); //restamos 1 porque estamos contando el ID de los usuarios empezando en 1 en lugar de en 0
			}
		}
	}
	// resolver el caso posiblemente llamando a otras funciones
	DifundirNoticia sol = DifundirNoticia(grupos);
	for (int i = 0; i < nUsers; i++) {
		cout << sol.getAllegados(i)<< " ";
	}
	cout << "\n";
	// escribir la solución

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
