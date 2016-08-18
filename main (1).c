#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>

/* DESARROLLADO POR:
	- Mauricio Villanueva */
void salir();
opSalir=0;
/* Retorna un número del intervalo recibido como parametro. */
int mrand(int min, int max)
{
	rand();
    return rand()*(max-min+1)/RAND_MAX + min;
}

void main ()
{
	system("color 8f"); /* Cambia los colores de la consola */
	
	/*Variables a utilizar.*/
	int nIntentos=0,nIngresado=0;
	int nAzar1=0,nAzar2=0,nAzar3=0,nAzar4=0;
	int nIngresado1=0,nIngresado2=0,nIngresado3=0,nIngresado4=0;
	int toque=0,fama=0,opMenu=0,opSalir=0;
	
	/* Limpia la consola */
	system("cls");
	
	/*Muestra un menú principal*/
	printf("\t*** TOQUE Y FAMA ***\n");
	printf("\n  Seleccione una opcion:\n");
	printf("\n1: Instrucciones\n");	
	printf("2: Jugar\n");
	printf("3: Salir\n");
	scanf("%d",&opMenu); 
	
	/* Realiza una acción dependiendo de la opción ingresada. */
	switch(opMenu)
	{
		case 1:
			system("cls");/* Limpia la consola */
			printf("\t*** TOQUE Y FAMA ***\n");
			/*Instrucciones del juego*/
			printf("\nEl juego 'Toque y Fama', consiste en una secuencia de 4 numeros.\n");
			printf("El jugador tiene 10 oportunidades para poder descifrar dicho numero\n");
			printf("y asi poder obtener la Fama. En cada turno el jugador intenta \n");
			printf("adivinar dicha secuencia, por lo que ingresa los digitos que desea. \n");
			printf("Con cada oportunidad, el jugador recibe una respuesta a cada uno de\n");
			printf("sus numeros ingresados. Aparece la cantidad de 'Toques', el \n");
			printf("cual ocurre cuando el numero coincide con un numero de la secuencia, pero\n");
			printf("no se encuentra en su ubicacion correcta. Luego, aparece la cantidad de \n");
			printf("'Famas', esta ocurre cuando un numero coincide con un numero de las \n");
			printf("secuencia y se encuentra en su ubicacion exacta. Por ultimo, si no hay \n");
			printf("'Toque' ni 'Fama',los contadores apareceran en 0. \n");
			printf("\n");
			/* Espera que se pulse una tecla para continuar. */
			system("pause");
			main();/*Retorna al menú incial*/
			break;
		case 2:
			nIntentos=1;
			
    		/* Inicializa el generador aleatorio */
  			srand ( time(NULL) );
			/*Se genera un número al azar de 4 digitos y se asigna a una variable.
			(llama a la función mrand y enviando como parametros el rango del número)*/
			int nAzar = mrand(999,10000);
	
			/*Se descompone el número, asignando cada digito a una variable distinta.
			(Para realizar comparaciones 1 a 1) */
			nAzar1=nAzar/1000;
			nAzar2=(nAzar/100)-nAzar1*10;
			nAzar3=((nAzar/10)-(nAzar1*100)-(nAzar2*10));
			nAzar4=((nAzar/1)-(nAzar1*1000)-(nAzar2*100)-(nAzar3*10));
	
		
			/* este proceso se repetira mientras el número ingresado sea
			distinto del número generado al azar. */
			do
			{   system("cls");
				fama=0;
				toque=0;
				printf("\n%d\n",nAzar);
				printf("\t*** TOQUE Y FAMA ***\n");
				printf("\nNumero secreto: XXXX\n");
				printf("Jugada numero : %d\n", nIntentos);
				/*Se solicia ingresar un número, se repetirá este proceso
				hasta que el número ingresado sea de 4 dígitos. */
				do{
					printf("\n Ingrese un numero de 4 digitos: ");
					scanf("%d",&nIngresado);
				}while((nIngresado<1000)||(nIngresado>9999));
		
				/*Se descompone el número ingresado por el usuario, asignando cada digito
				en una variable distinta. */
				nIngresado1=nIngresado/1000;
				nIngresado2=(nIngresado/100)-nIngresado1*10;
				nIngresado3=((nIngresado/10)-(nIngresado1*100)-(nIngresado2*10));
				nIngresado4=((nIngresado/1)-(nIngresado1*1000)-(nIngresado2*100)-(nIngresado3*10));
		
			
				/*Si el número ingresado es distinto al número generado al azar
				compara los valores 1 a 1 (entre el valor al azar y el valor ingresado por el usuario)
				en busca de coincidencias exactas para determinar si es "fama".
				Si el valor de la posicion no es identico, compara el valor con las otras posiciones
				para determinar si es "toque".*/
		
				if(nAzar!=nIngresado){
				
					if(nIngresado1==nAzar1){
						fama++;
					}else if((nIngresado1!=nIngresado2)&&(nIngresado1!=nIngresado3)&&(nIngresado1!=nIngresado4)) {
				  		if((nIngresado1==nAzar2)||(nIngresado1==nAzar3)||(nIngresado1==nAzar4)){
						  toque++;
				 		}
					 }
					
					if(nIngresado2==nAzar2){
						fama++;
					} else if ((nIngresado2!=nIngresado3)&&(nIngresado2!=nIngresado4)) {
						if((nIngresado2==nAzar1)||(nIngresado2==nAzar3)||(nIngresado2==nAzar4)){
							toque++;
						}
					}
								
		
					if(nIngresado3==nAzar3){
						fama++;
					} else if (nIngresado3!=nIngresado4) {
						if((nIngresado3==nAzar1)||(nIngresado3==nAzar2)||(nIngresado3==nAzar4)){
							toque++;
						}
					}
			
					if(nIngresado4==nAzar4){
						fama++;
					} else if((nIngresado4==nAzar1)||(nIngresado4==nAzar2)||(nIngresado4==nAzar3)){
						toque++;
						}
					 
					/* Muestra por pantalla la cantidad de "toques" y/o "famas" de la jugada. */
					if ((fama==0)&&(toque==0)){
						printf("\nNo tuvo aciertos, intentelo nuevamente.\n");
					}else{
						printf("\nNumero de famas\t\t: %d",fama);
						printf("\nNumero de toques\t: %d\n",toque);
					}
						printf("\n");
						system("pause");/* Espera que se pulse una tecla para continuar. */
					nIntentos++;/*Aumenta en 1 la cantidad de jugadas. */
				}
			}while((nIntentos<=10)&&(nAzar!=nIngresado));
			/*Una vez el número al azar es igual al número ingresado
			se termina el juego, muestra los resultados.*/
			if(nAzar==nIngresado){
				system("cls");
				system("color 8e"); /* Cambia los colores de la consola */
				printf("\t*** TOQUE Y FAMA ***\n");
				printf("\n****** !!Usted adivino el numero secreto!! ******\n");
				printf("\nEl numero secreto es\t:%d",nAzar);
				printf("\nCantidad de intentos\t: %d\n",nIntentos);
				printf("\n");
				system("pause");/* Espera que se pulse una tecla para continuar. */
				main();/*Retorna al menú incial.*/
			}else {
				system("cls");
				system("color 8e"); /* Cambia los colores de la consola */
				printf("\t*** TOQUE Y FAMA ***\n");
				printf("\nSus 10 oportunidades se han agotado.\n");
				printf("\nEl numero secreto era: %d\n",nAzar);
				printf("\n");
				system("pause");/* Espera que se pulse una tecla para continuar. */
				main();/*Retorna al menú incial.*/
			}
			break;
		case 3: /* Confirma que el usuario quiere finalizar la aplicación.*/
					system("cls");
		system("color 8e"); /* Cambia los colores de la consola */
		printf("\t*** TOQUE Y FAMA ***\n");
		printf("\nEsta seguro que desea salir?.\n");
		printf("\n1: Si\n");
		printf("\n2: No\n");
		scanf("%d",&opSalir);
				/*Si la opción seleccionada es 1, finaliza la aplicación
				de lo contrario regresará al menú inicial.*/
				switch (opSalir){
					case 1:	system("cls");
							system("color 8f"); /* Cambia los colores de la consola */
							printf("\n");
							printf("\t**** GRACIAS POR JUGAR! ****\n");
							printf("\n");
							printf("\nAPLICACION DESARROLLADA POR: \n");
							printf("\tMauricio Villanueva\n");
							printf("\n");
							printf("INGENIERIA EN COMPUTACION E INFORMATICA - UNAB\n");
							printf("\n");
							system("pause");/* Espera que se pulse una tecla para continuar. */
							exit(0); /* Función que finaliza la consola. */
							break;
					case 2:	 main();/*Retorna al menú incial.*/
							break;
					default: 
							system("cls");
							system("color 4f"); /* Cambia los colores de la consola */
							printf("\t*** TOQUE Y FAMA ***\n");
							printf("\nOpcion Ingresada no valida, intente nuevamente.\n");
							printf("\n");
							system("pause");/* Espera que se pulse una tecla para continuar. */
							main();/*Retorna al menú incial*/
							break;
				}
		default:
				system("cls");
				system("color 4f"); /* Cambia los colores de la consola */
				printf("\t*** TOQUE Y FAMA ***\n");
				printf("\nOpcion Ingresada no valida, intente nuevamente.\n");
				printf("\n");
				system("pause");/* Espera que se pulse una tecla para continuar. */
				main();/*Retorna al menú incial*/		
	}	
}


