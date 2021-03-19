#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;


void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
    indexMin = indexMax = -1;
    int start = 0;
    int end = array.size();
    int mid,temp;

    while(start < end){
        mid = (start + end)/2;
        if(toSearch > array[mid]) start = mid +1;
        else if(toSearch < array[mid]) end = mid;
        else{
            temp = mid;
            while(temp-1 > start && array[temp-1] == array[mid])
                temp--;
            indexMin = temp;
            temp = mid;
            while (temp+1 <end && array[mid] == array[temp+1])
                temp++;
            indexMax = temp;
            return;
        }
    }

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 300;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
