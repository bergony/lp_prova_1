#include <iostream>
#include <fstream>

int main ( void )
{
    std::ofstream fout("saida.txt");
    std::ifstream fin("entrada.txt");

    int fuel{0};
    int big{0};
    int small{0};
    int count{0};
    std::string line;
    while(true){
        std::getline(fin, line);
        big = atoi (line[0]);
        small = atoi (line[0]);

        std::cout << "big:" << line[0] << " small:" << small <<  "\n";
        for(int i{0}; i < line.length();i++)
        {
            if(small > line[i])
            {
                small = line[i];
            }
            if(big < line[i])
            {
                big = line[i];
            }
        }
//        std::cout << "big:" << big << " small:" << small <<  "\n";

          if(fin.fail())
              break;
            fout << line[0] << "\n";
    }
    fout.close();
    fin.close();
    return 0;
}
