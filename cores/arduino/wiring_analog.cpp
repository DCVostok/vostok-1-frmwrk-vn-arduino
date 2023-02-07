#include "Arduino.h"
#include "wiring_private.h"
#include "wiring_analog.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MCU_K1921VK035
    const PwmChDescription pwm_ch_description_map[] = {// key - PIN_PWM_CH_NUM(num)
      {PWM0,PWM_CH_DESCRIPTION_CH_A},
      {PWM0,PWM_CH_DESCRIPTION_CH_B},
      {PWM1,PWM_CH_DESCRIPTION_CH_A},
      {PWM1,PWM_CH_DESCRIPTION_CH_B},
      {PWM2,PWM_CH_DESCRIPTION_CH_A},
      {PWM2,PWM_CH_DESCRIPTION_CH_B},
    };

#elif MCU_K1921VK01T
    const PwmChDescription pwm_ch_description_map[] = {// key - PIN_PWM_CH_NUM(num)
      {NT_PWM0,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM0,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM1,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM1,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM2,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM2,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM3,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM3,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM4,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM4,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM5,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM5,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM6,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM6,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM7,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM7,PWM_CH_DESCRIPTION_CH_B},
      {NT_PWM8,PWM_CH_DESCRIPTION_CH_A},
      {NT_PWM8,PWM_CH_DESCRIPTION_CH_B}
    };
#endif



static int _readResolution = ADC_RESOLUTION;
static int _internalReadResolution = MAX_ADC_RESOLUTION;


static eAnalogWriteFreq _writeFreq = PWM_FREQUENCY;
static int _writeResolution = PWM_RESOLUTION;
static int _internalWriteResolution = MAX_PWM_RESOLUTION;

uint8_t pwn_enabled = 0;

void enablePwmBlocks();
void update_adc_config();
static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to);


void enablePwmBlocks(){
  #ifdef MCU_K1921VK035
    RCU_APBClkCmd(RCU_APBClk_PWM0, ENABLE);
    RCU_APBRstCmd(RCU_APBRst_PWM0, ENABLE);
    RCU_APBClkCmd(RCU_APBClk_PWM1, ENABLE);
    RCU_APBRstCmd(RCU_APBRst_PWM1, ENABLE);
    RCU_APBClkCmd(RCU_APBClk_PWM2, ENABLE);
    RCU_APBRstCmd(RCU_APBRst_PWM2, ENABLE);
  #elif MCU_K1921VK01T
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM0, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM0, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM1, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM1, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM2, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM2, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM3, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM3, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM4, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM4, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM5, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM5, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM6, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM6, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM7, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM7, ENABLE);
    RCC_PeriphClkCmd(RCC_PeriphClk_PWM8, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_PWM8, ENABLE);
    #endif
    pwn_enabled = 1;
}

void update_adc_config(){

  #ifdef MCU_K1921VK035
    RCU_PeriphClk_TypeDef Rcu_adc_clk_sel = RCU_PeriphClk_PLLClk;
    if (RCU->SYSCLKCFG_bit.SYSSEL == RCU_SYSCLKCFG_SYSSEL_OSICLK){
      Rcu_adc_clk_sel = RCU_PeriphClk_OSIClk;
    }
    if (RCU->SYSCLKCFG_bit.SYSSEL == RCU_SYSCLKCFG_SYSSEL_OSECLK){
      Rcu_adc_clk_sel = RCU_PeriphClk_OSEClk;
    } 
    RCU_ADCClkConfig(Rcu_adc_clk_sel, ((SystemCoreClock/25)/2)-1, ENABLE); //25MHz
    //RCU_ADCClkConfig(RCU_PeriphClk_PLLClk, 7, ENABLE); ////12.5MHz
    RCU_ADCClkCmd(ENABLE);
    RCU_ADCRstCmd(ENABLE);
    for (uint32_t i = 0; i < ADC_CH_Total; i++){
      ADC_CH_SetGainTrim ((ADC_CH_Num_TypeDef)i, ADC_CALIBRATION_GAIN);
      ADC_CH_SetOffsetTrim ((ADC_CH_Num_TypeDef)i,ADC_CALIBRATION_OFFSET);
    }
    ADC_AM_Cmd(ENABLE);
    while (!ADC_AM_ReadyStatus()) {
    }
  #elif MCU_K1921VK01T
      for(int i = 0; i < 12; i++){
         RCC_ADCClkCmd(i,DISABLE);
      }
      RCC_PeriphClkCmd(RCC_PeriphClk_ADC, DISABLE);
      int adc_clk_div = _internalReadResolution == 12 ? 3 : 1;// real_div = (2*(adc_clk_div+1)) 12.5/25 Мгц
      for(int i = 0; i < 12; i++){

          RCC_ADCClkDivConfig(i, adc_clk_div, ENABLE);
      }
      RCC_PeriphClkCmd(RCC_PeriphClk_ADC, ENABLE);
      for(int i = 0; i < 12; i++){
          RCC_ADCClkCmd(i,ENABLE);
      }
      ADC_Init_TypeDef ADC_InitStruct;
      ADC_StructInit(&ADC_InitStruct);
      ADC_InitStruct.ADC_Resolution = _internalReadResolution == 12 ? ADC_Resolution_12bit: ADC_Resolution_10bit;
      ADC_InitStruct.ADC_Average = ADC_Average_4;
      ADC_InitStruct.ADC_Mode = ADC_Mode_Active;

      for(int i = 0; i < 12; i++){
          ADC_Init(i, &ADC_InitStruct);
          ADC_Cmd(i, ENABLE);
      }
  #endif

}

