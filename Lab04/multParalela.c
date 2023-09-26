#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int l = 1000, c = 1000;
int v[1000];
int m[1000][1000];
int x[1000];

void preencheMatriz() {
  for (int i = 0; i < l; i++) {
    v[i] = i;
    for (int j = 0; j < c; j++) {
      m[i][j] = j;
    }
  }
}

int count_t;

void *createThread(void *rank) {
  long mRank = (long)rank;
  int i, j;
  int loc = l / count_t;
  int my_first_row = mRank * loc;
  int my_last_row = (mRank + 1) * loc - 1;
  for (i = my_first_row; i <= my_last_row; i++) {
    x[i] = 0;
    for (j = 0; j < c; j++) {
      x[i] += m[i][j] * v[j];
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
    
  long thread;
  pthread_t *handle;
    
  preencheMatriz();
    
  count_t = strtol(argv[1], NULL, 10);
  handle = malloc(count_t * sizeof(pthread_t));
  for (thread = 0; thread < count_t; thread++) {
    pthread_create(&handle[thread], NULL, createThread,
                   (void *)thread);
  }
  for (thread = 0; thread < count_t; thread++) {
    pthread_join(handle[thread],
                 NULL);
  }

  free(handle);
}

