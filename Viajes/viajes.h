//Numero de pasajeros
#define TP 40

//EStructura de pasajeros
typedef struct pasajeros{
	char nombre[20];
	char apellido[20];
	int edad;
	int asiento;
}Pasajero;

//Estructura de camiones
typedef struct{
	Pasajero asientos[TP];
	int hora;
	int camion;
	int precio;
	char destino[10];
	int pos;
}Camion;

//Funciones pasajero
void ingresarPasajero(Camion *c){
	Pasajero a;
	printf("Ingrese el nombre del pasajero: ");
	fflush(stdin);
	scanf("%s",&(*(a.nombre)));
	printf("Ingrese el primer apellido del pasajero");
	fflush(stdin);
	scanf("%s",&(*(a.apellido)));
	printf("Ingrese la edad del pasajero: ");
	fflush(stdin);
	scanf("%d", &(a.edad));
	printf("El asiento se le otorgara por default\n Su asiento es: %d\n", (c->pos)+1);
	a.asiento=((c->pos)+1);
	c->asientos[c->pos]=(a);
	c->pos++;
}

void mostrarPasajero(Pasajero a){
	printf("Nombre: %s\nApellido: %s\nEdad: %d\nAsiento:%d\n", a.nombre, a.apellido, a.edad, a.asiento);	
}

//Funciones camion
void ingresarCamion(Camion *a, int nC){
	printf("Ingrese la hora de salida del camion: ");
	scanf("%d", &(a->hora));
	printf("El numero de camion se da por default\n Su munero es:%d\n", nC);
	a->camion=nC;
	printf("Ingrese el precio: ");
	fflush(stdin);
	scanf("%d", &(a->precio));
	printf("Ingrese el destino del camion: ");
	fflush(stdin);
	scanf("%s",&(*(a->destino)));
	a->pos=0;
}
void mostrarCamion(Camion a){
	printf("Destino: %s\nHora: %d\nNumero de camion: %d\nPrecio:%d\n",a.destino, a.hora, a.camion, a.precio);	
}

void mostrarPasajeroCamion(Camion c){
	int i;
	for(i=0; i<c.pos; i++){
		mostrarPasajero(c.asientos[i]);
		puts("\n");
	}
}
int asientosDisponibles(Camion c){
	int a=0;
if(c.pos==TP)
	printf("No hay asientos disponibles\n");
else
	a=TP-c.pos;
return a;
}
