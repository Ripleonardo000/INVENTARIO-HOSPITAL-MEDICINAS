#include <stdio.h>
#include <stdlib.h>
//ESTRUCTURAS DE TIPO HOSPITAL
typedef struct  HOSPITAL{
	char nombre_del_medicamento [25];
	int lote;
	int cantidad;
	float precio_medicamento;	
} Medicamento;
//CREAMOS LAS FUNCIONES CON EL USO DE ARREGLOS Y PUNTEROS
//CREAMOS UN ARREGLO DE TIPO MEDICINAS.
int Solicitar_cantidad();
Medicamento Agregar_medicamento ();
void Mostrar_medicamentos (Medicamento*medicamentos,int Num_medicamentos);
void Mostrar_medicamento (Medicamento*medicamentos,int posicion);
int Busqueda (Medicamento*medicamentos, int Codigo, int contador);
void Despachar_receta(Medicamento*medicamentos, int posicion);

//CREAMOS EL MENU PARA EL USUARIO.
//CON LA SENTENCIA WHILE REALIZAMOS EL ALGORITMO DE ELECCION DE LAS DIFERENTES FUNCIONES EN EL MENU PRINCIPAL.
//Y CON EL USO DEL SWITCH EVALUAMOS LOS DIFERENTES CASOS QUE PUEDEN PASAR, POR EJEMPLO UN MENSAJE DE ERROR CUANDO INGRESAMOS MAS MEDICINAS DE LAS QUE SON.

int main(){
	int Num_medicamentos, elegir=0, contador_medicinas=0;
	Num_medicamentos= Solicitar_cantidad();
	Medicamento medicamentos[Num_medicamentos];
	system("cls");                               //ESTA FUNCION BORRA UNA VEZ QUE SE EJECUTA, BORRA LA PANTALLA DE EJECUCION.
	while (elegir!=5){
	   printf("\n\n Bienvenidos al menu principal\n\n");
	   printf("\n\nSISTEMA DE INVENTARIO DE MEDICAMENTOS\n\n");
	   printf("1) AGREGAR MEDICAMENTO AL INVENTARIO\n\n");
	   printf("2)BUSCAR MEDICAMENTO DENTRO DEL INVENTARIO CON EL NUMERO DE LOTE: \n\n");
	   printf("3)MOSTRAR MEDICAMENTO: \n\n");
	   printf("4) DESPACHAR RECETA:  \n");
	   printf("5) SALIR DE LA APLICACION:  \n");
	   scanf("%d",&elegir);
	    switch(elegir){
	   	    case 1: {                                // NO ES POSIBLE AGREGAR MAS PRODUCTOS SI SOBREPASAMOS EL LIMITE INGRESADO AL INICIO
			    if(contador_medicinas==Num_medicamentos){
			        printf("\nNO ES POSIBLE AGREGAR MAS PRODUCTOS\n");
		    	 }else{	
				    medicamentos[contador_medicinas]= Agregar_medicamento();
				    contador_medicinas++;
				}
				break;
			}
			case 2:{ //SI INGRESAMOS EL NUMERO DE LOTE DE LA MEDICINA INCORRECTO, NOS ENVIA EL MENSAJE DE PRODUCTO NO ENCONTRADO
				int buscado, Codigo;
				printf("POR FAVOR INGRESA EL NUMERO DE LOTE PARA ENCONTRAR EL PRODUCTO: ");
				scanf("%d",&Codigo);
				buscado=Busqueda (medicamentos,Codigo,contador_medicinas);
				if (buscado==-1){
					printf("\nPRODUCTO NO ENCONTRADO\n");
				 }else{
				    Mostrar_medicamento(medicamentos,buscado);
				 }
				break;
			}
			case 3:{ //EN EL CASO 3 NOS MUESTRA TODOS LOS MEDICAMENTOS QUE HEMOS INGRESADO
				Mostrar_medicamentos(medicamentos, contador_medicinas);
				break;
			}
			case 4:{ // EL DESPACHO DE RECETAS
				int buscado, Codigo;
				printf("POR FAVOR INGRESA EL NUMERO DE LOTE PARA ENCONTRAR EL PRODUCTO: ");
				scanf("%d",&Codigo);
				buscado=Busqueda (medicamentos,Codigo,contador_medicinas);
				if (buscado==-1){
					printf("\nPRODUCTO NO ENCONTRADO\n");
				 }else{
				    Mostrar_medicamento(medicamentos,buscado);
				    
				    Despachar_receta(medicamentos,buscado);
				    
				 }
				 
				break;
			}
			case 5:{ //SALIR
				printf("\nSALIR DE LA APLICACION: \n");
				break;
			}
		}
	 }
	 return 0;
}
//EMPEZAMOS CON UNA MEMORIA DEFINIDA, ES DECIR QUE INGRESEMOS LA CANTIDAD PREVIA DE MEDICAMENTOS A INGRESAR AL INVENTARIO.
//SOLICITAMOS LA CANTIDAD DE MEDICINAS A INGRESARSE AL INVENTARIO AL ENCARGADO DEL INVENTARIO DE MEDICINAS.

