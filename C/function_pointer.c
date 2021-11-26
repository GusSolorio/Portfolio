/*Ejercicio de puntero a funciones
 * Gustavo Alejandro Solorio Ramos & Roberto Vazquez Vega
 * 15 de Septiembre 2021 */

#include <stdio.h>

int suma (int a,int b);
int resta (int a,int b);
int division (int a,int b);
int modulo (int a,int b);

void main (void)
{
	int (*OpFunc[])(int,int)={suma,resta,division,modulo};
	int a=0,b=0,resultado=0,operador=0;
	printf("Ingresa el dato A: \n");
	scanf("%d", &a);
	printf("Ingresa el dato B: \n");
	scanf("%d", &b);
	printf("Ingresa la operacion a realizar \n");
	printf("\n'0' Para la suma  || '1' Para  la resta \n'2' Para division || '3' Para el modulo: \n");
	scanf("%d",&operador);
	resultado =OpFunc[operador] (a,b);
	printf("\nEl resultado es: %d\n",resultado);
}

int suma (int a,int b)
{
	return a+b;
}

int resta (int a,int b)
{
	return  a-b;
}

int division (int a,int b)
{
	return a/b;
}

int modulo (int a,int b)
{
	return  a%b;
}