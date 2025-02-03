#ifndef _SENDERRECEIVER_MAIN_H
#define _SENDERRECEIVER_MAIN_H
#include "include/core/reactor.h"
#include "_sendermodel.h"
#include "_bitgenerator.h"
#include "_receivermodel.h"
#ifndef TOP_LEVEL_PREAMBLE_448765163_H
#define TOP_LEVEL_PREAMBLE_448765163_H
#include <stdlib.h>
typedef enum {
    STATE_A = 0, STATE_B = 1,
    STATE_C = 2, STATE_D = 3,
    STATE_E = 4, STATE_F = 5,
    STATE_G = 6, STATE_H = 7
} SenderModelState;

typedef enum {
    STATE_IDLE  = 0,
    STATE_LAST1 = 1,
    STATE_LAST0 = 2
} ReceiverModelState;

// queue_ss_t structure for Enq operation
typedef struct {
    int* items;
    int front;
    int rear;
    int capacity;
} queue_ss_t;

queue_ss_t* createQueue(int capacity);
void enqueue(queue_ss_t* queue, int value);
int dequeue(queue_ss_t* queue);
int get_front(queue_ss_t* queue);
void deleteQueue(queue_ss_t* queue);
int is_empty(queue_ss_t* queue);
void printQueue(queue_ss_t* queue, const char* message);
#endif
typedef struct {
    struct self_base_t base;
#line 42 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_senderreceiver_main.h"
#line 43 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_senderreceiver_main.h"
} _senderreceiver_main_main_self_t;
_senderreceiver_main_main_self_t* new__senderreceiver_main();
#endif // _SENDERRECEIVER_MAIN_H
