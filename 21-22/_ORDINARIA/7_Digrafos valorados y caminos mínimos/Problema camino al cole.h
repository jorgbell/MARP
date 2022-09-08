//hay que encontrar el numero de caminos minimos, por lo que hay que empezar buscando caminos minimos en general.
//modificamos el algoritmo de diksjtra con grafos dirigidos. Como nos dice que se puede recorrer en ambos sentidos, cuando tengamos informacion de una arista, ponemos la contraria.
//Para usar dikjstra con grafos no dirigidos, usaremos un digrafo, pero añadiendo la arista inversa cada vez que tengamos info de una arista. 1->2, 2->1
//Como encontrar los caminos minimos:
//cam[v] cuenta cuantos caminos conocidos hay que vayan desde el origen a V que cuesten dist[v]
//dist[0] = 0; cam[0] = 1 -> hay un camino que vaya del origen al origen (quedarte quieto)
//Cuando con dikksjtra relajamos, cambiamos dist[v], por lo que tenemos que cambiar cam[v].
//Si se da el caso en el que los caminos calculados a un vertice U son utiles para pasar a V porque pasan también por U, comprobando el valor de dist[v], 
//igualamos o sumamos al valor cam[v] el valor de cam[u]




Coste://O(E log V)

class DikkjstraNumero{

    puvlic:

private:
    vector<int> numCaminos //un vector más en DikstraNumero

}


DigrafoValorado<int> grafo(V);
for(int ar = 0; ar<E;++ar){
    
}


