#include <QtTest>

// add necessary includes here
#include <validation.h>
#include <user.h>
#include <mainlogin.h>

class AllTests : public QObject
{
    Q_OBJECT

private:
    Validation val;
    MainLogin mainLogin;


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
    QCOMPARE("Admin", mainLogin.getLoggedUser("admin1", "Admin11")->getRole());
    QCOMPARE("admin1", mainLogin.getLoggedUser("admin1", "Admin11")->getLogin());
    QCOMPARE("Admin", mainLogin.readFileUsersList().at(0)->getRole());
    QCOMPARE("admin1", mainLogin.readFileUsersList().at(0)->getLogin());
}

QTEST_APPLESS_MAIN(AllTests)

#include "tst_alltests.moc"
