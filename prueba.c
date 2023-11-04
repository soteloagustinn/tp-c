#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <cstdlib>
#include <time.h>

//Definicion de registro Lista
struct Lista {
    char partido[30];
    int cantVotos;
};

struct Lista votos[4];

//registro de votantes
struct voto{
    int DNI;
    struct voto *prox;
};

//Procedimiento ordenar arreglo
void ordenar_Arreglo(struct Lista votos[]){
    for(int p = 1; p <=4; p++){
        for(int i = 0; i < 3 - p; i++){
            if(votos[i].cantVotos < votos[i + 1].cantVotos){
                struct Lista aux = votos[i];
                votos[i] = votos[i + 1];
                votos[i + 1] = aux;
            }
        }
    }
    
}

//Procedimiento Mostrar Listas
void Ver_Listas(int Dia, int Mes, int Anio){
    system("cls");
    printf("\n");
    printf("                                     LISTAS DE LOS PATIDOS: \n");
    printf("\n");
    printf("         ___________________________________         ___________________________________ \n");
    printf("        |               |                   |       |               |                   |\n");
    printf("        | Lista: Nro 1  |  Fecha: %d/%d/%d   |", Dia, Mes, Anio);
    printf("       | Lista: Nro 2  |  Fecha: %d/%d/%d   |", Dia, Mes, Anio);
    printf("\n");
    printf("        |_______________|___________________|       |_______________|___________________|\n");
    printf("        |                                   |       |                                   |\n");
    printf("        |             PARTIDO:              |       |             PARTIDO:              |\n");
    printf("        |         CELESTE Y BLANCA          |       |      LOS FUTUROS GRADUADOS        |\n");
    printf("        |___________________________________|       |___________________________________|\n");
    printf("        |                                   |       |                                   |\n");
    printf("        |          CANDIDATO/OS:            |       |          CANDIDATO/OS:            |\n");
    printf("        |           Candidato 1             |       |           Candidato 2             |\n");
    printf("        |___________________________________|       |___________________________________|\n");
    printf("\n");
    printf("\n");
    printf("         ___________________________________         ___________________________________ \n");
    printf("        |               |                   |       |               |                   |\n");
    printf("        | Lista: Nro 3  |  Fecha: %d/%d/%d   |", Dia, Mes, Anio);
    printf("       | Lista: Nro 4  |  Fecha: %d/%d/%d   |", Dia, Mes, Anio);
    printf("\n");
    printf("        |_______________|___________________|       |_______________|___________________|\n");
    printf("        |                                   |       |                                   |\n");
    printf("        |             PARTIDO:              |       |             PARTIDO:              |\n");
    printf("        |         LOS RECURSANTES           |       |        ACCION ESTUDIANTIL         |\n");
    printf("        |___________________________________|       |___________________________________|\n");
    printf("        |                                   |       |                                   |\n");
    printf("        |          CANDIDATO/OS:            |       |          CANDIDATO/OS:            |\n");
    printf("        |           Candidato 3             |       |           Candidato 4             |\n");
    printf("        |___________________________________|       |___________________________________|\n");
    printf("\n");
    system("pause");
}

//Crear nodo
struct voto *nuevo(int dni){
    struct voto *a;
    a = malloc(sizeof(struct voto));
    a->DNI = dni;
    a->prox = NULL;
    return a;
}

//registrar votantes
void Registrar_Votos(struct voto *prim,struct voto *p1, struct voto *q){
    int DNIE;
    printf("Ingrese su DNI\n");
    scanf("%d", &DNIE);
    if (prim != NULL) {
        p1 = prim;
        while ((p1->prox != NULL)&&(DNIE != p1->DNI)){
            p1 = p1->prox;
        }
        if (DNIE == p1->DNI){
            printf("Usted ya ha votado!");
        } else {
            q = nuevo(DNIE);
            p1->prox = q;
            Votar();
        }
    }else{
        q = nuevo(DNIE);
        prim=q;
        Votar(); 
    }
}



