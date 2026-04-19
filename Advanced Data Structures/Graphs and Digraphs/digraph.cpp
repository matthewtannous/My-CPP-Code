/*
Digraph Implementations using an adjacency list (2D array)
Code from ppt
*/

#include <algorithm>
#include <climits> // for INT_MAX
#include <iostream>
#include <queue> // Queue is used for BFS
#include <vector>
// #include <stack> // Stack is used for DFS

using namespace std;

class Graph
{
public:
    int vertices;
    vector<vector<int>> adjList; // declare vector adjlist

    // constructor
    Graph(int v) : vertices(v), adjList(v) {}

    // function to add a links between vertices
    // adds v to the adjacency list of u, indicating an edge from u to v.
    void addEdge(int u, int v)
    {
        // push_back(v) appends the value v to the end of the adjacency list for
        // vertex u.
        adjList[u].push_back(v);
    }

    // Breadth-First Search (BFS)
    // start, representing the starting vertex for the BFS traversal.
    void BFS(int start)
    {
        // creates a boolean vector visited of size vertices
        // (the total number of vertices in the graph) initialized with false.
        vector<bool> visited(vertices, false);

        // queue<int> q declares a queue q of integers.
        // to keep track of vertices that are discovered during the BFS
        // traversal
        queue<int> q;

        // marks the starting vertex start as visited.
        visited[start] = true;

        // adds the starting vertex start to the queue q.
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";

        // This while loop continues until the queue q becomes empty
        while (!q.empty())
        {
            // retrieves the front element of the queue q
            int current = q.front();
            cout << current << " ";
            // removes the current vertex from the queue since it has been fully
            // explored.
            q.pop();

            // This for loop iterates over all neighbors of the current vertex
            // current by accessing the adjacency list of current stored in
            // adjList.
            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    // If the neighbor vertex has not been visited, it marks it
                    // as visited.
                    visited[neighbor] = true;

                    // then adds the neighbor vertex to the queue q to explore
                    // it in the next iterations of the while loop.
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    /* Depth-First Search (helper function) (DFS): takes two parameters:
     * current, representing the current vertex being visited,and visited, which
     * is a reference to a boolean vector indicating whether each vertex has
     * been visited.
     */
    void DFSUtil(int current, vector<bool> &visited)
    {
        // marks the current vertex current as visited.
        visited[current] = true;
        cout << current << " ";

        // loop iterates over all neighbors of the current vertex current
        for (int neighbor : adjList[current])
        {

            if (!visited[neighbor])
            {

                // If the neighbor vertex has not been visited,
                // it recursively calls DFSUtil to visit that neighbor.
                DFSUtil(neighbor, visited);
            }
        }
    }

    /* Depth - First Search(DFS): This is the main DFS function. It takes a
     * parameter start, representing the starting vertex for the DFS
     * traversal.
     */
    void DFS(int start)
    {

        // creates a boolean vector visited of size vertices
        // (the total number of vertices in the graph) initialized with false.
        vector<bool> visited(vertices, false);

        cout << "DFS starting from vertex " << start << ": ";

        // calls the DFSUtil function to start the DFS traversal from the vertex
        // start
        DFSUtil(start, visited);
        cout << endl;
    }

    /* Function to find the shortest path from a given start vertex to a
     * specific destination vertex. How can we find the shortest path between
     * two vertices in an unweighted digraph? Since all edges have the same
     * weight, the shortest path will simply be the path with the fewest number
     * of edges.
     */

    vector<int> findShortestPath(int start, int destination)
    {
        // Distance vector stores the shortest distance from the start vertex to
        // all other vertices. Initialize distances to infinity.
        vector<int> distance(vertices, INT_MAX);

        // This vector stores the parent vertex of each vertex in the shortest
        // path. It is initialized with all values set to -1.
        vector<int> parent(vertices, -1);

        // This is a queue used for the BFS traversal.It stores vertices to be
        // visited.
        queue<int> q;

        distance[start] = 0; // Distance to start vertex is 0
        // The start vertex is pushed onto the queue to begin the BFS traversal.
        q.push(start);
        // BFS Traversal:The BFS traversal continues until
        // the queue is empty or until the destination vertex is found.
        while (!q.empty())
        {
            // current is the vertex being processed from the front of the
            // queue.
            int current = q.front();
            q.pop();

            if (current == destination)
                break; // Break if destination is found

            // For each neighbor of the current vertex, we check if
            // the distance to the neighbor through the current vertex
            // is shorter than the distance stored in distance[neighbor].
            for (int neighbor : adjList[current])
            {
                if (distance[current] + 1 < distance[neighbor])
                {
                    // If a shorter path is found, we update the distance to the
                    // neighbor and set its parent to the current vertex. and
                    // the neighbor is then added to the queue for further
                    // exploration.
                    distance[neighbor] = distance[current] + 1;
                    parent[neighbor] = current; // Update parent
                    q.push(neighbor);
                }
            }
        }
        /* After the BFS traversal completes or when the destination vertex is
         * found, we reconstruct the shortest path starting from the destination
         * vertex, we follow the parent pointers stored in the parent array to
         * trace back the path to the start vertex.
         */

        vector<int> shortestPath;
        for (int v = destination; v != -1; v = parent[v])
            shortestPath.push_back(v);

        /* The path is initially constructed in reverse order (from destination
         * to start). We reverse it to obtain the correct order (from start to
         * destination).
         */
        reverse(shortestPath.begin(), shortestPath.end());

        return shortestPath;
    }
};