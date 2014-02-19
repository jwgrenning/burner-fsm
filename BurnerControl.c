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

void BurnerControl_OnPressed(struct BurnerControl * self)
{
	BurnerControlContext_OnPressed(&self->_fsm);
}