//Procedimiento Votar
void Votar(struct Lista votos[]){
    int i;
    int numCandidatos = sizeof(votos) / sizeof(votos[0]);
    printf("Ingrese un candidato");
    readln(i);
    if(i >=0 && i < numCandidatos){
        votos[i].cantVotos++;
        printf("¡Su voto por %s ha sido registrado!\n", votos[i].partido);
    }else{
        printf("Candidato no válida.\n");
    }
    
}

void Borrar_Votantes(struct voto** Prim) {
    struct voto* p1 = *Prim;
    struct voto* q;

    if (p1 == NULL) {
        printf("Ningún votante fue a votar.\n");
    } else {
        while (p1 != NULL) {
            q = p1;
            p1 = p1->prox;
            free(q); // Liberar memoria del nodo actual
        }
        *Prim = NULL; // Establecer el puntero al inicio de la lista como NULL
    }
}

//Procedimiento Ranking de Votos
void Ranking_Votos(){
    system("cls");
    printf("\n");
    printf("     Las votaciones ya han finalizado. El ranking de votos quedo de la siguiente forma: \n");
    printf("\n");
    printf("       ___________________________________________________________________________ \n");
    printf("      |                                                                           |\n");
    printf("      |                             RANKING DE VOTOS                              |\n");
    printf("      |___________________________________________________________________________|\n");
    printf("      |                                                                           |\n");
    printf("      |  1ro %30c          ",votos[1].partido[30]);
	printf(" Nro de votos:  %8d     |",votos[1].cantVotos);
    printf("\n");
    printf("      |  2do %30c          ",votos[2].partido[30]);
	printf(" Nro de votos:  %8d     |",votos[2].cantVotos);
    printf("\n");
	printf("      |  3ro %30c          ",votos[3].partido[30]);
	printf(" Nro de votos:  %8d     |",votos[3].cantVotos);
    printf("\n");
	printf("      |  4to %30c          ",votos[4].partido[30]);
	printf(" Nro de votos:  %8d     |",votos[4].cantVotos);
    printf("\n");
	printf("      |___________________________________________________________________________|\n");
    printf("\n");
    system("pause");
    exit(0);
}

int main() {
    
    //punteros
    struct voto *p1;
    struct voto *q;
    struct voto *prim;
    prim = NULL;
     
    int Dia,Mes,Anio,hora,Opcion,i,j,aux;
    
    //Ingresar fecha actual
    printf("\n");
    printf("Ingrese la fecha actual en formato DD/MM/AA: \n");
    scanf("%d %d %d\n",&Dia,&Mes,&Anio);
    printf("\n");

    // Inicialización de los registros del arreglo
    strcpy(votos[0].partido, "Lista Celeste y Blanca");
    votos[0].cantVotos = 0;
    strcpy(votos[0].partido, "Lista Los futuros Graduados");
    votos[0].cantVotos = 0;
    strcpy(votos[0].partido, "Lista Recursantes");
    votos[0].cantVotos = 0;
    strcpy(votos[0].partido, "Lista Accion Estudiantil");
    votos[0].cantVotos = 0;

    //ciclo while y seleccion de opcion
    while (hora > 7 && hora < 21){
        system("cls");
        printf("\n");
        printf("\n");
        printf("         _______________________________ \n");
        printf("        |                               |\n");
        printf("        |       Elija una opcion:       |\n");
        printf("        |_______________________________|\n");
        printf("        |                               |\n");
        printf("        |  1. Ver listas de candidatos  |\n");
        printf("        |  2. Votar por un candidato    |\n");
        printf("        |  3. Mostrar ranking de Votos  |\n");
        printf("        | (Esto finalizara el programa) |\n");
        printf("        |_______________________________|\n");
        printf("\n");
        printf("\n");
        scanf("%d",&Opcion);
        switch (Opcion){
        case 1:
            Ver_Listas(Dia,Mes,Anio);
            break;
        case 2:
            Registrar_Votos(prim,p1,q);
            break;
        case 3:
            Ranking_Votos();
            break;
        default:
            printf("Opcion ingresada incorrecta. Elija una opcion del 1 al 3, por favor.\n");
            break;
        }
    }
    if (hora<7 || hora>20){
        printf("No se permite votar fuera de la franja horaria establecida. \n");
        exit(0);
    }
    Borrar_Votantes(prim);
}