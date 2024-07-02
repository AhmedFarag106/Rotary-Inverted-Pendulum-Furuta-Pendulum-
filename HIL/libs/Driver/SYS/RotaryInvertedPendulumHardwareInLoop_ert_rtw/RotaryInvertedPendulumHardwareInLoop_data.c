/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: RotaryInvertedPendulumHardwareInLoop_data.c
 *
 * Code generated for Simulink model 'RotaryInvertedPendulumHardwareInLoop'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Dec 22 21:34:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RotaryInvertedPendulumHardwareInLoop.h"

/* Block parameters (default storage) */
P_RotaryInvertedPendulumHardw_T RotaryInvertedPendulumHardwar_P = {
  /* Variable: K
   * Referenced by: '<Root>/Gain1'
   */
  { -31.622776601633795, 10214.133507714503, -374.01455331134218,
    979.33942422328028 },

  /* Mask Parameter: FilteredDerivativeDiscreteorCon
   * Referenced by: '<S6>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_n
   * Referenced by: '<S13>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_f
   * Referenced by: '<S6>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_h
   * Referenced by: '<S13>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteor_fa
   * Referenced by: '<S6>/Gain'
   */
  -1.0,

  /* Mask Parameter: FilteredDerivativeDiscreteor_hx
   * Referenced by: '<S13>/Gain'
   */
  1.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_d
   * Referenced by: '<S7>/Time constant'
   */
  0.001,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_a
   * Referenced by: '<S14>/Time constant'
   */
  0.001,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_l
   * Referenced by: '<S7>/Minimum sampling to time constant ratio'
   */
  10.0,

  /* Mask Parameter: FilteredDerivativeDiscreteor_hb
   * Referenced by: '<S14>/Minimum sampling to time constant ratio'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

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

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

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
   * Referenced by: '<S12>/Gain1'
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

  /* Expression: (360/500)/4
   * Referenced by: '<S1>/rev to degree'
   */
  0.18,

  /* Expression: pi/180
   * Referenced by: '<S5>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S11>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S11>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S11>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S11>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S11>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S18>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S18>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S18>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S18>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S18>/Saturation'
   */
  0.0,

  /* Expression: pi/7
   * Referenced by: '<Root>/Switch'
   */
  0.44879895051282759,

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
