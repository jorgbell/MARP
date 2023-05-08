# MÉTODOS ALGORÍTMICOS PARA LA RESOLUCIÓN DE PROBLEMAS

RESUMEN GRAFOS:
- NO VALORADOS
  - NO DIRIGIDOS: DFS y BFS normales.
  - DIRIGIDOS: DFS con posible deteccion de ciclos, BFS normal. Tambien puede haber ordenacion topologica.
- VALORADOS
  - NO DIRIGIDOS: DFS normal. BFS = Algoritmo de Kruskal con ARM.
  - DIRIGIDOS: DFS normal. BFS = Algoritmo de Dikjstra.


## GRAFOS NO VALORADOS
**NO DIRIGIDOS**
ENCONTRAR CAMINOS DESDE UN ORIGEN S : DFS. -> RECORRIDO EN PROFUNDIDAD
```c++
class CaminoDFS {
private:
 std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
 std::vector<int> ant; // ant[v] = ultimo vertice antes de llegar a v
 int s; // vertice origen

// cada vertice del grafo solo puede ser argumento de la funcion dfs como maximo una vez
// O(V+A) porque cada vertice solo se visita una vez
void dfs (Grafo const& g, int v) {
 visit[v] = true;
 for (int w : g.ady(v)) {
  if (!visit[w]) {
   ant[w] = v;
   dfs(g, w);
  }
 }
}

public:
 CaminoDFS (Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), s(s) {
  dfs(g, s);
 }

 // ¿hay camino del origen a v?
 bool hayCamino(int v) const {
  return visit[v];
 }

 using Camino = std::deque<int>; // para representar caminos

 // devuelve un camino desde el origen a v (debe existir)
 Camino camino(int v) const {
  if (!hayCamino(v))
   throw std::domain_error("No existe camino");
  Camino cam;
  // recuperamos el camino retrocediendo
  for (int x = v; x != s; x = ant[x])
   cam.push_front(x);
  cam.push_front(s);
  return cam;
 }
};

Si el problema requiere hallar un camino mínimo entre pares de vértices: BFS. Según si se quiere hacer desde un origen o desde distintos origenes cambiar el numero de llamadas.

#### **Encontrar los caminos desde un origen s en un grafo no dirigido**

```
ENCONTRAR CUAL ES EL SUBGRUPO (COMPONENTE CONEXA) MAYOR: Hacer dfs e ir sumando un contador de cada grupo. Recorremos cada uno de los adyacentes para ello
```c++
class MaximaCompConexa {
public: 
 MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
  // bucle que recorre todos los vertices
  for (int v = 0; v < g.V(); ++v) {
   if (!visit[v]) { // se recorre una nueva componente conexa
    int tam = dfs(g, v);
    maxim = max(maxim, tam);
   }
  }
 }

 // tamaño maximo de una componente conexa
 int maximo() const {
  return maxim;
 }

private:
 vector<bool> visit; // vist[v] ? se ha visitado el vértice v?
 int maxim; // tamaño de la componente mayor

 int dfs(Grafo const& g, int v) {
  visit[v] = true;
  int tam = 1;
  for (int w: g.ady(v)) {
   if(!visit[w])
    tam += dfs(g, w);
  }
  return tam;
 }
};
```
ENCONTRAR CAMINOS MÁS CORTOS DESDE UN ORIGEN: BFS -> ANCHURA
```c++
class CaminoMasCorto {
private:
 std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
 std::vector<int> ant; // ant[v] = ultimo vertice antes de llegar a v
 std::vector<int> dist; // dist[v] = artistas en el camino s-v mas corto
 int s; // vertice origen

 // O(V+A)
 void bfs(Grafo const& g) {
  std::queue<int> q;
  dist[s] = 0; visit[s] = true;
  q.push(s);
  while(!q.empty()){
   int v = q.front();
   q.pop();
   for(int w: g.ady(v)){
    if(!visit[w]){
     ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
     q.push(w);
    }
   }
  }
 }

public:
 CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s) {
  bfs(g);
 }

 // ¿hay camino del origen a v?
 bool hayCamino(int v) const {
  return visit[v];
 }

 // numero de aristas entre s y v
 int distancia(int v) const {
  return dist[v];
 }

 // devuelve el camino mas corto desde el origen a v (si existe)
 Camino camino(int v) const {
  if (!hayCamino(v)) throw std::domain_error("No existe camino");
  Camino cam;
  for(int x = v; x != s; x = ant[x])
   cam.push_front(x);
  cam.push_front(s);
  return cam;
 }
};
```

