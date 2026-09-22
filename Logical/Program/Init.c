
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor.ke=0.00096;
	fb_motor.Tm=0.04;
	fb_motor.dt=0.002;
	fb_motor.w=0.0;
	fb_motor.phi=0.0;
	fb_motor.integrator.out=0.0;
	
	fb_motor_2.ke=0.00096;
	fb_motor_2.Tm=0.04;
	fb_motor_2.dt=0.002;
	fb_motor_2.w=0.0;
	fb_motor_2.phi=0.0;
	fb_motor_2.integrator.out=0.0;
	
	fb_controller.k_p=0.0064*2;
	fb_controller.k_i=0.16*2;
	fb_controller.max_abs_value=24.0;
	fb_controller.dt=0.002;
	fb_controller.u=0.0;
	fb_controller.iyOld=0.0;
	fb_controller.integrator.out=0.0;
	
	Enable=1;
	Speed=0.0;
	counter=0;
}
