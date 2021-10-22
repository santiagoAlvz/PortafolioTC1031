/* Implementación de los algoritmos de ordenamiento y búsqueda
 * Santiago Álvarez <A01640172@itesm.mx>
 * 15 de septiembre de 2021
 */

template <class T>
void quickSort(std::vector <T> &arr, int l, int r){
	//Algoritmo de Ordenamiento QuickSort
	
	int pi;
	if(l < r){
		//Divide el arreglo y hace una llamada recursiva
		pi = particion(arr, l, r);
		quickSort(arr,l,pi-1);
		quickSort(arr,pi+1,r);
	}
}

template <class T>
int particion(std::vector <T> &arr, int l, int r){
	//Función de división del arreglo, forma parte de QuickSort
	
	T pivote = arr[r];
	T temp;
	int i = l-1;
	
	for(int j = l;j<r;j++){
		if(arr[j] < pivote){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

template <class T>
int busquedaBinaria(std::vector <T> &arr, T key, int l, int r){
	//Algoritmo de búsqueda binaria

	if(l>r) return -1;
	int m = l + (r-l)/2;
	
	if(key == arr[m]) return m;
	else if (key < arr[m])
		return busquedaBinaria(arr,key,l,m-1);
	else
		return busquedaBinaria(arr,key, m+1, r);
}
