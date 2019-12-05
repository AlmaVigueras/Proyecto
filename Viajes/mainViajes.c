#include<stdio.h>
#include<stdlib.h>
#include "viajes.h"
#include "lista.c"

void menu();
void mostrarViajes(struct Lista *L);
void validarAgregarPasajeroACamion(struct Lista **L, int n);
void validarMostrarPasajeroCamion(struct Lista **L, int n);
void validarAsientosDisponibles(struct Lista *L, int n);

int main(){
	menu();
	return 0;
}

//Menu del programa
void menu(){
	int opcion, numeroCamion=1, t;
	char det;
	Camion *c;
	struct Lista *L=NULL;
	do{
		//system("clear");
		printf("Menu: \nElija una opcion\n");
		printf("1.-Insertar camion.\n");
		printf("2.-Insertar pasajeros\n");
		printf("3.-Mostrar pasajeros\n");
		printf("4.-Mostrar viajes\n");
		printf("5.-Mostrar asientos disponibles\n");
		printf("6.-Salir\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				c=(Camion*)malloc(sizeof(Camion));
				ingresarCamion(c, numeroCamion);
				numeroCamion++;
				insertar(&L,c);
				printf("\n*****Camion agregado******\n");
				break;
			case 2:
				printf("\nQue camion tomara(Numero de camion. Ej. 3): ");
				scanf("%d", &t);
				validarAgregarPasajeroACamion(&L, t);
				break;
			case 3:
				printf("\nDe que camion quisiera ver los pasajeros(numero de camion, Ej. 3): ");
				fflush(stdin);
				scanf("%d", &t);
				validarMostrarPasajeroCamion(&L, t);
				break;
			case 4:
				mostrarViajes(L);
				break;
			case 5:
				printf("\nDe que camion quisiera ver los asientos disponibles (numero de camion, Ej. 3): ");
				fflush(stdin);
				scanf("%d", &t);
				validarAsientosDisponibles(L, t);
				break;
			case 6:
				printf("\nVuelva pronto\n");
				break;
		}
	} while(opcion!=6);
}

//Insertar pasejeron a un camion 
void validarAgregarPasajeroACamion(struct Lista **L, int n){
	struct Lista *aux;
	int ban=0;
	for(aux=*L; aux;aux=aux->siguiente){
		if(aux->dato->camion==n){
			ingresarPasajero(aux->dato);
			ban=1;
		}
	}
	if(ban==0)
		printf("\nNo se encontro el camion al que se desea ingresar un pasajero\nConsulta los viajes para mas informacion\n\n");
	else
		printf("\n******Pasajero agragado******\n");
}

//Mostrar pasajeros de un camion
void validarMostrarPasajeroCamion(struct Lista **L, int n){
	struct Lista *aux;
	int ban=0;
	for(aux=*L;aux;aux=aux->siguiente){
		if(aux->dato->camion==n){
			mostrarPasajeroCamion(*(aux->dato));
			ban=1;
		}
	}
	if(ban==0)
		printf("\nNo se encontro el camion del que desea mostrar los pasajeros\nConsulta los viajes para mas informacion\n\n");

}

//Mostrar viajes 
void mostrarViajes(struct Lista *L){
	struct Lista *aux;
	if(L!=NULL){
		for(aux=L; aux;aux=aux->siguiente){
			mostrarCamion(*(aux->dato));
			puts("\n");
		}
	}else
		printf("No hay camiones actualmente\n\n");
}

void validarAsientosDisponibles(struct Lista *L, int n){
	struct Lista *aux;
	int ban=0, asi;
	for(aux=L;aux; aux=aux->siguiente){
		if(aux->dato->camion==n){
			asi=asientosDisponibles(*(aux->dato));
			ban=1;
		}
	}
	if(ban==0)
		printf("\nNo se encontro el camion del que se desea mostrar los asientos disponibles\nConsulta los viajes para mas informacion\n");
	else
		printf("Asientos disponibles: %d\n\n", asi);
}
