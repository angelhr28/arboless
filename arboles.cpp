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

int i=0;
int a=100000;

void reset(){
	i=0;
	a=100000;
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


int max(Abinario arbol)
{
     if(arbol==NULL){
     	  return 0;
	 }
     else if(i<arbol->Valor){
     	 i=arbol->Valor;
		max(arbol->Der);
    	max(arbol->Izq);
	 }   
    return i;	
}

int min(Abinario arbol){
	if(arbol ==NULL){
		return 0;
	}
	else if(a>arbol->Valor){
		a=arbol->Valor;
		min(arbol->Der);
    	min(arbol->Izq);	
		}
	return a;
}

bool busqueda(Abinario arbol,int bus){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->Valor==bus){
		return true;
	}
	else if(bus<arbol->Valor){
		return busqueda(arbol->Izq,bus);
	}
	else{
		return busqueda(arbol->Der,bus);
	}
}

void preOrden(Abinario arbol){
	if(arbol!=NULL){
		cout<< arbol->Valor<<"	";
		preOrden(arbol->Izq);
		preOrden(arbol->Der);
	}
}
void inOrden(Abinario arbol){
	if(arbol!=NULL){
		inOrden(arbol->Izq);
		cout<<arbol->Valor<<"	";
		inOrden(arbol->Der);
	}
}

void posOrden(Abinario arbol){
	if(arbol!=NULL){
		posOrden(arbol->Izq);
		posOrden(arbol->Der);
		cout<<arbol->Valor<<"	";
	}
	
}

int conteo(Abinario arbol){
	if(arbol!=NULL){
		i++;
		conteo(arbol->Izq);
		conteo(arbol->Der);
	}
	return i;
}

int maxima(int a,int b){
   if (a<b)
      return b;
   else
      return a;
}

int alturaMaxima(Abinario arbol){
   if (arbol != NULL){
      if ((arbol->Der==NULL) && (arbol->Izq==NULL))
         return 0;
      else
         return 1+maxima(alturaMaxima(arbol->Izq),alturaMaxima(arbol->Der));
   }else
      return 0;
}

void hojas(Abinario arbol){
	if(arbol!=NULL){
		
		if((arbol->Izq==NULL) && (arbol->Der==NULL)){
			cout<<arbol->Valor<<"	";
		}
		hojas(arbol->Izq);
		hojas(arbol->Der);
	}
}

void Menu()
{
	cout<<"1. Insertar "<<endl;
	cout<<"2. Mostrar "<<endl;
	cout<<"3. Numero Mayor"<<endl;
	cout<<"4. Numero Menor"<<endl;
	cout<<"5. Busqueda"<<endl;
	cout<<"6. Pre-Orden"<<endl;
	cout<<"7. In-Orden"<<endl;
	cout<<"8. Pos-Orden"<<endl;
	cout<<"9. Numero de elementos"<<endl;
	cout<<"10. Altura y Nivel del arbol"<<endl;
	cout<<"11. Hojas de un arbol"<<endl;
	cout<<"Ingrese la opción que desea: ";
}
int main()
{
    Abinario arbol = NULL;   
	int Opcion,Valor;

	do {
		Menu();
		cin>>Opcion;
		system("cls");
		cout<<"-----------------------------OPERACION REALIZADA------------------------------"<<endl;
		switch(Opcion)
		{
			case 1:
				cout<<"Ingrese valor:"; 
				cin>>Valor;
				insertar( arbol, Valor);
				break;
			case 2:
				cout << "\n Mostrando Arbol binario \n";
				verArbol( arbol,0);
				break;
		
			case 3: cout<<"	Numero mayor: ";
				cout<<max(arbol)<<endl;
				reset();
				break;
				
		
			case 4: cout<<"	Numero menor: ";
				cout<<min(arbol)<<endl;
				reset();
				break;
			case 5:
				int bus;
				cout<<"Digite el valor a buscar."<<endl;
				cin>>bus;
				if(busqueda(arbol,bus)==true){
					cout<<"El valor	"<<bus<<"	se encuentra dentro del arbol."<<endl;
				}
				else {
					cout<<"El numero no existe dentro del arreglo."<<endl;;
				}
				break;
			case 6: 
				preOrden(arbol);
				cout<<endl;
				break;
			
			case 7: 
				inOrden(arbol);
				cout<<endl;
				break;
				
			case 8:
				posOrden(arbol);
				cout<<endl;
				break;
				
			case 9:
				cout<<conteo(arbol)<<endl;
				reset ();	
				break;
			case 10:
				cout<<"El nivel maxima del arbol es :"<<endl;
				cout<<alturaMaxima(arbol)<<endl;
				cout<<"La altura maxima del arbol es :"<<endl;
				cout<<1+alturaMaxima(arbol)<<endl;
				break;
			case 11: 
				cout<<"Los valores de las hojas encontradas son:	"<<endl;
				hojas(arbol);
				cout<<endl;
				break;
		}	
		cout<<"----------------------VALORES DEL ARBOL-----------------------------"<<endl;
		verArbol( arbol,0);
		cout<<"---------------------------------------------------"<<endl;

	} while (Opcion !=20);
}

