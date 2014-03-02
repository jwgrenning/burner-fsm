#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace std;

extern "C"
{
    #include "BurnerControl.h"
}

TEST_GROUP(BurnerControlStartState)
{
    struct BurnerControl * burnerControl;

    void setup()
    {
        mock("burner").strictOrder();
        burnerControl = BurnerControl_Create();
        expectCall("BurnerControl_Action_AllLedsOff");
        expectCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 0);
        BurnerControl_Go(burnerControl);
    }

    void teardown()
    {
        BurnerControl_Destroy(burnerControl);
        mock().checkExpectations();
        mock().clear();
    }

    MockFunctionCall& expectCall(SimpleString functionName)
    {
        return mock("burner").expectOneCall(functionName);
    }
};

TEST(BurnerControlStartState, initially_off)
{
}

TEST(BurnerControlStartState, press_on_button_starts_annimation)
{
    expectCall("BurnerControl_Action_StartLedAnnimation");
    BurnerControl_PowerButtonPressed(burnerControl);
}

TEST(BurnerControlStartState, press_on_twice_stops_annimation)
{
    expectCall("BurnerControl_Action_StartLedAnnimation");
    expectCall("BurnerControl_Action_StopLedAnnimation");
    expectCall("BurnerControl_Action_AllLedsOff");
    expectCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 0);
    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_PowerButtonPressed(burnerControl);
}

TEST(BurnerControlStartState, select_high)
{
    expectCall("BurnerControl_Action_StartLedAnnimation");
    expectCall("BurnerControl_Action_StopLedAnnimation");
    expectCall("BurnerControl_Action_LedOn").withParameter("ledNumber", 8);
    expectCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 100);

    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_UpPressed(burnerControl);
}

TEST(BurnerControlStartState, select_low)
{
    expectCall("BurnerControl_Action_StartLedAnnimation");
    expectCall("BurnerControl_Action_StopLedAnnimation");
    expectCall("BurnerControl_Action_LedOn").withParameter("ledNumber", 1);
    expectCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 10);

    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_DownPressed(burnerControl);
}

TEST(BurnerControlStartState, medium_low_power)
{
    expectCall("BurnerControl_Action_StartLedAnnimation");
    expectCall("BurnerControl_Action_StopLedAnnimation");
    expectCall("BurnerControl_Action_LedOn").withParameter("ledNumber", 1);
    expectCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 10);
    expectCall("BurnerControl_Action_LedUpOne");
    expectCall("BurnerControl_Action_PowerUpOneLevel");

    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_DownPressed(burnerControl);
    BurnerControl_UpPressed(burnerControl);
}

TEST(BurnerControlStartState, medium_high_power)
{
    expectCall("BurnerControl_Action_StartLedAnnimation");
    expectCall("BurnerControl_Action_StopLedAnnimation");
    expectCall("BurnerControl_Action_LedOn").withParameter("ledNumber", 8);
    expectCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 100);
    expectCall("BurnerControl_Action_LedDownOne");
    expectCall("BurnerControl_Action_PowerDownOneLevel");

    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_UpPressed(burnerControl);
    BurnerControl_DownPressed(burnerControl);
}

