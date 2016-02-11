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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=CRC16.c ComSlip.c PIC24FConfig.c SendUartMessage.c Service.c newmain.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/CRC16.o ${OBJECTDIR}/ComSlip.o ${OBJECTDIR}/PIC24FConfig.o ${OBJECTDIR}/SendUartMessage.o ${OBJECTDIR}/Service.o ${OBJECTDIR}/newmain.o
POSSIBLE_DEPFILES=${OBJECTDIR}/CRC16.o.d ${OBJECTDIR}/ComSlip.o.d ${OBJECTDIR}/PIC24FConfig.o.d ${OBJECTDIR}/SendUartMessage.o.d ${OBJECTDIR}/Service.o.d ${OBJECTDIR}/newmain.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/CRC16.o ${OBJECTDIR}/ComSlip.o ${OBJECTDIR}/PIC24FConfig.o ${OBJECTDIR}/SendUartMessage.o ${OBJECTDIR}/Service.o ${OBJECTDIR}/newmain.o

# Source Files
SOURCEFILES=CRC16.c ComSlip.c PIC24FConfig.c SendUartMessage.c Service.c newmain.c


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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24F16KA102
MP_LINKER_FILE_OPTION=,--script=p24F16KA102.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/CRC16.o: CRC16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CRC16.o.d 
	@${RM} ${OBJECTDIR}/CRC16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CRC16.c  -o ${OBJECTDIR}/CRC16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CRC16.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/CRC16.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ComSlip.o: ComSlip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ComSlip.o.d 
	@${RM} ${OBJECTDIR}/ComSlip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ComSlip.c  -o ${OBJECTDIR}/ComSlip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ComSlip.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ComSlip.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PIC24FConfig.o: PIC24FConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PIC24FConfig.o.d 
	@${RM} ${OBJECTDIR}/PIC24FConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIC24FConfig.c  -o ${OBJECTDIR}/PIC24FConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PIC24FConfig.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/PIC24FConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SendUartMessage.o: SendUartMessage.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SendUartMessage.o.d 
	@${RM} ${OBJECTDIR}/SendUartMessage.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SendUartMessage.c  -o ${OBJECTDIR}/SendUartMessage.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SendUartMessage.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/SendUartMessage.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Service.o: Service.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Service.o.d 
	@${RM} ${OBJECTDIR}/Service.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Service.c  -o ${OBJECTDIR}/Service.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Service.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Service.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/newmain.o: newmain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.o.d 
	@${RM} ${OBJECTDIR}/newmain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  newmain.c  -o ${OBJECTDIR}/newmain.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/newmain.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/newmain.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/CRC16.o: CRC16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CRC16.o.d 
	@${RM} ${OBJECTDIR}/CRC16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CRC16.c  -o ${OBJECTDIR}/CRC16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CRC16.o.d"        -g -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/CRC16.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ComSlip.o: ComSlip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ComSlip.o.d 
	@${RM} ${OBJECTDIR}/ComSlip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ComSlip.c  -o ${OBJECTDIR}/ComSlip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ComSlip.o.d"        -g -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ComSlip.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PIC24FConfig.o: PIC24FConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PIC24FConfig.o.d 
	@${RM} ${OBJECTDIR}/PIC24FConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIC24FConfig.c  -o ${OBJECTDIR}/PIC24FConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PIC24FConfig.o.d"        -g -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/PIC24FConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SendUartMessage.o: SendUartMessage.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SendUartMessage.o.d 
	@${RM} ${OBJECTDIR}/SendUartMessage.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SendUartMessage.c  -o ${OBJECTDIR}/SendUartMessage.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SendUartMessage.o.d"        -g -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/SendUartMessage.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Service.o: Service.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Service.o.d 
	@${RM} ${OBJECTDIR}/Service.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Service.c  -o ${OBJECTDIR}/Service.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Service.o.d"        -g -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Service.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/newmain.o: newmain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.o.d 
	@${RM} ${OBJECTDIR}/newmain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  newmain.c  -o ${OBJECTDIR}/newmain.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/newmain.o.d"        -g -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/newmain.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -no-legacy-libc  -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/include" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/generic/h" -I"../../../../../Program Files (x86)/Microchip/xc16/v1.25/support/PIC24F/h" -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/WiMODSendUartMsg.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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
