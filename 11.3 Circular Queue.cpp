// circularQueue.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front; //al añadir en resize, al sacar un elemento
    int back; //Espacios no ocupados en el array 0/-1
    int* array;
    int capacity; //Capacidad maxima del array, llena o no
    int size; //Datos que se tienen en verdad dentro del array

    void resize() //Cambiar tamaño array 
    {
        int newCapacity = capacity * 2;
        int* newArray = new int[newCapacity];


        int index = front;
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[index];
            index++;
            if (index == capacity) {
                index = 0;
            }
        }


        delete[] array;
        array = newArray;
        capacity = newCapacity;
        front = 0;
        back = size - 1; //Back es -1
    }
public:
    CircularQueue(int capacidad = 10) {
        capacity = capacidad;
        array = new int[capacidad];
        front = -1;
        back = -1;
        size = 0;
    }
    ~CircularQueue() {
        delete[] array;
    }
    //Ficar a la ultima posicio del array no omplenada
    void enqueue(int x) {
        if (empty() != 0)
        {
            print();
            resize();
        }
        else if (size == capacity)
        {
            print();
            resize();
        }
        array[size] = x; //Llenamos el array con el valor
        size++; //Al añadir valores debemos indicar augmentando el size
    }
    //borrar el valor [0] mes aprop del array
    int dequeue() {
        //int aux;
        //int ultimo = array[size]; //Copia el NULL, otra forma de mover el back?

        //for (int i = 0; i < capacity; i++) 
        //{
        //    aux = array[i + 1];
        //    array[i] = aux;
        //}
        //array[capacity] = ultimo;
        front++;
        return size--; //Como restamos un valor debemos disminuir el size
    }


    bool empty() {
        return size == 0;
    }

    void print()
    { //imprime hasta donde esta escrito
        if (empty())
        {
            cout << "Queue is empty. Nothing to print.\n";
            return;
        }

        cout << "Queue elements: ";
        int index = front;
        for (int i = 0; i < size; ++i)
        {
            cout << array[index] << " ";
            index++;
            if (index == capacity) {
                index = 0;
            }
        }
        cout << endl;
    }
    void print_array()
    {
        cout << "Array entera: ";
        for (int i = 0; i < capacity; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl << endl;
    }
};

int main() {
    CircularQueue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.print_array();

    q.enqueue(40); // This triggers a resize
    q.print();
    q.print_array();

    q.dequeue();
    q.enqueue(50);
    q.print();
    q.print_array();

    return 0;
}