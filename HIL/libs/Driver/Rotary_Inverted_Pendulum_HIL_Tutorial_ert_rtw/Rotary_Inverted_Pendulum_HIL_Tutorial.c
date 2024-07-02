/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Rotary_Inverted_Pendulum_HIL_Tutorial.c
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
#include "Rotary_Inverted_Pendulum_HIL_Tutorial_private.h"
#include <math.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_Rotary_Inverted_Pendulum_HI_T Rotary_Inverted_Pendulum_HIL__B;

/* Block states (default storage) */
DW_Rotary_Inverted_Pendulum_H_T Rotary_Inverted_Pendulum_HIL_DW;

/* Real-time model */
static RT_MODEL_Rotary_Inverted_Pend_T Rotary_Inverted_Pendulum_HIL_M_;
RT_MODEL_Rotary_Inverted_Pend_T *const Rotary_Inverted_Pendulum_HIL_M =
  &Rotary_Inverted_Pendulum_HIL_M_;
real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Rotary_Inverted_Pendulum_HIL_Tutorial_step(void)
{
  {
    real_T lastTime;
    real_T rtb_Derivative;
    real_T rtb_Derivative_e;
    real_T *lastU;
    int32_T rtb_motorencoder_0;
    uint8_T tmp;

    /* MATLABSystem: '<S5>/motor encoder' */
    if (Rotary_Inverted_Pendulum_HIL_DW.obj.SampleTime !=
        Rotary_Inverted_Pendulum_HIL__P.motorencoder_SampleTime_i) {
      Rotary_Inverted_Pendulum_HIL_DW.obj.SampleTime =
        Rotary_Inverted_Pendulum_HIL__P.motorencoder_SampleTime_i;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_motorencoder_0 = enc_output(0.0);

    /* Gain: '<S9>/Gain1' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     *  Gain: '<S5>/rev to degree'
     *  MATLABSystem: '<S5>/motor encoder'
     */
    Rotary_Inverted_Pendulum_HIL__B.Gain1 =
      Rotary_Inverted_Pendulum_HIL__P.revtodegree_Gain * (real_T)
      rtb_motorencoder_0 * Rotary_Inverted_Pendulum_HIL__P.Gain1_Gain;

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Pi'
     */
    Rotary_Inverted_Pendulum_HIL__B.Add = Rotary_Inverted_Pendulum_HIL__B.Gain1
      + Rotary_Inverted_Pendulum_HIL__P.Pi_Value;

    /* Switch: '<S7>/Switch' */
    if (Rotary_Inverted_Pendulum_HIL__B.Add >=
        Rotary_Inverted_Pendulum_HIL__P.Switch_Threshold) {
      /* Switch: '<S7>/Switch' incorporates:
       *  Bias: '<S7>/Bias'
       *  Bias: '<S7>/Bias1'
       *  Constant: '<S7>/Constant'
       *  Math: '<S7>/Rem'
       */
      Rotary_Inverted_Pendulum_HIL__B.Switch = rt_remd_snf
        (Rotary_Inverted_Pendulum_HIL__B.Add +
         Rotary_Inverted_Pendulum_HIL__P.Bias_Bias_m,
         Rotary_Inverted_Pendulum_HIL__P.Constant_Value_b) +
        Rotary_Inverted_Pendulum_HIL__P.Bias1_Bias_e;
    } else {
      /* Switch: '<S7>/Switch' incorporates:
       *  Bias: '<S7>/Bias2'
       *  Bias: '<S7>/Bias3'
       *  Constant: '<S7>/Constant1'
       *  Math: '<S7>/Rem1'
       */
      Rotary_Inverted_Pendulum_HIL__B.Switch = rt_remd_snf
        (Rotary_Inverted_Pendulum_HIL__B.Add +
         Rotary_Inverted_Pendulum_HIL__P.Bias2_Bias_j,
         Rotary_Inverted_Pendulum_HIL__P.Constant1_Value_p) +
        Rotary_Inverted_Pendulum_HIL__P.Bias3_Bias_i;
    }

    /* End of Switch: '<S7>/Switch' */

    /* MATLABSystem: '<S4>/motor encoder' */
    if (Rotary_Inverted_Pendulum_HIL_DW.obj_l.SampleTime !=
        Rotary_Inverted_Pendulum_HIL__P.motorencoder_SampleTime) {
      Rotary_Inverted_Pendulum_HIL_DW.obj_l.SampleTime =
        Rotary_Inverted_Pendulum_HIL__P.motorencoder_SampleTime;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_motorencoder_0 = enc_output(1.0);

    /* Gain: '<S4>/rev to degree' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     *  MATLABSystem: '<S4>/motor encoder'
     */
    Rotary_Inverted_Pendulum_HIL__B.revtodegree =
      Rotary_Inverted_Pendulum_HIL__P.revtodegree_Gain_j * (real_T)
      rtb_motorencoder_0;

    /* Gain: '<S8>/Gain1' */
    Rotary_Inverted_Pendulum_HIL__B.Gain1_l =
      Rotary_Inverted_Pendulum_HIL__P.Gain1_Gain_d *
      Rotary_Inverted_Pendulum_HIL__B.revtodegree;

    /* DataTypeConversion: '<S4>/Data Type Conversion3' */
    Rotary_Inverted_Pendulum_HIL__B.DataTypeConversion3 =
      Rotary_Inverted_Pendulum_HIL__B.Gain1_l;

    /* Switch: '<S6>/Switch' */
    if (Rotary_Inverted_Pendulum_HIL__B.DataTypeConversion3 >
        Rotary_Inverted_Pendulum_HIL__P.Switch_Threshold_c) {
      /* Switch: '<S6>/Switch' incorporates:
       *  Bias: '<S6>/Bias'
       *  Bias: '<S6>/Bias1'
       *  Constant: '<S6>/Constant'
       *  Math: '<S6>/Rem'
       */
      Rotary_Inverted_Pendulum_HIL__B.Switch_f = rt_remd_snf
        (Rotary_Inverted_Pendulum_HIL__B.DataTypeConversion3 +
         Rotary_Inverted_Pendulum_HIL__P.Bias_Bias,
         Rotary_Inverted_Pendulum_HIL__P.Constant_Value) +
        Rotary_Inverted_Pendulum_HIL__P.Bias1_Bias;
    } else {
      /* Switch: '<S6>/Switch' incorporates:
       *  Bias: '<S6>/Bias2'
       *  Bias: '<S6>/Bias3'
       *  Constant: '<S6>/Constant1'
       *  Math: '<S6>/Rem1'
       */
      Rotary_Inverted_Pendulum_HIL__B.Switch_f = rt_remd_snf
        (Rotary_Inverted_Pendulum_HIL__B.DataTypeConversion3 +
         Rotary_Inverted_Pendulum_HIL__P.Bias2_Bias,
         Rotary_Inverted_Pendulum_HIL__P.Constant1_Value) +
        Rotary_Inverted_Pendulum_HIL__P.Bias3_Bias;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Derivative: '<S4>/Derivative' incorporates:
     *  Derivative: '<S5>/Derivative'
     */
    rtb_Derivative_e = Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
    if ((Rotary_Inverted_Pendulum_HIL_DW.TimeStampA >= rtb_Derivative_e) &&
        (Rotary_Inverted_Pendulum_HIL_DW.TimeStampB >= rtb_Derivative_e)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = Rotary_Inverted_Pendulum_HIL_DW.TimeStampA;
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeA;
      if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA <
          Rotary_Inverted_Pendulum_HIL_DW.TimeStampB) {
        if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampB < rtb_Derivative_e) {
          lastTime = Rotary_Inverted_Pendulum_HIL_DW.TimeStampB;
          lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB;
        }
      } else if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA >= rtb_Derivative_e)
      {
        lastTime = Rotary_Inverted_Pendulum_HIL_DW.TimeStampB;
        lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB;
      }

      rtb_Derivative = (Rotary_Inverted_Pendulum_HIL__B.Gain1_l - *lastU) /
        (rtb_Derivative_e - lastTime);
    }

    /* End of Derivative: '<S4>/Derivative' */

    /* Derivative: '<S5>/Derivative' */
    if ((Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i >= rtb_Derivative_e) &&
        (Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j >= rtb_Derivative_e)) {
      rtb_Derivative_e = 0.0;
    } else {
      lastTime = Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i;
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeA_f;
      if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i <
          Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j) {
        if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j < rtb_Derivative_e) {
          lastTime = Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j;
          lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB_a;
        }
      } else if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i >=
                 rtb_Derivative_e) {
        lastTime = Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j;
        lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB_a;
      }

      rtb_Derivative_e = (Rotary_Inverted_Pendulum_HIL__B.Gain1 - *lastU) /
        (rtb_Derivative_e - lastTime);
    }

    /* Switch: '<S1>/Linearity checker' incorporates:
     *  Abs: '<S1>/Abs'
     */
    if (fabs(Rotary_Inverted_Pendulum_HIL__B.Switch) >
        Rotary_Inverted_Pendulum_HIL__P.Linearitychecker_Threshold) {
      /* Switch: '<S1>/Linearity checker' incorporates:
       *  Constant: '<S1>/Constant'
       */
      Rotary_Inverted_Pendulum_HIL__B.ControlAction =
        Rotary_Inverted_Pendulum_HIL__P.Constant_Value_k;
    } else {
      /* Switch: '<S1>/Linearity checker' incorporates:
       *  Gain: '<S1>/Gain'
       *  Gain: '<S1>/Gain1'
       *  SignalConversion generated from: '<S1>/Gain1'
       */
      Rotary_Inverted_Pendulum_HIL__B.ControlAction =
        (((-Rotary_Inverted_Pendulum_HIL__P.k[0] *
           Rotary_Inverted_Pendulum_HIL__B.Switch_f +
           -Rotary_Inverted_Pendulum_HIL__P.k[1] *
           Rotary_Inverted_Pendulum_HIL__B.Switch) +
          -Rotary_Inverted_Pendulum_HIL__P.k[2] * rtb_Derivative) +
         -Rotary_Inverted_Pendulum_HIL__P.k[3] * rtb_Derivative_e) *
        Rotary_Inverted_Pendulum_HIL__P.Gain_Gain;
    }

    /* End of Switch: '<S1>/Linearity checker' */

    /* Gain: '<S3>/Scaling' */
    rtb_Derivative = Rotary_Inverted_Pendulum_HIL__P.Scaling_Gain *
      Rotary_Inverted_Pendulum_HIL__B.ControlAction;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_Derivative > Rotary_Inverted_Pendulum_HIL__P.Saturation_UpperSat) {
      rtb_Derivative = Rotary_Inverted_Pendulum_HIL__P.Saturation_UpperSat;
    } else if (rtb_Derivative <
               Rotary_Inverted_Pendulum_HIL__P.Saturation_LowerSat) {
      rtb_Derivative = Rotary_Inverted_Pendulum_HIL__P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     */
    if (rtb_Derivative >= Rotary_Inverted_Pendulum_HIL__P.Switch1_Threshold) {
      rtb_Derivative_e = Rotary_Inverted_Pendulum_HIL__P.Constant_Value_a;
    } else {
      rtb_Derivative_e = Rotary_Inverted_Pendulum_HIL__P.Constant1_Value_e;
    }

    /* End of Switch: '<S3>/Switch1' */

    /* MATLABSystem: '<S3>/Digital Output' incorporates:
     *  Logic: '<S3>/NOT'
     */
    writeDigitalPin(7, (uint8_T)!(rtb_Derivative_e != 0.0));

    /* MATLABSystem: '<S3>/Digital Output1' */
    rtb_Derivative_e = rt_roundd_snf(rtb_Derivative_e);
    if (rtb_Derivative_e < 256.0) {
      if (rtb_Derivative_e >= 0.0) {
        tmp = (uint8_T)rtb_Derivative_e;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(8, tmp);

    /* End of MATLABSystem: '<S3>/Digital Output1' */

    /* Abs: '<S3>/remove any negative pwm sign' */
    Rotary_Inverted_Pendulum_HIL__B.pwm = fabs(rtb_Derivative);

    /* MATLABSystem: '<S3>/PWM' */
    Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(6UL);

    /* Start for MATLABSystem: '<S3>/PWM' */
    if (Rotary_Inverted_Pendulum_HIL__B.pwm <= 255.0) {
      rtb_Derivative_e = Rotary_Inverted_Pendulum_HIL__B.pwm;
    } else {
      rtb_Derivative_e = 255.0;
    }

    if (!(rtb_Derivative_e >= 0.0)) {
      rtb_Derivative_e = 0.0;
    }

    /* MATLABSystem: '<S3>/PWM' */
    MW_PWM_SetDutyCycle
      (Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Derivative_e);
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<S4>/Derivative' */
    if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA == (rtInf)) {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampA =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeA;
    } else if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampB == (rtInf)) {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampB =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB;
    } else if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA <
               Rotary_Inverted_Pendulum_HIL_DW.TimeStampB) {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampA =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeA;
    } else {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampB =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB;
    }

    *lastU = Rotary_Inverted_Pendulum_HIL__B.Gain1_l;

    /* End of Update for Derivative: '<S4>/Derivative' */

    /* Update for Derivative: '<S5>/Derivative' */
    if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i == (rtInf)) {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeA_f;
    } else if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j == (rtInf)) {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB_a;
    } else if (Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i <
               Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j) {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeA_f;
    } else {
      Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j =
        Rotary_Inverted_Pendulum_HIL_M->Timing.t[0];
      lastU = &Rotary_Inverted_Pendulum_HIL_DW.LastUAtTimeB_a;
    }

    *lastU = Rotary_Inverted_Pendulum_HIL__B.Gain1;

    /* End of Update for Derivative: '<S5>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Rotary_Inverted_Pendulum_HIL_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Rotary_Inverted_Pendulum_HIL_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Rotary_Inverted_Pendulum_HIL_M->Timing.t[0] =
    ((time_T)(++Rotary_Inverted_Pendulum_HIL_M->Timing.clockTick0)) *
    Rotary_Inverted_Pendulum_HIL_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Rotary_Inverted_Pendulum_HIL_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Rotary_Inverted_Pendulum_HIL_Tutorial_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Rotary_Inverted_Pendulum_HIL_M->solverInfo,
                          &Rotary_Inverted_Pendulum_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&Rotary_Inverted_Pendulum_HIL_M->solverInfo, &rtmGetTPtr
                (Rotary_Inverted_Pendulum_HIL_M));
    rtsiSetStepSizePtr(&Rotary_Inverted_Pendulum_HIL_M->solverInfo,
                       &Rotary_Inverted_Pendulum_HIL_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Rotary_Inverted_Pendulum_HIL_M->solverInfo,
                          (&rtmGetErrorStatus(Rotary_Inverted_Pendulum_HIL_M)));
    rtsiSetRTModelPtr(&Rotary_Inverted_Pendulum_HIL_M->solverInfo,
                      Rotary_Inverted_Pendulum_HIL_M);
  }

  rtsiSetSimTimeStep(&Rotary_Inverted_Pendulum_HIL_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Rotary_Inverted_Pendulum_HIL_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Rotary_Inverted_Pendulum_HIL_M,
             &Rotary_Inverted_Pendulum_HIL_M->Timing.tArray[0]);
  rtmSetTFinal(Rotary_Inverted_Pendulum_HIL_M, -1);
  Rotary_Inverted_Pendulum_HIL_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Rotary_Inverted_Pendulum_HIL_M->Sizes.checksums[0] = (1926573048U);
  Rotary_Inverted_Pendulum_HIL_M->Sizes.checksums[1] = (3329457791U);
  Rotary_Inverted_Pendulum_HIL_M->Sizes.checksums[2] = (3999236048U);
  Rotary_Inverted_Pendulum_HIL_M->Sizes.checksums[3] = (2450392545U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    Rotary_Inverted_Pendulum_HIL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Rotary_Inverted_Pendulum_HIL_M->extModeInfo,
      &Rotary_Inverted_Pendulum_HIL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Rotary_Inverted_Pendulum_HIL_M->extModeInfo,
                        Rotary_Inverted_Pendulum_HIL_M->Sizes.checksums);
    rteiSetTPtr(Rotary_Inverted_Pendulum_HIL_M->extModeInfo, rtmGetTPtr
                (Rotary_Inverted_Pendulum_HIL_M));
  }

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  Rotary_Inverted_Pendulum_HIL_DW.TimeStampA = (rtInf);
  Rotary_Inverted_Pendulum_HIL_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  Rotary_Inverted_Pendulum_HIL_DW.TimeStampA_i = (rtInf);
  Rotary_Inverted_Pendulum_HIL_DW.TimeStampB_j = (rtInf);

  /* Start for MATLABSystem: '<S5>/motor encoder' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  Rotary_Inverted_Pendulum_HIL_DW.obj.matlabCodegenIsDeleted = false;

  /*  Do not generate code for sprintf */
  Rotary_Inverted_Pendulum_HIL_DW.obj.SampleTime =
    Rotary_Inverted_Pendulum_HIL__P.motorencoder_SampleTime_i;
  Rotary_Inverted_Pendulum_HIL_DW.obj.isInitialized = 1L;

  /*         %% Define output properties */
  /*  Call: void enc_init(int enc, int pinA, int pinB) */
  enc_init(0.0, 2.0, 3.0);
  Rotary_Inverted_Pendulum_HIL_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/motor encoder' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  Rotary_Inverted_Pendulum_HIL_DW.obj_l.matlabCodegenIsDeleted = false;

  /*  Do not generate code for sprintf */
  Rotary_Inverted_Pendulum_HIL_DW.obj_l.SampleTime =
    Rotary_Inverted_Pendulum_HIL__P.motorencoder_SampleTime;
  Rotary_Inverted_Pendulum_HIL_DW.obj_l.isInitialized = 1L;

  /*         %% Define output properties */
  /*  Call: void enc_init(int enc, int pinA, int pinB) */
  enc_init(1.0, 18.0, 19.0);
  Rotary_Inverted_Pendulum_HIL_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output' */
  Rotary_Inverted_Pendulum_HIL_DW.obj_i.matlabCodegenIsDeleted = false;
  Rotary_Inverted_Pendulum_HIL_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(7, 1);
  Rotary_Inverted_Pendulum_HIL_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output1' */
  Rotary_Inverted_Pendulum_HIL_DW.obj_n.matlabCodegenIsDeleted = false;
  Rotary_Inverted_Pendulum_HIL_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Rotary_Inverted_Pendulum_HIL_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/PWM' */
  Rotary_Inverted_Pendulum_HIL_DW.obj_m.matlabCodegenIsDeleted = false;
  Rotary_Inverted_Pendulum_HIL_DW.obj_m.isInitialized = 1L;
  Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (6UL, 0.0, 0.0);
  Rotary_Inverted_Pendulum_HIL_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void Rotary_Inverted_Pendulum_HIL_Tutorial_terminate(void)
{
  /* Terminate for MATLABSystem: '<S5>/motor encoder' */
  if (!Rotary_Inverted_Pendulum_HIL_DW.obj.matlabCodegenIsDeleted) {
    Rotary_Inverted_Pendulum_HIL_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/motor encoder' */

  /* Terminate for MATLABSystem: '<S4>/motor encoder' */
  if (!Rotary_Inverted_Pendulum_HIL_DW.obj_l.matlabCodegenIsDeleted) {
    Rotary_Inverted_Pendulum_HIL_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/motor encoder' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!Rotary_Inverted_Pendulum_HIL_DW.obj_i.matlabCodegenIsDeleted) {
    Rotary_Inverted_Pendulum_HIL_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!Rotary_Inverted_Pendulum_HIL_DW.obj_n.matlabCodegenIsDeleted) {
    Rotary_Inverted_Pendulum_HIL_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!Rotary_Inverted_Pendulum_HIL_DW.obj_m.matlabCodegenIsDeleted) {
    Rotary_Inverted_Pendulum_HIL_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Rotary_Inverted_Pendulum_HIL_DW.obj_m.isInitialized == 1L) &&
        Rotary_Inverted_Pendulum_HIL_DW.obj_m.isSetupComplete) {
      Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close
        (Rotary_Inverted_Pendulum_HIL_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
