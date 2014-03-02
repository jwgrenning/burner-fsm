#include "BurnerControl.h"
#include <stdlib.h>
#include <memory.h>

struct BurnerControl * BurnerControl_Create(void)
{
     struct BurnerControl * self = calloc(1, sizeof(struct BurnerControl));
     BurnerControlContext_Init(&self->_fsm, self);
     return self;
}

void BurnerControl_Destroy(struct BurnerControl * self)
{
    free(self);
}

void BurnerControl_PowerButtonPressed(struct BurnerControl * self)
{
    BurnerControlContext_PowerButtonPressed(&self->_fsm);
}

void BurnerControl_UpPressed(struct BurnerControl * self)
{
    BurnerControlContext_UpPressed(&self->_fsm);
}

void BurnerControl_DownPressed(struct BurnerControl * self)
{
    BurnerControlContext_DownPressed(&self->_fsm);
}

