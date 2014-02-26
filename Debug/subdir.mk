################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../main.o 

CPP_SRCS += \
../CPU.cpp \
../Character.cpp \
../Character_Select.cpp \
../Credits.cpp \
../Gameplay.cpp \
../Gameplay2.cpp \
../Gameplay_Input.cpp \
../Gameplay_Render.cpp \
../Load_Game.cpp \
../Loading_Screen.cpp \
../OptionKeys.cpp \
../Options.cpp \
../Player.cpp \
../Select_Screen.cpp \
../Texture.cpp \
../Title_Screen.cpp \
../cpu_select.cpp \
../main.cpp \
../setup.cpp \
../specials.cpp \
../stage.cpp \
../vs_screen.cpp \
../xylist.cpp 

OBJS += \
./CPU.o \
./Character.o \
./Character_Select.o \
./Credits.o \
./Gameplay.o \
./Gameplay2.o \
./Gameplay_Input.o \
./Gameplay_Render.o \
./Load_Game.o \
./Loading_Screen.o \
./OptionKeys.o \
./Options.o \
./Player.o \
./Select_Screen.o \
./Texture.o \
./Title_Screen.o \
./cpu_select.o \
./main.o \
./setup.o \
./specials.o \
./stage.o \
./vs_screen.o \
./xylist.o 

CPP_DEPS += \
./CPU.d \
./Character.d \
./Character_Select.d \
./Credits.d \
./Gameplay.d \
./Gameplay2.d \
./Gameplay_Input.d \
./Gameplay_Render.d \
./Load_Game.d \
./Loading_Screen.d \
./OptionKeys.d \
./Options.d \
./Player.d \
./Select_Screen.d \
./Texture.d \
./Title_Screen.d \
./cpu_select.d \
./main.d \
./setup.d \
./specials.d \
./stage.d \
./vs_screen.d \
./xylist.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


