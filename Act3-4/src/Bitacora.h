/* Declaración de la clase Bitacora
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <vector>
#include "Registro.h"

class Bitacora{
	private:
		std::vector <Registro> data;
		void heapify(int n, int root);
	public:
		Bitacora(std::string fileName);
		Registro operator[](int position);
		void heapSort();
		void guardarArchivo(std::string fileName);
		void contarIncidencias(std::string fileName);
};

#endif