void analogReadResolution(int res)
{
  if ((res > 0) && (res <= 32)) {
    _readResolution = res;
    if (_readResolution > MAX_ADC_RESOLUTION) {
      _readResolution = MAX_ADC_RESOLUTION;
    }
    #ifdef MCU_K1921VK01T
      _internalReadResolution  = _readResolution > 10 ? 12 : 10;
    #endif
    update_adc_config();
  }
}

void analogWriteResolution(int res)
{
  if ((res > 0) && (res <= 32)) {
    _writeResolution = res;
  }
}



void analogWriteFrequency(eAnalogWriteFreq freq)
{
  _writeFreq = freq;
}

static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to)
{
  if (from != to) {
    if (from > to) {
      value = (value < (uint32_t)(1 << (from - to))) ? 0 : ((value + 1) >> (from - to)) - 1;
    } else {
      if (value != 0) {
        value = ((value + 1) << (to - from)) - 1;
      }
    }
  }
  return value;
}

void analogWrite(pin_size_t pin, int value)
{
  const PinDescription *pin_description = PIN_GET_DESCRIPTION_WITH_PWM(pin);
  if(pin_description == NULL){
    return;
  }
  digital_pin_use_hook(pin);

  if (pin_description->pwm_ch != PIN_PWM_NONE){
    if(pwn_enabled == 0){
      enablePwmBlocks();
    }
    value = mapResolution(value, _writeResolution, _internalWriteResolution);
    
    const PwmChDescription *pwm_ch_description = &(pwm_ch_description_map[pin_description->pwm_ch]);
    #ifdef MCU_K1921VK035
      PWM_TB_Init_TypeDef PWM_TB_InitStruct;
      PWM_AQ_Init_TypeDef PWM_AQ_InitStruct;


      PWM_TB_StructInit(&PWM_TB_InitStruct);
      PWM_TB_InitStruct.Mode = PWM_TB_Mode_Up;
      PWM_TB_InitStruct.ClkDiv = (PWM_TB_ClkDiv_TypeDef)(_writeFreq >> 3);
      PWM_TB_InitStruct.ClkDivExtra = (PWM_TB_ClkDivExtra_TypeDef)(_writeFreq & 0b111);
      PWM_TB_InitStruct.Period = (1 << MAX_PWM_RESOLUTION) - 1;
      PWM_TB_Init(pwm_ch_description->pwm, &PWM_TB_InitStruct);

      PWM_AQ_StructInit(&PWM_AQ_InitStruct);
      PWM_AQ_InitStruct.ActionA_CTREqCMPAUp = PWM_AQ_Action_ToZero; 
      PWM_AQ_InitStruct.ActionA_CTREqPeriod = PWM_AQ_Action_ToOne;
      PWM_AQ_InitStruct.ActionB_CTREqCMPBUp = PWM_AQ_Action_ToZero; 
      PWM_AQ_InitStruct.ActionB_CTREqPeriod = PWM_AQ_Action_ToOne;
      PWM_AQ_Init(pwm_ch_description->pwm, &PWM_AQ_InitStruct);


      PWM_CMP_CmpALoadEventConfig(pwm_ch_description->pwm, PWM_CMP_LoadEvent_CTREqZero);
      PWM_CMP_CmpADirectLoadCmd(pwm_ch_description->pwm, DISABLE);
      
      PWM_CMP_CmpBLoadEventConfig(pwm_ch_description->pwm, PWM_CMP_LoadEvent_CTREqZero);
      PWM_CMP_CmpBDirectLoadCmd(pwm_ch_description->pwm, DISABLE);

      if(pwm_ch_description->pwm_ch == PWM_CH_DESCRIPTION_CH_A){
        PWM_CMP_SetCmpA(pwm_ch_description->pwm, value);
      }
      else{
       PWM_CMP_SetCmpB(pwm_ch_description->pwm, value);
      }

      GPIO_AltFuncCmd(pin_description->port, pin_description->pin_msk, ENABLE);
      GPIO_DigitalCmd(pin_description->port, pin_description->pin_msk, ENABLE);
      PWM_TB_PrescCmd(PWM_TB_Presc_1, ENABLE);
      PWM_TB_PrescCmd(PWM_TB_Presc_0, ENABLE);
      PWM_TB_PrescCmd(PWM_TB_Presc_2, ENABLE);
    #elif MCU_K1921VK01T
    GPIO_Init_TypeDef GPIO_InitStruct;
    PWM_CTR_Init_TypeDef PWM_CTR_InitStruct;

    PWM_CTR_StructInit(&PWM_CTR_InitStruct);
    PWM_CTR_InitStruct.PWM_ChAction_CTREqPeriod_A = PWM_ChAction_ToOne;
    PWM_CTR_InitStruct.PWM_ChAction_CTREqPeriod_B = PWM_ChAction_ToOne;
    PWM_CTR_InitStruct.PWM_CTR_Mode = PWM_CTR_Mode_Up;
   
    PWM_CTR_InitStruct.PWM_ClkDiv = (_writeFreq >> 3);
    PWM_CTR_InitStruct.PWM_ClkDivExtra = _writeFreq & 0b111;
    PWM_CTR_InitStruct.PWM_Period = 1 << MAX_PWM_RESOLUTION;
    PWM_CTR_Init(pwm_ch_description->pwm, &PWM_CTR_InitStruct);

    PWM_CMP_StructInit(&PWM_CMP_InitStruct);
    PWM_CMP_InitStruct.PWM_ChAction_CTREqCMPB_Up_A = PWM_ChAction_ToZero;
    PWM_CMP_InitStruct.PWM_ChAction_CTREqCMPB_Up_B = PWM_ChAction_ToZero;
    if(pwm_ch_description->pwm_ch == PWM_CH_DESCRIPTION_CH_A){
      PWM_CMP_InitStruct.PWM_CMPA = value;
    }
    else{
      PWM_CMP_InitStruct.PWM_CMPB = value;
    }
    PWM_CMP_Init(pwm_ch_description->pwm, &PWM_CMP_InitStruct);


    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_AltFunc = get_alt_func_pwm(pin_description->port,pin_description->pin_msk);
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_InitStruct.GPIO_Pin = pin_description->pin_msk;
    GPIO_Init(pin_description->port, &GPIO_InitStruct);
    #endif
    return;
}
    // -- Defaults to digital write
    pinMode(pin, OUTPUT);
    if (value < 128) {
      digitalWrite(pin, LOW);
    } else {
      digitalWrite(pin, HIGH);
    }
}

