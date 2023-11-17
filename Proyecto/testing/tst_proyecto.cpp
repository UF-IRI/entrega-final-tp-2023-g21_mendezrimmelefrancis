#include <catch2/catch.hpp>

// TestMathFunctions.cpp
#include <QtTest/QTest>
#include "clases.h"
class TestMathFunctions : public QObject {
    Q_OBJECT
private slots:
    void testAddition() {
        QCOMPARE(suma(2, 3), 5);
        QCOMPARE(suma(-2, 2), 0);
        QCOMPARE(suma(0, 0), 0);


    }
};

