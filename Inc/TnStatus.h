#pragma once
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>

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
  
  #ifndef TN_STATUS_LIGHT
  size_t Line;
  const char* File;
  #endif
} TnStatus;

#ifndef TN_STATUS_LIGHT
TnStatus CreateStatus(TnStatusCode code, size_t line, const char* file);
#define TNSTATUS(code) CreateStatus(code, __LINE__,  __FILE__);
#else
TnStatus CreateStatus(TnStatusCode code);
#define TNSTATUS(code) CreateStatus(code);
#endif

#define TN_OK TNSTATUS(TN_SUCCESS)

const char* TnStatusCodeGetDescription(TnStatusCode code);
void TnStatusPrintDescription(TnStatus status);
int TnStatusOk(TnStatus status);
void TnStatusAssert(TnStatus status);

#ifdef __cplusplus
}
#endif