#ifndef GPIO_IRQ_TABLE_H
#define GPIO_IRQ_TABLE_H
#include <stdint.h>
#include <k1921vk_sdk.h>
void gpio_irq_table_init();
void gpio_irq_table_Add_CallBack(GPIO_TypeDef* nt_port, uint32_t pin_msk,void (*call_back)());
void gpio_irq_table_Remove_Callback(GPIO_TypeDef* nt_port, uint32_t pin_msk);
void gpio_irq_table_Add_CallBackWithParam(GPIO_TypeDef* nt_port, uint32_t pin_msk,void (*call_back)(void*), void* param);

#endif