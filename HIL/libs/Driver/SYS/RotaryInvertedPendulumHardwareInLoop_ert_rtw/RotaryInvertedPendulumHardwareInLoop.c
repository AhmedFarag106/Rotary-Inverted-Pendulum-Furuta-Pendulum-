/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: RotaryInvertedPendulumHardwareInLoop.c
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
#include "RotaryInvertedPendulumHardwareInLoop_private.h"
#include "rt_nonfinite.h"
#include <math.h>
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
  real_T rtb_Gain1;
  real_T rtb_Gain1_o;
  real_T rtb_Integrator;
  real_T rtb_Integrator_d;
  real_T tmp;
  real_T u0;
  int32_T rtb_motorencoder_0;
  uint8_T tmp_0;

  /* MATLABSystem: '<S2>/motor encoder' */
  if (RotaryInvertedPendulumHardwa_DW.obj.SampleTime !=
      RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime_i) {
    RotaryInvertedPendulumHardwa_DW.obj.SampleTime =
      RotaryInvertedPendulumHardwar_P.motorencoder_SampleTime_i;
  }

  /*         %% Define output properties */
  /*  Call: int enc_output(int enc) */
  rtb_motorencoder_0 = enc_output(0.0);

  /* Gain: '<S12>/Gain1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  Gain: '<S2>/rev to degree'
   *  MATLABSystem: '<S2>/motor encoder'
   */
  rtb_Gain1 = RotaryInvertedPendulumHardwar_P.revtodegree_Gain * (real_T)
    rtb_motorencoder_0 * RotaryInvertedPendulumHardwar_P.Gain1_Gain;

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Pi'
   */
  RotaryInvertedPendulumHardwar_B.Add = rtb_Gain1 +
    RotaryInvertedPendulumHardwar_P.Pi_Value;

  /* Switch: '<S4>/Switch' */
  if (RotaryInvertedPendulumHardwar_B.Add >=
      RotaryInvertedPendulumHardwar_P.Switch_Threshold_p) {
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

  /* MATLABSystem: '<S1>/motor encoder' */
  /*         %% Define output properties */
  /*  Call: int enc_output(int enc) */
  RotaryInvertedPendulumHardwar_B.motorencoder = enc_output(1.0);

  /* Gain: '<S5>/Gain1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  Gain: '<S1>/rev to degree'
   */
  rtb_Gain1_o = RotaryInvertedPendulumHardwar_P.revtodegree_Gain_j * (real_T)
    RotaryInvertedPendulumHardwar_B.motorencoder *
    RotaryInvertedPendulumHardwar_P.Gain1_Gain_d;

  /* Gain: '<S7>/Minimum sampling to time constant ratio' */
  rtb_Integrator_d =
    RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_l *
    RotaryInvertedPendulumHardwar_B.Probe[0];

  /* MinMax: '<S7>/MinMax' incorporates:
   *  Constant: '<S7>/Time constant'
   */
  if ((!(rtb_Integrator_d >=
         RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_d)) &&
      (!rtIsNaN(RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_d)))
  {
    rtb_Integrator_d =
      RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_d;
  }

  /* End of MinMax: '<S7>/MinMax' */

  /* DiscreteIntegrator: '<S11>/Integrator' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (RotaryInvertedPendulumHardwa_DW.Integrator_IC_LOADING != 0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE = rtb_Gain1_o;
    if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE >
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE =
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat;
    } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE <
               RotaryInvertedPendulumHardwar_P.Integrator_LowerSat) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE =
        RotaryInvertedPendulumHardwar_P.Integrator_LowerSat;
    }
  }

  if ((RotaryInvertedPendulumHardwar_P.Constant_Value_g != 0.0) ||
      (RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState != 0)) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE = rtb_Gain1_o;
    if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE >
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE =
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat;
    } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE <
               RotaryInvertedPendulumHardwar_P.Integrator_LowerSat) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE =
        RotaryInvertedPendulumHardwar_P.Integrator_LowerSat;
    }
  }

  /* Saturate: '<S11>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S11>/Integrator'
   */
  if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE >
      RotaryInvertedPendulumHardwar_P.Saturation_UpperSat) {
    tmp = RotaryInvertedPendulumHardwar_P.Saturation_UpperSat;
  } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE <
             RotaryInvertedPendulumHardwar_P.Saturation_LowerSat) {
    tmp = RotaryInvertedPendulumHardwar_P.Saturation_LowerSat;
  } else {
    tmp = RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE;
  }

  /* Product: '<S6>/1//T' incorporates:
   *  Fcn: '<S7>/Avoid Divide by Zero'
   *  Saturate: '<S11>/Saturation'
   *  Sum: '<S6>/Sum1'
   */
  rtb_Integrator_d = 1.0 / ((real_T)(rtb_Integrator_d == 0.0) *
    2.2204460492503131e-16 + rtb_Integrator_d) * (rtb_Gain1_o - tmp);

  /* Gain: '<S14>/Minimum sampling to time constant ratio' */
  rtb_Integrator =
    RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteor_hb *
    RotaryInvertedPendulumHardwar_B.Probe_m[0];

  /* MinMax: '<S14>/MinMax' incorporates:
   *  Constant: '<S14>/Time constant'
   */
  if ((!(rtb_Integrator >=
         RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_a)) &&
      (!rtIsNaN(RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_a)))
  {
    rtb_Integrator =
      RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_a;
  }

  /* End of MinMax: '<S14>/MinMax' */

  /* DiscreteIntegrator: '<S18>/Integrator' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (RotaryInvertedPendulumHardwa_DW.Integrator_IC_LOADING_m != 0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g = rtb_Gain1;
    if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g >
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g =
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d;
    } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g <
               RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g =
        RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m;
    }
  }

  if ((RotaryInvertedPendulumHardwar_P.Constant_Value_p != 0.0) ||
      (RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState_f != 0)) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g = rtb_Gain1;
    if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g >
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g =
        RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d;
    } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g <
               RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m) {
      RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g =
        RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m;
    }
  }

  /* Saturate: '<S18>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator'
   */
  if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g >
      RotaryInvertedPendulumHardwar_P.Saturation_UpperSat_j) {
    tmp = RotaryInvertedPendulumHardwar_P.Saturation_UpperSat_j;
  } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g <
             RotaryInvertedPendulumHardwar_P.Saturation_LowerSat_e) {
    tmp = RotaryInvertedPendulumHardwar_P.Saturation_LowerSat_e;
  } else {
    tmp = RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g;
  }

  /* Product: '<S13>/1//T' incorporates:
   *  Fcn: '<S14>/Avoid Divide by Zero'
   *  Saturate: '<S18>/Saturation'
   *  Sum: '<S13>/Sum1'
   */
  rtb_Gain1 = 1.0 / ((real_T)(rtb_Integrator == 0.0) * 2.2204460492503131e-16 +
                     rtb_Integrator) * (rtb_Gain1 - tmp);

  /* Switch: '<Root>/Switch' incorporates:
   *  Abs: '<Root>/Abs'
   */
  if (fabs(RotaryInvertedPendulumHardwar_B.Switch) >
      RotaryInvertedPendulumHardwar_P.Switch_Threshold_m) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    RotaryInvertedPendulumHardwar_B.Switch_b =
      RotaryInvertedPendulumHardwar_P.Constant_Value;
  } else {
    /* Gain: '<S6>/Gain' */
    rtb_Integrator =
      RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteor_fa *
      rtb_Integrator_d;

    /* Gain: '<S13>/Gain' */
    u0 = RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteor_hx *
      rtb_Gain1;

    /* Switch: '<S3>/Switch' incorporates:
     *  Bias: '<S3>/Bias'
     *  Bias: '<S3>/Bias1'
     *  Bias: '<S3>/Bias2'
     *  Bias: '<S3>/Bias3'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  Math: '<S3>/Rem'
     *  Math: '<S3>/Rem1'
     */
    if (rtb_Gain1_o > RotaryInvertedPendulumHardwar_P.Switch_Threshold) {
      tmp = rt_remd_snf(rtb_Gain1_o + RotaryInvertedPendulumHardwar_P.Bias_Bias,
                        RotaryInvertedPendulumHardwar_P.Constant_Value_e) +
        RotaryInvertedPendulumHardwar_P.Bias1_Bias;
    } else {
      tmp = rt_remd_snf(rtb_Gain1_o + RotaryInvertedPendulumHardwar_P.Bias2_Bias,
                        RotaryInvertedPendulumHardwar_P.Constant1_Value) +
        RotaryInvertedPendulumHardwar_P.Bias3_Bias;
    }

    /* Saturate: '<S6>/[A,B]' */
    if (rtb_Integrator >
        RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_f) {
      rtb_Integrator =
        RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_f;
    } else if (rtb_Integrator <
               RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorCon)
    {
      rtb_Integrator =
        RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorCon;
    }

    /* Saturate: '<S13>/[A,B]' */
    if (u0 > RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_h) {
      u0 = RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_h;
    } else if (u0 <
               RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_n)
    {
      u0 = RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_n;
    }

    /* Switch: '<Root>/Switch' incorporates:
     *  Gain: '<Root>/Gain'
     *  Gain: '<Root>/Gain1'
     *  Saturate: '<S13>/[A,B]'
     *  Saturate: '<S6>/[A,B]'
     *  SignalConversion generated from: '<Root>/Gain1'
     *  Switch: '<S3>/Switch'
     */
    RotaryInvertedPendulumHardwar_B.Switch_b =
      (((-RotaryInvertedPendulumHardwar_P.K[0] * tmp +
         -RotaryInvertedPendulumHardwar_P.K[1] *
         RotaryInvertedPendulumHardwar_B.Switch) +
        -RotaryInvertedPendulumHardwar_P.K[2] * rtb_Integrator) +
       -RotaryInvertedPendulumHardwar_P.K[3] * u0) *
      RotaryInvertedPendulumHardwar_P.Gain_Gain;
  }

  /* End of Switch: '<Root>/Switch' */
  /* Saturate: '<S1>/Saturation' */
  if (RotaryInvertedPendulumHardwar_B.Switch_b >
      RotaryInvertedPendulumHardwar_P.Saturation_UpperSat_p) {
    rtb_Gain1_o = RotaryInvertedPendulumHardwar_P.Saturation_UpperSat_p;
  } else if (RotaryInvertedPendulumHardwar_B.Switch_b <
             RotaryInvertedPendulumHardwar_P.Saturation_LowerSat_j) {
    rtb_Gain1_o = RotaryInvertedPendulumHardwar_P.Saturation_LowerSat_j;
  } else {
    rtb_Gain1_o = RotaryInvertedPendulumHardwar_B.Switch_b;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Signum: '<S1>/check input sign' */
  if (rtIsNaN(rtb_Gain1_o)) {
    rtb_Integrator = (rtNaN);
  } else if (rtb_Gain1_o < 0.0) {
    rtb_Integrator = -1.0;
  } else {
    rtb_Integrator = (rtb_Gain1_o > 0.0);
  }

  /* End of Signum: '<S1>/check input sign' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  if (rtb_Integrator >= RotaryInvertedPendulumHardwar_P.Switch_Threshold_p2) {
    tmp = RotaryInvertedPendulumHardwar_P.Constant_Value_a;
  } else {
    tmp = RotaryInvertedPendulumHardwar_P.Constant1_Value_e;
  }

  /* MATLABSystem: '<S1>/Digital Output' incorporates:
   *  Switch: '<S1>/Switch'
   */
  tmp = rt_roundd_snf(tmp);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_0);

  /* End of MATLABSystem: '<S1>/Digital Output' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  if (rtb_Integrator >= RotaryInvertedPendulumHardwar_P.Switch1_Threshold) {
    tmp = RotaryInvertedPendulumHardwar_P.Constant1_Value_e;
  } else {
    tmp = RotaryInvertedPendulumHardwar_P.Constant_Value_a;
  }

  /* MATLABSystem: '<S1>/Digital Output1' incorporates:
   *  Switch: '<S1>/Switch1'
   */
  tmp = rt_roundd_snf(tmp);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<S1>/Digital Output1' */

  /* MATLABSystem: '<S1>/PWM' */
  RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(6UL);

  /* Abs: '<S1>/remove any negative pwm sign' */
  rtb_Integrator = fabs(rtb_Gain1_o);

  /* Start for MATLABSystem: '<S1>/PWM' */
  if (!(rtb_Integrator <= 255.0)) {
    rtb_Integrator = 255.0;
  }

  /* MATLABSystem: '<S1>/PWM' */
  MW_PWM_SetDutyCycle
    (RotaryInvertedPendulumHardwa_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Integrator);

  /* Update for DiscreteIntegrator: '<S11>/Integrator' incorporates:
   *  Constant: '<S6>/Constant'
   */
  RotaryInvertedPendulumHardwa_DW.Integrator_IC_LOADING = 0U;
  RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE +=
    RotaryInvertedPendulumHardwar_P.Integrator_gainval * rtb_Integrator_d;
  if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE >
      RotaryInvertedPendulumHardwar_P.Integrator_UpperSat) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE =
      RotaryInvertedPendulumHardwar_P.Integrator_UpperSat;
  } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE <
             RotaryInvertedPendulumHardwar_P.Integrator_LowerSat) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE =
      RotaryInvertedPendulumHardwar_P.Integrator_LowerSat;
  }

  if (RotaryInvertedPendulumHardwar_P.Constant_Value_g > 0.0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState = 1;
  } else if (RotaryInvertedPendulumHardwar_P.Constant_Value_g < 0.0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState = -1;
  } else if (RotaryInvertedPendulumHardwar_P.Constant_Value_g == 0.0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState = 0;
  } else {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Integrator' */

  /* Update for DiscreteIntegrator: '<S18>/Integrator' incorporates:
   *  Constant: '<S13>/Constant'
   */
  RotaryInvertedPendulumHardwa_DW.Integrator_IC_LOADING_m = 0U;
  RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g +=
    RotaryInvertedPendulumHardwar_P.Integrator_gainval_n * rtb_Gain1;
  if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g >
      RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g =
      RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d;
  } else if (RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g <
             RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m) {
    RotaryInvertedPendulumHardwa_DW.Integrator_DSTATE_g =
      RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m;
  }

  if (RotaryInvertedPendulumHardwar_P.Constant_Value_p > 0.0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState_f = 1;
  } else if (RotaryInvertedPendulumHardwar_P.Constant_Value_p < 0.0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState_f = -1;
  } else if (RotaryInvertedPendulumHardwar_P.Constant_Value_p == 0.0) {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState_f = 0;
  } else {
    RotaryInvertedPendulumHardwa_DW.Integrator_PrevResetState_f = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S18>/Integrator' */
  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  RotaryInvertedPendulumHardwa_M->Timing.taskTime0 =
    ((time_T)(++RotaryInvertedPendulumHardwa_M->Timing.clockTick0)) *
    RotaryInvertedPendulumHardwa_M->Timing.stepSize0;
}

