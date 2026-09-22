
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
void FB_Regulator(struct FB_Regulator* inst)
{
	REAL p_term,sum_before_sat, u_sat;

	p_term= inst->e * inst->k_p;
	if (p_term > inst->max_abs_value)
		p_term=inst->max_abs_value;
	else if (p_term < -inst->max_abs_value)
		p_term=-inst->max_abs_value;

	inst->integrator.in=inst->e * inst->k_i +(inst->iyOld -(p_term +inst->integrator.out));
	inst->integrator.dt=inst->dt;
	FB_Integrator(&inst->integrator);
	
	sum_before_sat=p_term + inst->integrator.out;
	if (sum_before_sat > inst->max_abs_value)
		u_sat=inst->max_abs_value;
	else if (sum_before_sat < -inst->max_abs_value)
		u_sat=-inst->max_abs_value;
	else
		u_sat=sum_before_sat;

	inst->iyOld=u_sat;
	inst->u=u_sat;
}
