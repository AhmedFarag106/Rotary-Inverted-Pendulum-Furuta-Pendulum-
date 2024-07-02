/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Rotary_Inverted_Pendulum_HIL_Tutorial_data.c
 *
 * Code generated for Simulink model 'Rotary_Inverted_Pendulum_HIL_Tutorial'.
 *
 * Model version                  : 8.38
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Dec 29 05:13:59 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rotary_Inverted_Pendulum_HIL_Tutorial.h"

/* Block parameters (default storage) */
P_Rotary_Inverted_Pendulum_HI_T Rotary_Inverted_Pendulum_HIL__P = {
  /* Variable: k
   * Referenced by: '<S1>/Gain1'
   */
  { -3.1622776636352192, 1888.5144189720652, -168.11120904702577,
    127.15158764182901 },

  /* Expression: 1
   * Referenced by: '<S1>/Gain'
   */
  1.0,

  /* Expression: 2*pi
   * Referenced by: '<S6>/Constant'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S6>/Bias'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S6>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S6>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S6>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: +pi
   * Referenced by: '<S6>/Bias3'
   */
  3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S7>/Constant'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S7>/Bias'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S7>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S7>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S7>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: +pi
   * Referenced by: '<S7>/Bias3'
   */
  3.1415926535897931,

  /* Expression: 0.001
   * Referenced by: '<S4>/motor encoder'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S5>/motor encoder'
   */
  0.001,

  /* Expression: (360/600)/4
   * Referenced by: '<S5>/rev to degree'
   */
  0.15,

  /* Expression: pi/180
   * Referenced by: '<S9>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi
   * Referenced by: '<S2>/Pi'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S7>/Switch'
   */
  0.0,

  /* Expression: (360/(500*4))
   * Referenced by: '<S4>/rev to degree'
   */
  0.18,

  /* Expression: pi/180
   * Referenced by: '<S8>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: pi/7
   * Referenced by: '<S1>/Linearity checker'
   */
  0.44879895051282759,

  /* Expression: 0.0008
   * Referenced by: '<S3>/Scaling'
   */
  0.0008,

  /* Expression: 255
   * Referenced by: '<S3>/Saturation'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<S3>/Saturation'
   */
  -255.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch1'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
