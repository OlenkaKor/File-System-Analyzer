#include "functions.hpp"
#define NUMBER_OF_THREAD 8

int main(int argc, char *argv[]) {
    pthread_t *thread = new pthread_t[NUMBER_OF_THREAD];
    for(int i = 0; i < NUMBER_OF_THREAD; i++){
      pthread_create(&thread[i], 0, thread_func, 0);
    }

    for(int i = 0; i < NUMBER_OF_THREAD; i++){
      pthread_join(thread[i], 0);
    }

    return 0;
}
