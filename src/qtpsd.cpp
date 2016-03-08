#include "qtpsd.h"
#include "./private/psd.h"
#include <QFile>
#include <QbyteArray>
#include <QDir>
#include <iostream>

namespace QPSD {
    QImage loadWholeImage(const QString filePath) {
        QFile file(filePath);
        QImage result;
        if (file.open(QIODevice::ReadOnly)) {
            std::cout << file.errorString().toStdString() << std::endl;
            auto data = file.readAll();
            psd_buffer_t *buffer = psdBufferCreate((const psd_uint8_t *)data.constData(), (psd_rsize_t)data.size());
            psd_document_t *document = psdDocumentCreate();
            psdDocumentParse(document, buffer);
            psdDocumentExtractImage(document);
            const psd_header_t *header = psdDocumentGetHeader(document);
            psd_size_t size = psdHeaderGetSize(header);
            psd_rsize_t ncomponents = 4;
            if (const psd_uint8_t *pixel_data = psdImageGetPixelData(psdDocumentGetImage(document))) {
                psd_rsize_t stride = psdHeaderGetStrideLength(header) * ncomponents;
                result = QImage(pixel_data, size.columns, size.rows, stride, QImage::Format_RGBA8888);
            }
            psdDocumentDestroy(document);
            psdBufferDestroy(buffer);
        }
        return result;
    }
}

#include "moc_qtpsd.cpp"
