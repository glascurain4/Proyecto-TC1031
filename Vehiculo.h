/*

Author: Gabriel Lascurain

A01707236

*/

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
    void setPrecio(float);
    void setColor(string);
    void setTipo(string);
    void setMarca(string);
    void setAnio(int);
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

void Vehiculo::setPrecio(float p) {
  precio = p;
}

void Vehiculo::setMarca(string m) {
  marca = m;
}

void Vehiculo::setColor(string c) {
  color = c;
}

void Vehiculo::setTipo(string t) {
  tipo = t;
}

void Vehiculo::setAnio(int a) {
  anio = a;
}

string Vehiculo::getDatos() {
  return  marca + " " + tipo + " " + color + " (" + to_string(anio) + ") - $" + to_string(precio);
}

#endif