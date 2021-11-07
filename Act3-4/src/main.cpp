/* Archivo principal del programa 
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#include <iostream>
#include <string>
#include "Registro.h"
#include "Bitacora.h"

int main(){
	//Función principal del programa
		
	try{
		
		//Lee el archivo bitácora y lo ordena
		Bitacora miBitacora("bitacoraHeap.txt");
		miBitacora.heapSort();
		miBitacora.guardarArchivo("bitacora_ordenada.txt");
		miBitacora.contarIncidencias("ips_con_mayor_acceso.txt");		
		
	} catch(const char* e){
		//Si se pasó una excepción de alguna función, muestra el error
		std::cout<<" **Error. "<<e<<std::endl;
		return -1;
	}
	
	return 0;
}
