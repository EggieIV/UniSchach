#ifndef ISTGUELTIG_H
#define ISTGUELTIG_H
#include<iostream>

class istGueltig
{
public:
    istGueltig();

//funktionen
    bool Bauer (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug);
    bool Koenig (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug);
    bool laeufer (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug);
    bool springer (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug);
    bool turm (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug);
    bool gueltig (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug);



private:

};

#endif // ISTGUELTIG_H
