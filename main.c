#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int flagMenu = 0;
	int flagCaseUno = 0;
	int opcion = 0;

	LinkedList *listaPasajeros = ll_newLinkedList();

	do {
		printf(
				"\n------------MENU------------\n"
						"\nIngrese la opcion deseada.\n"
						"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
						"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
						"3. Alta de pasajero\n"
						"4. Modificar datos de pasajero\n"
						"5. Baja de pasajero\n"
						"6. Listar pasajeros\n"
						"7. Ordenar pasajeros\n"
						"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
						"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
						"10. Salir\n\n");
		scanf("%d", &opcion);
		fflush(stdin);

		switch (opcion) {
		case 1:
			if (flagCaseUno == 0) {

				flagCaseUno = 1;
				controller_loadFromText("data.csv", listaPasajeros);
			} else {
				printf("los datos solo pueden ser cargados una vez\n");
			}
			flagMenu = 1;
			break;
		case 2:
			if (flagCaseUno == 0) {

				flagCaseUno = 1;
				controller_loadFromBinary("data.csv", listaPasajeros);
			} else {
				printf(
						"los datos del archivo solo pueden ser cargados una vez\n");
			}
			flagMenu = 1;
			break;
		case 3:
			controller_addPassenger(listaPasajeros);
			flagMenu = 1;
			break;
		case 4:
			if (flagMenu == 0) {
				printf(
						"primero debe ingresar datos en las tres primeras opciones\n");
			} else {

			}
			break;
		case 5:
			if (flagMenu == 0) {
				printf(
						"primero debe ingresar datos en las tres primeras opciones\n");
			} else {

			}
			break;
		case 6:
			if (flagMenu == 0) {
				printf(
						"primero debe ingresar datos en las tres primeras opciones\n");
			} else {
				controller_ListPassenger(listaPasajeros);
			}

			break;
		case 7:
			if (flagMenu == 0) {
				printf(
						"primero debe ingresar datos en las tres primeras opciones\n");
			} else {

			}
			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			printf("\nSaliendo del menu.\n"
					"\n\n\n\tMUCHAS GRACIAS!!!\n"
					"\nSantiago Diez");

			break;

		default:
			printf("opcion no valida\n");
			break;

		}
	} while (opcion != 10);
	return 0;
}

