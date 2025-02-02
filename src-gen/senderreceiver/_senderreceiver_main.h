#ifndef _SENDERRECEIVER_MAIN_H
#define _SENDERRECEIVER_MAIN_H
#include "include/core/reactor.h"
#include "_sendermodel.h"
#include "_bitgenerator.h"
#ifndef TOP_LEVEL_PREAMBLE_940375901_H
#define TOP_LEVEL_PREAMBLE_940375901_H
#include <stdlib.h>
typedef enum {
    STATE_A = 0, STATE_B = 1,
    STATE_C = 2, STATE_D = 3,
    STATE_E = 4, STATE_F = 5,
    STATE_G = 6, STATE_H = 7
} ModelState;

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
#endif
typedef struct {
    struct self_base_t base;
#line 34 "c:\\Users\\SabaEbrahimi\\workspace\\EmbeddedMaster\\final_project\\project2\\src-gen\\senderreceiver\\_senderreceiver_main.h"
#line 35 "c:\\Users\\SabaEbrahimi\\workspace\\EmbeddedMaster\\final_project\\project2\\src-gen\\senderreceiver\\_senderreceiver_main.h"
} _senderreceiver_main_main_self_t;
_senderreceiver_main_main_self_t* new__senderreceiver_main();
#endif // _SENDERRECEIVER_MAIN_H
