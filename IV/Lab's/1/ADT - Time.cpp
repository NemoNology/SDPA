#include <iostream>
#include <fstream>
#include <exception>
#include "Time.h"
#include "File_Unit.h"



using namespace std;



int main()
{
    
    setlocale(LC_ALL, "Russian");

    fstream f;

    f.open("Res.txt");


    Time t1(12, 5, 4);


   Record_to_file(f, t1.Get_string_time());


    t1.Set_hour(14);

    t1.Set_minute(27);

    t1.Set_second(9);


    Record_to_file(f, "Hour (Not seconds!):" + t1.Get_hour());


    Record_to_file(f, "New data:\n" + t1.Get_string_time());
    

    system("pause");

    return 0;

}