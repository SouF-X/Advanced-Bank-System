#pragma once
#include <iostream>
#include "clsCurrency.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencies.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyExChangeOptions {eListCurrencies = 1, eFindCurrencies = 2,
									eUpdateCurrencies = 3, eCurrenciesCalculator = 4,
									eBackToMainMenue = 5
    };

    static short _ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowListCurrencyScreen()
    {
        //cout << "List Currency Screen Will Be Here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "Find Currency Screen Will Be Here.\n";
        clsFindCurrencies::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "Update Rate Screen Will Be Here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "Currency Calculator Screen Will Be Here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _PerformCurrencyExchangeOption(enCurrencyExChangeOptions CurrencyExchangeOption)
    {
        switch (CurrencyExchangeOption)
        {
        case enCurrencyExChangeOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExChangeOptions::eFindCurrencies:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExChangeOptions::eUpdateCurrencies:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExChangeOptions::eCurrenciesCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExChangeOptions::eBackToMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:

    static void ShowCurrencyExchangeMenue()
    {

        system("cls");
        _DrawScreenHeader("  Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeOption((enCurrencyExChangeOptions)_ReadCurrencyExchangeMenueOption());
    }
};

