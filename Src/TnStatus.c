#include "TnStatus.h"

#ifdef TN_STATUS_EXTENDED
TnStatus CreateStatus(TnStatusCode code, size_t line, const char* function, const char* file, const char* comment) {
  TnStatus status = {code, line, function, file, comment};
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

    default: return "Undefined status code";
  }
}

void TnStatusPrintDescription(TnStatus status) {
  #ifdef TN_STATUS_EXTENDED
  fprintf(stderr, "%s, %s, %zu: ", status.File, status.Function, status.Line);
  if (status.Comment)
    fprintf(stderr, "%s: ", status.Comment);
  #endif

  fprintf(stderr, "%s", TnStatusCodeGetDescription(status.Code));
}