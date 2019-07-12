#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
   // string item, header;
   // int cost=0, total=0, starting_money, k = 0;
    string DeckName;
    int R=0, A=0, S=0, D=0, F=0, P=0, Tax=0, Tax_cost=0, Cost=0, Scratch=0, loop_count=0;
    float Percent = 0, Percent_Ave=0;

    ifstream file;
    file.open("deck_stats.txt");
    if (!file)
    {
        cout << "Error. File not present.";
        return 9001;
    }
    //ofstream output;
    //output.open("Deck_Output.txt");
    //------------------------------------------- simple file check

    cout << left << fixed<< endl;
    //output << left << fixed;
    //cout << setw(25) << DeckName << starting_money << endl << endl;
    cout << setw(25) << "Deck" << setw(12) << " Array" << setw(8) <<"Cost" <<setw(10) << "Scratch"<<setw(10) << "Percenage"<<"Tax\n---------------------------------------------------------------------\n";
    //output << setw(25) << "Deck" << setw(12) << " Array" << setw(8) <<"Cost" <<setw(10) << "Scratch"<<setw(10) << "Percenage\n----------------------------------------------------------------\n";
    while (!file.eof())
    {
    file >> DeckName >> R >> A >> S >> D >> F >> P>> Cost;

    Tax = A+S+D+F;
    if ((R+P-2) == 0)
    {
        Tax_cost = 125*Tax;
    }
    else
        Tax_cost = Tax*((R+P-2)/2)*500;

    Scratch = (R*R*3000)+((A*(A+1)*1000)/2)+((S*(S+1)*1000)/2)+((D*(D+1)*1000)/2)+((F*(F+1)*1000)/2)+(P*P*3000)+Tax_cost;
    Percent = (float)Scratch/(float)Cost;

    cout << setw(25) << DeckName << setw(2) << R << setw(0)<<A<<S<<D<<setw(2)<<F<<setw(5)<<P <<setw(8) << Cost <<setw(10) <<Scratch<<setprecision(2) <<setw(8)<< Percent<< Tax_cost<< endl;
    //output << setw(25) << DeckName << setw(2) << R << setw(0)<<A<<S<<D<<setw(2)<<F<<setw(5)<<P <<setw(8) << Cost <<setw(10) <<Scratch<<setprecision(2) << Percent<< endl;
    Percent_Ave+=Percent;
    loop_count++;
    }

    cout << "\n\n"<< "Average Percentage: "<< Percent_Ave/loop_count<< endl;
    //output << "\n\n"<< "Average Percentage: "<< Percent_Ave/loop_count<< endl;

    //output.close();
    file.close();

    return 0;
}
