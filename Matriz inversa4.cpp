#include<stdio.h>
#include<stdlib.h>
#include<math.h>


main(){
	
	//declaracion de variables
	
	int fila,columna,tamano,j=0,k=0,n=0,m,determinante1;
	float matriz[4][4],divisor,indice,x1,x2,x3,x4;
	float matriz2[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1,}};
	float independiente[n];
	
	
		printf ("\t\t\tEste programa solo resuelve matrices cuadradas con numeros reales\n");
	//CAPTURA DE MATRIZ-------------------------------
	do{

		printf("\n\nIntroduce el grado de la matriz: ");
		scanf ("%d",&tamano);
	if (tamano<2 or tamano>4){
		printf ("Solo se aceptan matricez de 2x2, 3x3, y 4x4");
			}
	}while(tamano<2 || tamano>4);// validamos que no sea una matriz mas grande que 4x4
		
	tamano=tamano-1;//se le resta 1 porque la matriz comienza de cero no de 1

	for(fila=0; fila<=tamano; fila++){
		
		for(columna=0; columna<=tamano; columna++){
			printf ("digita el valor en la posicion [%d] [%d] ", fila, columna);
			scanf("%f",&matriz[fila][columna]);
			
		}
	
}
//validamos que la determinante no sea cero
switch(tamano){
			
			case 1:
			if((matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1])==0){
			printf ("\n\nEl determinante de la matriz es cero, la matriz es no invertible");
			return 0;
				}
				
				break;
				
				
			case 2:
			if((matriz[0][0]*matriz[1][1]*matriz[2][2]+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1])-(matriz[2][0]*matriz[1][1]*matriz[0][2]+matriz[2][1]*matriz[1][2]*matriz[0][0]+matriz[2][2]*matriz[1][0]*matriz[0][1])==0)){
	printf ("\n\nEl determinante de la matriz es cero, la matriz es no invertible");
	return 0;
}
		
				break;
				
			case 3:
			if((matriz[0][0]*matriz[1][1]*matriz[2][2]*matriz[3][3]+(matriz[0][1]*matriz[1][2]*matriz[2][3]*matriz[3][0])+(matriz[0][2]*matriz[1][3]*matriz[2][0]*matriz[3][1]+(matriz[0][3]*matriz[1][0]*matriz[2][1]*matriz[3][2]))-(matriz[3][0]*matriz[2][1]*matriz[1][2]*matriz[0][3]+matriz[3][1]*matriz[2][2]*matriz[1][3]*matriz[0][0]+matriz[3][2]*matriz[2][3]*matriz[1][0]*matriz[0][1]+(matriz[3][3]*matriz[2][0]*matriz[1][1]*matriz[0][2]))==0)){
	printf ("\n\nEl determinante de la matriz es cero, la matriz es no invertible");
	return 0;
}	
				break;
				
				
		}


//convertir el primero en un 1
divisor=matriz[0][0];
for(k=0;k<=tamano;k++){
	
matriz[0][k]=matriz[0][k]/divisor;
//matriz 2---------------------------
matriz2[0][k]=matriz2[0][k]/divisor;
}
//------------------------------
k=0;
//hacer ceros la segunda fila
indice=matriz[1][0];//para que no nos este cambiando el valor en ese punto con cada ciclo

for(k=0;k<=tamano;k++){
	
	
	matriz[1][k]=((indice*(-1))*matriz[0][k])+matriz[1][k];
	//matriz 2

	matriz2[1][k]=((indice*(-1))*matriz2[0][k])+matriz2[1][k];
	
}

//hacer 0 el [2][0] 
if (tamano>1){//es cuando tamaño sea mayor a 2 pero como ya se le resto 1 al tamaño en la parte de arriba
	indice=matriz[2][0];
	for(k=0;k<=tamano;k++){

	matriz[2][k]=((indice*(-1))*matriz[0][k])+matriz[2][k];
	//matriz 2
	matriz2[2][k]=((indice*-1)*(matriz2[0][k]))+matriz2[2][k];

	}

}
//hacer 0 el [3][0] en caso de que la matriz sea de 4x4
if (tamano>2){
	indice=matriz[3][0];
	
	for(k=0;k<=tamano;k++){

	matriz[3][k]=((indice*(-1))*matriz[0][k])+matriz[3][k];
	//matriz 2
	matriz2[3][k]=((indice*-1)*(matriz2[0][k]))+matriz2[3][k];

	}
	
	
}
	//convertir el segundo 1
