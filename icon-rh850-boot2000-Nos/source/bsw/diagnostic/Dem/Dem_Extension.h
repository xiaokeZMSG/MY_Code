#ifndef __DEM_EXTENSION__
#define __DEM_EXTENSION__
#include "Dem.h"
Std_ReturnType Dem_CallbackGetExtDataRecordAged(uint8_t *ExtendedDataRecord) ;
Std_ReturnType Dem_CallbackGetExtDataRecordAging(uint8_t *ExtendedDataRecord);
Std_ReturnType Dem_CallbackGetExtDataRecordFaultOccured(uint8_t *ExtendedDataRecord) ;
#endif
