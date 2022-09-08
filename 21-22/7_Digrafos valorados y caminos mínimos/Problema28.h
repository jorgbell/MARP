//Hay que comparar dos caminos minimos: en distancia y en numero de aristas
//No usar el algoritmo de dikjstra para buscar ambos a la vez
//Usamos una dfs para saber el menor numero de aristas (menor numero de calles)
//Diksjtra puede encontrar varios caminos de distancia minima pero no compara el numero de aristas, solo se fija en que sea el camino minimo
//Hay que modificar el algoritmo de dikjstra para que encuentre el camino de distancia minima con el menor numero de aristas, compararlo con el camino de dfs
//la mejor forma es pensar que ahora el coste del camino es un par: <distancia, numAristas>
//Si la distancia es menor, el camino es mejor. Peor si la distancia de dos caminos es igual, es mejor el que tiene menos aristas.
//Ahora el vector dist[] tiene que ser de pares, y ahora la cola de prioridad tiene que ordenar por pares.