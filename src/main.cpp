
#include "stm32f3xx_hal.h"

auto LedPin = GPIO_PIN_5;
auto LedPort = GPIOA;

GPIO_InitTypeDef GPIO_InitStruct;

void led_init();

int main(void) {
    HAL_Init();
    led_init();

    while (1) {
        HAL_GPIO_WritePin(LedPort, LedPin, GPIO_PIN_SET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(LedPort,LedPin,GPIO_PIN_RESET);
        HAL_Delay(1000);
        
    }
}

void led_init() {

    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = LedPin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LedPort, &GPIO_InitStruct);

}

extern "C" {
    
    void SysTick_Handler(void) {
    HAL_IncTick();
}
}