int Solicitar_cantidad(){
	int cantidad;
	printf("\nPOR FAVOR INGRESA LA CANTIDAD DE MEDICINAS A INGRESAR AL INVENTARIO: \n");
	scanf("%d",&cantidad);
	return cantidad;
}
//ACCEDER A LAS ESTRUCTURAS --> articulo.
Medicamento Agregar_medicamento (){
	Medicamento articulo;
	printf("\nPOR FAVOR INGRESA EL NOMBRE DEL MEDICAMENTO: \n");
	scanf("%s",&articulo.nombre_del_medicamento);
	printf("\n POR FAVOR INGRESA EL PRECIO DEL MEDICAMENTO: \n");
	scanf("%f",&articulo.precio_medicamento);
	printf("\nPOR FAVOR INGRESA EL STOCK DISPONIBLE DEL MEDICAMENTO: \n");
	scanf("%d",&articulo.cantidad);
	printf("\nINGRESA EL NUMERO DE LOTE: \n");
	scanf("%d",&articulo.lote);
	return articulo;
	
}
//CON ESTA FUNCION NOS IMPRIME TODOS LOS MEDICAMENTOS INGRESADOS.
//CON LA AYUDA DE LA SENTENCIA FOR.
void Mostrar_medicamentos (Medicamento*medicamentos,int Num_medicamentos){
	
	for (int i=0;i<Num_medicamentos;i++){
	    printf("\n NOMBRE DEL MEDICAMENTO: %s\n", medicamentos[i].nombre_del_medicamento);
		printf("\n PRECIO DEL MEDICAMENTO: %.2f\n", medicamentos[i].precio_medicamento);
		printf("\n STOCK DEL MEDICAMENTO DISPONIBLE: %d\n", medicamentos[i].cantidad);
		printf("\n EL NUMERO DE LOTE ES: %d\n", medicamentos[i].lote);
		printf("\n\n");
	 }
	
}


//CON ESTA FUNCION IMPRIMER SOLO EL MEDICAMENTO SELECCIONADO EN LA BUSQUEDA.
void Mostrar_medicamento (Medicamento*medicamentos,int posicion){

    printf("\n NOMBRE DEL MEDICAMENTO: %s\n", medicamentos[posicion].nombre_del_medicamento);
	printf("\n PRECIO DEL MEDICAMENTO: %.2f\n", medicamentos[posicion].precio_medicamento);
	printf("\n STOCK DEL MEDICAMENTO DISPONIBLE: %d\n", medicamentos[posicion].cantidad);
	printf("\n EL NUMERO DE LOTE ES: %d\n", medicamentos[posicion].lote);
	printf("\n\n");
}
//PROGRAMAMOS LA FUNCION DE BUSQUEDA
int Busqueda (Medicamento*medicamentos, int Codigo, int contador){
	int i=0;
	for(i;i<contador;i++){
	    if(medicamentos[i].lote==Codigo){
	  	     return i;
	     }	
	 }
	
	return -1;
}
//PROGRAMAMOS LA FUNCION DE DESPACHAR RECETA.
//EVALUAMOS CON LAS SENTENCIAS IF LOS DIFERENTES CASOS QUE PODRIAN PASAR CON LOS VALORES INGRESADOS.
//ADEMAS ME RETORNA EL GASTO AL DESPACHAR LOS MEDICAMENTOS SELECCIONADOS.
void Despachar_receta(Medicamento*medicamentos, int posicion){
	if(medicamentos[posicion].cantidad==0){
		printf("\nLO SENTIMOS, NO DISPONEMOS MAS STOCK\n");
	 }else{
	   int despachar;
	   printf("\nPORFAVOR INGRESE EL NUMERO DE MEDICAMENTOS QUE VA ADQUIRIR: \n");
	   scanf("%d",&despachar);
	   
	    if(medicamentos[posicion].cantidad>=despachar){
	   	   (medicamentos[posicion].cantidad=medicamentos[posicion].cantidad-despachar);
	   	   printf("\nEL VALOR TOTAL A DESPACHAR ES DE: %.2f\n",medicamentos[posicion].precio_medicamento*despachar);
	   	   Mostrar_medicamento(medicamentos, posicion);
	     }else{
	    	printf("\nNO HAY SUFICIENTE STOCK, SOLO CONTAMOS CON %d MEDICAMENTOS", medicamentos[posicion].cantidad);
		 }
	   	    
	 }
	
}