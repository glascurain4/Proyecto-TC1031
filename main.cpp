/*
Author: Gabriel Lascurain

A01707236
*/

#include <iostream>
#include "Heap.h"
#include "Vehiculo.h"

void mostrarMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Agregar Vehiculo" << endl;
    cout << "2. Eliminar Vehiculo" << endl;
    cout << "3. Imprimir Inventario" << endl;
    cout << "4. Buscar Vehiculo por precio" << endl;
    cout << "5, Salir" << endl;
    cout << "Seleccione una opción: " << endl;
}

void ImprimeInventario(Heap<Vehiculo>& heap) {
    cout << "\nInventario de Vehículos:" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|    Marca    |   Tipo   |   Color   |  Año  |  Precio  |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < heap.count; ++i) {
        cout << "| " << heap.data[i].getMarca() << " | "
        << heap.data[i].getTipo() << " | "
        << heap.data[i].getColor() << " | "
        << heap.data[i].getAnio() << " | "
        << heap.data[i].getPrecio() << " |" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void BuscarVehiculoPorPrecio(Heap<Vehiculo>& heap, float precioBuscado) {
    bool encontrado = false;
    for (unsigned int i = 0; i < heap.count; ++i) {
        if (heap.data[i].getPrecio() == precioBuscado) {
            cout << "Vehículo encontrado: " << heap.data[i].getDatos() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontró ningún vehículo con el precio: $" << precioBuscado << endl;
    }
}

int main() {
    Heap<Vehiculo> heap(100); //Creamos un heap de tamaño 100
    int opcion;

    while (opcion != 4) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                float precio;
                string color, tipo, marca;
                int anio;

                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese el color: ";
                cin >> color;
                cout << "Ingrese el tipo: ";
                cin >> tipo;
                cout << "Ingrese la marca: ";
                cin >> marca;
                cout << "Ingrese el año: ";
                cin >> anio;

                Vehiculo nuevoVehiculo(precio, color, tipo, marca, anio);
                try {
                    heap.add(nuevoVehiculo);
                    cout << "Vehiculo agregado con éxito." << endl;
                } catch (const Overflow&) {
                    cout << "El Heap está lleno. No se puede agregar el vehículo." << endl;
                }
                break;
            }
            case 2: {
                try {
                    Vehiculo vehiculoEliminado = heap.remove();
                    cout << "Vehiculo eliminado: " << vehiculoEliminado.getDatos() << "\n";
                } catch (const NoSuchElement&) {
                    cout << "No hay vehículos para eliminar." << endl;
                }
                break;
            }
            case 3: {
                ImprimeInventario(heap);
                break;
            }
            case 4: { 
                float precioBuscado;
                cout << "Ingrese el precio a buscar: ";
                cin >> precioBuscado;
                BuscarVehiculoPorPrecio(heap, precioBuscado);
                break;
            }
            case 5: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
            }
        }
    }

    return 0;
}