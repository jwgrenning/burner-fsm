#ifndef BURNER_CONTROL_INCLUDED
#define BURNER_CONTROL_INCLUDED

#include "BurnerControl_sm.h"

struct BurnerControl
{
    struct BurnerControlContext _fsm;
};

struct BurnerControl * BurnerControl_Create(void);
void BurnerControl_Destroy(struct BurnerControl *);

void BurnerControl_OnPressed(struct BurnerControl *);

void BurnerControl_Action_StartLedAnnimation(struct BurnerControl *);
void BurnerControl_Action_StopLedAnnimation(struct BurnerControl *);

#endif
