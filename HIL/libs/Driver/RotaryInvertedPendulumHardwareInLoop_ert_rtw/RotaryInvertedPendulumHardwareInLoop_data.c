/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: RotaryInvertedPendulumHardwareInLoop_data.c
 *
 * Code generated for Simulink model 'RotaryInvertedPendulumHardwareInLoop'.
 *
 * Model version                  : 8.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Dec 26 23:30:09 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RotaryInvertedPendulumHardwareInLoop.h"

/* Block parameters (default storage) */
P_RotaryInvertedPendulumHardw_T RotaryInvertedPendulumHardwar_P = {
  /* Variable: k
   * Referenced by: '<Root>/Gain1'
   */
  { -316.22777391828106, 426242.59413553751, -18834.57972636641,
    29592.330650577824 },

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S1>/motor encoder'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S2>/motor encoder'
   */
  0.001,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Constant'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S3>/Bias'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S3>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S3>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: +pi
   * Referenced by: '<S3>/Bias3'
   */
  3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Constant'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S4>/Bias'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S4>/Bias1'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S4>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: +pi
   * Referenced by: '<S4>/Bias3'
   */
  3.1415926535897931,

  /* Expression: (360/600)/4
   * Referenced by: '<S2>/rev to degree'
   */
  0.15,

  /* Expression: pi/180
   * Referenced by: '<S13>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi
   * Referenced by: '<Root>/Pi'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: (360/(500*4))
   * Referenced by: '<S1>/rev to degree'
   */
  0.18,

  /* Expression: pi/180
   * Referenced by: '<S5>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: pi/7
   * Referenced by: '<Root>/Switch'
   */
  0.44879895051282759,

  /* Expression: 0.00080
   * Referenced by: '<S1>/Scaling'
   */
  0.0008,

  /* Expression: 255
   * Referenced by: '<S1>/Saturation'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<S1>/Saturation'
   */
  -255.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch1'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
