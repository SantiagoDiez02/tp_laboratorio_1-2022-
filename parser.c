#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#include "string.h"
#include "ctype.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{

	Passenger* nuevo;

	char idNoUsado[50];
	char nombreAux[50];
	char apellidoAux[50];
	char precioAux[50];

	char flycodeAux[50];
	char tipoAux[50];

	char estadoNoUsado[50];

	char validacionApellido[50];

	int idAuxNumero;
	char idAux[6];

	int r;


	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^, ^\n],%[^,],%[^,],%[^,],%[^\n]\n",idNoUsado,nombreAux,apellidoAux,precioAux,flycodeAux,tipoAux,estadoNoUsado);
		if(r==7)
		{

			//      ESTA VALIDACION VA EN CASO DE ELIMINAR LOS CARACTERES ESPECIALES EN LOS APELLIDOS
			sscanf(apellidoAux, "%[a-zA-Z ]", validacionApellido);
			if(strcmp(apellidoAux,validacionApellido) == 0)
			{

				idAuxNumero = Passenger_idDisponible(pArrayListPassenger);
				itoa(idAuxNumero, idAux, 10);

					nuevo = Passenger_newParametros(idAux, nombreAux, apellidoAux, tipoAux, precioAux, flycodeAux);

					if(nuevo != NULL)
					{
						ll_add(pArrayListPassenger, nuevo);
					}
				}
		}

	}while(!feof(pFile));

	fclose(pFile);



    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* nuevo = Passenger_new();
	char lectura[sizeof(Passenger)];
	int cant;

	char idAux[50];
	char nombreAux[50];
	char apellidoAux[50];
	char precioAux[50];

	char flycodeAux[50];
	char tipoAux[50];

	char estadoAux[50];

	char validacionApellido[50];


	while(!feof(pFile))
	{
		cant=fread(&lectura,sizeof(Passenger),1,pFile);

		sscanf(lectura,"%[0-9],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,apellidoAux,precioAux,flycodeAux,tipoAux,estadoAux);

		printf(lectura);
		printf("\n");
		if(cant!=1)
		{
			if(feof(pFile))
			{
				break;
			}
			else
			{
				printf("No leyo el ultimo registro");
				break;
			}
		}
		else
		{
		/*	if(&nuevo != NULL)
			{
				printf("\n");
				printf("%d",nuevo.id);
				printf(" | ");
				printf(nuevo.nombre);
				printf(" %d", nuevo.tipoPasajero);

				ll_add(pArrayListPassenger, &nuevo);
			}

*/
		}
	}


    return 1;
}

