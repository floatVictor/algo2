#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
    for (int i=0; i<nodeCount; i++) {
         this->appendNewNode(new GraphNode(i));
     }
      for (int i=0; i<nodeCount; i++) {
        for (int j=0; j<nodeCount; j++) {
            if (adjacencies[i][j] != 0) {
                this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
            }
        }
     }

}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
    nodes[nodesSize] = first;
     visited[first->value] = true;
     nodesSize++;

     for (Edge* elem=first->edges; elem!=NULL; elem=elem->next) {
         if (not visited[elem->destination->value]) {
            deepTravel(elem->destination, nodes, nodesSize, visited);
         }
     }


}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
    std::queue<GraphNode*> nodeQueue;
    nodeQueue.push(first);

    while (nodeQueue.size()!=0) {
        GraphNode* elemPop = nodeQueue.front();
        nodeQueue.pop();
        nodes[nodesSize] = elemPop;
        visited[elemPop->value] = true;
        nodesSize++;

        for (Edge* elem=first->edges; elem!=nullptr; elem=elem->next) {
         if (visited[elem->destination->value] == false) {
            nodeQueue.push(elem->destination);
         }
     }
    }

}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
    visited[first->value]=true;
    for (Edge * elem=first->edges ; elem!=nullptr ; elem=elem->next){
        if (visited[elem->destination->value]){
            return true;
        }

        else{
            if (detectCycle(elem->destination, visited)==true){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 150;
    w = new GraphWindow();
    w->show();

    return a.exec();
}
