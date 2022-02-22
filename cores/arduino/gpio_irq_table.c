#include <gpio_irq_table.h>
#include <stddef.h>
#ifdef USE_FREERTOS
    #include <FreeRTOS.h>
#endif


#define GPIO_IRQ_TABLE_GPIOAnum (0)
#define GPIO_IRQ_TABLE_GPIOBnum (1)
#define GPIO_IRQ_TABLE_GPIOCnum (2)
#define GPIO_IRQ_TABLE_GPIODnum (3)
#define GPIO_IRQ_TABLE_GPIOEnum (4)
#define GPIO_IRQ_TABLE_GPIOFnum (5)
#define GPIO_IRQ_TABLE_GPIOGnum (6)
#define GPIO_IRQ_TABLE_GPIOHnum (7)

#ifdef MCU_K1921VK035
    #define PORT_NUM 2
#elif MCU_K1921VK01T
    #define PORT_NUM 8
#endif
typedef void (*voidFuncPtr)(void);
typedef void (*voidFuncPtrParam)(void*);

voidFuncPtrParam call_backs_table[PORT_NUM][16];
void*  call_backs_param_table[PORT_NUM][16];
uint32_t pin_mask_table[PORT_NUM][16];
int8_t callbacks_num[PORT_NUM];


void gpio_irq_table_init(){
    #ifdef USE_FREERTOS
        NVIC_SetPriority(GPIOA_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_SetPriority(GPIOB_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        #ifdef MCU_K1921VK01T
        NVIC_SetPriority(GPIOC_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_SetPriority(GPIOD_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_SetPriority(GPIOE_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_SetPriority(GPIOF_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_SetPriority(GPIOG_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        NVIC_SetPriority(GPIOH_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
        #endif
    #endif
    NVIC_EnableIRQ(GPIOA_IRQn);
    NVIC_EnableIRQ(GPIOB_IRQn);
    #ifdef MCU_K1921VK01T
    NVIC_EnableIRQ(GPIOC_IRQn);
    NVIC_EnableIRQ(GPIOD_IRQn);
    NVIC_EnableIRQ(GPIOE_IRQn);
    NVIC_EnableIRQ(GPIOF_IRQn);
    NVIC_EnableIRQ(GPIOG_IRQn);
    NVIC_EnableIRQ(GPIOH_IRQn);
    #endif
}

void gpio_irq_table_Add_CallBack(GPIO_TypeDef* nt_port, uint32_t pin_msk,void (*call_back)()){
    gpio_irq_table_Add_CallBackWithParam(nt_port,pin_msk,call_back,NULL);
}

void gpio_irq_table_Add_CallBackWithParam(GPIO_TypeDef* nt_port, uint32_t pin_msk,void (*call_back)(void*), void* param){
    #ifdef MCU_K1921VK035
        int gpio_irq_tableNum = nt_port == GPIOA?GPIO_IRQ_TABLE_GPIOAnum:
                                nt_port == GPIOB?GPIO_IRQ_TABLE_GPIOBnum:
                                GPIO_IRQ_TABLE_GPIOAnum;
    #elif MCU_K1921VK01T
        int gpio_irq_tableNum = nt_port == NT_GPIOA?GPIO_IRQ_TABLE_GPIOAnum:
                            nt_port == NT_GPIOB?GPIO_IRQ_TABLE_GPIOBnum:
                            nt_port == NT_GPIOC?GPIO_IRQ_TABLE_GPIOCnum:
                            nt_port == NT_GPIOD?GPIO_IRQ_TABLE_GPIODnum:
                            nt_port == NT_GPIOE?GPIO_IRQ_TABLE_GPIOEnum:
                            nt_port == NT_GPIOF?GPIO_IRQ_TABLE_GPIOFnum:
                            nt_port == NT_GPIOG?GPIO_IRQ_TABLE_GPIOGnum:
                            nt_port == NT_GPIOH?GPIO_IRQ_TABLE_GPIOHnum:
                            GPIO_IRQ_TABLE_GPIOAnum;
    #endif

    int find_num_callback = -1;
    for(uint8_t i = 0; i < callbacks_num[gpio_irq_tableNum];++i){
        if(pin_mask_table[gpio_irq_tableNum][i] == pin_msk){
            find_num_callback = i;
            break;
        }
    }
    if(find_num_callback == -1){//add new
        assert_param(callbacks_num[gpio_irq_tableNum] < 16);
        call_backs_table[gpio_irq_tableNum][callbacks_num[gpio_irq_tableNum]] = call_back;
        call_backs_param_table[gpio_irq_tableNum][callbacks_num[gpio_irq_tableNum]] = param;
        pin_mask_table[gpio_irq_tableNum][callbacks_num[gpio_irq_tableNum]] = pin_msk;
        callbacks_num[gpio_irq_tableNum]++;
        GPIO_ITCmd(nt_port, pin_msk, ENABLE);
    }else{//rewrite
        call_backs_table[gpio_irq_tableNum][find_num_callback] = call_back;
        call_backs_param_table[gpio_irq_tableNum][find_num_callback] = param;
        pin_mask_table[gpio_irq_tableNum][find_num_callback] = pin_msk;
  
        GPIO_ITCmd(nt_port, pin_msk, ENABLE);
    }
    

}

void gpio_irq_table_Remove_Callback(GPIO_TypeDef* nt_port, uint32_t pin_msk){
    GPIO_ITCmd(nt_port, pin_msk, DISABLE);
    #ifdef MCU_K1921VK035
        int gpio_irq_tableNum = nt_port == GPIOA?GPIO_IRQ_TABLE_GPIOAnum:
                                nt_port == GPIOB?GPIO_IRQ_TABLE_GPIOBnum:
                                GPIO_IRQ_TABLE_GPIOAnum;
    #elif MCU_K1921VK01T
        int gpio_irq_tableNum = nt_port == NT_GPIOA?GPIO_IRQ_TABLE_GPIOAnum:
                                nt_port == NT_GPIOB?GPIO_IRQ_TABLE_GPIOBnum:
                                nt_port == NT_GPIOC?GPIO_IRQ_TABLE_GPIOCnum:
                                nt_port == NT_GPIOD?GPIO_IRQ_TABLE_GPIODnum:
                                nt_port == NT_GPIOE?GPIO_IRQ_TABLE_GPIOEnum:
                                nt_port == NT_GPIOF?GPIO_IRQ_TABLE_GPIOFnum:
                                nt_port == NT_GPIOG?GPIO_IRQ_TABLE_GPIOGnum:
                                nt_port == NT_GPIOH?GPIO_IRQ_TABLE_GPIOHnum:
                                GPIO_IRQ_TABLE_GPIOAnum;
    #endif
    int remove_num_callback = -1;
    for(uint8_t i = 0; i < callbacks_num[gpio_irq_tableNum];++i){
        if(pin_mask_table[gpio_irq_tableNum][i] == pin_msk){
            remove_num_callback = i;
            break;
        }
    }
    if(remove_num_callback == -1){
        return;
    }
    for (; remove_num_callback<callbacks_num[gpio_irq_tableNum]-1; remove_num_callback++) {
        call_backs_table[gpio_irq_tableNum][remove_num_callback] = call_backs_table[gpio_irq_tableNum][remove_num_callback+1];
        call_backs_param_table[gpio_irq_tableNum][remove_num_callback] = call_backs_param_table[gpio_irq_tableNum][remove_num_callback+1];
        pin_mask_table[gpio_irq_tableNum][remove_num_callback] = pin_mask_table[gpio_irq_tableNum][remove_num_callback+1];
    }
    callbacks_num[gpio_irq_tableNum]--;
}


void GPIOA_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOAnum];++i){
        #ifdef MCU_K1921VK035
            if(GPIO_ITStatus(GPIOA,pin_mask_table[GPIO_IRQ_TABLE_GPIOAnum][i])){
                if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOAnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOAnum][i])();
                }
                else{
                    call_backs_table[GPIO_IRQ_TABLE_GPIOAnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOAnum][i]);
                }
                GPIO_ITStatusClear(GPIOA,pin_mask_table[GPIO_IRQ_TABLE_GPIOAnum][i]);
            }
        #elif MCU_K1921VK01T
            if(GPIO_ITStatus(NT_GPIOA,pin_mask_table[GPIO_IRQ_TABLE_GPIOAnum][i])){
                if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOAnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOAnum][i])();
                }
                else{
                    call_backs_table[GPIO_IRQ_TABLE_GPIOAnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOAnum][i]);
                }
            }
        #endif
    }
    
}
void GPIOB_IRQHandler(){

    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOBnum];++i){
        #ifdef MCU_K1921VK035
            if(GPIO_ITStatus(GPIOB,pin_mask_table[GPIO_IRQ_TABLE_GPIOBnum][i])){
                if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOBnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOBnum][i])();
                }
                else{
                    call_backs_table[GPIO_IRQ_TABLE_GPIOBnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOBnum][i]);
                }
                GPIO_ITStatusClear(GPIOB,pin_mask_table[GPIO_IRQ_TABLE_GPIOBnum][i]);
            }
        #elif MCU_K1921VK01T
            if(GPIO_ITStatus(NT_GPIOB,pin_mask_table[GPIO_IRQ_TABLE_GPIOBnum][i])){
                if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOBnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOBnum][i])();
                }
                else{
                    call_backs_table[GPIO_IRQ_TABLE_GPIOBnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOBnum][i]);
                }
            }
        #endif
    }
    
}
#ifdef MCU_K1921VK01T
void GPIOC_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOCnum];++i){
        if(GPIO_ITStatus(NT_GPIOC,pin_mask_table[GPIO_IRQ_TABLE_GPIOCnum][i])){
            if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOCnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOCnum][i])();
            }
            else{
                call_backs_table[GPIO_IRQ_TABLE_GPIOCnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOCnum][i]);
            }
        }
    }
}
void GPIOD_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIODnum];++i){
        if(GPIO_ITStatus(NT_GPIOD,pin_mask_table[GPIO_IRQ_TABLE_GPIODnum][i])){
            if(call_backs_param_table[GPIO_IRQ_TABLE_GPIODnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIODnum][i])();
            }
            else{
                call_backs_table[GPIO_IRQ_TABLE_GPIODnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIODnum][i]);
            }
        }
    }
}
void GPIOE_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOEnum];++i){
        if(GPIO_ITStatus(NT_GPIOE,pin_mask_table[GPIO_IRQ_TABLE_GPIOEnum][i])){
            if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOEnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOEnum][i])();
            }
            else{
                call_backs_table[GPIO_IRQ_TABLE_GPIOEnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOEnum][i]);
            }
        }
    }
}
void GPIOF_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOFnum];++i){
        if(GPIO_ITStatus(NT_GPIOF,pin_mask_table[GPIO_IRQ_TABLE_GPIOFnum][i])){
            if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOFnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOFnum][i])();
            }
            else{
                call_backs_table[GPIO_IRQ_TABLE_GPIOFnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOFnum][i]);
            }
        }
    }
}
void GPIOG_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOGnum];++i){
        if(GPIO_ITStatus(NT_GPIOG,pin_mask_table[GPIO_IRQ_TABLE_GPIOGnum][i])){
            if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOGnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOGnum][i])();
            }
            else{
                call_backs_table[GPIO_IRQ_TABLE_GPIOGnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOGnum][i]);
            }
        }
    }
}
void GPIOH_IRQHandler(){
    for(uint8_t i = 0; i < callbacks_num[GPIO_IRQ_TABLE_GPIOHnum];++i){
        if(GPIO_ITStatus(NT_GPIOH,pin_mask_table[GPIO_IRQ_TABLE_GPIOHnum][i])){
            if(call_backs_param_table[GPIO_IRQ_TABLE_GPIOHnum][i] == NULL){
                    ((voidFuncPtr)call_backs_table[GPIO_IRQ_TABLE_GPIOHnum][i])();
            }
            else{
                call_backs_table[GPIO_IRQ_TABLE_GPIOHnum][i](call_backs_param_table[GPIO_IRQ_TABLE_GPIOHnum][i]);
            }
            
        }
    }
}
#endif //MCU_K1921VK01T