/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t message = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan1;
/* USER CODE BEGIN EV */
extern uint8_t datarx[];
extern CAN_FilterTypeDef filter;
extern CAN_RxHeaderTypeDef RxHeader; //Rx refers as input
extern CAN_TxHeaderTypeDef TxHeader;
extern uint32_t mailbox;
extern uint8_t data [8]; 
extern uint32_t error;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
  
  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */
if (message < 8) {
      message ++;
  }
  else {
      message = 0;
  }
  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles CAN1 TX interrupts.
  */
void CAN1_TX_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_TX_IRQn 0 */

  /* USER CODE END CAN1_TX_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_TX_IRQn 1 */
  
  /* USER CODE END CAN1_TX_IRQn 1 */
}

/**
  * @brief This function handles CAN1 RX0 interrupts.
  */
void CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX0_IRQn 0 */
  
  /* USER CODE END CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX0_IRQn 1 */
  HAL_CAN_GetRxMessage(&hcan1, CAN_FILTER_FIFO0, &RxHeader, datarx);
  if (RxHeader.StdId == 0x690){
    if (message == 0) {
      TxHeader.StdId = 0x440; 
      data[2] =0x00;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0x00;
      data[3] =0x00;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 1) {
      TxHeader.StdId = 0x440; 
      data[2] =0x1D;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0xa0;
      data[3] =0x0f;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 2) {
      TxHeader.StdId = 0x440; 
      data[2] =0x3c;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0x40;
      data[3] =0x1f;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 3) {
      TxHeader.StdId = 0x440; 
      data[2] =0x5b;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0xe0;
      data[3] =0x2e;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 4) {
      TxHeader.StdId = 0x440; 
      data[2] =0x7b;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0x80;
      data[3] =0x3e;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 5) {
      TxHeader.StdId = 0x440; 
      data[2] =0x9a;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0x20;
      data[3] =0x4e;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 6) {
      TxHeader.StdId = 0x440; 
      data[2] =0xba;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0xc0;
      data[3] =0x5d;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 7) {
      TxHeader.StdId = 0x440; 
      data[2] =0xd9;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0x60;
      data[3] =0x6d;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
    else if (message == 8) {
      TxHeader.StdId = 0x440; 
      data[2] =0xfa;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
      TxHeader.StdId = 0x316; 
      data[2] =0x00;
      data[3] =0x7d;
      error = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &mailbox);
    }
  }
  /* USER CODE END CAN1_RX0_IRQn 1 */
}

/**
  * @brief This function handles CAN1 RX1 interrupt.
  */
void CAN1_RX1_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX1_IRQn 0 */

  /* USER CODE END CAN1_RX1_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX1_IRQn 1 */
  
  /* USER CODE END CAN1_RX1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
