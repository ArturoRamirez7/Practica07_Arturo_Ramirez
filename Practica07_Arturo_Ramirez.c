//Práctica07-FDP																                            		Ramírez Mondragón Arturo Gabriel.
//23 de noviembre del 2020

// Estructura muy general del código:
//Este será un código que calcule el centroide de un cuerpo trimensional irregular y homogéneo
//con forma rectangular constituido por un prisma triangular y de una semiesfera inscritos.

//librerías:
//Dado que no usaremos operaciones o funciones matematicas complejas para este ejemplo usaremos la estándar.
#include<stdio.h>

//variables: Para calcular coordenadas y volúmenes.

//Semiesfera:
float radio, centroEsfera, volumenSemiEsfera, i3, j3, k3;
const double PI=3.141593;
//Prisma trianular:
float largo, ancho, alto, co1, co2, co3, i2, j2, k2, volumenRampa;
//Prisma rectangular:
float largo2, ancho2, alto2, co4, co5, co6, i4, j4, k4, volumenRectangulo;
//Prisma principal:
float volumenP, i, j, k;
//Para la estructuras de selección:
unsigned int bujeros, bujero1, unoBujero;

//función
int main(){
	
	printf("Este programa es unicamente capaz de calcular el centroide de un prisma rectangular homogeneo que \n");
	printf("tiene inscrito un prisma rectangular con forma de rampa y una semiesfera.\n");
	printf("\nPor favor coloca tu sistema de referencia en una de las aristas del prisma. Procura que el prisma");
	printf("\ntenga coordenadas positivas para sus aristas.\n\n");
	printf("\n");
	printf("\n");
	
	//Esfera:
	//Con esta variable se busca calcular su centro.
	printf("Para la semi esfera:\n");
	printf("\nEscriba el radio de la media esfera, por favor: ");
	scanf("%f", &radio);
	
	//El centro está definido por:
	centroEsfera=(3*radio/8);
	printf("Las coordenadas de este centroide estan en el centro de la semiesfera con una elevacion hacia la cupula de: %5.3f", centroEsfera);
	printf("\n\nPerdone. Por favor sume o reste a sus coordenadas -para  algun extremo de la semiesfera- los previos valores.\nEscriba el resultado de las coordenadas: ");
	
	//Lamentablemente no tuve mas que pedirle al usuario realizar la suma dependiendo el sistema de referencia.
	scanf("%g %g %g",  &i3,  &j3,  &k3);
	printf("Estas son las coordenadas del centroide de la semiesfera desde referencia:");
	printf("	i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i3,  j3,  k3);
	volumenSemiEsfera=(2*PI*radio*radio*radio/3);
	printf("\nY su volumen en unidades cubicas es: %.3g\n", volumenSemiEsfera);
	//Fin del primer cálculo.
	
	//Prisma con forma de rampa:
	printf("\n\n\nPara el prisma con forma de rampa:\n");
	printf("\nEscriba de favor las medidas del largo, profundidad y altura, en ese orden, del prisma con forma de rampa?\n");
	scanf("%g %g %g", &largo, &ancho, &alto);
	//Para calcular su centroide:
	co1=largo/3;
	co2=ancho/2;
	co3=alto/3;
	//Terminando esta asignación ocurre un error si el usuario no identifica correctamente la posición y referencia del prisma.
	//Igualmente tuve enormes fallas por depender tanto del usuario y su capacidad para relacionar los lados con su sistema de referencia.
	
	//Nuevamente dependiendo del usuario... :(
	printf("\nSume o reste a las coordenadas del prisma, dependiendo su sistema de referencia, los siguientes valores:\n");
	printf("largo= %-3.4g;		profundidad= %-3.4g;		alto= %-3.4g \n",  co1,  co2,  co3);
	
	//Coordenadas:
	printf("\n\nEscriba las coordenadas resultantes del centroide para el prisma con forma de rampa:\n");
	scanf("%g %g %g",  &i2,  &j2,  &k2);
	printf("\n\nEstas son las coordenadas del centroide de la rampa desde su referencia:");
	printf("	i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i2,  j2,  k2);
	
	//Volumen:
	volumenRampa=(largo*ancho*alto/2);
	printf("\nSu volumen en unidades cubicas es: %.3g\n", volumenRampa);
	//Fin del segundo cálculo.
	
	//Calcularemos el volumen del prisma rectangular principal:
	printf("\n\n\nPara el prisma principal:");
	
	//Para su centroide:
	printf("\n\nEscriba las correspondientes medidas del largo, ancho y alto de la figura:\n");
	scanf("%g %g %g", &largo2, &ancho2, &alto2);
	co4=largo2/2;
	co5=ancho2/2;
	co6=alto2/2;
	
	//Coordenadas:
	printf("\nSume o reste a las coordenadas del prisma, dependiendo su sistema de referencia, las siguientes coordenadas:\n");
	printf("largo= %-3.4g;		ancho= %-3.4g;		alto= %-3.4g \n",  co4,  co5,  co6);
	printf("\n\nEscriba las coordenadas resultantes del centroide para el prisma rectangular:\n");
	scanf("%g %g %g",  &i4,  &j4,  &k4);
	printf("\n\nEstas son las coordenadas del centroide del prisma desde su referencia:");
	printf("	i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i4,  j4,  k4);
	
	//Volumen:
	volumenRectangulo=(largo2*ancho2*alto2);
	printf("\nSu volumen en unidades cubicas es: %.3g\n", volumenRampa);
	//Fin del cálculo para el prisma principal.
	
	
	
	//Calcular el volumen general de la figura:
	printf("\n\n\nProcederemos a calcular el volumen general del prisma rectangular principal.\n\n");
	printf("La figura tiene DOS huecos con la forma de los previos prismas? Seleccione de favor \n Si = 1 \n No = 0\n");
	scanf("%d", &bujeros);
	
	//Si la figura no está completamente rellena:
	if (bujeros==1){
		
		//Para su volumen:
		volumenP=(volumenRectangulo-volumenSemiEsfera-volumenRampa);
		printf("\n\nEl volumen general de la figura es: %g", volumenP);
		
		//Sus coordenadas:
		i=(volumenRectangulo*i4-volumenSemiEsfera*i3-volumenRampa*i2)/volumenP;
		j=(volumenRectangulo*j4-volumenSemiEsfera*j3-volumenRampa*j2)/volumenP;
		k=(volumenRectangulo*k4-volumenSemiEsfera*k3-volumenRampa*k2)/volumenP;
		
		//Fin:
		printf("\n\nPara finalizar:\nLas coordenadas del centroide de la figura principal en sus respectivas unidades son:\n");
		printf("i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i,  j,  k);
	}
	
	//Si la figura está parcialmente completa
	else {
		printf("\n\nTiene un hueco? Seleccione de favor \n Si = 1 \n No = 0\n");
		scanf("%d", &bujero1);
		
		//Con un hueco:
		if (bujero1==1){
			
			printf("\n\nQue forma tiene? Seleccione de favor \n P.triangular = 1 \n Semiesfera = 0\n");
			scanf("%i", &unoBujero);
			
			//Hueco con forma de prisma triangular:
			if (unoBujero=1){
				
				volumenP=(volumenRectangulo+volumenSemiEsfera-volumenRampa);
				printf("\n\nEl volumen general de la figura es: %g", volumenP);
		
				i=(volumenRectangulo*i4+volumenSemiEsfera*i3-volumenRampa*i2)/volumenP;
				j=(volumenRectangulo*j4+volumenSemiEsfera*j3-volumenRampa*j2)/volumenP;
				k=(volumenRectangulo*k4+volumenSemiEsfera*k3-volumenRampa*k2)/volumenP;
		
				printf("\n\nPara finalizar:\nLas coordenadas del centroide de la figura principal en sus respectivas unidades son:\n");
				printf("i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i,  j,  k);			
			}
			
			//Hueco con forma de semiesfera:
			else {
				
				volumenP=(volumenRectangulo-volumenSemiEsfera+volumenRampa);
				printf("\n\nEl volumen general de la figura es: %g", volumenP);
		
				i=(volumenRectangulo*i4-volumenSemiEsfera*i3+volumenRampa*i2)/volumenP;
				j=(volumenRectangulo*j4-volumenSemiEsfera*j3+volumenRampa*j2)/volumenP;
				k=(volumenRectangulo*k4-volumenSemiEsfera*k3+volumenRampa*k2)/volumenP;
		
				printf("\n\nPara finalizar:\nLas coordenadas del centroide de la figura principal en sus respectivas unidades son:\n");
				printf("i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i,  j,  k);
				
			}
		}
		
		//Sin huecos:
		else {
			
			volumenP=(volumenRectangulo+volumenSemiEsfera+volumenRampa);
				printf("\n\nEl volumen general de la figura es: %g", volumenP);
		
				i=(volumenRectangulo*i4+volumenSemiEsfera*i3+volumenRampa*i2)/volumenP;
				j=(volumenRectangulo*j4+volumenSemiEsfera*j3+volumenRampa*j2)/volumenP;
				k=(volumenRectangulo*k4+volumenSemiEsfera*k3+volumenRampa*k2)/volumenP;
		
				printf("\n\nPara finalizar:\nLas coordenadas del centroide de la figura principal en sus respectivas unidades son:\n");
				printf("i= %-3.4g;		j= %-3.4g;		k= %-3.4g \n",  i,  j,  k);
			
		}
	}
	
	return 0;
}
