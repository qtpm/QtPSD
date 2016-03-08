#include <QString>
#include <QtTest>
#include <QImage>
#include "qtpsd.h"

class TestQtPSD : public QObject {
    Q_OBJECT

public:
    TestQtPSD() {

    }

private Q_SLOTS:
    void testLoadWholeImage() {
        auto image = QPSD::loadWholeImage("../test/test.psd");
        QCOMPARE(image.width(), 1012);
        QCOMPARE(image.height(), 834);
    }
};

QTEST_APPLESS_MAIN(TestQtPSD)

#include "qtpsd_test.moc"
