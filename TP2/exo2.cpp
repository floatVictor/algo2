#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());
    bool end;
    int cpt = 0;
    for(int i = 0; i < toSort.size(); i++){
        end = true;
        for (int j = 0; j< cpt; j++){
            if (toSort[i] < sorted[j]){
                for(int k = cpt; k > j; k--){
                    sorted[k] = sorted[k-1];
                }
                sorted[j] = toSort[i];
                end = false;
                cpt++;
                break;
            }
        }
        if(end){
            sorted[cpt] = toSort[i];
            cpt++;
        }
    }
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
