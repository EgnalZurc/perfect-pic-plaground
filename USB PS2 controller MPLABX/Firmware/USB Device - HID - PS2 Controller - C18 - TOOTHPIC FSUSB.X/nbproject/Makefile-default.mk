#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/usb_descriptors.o ${OBJECTDIR}/_ext/972848033/usb_device.o ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1548923258/getsuart.o ${OBJECTDIR}/_ext/1548923258/openuart.o ${OBJECTDIR}/_ext/1548923258/putsuart.o ${OBJECTDIR}/_ext/1548923258/readuart.o ${OBJECTDIR}/_ext/1548923258/uart_delays.o ${OBJECTDIR}/_ext/1548923258/uartdata.o ${OBJECTDIR}/_ext/1548923258/writuart.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/usb_descriptors.o.d ${OBJECTDIR}/_ext/972848033/usb_device.o.d ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1548923258/getsuart.o.d ${OBJECTDIR}/_ext/1548923258/openuart.o.d ${OBJECTDIR}/_ext/1548923258/putsuart.o.d ${OBJECTDIR}/_ext/1548923258/readuart.o.d ${OBJECTDIR}/_ext/1548923258/uart_delays.o.d ${OBJECTDIR}/_ext/1548923258/uartdata.o.d ${OBJECTDIR}/_ext/1548923258/writuart.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/usb_descriptors.o ${OBJECTDIR}/_ext/972848033/usb_device.o ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1548923258/getsuart.o ${OBJECTDIR}/_ext/1548923258/openuart.o ${OBJECTDIR}/_ext/1548923258/putsuart.o ${OBJECTDIR}/_ext/1548923258/readuart.o ${OBJECTDIR}/_ext/1548923258/uart_delays.o ${OBJECTDIR}/_ext/1548923258/uartdata.o ${OBJECTDIR}/_ext/1548923258/writuart.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2550
MP_PROCESSOR_OPTION_LD=18f2550
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0x7dc0 -u_DEBUGCODELEN=0x240 -u_DEBUGDATASTART=0x3f4 -u_DEBUGDATALEN=0xb
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1548923258/openuart.o: ../SW_UART/openuart.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/openuart.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/openuart.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_PICKIT2=1 -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/openuart.lst\" -e\"${OBJECTDIR}/_ext/1548923258/openuart.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/openuart.o\" ../SW_UART/openuart.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/openuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/openuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/readuart.o: ../SW_UART/readuart.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/readuart.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/readuart.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_PICKIT2=1 -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/readuart.lst\" -e\"${OBJECTDIR}/_ext/1548923258/readuart.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/readuart.o\" ../SW_UART/readuart.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/readuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/readuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/uartdata.o: ../SW_UART/uartdata.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/uartdata.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/uartdata.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_PICKIT2=1 -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/uartdata.lst\" -e\"${OBJECTDIR}/_ext/1548923258/uartdata.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/uartdata.o\" ../SW_UART/uartdata.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/uartdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/uartdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/writuart.o: ../SW_UART/writuart.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/writuart.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/writuart.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_PICKIT2=1 -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/writuart.lst\" -e\"${OBJECTDIR}/_ext/1548923258/writuart.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/writuart.o\" ../SW_UART/writuart.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/writuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/writuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1548923258/openuart.o: ../SW_UART/openuart.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/openuart.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/openuart.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/openuart.lst\" -e\"${OBJECTDIR}/_ext/1548923258/openuart.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/openuart.o\" ../SW_UART/openuart.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/openuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/openuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/readuart.o: ../SW_UART/readuart.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/readuart.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/readuart.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/readuart.lst\" -e\"${OBJECTDIR}/_ext/1548923258/readuart.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/readuart.o\" ../SW_UART/readuart.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/readuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/readuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/uartdata.o: ../SW_UART/uartdata.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/uartdata.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/uartdata.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/uartdata.lst\" -e\"${OBJECTDIR}/_ext/1548923258/uartdata.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/uartdata.o\" ../SW_UART/uartdata.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/uartdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/uartdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/writuart.o: ../SW_UART/writuart.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/writuart.o.d 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1548923258/writuart.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1548923258/writuart.lst\" -e\"${OBJECTDIR}/_ext/1548923258/writuart.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1548923258/writuart.o\" ../SW_UART/writuart.asm 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/writuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/writuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/usb_descriptors.o: ../usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_descriptors.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/usb_descriptors.o   ../usb_descriptors.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usb_descriptors.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/972848033/usb_device.o: ../../../Libraries/USB/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/972848033 
	@${RM} ${OBJECTDIR}/_ext/972848033/usb_device.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/972848033/usb_device.o   ../../../Libraries/USB/usb_device.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/972848033/usb_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/972848033/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1813102981/usb_function_hid.o: ../../../Libraries/USB/HID\ Device\ Driver/usb_function_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1813102981 
	@${RM} ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o   "../../../Libraries/USB/HID Device Driver/usb_function_hid.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1813102981/usb_function_hid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/getsuart.o: ../SW_UART/getsuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/getsuart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1548923258/getsuart.o   ../SW_UART/getsuart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/getsuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/getsuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/putsuart.o: ../SW_UART/putsuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/putsuart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1548923258/putsuart.o   ../SW_UART/putsuart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/putsuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/putsuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/uart_delays.o: ../SW_UART/uart_delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/uart_delays.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1548923258/uart_delays.o   ../SW_UART/uart_delays.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/uart_delays.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/uart_delays.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1472/usb_descriptors.o: ../usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_descriptors.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/usb_descriptors.o   ../usb_descriptors.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usb_descriptors.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/972848033/usb_device.o: ../../../Libraries/USB/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/972848033 
	@${RM} ${OBJECTDIR}/_ext/972848033/usb_device.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/972848033/usb_device.o   ../../../Libraries/USB/usb_device.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/972848033/usb_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/972848033/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1813102981/usb_function_hid.o: ../../../Libraries/USB/HID\ Device\ Driver/usb_function_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1813102981 
	@${RM} ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o   "../../../Libraries/USB/HID Device Driver/usb_function_hid.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1813102981/usb_function_hid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1813102981/usb_function_hid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/getsuart.o: ../SW_UART/getsuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/getsuart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1548923258/getsuart.o   ../SW_UART/getsuart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/getsuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/getsuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/putsuart.o: ../SW_UART/putsuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/putsuart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1548923258/putsuart.o   ../SW_UART/putsuart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/putsuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/putsuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1548923258/uart_delays.o: ../SW_UART/uart_delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1548923258 
	@${RM} ${OBJECTDIR}/_ext/1548923258/uart_delays.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../Libraries/Include" -I".." -I"../../../../../../../MCC18/h" -I"../../../Libraries/Include/USB" -I"../../../Libraries/USB" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1548923258/uart_delays.o   ../SW_UART/uart_delays.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1548923258/uart_delays.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1548923258/uart_delays.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../rm18f4550\ -\ HID\ Bootload.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\rm18f4550 - HID Bootload.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../../../../../../../mcc18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PICKIT2=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../rm18f4550\ -\ HID\ Bootload.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\rm18f4550 - HID Bootload.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../../../../../../../mcc18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/USB_Device_-_HID_-_PS2_Controller_-_C18_-_TOOTHPIC_FSUSB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
