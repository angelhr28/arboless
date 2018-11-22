#include <iostream>

using namespace std;

struct Nodo{
     int Valor;
     Nodo *Izq, *Der;
};

typedef struct Nodo *Abinario;
Abinario crearNodo(int x)
{
     Abinario nuevoNodo = new(struct Nodo);
     nuevoNodo->Valor = x;
     nuevoNodo->Izq = NULL;
     nuevoNodo->Der = NULL;

     return nuevoNodo;
}
void insertar(Abinario &arbol, int x)
{   // si el arbol esta vacio
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else{ // si dato insertado es menor a la raiz
          
          if(x < arbol->Valor)
        	insertar(arbol->Izq, x);
          else // si dato insertado el mayor a la raiz
	 	     if (x > arbol->Valor)
          	   insertar(arbol->Der, x);
	 }
}


void verArbol(Abinario arbol, int n)
{
     if(arbol==NULL){
     	  return;
	 }
     else{
     	verArbol(arbol->Der, n+1);
     	for(int i=0; i<n; i++){
         	cout<<"   ";
    	 }
     	cout<< arbol->Valor <<endl;
    	verArbol(arbol->Izq, n+1);
	 }   
     
}
void Menu()
{
	cout<<"1. Insertar "<<endl;
	cout<<"2. Mostrar "<<endl;

	cout<<"Ingrese la opción que desea: ";
}
int main()
{
    Abinario arbol = NULL;   
	int Opcion,Valor;

	do {
		Menu();
		cin>>Opcion;
		switch(Opcion)
		{
			case 1:
				cout<<"Ingrese valor:"; 
				cin>>Valor;
				insertar( arbol, Valor);
				break;
			case 2:
				cout << "\n Mostrando Arbol binario \n";
				verArbol( arbol, 0);
				break;
		
			case 3:
				exit(0);
		}	
	} while (Opcion !=2);
}

