#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if(size <= 1) return;

	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
    int indexMid = (int)size/2;
    for(int i = 0; i < size; i++){
        if(i != indexMid){
            if(toSort[i] < toSort[indexMid]){
                lowerArray[lowerSize] = toSort[i];
                lowerSize++;
            }
            else{
                greaterArray[greaterSize] = toSort[i];
                greaterSize++;
            }
        }
    }
	
	// recursiv sort of lowerArray and greaterArray
    recursivQuickSort(lowerArray,lowerSize);
    recursivQuickSort(greaterArray,greaterSize);

	// merge
    for(int j = 0; j < lowerSize; j++){
        toSort[j] = lowerArray[j];
    }
    toSort[lowerSize] = toSort[indexMid];
    for(int k = 0; k < greaterSize;k++){
        toSort[k+lowerSize+1] = greaterArray[k];
    }
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
