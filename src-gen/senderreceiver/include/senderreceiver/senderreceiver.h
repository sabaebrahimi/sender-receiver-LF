#ifndef _senderreceiver_main_H
#define _senderreceiver_main_H
#ifndef _SENDERRECEIVER_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1165973527_H
#define TOP_LEVEL_PREAMBLE_1165973527_H
/*Correspondence: Range: [(3, 4), (23, 36)) -> Range: [(0, 0), (20, 36)) (verbatim=true; src=c:\Users\SabaEbrahimi\workspace\EmbeddedMaster\final_project\project2\src\senderreceiver.lf)*/#include <stdlib.h>
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
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct senderreceiver_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} senderreceiver_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} bitgenerator_out_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} sendermodel_in_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} sendermodel_up_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} sendermodel_down_t;
#endif
#endif
