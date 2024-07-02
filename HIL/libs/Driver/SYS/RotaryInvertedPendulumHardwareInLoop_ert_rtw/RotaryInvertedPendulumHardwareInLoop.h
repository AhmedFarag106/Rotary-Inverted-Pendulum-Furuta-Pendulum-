/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: RotaryInvertedPendulumHardwareInLoop.h
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

#ifndef RTW_HEADER_RotaryInvertedPendulumHardwareInLoop_h_
#define RTW_HEADER_RotaryInvertedPendulumHardwareInLoop_h_
#ifndef RotaryInvertedPendulumHardwareInLoop_COMMON_INCLUDES_
#define RotaryInvertedPendulumHardwareInLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "encoder_arduino.h"
#endif               /* RotaryInvertedPendulumHardwareInLoop_COMMON_INCLUDES_ */

#include "RotaryInvertedPendulumHardwareInLoop_types.h"
#include "rt_nonfinite.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define RotaryInvertedPendulumHardwareInLoop_M (RotaryInvertedPendulumHardwa_M)

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<Root>/Add' */
  real_T Switch;                       /* '<S4>/Switch' */
  real_T Probe[2];                     /* '<S7>/Probe' */
  real_T Probe_m[2];                   /* '<S14>/Probe' */
  real_T Switch_b;                     /* '<Root>/Switch' */
  int32_T motorencoder;                /* '<S1>/motor encoder' */
} B_RotaryInvertedPendulumHardw_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_RotaryInverte_T obj; /* '<S2>/motor encoder' */
  Encoder_arduino_RotaryInverte_T obj_l;/* '<S1>/motor encoder' */
  codertarget_arduinobase_block_T obj_n;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_block_T obj_i;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_m;/* '<S1>/PWM' */
  real_T Integrator_DSTATE;            /* '<S11>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S18>/Integrator' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_l;                     /* '<Root>/Scope' */

  int8_T Integrator_PrevResetState;    /* '<S11>/Integrator' */
  int8_T Integrator_PrevResetState_f;  /* '<S18>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S11>/Integrator' */
  uint8_T Integrator_IC_LOADING_m;     /* '<S18>/Integrator' */
} DW_RotaryInvertedPendulumHard_T;

/* Parameters (default storage) */
struct P_RotaryInvertedPendulumHardw_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T FilteredDerivativeDiscreteorCon;
                              /* Mask Parameter: FilteredDerivativeDiscreteorCon
                               * Referenced by: '<S6>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_n;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_n
                               * Referenced by: '<S13>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_f;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_f
                               * Referenced by: '<S6>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_h;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_h
                               * Referenced by: '<S13>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteor_fa;
                              /* Mask Parameter: FilteredDerivativeDiscreteor_fa
                               * Referenced by: '<S6>/Gain'
                               */
  real_T FilteredDerivativeDiscreteor_hx;
                              /* Mask Parameter: FilteredDerivativeDiscreteor_hx
                               * Referenced by: '<S13>/Gain'
                               */
  real_T FilteredDerivativeDiscreteorC_d;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_d
                               * Referenced by: '<S7>/Time constant'
                               */
  real_T FilteredDerivativeDiscreteorC_a;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_a
                               * Referenced by: '<S14>/Time constant'
                               */
  real_T FilteredDerivativeDiscreteorC_l;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_l
                               * Referenced by: '<S7>/Minimum sampling to time constant ratio'
                               */
  real_T FilteredDerivativeDiscreteor_hb;
                              /* Mask Parameter: FilteredDerivativeDiscreteor_hb
                               * Referenced by: '<S14>/Minimum sampling to time constant ratio'
                               */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: pi
                                        * Referenced by: '<S3>/Bias'
                                        */
  real_T Bias1_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S3>/Bias1'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Bias2_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S3>/Bias2'
                                        */
  real_T Bias3_Bias;                   /* Expression: +pi
                                        * Referenced by: '<S3>/Bias3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T motorencoder_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S1>/motor encoder'
                                        */
  real_T motorencoder_SampleTime_i;    /* Expression: 0.001
                                        * Referenced by: '<S2>/motor encoder'
                                        */
  real_T Constant_Value_b;             /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Bias_Bias_m;                  /* Expression: pi
                                        * Referenced by: '<S4>/Bias'
                                        */
  real_T Bias1_Bias_e;                 /* Expression: -pi
                                        * Referenced by: '<S4>/Bias1'
                                        */
  real_T Constant1_Value_p;            /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Bias2_Bias_j;                 /* Expression: -pi
                                        * Referenced by: '<S4>/Bias2'
                                        */
  real_T Bias3_Bias_i;                 /* Expression: +pi
                                        * Referenced by: '<S4>/Bias3'
                                        */
  real_T revtodegree_Gain;             /* Expression: (360/600)/4
                                        * Referenced by: '<S2>/rev to degree'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<Root>/Pi'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T revtodegree_Gain_j;           /* Expression: (360/500)/4
                                        * Referenced by: '<S1>/rev to degree'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Integrator_gainval_n;       /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S18>/Integrator'
                                      */
  real_T Integrator_UpperSat_d;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Integrator_LowerSat_m;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Switch_Threshold_m;           /* Expression: pi/7
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 255
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -255
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Switch_Threshold_p2;          /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RotaryInvertedPendulu_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_RotaryInvertedPendulumHardw_T RotaryInvertedPendulumHardwar_P;

/* Block signals (default storage) */
extern B_RotaryInvertedPendulumHardw_T RotaryInvertedPendulumHardwar_B;

/* Block states (default storage) */
extern DW_RotaryInvertedPendulumHard_T RotaryInvertedPendulumHardwa_DW;

/* Model entry point functions */
extern void RotaryInvertedPendulumHardwareInLoop_initialize(void);
extern void RotaryInvertedPendulumHardwareInLoop_step(void);
extern void RotaryInvertedPendulumHardwareInLoop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RotaryInvertedPendul_T *const RotaryInvertedPendulumHardwa_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * '<Root>' : 'RotaryInvertedPendulumHardwareInLoop'
 * '<S1>'   : 'RotaryInvertedPendulumHardwareInLoop/motor feedback'
 * '<S2>'   : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback'
 * '<S3>'   : 'RotaryInvertedPendulumHardwareInLoop/waraper'
 * '<S4>'   : 'RotaryInvertedPendulumHardwareInLoop/waraper1'
 * '<S5>'   : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Degrees to Radians'
 * '<S6>'   : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Filtered Derivative (Discrete or Continuous)'
 * '<S7>'   : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Filtered Derivative (Discrete or Continuous)/Enable//disable time constant'
 * '<S8>'   : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Filtered Derivative (Discrete or Continuous)/Initialization'
 * '<S9>'   : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S10>'  : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Filtered Derivative (Discrete or Continuous)/Initialization/Init_u'
 * '<S11>'  : 'RotaryInvertedPendulumHardwareInLoop/motor feedback/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S12>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Degrees to Radians'
 * '<S13>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Filtered Derivative (Discrete or Continuous)'
 * '<S14>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Filtered Derivative (Discrete or Continuous)/Enable//disable time constant'
 * '<S15>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Filtered Derivative (Discrete or Continuous)/Initialization'
 * '<S16>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S17>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Filtered Derivative (Discrete or Continuous)/Initialization/Init_u'
 * '<S18>'  : 'RotaryInvertedPendulumHardwareInLoop/pendulum feedback/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 */
#endif                  /* RTW_HEADER_RotaryInvertedPendulumHardwareInLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
