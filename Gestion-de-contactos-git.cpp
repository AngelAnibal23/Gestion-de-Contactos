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

const int limite_contactos = 50; 

struct contactoEmail{
	string 	nombrescompletos; 
	string 	sexo; 
	int 	edad; 
	int 	telefono; 
	string 	email; 
	string 	nacionalidad; 
};

void agregarContactos(contactoEmail contactos[], int &cantidadContactos){
	if(cantidadContactos >= limite_contactos){
		cout<<"Ya no queda espacio sufieciente para agregar otro contacto. "; 
		
		return; 
	}
	
	contactoEmail cont;
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
	
	contactos[cantidadContactos] = cont;
	cantidadContactos++; 
	
	cout<<"CONTACTO GUARDADO SATISFACTORIAMENTE!\n"; 
	
}

void eliminarContactos(contactoEmail contactos[], int &cantidadContactos, int indice){
	
	if(cantidadContactos==0){
		cout<<"No se ha registrado ningun contacto hasta el momento. "; 
	}
	
	if(indice >= 0 && indice < limite_contactos){
		for(int i=indice; i < cantidadContactos - 1; ++i){
			contactos[i]=contactos[i+1]; 
		}
		
		cantidadContactos--; 
		
		cout<<"\nEL CONTACTO SE ELIMINO SATISFACTORIAMENTE!\n"; 
		cout<<"\n"; 
		
	}
	else{
		cout<<"El indice ingresado no es valido. "; 
	}
}

void mostrarContactos(contactoEmail contactos[], int cantidadContactos){
	if(cantidadContactos == 0){
		cout<<"\nNingun contacto por mostrar. "<<endl;
	}
	else{
	   for(int i=0; i<cantidadContactos; ++i){
	   	cout<<"Contacto: "<<i+1<<" | "<<" -> "<<"INDICE: "<< i <<endl; 
	   	cout<<"Nombres completos: "<<contactos[i].nombrescompletos<<endl;
	   	cout<<"Sexo: "<<contactos[i].sexo<<endl; 
	   	cout<<"Edad: "<<contactos[i].edad<<endl; 
	   	cout<<"Telefono: "<<contactos[i].telefono<<endl; 
	   	cout<<"Email: "<<contactos[i].email<<endl; 
	   	cout<<"Nacionalidad: "<<contactos[i].nacionalidad<<endl; 
	   	cout<<"\n"; 
	   }
	}
}

string obtenerDominio(const string& email){
    int buscarroba=-1;
    for (int i=0;i<email.length();++i){
        if(email[i]=='@') {
            buscarroba=i;
            break;
        }
    }
    if(buscarroba == -1){
        return "";
    }
    string dominio = "";
    for(int i = buscarroba + 1; i<email.length();++i){
        dominio+=email[i];
    }
    return dominio;
}

void ordenServidor(contactoEmail contactos[], int cantidadContactos) {
    for (int i = 0; i<cantidadContactos - 1; ++i) {
        for (int j = 0; j<cantidadContactos - 1 - i; ++j) {
            if (obtenerDominio(contactos[j].email)>obtenerDominio(contactos[j + 1].email)){
                contactoEmail temp =contactos[j];
                contactos[j]=contactos[j + 1];
                contactos[j+1]=temp;
            }
        }
    }
}

int main(){
	int opcion;
	contactoEmail contactos[limite_contactos]; 
	int cantidadContactos=0; 
	
	do{		
			cout<<"\n"; 
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
  	   		cout<<"\n"; 
  	   		
  	   		switch(opcion){
  			     case 1: 
				    agregarContactos(contactos, cantidadContactos);    			  	 
				    break;  
				 	
		 		 case 2: 
		 	        int indice; 
		 	        cout<<"Ingrese el indice del contacto a eliminar."<<endl;
				 	cout<<"Tenga en cuenta que los indices inician desde el 0. Indice: "; 
		 	        cin>>indice; 
		    		eliminarContactos(contactos, cantidadContactos, indice); 
		    		break; 
		    		
  				 case 3:
				    mostrarContactos(contactos, cantidadContactos);  
				    break; 
				    
			     case 4: 
                    if(cantidadContactos == 0){
					cout<<"\nNingun contacto por mostrar. "<<endl;
	}
     	            cout<<"\nMOSTRANDO CONTACTOS SEGUN EL ORDEN POR SERVIDOR: \n"; 
     	            
			     
  		 	        ordenServidor(contactos, cantidadContactos); 
                    mostrarContactos(contactos, cantidadContactos); 
   	  			    break; 
		    	 
		    	 case 5: 
   	 	            cout<<"Saliendo del programa..."<<endl;
						
				 default: break;  
  	   		}
  	   		
	}while(opcion != 5); 
	
	
	
	
	return 0; 
}
