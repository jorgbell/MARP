/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Bello Martín
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include <queue>// propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
/*@ <answer>
 
 Tenemos una cola de prioridad en la cual guardamos elementos de tipo Atril, que contendrá información sobre los grupos que hay por cada atril.
 La idea principal es que teniendo un numero p de partituras y n instrumentos, donde p>=n, debemos repartir p-n partituras en todos los instrumentistas.
 Guardaremos una cola de prioridad con prioridad variable, y por cada partitura que tengamos dividiremos el grupo mayor de instrumentistas (el que mayor prioridad tiene)
 entre 2, y lo reordenaremos si es necesario.
 Haremos esto consecutivamente hasta que:
 - nos quedemos sin partituras a repartir (p = 0)
 - cada instrumentista tenga una partitura para si mismo (.top() = 1)
 Para finalizar, haremos un cout del grupo con más instrumentistas agrupados.

 He tenido problemas al usar el comparador, y por lo tanto el resultado no es el deseado, porque reordena la cola de prioridad de manera incorrecta.
 
 @ </answer> */

// =======================================================================
// Escribe el código completo de tu solución aquí debajo, tras la etiqueta
// =======================================================================
//@ <answer>

struct Atril {
    int instrumento;  //id
    int numMusicos; 
    int numPartituras; //numero de partituras que hemos ido añadiendo, para poder calcular la prioridad

};
bool operator<(Atril const& a, Atril const& b) {

    //numMusicos/numPartituras + (numMusicos%numPartituras>0)
    int priorA, priorB;
    priorA = a.numMusicos / a.numPartituras + (a.numMusicos % a.numPartituras > 0);
    priorB = b.numMusicos / b.numPartituras + (b.numMusicos % b.numPartituras > 0);
    return priorB > priorA
        || (priorA == priorB && b.numPartituras>a.numPartituras);
}


void resuelve(priority_queue<Atril>& orquesta, int numPartituras) {
    if (numPartituras == 0)
        return;
    if (orquesta.top().numMusicos == 1)
        return;
    Atril a = { orquesta.top().instrumento, orquesta.top().numMusicos,orquesta.top().numPartituras+1 };
    orquesta.pop(); 
    orquesta.push(a);
    resuelve(orquesta, numPartituras--);

}

bool resuelveCaso() {
  
  // leemos la entrada
  int partituras, numInstrumentos;
  cin >> partituras >> numInstrumentos;
  if (!cin) return false;
  
  // leer el resto del caso y resolverlo
  priority_queue<Atril> orquesta;
  int numMusicos; int i = 0; int prioridad;
  while (i<numInstrumentos){
      cin >> numMusicos;
      orquesta.push({ i+1, numMusicos, 1}); //id, prioridad, partituras (inicialmente 1)
      ++i;        
  }
  resuelve(orquesta, partituras-numInstrumentos);
  int sol = orquesta.top().numMusicos / orquesta.top().numPartituras + (orquesta.top().numMusicos % orquesta.top().numPartituras > 0);
  cout << sol << '\n';
  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
