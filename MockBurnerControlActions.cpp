#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "BurnerControl.h"

void BurnerControl_Action_StartLedAnnimation(struct BurnerControl * self)
{
        mock("burner").actualCall("BurnerControl_Action_StartLedAnnimation");
}

void BurnerControl_Action_StopLedAnnimation(struct BurnerControl * self)
{
        mock("burner").actualCall("BurnerControl_Action_StopLedAnnimation");
}

void BurnerControl_Action_LedOn(struct BurnerControl * self, int ledNumber)
{
        mock("burner").actualCall("BurnerControl_Action_LedOn")
                      .withParameter("ledNumber", ledNumber);
}

void BurnerControl_Action_AllLedsOff(struct BurnerControl * self)
{
        mock("burner").actualCall("BurnerControl_Action_AllLedsOff");
}

void BurnerControl_Action_LedUpOne(struct BurnerControl * self)
{
        mock("burner").actualCall("BurnerControl_Action_LedUpOne");
}

void BurnerControl_Action_SetPowerTo(struct BurnerControl *, int powerLevel)
{
        mock("burner").actualCall("BurnerControl_Action_SetPowerTo")
                      .withParameter("powerLevel", powerLevel);
}

void BurnerControl_Action_PowerUpOneLevel(struct BurnerControl * self)
{
        mock("burner").actualCall("BurnerControl_Action_PowerUpOneLevel");
}

}
