################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/timer1_module/timer1.c 

OBJS += \
./MCAL/timer1_module/timer1.o 

C_DEPS += \
./MCAL/timer1_module/timer1.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/timer1_module/%.o: ../MCAL/timer1_module/%.c MCAL/timer1_module/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


