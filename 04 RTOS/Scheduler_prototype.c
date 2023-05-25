#include	"Std_Types.h"
#include	"Bit_Math.h"
#include 	<Scheduler_prototype.h>
Task task_stack[3] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

void Create_task(char *name,u8 period,u8 priority,u16 del, void (*ptr)(void)){
	for (int i = 0; i < 3; i++) {
		if(task_stack[i].priority == 0){
			task_stack[i].name = name;
			task_stack[i].periodicity = period;
			task_stack[i].priority = priority;
			task_stack[i].ptrfunc = ptr;
			task_stack[i].u16FirstDelay = del;
			break;
		}
	}


}
void start_scheduler(void){
	for(int i = 0; i < 2; i++){
		for(int j = i+1; j < 3; j++){
			if(task_stack[i].priority > task_stack[j].priority){
				Task temp = task_stack[j];
				task_stack[j] = task_stack[i];
				task_stack[i] = temp;
			}
		}
	}
	/* for loop to check on every TCB */
	u8 counter;
	for(counter = 0; counter < 3 ; counter++)
	{
		if(task_stack[counter].u16FirstDelay == 0)
		{
			//Call function
			task_stack[counter].ptrfunc();
			//Periodicity => firstdelay
			task_stack[counter].u16FirstDelay = task_stack[counter].periodicity - 1;
		}
		else
		{
			task_stack[counter].u16FirstDelay--;
		}
	}

}


