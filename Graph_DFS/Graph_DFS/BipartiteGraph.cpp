#include <iostream>
#include <stack>
#include <vector>

class Bipartite
{
public:
    bool isBipartite(std::vector<std::vector<int>>& graph)
    {
        // starts from an arbitrary node
        // add the node to visited array 
        arrayVisited.resize(graph.size(), false);
        colored.resize(graph.size());
        for (int v = 0; v < graph.size() - 1; v++)
        {
            int color = 1;
            dFS(0, graph, color);
        }
        int redCount = 0;
        int blackCount = 0;
        int none = 0;
        for (auto i : colored)
        {
            if (i == 1)
            {
                redCount++;
            }
            else if (i == 2)
            {
                blackCount++;
            }
            else
            {
                none++;
            }
        }
        return redCount == blackCount;
    }
    void dFS(int vertex, std::vector<std::vector<int>>& graph, int color)
    {
        // color when visiting vertices with two colors 
        // Each node is an integer between 0 and graph.length - 1
        // graph[0] = {1, 3} adjacent nodes (vertices)
        arrayVisited[vertex] = true;
        colored[vertex] = color;
        for (auto v : graph[vertex])
        {
            if (!arrayVisited[v])
            {
                if (color == 1)
                {
                    color = 2;
                }
                else
                {
                    color = 1;
                }
                dFS(v, graph, color);
            }
        }
    }
private:
    // 1 - red, 2 - black
    std::vector<bool> arrayVisited;
    std::vector<int> colored;
};


//0 ____ 1 
//|      |
//|      |
//3 ____ 2