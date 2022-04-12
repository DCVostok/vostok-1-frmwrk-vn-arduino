#ifndef WIRING_ANALOG_H
#define WIRING_ANALOG_H
#include "wiring_private.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ADC_RESOLUTION
#define ADC_RESOLUTION 10
#endif

#ifndef PWM_RESOLUTION
#define PWM_RESOLUTION 8
#endif

#ifndef PWM_FREQUENCY
#define PWM_FREQUENCY (E_ANALOG_WRITE_FREQ_1K_Hz)
#endif

#define MAX_PWM_RESOLUTION 10
#ifndef ADC_CALIBRATION_GAIN
#define ADC_CALIBRATION_GAIN (0)
#endif
#ifndef ADC_CALIBRATION_OFFSET
#define ADC_CALIBRATION_OFFSET (0)
#endif

#ifdef MCU_K1921VK035
typedef enum {
  PWM_ClkDiv_1 =
      ((uint32_t)PWM_TB_ClkDiv_1), /*!< Без деления тактовой частоты. */
  PWM_ClkDiv_2 =
      ((uint32_t)PWM_TB_ClkDiv_2), /*!< Деление тактовой частоты на 2. */
  PWM_ClkDiv_4 =
      ((uint32_t)PWM_TB_ClkDiv_4), /*!< Деление тактовой частоты на 4. */
  PWM_ClkDiv_8 =
      ((uint32_t)PWM_TB_ClkDiv_8), /*!< Деление тактовой частоты на 8. */
  PWM_ClkDiv_16 =
      ((uint32_t)PWM_TB_ClkDiv_16), /*!< Деление тактовой частоты на 16. */
  PWM_ClkDiv_32 =
      ((uint32_t)PWM_TB_ClkDiv_32), /*!< Деление тактовой частоты на 32. */
  PWM_ClkDiv_64 =
      ((uint32_t)PWM_TB_ClkDiv_64), /*!< Деление тактовой частоты на 64. */
  PWM_ClkDiv_128 =
      ((uint32_t)PWM_TB_ClkDiv_128), /*!< Деление тактовой частоты на 128. */
} PWM_ClkDiv_TypeDef;

typedef enum {
  PWM_ClkDivExtra_1 = ((uint32_t)PWM_TB_ClkDivExtra_1),
  PWM_ClkDivExtra_2 = ((uint32_t)PWM_TB_ClkDivExtra_2),
  PWM_ClkDivExtra_4 = ((uint32_t)PWM_TB_ClkDivExtra_4),
  PWM_ClkDivExtra_6 = ((uint32_t)PWM_TB_ClkDivExtra_6),
  PWM_ClkDivExtra_8 = ((uint32_t)PWM_TB_ClkDivExtra_8),
  PWM_ClkDivExtra_10 = ((uint32_t)PWM_TB_ClkDivExtra_10),
  PWM_ClkDivExtra_12 = ((uint32_t)PWM_TB_ClkDivExtra_12),
  PWM_ClkDivExtra_14 = ((uint32_t)PWM_TB_ClkDivExtra_14),
} PWM_ClkDivExtra_TypeDef;
#endif

// freq and div calculated for SysTick  100Mhz and pwm resolution 10bit(Timer
// reload reg = 1024)
typedef enum { // CLKDIV|HSPCLKDIV
  E_ANALOG_WRITE_FREQ_54_Hz =
      (PWM_ClkDiv_128 << 3) | PWM_ClkDivExtra_14, // 128*14=1792 real freq 54 Hz
  E_ANALOG_WRITE_FREQ_508_Hz =
      (PWM_ClkDiv_32 << 3) | PWM_ClkDivExtra_6, // 32*6=192 real freq 508 Hz
  E_ANALOG_WRITE_FREQ_1K_Hz =
      (PWM_ClkDiv_16 << 3) | PWM_ClkDivExtra_6, // 16*6=96 real freq 1017 Hz
  E_ANALOG_WRITE_FREQ_97K_Hz =
      (PWM_ClkDiv_1 << 3) | PWM_ClkDivExtra_1, // 1 real freq 97656 Hz
  E_ANALOG_WRITE_FREQ_49K_Hz =
      (PWM_ClkDiv_2 << 3) | PWM_ClkDivExtra_1, // 2*1=4 real freq 48828 Hz
  E_ANALOG_WRITE_FREQ_24K_Hz =
      (PWM_ClkDiv_4 << 3) | PWM_ClkDivExtra_1, // 4*1=4 real freq 24414 Hz
  E_ANALOG_WRITE_FREQ_12K_Hz =
      (PWM_ClkDiv_8 << 3) | PWM_ClkDivExtra_1, // 8*1=8 real freq 12207 Hz
  E_ANALOG_WRITE_FREQ_6K_Hz =
      (PWM_ClkDiv_16 << 3) | PWM_ClkDivExtra_1, // 16*1=16 real freq 6103 Hz
  E_ANALOG_WRITE_FREQ_3K_Hz =
      (PWM_ClkDiv_32 << 3) | PWM_ClkDivExtra_1, // 32*1=32 real freq 3051 Hz
  E_ANALOG_WRITE_FREQ_10K_Hz =
      (PWM_ClkDiv_1 << 3) | PWM_ClkDivExtra_10, // 1*10=10 real freq 9765 Hz
  E_ANALOG_WRITE_FREQ_8K_Hz =
      (PWM_ClkDiv_1 << 3) | PWM_ClkDivExtra_12, // 1*12=12 real freq 8138 Hz
  E_ANALOG_WRITE_FREQ_7K_Hz =
      (PWM_ClkDiv_1 << 3) | PWM_ClkDivExtra_14, // 1*14=14 real freq 6975 Hz
} eAnalogWriteFreq;

/**
 * @brief Set resolution for ADC and analogRead function. Default resolution is
 * 10 bit (0-1023). Max resolution is 12 bit (0 - 4095).
 *
 * @param res resolution in bits.
 */
void analogReadResolution(int res);
/**
 * @brief Set resolution for PWM and analogWrite function. Default resolution is
 * 8 bit (0-255). Max resolution is 10 bit (0 - 1023).
 *
 * @param res resolution in bits.
 */
void analogWriteResolution(int res);
/**
 * @brief Set frequency of PWM for analogWrite function. Default freq is
 * E_ANALOG_WRITE_FREQ_1K_Hz (1000 Hz).
 *
 * @param freq frequency from enum eAnalogWriteFreq
 */
void analogWriteFrequency(eAnalogWriteFreq freq);

#ifdef __cplusplus
}
#endif
#endif // WIRING_ANALOG_H