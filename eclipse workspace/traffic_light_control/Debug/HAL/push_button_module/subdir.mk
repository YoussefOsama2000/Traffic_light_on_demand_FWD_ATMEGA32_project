################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/push_button_module/pushButton.c 

OBJS += \
./HAL/push_button_module/pushButton.o 

C_DEPS += \
./HAL/push_button_module/pushButton.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/push_button_module/%.o: ../HAL/push_button_module/%.c HAL/push_button_module/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


