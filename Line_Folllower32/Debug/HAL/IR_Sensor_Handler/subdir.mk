################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/IR_Sensor_Handler/IR_Sensor_prg.c 

OBJS += \
./HAL/IR_Sensor_Handler/IR_Sensor_prg.o 

C_DEPS += \
./HAL/IR_Sensor_Handler/IR_Sensor_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/IR_Sensor_Handler/%.o: ../HAL/IR_Sensor_Handler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


