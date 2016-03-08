#ifndef QTPSD_H
#define QTPSD_H

#include "qtpsd_global.h"
#include <QString>
#include <QImage>

/*!
 * \namespace QPSD
 *
 * \brief QPSD namespace contains PSD file loader functions.
 */
namespace QPSD {
    QImage loadWholeImage(const QString filePath);
}

#endif // QTPSD_H
