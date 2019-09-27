#include "passwordassembly.h"
#include <QMessageBox>

char PasswordAssembly::setLowerCaseLetter()
{
    char newLowerLetter;
    newLowerLetter = static_cast<char>(MIN_CODE_LOWER + rand() % (MAX_CODE_LOWER - MIN_CODE_LOWER));
    return newLowerLetter;
}

char PasswordAssembly::setUpperCaseLetter()
{
    char newUpperLetter;
    newUpperLetter = static_cast<char>(MIN_CODE_UPPER + rand() % (MAX_CODE_UPPER - MIN_CODE_UPPER));
    return newUpperLetter;
}

char PasswordAssembly::setTheNumbers()
{
    char newNumber;
    newNumber = static_cast<char>(MIN_CODE_NUM + rand() % (MAX_CODE_NUM - MIN_CODE_NUM));
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
        choiseSymbol = rand() % MAX_DIVERSITY_SYMBOL + 1;
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
        choiseSymbol = rand() % generateNewPassword.size() - 1;
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
