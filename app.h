/*
 * app.h
 *
 *  Created on: 2017/07/07
 *      Author: Yuki Mori
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TOPPERS_MACRO_ONLY


extern void init_task(intptr_t exinf);
extern void cognition_task(intptr_t exinf);
extern void judgement_task(intptr_t exinf);
extern void operation_task(intptr_t exinf);
extern void main_cyc(intptr_t exinf);


#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
