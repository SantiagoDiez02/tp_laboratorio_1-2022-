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
	int flagGuardar = 0;

	int opcion = 0;

	int contadorIdsAlta = 0;
	int validacionDeReturns;

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
				if (controller_contadorIds(listaPasajeros, contadorIdsAlta)
						== 0) {
					printf("se generaron nuevos IDs");

				}
			} else {
				printf("los datos solo pueden ser cargados una vez\n");
			}
			flagMenu = 1;
			break;
		case 2:
			if (flagCaseUno == 0) {

				flagCaseUno = 1;
				controller_loadFromBinary("data.bin", listaPasajeros);

				if (controller_contadorIds(listaPasajeros, contadorIdsAlta)
						== 0) {
					printf("se generaron nuevos IDs");
				}
			} else {
				printf(
						"los datos del archivo solo pueden ser cargados una vez\n");
			}
			flagMenu = 1;
			break;
		case 3:
			if (controller_addPassenger(listaPasajeros) != 1) {
				printf("Hubo un error al cargar el pasajero");
			} else {
				contadorIdsAlta++;
				flagMenu = 1;
			}
			break;
		case 4:
			if (flagMenu == 0) {
				printf(
						"primero debe ingresar datos en las tres primeras opciones\n");
			} else {
				validacionDeReturns = controller_editPassenger(listaPasajeros);
				if (validacionDeReturns == 1) {
					printf("se modifico correctamente");
				} else {
					printf("hubo un fallo en la modificacion");
				}
			}
			break;
		case 5:
			if (flagMenu == 0) {
				printf(
						"primero debe ingresar datos en las tres primeras opciones\n");
			} else {
				validacionDeReturns = controller_removePassenger(
						listaPasajeros);
				if (validacionDeReturns == 1) {
					printf("se elimino correctamente");
				} else {
					printf("hubo un fallo en la eliminacion");
				}
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
				validacionDeReturns = controller_sortPassenger(listaPasajeros);
				if (validacionDeReturns == 1) {
					printf("se ordeno correctamente");
				} else {
					printf("se ordeno correctamente");
				}
			}
			break;
		case 8:
			validacionDeReturns = controller_saveAsText("dataNuevo.csv",
					listaPasajeros);
			if (validacionDeReturns == 1) {
				printf("\nse guardo correctamente.\n");
				flagGuardar = 1;
			} else {
				printf("\nNo se puedo abrir el archivo.\n");
			}

			break;
		case 9:
			validacionDeReturns = controller_saveAsBinary("data.bin",
					listaPasajeros);
			if (validacionDeReturns == 1) {
				printf("\nse guardo correctamente.\n");
				flagGuardar = 1;
			} else {
				printf("\nNo se puedo abrir el archivo.\n");
			}
			break;
		case 10:
			if (flagGuardar == 0) {
				printf(
						"\nno cierre el programa si antes no guardo los datos, o los perdera PARA SIEMPRE.\n");
			} else {
				printf("\nSaliendo del menu.\n"
						"\n\n\tMUCHAS GRACIAS!!!\n"
						"\nSantiago Diez");
			}
			break;
		default:
			printf("opcion no valida\n");
			break;

		}
	} while (opcion != 10 || flagGuardar != 1);
	return 0;
}

