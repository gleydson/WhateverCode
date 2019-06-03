#include <stdio.h>
#include "stdlib.h"

typedef enum
{
  True = 1,
  False = 0
} Boolean;

typedef enum
{
  Wait,
  Running,
  Finish
} Status;

enum
{
  MAX_RECURSOS = 100,
  QTD_PROCESSOS = 2
};

int qtdRecursos = MAX_RECURSOS;
int processosFinalizados = 0;

typedef struct
{
  int qtdRecursos;
  int recursosUsados;
  Status status;
} Processo;

int main()
{

  Processo *processos = (Processo *)malloc(sizeof(Processo) * QTD_PROCESSOS);
  int i = 0;
  for (; i < QTD_PROCESSOS; i++)
  {
    Processo p;
    processos[i] = p;
    processos[i].qtdRecursos = (rand() % MAX_RECURSOS) + 1;
    processos[i].recursosUsados = 0;
    processos[i].status = Wait;
  }

  while (True)
  {

    for (i = 0; i < QTD_PROCESSOS; i++)
    {
      if (processos[i].status != Finish)
      {
        if (processos[i].recursosUsados > 0)
        {
          processos[i].qtdRecursos -= processos[i].recursosUsados;
          qtdRecursos += processos[i].recursosUsados;
          printf("Devolveu: %d\n", processos[i].recursosUsados);
          processos[i].recursosUsados = 0;
          processos[i].status = Running;
        }

        printf("Disponivel: %d\n", qtdRecursos);

        if (qtdRecursos == 0)
        {
          processos[i].status = Wait;
          printf("Tipo: 1\n");
        }

        if (processos[i].qtdRecursos <= 0)
        {
          processos[i].status = Finish;
          processosFinalizados++;
          printf("Tipo: 2\n");
          break;
        }

        if (processos[i].qtdRecursos <= (qtdRecursos / 2))
        {
          processos[i].recursosUsados += processos[i].qtdRecursos;
          qtdRecursos -= processos[i].qtdRecursos;
          processos[i].status = Running;
          printf("Tipo: 3\n");
        }

        if (processos[i].qtdRecursos > (qtdRecursos / 2) && processos[i].status != Finish)
        {
          processos[i].recursosUsados += (qtdRecursos / 2);
          qtdRecursos -= (qtdRecursos / 2);
          processos[i].status = Running;
          printf("Tipo: 4\n");
        }

        printf("P: %d Falta: %d Usou: %d Recursos: %d \n", i, processos[i].qtdRecursos, processos[i].recursosUsados, qtdRecursos);
      }
    }

    if (processosFinalizados == QTD_PROCESSOS)
      break;
  }

  for (i = 0; i < QTD_PROCESSOS; i++)
    if (processos[i].status == Finish)
      printf("Processo %d finalizado!\n", i);

  free(processos);
  return 0;
}