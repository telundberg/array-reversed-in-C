#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_ELEMENTS = 5;

void fillArrays(int *oneArray, int *anotherArray) {

  int randNum;
  int i;

  for (i=0; i<NUM_ELEMENTS; i++) {
    randNum = (rand()%100) + 1;
    oneArray[i] = randNum;
  }
  for (i=0; i<NUM_ELEMENTS; i++) {
    randNum = (rand()%100) + 1;
    anotherArray[i] = randNum;
  }
}

void mergeArrays(int thisArray[NUM_ELEMENTS],int thatArray[NUM_ELEMENTS]) {

  int i;
  int tempVal;
  int thirdArray[NUM_ELEMENTS*2];

  for (i=0; i<NUM_ELEMENTS; i++) {
    thirdArray[i] = thisArray[i];
  }
  for (i=0; i<NUM_ELEMENTS; i++) {
    thirdArray[NUM_ELEMENTS+i] = thatArray[i];
  }

  for (i=0; i<NUM_ELEMENTS; i++) {
    tempVal = thirdArray[i];
    thirdArray[i] = thirdArray[NUM_ELEMENTS*2-1-i];
    thirdArray[NUM_ELEMENTS*2-1-i] = tempVal;
  }
  for (i=0; i<NUM_ELEMENTS*2; i++) {
    printf("%d ", thirdArray[i]);
  }
}

int main(void) {

  int i;
  int nearArray[5];
  int farArray[5];

  srand((int)time(0));

  fillArrays(nearArray, farArray);

  printf("Array 1: ");
  for (i = 0; i < NUM_ELEMENTS; i++) {
    printf("%d ", nearArray[i]);
  }
  printf("\n");
  printf("Array 2: ");
  for (i = 0; i < NUM_ELEMENTS; i++) {
    printf("%d ", farArray[i]);
  }
  printf("\n");
  printf("Array 3: ");
  mergeArrays(nearArray,farArray);

  return 0;
}
