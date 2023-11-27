#include "TnStatus.h"

#ifndef TN_STATUS_LIGHT
TnStatus CreateStatus(TnStatusCode code, size_t line, const char* file) {
  assert(file);
  TnStatus status = {code, line, file};
  return status;
} 
#else
TnStatus CreateStatus(TnStatusCode code) {
  TnStatus status = {code};
  return status;
}
#endif

const char* TnStatusCodeGetDescription(TnStatusCode code) {
  switch(code) {
    #define TN_STATUS_DECLARE(code, description) case code: return #description;
    #include "TnStatusCode.decl"
    #undef TN_STATUS_DECLARE

    case TN_ERRNO: return strerror(errno);
    default: return "Undefined status code";
  }
}

void TnStatusPrintDescription(TnStatus status) {
  #ifndef TN_STATUS_LIGHT
  fprintf(stderr, "File %s, line %zu: ", status.File, status.Line);
  #endif

  fprintf(stderr, "%s", TnStatusCodeGetDescription(status.Code));
}

int TnStatusOk(TnStatus status) {
  return status.Code == TN_SUCCESS;
}

void TnStatusAssert(TnStatus status) {
  if (TnStatusOk(status)) return;

  fprintf(stderr, "TnStatus assertion failed: ");
  TnStatusPrintDescription(status);
  fprintf(stderr, "\n");
  exit(1);
}