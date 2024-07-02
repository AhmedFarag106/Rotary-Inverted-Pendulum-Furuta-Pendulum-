/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Rotary_Inverted_Pendulum_HIL_private.h
 *
 * Code generated for Simulink model 'Rotary_Inverted_Pendulum_HIL'.
 *
 * Model version                  : 8.70
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jan  3 00:27:39 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rotary_Inverted_Pendulum_HIL_private_h_
#define RTW_HEADER_Rotary_Inverted_Pendulum_HIL_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Rotary_Inverted_Pendulum_HIL_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);

#endif                  /* RTW_HEADER_Rotary_Inverted_Pendulum_HIL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
