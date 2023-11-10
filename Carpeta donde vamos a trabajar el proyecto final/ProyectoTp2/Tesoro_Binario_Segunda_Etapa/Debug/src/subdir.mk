################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Carta.cpp \
../src/Interfaz.cpp \
../src/Jugador.cpp \
../src/Mazo.cpp \
../src/Registro.cpp \
../src/Tablero.cpp \
../src/Tesoro.cpp \
../src/TesoroBinario.cpp \
../src/Tesoro_Binario_Segunda_Etapa.cpp 

OBJS += \
./src/Carta.o \
./src/Interfaz.o \
./src/Jugador.o \
./src/Mazo.o \
./src/Registro.o \
./src/Tablero.o \
./src/Tesoro.o \
./src/TesoroBinario.o \
./src/Tesoro_Binario_Segunda_Etapa.o 

CPP_DEPS += \
./src/Carta.d \
./src/Interfaz.d \
./src/Jugador.d \
./src/Mazo.d \
./src/Registro.d \
./src/Tablero.d \
./src/Tesoro.d \
./src/TesoroBinario.d \
./src/Tesoro_Binario_Segunda_Etapa.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


