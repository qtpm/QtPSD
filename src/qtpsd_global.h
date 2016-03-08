#ifndef QTPSD_GLOBAL_H
#define QTPSD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTPSD_LIBRARY)
#  define QTPSDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTPSDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTPSD_GLOBAL_H

