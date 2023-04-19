#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rut[12];
    char nombre[50];
    int entradas_solicitadas;
    int entradas_asignadas;
} Cliente;

int main() {
    int total_entradas = 50;
    int entradas_asignadas = 0;
    int num_clientes = 0;
    Cliente clientes[100];

    FILE *archivo_solicitudes = fopen("clientes.txt", "r");
    if (archivo_solicitudes == NULL) {
        printf("Error al abrir el archivo clientes.txt\n");
        exit(1);
    }

    while (fscanf(archivo_solicitudes, "%[^,],%[^,],%d\n", clientes[num_clientes].rut, clientes[num_clientes].nombre, &clientes[num_clientes].entradas_solicitadas) != EOF) {
        clientes[num_clientes].entradas_asignadas = 0;
        num_clientes++;
    }
    fclose(archivo_solicitudes);

    int entradas_pendientes = total_entradas - entradas_asignadas;
    while (entradas_pendientes > 0) {
        for (int i = 0; i < num_clientes; i++) {
            Cliente *cliente = &clientes[i];
            int entradas_solicitadas = cliente->entradas_solicitadas;

            if (entradas_solicitadas > 2) {
                entradas_solicitadas = 2;
            }

            if (entradas_solicitadas <= entradas_pendientes) {
                cliente->entradas_asignadas += entradas_solicitadas;
                entradas_asignadas += entradas_solicitadas;
                entradas_pendientes -= entradas_solicitadas;
            }
        }
    }

    FILE *archivo_asignadas = fopen("clientes.asg", "w");
    if (archivo_asignadas == NULL) {
        printf("Error al crear el archivo clientes.asg\n");
        exit(1);
    }

    for (int i = 0; i < num_clientes; i++) {
        Cliente *cliente = &clientes[i];
        if (cliente->entradas_asignadas > 0) {
            fprintf(archivo_asignadas, "%s,%s,%d\n", cliente->rut, cliente->nombre, cliente->entradas_asignadas);
        }
    }
    fprintf(archivo_asignadas, "Asignadas: %d\n", entradas_asignadas);
    fprintf(archivo_asignadas, "Pendientes: %d\n", entradas_pendientes);
    fclose(archivo_asignadas);

    int espera = 0;
    for (int i = 0; i < num_clientes; i++) {
        Cliente *cliente = &clientes[i];
        int entradas_pendientes = cliente->entradas_solicitadas - cliente->entradas_asignadas;
        if (entradas_pendientes > 0) {
            espera = 1;
            break;
        }
    }
        if (espera) {
            FILE *archivo_espera = fopen("clientes.esp", "w");
            if (archivo_espera == NULL) {
                printf("Error al crear el archivo clientes.esp\n");
                exit(1);
            }

            for (int i = 0; i < num_clientes; i++) {
                Cliente *cliente = &clientes[i];
                int entradas_pendientes = cliente->entradas_solicitadas - cliente->entradas_asignadas;
                if (entradas_pendientes > 0) {
                    fprintf(archivo_espera, "%s,%s\n", cliente->rut, cliente->nombre);
                }
            }

            fclose(archivo_espera);
        }

        return 0;
    }
