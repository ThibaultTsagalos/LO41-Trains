#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "maintest.h"
#include "parser.h"

int main(void)
{
  int i = 0,j = 0, number = 0, count = 0,x;
  char file_name[100] = "";
  char line[128];
  int size;
  FILE* input;
  int ** output;
  printf("Entrez le chemin du fichier a utiliser:\n");
  gets(file_name);
  printf("Fichier: %s\n", file_name);


  if((input = fopen(file_name, "r")) == NULL)
  {
    perror("Wrong input");
    return 1;
  }
  fgets(line, sizeof line, input);
  size = atoi(line)+1;


  output = malloc (size * sizeof (int *));

  for (x = 0;x < 3;x ++)
  {
    output[x] = malloc (3 * sizeof (int));
  }


  while(fgets(line, sizeof line, input) != NULL)
  {
    if (strncmp(line, "TGV", 3) == 0)
    {
      output[number][count] = 1;
      count ++;
    }
    else if (strncmp(line, "GL", 2) == 0)
    {
      output[number][count] = 2;
      count ++;
    }
    else if (strncmp(line, "M", 1) == 0)
    {
      output[number][count] = 3;
      count ++;
    }
    else if (strncmp(line, "EST", 3) == 0)
    {
      output[number][count] = 5;
      count ++;
    }
    else if (strncmp(line, "A", 1) == 0)
    {
      output[number][count] = 1;
      count ++;
    }
    else if (strncmp(line, "B", 1) == 0)
    {
      output[number][count] = 2;
      count ++;
    }
    else if (strncmp(line, "C", 1) == 0)
    {
      output[number][count] = 3;
      count ++;
    }
    else if (strncmp(line, "D", 1) == 0)
    {
      output[number][count] = 4;
      count ++;
    }
    else
    {
      printf("Train number %d\n", number + 1);
    }
    if (count == 3)
    {
      count = 0;
      number ++;
    }

  }
  fclose(input);

  for (i = 0; i < 3; i++)
  {
    printf("i=%d\n", i);
    for(j = 0; j < 3; j++)
    {
      printf("j=%d\n",j);
      printf("MAIN tab output :%d\n", output[i][j]);
    }
  }

  maintest();
  return EXIT_SUCCESS;
}
