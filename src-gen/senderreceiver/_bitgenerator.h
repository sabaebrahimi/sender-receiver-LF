#ifndef _BITGENERATOR_H
#define _BITGENERATOR_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1432929075_H
#define TOP_LEVEL_PREAMBLE_1432929075_H
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
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bitgenerator_out_t;
typedef struct {
    struct self_base_t base;
#line 53 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_bitgenerator.h"
    #line 37 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    int sent;
#line 56 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_bitgenerator.h"
    _bitgenerator_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__inputTimer;
    reaction_t* _lf__inputTimer_reactions[1];
} _bitgenerator_self_t;
_bitgenerator_self_t* new__bitgenerator();
#endif // _BITGENERATOR_H
