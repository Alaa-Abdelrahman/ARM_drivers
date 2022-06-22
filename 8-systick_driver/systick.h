#ifndef _SYSTICK_H
#define _SYSTICK_H

void systk_init_1sec(void);

int get_count_flag(void);

void systick_delayMs(int dly);


#endif