#include "digraph.cpp"

int main()
{
    // Example usage
    Graph graph(6);
    graph.addEdge(0, 1); // link from 0 to 1
    graph.addEdge(0, 2); // link from 0 to 2
    graph.addEdge(1, 3); // link from 1 to 3
    graph.addEdge(1, 4); // link from 1 to 4
    graph.addEdge(2, 4); // link from 2 to 4
    graph.addEdge(3, 5); // link from 3 to 5
    graph.addEdge(4, 5); // link from 4 to 5

    // the DFS and BSF will traverse the Digraph starting from 0
    int startVertex = 0;

    // Breadth-First Search
    // Prints:BFS starting from vertex 0: 0 1 2 3 4 5
    graph.BFS(startVertex);

    // Depth-First Search
    // Prints:DFS starting from vertex 0: 0 1 3 5 4 2
    graph.DFS(startVertex);

    // destination vertex (e.g. find the shortest path from 0 to 5)
    int destinationVertex = 5;

    // Find the shortest path from startVertex to destinationVertex
    // call function findShortestPath()
    vector<int> shortestPath =
        graph.findShortestPath(startVertex, destinationVertex);

    // Prints: Shortest path from vertex 0 to vertex 5: 0 1 3 5
    cout << "Shortest path from vertex " << startVertex << " to vertex "
         << destinationVertex << ": ";

    /* iterates over each element of the shortestPath vector int vertex: This
     * declares a variable vertex of type int, which holds the value of each
     * element in the shortestPath vector during each iteration of the loop.
     */
    for (int vertex : shortestPath)
        cout << vertex << " ";
    cout << endl;

    return 0;
}