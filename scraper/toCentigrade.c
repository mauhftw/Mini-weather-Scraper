#include "functions.h"

float toCentigrade(char* temp) {
	
	int aux;
	float result;

	aux = atoi(temp);	
	result = (aux - 32) * 0.55;  /*F° to C°*/
	return result;


}