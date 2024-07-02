/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: encoder_arduino_test_data.c
 *
 * Code generated for Simulink model 'encoder_arduino_test'.
 *
 * Model version                  : 18.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Dec 22 20:45:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "encoder_arduino_test.h"

/* Block parameters (default storage) */
P_encoder_arduino_test_T encoder_arduino_test_P = {
  /* Variable: K
   * Referenced by: '<S2>/Gain3'
   */
  { -0.99999999999944145, 3403.673375497388, -159.16193194378903,
    317.812942069593 },

  /* Expression: 0.001
   * Referenced by: '<S3>/MATLAB System'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S3>/MATLAB System1'
   */
  0.001,

  /* Expression: -1
   * Referenced by: '<S2>/Gain1'
   */
  -1.0,

  /* Expression: 0.05
   * Referenced by: '<S1>/Gain'
   */
  0.05,

  /* Expression: 255
   * Referenced by: '<S1>/Saturation'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<S1>/Saturation'
   */
  -255.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S3>/Gain3'
   */
  { { 0x4A74E400UL, 0x477D1A89UL } },

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S3>/Gain2'
   */
  { { 0x4A74E400UL, 0x477D1A89UL } },

  /* Computed Parameter: Gain1_Gain_j
   * Referenced by: '<S3>/Gain1'
   */
  1546188227,

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S3>/Gain'
   */
  1288490189
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
