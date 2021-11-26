/*Tarea 2 - Programa para generar la CURP solicitando los datos al usuario. Se implementan excepciones a los nombres
Jose y Maria, preguntando un segundo nombre
Alumno: Gustavo Alejandro Solorio Ramos
Correo: gustavo.solorio@iteso.mx
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main(void) 
	{
/*========== Declaracion de Arreglos y variables + Mensaje inicial========== */
	const int Tam1=20, Tam2=10, Tam3=2, Tam4=16;
	int longitud1=0, longitud2=0, longitud3=0, longitud4=0, longitud5=0;
	char Nombre1 [Tam1];
	char Nombre2 [Tam1];
	char Apellido1 [Tam1];
	char Apellido2 [Tam1];
	char Nacimiento [Tam2];
	char Genero=0, Consulta=0;
	char Edo [Tam3];
	char CURP[Tam4];
	bool Bandera=0;
	printf("***PROGRAMA PARA GENERAR LA CURP, FAVOR DE SEGUIR PUNTUALMENTE LAS INSTRUCCIONES*** \n");
/*========== Declaracion de Arreglos y variables + Mensaje inicial========== */

/*======================Scan del Primer Nombre===============================================================*/
	    do
	    {
INICIO: printf("\nIngresa tu NOMBRE DE PILA || PRIMER NOMBRE sin acentos, en caso de tener una '%c' sustituir la letra por una X: \n",-92);
	    gets(Nombre1);
	    longitud1= strlen(Nombre1);
	    for(int i=0;i<longitud1;i++)
		    {
		        if (Nombre1[i]>122 || Nombre1[i]<65 || Nombre1[i]==91 || Nombre1[i]==92 || Nombre1[i]==93 || Nombre1[i]==94 || Nombre1[i]==95 || Nombre1[i]==96 || Nombre1[i] == 32 || Nombre1[i] == 13)
	        	{
		            printf("***Favor de introducir un nombre valido*** \n");
		            Bandera=0;
		            break;
	        	}
		        else if(longitud1<3)
	        	{
		            printf("***Favor de introducir un nombre valido*** \n");
		            Bandera=0;
		            break;
	        	}
		        else if(Nombre1[i]>90)
		        {
			        Nombre1[i]-=32;
			        Bandera=1;
		        }
		        
		        else 
		        {
		            Bandera=1;
		        }
		    }
		}while (Bandera==0);
/*=====================================Scan del Primer Nombre===============================================================*/
	    
/*====================== Identificar excepciones & Guardar segundo nombre si es necesario ==================================*/
	    if (strcmp(Nombre1,"JOSE")==0 || strcmp(Nombre1,"MARIA")==0)
	    {
	    	do
			{
		        printf("\nIngresa tu SEGUNDO NOMBRE sin acentos, en caso de tener una '%c' sustituir la letra por una X \nsi tiene un prefijo como 'de' 'mc' 'jr' favor de omitirlo: \n",-92);
		        gets(Nombre2);
		        longitud2= strlen(Nombre2);
	    		for(int i=0;i<longitud2;i++)
	    		{
	        		if (Nombre2[i]>122 || Nombre2[i]<65 || Nombre2[i]==91 || Nombre2[i]==92 || Nombre2[i]==93 || Nombre2[i]==94 || Nombre2[i]==95 || Nombre2[i]==96 || Nombre2[i] == 32 || Nombre2[i] == 13)
	        		{
		           		printf("\n***Favor de introducir un nombre valido*** \n");
		            	Bandera=0;
	  		          	break;
	        		}
	       			else if(longitud2<3)
	        		{
		             	printf("***Favor de introducir un nombre valido*** \n");
		             	Bandera=0;
		             	break;
	        		}
			        else if(Nombre2[i]>90)
			        {
				        Nombre2[i]-=32;
				        Bandera=1;
			        }
	        		else 
	        		{
	            		Bandera=1;
	        		}
	    		}
			}while (Bandera==0);
		}
		
	    else 
	    {
	    for(int i=0;i<strlen(Nombre2);i++)
	    	{
	    		Nombre2[i]=0; /*Borra el segundo nombre en caso de existir*/
			}
	    }
/*============================ Identificar excepciones & Guardar segundo nombre si es necesario =================================*/
	
/*===================================== Scan del Apellido Paterno ===============================================================*/
		do
	    {
		printf("\nIngresa tu APELLIDO PATERNO sin acentos, en caso de tener una '%c' sustituir la letra por una X: \n",-92);
	    gets(Apellido1);
	    longitud3= strlen(Apellido1);
	    for(int i=0;i<longitud3;i++)
	    {
	        if (Apellido1[i]>122 || Apellido1[i]<65 || Apellido1[i]==91 || Apellido1[i]==92 || Apellido1[i]==93 || Apellido1[i]==94 || Apellido1[i]==95 || Apellido1[i]==96 || Apellido1[i] == 32 || Apellido1[i] == 13)
	        {
	            printf("\n***Favor de introducir un apellido valido***\n");
	            Bandera=0;
	            break;
	        }
	        else if(longitud3<3)
	        {
	             printf("\n***Favor de introducir un apellido valido***\n");
	             Bandera=0;
	             break;
	        }
	        
	        else if(Apellido1[i]>90)
	        {
	                Apellido1[i]-=32;
	                Bandera=1;
	        }
	        
	        else 
	        {
	            Bandera=1;
	        }
	    }
		}while (Bandera==0);
