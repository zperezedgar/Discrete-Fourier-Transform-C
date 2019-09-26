#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) 
{
	int k, N=20, n, i;	//CAMBIAR el valor de N por el numero de DATOS a usar<--------------------------------------------------!!!!!!
	float angulo, real[N], imaginaria[N];
	//DATOS a usar
	float f[]={975
,975
,975
,975
,625
,342
,218
,231
,315
,408
,465
,474
,441
,384
,319
,263
,225
,210
,213
,230
};
		
	//Convertimos a Volts
	for(i=0; i<N; i++)
	{
		f[i]=f[i]/1000;
	}
	
	
	FILE* archivo;
	archivo=fopen("resultados.txt", "wt");
	
	for(k=0; k<=(N-1); k++)
	{
		real[k]=0;
		imaginaria[k]=0;
		
		for(n=0; n<=(N-1); n++)
		{
			angulo=k*(2*M_PI/N)*n;   //(2*M_PI);
			real[k]=real[k]+f[n]*cos(angulo)/N;
			imaginaria[k]=imaginaria[k]-f[n]*sin(angulo)/N;
		}
	}
	
	printf("Indice\tf(t)\tReal\tImaginaria\n");
	fputs("Indice\tf(t)\tReal\tImaginaria\n", archivo);
	
	i=0;
	for(k=0; k<=(N-1); k++)
	{
		printf("%i\t%.3f\t%.3f\t%.3f\n", i, f[k], real[k], imaginaria[k]);
		fprintf(archivo,"%i\t%.3f\t%.3f\t%.3f\n", i++, f[k], real[k], imaginaria[k]);
	}
	
	////////////////valor absoluto
	printf("\n\nIndice\tf(t)\tReal\tImaginaria\n");
	fputs("\n\nIndice\tf(t)\tReal\tImaginaria\n", archivo);
	
	i=0;
	for(k=0; k<=(N-1); k++)
	{
		printf("%i\t%.3f\t%.3f\t%.3f\n", i, f[k], fabs(real[k]), fabs(imaginaria[k]));
		fprintf(archivo,"%i\t%.3f\t%.3f\t%.3f\n", i++, f[k], fabs(real[k]), fabs(imaginaria[k]));
	}

	fclose(archivo);
	system("PAUSE");

	return 0;
}
