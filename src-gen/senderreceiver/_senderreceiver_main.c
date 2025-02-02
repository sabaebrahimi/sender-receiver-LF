#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/senderreceiver\senderreceiver.h"
#include "_senderreceiver_main.h"
// *********** From the preamble, verbatim:
#line 211 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/sender-receiver-LF/src/senderreceiver.lf"
// queue_ss_t operations
queue_ss_t* createQueue(int capacity) {
    queue_ss_t* queue = (queue_ss_t*)malloc(sizeof(queue_ss_t));
    queue->items = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

void enqueue(queue_ss_t* queue, int value) {
    if (queue->rear < queue->capacity - 1) {
        queue->items[++queue->rear] = value;
    }
}

int dequeue(queue_ss_t* queue) {
    if (queue->front <= queue->rear) {
        return queue->items[queue->front++];
    }
    return -1;
}

int get_front(queue_ss_t* queue) {
    if (queue->front <= queue->rear) {
        return queue->items[queue->front];
    }
    return -1;
}

void deleteQueue(queue_ss_t* queue) {
    free(queue->items);
    free(queue);
}

int is_empty(queue_ss_t* queue) {
    return queue->front > queue->rear;
}
#line 46 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\sender-receiver-LF\\src-gen\\senderreceiver\\_senderreceiver_main.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
_senderreceiver_main_main_self_t* new__senderreceiver_main() {
    _senderreceiver_main_main_self_t* self = (_senderreceiver_main_main_self_t*)lf_new_reactor(sizeof(_senderreceiver_main_main_self_t));

    return self;
}
