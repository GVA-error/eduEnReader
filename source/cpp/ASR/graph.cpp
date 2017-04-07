#include "graph.h"

Graph::Graph(qint32 V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(qint32 u, qint32 v)
{
    AdjListNode node(v, 1);
    adj[u].push_back(node); // Add v to u's list
}

// A recursive function used by longestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(qint32 v, QVector <bool>& visited, QStack<qint32> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    QList<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }

    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}

// The function to find longest distances from a given vertex. It uses
// recursive topologicalSortUtil() to get topological sorting.
QList <qint32> Graph::longestPath(qint32 s)
{
    map<qint32, qint32> prev; // говорит из какой вершины мы пришли

    for (qint32 i = 0; i < V; i++)
        prev[i] = NINF;

    QStack<qint32> Stack;
    qint32 dist[V];

    // Mark all the vertices as not visited
    QVector <bool> visited;
    visited.resize(V);
    for (qint32 i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (qint32 i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (qint32 i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;

    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        qint32 u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices
        QList<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] < dist[u] + i->getWeight())
             {
                 prev[i->getV()] = u;
                 dist[i->getV()] = dist[u] + i->getWeight();
             }
        }
    }

    // Print the calculated longest distances
    QList <qint32> path = getMaxPath(dist, prev);
    return path;
}

QList <qint32> Graph::getMaxPath(qint32 dist[], map<qint32, qint32> prev)
{
    QList <qint32> path;

    qint32 cur = V-1;
    qint32 maxDistance = 0;
    for (qint32 c=0; c<V; c++)
        if (maxDistance < dist[c])
        {
            maxDistance = dist[c];
            cur = c;
        }

    while (cur != NINF)
    {
        path.push_front(cur);
        cur = prev[cur];
        assert(path.size() <= V);
    }
    return path;
}

QList<qint32> Graph::longestPath()
{
    QList <qint32> rezPath;
    for (qint32 i = 0; i<V; i++)
    {
        QList <qint32> curPath = longestPath(i);
        if (curPath.size() > rezPath.size())
            rezPath = curPath;
    }
   // std::cout << "Path ";
   // for (auto pos : rezPath)
   //     std::cout << pos << " ";
    return rezPath;
}
