/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Rotary_Inverted_Pendulum_HIL.h
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

#ifndef RTW_HEADER_Rotary_Inverted_Pendulum_HIL_h_
#define RTW_HEADER_Rotary_Inverted_Pendulum_HIL_h_
#ifndef Rotary_Inverted_Pendulum_HIL_COMMON_INCLUDES_
#define Rotary_Inverted_Pendulum_HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "encoder_arduino.h"
#endif                       /* Rotary_Inverted_Pendulum_HIL_COMMON_INCLUDES_ */

#include "Rotary_Inverted_Pendulum_HIL_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
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
  real_T Gain1;                        /* '<S9>/Gain1' */
  real_T Add;                          /* '<S2>/Add' */
  real_T Switch;                       /* '<S7>/Switch' */
  real_T revtodegree;                  /* '<S4>/rev to degree' */
  real_T Gain1_l;                      /* '<S8>/Gain1' */
  real_T DataTypeConversion3;          /* '<S4>/Data Type Conversion3' */
  real_T Switch_f;                     /* '<S6>/Switch' */
  real_T ControlAction;                /* '<S1>/Linearity checker' */
  real_T pwm;                          /* '<S3>/remove any negative pwm sign' */
} B_Rotary_Inverted_Pendulum_HI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_Rotary_Invert_T obj; /* '<S5>/motor encoder' */
  Encoder_arduino_Rotary_Invert_T obj_l;/* '<S4>/motor encoder' */
  codertarget_arduinobase_block_T obj_n;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_block_T obj_i;/* '<S3>/Digital Output' */
  codertarget_arduinobase_inter_T obj_m;/* '<S3>/PWM' */
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S4>/Derivative' */
  real_T TimeStampA_i;                 /* '<S5>/Derivative' */
  real_T LastUAtTimeA_f;               /* '<S5>/Derivative' */
  real_T TimeStampB_j;                 /* '<S5>/Derivative' */
  real_T LastUAtTimeB_a;               /* '<S5>/Derivative' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S3>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_a;                    /* '<S1>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S2>/Scop e2' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S4>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_l;                     /* '<S2>/Scope' */
} DW_Rotary_Inverted_Pendulum_H_T;

/* Parameters (default storage) */
struct P_Rotary_Inverted_Pendulum_HI_T_ {
  real_T k[4];                         /* Variable: k
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: pi
                                        * Referenced by: '<S6>/Bias'
                                        */
  real_T Bias1_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S6>/Bias1'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Bias2_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S6>/Bias2'
                                        */
  real_T Bias3_Bias;                   /* Expression: +pi
                                        * Referenced by: '<S6>/Bias3'
                                        */
  real_T Constant_Value_b;             /* Expression: 2*pi
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Bias_Bias_m;                  /* Expression: pi
                                        * Referenced by: '<S7>/Bias'
                                        */
  real_T Bias1_Bias_e;                 /* Expression: -pi
                                        * Referenced by: '<S7>/Bias1'
                                        */
  real_T Constant1_Value_p;            /* Expression: 2*pi
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Bias2_Bias_j;                 /* Expression: -pi
                                        * Referenced by: '<S7>/Bias2'
                                        */
  real_T Bias3_Bias_i;                 /* Expression: +pi
                                        * Referenced by: '<S7>/Bias3'
                                        */
  real_T motorencoder_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S4>/motor encoder'
                                        */
  real_T motorencoder_SampleTime_i;    /* Expression: 0.001
                                        * Referenced by: '<S5>/motor encoder'
                                        */
  real_T revtodegree_Gain;             /* Expression: (360/600)/4
                                        * Referenced by: '<S5>/rev to degree'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S2>/Pi'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T revtodegree_Gain_j;           /* Expression: (360/(500*4))
                                        * Referenced by: '<S4>/rev to degree'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Linearitychecker_Threshold;   /* Expression: pi/7
                                        * Referenced by: '<S1>/Linearity checker'
                                        */
  real_T Scaling_Gain;                 /* Expression: 0.0008
                                        * Referenced by: '<S3>/Scaling'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -255
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S3>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Rotary_Inverted_Pendu_T {
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
extern P_Rotary_Inverted_Pendulum_HI_T Rotary_Inverted_Pendulum_HIL_P;

/* Block signals (default storage) */
extern B_Rotary_Inverted_Pendulum_HI_T Rotary_Inverted_Pendulum_HIL_B;

/* Block states (default storage) */
extern DW_Rotary_Inverted_Pendulum_H_T Rotary_Inverted_Pendulum_HIL_DW;

/* Model entry point functions */
extern void Rotary_Inverted_Pendulum_HIL_initialize(void);
extern void Rotary_Inverted_Pendulum_HIL_step(void);
extern void Rotary_Inverted_Pendulum_HIL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rotary_Inverted_Pend_T *const Rotary_Inverted_Pendulum_HIL_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'Rotary_Inverted_Pendulum_HIL'
 * '<S1>'   : 'Rotary_Inverted_Pendulum_HIL/Controller'
 * '<S2>'   : 'Rotary_Inverted_Pendulum_HIL/Subsystem1'
 * '<S3>'   : 'Rotary_Inverted_Pendulum_HIL/motor drive'
 * '<S4>'   : 'Rotary_Inverted_Pendulum_HIL/motor encoder'
 * '<S5>'   : 'Rotary_Inverted_Pendulum_HIL/pendulum encoder'
 * '<S6>'   : 'Rotary_Inverted_Pendulum_HIL/Subsystem1/waraper'
 * '<S7>'   : 'Rotary_Inverted_Pendulum_HIL/Subsystem1/waraper1'
 * '<S8>'   : 'Rotary_Inverted_Pendulum_HIL/motor encoder/Degrees to Radians'
 * '<S9>'   : 'Rotary_Inverted_Pendulum_HIL/pendulum encoder/Degrees to Radians'
 */
#endif                          /* RTW_HEADER_Rotary_Inverted_Pendulum_HIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
