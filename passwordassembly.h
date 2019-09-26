#ifndef PASSWORDASSEMBLY_H
#define PASSWORDASSEMBLY_H

#include <QString>
#include <ctime>

class PasswordAssembly
{
private:
    int setUserQuantityPassword;
    bool checkUpper;
    bool checkNumber;

public:
    QString AssemblyNewPassword();
    char setLowerCaseLetter();
    char setUpperCaseLetter();
    char setTheNumbers();
    PasswordAssembly(int setQuantity, bool upperCheck, bool numberCheck)
    {
        checkUpper = upperCheck;
        checkNumber = numberCheck;
        setUserQuantityPassword = setQuantity;
    }
};

#endif // PASSWORDASSEMBLY_H