/*===================================== Scan del Apellido Paterno ===============================================================*/	
		
/*===================================== Scan del Apellido Materno ===============================================================*/	
	    do
	    {
			printf("\nIngresa tu APELLIDO MATERNO sin acentos, en caso de tener una '%c' sustituir la letra por una X: \n",-92);
		    gets(Apellido2);
		    longitud4= strlen(Apellido2);
		    for(int i=0;i<longitud4;i++)
	   		{
	        	if (Apellido2[i]>122 || Apellido2[i]<65 || Apellido2[i]==91 || Apellido2[i]==92 || Apellido2[i]==93 || Apellido2[i]==94 || Apellido2[i]==95 || Apellido2[i]==96 || Apellido2[i] == 32 || Apellido2[i] == 13)
	        	{
		            printf("\n***Favor de introducir un nombre valido***\n");
		            Bandera=0;
		            break;
	        	}
	        else if(longitud4<3)
		        {
		            printf("\n***Favor de introducir un nombre valido***\n");
		            Bandera=0;
		            break;
		        }
	        else if(Apellido2[i]>90)
	       		{
	                Apellido2[i]-=32;
	                Bandera=1;
	        	}
	        else 
		        {
		            Bandera=1;
		        }
	    	}
		}while (Bandera==0);
/*===================================== Scan del Apellido Materno ===============================================================*/	
	
/*===================================== Scan de la fecha de Nacimiento ===============================================================*/	
		do
		{
			printf("\nIngresa tu Fecha de nacimiento en formato DD/MM/AAAA: \n");
			gets(Nacimiento);
			for(int i=0;i<10;i++)
		    {
		        if (Nacimiento[i]>58 || Nacimiento[i]<47) /*Solo acepta números o '/' */
		        {
		            printf("\n***Favor de introducir una fecha valida***\n");
		            Bandera=0;
		            break;
		        }  
		        else if (Nacimiento[2]!='/' || Nacimiento[5]!='/')
		        {
		            printf("\n***Favor de introducir una fecha valida***\n"); /*Evalua que este en el formato que se pide, o la vuelve a pedir*/
		            Bandera=0;
		            break;
		        }
		        else 
		        {
		            Bandera=1;
		        }
		    }
		}while (Bandera==0);
/*===================================== Scan de la fecha de Nacimiento ===============================================================*/	
	Bandera=0;
/*============================================ Scan del Genero / Sexo  ===============================================================*/	
		do
		{
			printf("\nFavor de indicar su Genero / Sexo con una 'H' para Hombre o 'M' para Mujer: \n");
			scanf("%c",&Genero);
			scanf("%c");
			if(Genero == 'H' || Genero =='M')
				{
					Bandera=1;	
				}
			else
				{
					printf("\n***Genero no existente*** \n");
					Bandera=0;
				}
		}while (Bandera==0);
/*============================================ Scan del Genero / Sexo  ===============================================================*/
	Bandera=0;
	
/*============================================ Scan del Estado de Nacimiento  ========================================================*/
		do
		{
			printf("\nIndique las iniciales 'XX' correspondiente a su Estado de Nacimiento\n");
			printf("AS - Aguascalientes      ");
			printf("|| BC - Baja California     \n");
			printf("BS - Baja California Sur ");
			printf("|| CC - Campeche            \n");
			printf("CL - Coahuila            ");
			printf("|| CM - Colima              \n");
			printf("CS - Chiapas             ");
			printf("|| CH - Chihuahua           \n");
			printf("DF - Ciudad de Mexico    ");
			printf("|| DG - Durango             \n");
			printf("GT - Guanajuato          ");
			printf("|| GR - Guerrero            \n");
			printf("HG - Hidalgo             ");
			printf("|| JC - Jalisco             \n");
			printf("MC - Estado de Mexico    ");
			printf("|| MN - Michoacan de Ocampo \n");
			printf("MS - Morelos             ");
			printf("|| NT - Nayarit             \n");
			printf("NL - Nuevo Leon          ");
			printf("|| OC - Oaxaca              \n");
			printf("PL - Puebla              ");
			printf("|| QT - Querétaro           \n");
			printf("QR - Quintana Roo        ");
			printf("|| SP - San Luis Potosi     \n");
			printf("SL - Sinaloa             ");
			printf("|| SR - Sonora              \n");
			printf("TC - Tabasco             ");
			printf("|| TS - Tamaulipas          \n");
			printf("TL - Tlaxcala            ");
			printf("|| VZ - Veracruz            \n");
			printf("YN - Yucatan             ");
			printf("|| ZS - Zacatecas           \n");
			printf("NE - Nacido en el Extranjero \n");
			printf("Respuesta: ");
/*Imprime una Tabla con las opciones, adelante solo permite 2 caractreres en mayúscula o la vuelve a generar*/
			gets(Edo);
			longitud5= strlen(Edo);
			if(longitud5>2)
			{
				printf("\n***Introduce un estado valido\n***");
				Bandera=0;
			}
			else
			{
			
			for(int i=0;i<2;i++)
				{
					if(Edo[i] <=64 || Edo[i] >90)
					{
					Bandera=0;
					printf("\n***Intenta de nuevo***\n");
					break;
					}
					else
					Bandera=1;
				}
			}
		}while(Bandera==0);
