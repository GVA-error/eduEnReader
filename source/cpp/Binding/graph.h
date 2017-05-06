#ifndef GRAPH_H
#define GRAPH_H

/*
 * Подправленная версия алгоритма поиска длиннейшего пути - мы ищем маршрут
 * Оригинал http://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
*/

// A C++ program to find single source longest distances in a DAG
#include <iostream>
#include <QStack>
#include <QMap>
#include <QList>
#include <QObject>
#include <limits.h>
#include <assert.h>
#define NINF std::numeric_limits<qint32>::min()
using namespace std;

// Graph is represented using adjacency list. Every node of adjacency list
// contains vertex number of the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(qint32 _v, qint32 _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

// Class to represent a graph using adjacency list representation
class Graph : public QObject
{
    Q_OBJECT
    qint32 V;    // No. of vertices'

    // Pointer to an array containing adjacency lists
    QVector<QList<AdjListNode>> adj;

    // A function used by longestPath
    void topologicalSortUtil(qint32 v, QVector<bool> &visited, QStack<qint32> &Stack);
    QList <qint32> getMaxPath(qint32 dist[], map<qint32, qint32> prev);
public:
    Graph(qint32 V);   // Constructor

    // function to add an edge to graph
    void addEdge(qint32 u, qint32 v);

    // Finds longest distances from given source vertex
    QList<qint32> longestPath(qint32 s);
    // .. from All
    QList<qint32> longestPath();

signals:
    void process(qreal);
};

#endif // GRAPH_H
