typedef Camion * elem;
struct Lista{
	elem dato;
	struct Lista *siguiente;
};

struct Lista *CrearNodo(struct Lista *lista, elem e){
	lista=(struct Lista*) malloc(sizeof(struct Lista));
	lista->dato=e;
	lista->siguiente=lista;
	return lista;
}

struct Lista insertar(struct Lista **lista, elem e){
	struct Lista *nuevo=CrearNodo(nuevo, e);
	nuevo->siguiente=*lista;
	*lista=nuevo;
}		

void imprimir(struct Lista *lista){
	struct Lista *aux;
	for(aux=lista; aux; aux=aux->siguiente){
		printf("\nCamion: %d \n\n", aux->dato->camion);
		mostrarPasajeroCamion(*(aux->dato));
	}
}
void eliminar(struct Lista **eli, elem e){
	struct Lista *aux;
	int band=0;
	aux=*eli;
	if(aux->dato==e)
		(*eli)=(*eli)->siguiente;
	else{
		for(aux=*eli; aux->siguiente!=NULL&&band!=1; aux=aux->siguiente){
			if(aux->siguiente->dato==e){
				aux->siguiente=aux->siguiente->siguiente;
				band=1;
			}
		}
	}
}

void insertarL(struct Lista *li, elem e){
	struct Lista *nuevo=CrearNodo(nuevo, e);
	nuevo->siguiente=li->siguiente;
	li->siguiente=nuevo;
	}
