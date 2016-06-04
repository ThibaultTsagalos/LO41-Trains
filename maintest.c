#ifndef MAINTEST_H
#define MAINTEST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int train;
    struct elem* next;
}Element;

typedef struct {
    Element* head;
    int length;
}FileTrain;

/* Function createTrainLine
*
*  This Function creates and initializes an empty train waiting line, takes nothing and
*  returns a TrainLine.
*
*  F : a TrainLine variable corresponding to the TrainLine the user wants to
*  create.
*/

FileTrain createFileTrain()
{
FileTrain F;
F.head = NULL;
F.length = 0;
return F;
}

/* Function addTrain
*
*  This function adds the specified train to the specified TrainLine, it takes a *  TrainLine variable and a train variable (number) and returns the same TrainLine
*  containing the new train at the end.
*
*  h : a TrainLine variable corresponding to the TrainLine where the user wants to
*  add a train.
*  t : a train
*/
FileTrain addTrain(FileTrain f, int t)
{
  int i;
	 Element* newElem = (Element*)malloc(sizeof(Element));
	 newElem -> train = t;
    if (f.length == 0)
    {
	    newElem -> next = NULL;
	    f.head = newElem;
		  f.length = 1;
    }
    else
    {   newElem->next = f.head;
      for (i = 1; i < f.length; i++) {
        newElem->next = newElem->next->next;
        }
    newElem->next->next = newElem;
    newElem->next = NULL;
		f.length = f.length + 1;
    }

return f;
}

/* Function removeTrain
*
*  This function removes the first train of the waiting line.

*  f : a TrainLine, the one we want to delete the first train in line.
*/
FileTrain removeTrain(FileTrain t)
{

    Element* m = t.head;
    if (t.length == 0)
    {
        return t;
    }
    else if (t.length == 1)
    {
        t.length = 0;
        free(t.head);
        t.head = NULL;
        return t;
    }
	 else
        {
		  m -> next -> next = m -> next;
		  free(m);
        t.length = t.length - 1;

    }
return t;
}
/* Function PrintTrainLine
*
*This function prints a TrainLine on the console terminal, it takes a TrainLine and return nothing.
*
*t : A TrainLine that we want to explore.
*/

void PrintTrainLine(FileTrain t)
{
  int i;
  Element* m = t.head;
  for (i = 0; i < t.length; i++) {
    printf("Le train numéro %d est le train %d",i,m->train);
    m=m->next;
  }
}


void maintest()
{
FileTrain FT1;
FT1 = createFileTrain();
printf("FileTrain Crée");

}

#endif
