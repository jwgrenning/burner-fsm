#ifndef BURNER_CONTROL_INCLUDED
#define BURNER_CONTROL_INCLUDED

#include "BurnerControl_sm.h"

struct BurnerControl
{
    struct BurnerControlContext _fsm;
};

struct BurnerControl * BurnerControl_Create(void);
void BurnerControl_Destroy(struct BurnerControl *);

void BurnerControl_Go(struct BurnerControl *);
void BurnerControl_PowerButtonPressed(struct BurnerControl *);
void BurnerControl_UpPressed(struct BurnerControl *);
void BurnerControl_DownPressed(struct BurnerControl *);

void BurnerControl_Action_StartLedAnnimation(struct BurnerControl *);
void BurnerControl_Action_StopLedAnnimation(struct BurnerControl *);
void BurnerControl_Action_LedOn(struct BurnerControl *, int ledNumber);
void BurnerControl_Action_AllLedsOff(struct BurnerControl *);
void BurnerControl_Action_LedUpOne(struct BurnerControl *);
void BurnerControl_Action_LedDownOne(struct BurnerControl *);

void BurnerControl_Action_SetPowerTo(struct BurnerControl *, int powerLevel);
void BurnerControl_Action_PowerUpOneLevel(struct BurnerControl *);
void BurnerControl_Action_PowerDownOneLevel(struct BurnerControl *);

#endif
