#include <iostream>
#include <fstream>
#include <exception>
#include "ADT_Time.h"



using namespace std;



int main()
{
    

    Time t1(12, 4, 4);

    t1.Get_time_Console();

    t1.Set_hour(18);

    t1.Set_minute(27);

    t1.Set_second(9);


    cout << "Моих минут: " << t1.Get_minute() << "\t Часиков-то уже " << t1.Get_hour() << "! Пора бы удаляться из бара и идти делать дела...\n";



}