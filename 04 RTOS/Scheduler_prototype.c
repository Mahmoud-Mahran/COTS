#include	"Std_Types.h"
#include	"Bit_Math.h"
#include 	<Scheduler_prototype.h>

Task Create_task(char *name,u8 period,u8 priority,u16 del, void (*ptr)(void)){
	Task t1;
	t1.name = name;
	t1.periodicity = period;
	t1.priority = priority;
	t1.ptrfunc = ptr;
	t1.u16FirstDelay = 0;
	return t1;
}
void start_scheduler(Task * stack){
	for(int i = 0; i < 2; i++){
		for(int j = i+1; j < 3; j++){
			if(stack[i].priority > stack[j].priority){
				Task temp = stack[j];
				stack[j] = stack[i];
				stack[i] = temp;
			}
		}
	}
	/* for loop to check on every TCB */
	u8 counter;
	for(counter = 0; counter < 3 ; counter++)
	{
		if(stack[counter].u16FirstDelay == 0)
		{
			//Call function
			stack[counter].ptrfunc();
			//Periodicity => firstdelay
			stack[counter].u16FirstDelay = stack[counter].periodicity - 1;
		}
		else
		{
			stack[counter].u16FirstDelay--;
		}
	}

}


