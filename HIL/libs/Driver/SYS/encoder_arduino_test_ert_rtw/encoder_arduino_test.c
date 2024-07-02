/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: encoder_arduino_test.c
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
#include "encoder_arduino_test_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_encoder_arduino_test_T encoder_arduino_test_B;

/* Block states (default storage) */
DW_encoder_arduino_test_T encoder_arduino_test_DW;

/* Real-time model */
static RT_MODEL_encoder_arduino_test_T encoder_arduino_test_M_;
RT_MODEL_encoder_arduino_test_T *const encoder_arduino_test_M =
  &encoder_arduino_test_M_;
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
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
void encoder_arduino_test_step(void)
{
  {
    real_T lastTime;
    real_T rtb_Abs;
    real_T rtb_theta0_dot;
    real_T *lastU;
    int32_T rtb_MATLABSystem1_0;
    uint32_T tmp;
    uint32_T tmp_0;
    int16_T tmp_2;
    uint16_T u0;
    uint8_T tmp_1;

    /* Gain: '<S3>/Gain' incorporates:
     *  Gain: '<S3>/Gain3'
     */
    encoder_arduino_test_B.Gain = encoder_arduino_test_P.Gain3_Gain;

    /* MATLABSystem: '<S3>/MATLAB System1' */
    if (encoder_arduino_test_DW.obj.SampleTime !=
        encoder_arduino_test_P.MATLABSystem1_SampleTime) {
      encoder_arduino_test_DW.obj.SampleTime =
        encoder_arduino_test_P.MATLABSystem1_SampleTime;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_MATLABSystem1_0 = enc_output(1.0);

    /* Gain: '<S3>/Gain1' incorporates:
     *  MATLABSystem: '<S3>/MATLAB System1'
     */
    tmp = (uint32_T)encoder_arduino_test_P.Gain1_Gain_j;
    tmp_0 = (uint32_T)rtb_MATLABSystem1_0;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &encoder_arduino_test_B.Gain1.chunks[0U],
                  2);

    /* Gain: '<S3>/Gain3' incorporates:
     *  Gain: '<S3>/Gain1'
     */
    sMultiWordMul(&encoder_arduino_test_P.Gain3_Gain.chunks[0U], 2,
                  &encoder_arduino_test_B.Gain1.chunks[0U], 2,
                  &encoder_arduino_test_B.r.chunks[0U], 4);

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    encoder_arduino_test_B.theta0 = sMultiWord2Double
      (&encoder_arduino_test_B.r.chunks[0U], 4, 0) * 3.944304526105059E-31;

    /* MATLABSystem: '<S3>/MATLAB System' */
    if (encoder_arduino_test_DW.obj_p.SampleTime !=
        encoder_arduino_test_P.MATLABSystem_SampleTime) {
      encoder_arduino_test_DW.obj_p.SampleTime =
        encoder_arduino_test_P.MATLABSystem_SampleTime;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_MATLABSystem1_0 = enc_output(0.0);

    /* Gain: '<S3>/Gain' incorporates:
     *  MATLABSystem: '<S3>/MATLAB System'
     */
    tmp = (uint32_T)encoder_arduino_test_P.Gain_Gain_c;
    tmp_0 = (uint32_T)rtb_MATLABSystem1_0;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &encoder_arduino_test_B.Gain.chunks[0U], 2);

    /* Gain: '<S3>/Gain2' incorporates:
     *  Gain: '<S3>/Gain'
     */
    sMultiWordMul(&encoder_arduino_test_P.Gain2_Gain.chunks[0U], 2,
                  &encoder_arduino_test_B.Gain.chunks[0U], 2,
                  &encoder_arduino_test_B.r1.chunks[0U], 4);

    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    encoder_arduino_test_B.theta1 = sMultiWord2Double
      (&encoder_arduino_test_B.r1.chunks[0U], 4, 0) * 3.944304526105059E-31;

    /* Derivative: '<S3>/Derivative' incorporates:
     *  Derivative: '<S3>/Derivative1'
     */
    rtb_Abs = encoder_arduino_test_M->Timing.t[0];
    if ((encoder_arduino_test_DW.TimeStampA >= rtb_Abs) &&
        (encoder_arduino_test_DW.TimeStampB >= rtb_Abs)) {
      rtb_theta0_dot = 0.0;
    } else {
      lastTime = encoder_arduino_test_DW.TimeStampA;
      lastU = &encoder_arduino_test_DW.LastUAtTimeA;
      if (encoder_arduino_test_DW.TimeStampA <
          encoder_arduino_test_DW.TimeStampB) {
        if (encoder_arduino_test_DW.TimeStampB < rtb_Abs) {
          lastTime = encoder_arduino_test_DW.TimeStampB;
          lastU = &encoder_arduino_test_DW.LastUAtTimeB;
        }
      } else if (encoder_arduino_test_DW.TimeStampA >= rtb_Abs) {
        lastTime = encoder_arduino_test_DW.TimeStampB;
        lastU = &encoder_arduino_test_DW.LastUAtTimeB;
      }

      rtb_theta0_dot = (encoder_arduino_test_B.theta0 - *lastU) / (rtb_Abs -
        lastTime);
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* Derivative: '<S3>/Derivative1' */
    if ((encoder_arduino_test_DW.TimeStampA_p >= rtb_Abs) &&
        (encoder_arduino_test_DW.TimeStampB_n >= rtb_Abs)) {
      rtb_Abs = 0.0;
    } else {
      lastTime = encoder_arduino_test_DW.TimeStampA_p;
      lastU = &encoder_arduino_test_DW.LastUAtTimeA_n;
      if (encoder_arduino_test_DW.TimeStampA_p <
          encoder_arduino_test_DW.TimeStampB_n) {
        if (encoder_arduino_test_DW.TimeStampB_n < rtb_Abs) {
          lastTime = encoder_arduino_test_DW.TimeStampB_n;
          lastU = &encoder_arduino_test_DW.LastUAtTimeB_e;
        }
      } else if (encoder_arduino_test_DW.TimeStampA_p >= rtb_Abs) {
        lastTime = encoder_arduino_test_DW.TimeStampB_n;
        lastU = &encoder_arduino_test_DW.LastUAtTimeB_e;
      }

      rtb_Abs = (encoder_arduino_test_B.theta1 - *lastU) / (rtb_Abs - lastTime);
    }

    /* Gain: '<S2>/Gain3' incorporates:
     *  Gain: '<S2>/Gain1'
     */
    encoder_arduino_test_B.Control_actionu = ((encoder_arduino_test_P.Gain1_Gain
      * encoder_arduino_test_B.theta0 * encoder_arduino_test_P.K[0] +
      encoder_arduino_test_P.Gain1_Gain * encoder_arduino_test_B.theta1 *
      encoder_arduino_test_P.K[1]) + encoder_arduino_test_P.Gain1_Gain *
      rtb_theta0_dot * encoder_arduino_test_P.K[2]) +
      encoder_arduino_test_P.Gain1_Gain * rtb_Abs * encoder_arduino_test_P.K[3];

    /* Gain: '<S1>/Gain' */
    encoder_arduino_test_B.Saturation = encoder_arduino_test_P.Gain_Gain *
      encoder_arduino_test_B.Control_actionu;

    /* Saturate: '<S1>/Saturation' */
    if (encoder_arduino_test_B.Saturation >
        encoder_arduino_test_P.Saturation_UpperSat) {
      /* Gain: '<S1>/Gain' incorporates:
       *  Saturate: '<S1>/Saturation'
       */
      encoder_arduino_test_B.Saturation =
        encoder_arduino_test_P.Saturation_UpperSat;
    } else if (encoder_arduino_test_B.Saturation <
               encoder_arduino_test_P.Saturation_LowerSat) {
      /* Gain: '<S1>/Gain' incorporates:
       *  Saturate: '<S1>/Saturation'
       */
      encoder_arduino_test_B.Saturation =
        encoder_arduino_test_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Gain: '<Root>/Gain' */
    encoder_arduino_test_B.Gain_f = encoder_arduino_test_P.Gain_Gain_h *
      encoder_arduino_test_B.theta1;

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     */
    if (encoder_arduino_test_B.Saturation >
        encoder_arduino_test_P.Switch_Threshold) {
      rtb_Abs = encoder_arduino_test_P.Constant_Value;
    } else {
      rtb_Abs = encoder_arduino_test_P.Constant1_Value;
    }

    /* End of Switch: '<S1>/Switch' */

    /* MATLABSystem: '<S1>/Digital Output' incorporates:
     *  Logic: '<S1>/NOT'
     */
    writeDigitalPin(8, (uint8_T)!(rtb_Abs != 0.0));

    /* MATLABSystem: '<S1>/Digital Output1' */
    rtb_Abs = rt_roundd_snf(rtb_Abs);
    if (rtb_Abs < 256.0) {
      if (rtb_Abs >= 0.0) {
        tmp_1 = (uint8_T)rtb_Abs;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(7, tmp_1);

    /* End of MATLABSystem: '<S1>/Digital Output1' */

    /* MATLABSystem: '<S1>/PWM' */
    encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (6UL);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Abs: '<S1>/Abs'
     */
    rtb_Abs = floor(fabs(encoder_arduino_test_B.Saturation));
    if (rtIsNaN(rtb_Abs) || rtIsInf(rtb_Abs)) {
      /* Start for MATLABSystem: '<S1>/PWM' */
      u0 = 0U;
    } else {
      /* Start for MATLABSystem: '<S1>/PWM' */
      u0 = (uint16_T)fmod(rtb_Abs, 65536.0);
    }

    /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

    /* Start for MATLABSystem: '<S1>/PWM' */
    if (u0 <= 255U) {
      tmp_2 = (int16_T)u0;
    } else {
      tmp_2 = 255;
    }

    /* MATLABSystem: '<S1>/PWM' */
    MW_PWM_SetDutyCycle(encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)tmp_2);
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<S3>/Derivative' */
    if (encoder_arduino_test_DW.TimeStampA == (rtInf)) {
      encoder_arduino_test_DW.TimeStampA = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeA;
    } else if (encoder_arduino_test_DW.TimeStampB == (rtInf)) {
      encoder_arduino_test_DW.TimeStampB = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeB;
    } else if (encoder_arduino_test_DW.TimeStampA <
               encoder_arduino_test_DW.TimeStampB) {
      encoder_arduino_test_DW.TimeStampA = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeA;
    } else {
      encoder_arduino_test_DW.TimeStampB = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeB;
    }

    *lastU = encoder_arduino_test_B.theta0;

    /* End of Update for Derivative: '<S3>/Derivative' */

    /* Update for Derivative: '<S3>/Derivative1' */
    if (encoder_arduino_test_DW.TimeStampA_p == (rtInf)) {
      encoder_arduino_test_DW.TimeStampA_p = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeA_n;
    } else if (encoder_arduino_test_DW.TimeStampB_n == (rtInf)) {
      encoder_arduino_test_DW.TimeStampB_n = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeB_e;
    } else if (encoder_arduino_test_DW.TimeStampA_p <
               encoder_arduino_test_DW.TimeStampB_n) {
      encoder_arduino_test_DW.TimeStampA_p = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeA_n;
    } else {
      encoder_arduino_test_DW.TimeStampB_n = encoder_arduino_test_M->Timing.t[0];
      lastU = &encoder_arduino_test_DW.LastUAtTimeB_e;
    }

    *lastU = encoder_arduino_test_B.theta1;

    /* End of Update for Derivative: '<S3>/Derivative1' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((encoder_arduino_test_M->Timing.clockTick0 * 1) + 0)
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
      ((encoder_arduino_test_M->Timing.clockTick1 * 1) + 0)
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
  encoder_arduino_test_M->Timing.t[0] =
    ((time_T)(++encoder_arduino_test_M->Timing.clockTick0)) *
    encoder_arduino_test_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    encoder_arduino_test_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void encoder_arduino_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&encoder_arduino_test_M->solverInfo,
                          &encoder_arduino_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&encoder_arduino_test_M->solverInfo, &rtmGetTPtr
                (encoder_arduino_test_M));
    rtsiSetStepSizePtr(&encoder_arduino_test_M->solverInfo,
                       &encoder_arduino_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&encoder_arduino_test_M->solverInfo,
                          (&rtmGetErrorStatus(encoder_arduino_test_M)));
    rtsiSetRTModelPtr(&encoder_arduino_test_M->solverInfo,
                      encoder_arduino_test_M);
  }

  rtsiSetSimTimeStep(&encoder_arduino_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&encoder_arduino_test_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(encoder_arduino_test_M, &encoder_arduino_test_M->Timing.tArray[0]);
  rtmSetTFinal(encoder_arduino_test_M, -1);
  encoder_arduino_test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  encoder_arduino_test_M->Sizes.checksums[0] = (1335390093U);
  encoder_arduino_test_M->Sizes.checksums[1] = (3150276536U);
  encoder_arduino_test_M->Sizes.checksums[2] = (2454341576U);
  encoder_arduino_test_M->Sizes.checksums[3] = (1348097965U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    encoder_arduino_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(encoder_arduino_test_M->extModeInfo,
      &encoder_arduino_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(encoder_arduino_test_M->extModeInfo,
                        encoder_arduino_test_M->Sizes.checksums);
    rteiSetTPtr(encoder_arduino_test_M->extModeInfo, rtmGetTPtr
                (encoder_arduino_test_M));
  }

  /* Start for MATLABSystem: '<S3>/MATLAB System1' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  encoder_arduino_test_DW.obj.matlabCodegenIsDeleted = false;

  /*  Do not generate code for sprintf */
  encoder_arduino_test_DW.obj.SampleTime =
    encoder_arduino_test_P.MATLABSystem1_SampleTime;
  encoder_arduino_test_DW.obj.isInitialized = 1L;

  /*         %% Define output properties */
  /*  Call: void enc_init(int enc, int pinA, int pinB) */
  enc_init(1.0, 18.0, 19.0);
  encoder_arduino_test_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/MATLAB System' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  encoder_arduino_test_DW.obj_p.matlabCodegenIsDeleted = false;

  /*  Do not generate code for sprintf */
  encoder_arduino_test_DW.obj_p.SampleTime =
    encoder_arduino_test_P.MATLABSystem_SampleTime;
  encoder_arduino_test_DW.obj_p.isInitialized = 1L;

  /*         %% Define output properties */
  /*  Call: void enc_init(int enc, int pinA, int pinB) */
  enc_init(0.0, 2.0, 3.0);
  encoder_arduino_test_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Digital Output' */
  encoder_arduino_test_DW.obj_b.matlabCodegenIsDeleted = false;
  encoder_arduino_test_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(8, 1);
  encoder_arduino_test_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Digital Output1' */
  encoder_arduino_test_DW.obj_d.matlabCodegenIsDeleted = false;
  encoder_arduino_test_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(7, 1);
  encoder_arduino_test_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/PWM' */
  encoder_arduino_test_DW.obj_h.matlabCodegenIsDeleted = false;
  encoder_arduino_test_DW.obj_h.isInitialized = 1L;
  encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL,
    0.0, 0.0);
  encoder_arduino_test_DW.obj_h.isSetupComplete = true;

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  encoder_arduino_test_DW.TimeStampA = (rtInf);
  encoder_arduino_test_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S3>/Derivative1' */
  encoder_arduino_test_DW.TimeStampA_p = (rtInf);
  encoder_arduino_test_DW.TimeStampB_n = (rtInf);
}

/* Model terminate function */
void encoder_arduino_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/MATLAB System1' */
  if (!encoder_arduino_test_DW.obj.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/MATLAB System1' */

  /* Terminate for MATLABSystem: '<S3>/MATLAB System' */
  if (!encoder_arduino_test_DW.obj_p.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!encoder_arduino_test_DW.obj_b.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!encoder_arduino_test_DW.obj_d.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  if (!encoder_arduino_test_DW.obj_h.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((encoder_arduino_test_DW.obj_h.isInitialized == 1L) &&
        encoder_arduino_test_DW.obj_h.isSetupComplete) {
      encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close(encoder_arduino_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
