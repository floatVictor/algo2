#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return nodeIndex*2+1;
}

int Heap::rightChild(int nodeIndex)
{
    return nodeIndex*2+2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
    int i = heapSize;
    this->get(i) = value;
    while(i>0 && this->get(i) > this->get((i-1)/2)){
        this->swap(i,(i-1)/2);
        i = (i-1)/2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    int i_max = nodeIndex;
    int index = i_max;
    if(nodeIndex*2+2 < heapSize && this->get(nodeIndex)<this->get(nodeIndex*2+2)){
            index = nodeIndex*2+2;
    }
    if(nodeIndex*2+1 < heapSize && this->get(index)<this->get(nodeIndex*2+1)){
            index = nodeIndex*2+1;
    }
    if(index != i_max){
        this->swap(i_max,index);
        heapify(heapSize,index);
    }
}

void Heap::buildHeap(Array& numbers)
{
    heapify(numbers.size(),0);
}

void Heap::heapSort()
{
    for(int i=size()-1;i>=0;i--){
            swap(0,i);
            heapify(i,0);
        }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
