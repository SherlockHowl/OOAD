#include <iostream>
#include <vector>
using namespace std;

class graph
{
    private:
    int graphSize;
    std::vector<int> nodeArray;
    std::vector<int> edge1Array;
    std::vector<int> edge2Array;
    std::vector<int> weightArray;
    void addEdge(int node1, int node2, int weight);
    int deleteEdge(int node1, int node2);
    public:
    void addNode(int node);
    void addUEdge(int node1, int node2, int weight);
    void deleteNode(int node);
    void deleteUEdge(int node1, int node2);
    graph();
};
void graph::addEdge(int node1, int node2, int weight) 
{
    edge1Array.push_back(node1);
    edge2Array.push_back(node2);
    weightArray.push_back(weight);
}
void graph::addNode(int node)
{
    nodeArray.push_back(node);
    graphSize++;
}
int graph::deleteEdge(int node1, int node2)
{
    auto it1=edge1Array.begin();
    auto it2=edge2Array.begin();
    for(int i=1,int j)
}
graph::graph()
{
    graphSize=0;
    nodeArray.resize(graphSize);
}

int main()
{
    return 1;
}