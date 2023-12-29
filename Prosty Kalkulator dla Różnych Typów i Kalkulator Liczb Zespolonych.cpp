#include <iostream>
#include <Windows.h>
#include <math.h>
#include <cstdlib>




    double Dodawanie(double a, double b) {
        return a + b;
    }

    double Odejmowanie(double a, double b) {
        return a - b;
    }

    double Mnozenie(double a, double b) {
        return a * b;
    }

    double Dzielenie(double a, double b) {
        if (b == 0) {
            std::cout << "Nie dziel przez 0!\n";
            return 0;  // Dodano zwrot wartości, aby przerwać operację
        }
        else {
            return a / b;
        }
    }


    std::pair<double, double> DodawanieZesp(double a, double b, double c, double d) {
        double e, f;
        e = a + c;
        f = b + d;
  
        return std::make_pair(e, f);
    }

    std::pair<double, double> OdejmowanieZesp(double a, double b, double c, double d) {
       
        double e, f;
        e = a - c;
        f = b - d;

        return std::make_pair(e, f);

    }

    std::pair<double, double> MnozenieZesp(double a, double b, double c, double d) {
        double e, f;
        e = (a * c) - (b * d);
        f = (a * d) + (b * c);

        return std::make_pair(e, f);
    }

    std::pair<double, double> DzielenieZesp(double a, double b, double c, double d) {
        if (c == 0 && d == 0) {
            std::cout << "Nie dziel przez 0!\n";
            exit(1);  // Dodano zwrot wartości, aby przerwać operację
        }
        else {
            
            double e, f;

            e = ((a * c) + (b * d) / (pow(c, 2) + pow(d, 2)));
            f = ((b * c) - (a * d) / (pow(c, 2) + pow(d, 2)));

            return std::make_pair(e, f);


        }
    }










    void UstawKolor(int kolor) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolor);
    }


    void PokazMenu() {
        std::cout << "Prosty Kalkulator Matematyczny\n";
        UstawKolor(12);
        std::cout << "1.";
        UstawKolor(15); //15 biały 12 lekko czerwony
        std::cout << "Dodawanie\n";
        UstawKolor(12);
        std::cout << "2.";
        UstawKolor(15); 
        std::cout << "Odejmowanie\n";
        UstawKolor(12);
        std::cout << "3.";
        UstawKolor(15); 
        std::cout << "Mnożenie\n";
        UstawKolor(12);
        std::cout << "4.";
        UstawKolor(15);
        std::cout << "Dzielenie\n";
        UstawKolor(2);
        std::cout << "Kalkulator liczb zespolonych\n";
        UstawKolor(11);
        std::cout << "5.";
        UstawKolor(15); //15 biały 12 lekko czerwony
        std::cout << "Dodawanie\n";
        UstawKolor(11);
        std::cout << "6.";
        UstawKolor(15);
        std::cout << "Odejmowanie\n";
        UstawKolor(11);
        std::cout << "7.";
        UstawKolor(15);
        std::cout << "Mnożenie\n";
        UstawKolor(11);
        std::cout << "8.";
        UstawKolor(15);
        std::cout << "Dzielenie\n";
        UstawKolor(11);
        std::cout << "9.";
        UstawKolor(15);
        std::cout << "Wyjście\n";

    }


    std::pair<double, double> WprowadzDaneLiczba() {
        double liczba_A, liczba_B;
        // Wprowadzanie danych
        std::cout << "Podaj pierwszą liczbę:  ";
        std::cin >> liczba_A;
        std::cout << "\n";
        std::cout << "Podaj drugą liczbę:  ";
        std::cin >> liczba_B;

        return std::make_pair(liczba_A, liczba_B);
    }


int main(){
        int wybor;
        char odpowiedz;
            std::pair<double, double> liczba_pierwsza;

            std::pair<double, double> liczba_druga;
            std::pair<double, double> wynikDodawaniaZesp, wynikOdejmowaniaZesp, wynikMnozeniaZesp, wynikDzieleniaZesp;

        while (true) {
            

            PokazMenu();
            std::cout << "\n";
            std::cout << "Wybierz operację (1-9):  \n";
            std::cin >> wybor;

            if (wybor >= 1 && wybor <= 4) {
                liczba_pierwsza = WprowadzDaneLiczba();
            }
        

            
            //Przekazanie danych do odpowiedniej funkcji i wyświetlenie wyniku
            switch (wybor) {

            case 1:
                std::cout << "Wynik dodawania:" << Dodawanie(liczba_pierwsza.first, liczba_pierwsza.second) << '\n';
                break;
            case 2:
                std::cout << "Wynik odejmowania:" << Odejmowanie(liczba_pierwsza.first, liczba_pierwsza.second) << '\n';
                break;
            case 3:
                std::cout << "Wynik mnozenia:" << Mnozenie(liczba_pierwsza.first, liczba_pierwsza.second) << '\n';
                break;
            case 4:
                std::cout << "Wynik dzielenia:" << Dzielenie(liczba_pierwsza.first, liczba_pierwsza.second) << '\n';
                break;
            case 5:
                liczba_druga = WprowadzDaneLiczba();
                wynikDodawaniaZesp = DodawanieZesp(liczba_pierwsza.first, liczba_pierwsza.second, liczba_druga.first, liczba_druga.second);
                std::cout << "Wynik dodawania: " << wynikDodawaniaZesp.first << "+ " << wynikDodawaniaZesp.second << "i\n";
                break;
            case 6:
                liczba_druga = WprowadzDaneLiczba();
                 wynikOdejmowaniaZesp = OdejmowanieZesp(liczba_pierwsza.first, liczba_pierwsza.second, liczba_druga.first, liczba_druga.second);
                std::cout << "Wynik Odejmowania: " << wynikOdejmowaniaZesp.first << "+ " << wynikOdejmowaniaZesp.second << "i\n";
                break;
            case 7:
                liczba_druga = WprowadzDaneLiczba();
                 wynikMnozeniaZesp = MnozenieZesp(liczba_pierwsza.first, liczba_pierwsza.second, liczba_druga.first, liczba_druga.second);
                std::cout << "Wynik Odejmowania: " << wynikMnozeniaZesp.first << "+ " << wynikMnozeniaZesp.second << "i\n";
                break;
            case 8:
                liczba_druga = WprowadzDaneLiczba();
                wynikDzieleniaZesp = DzielenieZesp(liczba_pierwsza.first, liczba_pierwsza.second, liczba_druga.first, liczba_druga.second);
                std::cout << "Wynik Odejmowania: " << wynikDzieleniaZesp.first << "+ " << wynikDzieleniaZesp.second << "i\n";
                break;
            case 9:
                std::cout << "Dziękujemy za skorzystanie z kalkulatora!";
                return 0;
            default:
                std::cout << "Zła operacja\n";
            }
                //Warunek czy chcemy przeprowadzić jeszcze jakieś operacje
                std::cout << "Czy chcesz kontynuować? (T/N): ";
                std::cin >> odpowiedz;

                if (odpowiedz == 'N' || odpowiedz == 'n') {
                    std::cout << "Koniec programu.\n";
                    break;
                }
                else if (odpowiedz == 'T' || odpowiedz == 't') {
                    continue;
                }
                else {
                    std::cout << "Nieprawidłowy znak. Wprowadź 'T' lub 'N'.\n";
                }
            }

            return 0;

        }









