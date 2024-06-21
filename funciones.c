#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
char tipo[40];
printf("Ingrese el tamaño de habitación que desea buscar, simple doble o triple(en caso de escribir mal reinicie el programa): ");
scanf("%s", tipo);

printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
for (int i = 0; i < 9; i++) {
    if (strcmp(habitaciones[i][1], tipo) == 0) {
        printf("%s\t\t%s\t\t%s\t\t%lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
    }
}

printf("Elija la habitación que desea reservar: ");
}

void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
char hotel[40];
printf("Ingrese el nombre del hotel que desea buscar (Dan_Carlton,Swissotel,Sheraton): () ");
scanf("%s", hotel);

printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
for (int i = 0; i < 9; i++) {
    if (strcmp(habitaciones[i][2], hotel) == 0) {
        printf("%s\t\t%s\t\t%s\t\t%lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
    }
}

printf("Elija la habitación que desea reservar: ");
scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
int numCliente = -1;
for (int i = 0; i < 5; i++) {
if (strcmp(clientes[i][0], "") == 0) {
numCliente = i;
break;
}
}

if (numCliente == -1) {
    printf("No hay espacio para más clientes.\n");
    return;
}

printf("Ingrese el nombre del cliente: ");
scanf("%s", clientes[numCliente][0]);
printf("Ingrese la cédula del cliente: ");
scanf("%s", clientes[numCliente][1]);

int numReserva = -1;
for (int i = 0; i < 10; i++) {
    if (reservas[i][0] == -1) {
        numReserva = i;
        break;
    }
}

if (numReserva == -1) {
    printf("No hay espacio para más reservas.\n");
    return;
}

reservas[numReserva][0] = numCliente;
reservas[numReserva][1] = numHabitacion - 1;
printf("Ingrese la cantidad de días de la reserva: ");
scanf("%d", &reservas[numReserva][2]);
reservas[numReserva][3] = 0;

printf("Reserva realizada con éxito.\n");
}

void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
char cedula[40];
printf("Ingrese la cédula del cliente: ");
scanf("%s", cedula);

int numCliente = -1;
for (int i = 0; i < 5; i++) {
    if (strcmp(clientes[i][1], cedula) == 0) {
        numCliente = i;
        break;
    }
}

if (numCliente == -1) {
    printf("No se encontró ningún cliente con la cédula proporcionada.\n");
    return;
}

for (int i = 0; i < 10; i++) {
    if (reservas[i][0] == numCliente) {
        *numReserva = i;
        return;
    }
}

printf("No se encontró ninguna reserva para el cliente con la cédula proporcionada.\n");
}

void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
if (numReserva == -1) {
printf("Número de reserva inválido.\n");
return;
}

int numHabitacion = reservas[numReserva][1];
int numCliente = reservas[numReserva][0];
int dias = reservas[numReserva][2];
double precio = precios[numHabitacion] * dias;

printf("Detalles de la reserva:\n");
printf("Cliente: %d\n", numCliente);
printf("Habitación: %s\n", habitaciones[numHabitacion][0]);
printf("Tamaño: %s\n", habitaciones[numHabitacion][1]);
printf("Hotel: %s\n", habitaciones[numHabitacion][2]);
printf("Días: %d\n", dias);
printf("Precio total: %lf\n", precio);
printf("Estado: %s\n", reservas[numReserva][3] == 0 ? "Pendiente" : "Pagado");
}

void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
if (numReserva == -1) {
printf("Número de reserva inválido.\n");
return;
}

if (reservas[numReserva][3] == 1) {
    printf("La reserva ya ha sido pagada.\n");
    return;
}

int numHabitacion = reservas[numReserva][1];
int dias = reservas[numReserva][2];
double precio = precios[numHabitacion] * dias;

printf("Precio total a pagar: %lf\n", precio);
reservas[numReserva][3] = 1;
printf("Pago realizado con éxito.\n");
}