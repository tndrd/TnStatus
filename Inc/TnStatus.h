#pragma once
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  #define TN_STATUS_DECLARE(code, description) code,
  #include "TnStatusCode.decl"
  #undef TN_STATUS_DECLARE

  TN_ERRNO
} TnStatusCode;

typedef struct {
  TnStatusCode Code;
  
  #ifdef TN_STATUS_EXTENDED
  size_t Line;
  const char* Function;
  const char* File;
  const char* Comment;
  #endif
} TnStatus;

#ifdef TN_STATUS_EXTENDED
TnStatus CreateStatus(TnStatusCode code, size_t line, const char* function, const char* file, const char* comment);
#define TNSTATUS_C(code, comment) CreateStatus(code, __LINE__, __FUNCTION__, __FILE__, comment);
#else
TnStatus CreateStatus(TnStatusCode code);
#define TNSTATUS_C(code, comment) CreateStatus(code);
#endif

#define TNSTATUS(code) TNSTATUS_C(code, NULL)
#define TN_OK TNSTATUS(TN_SUCCESS)

const char* TnStatusCodeGetDescription(TnStatusCode code);
void TnStatusPrintDescription(TnStatus status);
int TnStatusOk(TnStatus status);

#ifdef __cplusplus
}
#endif