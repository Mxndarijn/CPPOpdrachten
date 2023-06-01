/*
	
De "Rule of 350" is een principe dat vaak wordt toegepast bij het ontwerpen van klassen in C++. Het principe stelt dat als een klasse een van de volgende drie functies moet implementeren (destructor, copy constructor, copy assignment operator), het waarschijnlijk nodig is om alle drie de functies te implementeren.

Waarom gebruik je de Rule of 350?
De Rule of 350 is gebaseerd op de "Rule of Three", een ontwerpprincipe dat voorschrijft dat als een klasse een van de drie genoemde functies nodig heeft, het vaak nodig is om ze alle drie te implementeren. Dit komt door de manier waarop C++ omgaat met geheugenbeheer en de standaardimplementaties van deze functies.

Als een klasse bronbeheer heeft, zoals dynamisch gealloceerd geheugen, bestanden, netwerkverbindingen, enz., kan het ontbreken van een van de drie genoemde functies leiden tot geheugenlekken, dubbele verwijzingen of onjuiste deallocatie. De Rule of 350 zorgt ervoor dat de bronnen van een klasse correct worden beheerd en voorkomt problemen die kunnen optreden bij het kopiëren of toewijzen van objecten van die klasse.

Wat kan er fout gaan als je deze regel niet toepast?
Als je de Rule of 350 niet toepast en een van de drie genoemde functies niet implementeert, kunnen er verschillende problemen optreden:

Geheugenlekken: Als een klasse dynamisch gealloceerd geheugen bevat en de destructor niet correct wordt geïmplementeerd, kan het geheugen niet worden vrijgegeven wanneer een object van de klasse wordt vernietigd. Dit resulteert in geheugenlekken.

Dubbele verwijzingen: Als een klasse een pointer naar gedeelde bronnen heeft en de copy constructor of copy assignment operator niet correct worden geïmplementeerd, kan het leiden tot dubbele verwijzingen naar dezelfde bron. Dit kan resulteren in ongewenst gedrag en fouten in de toestand van het object.

Onjuiste deallocatie: Als een klasse bronnen bevat die handmatig moeten worden vrijgegeven, zoals het sluiten van bestanden of het verbreken van netwerkverbindingen, kan het ontbreken van de juiste implementatie van de destructor of copy assignment operator leiden tot onjuiste deallocatie van deze bronnen. Dit kan leiden tot lekkage van systeembronnen en onvoorspelbaar gedrag.

*/

#include <iostream>

class MyResource {
private:
    int* data;
    int size;

public:
    // Constructor
    MyResource(int sz) : size(sz) {
        data = new int[size];
    }

    // Destructor
    ~MyResource() {
        delete[] data;
    }

    // Copy constructor
    MyResource(const MyResource& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }

    // Copy assignment operator
    MyResource& operator=(const MyResource& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Methode om gegevens weer te geven
    void printData() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyResource obj1(5);
    for (int i = 0; i < 5; i++) {
        obj1.printData(); // Originele gegevens weergeven
        obj1 = MyResource(3); // Toewijzing van een nieuw object
        obj1.printData(); // Nieuwe gegevens weergeven
    }

    return 0;
}