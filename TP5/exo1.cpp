#include <tp5.h>
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});


int HashTable::hash(std::string element)
{
    // use this->size() to get HashTable size

    int val = (int)element[0];
    val = val % this->size();
    return val;
}

void HashTable::insert(std::string element)
{
    int index = hash(element);
    this->get(index) = element;
}

void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
    for (int i=0 ; i<namesCount; i++){
        table.insert(names[i]);
    }
}

bool HashTable::contains(std::string element)
{
    if (this->get(hash(element)) == element) {
        return true;
    }
    return false;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 10;
    w = new HashWindow();
    w->show();

    return a.exec();
}
