#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "BurnerControl.h"
}

TEST_GROUP(BurnerControlStartState)
{
    struct BurnerControl * burnerControl;

    void setup()
    {
        burnerControl = BurnerControl_Create();
        mock("burner").strictOrder();
    }

    void teardown()
    {
        BurnerControl_Destroy(burnerControl);
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(BurnerControlStartState, press_on_button_starts_annimation)
{
    mock("burner").expectOneCall("BurnerControl_Action_StartLedAnnimation");
    BurnerControl_PowerButtonPressed(burnerControl);
}

TEST(BurnerControlStartState, press_on_twice_stops_annimation)
{
    mock("burner").expectOneCall("BurnerControl_Action_StartLedAnnimation");
    mock("burner").expectOneCall("BurnerControl_Action_StopLedAnnimation");
    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_PowerButtonPressed(burnerControl);
}

TEST(BurnerControlStartState, press_on_then_up_full_power)
{
    mock("burner").expectOneCall("BurnerControl_Action_StartLedAnnimation");
    mock("burner").expectOneCall("BurnerControl_Action_StopLedAnnimation");
    mock("burner").expectOneCall("BurnerControl_Action_LedOn").withParameter("ledNumber", 8);
    mock("burner").expectOneCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 100);

    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_UpPressed(burnerControl);
}

TEST(BurnerControlStartState, press_on_then_down_low_power)
{
    mock("burner").expectOneCall("BurnerControl_Action_StartLedAnnimation");
    mock("burner").expectOneCall("BurnerControl_Action_StopLedAnnimation");
    mock("burner").expectOneCall("BurnerControl_Action_LedOn").withParameter("ledNumber", 1);
    mock("burner").expectOneCall("BurnerControl_Action_SetPowerTo").withParameter("powerLevel", 10);

    BurnerControl_PowerButtonPressed(burnerControl);
    BurnerControl_DownPressed(burnerControl);
}

