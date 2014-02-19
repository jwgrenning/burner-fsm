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