k=0;
divisor=matriz[1][1];
for(k=0;k<=tamano;k++){
	
matriz[1][k]=matriz[1][k]/divisor;
//matriz 2
matriz2[1][k]=matriz2[1][k]/divisor;
}
//hacer 0 el [2][1] en caso de que sea de tamaño 3x3
if (tamano>1){
	indice=matriz[2][1];
	k=0;
	for(k=0;k<=tamano;k++){
		matriz[2][k]=(indice*-1)*(matriz[1][k])+matriz[2][k];//REVISAR ESTO
		//Matriz 2
			matriz2[2][k]=(indice*-1)*(matriz2[1][k])+matriz2[2][k];
		
}
//hacer 0 el [3][1] en caso de que sea tamaño 4x4
if (tamano>2){
	indice=matriz[3][1];
	k=0;
	for(k=0;k<=tamano;k++){
		matriz[3][k]=(indice*-1)*(matriz[1][k])+matriz[3][k];//REVISAR ESTO
		//Matriz 2
			matriz2[3][k]=(indice*-1)*(matriz2[1][k])+matriz2[3][k];
		
}

}
//convertir el tercer 1
	k=0;
	divisor=matriz[2][2];
for(k=0;k<=tamano;k++){
	
	matriz[2][k]=matriz[2][k]/divisor;
	//matriz 2
	matriz2[2][k]=matriz2[2][k]/divisor;
}


//convertir en cero el [3][2] si es 4x4
	if (tamano>2){
	indice=matriz[3][2];
	k=0;
	for(k=0;k<=tamano;k++){
		matriz[3][k]=(indice*-1)*(matriz[2][k])+matriz[3][k];
		//Matriz 2
			matriz2[3][k]=(indice*-1)*(matriz2[2][k])+matriz2[3][k];
		
}

}
//convertir el cuarto 1

if (tamano>2){
		k=0;
	divisor=matriz[3][3];
for(k=0;k<=tamano;k++){
	
	matriz[3][k]=matriz[3][k]/divisor;
	//matriz 2
	matriz2[3][k]=matriz2[3][k]/divisor;
}

//convertir en cero el [2][3]
	indice=matriz[2][3];
	k=0;
	for(k=0;k<=tamano;k++){
		matriz[2][k]=(indice*-1)*(matriz[3][k])+matriz[2][k];
		//Matriz 2
			matriz2[2][k]=(indice*-1)*(matriz2[3][k])+matriz2[2][k];
		
}

//convertir en cero el [1][3] 
indice=matriz[1][3];
	k=0;
	for(k=0;k<=tamano;k++){
		matriz[1][k]=(indice*-1)*(matriz[3][k])+matriz[1][k];
		//Matriz 2
			matriz2[1][k]=(indice*-1)*(matriz2[3][k])+matriz2[1][k];
		
}

//convertir en cero el [0][3]
indice=matriz[0][3];
		k=0;
	for(k=0;k<=tamano;k++){
		matriz[0][k]=(indice*-1)*(matriz[3][k])+matriz[0][k];
		//Matriz 2
			matriz2[0][k]=(indice*-1)*(matriz2[3][k])+matriz2[0][k];
		
}
	
}

//convertir el [1][2] en 0
k=0;
indice=matriz[1][2];
for(k=0;k<=tamano;k++){
	matriz[1][k]=(indice*-1)*(matriz[2][k])+matriz[1][k];
	
	//matriz 2
	matriz2[1][k]=(indice*-1)*(matriz2[2][k])+matriz2[1][k];
}
//convertir el [0][2] en 0
k=0;
indice=matriz[0][2];
for(k=0;k<=tamano;k++){
	matriz[0][k]=(indice*-1)*(matriz[2][k])+matriz[0][k];
	
	//matriz 2
	matriz2[0][k]=(indice*-1)*(matriz2[2][k])+matriz2[0][k];
}
}
// hacer cero el [0][1]
k=0;

indice=matriz[0][1];
for(k=0;k<=tamano;k++){
	matriz[0][k]=((indice*(-1))*matriz[1][k])+matriz[0][k];

//matriz 2
	
	matriz2[0][k]=((indice*(-1))*matriz2[1][k])+matriz2[0][k];
}
	printf("\n");

	//imprimir matriz 1----------------------------------
	
	for(fila=0; fila<=tamano; fila++){
		
		for(columna=0; columna<=tamano; columna++){
			printf ("\t%.2f",matriz[fila][columna]);
		
			
		}
		printf("\n\n");
	
}
printf ("-------matriz inversa---------------------------\n\n");
	//imprimir matriz 2----------------------------------

	for(fila=0; fila<=tamano; fila++){
		
		for(columna=0; columna<=tamano; columna++){
			printf ("\t%.2f",matriz2[fila][columna]);
			
		}
		printf("\n");
	
}
//pedimos los terminos independientes
printf("\n");
tamano=tamano+1;
for(n=0;n<tamano;n++){
	m=n+1;
	printf ("introduce el valor del termino independiente de la ecuacion %d : ",m);
	scanf("%f",&independiente[n]);

}
//Operaciones con los resultados de la matriz por los terminos independientes
x1=(independiente[0]*matriz2[0][0])+(independiente[1]*matriz2[0][1])+(independiente[2]*matriz2[0][2])+(independiente[3]*matriz2[0][3]);
x2=(independiente[0]*matriz2[1][0])+(independiente[1]*matriz2[1][1])+(independiente[2]*matriz2[1][2])+(independiente[3]*matriz2[1][3]);
x3=(independiente[0]*matriz2[2][0])+(independiente[1]*matriz2[2][1])+(independiente[2]*matriz2[2][2])+(independiente[3]*matriz2[2][3]);
x4=(independiente[0]*matriz2[3][0])+(independiente[1]*matriz2[3][1])+(independiente[2]*matriz2[3][2])+(independiente[3]*matriz2[3][3]);
printf ("\nx1=%.2f \nx2=%.2f \nx3=%.2f \nx4=%.2f",x1,x2,x3,x4);

	return 0;
	
}
