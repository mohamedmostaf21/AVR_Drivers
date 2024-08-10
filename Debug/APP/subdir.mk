################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Test.c \
../APP/TestADC.c \
../APP/TestLCD.c \
../APP/TestStepper.c \
../APP/Testled.c 

OBJS += \
./APP/Test.o \
./APP/TestADC.o \
./APP/TestLCD.o \
./APP/TestStepper.o \
./APP/Testled.o 

C_DEPS += \
./APP/Test.d \
./APP/TestADC.d \
./APP/TestLCD.d \
./APP/TestStepper.d \
./APP/Testled.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


