#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/senderreceiver\ReceiverModel.h"
#include "_receivermodel.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _receivermodelreaction_function_0(void* instance_args) {
    _receivermodel_self_t* self = (_receivermodel_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _receivermodel_a_t* a = &self->_lf_a;
    #line 225 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    self->queue = createQueue(10);
    lf_schedule(a, 0);
#line 15 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_receivermodel.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _receivermodelreaction_function_1(void* instance_args) {
    _receivermodel_self_t* self = (_receivermodel_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _receivermodel_a_t* a = &self->_lf_a;
    // Set the fields of the action struct to match the current trigger.
    a->is_present = (bool)self->_lf__a.status;
    a->has_value = ((self->_lf__a.tmplt.token) != NULL && (self->_lf__a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)a, (self->_lf__a.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    _receivermodel_up_t* up = self->_lf_up;
    int up_width = self->_lf_up_width; SUPPRESS_UNUSED_WARNING(up_width);
    #line 230 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    // printf("y: %d\n", self->y);
    switch(self->currState){
        case STATE_IDLE:
            if (up->is_present){
                self->y = 0;
                enqueue(self->queue, 1);
                self->currState = STATE_LAST1;
                printf("Receiver State: IDLE -> LAST1\n");
                // printQueue(self->queue);
            }
            break;
    
        case STATE_LAST1:
            if (up->is_present && self->y >= 3000 - self->drift 
                        && self->y <= 5000 + self->drift){
                self->y = 0;
                enqueue(self->queue, 1);
                printf("Receiver State: LAST1 -> LAST1\n");
                // printQueue(self->queue);
            }
            else if (up->is_present && self->y >= 5000 - self->drift 
                        && self->y <= 7000 + self->drift){
                self->y = 0;
                enqueue(self->queue, 0);
                printf("Receiver State: LAST1 -> LAST0\n");
                // printQueue(self->queue);
                self->currState = STATE_LAST0;
            }
            else if (up->is_present && self->y >= 7000 - self->drift 
                        && self->y <= 9000 + self->drift){
                self->y = 0;
                enqueue(self->queue, 0);
                enqueue(self->queue, 1);
                printf("Receiver State: LAST1 -> LAST1\n");
                // printQueue(self->queue);
            }
            break;
    
        case STATE_LAST0:
        if (up->is_present && self->y >= 3000 - self->drift 
                        && self->y <= 5000 + self->drift){
                self->y = 0;
                enqueue(self->queue, 0);
                printf("Receiver State: LAST0 -> LAST0\n");
                // printQueue(self->queue);
            }
            else if (up->is_present && self->y >= 5000 - self->drift 
                        && self->y <= 7000 + self->drift){
                self->y = 0;
                enqueue(self->queue, 0);
                enqueue(self->queue, 1);
                printf("Receiver State: LAST0 -> LAST1\n");
                // printQueue(self->queue);
                self->currState = STATE_LAST1;
            }
            else if (self->y >= 7000 - self->drift){
                self->y = 0;
                enqueue(self->queue, 0);
                printf("Receiver State: LAST0 -> IDLE\n");
                self->currState = STATE_IDLE;
                printQueue(self->queue, "Received Queue");
            }
            break;
    }
    
    self->y++;
    lf_schedule(a, self->step);
#line 99 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_receivermodel.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _receivermodelreaction_function_2(void* instance_args) {
    _receivermodel_self_t* self = (_receivermodel_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 300 "/Users/Amin/Desktop/RT/project/sender-receiver-LF/src/senderreceiver.lf"
    if (self->queue != NULL) {
        deleteQueue(self->queue);
    }
#line 110 "c:\\Users\\Amin\\Desktop\\RT\\project\\sender-receiver-LF\\src-gen\\senderreceiver\\_receivermodel.c"
}
#include "include/api/reaction_macros_undef.h"
_receivermodel_self_t* new__receivermodel() {
    _receivermodel_self_t* self = (_receivermodel_self_t*)lf_new_reactor(sizeof(_receivermodel_self_t));
    self->_lf_a._base.trigger = &self->_lf__a;
    self->_lf_a.parent = (self_base_t*)self;
    self->_lf_a.source_id = -1;
    // Set input by default to an always absent default input.
    self->_lf_up = &self->_lf_default__up;
    // Set the default source reactor pointer
    self->_lf_default__up._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _receivermodelreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _receivermodelreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _receivermodelreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__shutdown.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__shutdown_reactions[0] = &self->_lf__reaction_2;
    self->_lf__shutdown.last_tag = NEVER_TAG;
    self->_lf__shutdown.reactions = &self->_lf__shutdown_reactions[0];
    self->_lf__shutdown.number_of_reactions = 1;
    self->_lf__shutdown.is_timer = false;
    self->_lf__a.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__a.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__a_reactions[0] = &self->_lf__reaction_1;
    self->_lf__a.reactions = &self->_lf__a_reactions[0];
    self->_lf__a.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__a.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__a.is_physical = false;
    
    self->_lf__a.tmplt.type.element_size = 0;
    self->_lf_a.type.element_size = 0;
    self->_lf__up.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__up.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__up_reactions[0] = &self->_lf__reaction_1;
    self->_lf__up.reactions = &self->_lf__up_reactions[0];
    self->_lf__up.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__up.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__up.tmplt.type.element_size = sizeof(int);
    return self;
}