/*============================================ Scan del Estado de Nacimiento  ========================================================*/
		
/*Ya que se guaradaron los datos y se comprobo que esten en el formato correcto, se procede a generar la curp*/

/*============================================ Generar la CURP  ========================================================*/
	Bandera=0;
	CURP[0]=Apellido1[0]; /*Guarda el primer caracter del Apellido Paterno*/
	for(int i=1;i<longitud3;i++)
	{
		if(Apellido1[i] == 'A' || Apellido1[i] == 'E' || Apellido1[i] == 'I' || Apellido1[i] == 'O' || Apellido1[i] == 'U') 
		{
			CURP[1]=Apellido1[i]; /* ^ Busca la primer Vocal del Apellido Paterno*/
			Bandera=1;
			break;
		}
		else
		{
		}
	}
	CURP [2]=Apellido2[0]; /*Guarda el primer caracter del Apellido Materno*/
	if (strcmp(Nombre1,"JOSE")==0 || strcmp(Nombre1,"MARIA")==0) /*Identifica Nombres comunes, de ser asi se extraen los datos del 2o nombre*/
	{
		CURP[3]=Nombre2[0];  /*Primer caracter del Nombre valido para esta excepcion*/
		for(int i=1;i<longitud2;i++)
		{
			if(Nombre2[i] == 'A' || Nombre2[i] == 'E' || Nombre2[i] == 'I' || Nombre2[i] == 'O' || Nombre2[i] == 'U')
			{
			}
			else
			{
			CURP[15]=Nombre2[i]; /*Consonante del Nombre valido para esta excepcion*/
			break;
			}
		}
	}
	else
	{
		CURP[3]=Nombre1[0]; /*Primer caracter del Nombre de Pila si es que aplica*/
		for(int i=1;i<longitud1;i++)
		{
			if(Nombre1[i] == 'A' || Nombre1[i] == 'E' || Nombre1[i] == 'I' || Nombre1[i] == 'O' || Nombre1[i] == 'U')
			{
			}
			else
			{
			CURP[15]=Nombre1[i]; /*Consonante del Nombre de Pila si es que aplica*/
			break;
			}
		}
	}
/*Guarda los caracteres correspondienes a la fecha de nacimiento, el genero y el estado segun la posicion que les corresponde*/
	CURP[4]=Nacimiento[8];
	CURP[5]=Nacimiento[9];
	CURP[6]=Nacimiento[3];
	CURP[7]=Nacimiento[4];
	CURP[8]=Nacimiento[0];
	CURP[9]=Nacimiento[1];
	CURP[10]=Genero;
	CURP[11]=Edo[0];
	CURP[12]=Edo[1];
	for(int i=1;i<longitud3;i++)
	{
		if(Apellido1[i] == 'A'|| Apellido1[i] == 'E' || Apellido1[i] == 'I' || Apellido1[i] == 'O' || Apellido1[i] == 'U')
		{
		}
		else
		{
			CURP[13]=Apellido1[i]; /*Consonante interna del Apellido Paterno*/
			break;
		}
	}
	for(int i=1;i<longitud4;i++)
	{
		if(Apellido2[i] == 'A' || Apellido2[i] == 'E' || Apellido2[i] == 'I' || Apellido2[i] == 'O' || Apellido2[i] == 'U')
		{
		}
		else
		{
			CURP[14]=Apellido2[i]; /*Consonante interna del Apellido Materno*/
			break;
		}
	}
/*============================================ Generar la CURP  ========================================================*/
	
/*Validacion de datos;
		printf("Nombre completo: %s %s %s %s \n",Nombre1,Nombre2,Apellido1,Apellido2);
		printf("Fecha de Nacimiento: %s\n", Nacimiento);
		printf("Genero: %c\n",Genero);
		printf("Estado: %s\n",Edo);
/Validacion de datos*/
	printf("\nSu CURP es: \n");
	for(int i=0;i<16;i++)
	{
		printf("%c",CURP[i]); /* Imprime los 16 digitos de la curp sin homoclave*/
	}
	printf("\n");
	printf("\n¿Desea hacer Otra consulta? (Y/n) \n"); /* Si el usuario requiere otra consulta, lo permite*/
		scanf("%c",&Consulta);
		scanf("%c");
		if(Consulta == 'Y' || Consulta == 'y' )
		{
			goto INICIO; /*Regresa al inicio*/
		}
		else /* Termina el programa*/
		{
		}
	}