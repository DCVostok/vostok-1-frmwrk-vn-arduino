/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <api/Common.h>

#ifdef __cplusplus
extern "C" {
#endif
#include "bitFlip.h"
#include "k1921vk_sdk.h"
#define UNUSED(x) (void)(x)
GPIO_TypeDef * digitalPinToPort(pin_size_t ulPin);
uint32_t * portOutputRegister(GPIO_TypeDef * gpio);
uint32_t * portInputRegister(GPIO_TypeDef * gpio);
uint32_t digitalPinToBitMask(pin_size_t ulPin);
#ifdef __cplusplus
} // extern "C"

#endif
