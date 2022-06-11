#include "LinkedList.h"
#include "Passenger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int Passenger_setId(Passenger *this, int id) {
	this->id = id;
	if (this->id != id) {

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
int Passenger_getEstadoDeVuelo(Passenger *this, char *estadoDeVuelo) {
	strcpy(estadoDeVuelo, this->estadoDeVuelo);
	if (!(strcmp(estadoDeVuelo, this->estadoDeVuelo))) {
		return 1;
	}
	return 0;
}

int Passenger_setEstadoDeVuelo(Passenger *this, char *estadoDeVuelo) {

	if (this != NULL && estadoDeVuelo != NULL) {
		strcpy(this->estadoDeVuelo, estadoDeVuelo);
		return 0;
	}

	printf("\n no codigo");
	return 1;
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
		char *flycodeStr, char *estadoDeVuelo) {
	Passenger *nuevoPasajero = Passenger_new();
	int idAux;
	int tipoAux;
	float precioAux;

	idAux = atoi(idStr);
	tipoAux = strcmp(tipoPasajeroStr, "ExecutiveClass");

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
								validacion++;
								if (Passenger_setEstadoDeVuelo(nuevoPasajero,
										estadoDeVuelo) == 0) {
									validacion++;
								}
							}
						}
					}
				}
			}

			if (validacion != 7) {
				free(nuevoPasajero);
				nuevoPasajero = NULL;
			}
		}

	}
	return nuevoPasajero;
}

//-----------------------------------------------------//
int Passenger_listEntera(LinkedList *pArrayListPassenger) {
	Node *indice = pArrayListPassenger->pFirstNode;
	Passenger *leer;

	printf(
			"\nID:  || apellido y nombre: || Precio: \t|| Tipo De Pasajero:   || Codigo De Vuelo: \n");
	for (; indice != NULL; indice = indice->pNextNode) {
		leer = indice->pElement;
		Passenger_listaUno(leer);

	}
	printf(
			"\n-----------------------------------------------------------------------\n");
	return 1;
}

int Passenger_idDisponible(LinkedList *pArrayListPassenger) {
	Node *indice = pArrayListPassenger->pFirstNode;
	Passenger *ultimo;
	int devolver = 0;

	if (ll_len(pArrayListPassenger) == 0) {
		devolver = 1;
	} else {
		for (; indice != NULL; indice = indice->pNextNode) {
			ultimo = indice->pElement;
		}
		devolver = ultimo->id + 1;
	}

	return devolver;
}
void* Passenger_busqueda(LinkedList *pArrayListPassenger, int idABuscar) {
	Node *indice = pArrayListPassenger->pFirstNode;

	Passenger *idBuscada;

	for (idBuscada = indice->pElement;
			idBuscada->id != idABuscar && idBuscada != NULL;
			indice = indice->pNextNode) {
		idBuscada = indice->pElement;
	}
	if (idBuscada->id != idABuscar) {
		idBuscada = NULL;
		printf("ERROR");
	}
	return idBuscada;
}
void Passenger_listaUno(Passenger *lecturaDeDato) {
	char tipoPasajeroAux[15];
	if (lecturaDeDato != NULL) {
		switch (lecturaDeDato->tipoPasajero) {
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

		printf("%d  ||  ", lecturaDeDato->id);
		printf(lecturaDeDato->apellido);
		printf(" ");
		printf(lecturaDeDato->nombre);
		printf("  ||  ");
		printf("%.2f", lecturaDeDato->precio);
		printf("  ||  ");
		printf(tipoPasajeroAux);
		printf("  ||  ");
		printf(lecturaDeDato->codigoVuelo);
		printf("  ||  ");
		printf(lecturaDeDato->estadoDeVuelo);
		printf("\n");
	}

}