## GRAFOS NO VALORADOS
**DIRIGIDOS**
ENCONTRAR CAMINOS DESDE UN ORIGEN S : DFS. -> RECORRIDO EN PROFUNDIDAD
```c++
class DFSDirigido {
public:
 DFSDirigido(Digrafo const& g, int s) : visit(g.V(), false) {
  dfs(g, s);
 }
 bool alcanzable(int v) const {
  return visit[v];
 }

private:
 std::std::vector<bool> visit; // visit[v] = ¿hay camino dirigido de s a v?

 // O(V+A)
 void dfs(Digrafo const& g, int v) {
  visit[v] = true;
  for (int w : g.ady(v))
   if (!visit[w]) 
    dfs(g, w);
 }
};
```
ENCONTRAR CAMINOS MÁS CORTOS DESDE UN ORIGEN: BFS -> ANCHURA
```c++
class BFSDirigido {
public:
 BFSDirigido(Digrafo const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s) {
  bfs(g);
 }

 bool hayCamino(int v) const {
  return visit[v];
 }

 int distancia(int v) const {
  return dist[v];
 }

 Camino camino(int v) const {
  if (!hayCamino(v)) throw std::domain_error("No existe camino");
  Camino cam;
  for(int x = v; x != s; x = ant[x])
   cam.push_front(x);
  cam.push_front(s);
  return cam;
 }

private:
 std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
 std::vector<int> ant;  // ant[v] = ultimo vertice antes de llegar a v
 std::vector<int> dist;  // dist[v]= aristar en el camino s->v mas corto
 int s;     

 // O(V+A)
 void bfs(Digrafo const& g) {
  std::queue<int> q;
  dist[s] = 0; visit[s] = 0;
  q.push(s);
  while (!q.empty()) {
   int v = q.front();
   q.pop();
   for(int w: g.ady(v)){
    if(!visit[w]){
     ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
     q.push(w);
    }
   }
  }
 } 
};
```
### Ordenación topológica
Para la ordenacion topologica, hacer POSTORDEN INVERSO -> es decir, hacer un dfs (recorrer de manera recursiva, no por niveles) y darle la vuelta al resultado. Usar deque o hacerlo como sea pero es eso.
### Detección de ciclos dirigidos
Hacer un dfs e ir apilando valores, si vuelves a encontrarlo antes de acabar los adyacentes del vertice origen, es que hay un ciclo
```c++
class CicloDirigido {
public:
 // g es DAG
 CicloDirigido(Digrafo const& g) : visit(g.V(), false), ant(g.V()), 
           apilado(g.V(), false), hayciclo(false) {
  for (int v = 0; v < g.V(); ++v)
   if (!visit[v])
    dfs(g, v);
 }

 bool hayCiclo() const { return hayciclo; }

 Camino const& ciclo() const { return _ciclo; }

private:
 std::vector<bool> visit;   // visit[v] = ¿se ha alcanzado a v en el dfs?
 std::vector<int> ant;    // ant[v] = vertice anterior en el camino a v
 std::vector<bool> apilado; // apilado [v] = ¿esta el vertice v en la pila?
 Camino _ciclo;      // ciclo dirigido (vacio si no existe)
 bool hayciclo;

 // tambien construye el ciclo
 // O(V+A)
 void dfs(Digrafo const& g, int v) {
  apilado[v] = true;
  visit[v] = true;
  for (int w : g.ady(v)) {
   if (hayciclo) // si hemos encontrado un ciclo terminamos
    return;
   if(!visit[w]) { // encontrado un nuevo vertice, seguimos
    ant[w] = v;
    dfs(g, w);
   } else if (apilado[w]) { // hemos detectado un ciclo
    // se recupera retrocediendo
    hayciclo = true;
    for (int x = v; x != w; x = ant[x])
     _ciclo.push_front(x);
    _ciclo.push_front(w);
    _ciclo.push_front(v);
   }
  }
  apilado[v] = false;
 }
};
```

