/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: RotaryInvertedPendulumHardwareInLoop.c
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
#include "RotaryInvertedPendulumHardwareInLoop_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals (default storage) */
B_RotaryInvertedPendulumHardw_T RotaryInvertedPendulumHardwar_B;

/* Block states (default storage) */
DW_RotaryInvertedPendulumHard_T RotaryInvertedPendulumHardwa_DW;

/* Real-time model */
static RT_MODEL_RotaryInvertedPendul_T RotaryInvertedPendulumHardwa_M_;
RT_MODEL_RotaryInvertedPendul_T *const RotaryInvertedPendulumHardwa_M =
  &RotaryInvertedPendulumHardwa_M_;
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
void RotaryInvertedPendulumHardwareInLoop_step(void)
{
  {
    real_T rtb_Derivative;
    real_T rtb_Derivative_e;
    real_T rtb_checkinputsign;
    real_T *lastU;
    int32_T rtb_motorencoder_0;
    uint8_T tmp;

    /* MATLABSystem: '<S2>/motor encoder' */
    if (RotaryInvertedPendulumHardwa_DW.obj.SampleTime !=
        RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime_i) {
      RotaryInvertedPendulumHardwa_DW.obj.SampleTime =
        RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime_i;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_motorencoder_0 = enc_output(0.0);

    /* Gain: '<S13>/Gain1' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion1'
     *  Gain: '<S2>/rev to degree'
     *  MATLABSystem: '<S2>/motor encoder'
     */
    RotaryInvertedPendulumHardwar_B.Gain1 =
      RotaryInvertedPendulumHardwar_P.revtodegree_Gain * (real_T)
      rtb_motorencoder_0 * RotaryInvertedPendulumHardwar_P.Gain1_Gain;

    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Pi'
     */
    RotaryInvertedPendulumHardwar_B.Add = RotaryInvertedPendulumHardwar_B.Gain1
      + RotaryInvertedPendulumHardwar_P.Pi_Value;

    /* Switch: '<S4>/Switch' */
    if (RotaryInvertedPendulumHardwar_B.Add >=
        RotaryInvertedPendulumHardwar_P.Switch_Threshold) {
      /* Switch: '<S4>/Switch' incorporates:
       *  Bias: '<S4>/Bias'
       *  Bias: '<S4>/Bias1'
       *  Constant: '<S4>/Constant'
       *  Math: '<S4>/Rem'
       */
      RotaryInvertedPendulumHardwar_B.Switch = rt_remd_snf
        (RotaryInvertedPendulumHardwar_B.Add +
         RotaryInvertedPendulumHardwar_P.Bias_Bias_m,
         RotaryInvertedPendulumHardwar_P.Constant_Value_b) +
        RotaryInvertedPendulumHardwar_P.Bias1_Bias_e;
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Bias: '<S4>/Bias2'
       *  Bias: '<S4>/Bias3'
       *  Constant: '<S4>/Constant1'
       *  Math: '<S4>/Rem1'
       */
      RotaryInvertedPendulumHardwar_B.Switch = rt_remd_snf
        (RotaryInvertedPendulumHardwar_B.Add +
         RotaryInvertedPendulumHardwar_P.Bias2_Bias_j,
         RotaryInvertedPendulumHardwar_P.Constant1_Value_p) +
        RotaryInvertedPendulumHardwar_P.Bias3_Bias_i;
    }

    /* End of Switch: '<S4>/Switch' */

    /* MATLABSystem: '<S1>/motor encoder' */
    if (RotaryInvertedPendulumHardwa_DW.obj_l.SampleTime !=
        RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime) {
      RotaryInvertedPendulumHardwa_DW.obj_l.SampleTime =
        RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_motorencoder_0 = enc_output(1.0);

    /* Gain: '<S1>/rev to degree' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  MATLABSystem: '<S1>/motor encoder'
     */
    RotaryInvertedPendulumHardwar_B.revtodegree =
      RotaryInvertedPendulumHardwar_P.revtodegree_Gain_j * (real_T)
      rtb_motorencoder_0;

    /* Gain: '<S5>/Gain1' */
    RotaryInvertedPendulumHardwar_B.Gain1_l =
      RotaryInvertedPendulumHardwar_P.Gain1_Gain_d *
      RotaryInvertedPendulumHardwar_B.revtodegree;

    /* DataTypeConversion: '<S1>/Data Type Conversion3' */
    RotaryInvertedPendulumHardwar_B.DataTypeConversion3 =
      RotaryInvertedPendulumHardwar_B.Gain1_l;

    /* Switch: '<S3>/Switch' */
    if (RotaryInvertedPendulumHardwar_B.DataTypeConversion3 >
        RotaryInvertedPendulumHardwar_P.Switch_Threshold_c) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Bias: '<S3>/Bias'
       *  Bias: '<S3>/Bias1'
       *  Constant: '<S3>/Constant'
       *  Math: '<S3>/Rem'
       */
      RotaryInvertedPendulumHardwar_B.Switch_f = rt_remd_snf
        (RotaryInvertedPendulumHardwar_B.DataTypeConversion3 +
         RotaryInvertedPendulumHardwar_P.Bias_Bias,
         RotaryInvertedPendulumHardwar_P.Constant_Value) +
        RotaryInvertedPendulumHardwar_P.Bias1_Bias;
    } else {
      /* Switch: '<S3>/Switch' incorporates:
       *  Bias: '<S3>/Bias2'
       *  Bias: '<S3>/Bias3'
       *  Constant: '<S3>/Constant1'
       *  Math: '<S3>/Rem1'
       */
      RotaryInvertedPendulumHardwar_B.Switch_f = rt_remd_snf
        (RotaryInvertedPendulumHardwar_B.DataTypeConversion3 +
         RotaryInvertedPendulumHardwar_P.Bias2_Bias,
         RotaryInvertedPendulumHardwar_P.Constant1_Value) +
        RotaryInvertedPendulumHardwar_P.Bias3_Bias;
    }

    /* End of Switch: '<S3>/Switch' */

    /* Derivative: '<S1>/Derivative' incorporates:
     *  Derivative: '<S2>/Derivative'
     */
    rtb_Derivative_e = RotaryInvertedPendulumHardwa_M->Timing.t[0];
    if ((RotaryInvertedPendulumHardwa_DW.TimeStampA >= rtb_Derivative_e) &&
        (RotaryInvertedPendulumHardwa_DW.TimeStampB >= rtb_Derivative_e)) {
      rtb_Derivative = 0.0;
    } else {
      rtb_checkinputsign = RotaryInvertedPendulumHardwa_DW.TimeStampA;
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeA;
      if (RotaryInvertedPendulumHardwa_DW.TimeStampA <
          RotaryInvertedPendulumHardwa_DW.TimeStampB) {
        if (RotaryInvertedPendulumHardwa_DW.TimeStampB < rtb_Derivative_e) {
          rtb_checkinputsign = RotaryInvertedPendulumHardwa_DW.TimeStampB;
          lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB;
        }
      } else if (RotaryInvertedPendulumHardwa_DW.TimeStampA >= rtb_Derivative_e)
      {
        rtb_checkinputsign = RotaryInvertedPendulumHardwa_DW.TimeStampB;
        lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB;
      }

      rtb_Derivative = (RotaryInvertedPendulumHardwar_B.Gain1_l - *lastU) /
        (rtb_Derivative_e - rtb_checkinputsign);
    }

    /* End of Derivative: '<S1>/Derivative' */

    /* Derivative: '<S2>/Derivative' */
    if ((RotaryInvertedPendulumHardwa_DW.TimeStampA_i >= rtb_Derivative_e) &&
        (RotaryInvertedPendulumHardwa_DW.TimeStampB_j >= rtb_Derivative_e)) {
      rtb_Derivative_e = 0.0;
    } else {
      rtb_checkinputsign = RotaryInvertedPendulumHardwa_DW.TimeStampA_i;
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeA_f;
      if (RotaryInvertedPendulumHardwa_DW.TimeStampA_i <
          RotaryInvertedPendulumHardwa_DW.TimeStampB_j) {
        if (RotaryInvertedPendulumHardwa_DW.TimeStampB_j < rtb_Derivative_e) {
          rtb_checkinputsign = RotaryInvertedPendulumHardwa_DW.TimeStampB_j;
          lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB_a;
        }
      } else if (RotaryInvertedPendulumHardwa_DW.TimeStampA_i >=
                 rtb_Derivative_e) {
        rtb_checkinputsign = RotaryInvertedPendulumHardwa_DW.TimeStampB_j;
        lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB_a;
      }

      rtb_Derivative_e = (RotaryInvertedPendulumHardwar_B.Gain1 - *lastU) /
        (rtb_Derivative_e - rtb_checkinputsign);
    }

    /* Switch: '<Root>/Switch' incorporates:
     *  Abs: '<Root>/Abs'
     */
    if (fabs(RotaryInvertedPendulumHardwar_B.Switch) >
        RotaryInvertedPendulumHardwar_P.Switch_Threshold_m) {
      /* Switch: '<Root>/Switch' incorporates:
       *  Constant: '<Root>/Constant'
       */
      RotaryInvertedPendulumHardwar_B.Switch_b =
        RotaryInvertedPendulumHardwar_P.Constant_Value_k;
    } else {
      /* Switch: '<Root>/Switch' incorporates:
       *  Gain: '<Root>/Gain'
       *  Gain: '<Root>/Gain1'
       *  SignalConversion generated from: '<Root>/Gain1'
       */
      RotaryInvertedPendulumHardwar_B.Switch_b =
        (((-RotaryInvertedPendulumHardwar_P.k[0] *
           RotaryInvertedPendulumHardwar_B.Switch_f +
           -RotaryInvertedPendulumHardwar_P.k[1] *
           RotaryInvertedPendulumHardwar_B.Switch) +
          -RotaryInvertedPendulumHardwar_P.k[2] * rtb_Derivative) +
         -RotaryInvertedPendulumHardwar_P.k[3] * rtb_Derivative_e) *
        RotaryInvertedPendulumHardwar_P.Gain_Gain;
    }

    /* End of Switch: '<Root>/Switch' */
    /* Gain: '<S1>/Scaling' */
    rtb_Derivative = RotaryInvertedPendulumHardwar_P.Scaling_Gain *
      RotaryInvertedPendulumHardwar_B.Switch_b;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Derivative > RotaryInvertedPendulumHardwar_P.Saturation_UpperSat) {
      rtb_Derivative = RotaryInvertedPendulumHardwar_P.Saturation_UpperSat;
    } else if (rtb_Derivative <
               RotaryInvertedPendulumHardwar_P.Saturation_LowerSat) {
      rtb_Derivative = RotaryInvertedPendulumHardwar_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Signum: '<S1>/check input sign' */
    if (rtIsNaN(rtb_Derivative)) {
      rtb_checkinputsign = (rtNaN);
    } else if (rtb_Derivative < 0.0) {
      rtb_checkinputsign = -1.0;
    } else {
      rtb_checkinputsign = (rtb_Derivative > 0.0);
    }

    /* End of Signum: '<S1>/check input sign' */

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     */
    if (rtb_checkinputsign >= RotaryInvertedPendulumHardwar_P.Switch_Threshold_p)
    {
      rtb_Derivative_e = RotaryInvertedPendulumHardwar_P.Constant_Value_a;
    } else {
      rtb_Derivative_e = RotaryInvertedPendulumHardwar_P.Constant1_Value_e;
    }

    /* MATLABSystem: '<S1>/Digital Output' incorporates:
     *  Switch: '<S1>/Switch'
     */
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

    writeDigitalPin(7, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output' */

    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     */
    if (rtb_checkinputsign >= RotaryInvertedPendulumHardwar_P.Switch1_Threshold)
    {
      rtb_Derivative_e = RotaryInvertedPendulumHardwar_P.Constant1_Value_e;
    } else {
      rtb_Derivative_e = RotaryInvertedPendulumHardwar_P.Constant_Value_a;
    }

    /* MATLABSystem: '<S1>/Digital Output1' incorporates:
     *  Switch: '<S1>/Switch1'
     */
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

    /* End of MATLABSystem: '<S1>/Digital Output1' */

    /* Abs: '<S1>/remove any negative pwm sign' */
    RotaryInvertedPendulumHardwar_B.removeanynegativepwmsign = fabs
      (rtb_Derivative);

    /* MATLABSystem: '<S1>/PWM' */
    RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(6UL);

    /* Start for MATLABSystem: '<S1>/PWM' */
    if (RotaryInvertedPendulumHardwar_B.removeanynegativepwmsign <= 255.0) {
      rtb_Derivative_e =
        RotaryInvertedPendulumHardwar_B.removeanynegativepwmsign;
    } else {
      rtb_Derivative_e = 255.0;
    }

    if (!(rtb_Derivative_e >= 0.0)) {
      rtb_Derivative_e = 0.0;
    }

    /* MATLABSystem: '<S1>/PWM' */
    MW_PWM_SetDutyCycle
      (RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Derivative_e);
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<S1>/Derivative' */
    if (RotaryInvertedPendulumHardwa_DW.TimeStampA == (rtInf)) {
      RotaryInvertedPendulumHardwa_DW.TimeStampA =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeA;
    } else if (RotaryInvertedPendulumHardwa_DW.TimeStampB == (rtInf)) {
      RotaryInvertedPendulumHardwa_DW.TimeStampB =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB;
    } else if (RotaryInvertedPendulumHardwa_DW.TimeStampA <
               RotaryInvertedPendulumHardwa_DW.TimeStampB) {
      RotaryInvertedPendulumHardwa_DW.TimeStampA =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeA;
    } else {
      RotaryInvertedPendulumHardwa_DW.TimeStampB =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB;
    }

    *lastU = RotaryInvertedPendulumHardwar_B.Gain1_l;

    /* End of Update for Derivative: '<S1>/Derivative' */

    /* Update for Derivative: '<S2>/Derivative' */
    if (RotaryInvertedPendulumHardwa_DW.TimeStampA_i == (rtInf)) {
      RotaryInvertedPendulumHardwa_DW.TimeStampA_i =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeA_f;
    } else if (RotaryInvertedPendulumHardwa_DW.TimeStampB_j == (rtInf)) {
      RotaryInvertedPendulumHardwa_DW.TimeStampB_j =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB_a;
    } else if (RotaryInvertedPendulumHardwa_DW.TimeStampA_i <
               RotaryInvertedPendulumHardwa_DW.TimeStampB_j) {
      RotaryInvertedPendulumHardwa_DW.TimeStampA_i =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeA_f;
    } else {
      RotaryInvertedPendulumHardwa_DW.TimeStampB_j =
        RotaryInvertedPendulumHardwa_M->Timing.t[0];
      lastU = &RotaryInvertedPendulumHardwa_DW.LastUAtTimeB_a;
    }

    *lastU = RotaryInvertedPendulumHardwar_B.Gain1;

    /* End of Update for Derivative: '<S2>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((RotaryInvertedPendulumHardwa_M->Timing.clockTick0 * 1) + 0)
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
      ((RotaryInvertedPendulumHardwa_M->Timing.clockTick1 * 1) + 0)
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
  RotaryInvertedPendulumHardwa_M->Timing.t[0] =
    ((time_T)(++RotaryInvertedPendulumHardwa_M->Timing.clockTick0)) *
    RotaryInvertedPendulumHardwa_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    RotaryInvertedPendulumHardwa_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void RotaryInvertedPendulumHardwareInLoop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RotaryInvertedPendulumHardwa_M->solverInfo,
                          &RotaryInvertedPendulumHardwa_M->Timing.simTimeStep);
    rtsiSetTPtr(&RotaryInvertedPendulumHardwa_M->solverInfo, &rtmGetTPtr
                (RotaryInvertedPendulumHardwa_M));
    rtsiSetStepSizePtr(&RotaryInvertedPendulumHardwa_M->solverInfo,
                       &RotaryInvertedPendulumHardwa_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&RotaryInvertedPendulumHardwa_M->solverInfo,
                          (&rtmGetErrorStatus(RotaryInvertedPendulumHardwa_M)));
    rtsiSetRTModelPtr(&RotaryInvertedPendulumHardwa_M->solverInfo,
                      RotaryInvertedPendulumHardwa_M);
  }

  rtsiSetSimTimeStep(&RotaryInvertedPendulumHardwa_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&RotaryInvertedPendulumHardwa_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(RotaryInvertedPendulumHardwa_M,
             &RotaryInvertedPendulumHardwa_M->Timing.tArray[0]);
  rtmSetTFinal(RotaryInvertedPendulumHardwa_M, -1);
  RotaryInvertedPendulumHardwa_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[0] = (2645343875U);
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[1] = (352117144U);
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[2] = (4164707227U);
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[3] = (2272023372U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    RotaryInvertedPendulumHardwa_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(RotaryInvertedPendulumHardwa_M->extModeInfo,
      &RotaryInvertedPendulumHardwa_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RotaryInvertedPendulumHardwa_M->extModeInfo,
                        RotaryInvertedPendulumHardwa_M->Sizes.checksums);
    rteiSetTPtr(RotaryInvertedPendulumHardwa_M->extModeInfo, rtmGetTPtr
                (RotaryInvertedPendulumHardwa_M));
  }

  /* InitializeConditions for Derivative: '<S1>/Derivative' */
  RotaryInvertedPendulumHardwa_DW.TimeStampA = (rtInf);
  RotaryInvertedPendulumHardwa_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  RotaryInvertedPendulumHardwa_DW.TimeStampA_i = (rtInf);
  RotaryInvertedPendulumHardwa_DW.TimeStampB_j = (rtInf);

  /* Start for MATLABSystem: '<S2>/motor encoder' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  RotaryInvertedPendulumHardwa_DW.obj.matlabCodegenIsDeleted = false;

  /*  Do not generate code for sprintf */
  RotaryInvertedPendulumHardwa_DW.obj.SampleTime =
    RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime_i;
  RotaryInvertedPendulumHardwa_DW.obj.isInitialized = 1L;

  /*         %% Define output properties */
  /*  Call: void enc_init(int enc, int pinA, int pinB) */
  enc_init(0.0, 2.0, 3.0);
  RotaryInvertedPendulumHardwa_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/motor encoder' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  RotaryInvertedPendulumHardwa_DW.obj_l.matlabCodegenIsDeleted = false;

  /*  Do not generate code for sprintf */
  RotaryInvertedPendulumHardwa_DW.obj_l.SampleTime =
    RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime;
  RotaryInvertedPendulumHardwa_DW.obj_l.isInitialized = 1L;

  /*         %% Define output properties */
  /*  Call: void enc_init(int enc, int pinA, int pinB) */
  enc_init(1.0, 18.0, 19.0);
  RotaryInvertedPendulumHardwa_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  RotaryInvertedPendulumHardwa_DW.obj_i.matlabCodegenIsDeleted = false;
  RotaryInvertedPendulumHardwa_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(7, 1);
  RotaryInvertedPendulumHardwa_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Digital Output1' */
  RotaryInvertedPendulumHardwa_DW.obj_n.matlabCodegenIsDeleted = false;
  RotaryInvertedPendulumHardwa_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(8, 1);
  RotaryInvertedPendulumHardwa_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/PWM' */
  RotaryInvertedPendulumHardwa_DW.obj_m.matlabCodegenIsDeleted = false;
  RotaryInvertedPendulumHardwa_DW.obj_m.isInitialized = 1L;
  RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (6UL, 0.0, 0.0);
  RotaryInvertedPendulumHardwa_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void RotaryInvertedPendulumHardwareInLoop_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/motor encoder' */
  if (!RotaryInvertedPendulumHardwa_DW.obj.matlabCodegenIsDeleted) {
    RotaryInvertedPendulumHardwa_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/motor encoder' */

  /* Terminate for MATLABSystem: '<S1>/motor encoder' */
  if (!RotaryInvertedPendulumHardwa_DW.obj_l.matlabCodegenIsDeleted) {
    RotaryInvertedPendulumHardwa_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/motor encoder' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!RotaryInvertedPendulumHardwa_DW.obj_i.matlabCodegenIsDeleted) {
    RotaryInvertedPendulumHardwa_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!RotaryInvertedPendulumHardwa_DW.obj_n.matlabCodegenIsDeleted) {
    RotaryInvertedPendulumHardwa_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  if (!RotaryInvertedPendulumHardwa_DW.obj_m.matlabCodegenIsDeleted) {
    RotaryInvertedPendulumHardwa_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((RotaryInvertedPendulumHardwa_DW.obj_m.isInitialized == 1L) &&
        RotaryInvertedPendulumHardwa_DW.obj_m.isSetupComplete) {
      RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close
        (RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