/* Model initialize function */
void RotaryInvertedPendulumHardwareInLoop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorCon = rtMinusInf;
  RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_n = rtMinusInf;
  RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_f = rtInf;
  RotaryInvertedPendulumHardwar_P.FilteredDerivativeDiscreteorC_h = rtInf;
  RotaryInvertedPendulumHardwar_P.Integrator_UpperSat = rtInf;
  RotaryInvertedPendulumHardwar_P.Integrator_LowerSat = rtMinusInf;
  RotaryInvertedPendulumHardwar_P.Saturation_UpperSat = rtInf;
  RotaryInvertedPendulumHardwar_P.Saturation_LowerSat = rtMinusInf;
  RotaryInvertedPendulumHardwar_P.Integrator_UpperSat_d = rtInf;
  RotaryInvertedPendulumHardwar_P.Integrator_LowerSat_m = rtMinusInf;
  RotaryInvertedPendulumHardwar_P.Saturation_UpperSat_j = rtInf;
  RotaryInvertedPendulumHardwar_P.Saturation_LowerSat_e = rtMinusInf;
  rtmSetTFinal(RotaryInvertedPendulumHardwa_M, -1);
  RotaryInvertedPendulumHardwa_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[0] = (2785237523U);
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[1] = (2850261655U);
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[2] = (1431256616U);
  RotaryInvertedPendulumHardwa_M->Sizes.checksums[3] = (2312797967U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
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
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RotaryInvertedPendulumHardwa_M->extModeInfo,
      &RotaryInvertedPendulumHardwa_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RotaryInvertedPendulumHardwa_M->extModeInfo,
                        RotaryInvertedPendulumHardwa_M->Sizes.checksums);
    rteiSetTPtr(RotaryInvertedPendulumHardwa_M->extModeInfo, rtmGetTPtr
                (RotaryInvertedPendulumHardwa_M));
  }

  /* Start for Probe: '<S7>/Probe' */
  RotaryInvertedPendulumHardwar_B.Probe[0] = 0.001;
  RotaryInvertedPendulumHardwar_B.Probe[1] = 0.0;

  /* Start for Probe: '<S14>/Probe' */
  RotaryInvertedPendulumHardwar_B.Probe_m[0] = 0.001;
  RotaryInvertedPendulumHardwar_B.Probe_m[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Integrator' */
  RotaryInvertedPendulumHardwa_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Integrator' */
  RotaryInvertedPendulumHardwa_DW.Integrator_IC_LOADING_m = 1U;

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
