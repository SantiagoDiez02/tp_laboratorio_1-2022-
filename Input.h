

#ifndef INPUT_H_
#define INPUT_H_

void pedirEntero(int* variableRecibida, char textoAMostrar[]);
void pedirFlotante(float* variableRecibida, char textoAMostrar[]);
void pedirCadena(char arrayRecibido[], char textoAMostrar[]);
int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int cadenaValidada(char arrayRecibido[], char textoAMostrar[]);

#endif /* INPUT_H_ */
