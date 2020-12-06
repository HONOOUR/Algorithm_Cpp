// Graph_DFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stack>
#include <vector>

typedef std::vector<int> adjList;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Graph_DFS
{
public:
    Graph_DFS(int vertexNum)
    {
        arrayVisited.resize(vertexNum);
        adjacencyListGraph.resize(vertexNum);
    }

    std::vector<std::vector<int>> addEdge(int vertexTo, int vertexFrom)
    {
        adjacencyListGraph[vertexTo].push_back(vertexFrom);
        return adjacencyListGraph;
    }
    
    void showGraph(int vertex)
    {
        std::cout << "vertex " << vertex;

        for (int v : adjacencyListGraph[vertex])
            std::cout << " -> " << v;
        std::cout << std::endl;
    }

    void dFSearch(int vertex)
    {
        // starts from an arbitrary node
        // add the node to visited array 
        arrayVisited[vertex] = true;
        // explores as far as possible along each branch before backtracking
        for (auto v :adjacencyListGraph[vertex])
        {
            if (!arrayVisited[v])
            {
                dFSearch(v);
            }
        }
    }

    void topologicalSort_1(int vertex) 
    {
        arrayVisited.resize(5, false);
        // Call the recursive helper function to store Topological 
        // Sort starting from all vertices one by one
        for (int v = 0; v <= arrayVisited.size(); ++v)
        {
            if (!arrayVisited[v])
            {
                topologicalSort_1_DFS(v);
            }
        }
    }

    void topologicalSort_2(int vertex)
    {
        arrayVisited.resize(6, false);
        if (!arrayVisited[vertex])
        {
            topologicalSort_2_DFS(vertex);
            for (int v = 0; v <= arrayVisited.size(); ++v)
            {
                topologicalSort_2_DFS(v);
            }
        }
    }
private:
    std::vector<bool> arrayVisited;
    std::vector<adjList> adjacencyListGraph;
    std::stack<int> vertices;

    void topologicalSort_1_DFS(int vertex)
    {
        arrayVisited[vertex] = true;
        // explores as far as possible along each branch before backtracking
        for (auto v : adjacencyListGraph[vertex])
        {
            if (!arrayVisited[v])
            {
                topologicalSort_1_DFS(v);
            }
        }
    }
    void topologicalSort_2_DFS(int vertex)
    {
        arrayVisited[vertex] = true;
        // explores as far as possible along each branch before backtracking
        if (!vertices.empty())
        {
            for (auto v : adjacencyListGraph[vertices.top()])
            {
                if (!arrayVisited[v])
                {
                    topologicalSort_2_DFS(v);
                }
            }
        }
        // Push current vertex to stack which stores result 
        vertices.push(vertex);
    }
};
