#include "LinkedList.h"
#include "Passenger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int Passenger_setId(Passenger *this, int id) {
	this->id = id;
	if (this->id != id) {
		printf("\n No id");
		return 1;
	}
	return 0;
}
int Passenger_getId(Passenger *this, int *id) {
	*id = this->id;
	if (*id != this->id) {
		return 1;
	}
	return 0;
}

int Passenger_setNombre(Passenger *this, char *nombre) {
	if (nombre != NULL && this != NULL) {
		strcpy(this->nombre, nombre);
		return 0;
	}
	printf("\n no nombre");
	return 1;

}
int Passenger_getNombre(Passenger *this, char *nombre) {
	strcpy(nombre, this->nombre);
	if (!(strcmp(nombre, this->nombre))) {

		return 1;
	}
	return 0;
}

int Passenger_setApellido(Passenger *this, char *apellido) {
	if (this != NULL && apellido != NULL) {
		strcpy(this->apellido, apellido);
		return 0;
	}

	printf("\n no apellido");
	return 1;
}
int Passenger_getApellido(Passenger *this, char *apellido) {
	strcpy(apellido, this->apellido);
	if (!(strcmp(apellido, this->apellido))) {
		return 1;
	}
	return 0;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		return 0;
	}

	printf("\n no codigo");
	return 1;
}
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	strcpy(codigoVuelo, this->codigoVuelo);
	if (!(strcmp(codigoVuelo, this->codigoVuelo))) {
		return 1;
	}
	return 0;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	this->tipoPasajero = tipoPasajero;
	if (this->tipoPasajero != tipoPasajero) {
		printf("\n no tipo");
		return 1;
	}
	return 0;
}
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	*tipoPasajero = this->tipoPasajero;
	if (*tipoPasajero != this->tipoPasajero) {
		return 1;
	}
	return 0;
}

int Passenger_setPrecio(Passenger *this, float precio) {
	this->precio = precio;
	if (this->precio != precio) {
		printf("\n no precio");
		return 1;
	}
	return 0;
}
int Passenger_getPrecio(Passenger *this, float *precio) {
	*precio = this->precio;
	if (*precio != this->precio) {
		return 1;
	}
	return 0;
}

Passenger* Passenger_new() {
	Passenger *nuevoPasajero = NULL;
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	if (nuevoPasajero != NULL) {
		nuevoPasajero->id = 0;
		strcpy(nuevoPasajero->nombre, " ");
		strcpy(nuevoPasajero->apellido, " ");
		nuevoPasajero->tipoPasajero = 0;
		nuevoPasajero->precio = 0;
		strcpy(nuevoPasajero->codigoVuelo, " ");
	}

	return nuevoPasajero;

}

Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *tipoPasajeroStr, char *precioStr,
		char *flycodeStr) {
	Passenger *nuevoPasajero = Passenger_new();
	int idAux;
	int tipoAux;
	float precioAux;

	idAux = atoi(idStr);
	tipoAux = strcmp(tipoPasajeroStr, "ExecutiveClass");
	//-1 para economica, 0 para ejecutiva, 1 para primera
	precioAux = atof(precioStr);

	int validacion = 0;

	if (nuevoPasajero != NULL) {
		if (Passenger_setId(nuevoPasajero, idAux) == 0) {
			validacion++;
			if (Passenger_setNombre(nuevoPasajero, nombreStr) == 0) {
				validacion++;
				if (Passenger_setApellido(nuevoPasajero, apellidoStr) == 0) {
					validacion++;
					if (Passenger_setTipoPasajero(nuevoPasajero, tipoAux)
							== 0) {
						validacion++;
						if (Passenger_setPrecio(nuevoPasajero, precioAux)
								== 0) {
							validacion++;
							if (Passenger_setCodigoVuelo(nuevoPasajero,
									flycodeStr) == 0) {
								nuevoPasajero->isEmpty = 5;
								validacion++;
							}
						}
					}
				}
			}
		}

		if (validacion != 6) {
			free(nuevoPasajero);
			nuevoPasajero = NULL;
		}
	}

	return nuevoPasajero;

}

//-----------------------------------------------------//
int Passenger_list(LinkedList *pArrayListPassenger) {
	Node *indice = pArrayListPassenger->pFirstNode;
	Passenger *leer;
	char tipoPasajeroAux[15];

	printf(
			"\nID:  || Nombre y Apellido: || Precio: \t|| Tipo De Pasajero:   || Codigo De Vuelo: \n");
	for (; indice != NULL; indice = indice->pNextNode) {
		leer = indice->pElement;

		switch (leer->tipoPasajero) {
		case -1:
			strcpy(tipoPasajeroAux, "EconomyClass");
			break;
		case 0:
			strcpy(tipoPasajeroAux, "ExecutiveClass");
			break;
		case 1:
			strcpy(tipoPasajeroAux, "FirstClass");
			break;
		}
		if (leer->id != 0) {
			printf("%d   ||   ", leer->id);

			printf(leer->nombre);
			printf(" ");
			printf(leer->apellido);
			printf("  ||  ");
			printf("%.2f", leer->precio);
			printf("\t||\t");
			printf(tipoPasajeroAux);
			printf("\t||\t");
			printf(leer->codigoVuelo);
			printf("\n\n");
		}
	}
	printf(
			"\n-----------------------------------------------------------------------\n");
	return 1;
}

int Passenger_idDisponible(LinkedList *pArrayListPassenger) {
	int devolver = ll_len(pArrayListPassenger);

	return devolver;
}

