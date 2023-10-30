#include <windows.h> //Biblioteca para funcion sleep()
#include <process.h> //Biblioteca para la funcion _beginthread
#include <time.h> //Biblioteca para las funciones del reloj
#include <stdio.h> //Biblioteca para la funcion getchar()

void task1(void*);

int main (int, char**)
{
	//variable requerida para la funcion _beginthread
	int ThreadNr;
	
	//coloca la cantidad de nucleos de tu equipo
	//puedes jugar con valores altos como 10 o 20 y veras que tu equipo ocupa al 100% del CPU 
	int nucleos = 45;
	
	//se realiza el separado por hilos de ejcución por número de nucleos
	for(int i=0; i < nucleos; i++) _beginthread( task1, 0, &ThreadNr );
	
	//Escribe cualquier tecla para terminar
	(void) getchar();
	return 0;
	}
	
	void task1(void *)
	{ 
	//ciclo infinito para utlizar el procesador
	//Termina el programa presionando la recla Enter
	while(1)
	{
		//Obtenemos el reloj actual + 50
		clock_t wakeup = clock() + 50;
		
		//Hacemos 50 ticks de reloj que ocupa uso de CPU
		while (clock() < wakeup) {}
		
		//Despues de 50 ticks, dormimos 50 milisegundos para darle un respiro al procesador 
		// y no trabar al equipo
		Sleep(50);
	}
	}
	
	
