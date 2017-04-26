################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Buzzer.c \
../DIO.c \
../Keypad.c \
../LCD.c \
../Motor_Relay.c \
../PWM1.c \
../Servo1.c \
../Stepper.c \
../Timer0.c 

OBJS += \
./ADC.o \
./Buzzer.o \
./DIO.o \
./Keypad.o \
./LCD.o \
./Motor_Relay.o \
./PWM1.o \
./Servo1.o \
./Stepper.o \
./Timer0.o 

C_DEPS += \
./ADC.d \
./Buzzer.d \
./DIO.d \
./Keypad.d \
./LCD.d \
./Motor_Relay.d \
./PWM1.d \
./Servo1.d \
./Stepper.d \
./Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


