#ifndef		SCHEDULER_PROTOTYPE_H
#define		SCHEDULER_PROTOTYPE_H



typedef struct{
	char *name;
	u16 periodicity;
	u8 priority;
	u16 u16FirstDelay;
	void (*ptrfunc)(void);
}Task;

Task Create_task(char *name,u8 period,u8 priority,u16 del, void (*ptr)(void));
void start_scheduler(Task * stack);




#endif
