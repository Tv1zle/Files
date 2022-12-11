#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main()
{
    FILE* file;
    fopen_s(&file, "D:/C++_gamProject/HomeWork 31/hw.txt", "a+");


    char* word = new char[25];
    std::cout << "Word:";
    std::gets(word);
    fseek(file, 0, SEEK_SET);


   while (true)
    {
        if ((char*)fgetc(file) == " ")
        {
            fseek(file, -1, SEEK_CUR);
            if (word[-1] == (char)fgetc(file))
            {
                fseek(file, -1, SEEK_CUR);
                if (word[-2] == (char)fgetc(file))
                {
                    for (int i = -10; i <= 2; i++)
                    {
                        fseek(file, i, SEEK_CUR);
                        char s = fgetc(file);
                        std::cout << s;
                    }
                    fputs("\n", file);
                    std::cout << "\n";
                }
            }
        }
        else
            fseek(file, 1, SEEK_CUR);


        if (feof(file) == 0)
            continue;
        else
            break;
    }
    delete[] word;
}