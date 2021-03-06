/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef ERROR_H
#define ERROR_H
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream
using namespace std;

#ifdef TRACEALLOC
#define NEW(x) {cerr << "$$$ New " << x << "<BR>\n"; }
#define DELETE(x) {cerr << "$$$ Delete " << x << "<BR>\n"; }
#else
#define NEW(x)
#define DELETE(x)
#endif


#define WARNING_MSG(msg)  {cerr << "WARNING: " << "<BR>" << msg << "<BR>" << endl;}								

#define ERROR(msg) {\
try {\
  ostringstream oss;\
  oss << msg << "<BR>" << endl;\
  throw oss.str();\
 }\
 catch (string message) {\
   cout << message << endl;\
 }\
}

#define ERROR_MSG_LINE(msg)  {ERROR(msg); cerr << "PACKAGE: " << PACKAGE_NAME << "<BR>" << endl << "PACKAGE_VERSION: " << PACKAGE_VERSION << "<BR>" << endl << "BREAK: " << __FILE__ << "(" << __LINE__ << ")" << "<BR>" << "PLEASE SEND THIS MESSAGE TO <a href=\"mailto:lionel.clement@labri.fr?subject=BUG REPORT&body=bug report: GAT version "<< PACKAGE_VERSION << " it has stopped at " << __FILE__ << "(" << __LINE__ << ')' <<"\">lionel.clement@labri.fr</a>" << "<BR>" << endl;}

#define FATAL_ERROR {ERROR_MSG_LINE("fatal error");}

#endif // ERROR_H
