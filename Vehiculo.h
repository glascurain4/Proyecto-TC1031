#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
  private:
    float precio;
    string color;
    string tipo;
    string marca;
    int anio;

  public:
    Vehiculo();
    Vehiculo(float, string, string, string, int);
    float getPrecio();
    string getColor();
    string getTipo();
    string getMarca();
    int getAnio();
    string getDatos();
};

Vehiculo::Vehiculo() {
  precio = 0;
  color = "";
  tipo = "";
  marca = "";
  anio = 0;
}

Vehiculo::Vehiculo(float pre, string col, string tip, string mar, int ani) {
  precio = pre;
  color = col;
  tipo = tip;
  marca = mar;
  anio = ani;
}

float Vehiculo::getPrecio() {
  return precio;
}

string Vehiculo::getMarca() {
  return marca;
}

string Vehiculo::getColor() {
  return color;
}

string Vehiculo::getTipo() {
  return tipo;
}

int Vehiculo::getAnio() {
  return anio;
}

string Vehiculo::getDatos() {
  return  marca + " " + tipo + " " + color + " (" + to_string(anio) + ") - $" + to_string(precio);
}

#endif