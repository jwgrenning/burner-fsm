#include "BurnerControl.h"

static void amongOtherThingsAccessHw(void)
{
    int * burner_hw = 0;
    *burner_hw = 0xdeadbeef;
}

void BurnerControl_Action_StartLedAnnimation(struct BurnerControl * burner)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_StopLedAnnimation(struct BurnerControl * burner)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_LedOn(struct BurnerControl * self, int ledNumber)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_AllLedsOff(struct BurnerControl * self)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_LedUpOne(struct BurnerControl * self)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_LedDownOne(struct BurnerControl * self)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_SetPowerTo(struct BurnerControl * self, int powerLevel)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_PowerUpOneLevel(struct BurnerControl * self)
{
    amongOtherThingsAccessHw();
}

void BurnerControl_Action_PowerDownOneLevel(struct BurnerControl * self)
{
    amongOtherThingsAccessHw();
}
