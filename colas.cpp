#include <iostream>
using namespace std;

struct Cola{
    int Info;
    struct Cola *sgte;
};

typedef Cola *tcola;
bool cola_vacia(tcola frente);
void insertar(tcola &frente, tcola &fin ,int valor);


void insertar(tcola &frente, tcola &fin ,int valor){
	tcola nuevoNodo = new (struct Cola);
	
	nuevoNodo->Info=valor;
	nuevoNodo->sgte=NULL;
	
	if(cola_vacia( frente)){
		frente =nuevoNodo;	
	}
	else{
		fin->sgte=nuevoNodo;
	}
	fin =nuevoNodo;
	cout<<"listo";
}

bool cola_vacia(tcola frente){
return (frente==NULL)? true : false;

//	if(frente==NULL){
//		return true;
//	}
//	else{
//		return false;
//	}
}

void busqueda(tcola frente){
	int bus;
	tcola aux=NULL;
//	tcola busq=NULL;
	cout<<"indique el numero a buscar:	";
	cin>>bus;
	aux=frente;
	while((aux!=NULL)&&(aux->Info!=bus)){
//		busq=aux;
		aux=aux->sgte;
	}
	if(aux==NULL){
		cout<<"el numero no existe dentro de la lista"<<endl;
	}
	else if(aux->Info==bus){
		cout<<"el numero	"<<aux->Info <<"	se encuentra dentro de la cola"<<endl;
	}
	
}

void eliminar(tcola &frente, tcola &fin, int &valor){
	tcola aux=NULL;
	aux=frente;
	if(frente==fin){
		frente=NULL;
		fin=NULL;
		
	}
	else {
		frente=frente->sgte;
	}
	delete aux;
}
void mostrar(tcola frente, tcola fin, int valor){
	while(frente!=NULL){
	if(frente!=fin){
		cout<<frente->Info<<"	,	";
		}
	else{
		cout<<frente->Info<<"	."<<endl;

	}	
	frente=frente->sgte;
	}
}
void eliminar_eleg(tcola &frente){
	int bus;
	tcola aux=NULL;
	tcola delet=NULL;
	cout<<"indique el numero a buscar:	";
	cin>>bus;
	delet=frente;
	while((delet!=NULL)&&(delet->Info!=bus)){
		aux=delet;
		delet=delet->sgte;
	}	
	if(delet==NULL){
		cout<<"el numero no se encuentra"<<endl;
	}else if(aux==NULL){
		frente=frente->sgte;
		delete delet;
	}else {
		aux->sgte=delet->sgte;
		delete delet;
	}
}

int main (){
	tcola frente=NULL;
	tcola fin=NULL;
	int dato,a;
	int opc=1;
	while(opc!=0){
	cout<<"ingrese una opcion";
	cin>>a;
	switch(a){
	
	case 1:	
			cout<<"ingrese dato";
			cin>>dato;
			insertar(frente , fin , dato);
			break;
	case 2:
		
			cout<<"eliminar";
			eliminar(frente,fin,dato);
			break;
	case 3: 
		mostrar(frente,fin,dato);		
		break;
		
	case 4: 
		busqueda(frente);	
		break;
		
	case 5:
		eliminar_eleg(frente);
		break;
		}
	}
	return 0;
}
