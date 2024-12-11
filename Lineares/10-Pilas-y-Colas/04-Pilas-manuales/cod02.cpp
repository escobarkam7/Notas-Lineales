#include <iostream>

struct nodo{
	int valor;
	struct nodo * siguiente;
};//este es un nodo para una lista enlazada simple

typedef struct nodo * pilaL;//declaramos el tipo pilaL que es un tocayo o equivalente al nodo

//esto es opcional, pero nos va a ayudar a tener cierta claridad al trabajar con el codigo... en esencia porque en vez de trabajar con nodo, vamos a trabajar con la pilaL

bool eliminaNodo(struct nodo **p, int *x){//nuestra funcion realiza el desenlazado y enlazado de los elementos en la lista
//para poder eliminar un elemento (que en este caso se actualiza solamente el apuntador siguiente ->soguiente, estamos haciendo que se elimine un elemento hacia la izquierda)
	struct nodo * t= *p;//copiamos la desreferencia del nodo p que queremos eliminar (copiamos el enlace)
	if(t==NULL)
		return 0;//si no hay nodo, no podemos eliminar
	*x=t->valor;//copiamos el dato a la variable "x" que es donde guardamos la informacion
	*p=t->siguiente;//actualizamos el enlace
	free(t);
	return 1;//si pudimos hacer todo lo anterior, regresamos 1
}

bool desapilaL(pilaL *s, int *x){
	return eliminaNodo(s,x);
}

bool destruyePila(pilaL *s){
	int x;
	while(desapilaL(s, &x));//mientras pueda eliminar elementos, vamos eliminando uno a uno
    return 1;
}

struct nodo * creaNodo( struct nodo * p, int x){//esta funcion es la que reserva la memoria para el nodo y le asigna un valor
	struct nodo *t=(struct nodo*)malloc(sizeof(struct nodo));//estamos reservando de forma dinamica la memoria del nodo que vamos a trabajar
	if(t==NULL){//si no tengo memoria u ocurre un segmentation fault, regreso 0
		printf("\nNo puedo crear el nodo D=\n");
		exit(0);//si ponemos exit, evitamos que el programa mande la advertencia de segmentation fault
	}
	t->valor=x;//al nuevo nodo t le damos un valor
	t->siguiente=p;//como sabemos que p tiene la referencia al primer elemento, hacemos que el siguiente de t sea el primero... con esto hacemos que p ya no sea el primer elemento de la pila
	return t;//regresamos el nodo con sus conexiones hacia la funcion que lo llama
}

void insertaNodo(struct nodo **p, int x){//esta funcion literal, tambien es auxiliar porque necesita mandar a llamar a una funcion que cree el nodo
	struct nodo * t = creaNodo(*p,x);//mandamos a el valor x y mandamos a p
	*p=t;//con esto al crear el nodo, actualizamos nuestra pila, diciendo que el nodo que creamos es el primero
}

void apilaL(pilaL *s, int x){//esta funcion sirve para insertar elementos, pero es solo auxiliar
	insertaNodo(s,x);
}

void imprimePila(pilaL pila){
    pilaL dato = pila; 
    while(dato != NULL){ //Mientras el siguiente valor no sea NULL entonces va a seguir 
        printf("%d->", dato->valor);
        dato = dato->siguiente;
    }
    printf("\n");
}

int main (){
    pilaL pila = NULL; //Creamos estructura de datos que se llame pila
    //en principio nuestra pila está en NULL
    apilaL(&pila,5); //5->NULL
    apilaL(&pila,10);//10->5->NULL
    apilaL(&pila, 15); //15->10->5->NULL
    imprimePila(pila);
    int valor;
    desapilaL(&pila, &valor);
    printf("\nEl valor que quité es: %d", valor);
    desapilaL(&pila, &valor);
    printf("\nEl valor que quité es: %d", valor);
    imprimePila(pila);
}