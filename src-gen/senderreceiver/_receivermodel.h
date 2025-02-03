#ifndef _RECEIVERMODEL_H
#define _RECEIVERMODEL_H
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
} _receivermodel_up_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _receivermodel_a_t;
typedef struct {
    struct self_base_t base;
#line 70 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_receivermodel.h"
    #line 207 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    int y;
    #line 209 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    interval_t step;
    #line 211 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    ReceiverModelState currState;
    #line 212 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    queue_ss_t* queue;
#line 79 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_receivermodel.h"
    _receivermodel_a_t _lf_a;
    _receivermodel_up_t* _lf_up;
    // width of -2 indicates that it is not a multiport.
    int _lf_up_width;
    // Default input (in case it does not get connected)
    _receivermodel_up_t _lf_default__up;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__shutdown;
    reaction_t* _lf__shutdown_reactions[1];
    trigger_t _lf__a;
    reaction_t* _lf__a_reactions[1];
    trigger_t _lf__up;
    reaction_t* _lf__up_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _receivermodel_self_t;
_receivermodel_self_t* new__receivermodel();
#endif // _RECEIVERMODEL_H
