/*
1. Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos,
sexo, edad, teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del
mismo.
*/

#include <iostream>
#include <string>

using namespace std; 

struct contactoEmail{
	string 	nombrescompletos; 
	string 	sexo; 
	int 	edad; 
	int 	telefono; 
	string 	email; 
	string 	nacionalidad; 
};

//void agregarContacto(contactoEmail){

//	for(int i=0; )

	
//}

int main(){
	int opcion;
	
	contactoEmail cont;
	 //tam=50; 
	
	//contactoEmail cont[50]; 
	
	do{
			cout<<"-------------------------------------"<<endl; 
			cout<<"---------------MENU------------------"<<endl; 
			cout<<"-------------------------------------"<<endl; 
			cout<<endl<<"Digite una de las siguientes opciones: "<<endl; 
			cout<<"[1] Agregar un contacto. "<<endl; 
			cout<<"[2] Eliminar un contacto. "<<endl; 
			cout<<"[3] Mostrar contactos registrados. "<<endl; 
	  		cout<<"[4] Mostrar lista de contactos, ordenado por servidor de cuentas. "<<endl; 
		   	cout<<"[5] Salir del programa. "; 
		   	cout<<endl<<"Digite el numero de la opcion: "<<endl;
  	   		cin>>opcion;
  	   		
  	   		switch(opcion){
  			     case 1: 
   			  	 cout<<"Digite sus nombres completos: "; 
   			  	 cin.ignore(); 
   			  	 getline(cin,cont.nombrescompletos);  
   			  	 cout<<"Ingrese su sexo: "; 
   			  	 getline(cin, cont.sexo); 
   			  	 cout<<"Ingrese su edad: "; 
   			  	 cin>>cont.edad; 
   			  	 cout<<"Ingrese su telefono: "; 
   			  	 cin>>cont.telefono; 
				 cout<<"Ingrese su email: "; 
				 cin>>cont.email;  
				 cout<<"Ingrese su nacionalidad: "; 
				 cin>>cont.nacionalidad ; 
				 cout<<"\n"; 
				 
				 cout<<"\nNombres completos:"<<cont.nombrescompletos<<endl;  
				 cout<<"Sexo: "<<cont.sexo<<endl; 
				 cout<<"Edad: "<<cont.edad<<endl; 
				 cout<<"Telefono: "<<cont.telefono<<endl; 
				 cout<<"Email: "<<cont.email<<endl; 
				 cout<<"Nacionalidad: "<<cont.nacionalidad<<endl; 
			  
				 default : break;  
  	   		}
  	   		
	}while(opcion != 5); 
	
	
	
	
	return 0; 
}
