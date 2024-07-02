/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: encoder_arduino_test.h
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

#ifndef RTW_HEADER_encoder_arduino_test_h_
#define RTW_HEADER_encoder_arduino_test_h_
#ifndef encoder_arduino_test_COMMON_INCLUDES_
#define encoder_arduino_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "encoder_arduino.h"
#endif                               /* encoder_arduino_test_COMMON_INCLUDES_ */

#include "encoder_arduino_test_types.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <math.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  int128m_T r;
  int128m_T r1;
  int64m_T Gain1;                      /* '<S3>/Gain1' */
  int64m_T Gain;                       /* '<S3>/Gain' */
  real_T theta0;                       /* '<S3>/Data Type Conversion1' */
  real_T theta1;                       /* '<S3>/Data Type Conversion' */
  real_T Control_actionu;              /* '<S2>/Gain3' */
  real_T Saturation;                   /* '<S1>/Saturation' */
  real_T Gain_f;                       /* '<Root>/Gain' */
} B_encoder_arduino_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_encoder_ardui_T obj; /* '<S3>/MATLAB System1' */
  Encoder_arduino_encoder_ardui_T obj_p;/* '<S3>/MATLAB System' */
  codertarget_arduinobase_block_T obj_d;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_block_T obj_b;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_h;/* '<S1>/PWM' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative' */
  real_T TimeStampA_p;                 /* '<S3>/Derivative1' */
  real_T LastUAtTimeA_n;               /* '<S3>/Derivative1' */
  real_T TimeStampB_n;                 /* '<S3>/Derivative1' */
  real_T LastUAtTimeB_e;               /* '<S3>/Derivative1' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_j;                     /* '<S3>/Scope' */
} DW_encoder_arduino_test_T;

/* Parameters (default storage) */
struct P_encoder_arduino_test_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S3>/MATLAB System'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: 0.001
                                        * Referenced by: '<S3>/MATLAB System1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.05
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -255
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  int64m_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S3>/Gain3'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
  int32_T Gain1_Gain_j;                /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S3>/Gain1'
                                        */
  int32_T Gain_Gain_c;                 /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_encoder_arduino_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_encoder_arduino_test_T encoder_arduino_test_P;

/* Block signals (default storage) */
extern B_encoder_arduino_test_T encoder_arduino_test_B;

/* Block states (default storage) */
extern DW_encoder_arduino_test_T encoder_arduino_test_DW;

/* Model entry point functions */
extern void encoder_arduino_test_initialize(void);
extern void encoder_arduino_test_step(void);
extern void encoder_arduino_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_encoder_arduino_test_T *const encoder_arduino_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'encoder_arduino_test'
 * '<S1>'   : 'encoder_arduino_test/Arduino harduare drive'
 * '<S2>'   : 'encoder_arduino_test/Controller'
 * '<S3>'   : 'encoder_arduino_test/States Reading'
 */
#endif                                 /* RTW_HEADER_encoder_arduino_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
