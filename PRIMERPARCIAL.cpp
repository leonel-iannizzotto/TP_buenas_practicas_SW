#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tanque {
char sector[100];
char nombretanque[100];
int nivel;
};

void cargar_datos(struct tanque **datos, int &cantidad_datos); // doble puntero para poder modificar
void mostrar_todos(struct tanque *datos, int &cantidad_datos);
void dos_menos(struct tanque *datos, int &cantidad_datos);

int main()
{
int opcion;
char sector_temporal[100];
char nombre_temporal[100];
int cantidad_datos=0;
struct tanque *datos;

datos = (struct tanque*)malloc(sizeof(struct tanque)); //tamaño para una estructura como tanque
  printf("SECTOR DEL TANQUE: ");
  scanf("%s", sector_temporal);
  strcpy(datos->sector, sector_temporal);
  printf("%s",datos->sector);
  printf("\n");
  
  printf("NOMBRE DEL TANQUE: ");
  scanf("%s", nombre_temporal);
  strcpy(datos->nombretanque, nombre_temporal);
  printf("%s",datos->nombretanque);
  printf("\n");
  
  do
    {
        printf("NIVEL(1 a 100): ");
        scanf("%d", &datos->nivel);
    }
  while (datos->nivel < 1  || datos->nivel > 100);
  printf("%d\n",datos->nivel);

opcion=1;
	while (opcion!=4)
    {
        printf("\n");
        printf("============== MENU ==============\n");
        printf("1. Cargar Dato\n");
		printf("2. Mostrar datos ingresados\n");
        printf("3. Los 2 tanques que contienen el minimo nivel de agua\n");
        printf("4. Salir\n");
        printf("==================================\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
 switch (opcion)
        {
            case 1:
                cargar_datos(&datos, cantidad_datos); // se pasa la direccion
                break;
            case 2:
				mostrar_todos(datos, cantidad_datos);
                break;
			case 3:
                dos_menos(datos, cantidad_datos);
                break;
            case 4:
                printf("CHAU");
                break;
			default:
                printf("\nOpcion no disponible\n");
		}
	}
	free(datos);
}

void cargar_datos(struct tanque **datos, int &cantidad_datos) // cambio doble puntero
{
char sector_temporal[100];
char nombre_temporal[100];

cantidad_datos++;
printf("%d\n",cantidad_datos);
*datos = (struct tanque*)realloc(*datos,(cantidad_datos+1)*sizeof(struct tanque)); //correccion con realloc
 printf("SECTOR DEL TANQUE: ");
  scanf("%s", sector_temporal);
  strcpy((*datos+cantidad_datos)->sector, sector_temporal); //usamos *datos
  printf("%s",(*datos+cantidad_datos)->sector);
  printf("\n");
  
  printf("NOMBRE DEL TANQUE: ");
  scanf("%s", nombre_temporal);
  strcpy((*datos+cantidad_datos)->nombretanque, nombre_temporal);
  printf("%s",(*datos+cantidad_datos)->nombretanque);
  printf("\n");
  
  do
    {
        printf("NIVEL(1 a 100): ");
        scanf("%d", &(*datos+cantidad_datos)->nivel);
    }
  while ((*datos+cantidad_datos)->nivel < 1 || (*datos+cantidad_datos)->nivel > 100); //aqui
  printf("%d",(*datos+cantidad_datos)->nivel); // corregir condicion



}

void mostrar_todos(struct tanque *datos, int &cantidad_datos)
{
int i;
	for (i=0;i<=cantidad_datos;i++)
	{
		printf("MEDIDA NUMERO: %d\n",i+1);
		printf("SECTOR: %s\n",(datos+i)->sector);
		printf("NOMBRE: %s\n",(datos+i)->nombretanque);
		printf("NIVEL: %d\n", (datos+i)->nivel);
		printf("\n\n");
	}
}

void dos_menos(struct tanque *datos, int &cantidad_datos)
{
int i,k;
struct tanque auxiliar; //variable auxiliar, no es puntero

if (cantidad_datos < 1)
{
    printf("Debe haber al menos 2 tanques.\n");  // agregamos condicion
    return;
}

//primero ordenarlos y despues mostrar los 2 de menor nivel
for (i = 0; i < cantidad_datos - 1; i++)
    {
        for (k = i + 1; k <= cantidad_datos; k++)
        {
            if ((datos+k)->nivel > (datos+i)->nivel)
            {
                auxiliar = *(datos+i);
                *(datos+i) = *(datos+k);
                *(datos+k) = auxiliar; 
            }
        }
    }
	
printf("TANQUES DE MENOR NIVEL \n\n"); //aqui
printf("TANQUE 1:\n");
printf("SECTOR: %s\n", datos[cantidad_datos].sector);
printf("NOMBRE: %s\n", datos[cantidad_datos].nombretanque);
printf("NIVEL: %d\n", datos[cantidad_datos].nivel);

printf("\nTANQUE 2:\n");
printf("SECTOR: %s\n", datos[cantidad_datos-1].sector);
printf("NOMBRE: %s\n", datos[cantidad_datos-1].nombretanque);
printf("NIVEL: %d\n", datos[cantidad_datos-1].nivel);

}
