#include "IPGrado.h"

IPGrado::IPGrado(){
  this->ip = "";
  this->padres = 0;
  this-> hijos = 0;
}

IPGrado::IPGrado(std::string direccion,int pad, int hij){ //Complejidad O(1)
  this->ip = direccion;
  this->padres = pad;
  this-> hijos = hij;

}

std::string IPGrado::toString(){
  return "Dirección: "+ip+" Antecesores: "+to_string(padres)+"  Sucesores: "+to_string(hijos);
}