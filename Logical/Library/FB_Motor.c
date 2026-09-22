
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
	REAL e;

	e=inst->u/inst->ke-inst->w;
	inst->integrator.in=e/inst->Tm;
	inst->integrator.dt=inst->dt;
	FB_Integrator(&inst->integrator);
	
	inst->w= inst->integrator.out;
	inst->phi=inst->phi + inst->w * (2 * pi / 60) * inst->dt;
}
