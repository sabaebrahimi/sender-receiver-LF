#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/senderreceiver\BitGenerator.h"
#include "_bitgenerator.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _bitgeneratorreaction_function_0(void* instance_args) {
    _bitgenerator_self_t* self = (_bitgenerator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bitgenerator_out_t* out = &self->_lf_out;
    #line 34 "/Users/SabaEbrahimi/workspace/EmbeddedMaster/final_project/project2/src/senderreceiver.lf"
    if (self->sent == 0) {
        lf_set(out, 1);
        self->sent = 1;
    }
#line 17 "c:\\Users\\SabaEbrahimi\\workspace\\EmbeddedMaster\\final_project\\project2\\src-gen\\senderreceiver\\_bitgenerator.c"
}
#include "include/api/reaction_macros_undef.h"
_bitgenerator_self_t* new__bitgenerator() {
    _bitgenerator_self_t* self = (_bitgenerator_self_t*)lf_new_reactor(sizeof(_bitgenerator_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _bitgeneratorreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__inputTimer.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__inputTimer.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__inputTimer_reactions[0] = &self->_lf__reaction_0;
    self->_lf__inputTimer.reactions = &self->_lf__inputTimer_reactions[0];
    self->_lf__inputTimer.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__inputTimer.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__inputTimer.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__inputTimer.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
