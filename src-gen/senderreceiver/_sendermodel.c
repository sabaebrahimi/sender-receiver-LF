#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/senderreceiver\SenderModel.h"
#include "_sendermodel.h"
// *********** From the preamble, verbatim:
#line 43 "/Users/SabaEbrahimi/workspace/EmbeddedMaster/final_project/project2/src/senderreceiver.lf"

#line 9 "c:\\Users\\SabaEbrahimi\\workspace\\EmbeddedMaster\\final_project\\project2\\src-gen\\senderreceiver\\_sendermodel.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _sendermodelreaction_function_0(void* instance_args) {
    _sendermodel_self_t* self = (_sendermodel_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 62 "/Users/SabaEbrahimi/workspace/EmbeddedMaster/final_project/project2/src/senderreceiver.lf"
    printf("SenderModel started\n");
    self->currState = STATE_A;
    self->queue = createQueue(10);
    
    for (int i = 0; i < self->length; i++) {
        enqueue(self->queue, self->sequence[i]);
    }
#line 26 "c:\\Users\\SabaEbrahimi\\workspace\\EmbeddedMaster\\final_project\\project2\\src-gen\\senderreceiver\\_sendermodel.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _sendermodelreaction_function_1(void* instance_args) {
    _sendermodel_self_t* self = (_sendermodel_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _sendermodel_in_t* in = self->_lf_in;
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    #line 72 "/Users/SabaEbrahimi/workspace/EmbeddedMaster/final_project/project2/src/senderreceiver.lf"
    printf("Received input: %d\n", in->value);
    // if (in == 1) {
    //     enqueue(queue, 1);
    //     m = dequeue(queue);
    // }
#line 40 "c:\\Users\\SabaEbrahimi\\workspace\\EmbeddedMaster\\final_project\\project2\\src-gen\\senderreceiver\\_sendermodel.c"
}
#include "include/api/reaction_macros_undef.h"
_sendermodel_self_t* new__sendermodel() {
    _sendermodel_self_t* self = (_sendermodel_self_t*)lf_new_reactor(sizeof(_sendermodel_self_t));
    // Set input by default to an always absent default input.
    self->_lf_in = &self->_lf_default__in;
    // Set the default source reactor pointer
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _sendermodelreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _sendermodelreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__in.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__in_reactions[0] = &self->_lf__reaction_1;
    self->_lf__in.reactions = &self->_lf__in_reactions[0];
    self->_lf__in.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__in.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__in.tmplt.type.element_size = sizeof(int);
    return self;
}