## GRAFOS VALORADOS 
**NO DIRIGIDOS**
ENCONTRAR CAMINOS DESDE UN ORIGEN S : DFS. -> RECORRIDO EN PROFUNDIDAD
```c++
// visita los nodos alcanzables desde v respetando el umbral
void dfs(GrafoValorado<int> const& G, int v, int umbral) {
visit[v] = true;
for (auto a : G.ady(v)) {
if (a.valor() < umbral) {
int w = a.otro(v);
if (!visit[w])
dfs(G, w, ancho);
}
}
}
```

### Conjuntos disjuntos
Los usamos para 
```c++
class ConjuntosDisjuntos {
protected:
 int ncjtos; // numero de conjuntos disjuntos
 mutable std::vector<int> p; // enlace al padre
 std::vector<int> tam; // tamano de los arboles

public:
 // particion unitaria de N elementos
 ConjuntosDisjuntos(int N) : ncjtos(N), p(N), tam(N,1) {
  for (int i = 0; i < N; ++i)
   p[i] = i;
 }

 void unir(int a, int b) {
  int i = buscar(a);
  int j = buscar(b);
  if (i == j) return;
  if(tam[i] >= tam[j]) { // i es la raiz del arbol mas grande
   tam[i] += tam[j]; p[j] = i;
  } else {
   tam[j] += tam[i]; p[i] = j;
  }
  --ncjtos;
 }

 // Es a la vuelta de la recursion cuando se hace la compresion de caminos
 // cambiando el padre de 'a' a lo devuelto por la llamada recursiva
 // que es la raiz del arbol donde se encuentra 'a'
 // Es por esto que el atributo 'p' se ha declarado como mutable
 // para poderlo modificar en un metodo const
 int buscar(int a) const {
  if (p.at(a) == a) // es una raiz
   return a;
  else
   return p[a] = buscar(p[a]);
 }

 // O(lg*N)
 bool unidos(int a, int b) const {
  return buscar(a) == buscar(b);
 }

 // O(lg*N)
 int cardinal(int a) const {
  return tam[buscar(a)];
 }

 // O(1)
 int num_cjtos() const {
  return ncjtos;
 }
}
```
### Árbol de recubrimiento de coste mínimo
ES EL BFS DE LOS VALORADOS NO DIRIGIDOS -> ARM. Lo usamos para saber cual es el camino NO DIRIGIDO que recorre TODOS LOS VERTICES y que tenga VALOR MINIMO.
```c++
template <typename Valor>
class ARM {
public:

 ARM(GrafoValorado<Valor> const& g);

 Valor costeARM() const;

 std::vector<Arista<Valor>> ARM() cont;
};
```
#### **Algoritmo de Kruskal utilizando conjuntos disjuntos**
```c++
template <typename Valor>
class ARM_Kruskal {
private:
 std::vector<Arista<Valor>> _ARM;
 Valor coste;

public:
 Valor costeARM() const {
  return coste;
 }

 std::vector<Arista<Valor>> const& ARM() const{
  return _ARM;
 }

 // Kruskal esta en coste O(A log A) en tiempo y en coste O(A) en espacio
 ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0) {
  // conviene priorityqueue porque igual no hace falta ordenar todas las aristas
  PriorityQueue<Arista<Valor>> pq(g.aristas()); // O(A)
  // construimos una particion unitaria
  ConjuntosDisjuntos cjtos(g.V()); // O(V)
  while (!pq.empty()) { // A vueltas
   auto a = pq.top(); pq.pop(); // O(log A)
   int v = a.uno(), w = a.otro(v);
   if (!cjtos.unidos(v,w)) { // O(lg* V)
    cjtos.unir(v, w); // O(lg* V)
    _ARM.push_back(a); coste += a.valor();
    if (_ARM.size() == g.V() - 1) break;
   }
  }
 }
};
```

