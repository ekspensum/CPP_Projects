#include <QtTest>

// add necessary includes here
//#include <networkapi.h>
#include <validation.h>
#include <mainlogin.h>
#include <user.h>


class AllTests : public QObject
{
    Q_OBJECT

private:
    Validation val;

public:
    AllTests();
    ~AllTests();

private slots:
    void test_caseValidation();
    void test_caseMainLogin();


};

AllTests::AllTests()
{

}

AllTests::~AllTests()
{

}

void AllTests::test_caseValidation()
{
    QVERIFY(val.validName("name"));
    QVERIFY(!val.validName("name;"));
    QVERIFY(val.validEmail("name.name@gmail.com"));
    QVERIFY(!val.validEmail("name,name@gmail.com"));
    QVERIFY(val.validLogin("abc2"));
    QVERIFY(!val.validLogin("abć2"));
    QVERIFY(!val.validLogin("abdefghijk2"));
    QVERIFY(!val.validLogin("abc"));
    QVERIFY(val.validPassword(";{8y5"));
    QVERIFY(!val.validPassword(";{8y"));
    QVERIFY(val.validProductName("product name!*"));
    QVERIFY(!val.validProductName("p"));
    QVERIFY(!val.validProductName("product \"name\""));
    QVERIFY(val.validProductDescription("product description &*()"));
    QVERIFY(!val.validProductDescription("p"));
    QVERIFY(!val.validProductDescription("product \"description\" = opis#;"));
}

void AllTests::test_caseMainLogin()
{

}

QTEST_APPLESS_MAIN(AllTests)

#include "tst_alltests.moc"
