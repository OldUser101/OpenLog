#ifndef _OLOG_STRUCTURE
#define _OLOG_STRUCTURE
#endif
// This file defines structures that are used by log files internally


#include <stdint.h>

#define _ID "OLG\0"
#define _MIN_VER 1
#define _MAJ_VER 0

#define ATTRIBUTE_MULTIPLE_FILES 0x1
#define ATTRIBUTE_STATUS_FATAL 0x80000001
#define ATTRIBUTE_STATUS_ERROR 0x80000002
#define ATTRIBUTE_STATUS_WARNING 0x80000004
#define ATTRIBUTE_STATUS_INFO 0x80000008

#pragma pack(push, 1)

typedef struct _LOG_HEADER
{
	char id[4];
	uint8_t minorVersion;
	uint8_t majorVersion;
	uint32_t nEvents;
	uint32_t eventsOffset;
	uint16_t attributes;
	char nextFile[12];
} LOG_HEADER;

typedef struct _EVENT_INFO
{
	uint32_t code;
	uint32_t time;
	uint32_t dataLen;
	uint32_t dataOffset;
	uint32_t attributes;
} EVENT_INFO;

#pragma pack(pop)