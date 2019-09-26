#include "passwordassembly.h"
#include <QMessageBox>

char PasswordAssembly::setLowerCaseLetter()
{
    char newLowerLetter;
    newLowerLetter = static_cast<char>(97 + rand() % (122 - 97));
    return newLowerLetter;
}

char PasswordAssembly::setUpperCaseLetter()
{
    char newUpperLetter;
    newUpperLetter = static_cast<char>(65 + rand() % (90 - 65));
    return newUpperLetter;
}

char PasswordAssembly::setTheNumbers()
{
    char newNumber;
    newNumber = static_cast<char>(48 + rand() % (57 - 48));
    return newNumber;
}

QString PasswordAssembly::AssemblyNewPassword()
{
    QString generateNewPassword;
    int choiseSymbol = 0;
    bool checkUpperAssembly = checkUpper;
    bool checkNumberAssembly = checkNumber;
    for (int i = 0; i < setUserQuantityPassword; i++)
    {
        choiseSymbol = rand() % 3 + 1;
        switch (choiseSymbol)
        {
        case 1:
            generateNewPassword.push_back(setLowerCaseLetter());
            break;
        case 2:
            if (checkUpper == true)
            {
                generateNewPassword.push_back(setUpperCaseLetter());
                checkUpperAssembly = false;
            }
            else
            {
                generateNewPassword.push_back(setLowerCaseLetter());
            }
            break;
        case 3:
            if (checkNumber == true)
            {
                generateNewPassword.push_back(setTheNumbers());
                checkNumberAssembly = false;
            }
            else
            {
                generateNewPassword.push_back(setLowerCaseLetter());
            }
            break;
        }
    }
    while (checkUpperAssembly == true || checkNumberAssembly == true)
    {
        choiseSymbol = rand() % 2;
        if (checkUpperAssembly == true && !generateNewPassword[choiseSymbol].isNumber())
        {
            generateNewPassword[choiseSymbol] = setUpperCaseLetter();
            checkUpperAssembly = false;
        }
        if (checkNumberAssembly == true && !generateNewPassword[choiseSymbol].isUpper())
        {
            generateNewPassword[choiseSymbol] = setTheNumbers();
            checkNumberAssembly = false;
        }
    }
    return generateNewPassword;
}
