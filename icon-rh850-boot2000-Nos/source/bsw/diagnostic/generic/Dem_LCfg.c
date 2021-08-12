/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/
//#warning "This default file may only be used as an example!"

#include "Dem.h"
#include "Dem_Extension.h"
/*********************
 * DEM Configuration *
 *********************/


/*
 * Classes of extended data record
 */


/*
 * Classes of extended data
 */


/*
 * Classes of freeze frames
 */


/*
 * Classes of PreDebounce algorithms
 */


/*
 * Classes of event
 */


/*
 * Event parameter list
 */

Std_ReturnType Read_DidReadDataFnc_DF00(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF01(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF02(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF03(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF04(uint8_t *data);

const Dem_DTCClassType Dem_DTCClass[] ={
     {//dummy
		/*DTC*/							0x938011,					// (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	{////Battery Voltage High
		/*DTC*/					        0xF00617,					// (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	{//Battery Voltage Low
		/*DTC*/					        0xF00616,					// (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	
	{//CAN BusOff error
		/*DTC*/							0xC07300,					// (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	{//backlight temperature hight  
		/*DTC*/							0xA52098,	 			    // (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	{//LCD screen temperature hight
		/*DTC*/							0xA52198,	  			    // (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	{//Deserializing chip fault
		/*DTC*/							0xA52204,	 			    // (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						false,
	},
	
	{//END
		/*DTC*/							0x952700,					// (1)
		/*DTCFunctionalUnit*/			0,							// (1)
		/*DTCKind*/						DEM_DTC_KIND_ALL_DTCS,		// (1)
		/*CallbackDTCStatusChanged*/	NULL,						// (0..*)
		/*CallbackInitMForF*/			NULL,						// (0..*)
		/*Arc_EOL*/						true,
	}		
} ; /** @req DEM132 */



const Dem_EnableConditionType Dem_EnableCondition[] ={
	{ //0
		/*EnableConditionStatus*/false,		//
		/*EnableConditionID*/    CONDITION_LOC_VOL,		// Optional
	},
	{  // 1
		/*EnableConditionStatus*/true,		//
		/*EnableConditionID*/    CONDITION_PHY_BUS,		// Optional
	},
	{  // 2
		/*EnableConditionStatus*/false,		//
		/*EnableConditionID*/    CONDITION_T_STARTUP_ACC,		// Optional
	},
	{// 3
		/*EnableConditionStatus*/TRUE,		//
		/*EnableConditionID*/    CONDITION_DEBUG_AMP,		// Optional
	},
	{   // 4
		/*EnableConditionStatus*/false,		//
		/*EnableConditionID*/    CONDITION_DEBUG_USB,		// Optional
	},
	{  // 5
		/*EnableConditionStatus*/true,		//
		/*EnableConditionID*/    CONDITION_DEBUG_MIC,		// Optional
	},
	{  // 6
		/*EnableConditionStatus*/true,		//
		/*EnableConditionID*/    CONDITION_DEBUG_TUNER,		// Optional
	},
	{ // 7
		/*EnableConditionStatus*/true,		//
		/*EnableConditionID*/    CONDITION_DEBUG_SWC,		// Optional
	},
	{  //  8
		/*EnableConditionStatus*/true,		//
		/*EnableConditionID*/    CONDITION_DEBUG_CAN,		// Optional
	},
	{  //  9
		/*EnableConditionStatus*/true,		//
		/*EnableConditionID*/	 CONDITION_T_IGN_ON,		// Optional
	},
	{  //  10
		/*EnableConditionStatus*/false,		//
		/*EnableConditionID*/    DEM_ENABLE_CONDITION_EOL,		// Optional
	},
} ;

#define DEM_CONDITION_VOLTAGE 	&Dem_EnableCondition[0]
#define DEM_CONDITION_CANBUS  	&Dem_EnableCondition[1]
#define DEM_CONDITION_ACC_DELAY  &Dem_EnableCondition[2]
#define DEM_CONDITION_AMP_DEBUG  &Dem_EnableCondition[3]
#define DEM_CONDITION_USB_DEBUG  &Dem_EnableCondition[4]
#define DEM_CONDITION_MIC_DEBUG  &Dem_EnableCondition[5]
#define DEM_CONDITION_AIRBAG_DEBUG  &Dem_EnableCondition[6]
#define DEM_CONDITION_KEY_DEBUG  &Dem_EnableCondition[7]
#define DEM_CONDITION_CAN_DEBUG  &Dem_EnableCondition[8]
#define DEM_CONDITION_IGN  &Dem_EnableCondition[9]
/**********************************************************************/

/**********************************************************************/
const Dem_EnableConditionType *Dem_EnableCondition_Network[] = 
{
	DEM_CONDITION_VOLTAGE,
	DEM_CONDITION_ACC_DELAY,
	DEM_CONDITION_CANBUS,
	//DEM_CONDITION_IGN,
	//DEM_CONDITION_CAN_DEBUG,
};

Dem_EnableConditionGroupType Dem_EnableConditionGroup_Network ={
    /*nofEnableConditions;*/		3,
    /*Dem_EnableConditionType */	Dem_EnableCondition_Network,
};
/**********************************************************************/

const Dem_EnableConditionType *Dem_EnableCondition_Busoff[] = 
{
	DEM_CONDITION_VOLTAGE,
	DEM_CONDITION_ACC_DELAY,
};

Dem_EnableConditionGroupType Dem_EnableConditionGroup_BusOff ={
    /*nofEnableConditions;*/		2,
    /*Dem_EnableConditionType */	Dem_EnableCondition_Busoff,
};

/**********************************************************************/
const Dem_EnableConditionType *Dem_EnableCondition_Voltage[] = 
{
	DEM_CONDITION_ACC_DELAY,
};

Dem_EnableConditionGroupType Dem_EnableConditionGroup_Voltage ={
    /*nofEnableConditions;*/		1,
    /*Dem_EnableConditionType */	Dem_EnableCondition_Voltage,
};

/**********************************************************************/


const Dem_EnableConditionType *Dem_EnableCondition_LOCAL[] = 
{
	DEM_CONDITION_VOLTAGE,
	DEM_CONDITION_ACC_DELAY,

};

Dem_EnableConditionGroupType Dem_EnableConditionGroup_LOCAL ={
    /*nofEnableConditions;*/		2,
    /*Dem_EnableConditionType */	Dem_EnableCondition_LOCAL,
};

/**********************************************************************/

const Dem_EnableConditionType *Dem_EnableCondition_DUMP[] = 
{
	DEM_CONDITION_VOLTAGE,
	DEM_CONDITION_ACC_DELAY,

};

Dem_EnableConditionGroupType Dem_EnableConditionGroup_DUMP ={
    /*nofEnableConditions;*/		2,
    /*Dem_EnableConditionType */	Dem_EnableCondition_DUMP,
};




const Dem_EventClassType  Dem_EventClass[] = {
	{//dummy
		/*ConsiderPtoStatus*/ 				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/   					3,	     	
		/*FFPrestorageSupported*/ 			false,
		/*HealingAllowed*/      				true,
		/*OperationCycleRef*/   				DEM_POWER,
		/*HealingCycleRef*/     				DEM_WARMUP,
		/*ConfirmationCycleRef*/  				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/ 	1,
		/*HealingCycleCounter*/				DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/        	NULL,
		/*PreDebounceAlgorithmClass*/      	NULL,
		/*IndicatorAttribute*/             	NULL,
	},	
	{//Battery Voltage High
		/*ConsiderPtoStatus*/ 				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/   					3,	     	
		/*FFPrestorageSupported*/ 				false,
		/*HealingAllowed*/      				true,
		/*OperationCycleRef*/   				DEM_POWER,
		/*HealingCycleRef*/     				DEM_WARMUP,
		/*ConfirmationCycleRef*/  				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/ 	1,
		/*HealingCycleCounter*/				DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/        	&Dem_EnableConditionGroup_Voltage,
		/*PreDebounceAlgorithmClass*/      	NULL,
		/*IndicatorAttribute*/             	NULL,
	},
	{//Battery Voltage Low
		/*ConsiderPtoStatus*/ 				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/   					3,	     	
		/*FFPrestorageSupported*/ 				false,
		/*HealingAllowed*/      				true,
		/*OperationCycleRef*/   				DEM_POWER,
		/*HealingCycleRef*/     				DEM_WARMUP,
		/*ConfirmationCycleRef*/  				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/ 	1,
		/*HealingCycleCounter*/				DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/        	&Dem_EnableConditionGroup_Voltage,
		/*PreDebounceAlgorithmClass*/      	NULL,
		/*IndicatorAttribute*/             	NULL,
	},
	{//CAN BusOff error
		/*ConsiderPtoStatus*/				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/						3,			
		/*FFPrestorageSupported*/				false,
		/*HealingAllowed*/						true,
		/*OperationCycleRef*/					DEM_POWER,
		/*HealingCycleRef*/ 					DEM_WARMUP,
		/*ConfirmationCycleRef*/				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/	1,
		/*HealingCycleCounter*/ 			DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/ 		&Dem_EnableConditionGroup_BusOff,
		/*PreDebounceAlgorithmClass*/		NULL,
		/*IndicatorAttribute*/				NULL,
	},
	
//=====================================================================================
	{//backlight temperature hight  
		/*ConsiderPtoStatus*/				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/						3,			
		/*FFPrestorageSupported*/				false,
		/*HealingAllowed*/						true,
		/*OperationCycleRef*/					DEM_POWER,
		/*HealingCycleRef*/ 					DEM_WARMUP,
		/*ConfirmationCycleRef*/				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/	1,
		/*HealingCycleCounter*/ 			DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/ 		&Dem_EnableConditionGroup_LOCAL,
		/*PreDebounceAlgorithmClass*/		NULL,
		/*IndicatorAttribute*/				NULL,
	},
	{//LCD screen temperature hight
		/*ConsiderPtoStatus*/				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/						3,			
		/*FFPrestorageSupported*/				false,
		/*HealingAllowed*/						true,
		/*OperationCycleRef*/					DEM_POWER,
		/*HealingCycleRef*/ 					DEM_WARMUP,
		/*ConfirmationCycleRef*/				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/	1,
		/*HealingCycleCounter*/ 			DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/ 		&Dem_EnableConditionGroup_LOCAL,
		/*PreDebounceAlgorithmClass*/		NULL,
		/*IndicatorAttribute*/				NULL,
	},
	{//Deserializing chip fault
		/*ConsiderPtoStatus*/				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/						3,			
		/*FFPrestorageSupported*/				false,
		/*HealingAllowed*/						true,
		/*OperationCycleRef*/					DEM_POWER,
		/*HealingCycleRef*/ 					DEM_WARMUP,
		/*ConfirmationCycleRef*/				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/	1,
		/*HealingCycleCounter*/ 			DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/ 		&Dem_EnableConditionGroup_LOCAL,
		/*PreDebounceAlgorithmClass*/		NULL,
		/*IndicatorAttribute*/				NULL,
	},
	{//MMI_2A2_LOST 
		/*ConsiderPtoStatus*/				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/						3,			
		/*FFPrestorageSupported*/				false,
		/*HealingAllowed*/						true,
		/*OperationCycleRef*/					DEM_POWER,
		/*HealingCycleRef*/ 					DEM_WARMUP,
		/*ConfirmationCycleRef*/				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/	1,
		/*HealingCycleCounter*/ 			DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/ 		&Dem_EnableConditionGroup_Network,
		/*PreDebounceAlgorithmClass*/		NULL,
		/*IndicatorAttribute*/				NULL,
	},
	{//GW_287_LOST
		/*ConsiderPtoStatus*/				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/						3,			
		/*FFPrestorageSupported*/				false,
		/*HealingAllowed*/						true,
		/*OperationCycleRef*/					DEM_POWER,
		/*HealingCycleRef*/ 					DEM_WARMUP,
		/*ConfirmationCycleRef*/				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/	1,
		/*HealingCycleCounter*/ 			DEM_HEALING_CYCLE_COUNTER,
		/*EnableConditionGroupRef*/ 		&Dem_EnableConditionGroup_Network,
		/*PreDebounceAlgorithmClass*/		NULL,
		/*IndicatorAttribute*/				NULL,
	},
	
	{//dump
		/*ConsiderPtoStatus*/ 				false,
		/*EventDestination*/					DEM_DTC_ORIGIN_PRIMARY_MEMORY,
		/*EventPriority*/   					3,	     	
		/*FFPrestorageSupported*/ 				false,
		/*HealingAllowed*/      				true,
		/*OperationCycleRef*/   				DEM_POWER,
		/*HealingCycleRef*/     				DEM_WARMUP,
		/*ConfirmationCycleRef*/  				DEM_POWER,
		/*ConfirmationCycleCounterThreshold*/ 	1,
		/*HealingCycleCounter*/				40,
		/*EnableConditionGroupRef*/        	&Dem_EnableConditionGroup_DUMP,
		/*PreDebounceAlgorithmClass*/      	NULL,
		/*IndicatorAttribute*/             	NULL,
	},
//===============================================================================

};


const Dem_FreezeFrameRecNumClass Dem_FreezeFrameRecNum = 
{
		{1,0},
};

const Dem_PidOrDidType Dem_PidOrDid[] = {
	

	{//VEHICLE BATTERY VOLTAGE
		/*Dem_CallbackConditionCheckReadFncType*/	Dem_ConditionCheckReadFnc,
		/*DidIdentifier;*/						0xDF00,		
		/*DidReadDataLengthFnc*/				NULL,	// (0..1)
		/*Dem_CallbackReadDataFncType*/			Read_DidReadDataFnc_DF00,
		/*PidIdentifier*/ 						0,			
		/*PidOrDidSize*/  						1,			
		/*PidOrDidUsePort*/						false,				
		/*PidReadFnc;	*/ 						NULL,				
		/*Arc_EOL*/ 							false,
	},
	{//VEHICLESPEED
		/*Dem_CallbackConditionCheckReadFncType*/	Dem_ConditionCheckReadFnc,
		/*DidIdentifier;*/						0xDF01,		
		/*DidReadDataLengthFnc*/		NULL,// (0..1)
		/*Dem_CallbackReadDataFncType*/				Read_DidReadDataFnc_DF01,	
		/*PidIdentifier*/ 						0,			
		/*PidOrDidSize*/  						2,			
		/*PidOrDidUsePort*/						false,				
		/*PidReadFnc;	*/ 						NULL,				
		/*Arc_EOL*/ 							false,
	},
	{//OccurenceCounter
		/*Dem_CallbackConditionCheckReadFncType*/	Dem_ConditionCheckReadFnc,
		/*DidIdentifier;*/						0xDF02,		
		/*DidReadDataLengthFnc*/		NULL,// (0..1)
		/*Dem_CallbackReadDataFncType*/				Read_DidReadDataFnc_DF02,	
		/*PidIdentifier*/ 						0,			
		/*PidOrDidSize*/  						1,			
		/*PidOrDidUsePort*/						false,				
		/*PidReadFnc;	*/ 						NULL,				
		/*Arc_EOL*/ 							false,
	},
    {//TheOdometerOfLastMalfunction
		/*Dem_CallbackConditionCheckReadFncType*/	Dem_ConditionCheckReadFnc,
		/*DidIdentifier;*/						0xDF03,		
		/*DidReadDataLengthFnc*/		NULL,// (0..1)
		/*Dem_CallbackReadDataFncType*/				Read_DidReadDataFnc_DF03,	
		/*PidIdentifier*/ 						0,			
		/*PidOrDidSize*/  						3,			
		/*PidOrDidUsePort*/						false,				
		/*PidReadFnc;	*/ 						NULL,				
		/*Arc_EOL*/ 							false,
	},
	{//TheOdometerOfLastMalfunction
		/*Dem_CallbackConditionCheckReadFncType*/	Dem_ConditionCheckReadFnc,
		/*DidIdentifier;*/						0xDF04,		
		/*DidReadDataLengthFnc*/		NULL,// (0..1)
		/*Dem_CallbackReadDataFncType*/				Read_DidReadDataFnc_DF04,	
		/*PidIdentifier*/ 						0,			
		/*PidOrDidSize*/  						3,			
		/*PidOrDidUsePort*/						false,				
		/*PidReadFnc;	*/ 						NULL,				
		/*Arc_EOL*/ 							false,
	},
	{//DUMMY
		/*Dem_CallbackConditionCheckReadFncType*/	NULL,
		/*DidIdentifier;*/						0x6012,		
		/*DidReadDataLengthFnc*/		NULL,// (0..1)
		/*Dem_CallbackReadDataFncType*/				NULL,	
		/*PidIdentifier*/ 						0,			
		/*PidOrDidSize*/  						1,			
		/*PidOrDidUsePort*/						false,				
		/*PidReadFnc;	*/ 						NULL,				
		/*Arc_EOL*/ 						TRUE,
	},
} ; /** @req DEM136 */

const Dem_PidOrDidType 	*FFIdClassRef[] = 
{
	&Dem_PidOrDid[0],
	&Dem_PidOrDid[1],
	&Dem_PidOrDid[2],
	&Dem_PidOrDid[3],
	&Dem_PidOrDid[4],
	NULL,
};

const Dem_FreezeFrameClassType Dem_FreezeFrameClass = {
	/*Dem_FreezeFrameKindType*/ DEM_FREEZE_FRAME_NON_OBD,			// (1)
	/*Dem_PidOrDidType*/ 	FFIdClassRef	,
}; 

Std_ReturnType Dem_CallbackGetExtDataRecordAged(uint8_t *ExtendedDataRecord) ;
Std_ReturnType Dem_CallbackGetExtDataRecordAging(uint8_t *ExtendedDataRecord);
Std_ReturnType Dem_CallbackGetExtDataRecordFaultOccured(uint8_t *ExtendedDataRecord) ;


#if 0
Dem_ExtendedDataRecordClassType Dem_ExtendedDataRecordClass[] = {
	{
		/*RecordNumber;*/						0x0001,						// (1)
		/*DataSize*/							1	,			// (1)
		/*UpdateRule*/						DEM_UPDATE_RECORD_YES,
		/*Dem_CallbackGetExtDataRecordFncType*/	NULL,
		/*Dem_InternalDataElementType*/		DEM_OCCCTR,
	},
	{
		/*RecordNumber;*/						0x0002,						// (1)
		/*DataSize*/							1	,			// (1)
		/*UpdateRule*/						DEM_UPDATE_RECORD_YES,
		/*Dem_CallbackGetExtDataRecordFncType*/	NULL,
		/*Dem_InternalDataElementType*/		DEM_PENDINGCNT,
	},
	{
		/*RecordNumber;*/						0x0003,						// (1)
		/*DataSize*/							1	,			// (1)
		/*UpdateRule*/						DEM_UPDATE_RECORD_YES,
		/*Dem_CallbackGetExtDataRecordFncType*/	NULL,
		/*Dem_InternalDataElementType*/		DEM_AGED,
	},
	{
		/*RecordNumber;*/						0x0004,						// (1)
		/*DataSize*/							1	,			// (1)
		/*UpdateRule*/						DEM_UPDATE_RECORD_YES,
		/*Dem_CallbackGetExtDataRecordFncType*/	NULL,
		/*Dem_InternalDataElementType*/		DEM_AGING,
	},
} ; /** @req DEM135 */
Dem_ExtendedDataClassType Dem_ExtendedDataClass ={
	{
		&Dem_ExtendedDataRecordClass[0],
		&Dem_ExtendedDataRecordClass[1],
		&Dem_ExtendedDataRecordClass[2],
		&Dem_ExtendedDataRecordClass[3],
	    NULL,
	},
} ; 

#else//FE-7
Dem_ExtendedDataRecordClassType Dem_ExtendedDataRecordClass[] = {
	{
		/*RecordNumber;*/						0x0001,						// (1)
		/*DataSize*/							1	,			// (1)
		/*UpdateRule*/						DEM_UPDATE_RECORD_YES,
		/*Dem_CallbackGetExtDataRecordFncType*/	NULL,
		/*Dem_InternalDataElementType*/		DEM_OCCCTR,
	},
	{
		/*RecordNumber;*/						0x0002,						// (1)
		/*DataSize*/							1	,			// (1)
		/*UpdateRule*/						DEM_UPDATE_RECORD_YES,
		/*Dem_CallbackGetExtDataRecordFncType*/	NULL,
		/*Dem_InternalDataElementType*/		DEM_AGING,
	},
} ; /** @req DEM135 */
Dem_ExtendedDataClassType Dem_ExtendedDataClass ={
	{
		&Dem_ExtendedDataRecordClass[0],
		&Dem_ExtendedDataRecordClass[1],
	    NULL,
	},
} ; 

#endif


Dem_CallbackEventStatusChangedType Dem_CallbackEventStatusChanged[] = {
	{
	   NULL,//{Dem_CallbackEventStatusChangedFncWithId},	// (0..1)
		/*UsePort*/false,
		/*Arc_EOL*/false,
	},
	{//dummy
	  NULL,//{Dem_CallbackEventStatusChangedFncWithId},	// (0..1)
		/*UsePort*/false,
		/*Arc_EOL*/true,
	},
}; /** @req DEM140 */


const Dem_EventParameterType EventParameter[] = {
	//==============================================================================
		{
			/*EventID*/ 					DEM_EVENT_VOLTAGE_HIGH,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_VOLTAGE_HIGH],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_VOLTAGE_HIGH],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{
			/*EventID*/ 					DEM_EVENT_VOLTAGE_LOW,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_VOLTAGE_LOW],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_VOLTAGE_LOW],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{//dummy
			/*EventID*/ 					DEM_EVENT_CAN_BUSOFF,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_CAN_BUSOFF],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_CAN_BUSOFF],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,//TRUE,
		},
		{
			/*EventID*/ 					DEM_EVENT_BK_TEMP_HIGH,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_BK_TEMP_HIGH],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_BK_TEMP_HIGH],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{
			/*EventID*/ 					DEM_EVENT_LCD_TEMP_HIGH,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_LCD_TEMP_HIGH],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_LCD_TEMP_HIGH],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{
			/*EventID*/ 					DEM_EVENT_DESER_ERR,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_DESER_ERR],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_DESER_ERR],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{
			/*EventID*/ 					DEM_EVENT_MMI_2A2_LOST,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_DESER_ERR],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_DESER_ERR],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{
			/*EventID*/ 					DEM_EVENT_GW_287_LOST,
			/*EventKind*/					DEM_EVENT_KIND_BSW,
			/*MaxNumberFreezeFrameRecords*/ 1,
			/*EventClass*/					&Dem_EventClass[DEM_EVENT_DESER_ERR],
			/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
			/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
			/*CallbackInitMforE*/			NULL,
			/*CallbackEventStatusChanged*/	 NULL,
			/*CallbackClearEventAllowed*/	 NULL,
			/*CallbackEventDataChanged	*/	 NULL,
			/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_DESER_ERR],
			/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
			/*.Arc_EOL	= */			   false,
		},
		{
				/*EventID*/ 					DEM_EVENT_END,
				/*EventKind*/					DEM_EVENT_KIND_BSW,
				/*MaxNumberFreezeFrameRecords*/ 1,
				/*EventClass*/					&Dem_EventClass[DEM_EVENT_END],
				/*ExtendedDataClassRef*/		&Dem_ExtendedDataClass,
				/*FreezeFrameClassRef*/ 		&Dem_FreezeFrameClass,
				/*CallbackInitMforE*/			NULL,
				/*CallbackEventStatusChanged*/	 NULL,
				/*CallbackClearEventAllowed*/	 NULL,
				/*CallbackEventDataChanged	*/	 NULL,
				/*Dem_DTCClassType*/			&Dem_DTCClass[DEM_EVENT_END],
				/*FreezeFrameRecNumClassRef*/		&Dem_FreezeFrameRecNum,
				/*.Arc_EOL	= */			   TRUE,//false,
			}
	//==============================================================================

};









/*
 * DEM's config set
 */
const Dem_ConfigSetType DEM_ConfigSet = {
	/* EventParameter           */ EventParameter,
	/* Dem_DTCClassType         */ Dem_DTCClass,
	/* Dem_GroupOfDtcType       */ NULL,
	/* Dem_OemIdClassType       */ NULL,
	/* Dem_EnableConditionType  */ Dem_EnableCondition,
	/* Dem_FreezeFrameClassType */ NULL,
};

/*
 * DEM's config
 */
const Dem_ConfigType DEM_Config = {
	/*.ConfigSet =*/ &DEM_ConfigSet,
};