void analogReference(uint8_t mode)
{
  UNUSED(mode);
}

int analogRead(pin_size_t pin)
{
  uint32_t valueRead = 0;
  const PinDescription *pin_description = PIN_GET_DESCRIPTION_WITH_ADC(pin);
  if(pin_description == NULL){
    return 0;
  }
  if (pin_description->adc_ch != PIN_ADC_NONE){
    analog_pin_use_hook(pin);

#ifdef MCU_K1921VK035
      ADC_SEQ_Num_TypeDef ADC_SEQ_Module = ADC_SEQ_Num_0;
      ADC_SEQ_Init_TypeDef ADC_SEQ_InitStruct;
      GPIO_DigitalCmd(pin_description->port, pin_description->pin_msk, DISABLE);
      

      //ADC_SEQ_Cmd(ADC_SEQ_Module, DISABLE);
      ADC_SEQ_StructInit(&ADC_SEQ_InitStruct);
      ADC_SEQ_InitStruct.StartEvent = ADC_SEQ_StartEvent_SwReq;
      ADC_SEQ_InitStruct.SWStartEn = ENABLE;
      ADC_SEQ_InitStruct.ReqAverage = ADC_SEQ_Average_4;
      ADC_SEQ_InitStruct.ReqAverageEn = ENABLE;
      ADC_SEQ_InitStruct.Req[ADC_SEQ_ReqNum_0] = (ADC_CH_Num_TypeDef)pin_description->adc_ch;
      ADC_SEQ_InitStruct.ReqMax = ADC_SEQ_ReqNum_0;
      ADC_SEQ_InitStruct.RestartCount = 0;
      ADC_SEQ_Init(ADC_SEQ_Module, &ADC_SEQ_InitStruct);
      ADC_SEQ_Cmd(ADC_SEQ_Module, ENABLE);
      ADC_SEQ_SwStartCmd();
    #elif MCU_K1921VK01T
      const uint8_t ADC_SEQ_Module = ADC_SEQ_Module_0;
      ADC_SEQ_Init_TypeDef ADC_SEQ_InitStruct;

      ADC_SEQ_StructInit(&ADC_SEQ_InitStruct);
      ADC_SEQ_InitStruct.ADC_SEQ_StartEvent = ADC_SEQ_StartEvent_SWReq;
      ADC_SEQ_InitStruct.ADC_Channels =((uint32_t)1) << pin_description->adc_ch;
      ADC_SEQ_InitStruct.ADC_SEQ_ConversionCount = 1;
      ADC_SEQ_InitStruct.ADC_SEQ_ConversionDelay = 2;
      ADC_SEQ_InitStruct.ADC_SEQ_DC = ADC_DC_None;
      ADC_SEQ_Init(ADC_SEQ_Module, &ADC_SEQ_InitStruct);
      
      ADC_SEQ_SWReq();
    #endif
    
      while (!ADC_SEQ_GetFIFOLoad(ADC_SEQ_Module));
      valueRead = ADC_SEQ_GetFIFOData(ADC_SEQ_Module);
      valueRead = mapResolution(valueRead, _internalReadResolution, _readResolution);
  }

  return valueRead;
}


#ifdef __cplusplus
}
#endif