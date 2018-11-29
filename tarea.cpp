#include <iostream>
using namespace std;

struct Nodo{
    int Info;
    struct Nodo *sgte;
};

typedef Nodo *tpila;

void ingreso(tpila &pila,int valor){
	tpila nuevo ;
	nuevo = new(struct Nodo);
	nuevo->Info=valor;
	nuevo->sgte=pila;
	pila =nuevo;
	
	cout<<"el elemento	"<<valor<<"	fue apilado correctamente."<<endl;
}

int sacar(tpila &pila){
	tpila aux; 
	int n; 
	aux=pila;
	n=aux->Info;
	pila=aux->sgte;
	delete aux;
	return n;
	
}
void mostrar(tpila pila){
	 tpila aux;
     aux = pila;

     while( aux !=NULL )
     {
            cout<<"["<< aux->Info <<"]"<<endl;
            aux = aux->sgte;
     }
	
}

void eliminar(tpila &pila){
tpila borrar;
tpila aux;
int num;

cout<<"indique el numero a eliminar:	";
cin>>num;
borrar=pila;
	while ((borrar!=NULL)&&(borrar->Info != num)){
	aux=borrar;
	borrar=borrar->sgte;
	}
	
	if(borrar==NULL){
		cout<<"el numero no esta dentro de la pila"<<endl;
	}
	else if(aux==NULL){
	pila=pila->sgte;
	delete borrar;	
	}
	else {
		aux->sgte=borrar->sgte;
		delete borrar;
		
	}
}
void destruir(tpila &pila){
while (pila!=NULL){

	tpila aux; 
	int n; 
	aux=pila;
	n=aux->Info;
	pila=aux->sgte;
	delete aux;
}
	
}


void pares(tpila &pila){
int elemento;
    tpila aux;
    aux = pila;  
    tpila NuevoNodo;
    NuevoNodo = new(struct Nodo);
	tpila pila_aux = NULL;
	while( aux != NULL) {
		NuevoNodo = new(struct Nodo);
		if (aux->Info % 2 == 0) {
    
	    } else {
    		NuevoNodo->Info = aux->Info;
        	NuevoNodo->sgte = pila_aux ;
        	pila_aux = NuevoNodo;  
        }
    	aux = aux->sgte;
    }
    destruir(pila);
    aux = pila_aux;
	
	while( aux != NULL) {
		NuevoNodo = new(struct Nodo);
		NuevoNodo->Info = aux->Info;
		NuevoNodo->sgte = pila ;
        pila = NuevoNodo;  
        
    	aux = aux->sgte;
    }
}

void invertir(tpila &pila){
	tpila nuevo;
	tpila aux;
	tpila pila2 =NULL;
	
	aux=pila;
	while(aux != NULL){
		nuevo =new (struct Nodo);
		nuevo->Info=aux->Info;
		nuevo->sgte=pila2;
		pila2=nuevo;
		aux=aux->sgte;
	}
	destruir(pila);
	pila=pila2;
	
	
}
	
void recursividad (tpila &pila){
	
	tpila aux;
	aux = pila;
	if (aux == NULL) {
		return ;
	}
	cout<<endl;
	cout << aux->Info <<endl; 
	recursividad(aux->sgte); 
}

void torre1(int num,char A,char C,char B)
{
    if(num==1)
    {
            cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
             
    }
    else
    {
        torre1(num-1,A,B,C);
        cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        torre1(num-1,B,C,A);
    }
}
 
void torre(tpila pila){
	 int n=0;
        char A,B,C;
 
        cout<<"LAS PILA SON A B C"<<endl;
        while (pila!=NULL){
        	n++;
        	pila=pila->sgte;
		}
        cout<<"NUMERO DE DATOS A PASAR : "<<n<<endl;
        
        torre1(n,'A','C','B');
}




void menu()
{
    cout<<"\n\t IMPLEMENTACION DE PILAS EN C++\n";
    cout<<"1. APILAR "<<endl;
    cout<<"2. DESAPILAR "<<endl;
    cout<<"3. ELIMINAR " <<endl;
    cout<<"4. DESTRUIR PILA "<<endl;
    cout<<"5. ELIMINAR NUMEROS PARES" <<endl;
    cout<<"6. INVERTIR"<<endl;
    cout<<"7. RECURSIVIDAD IMPRIMIR" << endl;
	cout<<"8. TORRE DE HANOI "<<endl;
	cout<<"9. APILAR UN NUMERO FACTORIAL	";
	cout<<"OPCION:	";
 }
 
 int fact(int n){
 	
 	if(n==0){
 		n=1;
	 }
	 else{
	 	n=n*fact(n-1);
	 }
 	return n;
 	
 }
int factorial(tpila &pila){
	int n,A;
	tpila nuevo ;
	nuevo = new(struct Nodo);
	cout<<"INGRESE EL VALOR A FACTORIZA:	";
	cin>>n;
	cout<<"EL VALOR FACTORIZADO ES:	";
	fact(n);
	cout<<fact(n)<<endl;
	A=fact(n);
	nuevo->Info=A;
	nuevo->sgte=pila;
	pila =nuevo;
	
	cout<<"el elemento	"<<A<<"	fue apilado correctamente."<<endl;

}

 

 
int main (){
	tpila pila=NULL;
	int a=1;
	int opc,dato;
	int elem_des ;

	while(a!=0){	
		menu();
		cin>>opc;
		
		switch(opc){

			case 1: cout<<"INDIQUE EL NUMERO A AGREGAR:		";
					cin>>dato;
					ingreso(pila,dato);
					break;
			case 2: cout<<"DESAPILAR"<<endl;
					if(pila!=NULL){
						elem_des=sacar(pila);
						cout<<"EL ELEMENTO DESAPILADO ES:	"<<elem_des<<endl;
					}else{
						cout<<"LA PILA ESTA VACIA."<<endl;
					}
					break;
			case 3: cout<<"ELIMINAR NUMERO"<<endl;
					eliminar(pila);
					break;
			case 4: 
					while(pila!=NULL){
					sacar(pila);
					}
					break;
			case 5: 
					
					pares(pila);
					
					break;
			case 6: 
					invertir(pila);
			
					break;
					
			case 7: 
					recursividad(pila);
					break;
			case 8:
			 		
					torre(pila);
					break;
			case 9: 
					factorial(pila);
				 break;
		}
		system("pause");
		system("cls");
		
		cout<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
		mostrar(pila);
		cout<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
	}

	
	
}
