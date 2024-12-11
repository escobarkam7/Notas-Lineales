#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//esta es opcional, pero la añadimos por si el compilador se pone fresa

struct nodo{
	int valor;
	struct nodo * siguiente;
};//este es un nodo para una lista enlazada simple

struct colaL
{
    struct nodo * inicio;
    struct nodo * final;
};

void creaColaL(struct colaL * cola)
{
    cola->inicio = NULL;
    cola->final = NULL;
}

struct nodo * creaNodo(struct nodo * p, int x){//esta funcion es la que reserva la memoria para el nodo y le asigna un valor
	struct nodo *t=(struct nodo*)malloc(sizeof(struct nodo));//estamos reservando de forma dinmámica la memoria del nodo que vamos a trabajar
	if(t==NULL){//si no tengo memoria u ocurre un segmentation fault, regreso 0
		printf("\nNo puedo crear el nodo D=\n");
		exit(0);//si ponemos exit, evitamos que el programa mande la advertencia de segmentation fault
	}
	t->valor=x;//al nuevo nodo t le damos un valor
	t->siguiente=p;//como sabemos que p tiene la referencia al primer elemento, hacemos que el siguiente de t sea el primero... con esto hacemos que p ya no sea el primer elemento de la pila
	return t;//regresamos el nodo con sus conexiones hacia la funcion que lo llama
}

void formaL(struct colaL * cola, int x){
    //Necesitamos añadir elementos
    struct nodo * t = creaNodo(NULL, x); //Genera el último nodo y su siguiente va ligado con null pq pues va a ser el último new->null

    if (cola->final ==NULL){ //La cola no tiene elementos por lo que será el primero
        cola->inicio = t;
    }
    else{
        cola->final->siguiente = t; //El siguiente del final anterior ahora será el nuevo y se hará el final actual
    }
    cola->final=t; //Y t se vuelve oficialmente el final
}

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

bool desformaL(struct colaL * cola, int *x){ //Elimina nodo
    if(!eliminaNodo(&(cola->inicio), x)) {//Si al querer quitarle inicio da cero es pq la cola está vacía, no hay nodo
        return 0; //No se pudo
    } /*Si el elemento borrado era el último*/
    if(cola->inicio == NULL)
        cola->final == NULL; //Cuando hayas borrado todos el último elemento va a quedar esto, la cola ha sido deformada e incio y final están en null
    return 1; //Sí se pudo
}

void destruyeCola(struct colaL * cola){
    int x;
    while(desformaL(cola,&x));
}

void imprimeCola(struct colaL * cola){ //pedimos la dirección
    struct nodo * t = cola->inicio; //Sacamos el primer elemento de la estructura para poder iterar
    //pq colaL tiene colo elementos de inicio y final y nodo sí tiene siguiente
    while(t!=NULL){
        printf("%d->", t->valor);
        t=t->siguiente;
    }
    printf("NULL\n");
}
int main (){
    struct colaL * cola = (struct colaL*) malloc (sizeof(struct colaL));
    creaColaL(cola);
    //Podemos comenzar a agregar elementos
    formaL(cola,5);// 5->NULL
    imprimeCola(cola);
    formaL(cola,10);//5->10->NULL
    imprimeCola(cola);
    formaL(cola,20);//5->10->20->NULL
    imprimeCola(cola);
    formaL(cola,30);//5->10->20->30->NULL
    imprimeCola(cola);
}