/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Rotary_Inverted_Pendulum_HIL_types.h
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

#ifndef RTW_HEADER_Rotary_Inverted_Pendulum_HIL_types_h_
#define RTW_HEADER_Rotary_Inverted_Pendulum_HIL_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Custom Type definition for MATLABSystem: '<S3>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_h_matlabshared_ioclient_perip_T
#define typedef_h_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN h_matlabshared_ioclient_perip_T;

#endif                             /* typedef_h_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  h_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_tNlF2jjOTTyeKhyBNhAbs
#define struct_tag_tNlF2jjOTTyeKhyBNhAbs

struct tag_tNlF2jjOTTyeKhyBNhAbs
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /* struct_tag_tNlF2jjOTTyeKhyBNhAbs */

#ifndef typedef_Encoder_arduino_Rotary_Invert_T
#define typedef_Encoder_arduino_Rotary_Invert_T

typedef struct tag_tNlF2jjOTTyeKhyBNhAbs Encoder_arduino_Rotary_Invert_T;

#endif                             /* typedef_Encoder_arduino_Rotary_Invert_T */

/* Parameters (default storage) */
typedef struct P_Rotary_Inverted_Pendulum_HI_T_ P_Rotary_Inverted_Pendulum_HI_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Rotary_Inverted_Pendu_T RT_MODEL_Rotary_Inverted_Pend_T;

#endif                    /* RTW_HEADER_Rotary_Inverted_Pendulum_HIL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
