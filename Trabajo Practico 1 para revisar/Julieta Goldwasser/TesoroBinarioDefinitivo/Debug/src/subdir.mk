################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Auxiliares.cpp \
../src/Casillero.cpp \
../src/Interacciones.cpp \
../src/Jugador.cpp \
../src/Tablero.cpp \
../src/TesoroBinario.cpp \
../src/main.cpp 

O_SRCS += \
../src/Auxiliares.o \
../src/Casillero.o \
../src/Interacciones.o \
../src/Jugador.o \
../src/Tablero.o \
../src/TesoroBinario.o \
../src/main.o 

CPP_DEPS += \
./src/Auxiliares.d \
./src/Casillero.d \
./src/Interacciones.d \
./src/Jugador.d \
./src/Tablero.d \
./src/TesoroBinario.d \
./src/main.d 

OBJS += \
./src/Auxiliares.o \
./src/Casillero.o \
./src/Interacciones.o \
./src/Jugador.o \
./src/Tablero.o \
./src/TesoroBinario.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Auxiliares.d ./src/Auxiliares.o ./src/Casillero.d ./src/Casillero.o ./src/Interacciones.d ./src/Interacciones.o ./src/Jugador.d ./src/Jugador.o ./src/Tablero.d ./src/Tablero.o ./src/TesoroBinario.d ./src/TesoroBinario.o ./src/main.d ./src/main.o

.PHONY: clean-src

