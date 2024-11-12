/*

Author: Gabriel Lascurain

A01707236

*/

#include <iostream>
#include <fstream>
#include "Heap.h"
#include "Vehiculo.h"
#include <string>
#include <algorithm>

using namespace std;

void mostrarMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Agregar Vehiculo" << endl;
    cout << "2. Eliminar Vehiculo" << endl;
    cout << "3. Imprimir Inventario" << endl;
    cout << "4. Establecer presupuesto" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: " << endl;
}

void ImprimeInventario(Heap<Vehiculo>& heap) {
    cout << "\nInventario de Vehículos:" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|    Marca    |   Tipo   |   Color   |  Año  |  Precio  |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < heap.count; ++i) {
        cout << "| " << heap.data[i].getMarca() << " | "
        << heap.data[i].getTipo() << " | "
        << heap.data[i].getColor() << " | "
        << heap.data[i].getAnio() << " | "
        << " $ " << heap.data[i].getPrecio() << " |" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void BuscarPorPresupuesto(Heap<Vehiculo>& heap, float precioBuscado) {      //búsqueda y escritura
    ofstream archivoSalida("vehiculos_presupuesto.txt");
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    int limite = 0;
    for (int i = 0; i < heap.count && heap.data[i].getPrecio() <= precioBuscado; ++i ) { //encontramos el límite de nuestro presupuesto
        limite++;
    }

    cout << "\nVehículos dentro del presupuesto: $" << precioBuscado << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|    Marca    |   Tipo   |   Color   |  Año  |  Precio  |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    archivoSalida << "Vehículos dentro del presupuesto: $" << precioBuscado << "\n";
    archivoSalida << "-----------------------------------------------------------\n";
    archivoSalida << "|    Marca    |   Tipo   |   Color   |  Año  |  Precio  |\n";
    archivoSalida << "-----------------------------------------------------------\n";

    for (int i = 0; i < limite; ++i) {
        cout << "| " << heap.data[i].getMarca() << " | "
             << heap.data[i].getTipo() << " | "
             << heap.data[i].getColor() << " | "
             << heap.data[i].getAnio() << " | "
             << " $ " << heap.data[i].getPrecio() << " |" << endl;
                        //Despplegamos tanto en la terminal como en el archivo de salida
        archivoSalida << "| " << heap.data[i].getMarca() << " | "
                      << heap.data[i].getTipo() << " | "
                      << heap.data[i].getColor() << " | "
                      << heap.data[i].getAnio() << " | "
                      << " $ " << heap.data[i].getPrecio() << " |\n";
    }

    cout << "-----------------------------------------------------------" << endl;
    archivoSalida << "-----------------------------------------------------------\n";

    archivoSalida.close();
    cout << "\nInventario guardado en 'vehiculos_presupuesto.txt'.\n";
}

string trim(const string& str) {         //Función auxiliar (creada por ChatGPT) para que las entradas a la función
    size_t first = str.find_first_not_of(" \t");        //cargarHeap sean reconocidas
    size_t last = str.find_last_not_of(" \t");    
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

Heap<Vehiculo> cargarHeap(const string& nombreArchivo) { //Lectura de archivos !!!
    Heap<Vehiculo> heap(100);
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {                
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return heap;
    }

    string linea;
    while (getline(archivo, linea)) {
        Vehiculo vehiculo;
        size_t pos = 0;

        try {
            pos = linea.find(",");
            if (pos == string::npos) throw invalid_argument("Formato incorrecto en precio");
            vehiculo.setPrecio(stoi(trim(linea.substr(0, pos))));
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            if (pos == string::npos) throw invalid_argument("Formato incorrecto en color");
            vehiculo.setColor(trim(linea.substr(0, pos)));
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            if (pos == string::npos) throw invalid_argument("Formato incorrecto en tipo");
            vehiculo.setTipo(trim(linea.substr(0, pos)));
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            if (pos == string::npos) throw invalid_argument("Formato incorrecto en marca");
            vehiculo.setMarca(trim(linea.substr(0, pos)));
            linea.erase(0, pos + 1);

            vehiculo.setAnio(stoi(trim(linea)));

            heap.add(vehiculo);

        } catch (const invalid_argument& e) {
            cerr << "Error de formato en la línea: " << linea << " - " << e.what() << endl;
        } catch (const out_of_range& e) {
            cerr << "Número fuera de rango en la línea: " << linea << " - " << e.what() << endl;
        }
    }

    archivo.close();
    return heap;
}

int main() {
    string archivo = "vehiculos.txt"; //archivo con el inventrario de ejemplo (creado por ChatGPT para evitar escribir uno por uno)
    Heap<Vehiculo> heap = cargarHeap(archivo);
    int opcion;

    while (opcion != 5) {
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
                    float precioEliminado;

                    cout << "Ingrese el precio del vehiculo a eliminar: ";
                    cin >> precioEliminado;

                    Vehiculo vehiculoEliminado = heap.remove(precioEliminado);
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
                cout << "Ingrese el presupuesto a evaluar: ";
                cin >> precioBuscado;
                BuscarPorPresupuesto(heap, precioBuscado);
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