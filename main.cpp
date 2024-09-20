#include <iostream>
#include <string>
#include <vector>
#include "Vehiculo.h"

using namespace std;

// Imprimir el inventario
void mostrarInventario(vector<Vehiculo>& vehiculos) {
    for (int i=0; i < vehiculos.size(); i++) {
        cout << vehiculos[i].getDatos() << endl;
    }
}

//Funcion Merge para cada caso usando vectores
void merge(vector<Vehiculo>& vehiculos, int inicio, int medio, int fin, const string& atributo) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Vectores temporales
    vector<Vehiculo> izq(vehiculos.begin() + inicio, vehiculos.begin() + inicio + n1);
    vector<Vehiculo> der(vehiculos.begin() + medio + 1, vehiculos.begin() + medio + 1 + n2);

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (atributo == "precio") {
            if (izq[i].getPrecio() <= der[j].getPrecio()) {
                vehiculos[k] = izq[i];
                i++;
            } else {
                vehiculos[k] = der[j];
                j++;
            }
        } else if (atributo == "anio") {
            if (izq[i].getAnio() <= der[j].getAnio()) {
                vehiculos[k] = izq[i];
                i++;
            } else {
                vehiculos[k] = der[j];
                j++;
            }
        } else if (atributo == "marca") {
            if (izq[i].getMarca() <= der[j].getMarca()) {
                vehiculos[k] = izq[i];
                i++;
            } else {
                vehiculos[k] = der[j];
                j++;
            }
        }
        k++;
    }

    // Copiar los elementos restantes
    while (i < n1) {
        vehiculos[k] = izq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vehiculos[k] = der[j];
        j++;
        k++;
    }
}

// Merge Sort usando vectores
void mergeSort(vector<Vehiculo>& vehiculos, int inicio, int fin, const string& atributo) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        mergeSort(vehiculos, inicio, medio, atributo);
        mergeSort(vehiculos, medio + 1, fin, atributo);
        merge(vehiculos, inicio, medio, fin, atributo);
    }
}

// Búsqueda binaria
int busquedaBinaria(vector<Vehiculo>& vehiculos, float precioBuscado) {
    mergeSort(vehiculos, 0, vehiculos.size() - 1, "precio");
    int inicio = 0;
    int fin = vehiculos.size() - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        float precioMedio = vehiculos[medio].getPrecio();

        if (precioMedio == precioBuscado) {
            return medio;
        }
        if (precioMedio < precioBuscado) {
            inicio = medio + 1;
        } 
        if (precioMedio > precioBuscado) {
            fin = medio - 1;
        }
        else {
            return medio;
        }
    }
    return -1;
}

int main() {
    vector<Vehiculo> vehiculos = {
        {350000, "Rojo", "Sedán", "Volkswagen", 2018},
        {600000, "Negro", "Sedán", "Mercedes", 2020},
        {450000, "Blanco", "Camioneta", "Chevrolet", 2019},
        {300000, "Azul", "Sedán", "Nissan", 2017},
        {400000, "Gris", "Camioneta", "Renault", 2021},
        {550000, "Negro", "Sedán", "Audi", 2022},
        {380000, "Verde", "Camioneta", "Volkswagen", 2018},
        {580000, "Blanco", "Sedán", "Mercedes", 2021},
        {490000, "Rojo", "Camioneta", "Chevrolet", 2020},
        {320000, "Azul", "Sedán", "Nissan", 2016},
        {430000, "Gris", "Camioneta", "Renault", 2019},
        {520000, "Negro", "Sedán", "Audi", 2020},
        {370000, "Blanco", "Camioneta", "Volkswagen", 2017},
        {610000, "Azul", "Sedán", "Mercedes", 2022},
        {470000, "Negro", "Camioneta", "Chevrolet", 2018},
        {340000, "Verde", "Sedán", "Nissan", 2019},
        {390000, "Gris", "Camioneta", "Renault", 2020},
        {570000, "Blanco", "Sedán", "Audi", 2021},
        {360000, "Rojo", "Camioneta", "Volkswagen", 2016},
        {590000, "Azul", "Sedán", "Mercedes", 2023}
    };
    int opcion;

    // Mostrar el inventario sin ordenar
    cout << "Inventario original:\n";
    mostrarInventario(vehiculos);

    // Preguntar por qué atributo ordenar
    cout << "\n¿Sobre qué atributo desea ordenar?\n";
    cout << "1. Precio\n";
    cout << "2. Año\n";
    cout << "3. Marca\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;

    // Ordenar según la opción seleccionada
    string atributo;
    switch (opcion) {
        case 1:
            atributo = "precio";
            break;
        case 2:
            atributo = "anio";
            break;
        case 3:
            atributo = "marca";
            break;
        default:
            cout << "Opción inválida.\n";
            return 1;
    }
    mergeSort(vehiculos, 0, vehiculos.size() - 1, atributo);

    // Mostrar el inventario ordenado
    cout << "\nInventario ordenado:\n";
    mostrarInventario(vehiculos);

    // Búsqueda binaria por precio
    float precioBuscado;
    cout << "\nIngrese el precio del vehículo a buscar: ";
    cin >> precioBuscado;

    int resultado = busquedaBinaria(vehiculos, precioBuscado);

    if (resultado != -1) {
        cout << "Vehículo encontrado: " << vehiculos[resultado].getDatos() << endl;
    } else {
        cout << "Vehículo con precio $" << precioBuscado << " no encontrado.\n";
    }

    return 0;
}