## GRAFOS VALORADOS 
**DIRIGIDOS**
ENCONTRAR CAMINOS DESDE UN ORIGEN S : DFS. -> RECORRIDO EN PROFUNDIDAD
```c++
// visita los vertices alcanzables desde v respetando el umbral
// O(V+A)
void dfs(DigrafoValorado<int> const& g, int v, int ancho) {
 visit[v] = true;
 for (auto a : g.ady(v)) {
  if (a.valor() > ancho) {
   int w = a.hasta();
   if (!visit[w])
    dfs(g, w, ancho);
  }
 }
}
```
ENCONTRAR CAMINOS CON COSTE MINIMO DESDE UN ORIGEN: BFS -> ANCHURA
```c++
template <typename Valor>
class CaminosMinimos {
public:
 CaminosMinimos(DigrafoValorado<Vaor> const& g, int origen);
 Valor distancia(int v) const;
 Camino<Valor> camino(int v) const;
};

// No es el definitivo
void relajar(AristaDirigida<Valor> a) {
 int v = a.desde(), w = a.hasta();
 if(dist[w] > dist[v] + a.valor()) {
  dist[w] = dist[v] + a.valor();
  ulti[w] = a;
 }
}
```
ENCONTRAR CAMINOS CON COSTE MINIMO DESDE UN ORIGEN: BFS -> DIJKSTRA
#### **Algoritmo de Dijkstra**
Meter IndexPQ.
```c++
template <typename Valor>
class Dijkstra {
public:
 Dijkstra(DigrafoValorado<Valor> const& g, int orig) : 
   origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
  dist[origen] = 0;
  pq.push(origen, 0);
  while(!pq.empty()) {
   int v = pq.top().elem;
   pq.pop();
   for (auto a : g.ady(v))
    relajar(a);
  }
 }

 bool hayCamino(int v) const { return dist[v] != INF; }

 Valor distancia(int v) const { return dist[v]; }

 Camino<Valor> camino(int v) const {
  Camino<Valor> cam;
  // recuperamos el camino retrocediendo
  AristaDirigida<Valor> a;
  for ( a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
   cam.push_front(a);
  cam.push_front(a);
  return cam;
 }

private:
 const Valor INF = std::numeric_limits<Valor>::max();
 int origen;
 std::vector<Valor> dist;
 std::vector<AristaDirigida<Valor>> ulti;
 IndexPQ<Valor> pq;

 void relajar(AristaDirigida<Valor> a) {
  int v = a.desde(), w = a.hasta();
  if (dist[w] > dist[v] + a.valor()) {
   dist[w] = dist[v] + a.valor();
   ulti[w] = a;
   pq.update(w, dist[w]);
  }
 }
};
```


# COLAS DE MEDIANAS
```c++

/*@ <answer>
* Para conseguir una cola de medianas, sacamos una cola de mayor a menor y otra de menor a mayor.
* Siempre tendr�n una diferencia de un elemento. 
* La mediana ser� el elemento top de la cola que tenga m�s elementos
* ejemplo:
* cola vacia-> insertamos 1
*	- se inserta en la cola de min
*	- balancea: todo bien
* insertamos 2
*	- se inserta en la cola de min -> 1,2
*	- balancea: hay una diferencia de 2, por lo que mete el de la cola que tiene mas numeros en la otra (el 1)
* insertamos 3:
*	- se inserta en la cola de max en caso de que sea mayor que el tope de esta. Si no, se inserta en la de mins.
*		- se inserta por lo tanto en la de max, 3>2
*			- min: 2,3
*			- max: 1
* 
* sacamos la mediana: se saca el de la cola que tenga m�s elementos, si son iguales, sacas el de min
* 
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

#include <queue>

class ColaMedianas
{
	// top es mayor
	using MinQueue = std::priority_queue<int, std::vector<int>, std::less<int>>;
	// top es menor
	using MaxQueue = std::priority_queue<int, std::vector<int>, std::greater<int>>;

	MinQueue min;
	MaxQueue max;

public:
	void insertar(int x) {
		if (!max.empty() && x > max.top())
			max.push(x);
		else
			min.push(x);

		balancea();
	}

	bool vacia() const {
		return min.empty() && max.empty();
	}

	int mediana() const {
		if (min.size() >= max.size()) // Utilizamos el valor de la cola con m�s elementos
			return min.top();
		else
			return max.top();
	}

	void quitarMediana() {
		if (min.size() >= max.size()) // Utilizamos el valor de la cola con m�s elementos
			min.pop();
		else
			max.pop();
	}

private:
	void balancea() {
		auto diff = (int)max.size() - (int)min.size();

		if (diff > 1) { // max tiene al menos 2 elementos mas que min
			if (max.empty())
				return;

			min.push(max.top());
			max.pop();
		}
		else if (diff < -1) { // min tiene al menos 2 elementos mas que max
			if (min.empty())
				return;

			max.push(min.top());
			min.pop();
		}
	}
};
```
