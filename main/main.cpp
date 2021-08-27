/*
 * debug
 * nach den eingaben
 * a2aa4
 * b2bb4
 * c2cc4
 * d2dd4
 *
 * betritt die pogo ki eine endloschleife
 *
 *
 *
 */





#include <iostream>
#include "istgueltig.h"
#include <ctime>
using namespace std;



//public variables

std::string source = "00";        //source
std::string destination = "00";        //Destination
std::string Eingabe = "Leer";
std::string Buffer = "__";
char Spieler = 0;
bool debug = true;
bool pogo = false;

// Board


std::string Board [64]{"Tw","Sw","Lw","Kw","Dw","Lw","Sw","Tw",
                       "Bw","Bw","Bw","Bw","Bw","Bw","Bw","Bw",
                       "__","__","__","__","__","__","__","__",
                       "__","__","__","__","__","__","__","__",
                       "__","__","__","__","__","__","__","__",
                       "__","__","__","__","__","__","__","__",
                       "Bs","Bs","Bs","Bs","Bs","Bs","Bs","Bs",
                       "Ts","Ss","Ls","Ks","Ds","Ls","Ss","Ts"};

std::string Board2 [64]{"Tw","Sw","Lw","Kw","Dw","Lw","Sw","Tw",
                        "Bw","Bw","Bw","Bw","Bw","Bw","Bw","Bw",
                        "__","__","__","__","__","__","__","__",
                        "__","__","__","__","__","__","__","__",
                        "__","__","__","__","__","__","__","__",
                        "__","__","__","__","__","__","__","__",
                        "Bs","Bs","Bs","Bs","Bs","Bs","Bs","Bs",
                        "Ts","Ss","Ls","Ks","Ds","Ls","Ss","Ts"};
// Klassen

istGueltig Zug;

//funktionen

void drawboard(){
    bool r0 =true;
    bool r1 =true;
    bool r2 =true;
    bool r3 =true;
    bool r4 =true;
    bool r5 =true;
    bool r6 =true;
    bool r7 =true;
    bool r8 =true;


    while (r0 == true){

        std::cout<<std::endl<< "   ";
        for (char S =65; S< 73; S++){
            std::cout<< "____" << S << "_____   ";

        }
        r0 = false;
        std::cout <<std::endl<<std::endl<< std::endl;

    }

    while (r1 ==  true){
        std::cout << "8  ";
        for (int Za = 56; Za < 64; Za++ ){
            std::cout << "____"<< Board[Za]<<"____   ";

        }
        r1 = false;
        std::cout <<std::endl<<std::endl<<std::endl;

    }

    while (r2 ==  true){
        std::cout << "7  ";
        for ( int Zb = 48; Zb < 56; Zb++ ){
            std::cout << "____"<< Board[Zb]<<"____   ";

        }
        r2 = false;
        std::cout <<std::endl<<std::endl<<std::endl;
    }

    while (r3 ==  true){
        std::cout << "6  ";
        for (int Zc = 40; Zc < 48; Zc++ ){
            std::cout << "____"<< Board[Zc]<<"____   ";

        }
        r3 = false;
        std::cout <<std::endl<<std::endl<<std::endl;
    }

    while (r4 ==  true){
        std::cout << "5  ";
        for ( int Zd = 32; Zd < 40; Zd++ ){
            std::cout << "____"<< Board[Zd]<<"____   ";

        }
        r4 = false;
        std::cout <<std::endl<<std::endl<<std::endl;
    }

    while (r5 ==  true){
        std::cout << "4  ";
        for ( int Ze = 24; Ze < 32; Ze++ ){
            std::cout << "____"<< Board[Ze]<<"____   ";

        }
        r5 = false;
        std::cout <<std::endl<<std::endl<<std::endl;

    }

    while (r6 ==  true){
        std::cout << "3  ";
        for ( int Zf = 16; Zf < 24; Zf++ ){
            std::cout << "____"<< Board[Zf]<<"____   ";

        }
        r6 = false;
        std::cout <<std::endl<<std::endl<<std::endl;

    }

    while (r7 ==  true){
        std::cout << "2  ";
        for ( int Zg = 8; Zg < 16; Zg++ ){
            std::cout << "____"<< Board[Zg]<<"____   ";

        }
        r7 = false;
        std::cout <<std::endl<<std::endl<<std::endl;
    }

    while (r8 ==  true){
        std::cout << "1  ";
        for ( int Zh = 0; Zh < 8; Zh++ ){
            std::cout<< "____"<< Board[Zh]<<"____   ";

        }
        r8 = false;
        std::cout <<std::endl<<std::endl;

    }


}//drawboard ende

void bauernumwandlung(string Eingabe){
    char Umwandlung = 0;
    for (int i = 0; i< 7;i++ ){
        if (Board[i].at(0) == 66){
            cout << "Spieler B geben sie einen char f\x81r die Umwandlung ein [B,T,S,L,D]"<< endl;
            cin >> Umwandlung;
            if (Umwandlung == 66||84||83||76||68){
                Board[i].at(0)= Umwandlung;
                drawboard();
            }else{
                cout<< "dies ist kein g\x81ltiger Wert. [B,T,S,L,D]"<< endl;
                bauernumwandlung(Eingabe);
            }

        }
        if (Board[i+56].at(0) == 66){
            cout << "Spieler A geben sie einen char f\x81r die Umwandlung ein [B,T,S,L,D]"<< endl;
            cin >> Umwandlung;
            if (Umwandlung == 66||84||83||76||68){
                Board[i+56].at(0)= Umwandlung;
                drawboard();
            }else{
                cout<< "dies ist kein g\x81ltiger Wert. [B,T,S,L,D]"<< endl;
                bauernumwandlung(Eingabe);
            }

        }
    }

}

bool valid(std::string Eingabe, std::string Buffer, std::string source, std::string destination, bool debug){

    source = "00";        //source
    destination = "00";        //Destination


    bool exit2 = 0;

    if (Eingabe.length() !=5 ){
        if (debug == true)std::cout<< "Geben sie ihren Zug im angegebenen Format ein "<<std::endl;
        return false;
    }

    //konvertierung
    if ( (Eingabe.at(0)<=72) && (Eingabe.at(0)>=65)){
        // muss nicht konvertiert werden
    }else{
        if ( (Eingabe.at(0)<=105) || (Eingabe.at(0)>=96)){
            //std::cout << "Die Koordinate [A] wird umgewandelt."<< std::endl;
            Eingabe.at(0)= Eingabe.at(0)-32;
        }
    }

    if ( (Eingabe.at(3)<=72) && (Eingabe.at(3)>=65)){

    }else{
        if ( (Eingabe.at(3)<=105) || (Eingabe.at(3)>=96)){
            //std::cout << "Die Koordinate [B] wird umgewandelt."<< std::endl;
            Eingabe.at(3)= Eingabe.at(3)-32;
        }
    }

    //konvertierung  ende

    source.at(0) = Eingabe.at(0);
    source.at(1) = Eingabe.at(1);
    destination.at(0) = Eingabe.at(3);
    destination.at(1) = Eingabe.at(4);


    while (exit2 == 0){

        if (Spieler == 2){
            if(Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1)!= 115){//s
                if (debug == true) std::cout << "Spieler B (sie) darf nur schwarze Figuren bewegen"<< std::endl;
                return false;
            }
        }else{
            if(Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1)!= 119){//w
                if (debug == true) std::cout << "Spieler A (sie) darf nur weisse Figuren bewegen"<< std::endl;
                return false;
            }
        }


        if ((source==destination)){
            if (debug == true) std::cout << "Die Figur befindet sich schon auf "<<source<<"."<<std::endl;

            if (debug == true) std::cout << "Geben sie einen g\x81ltigen Zug ein"<< std::endl<< std::endl;
            exit2 = 1;
            break;
            return false;
        }if (((source.at(1)<=48 || source.at(1)>=57)) || ((destination.at(1)<=48) || destination.at(1)>=57)){
            if (debug == true) std::cout << "Mindestens eine Gew\x84hlte Koordinate existiert nicht.[#]"<< std::endl;
            if (debug == true)  std::cout << "Geben sie einen g\x81ltigen Zug ein"<< std::endl<< std::endl;
            exit2 = 1;
            break;
            return false;

        }if (((source.at(0)>=73) || (source.at(0)<=64)) || ((destination.at(0)>=73) || (destination.at(0)<=64))){
            if (debug == true)  std::cout << "Mindestens eine Gew\x84hlte Koordinate existiert nicht.[A/B]"<< std::endl;
            if (debug == true)  std::cout << "Geben sie einen g\x81ltigen Zug ein"<< std::endl<< std::endl;
            exit2 = 1;
            break;
            return false;
        }
        if ( Zug.gueltig(Board,Eingabe, source, destination,debug)== true){

            // wenn figur schl\x84gt setze dest = source && source = __
            if ((Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115) && (Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 119)||(Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119) && (Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 115)){
                if (debug == true) std::cout <<Board[(8*(source.at(1)-49))+(source.at(0)-65)]<< " schl\x84gt "<<Board[(8*(destination.at(1)-49))+(destination.at(0)-65)] <<std::endl;
                Buffer = Board[(8*(source.at(1)-49))+(source.at(0)-65)];
                Board[(8*(source.at(1)-49))+(source.at(0)-65)]= "__";
                Board[(8*(destination.at(1)-49))+(destination.at(0)-65)]= Buffer;
                exit2 = 1;
                return true;
            }else{            // andernfalls tausche pos im board

                Buffer = Board[(8*(source.at(1)-49))+(source.at(0)-65)];
                Board[(8*(source.at(1)-49))+(source.at(0)-65)]= Board[(8*(destination.at(1)-49))+(destination.at(0)-65)];
                Board[(8*(destination.at(1)-49))+(destination.at(0)-65)]= Buffer;
                exit2 = 1;
                return true;
            }


            //}


        }else{
            if (debug == true) std::cout << "Die Figur ["<< Board[(8*(source.at(1)-49))+(source.at(0)-65)]<< "] darf diesen Zug nicht machen."<<std::endl;

            return false;
        }

    }
    // spieler zur\x81cksetzen




    return false;
}//valid ende

void PogoKi(string Eingabe,bool debug){
    srand (time(NULL));
    bool done =false;
    int i = 0;
    int za = 0;
    int zb = 0;


    while(done != true && i <= 100000){
        Eingabe.at(0)= rand()%7+66;
        Eingabe.at(1)= rand()%7+50;
        Eingabe.at(3)= rand()%7+66;
        Eingabe.at(4)= rand()%7+50;
        i++;
        debug = false;



        if (Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)].at(1)== 115){
            za=0;
            zb=0;
            //std::cout<<i <<" "<< Eingabe<< std::endl;


            if  (Zug.gueltig(Board,Eingabe, source, destination, debug) == true){   // wenn zug gueltig ist

                if(valid(Eingabe,Buffer,source,destination, debug)==true){
                    done = true;


                }



                //if (i>= 10000){

            }
        }
    }
    if (i>= 100000){
        std::cout<<"#"<<i<<"kein gueltiger Zug gefunden"<< Eingabe<< std::endl;
    }else{
        std::cout<<"#"<<i<<": gueltig: "<< Eingabe<< std::endl;
    }
    debug= true;
}

void PogoKi2(string Eingabe,bool debug){
    srand (time(NULL));
    bool done =false;
    int i = 0;
    int za = 0;
    int zb = 0;


    /*vector nehmen und alle möglichen züge von Eingabe.at (1 & 0 )
     *
     * per push back auflisten (zählschleife (63))
     *
     * dann mit rand()% moeglich.size  einen gültigen zug wählen
     *
     *
     *
     * möglicherweise verringerte laufzeit ?
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     * */





    while(done != true && i <= 100000){
        Eingabe.at(0)= rand()%7+66;
        Eingabe.at(1)= rand()%7+50;
        Eingabe.at(3)= rand()%7+66;
        Eingabe.at(4)= rand()%7+50;
        i++;
        debug = false;



        if (Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)].at(1)== 115){
            za=0;
            zb=0;
            //std::cout<<i <<" "<< Eingabe<< std::endl;

            /*           while (zb != 9 && za !=8) {
                Eingabe.at(3)= zb+65;
                Eingabe.at(4)= za+49;
                debug = false;
                std::cout<<i <<" "<< Eingabe<< std::endl;


                if  (Zug.gueltig(Board,Eingabe, source, destination, debug) == true){   // wenn zug gueltig ist

                    if(valid(Eingabe,Buffer,source,destination, debug)==true){
                        done = true;
                        break;


                    }

                }za++;
            }zb++;
            */



            if  (Zug.gueltig(Board,Eingabe, source, destination, debug) == true){   // wenn zug gueltig ist

                if(valid(Eingabe,Buffer,source,destination, debug)==true){
                    done = true;


                }



                //if (i>= 10000){

            }
        }
    }
    if (i>= 100000){
        std::cout<<"#"<<i<<"kein gueltiger Zug gefunden"<< Eingabe<< std::endl;
    }else{
        std::cout<<"#"<<i<<": gueltig: "<< Eingabe<< std::endl;
    }
    debug= true;
}

bool gdroht(string Eingabe,int Kw,int Ks){ // geht alle z\x81ge von ist g\x81ltig durch und schaut ob eine Figur den K\x94nig schlagen kann
    string A = "00";        //source
    string B = "00";        //Destination
    Buffer = "00";
    int Kk = Kw;
    int za = 0;
    int zb = 0;

    for (int za= 0; za<8; za++){
        for (int zb= 0; zb<8; zb++){
            if ((8*za)+ zb == Kw){
                Eingabe.at(3)= zb+65;
                Eingabe.at(4)= za+49;
            }
        }
    } // pos Kk



    while (za<8){
        while (zb<8){

            if(zb == 8 && za ==8){
                Kk= Ks;
                za =0;
                zb = 0;
                for (int za= 0; za<8; za++){
                    for (int zb= 0; zb<8; zb++){
                        if ((8*za)+ zb == Kw){
                            Eingabe.at(3)= zb+65;
                            Eingabe.at(4)= za+49;
                        }
                    }
                } // pos Kk


            }

            while (zb != 9 && za !=8) {
                Eingabe.at(0)= zb+65;
                Eingabe.at(1)= za+49;
                debug = false;


                if  (Zug.gueltig(Board,Eingabe, A, B, debug) == true){   // wenn bedrohung gefunden wird gebe aus
                    Buffer = Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)];
                    cout<< Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)]<< " auf "<<Eingabe.at(0) << Eingabe.at(1);
                    if(Buffer != "00"){
                        cout<< " bedroht den ";
                        if (Buffer.at(1) == 119){
                            cout <<" schwarzen K\x94nig"<< endl;
                        }else{
                            cout <<" weissen K\x94nig"<< endl;
                        }

                    }

                }za++;
            }zb++;
            if (Eingabe.at(0)!= 72 && Eingabe.at(0)!= 56){
                za = 0;
            }else{    debug = true;
                if (Buffer.at(1) != 48){
                }
            }
        }
    } // hiernach Ks

    za = 0;
    zb = 0;


    for (int za= 0; za<8; za++){
        for (int zb= 0; zb<8; zb++){
            if ((8*za)+ zb == Ks){
                Eingabe.at(3)= zb+65;
                Eingabe.at(4)= za+49;
            }
        }
    } // pos Kk



    while (za<8){
        while (zb<8){

            if(zb == 8 && za ==8){
                Kk= Ks;
                za =0;
                zb = 0;
                for (int za= 0; za<8; za++){
                    for (int zb= 0; zb<8; zb++){
                        if ((8*za)+ zb == Kw){
                            Eingabe.at(3)= zb+65;
                            Eingabe.at(4)= za+49;
                        }
                    }
                } // pos Kk


            }

            while (zb != 9 && za !=8) {
                Eingabe.at(0)= zb+65;
                Eingabe.at(1)= za+49;
                debug = false;


                if  (Zug.gueltig(Board,Eingabe, A, B, debug) == true){   // wenn bedrohung gefunden wird gebe aus
                    Buffer = Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)];
                    cout<< Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)]<< " auf "<<Eingabe.at(0) << Eingabe.at(1);
                    if(Buffer != "00"){
                        cout<< " bedroht den ";
                        if (Buffer.at(1) == 119){
                            cout <<" schwarzen K\x94nig"<< endl;
                        }else{
                            cout <<" weissen K\x94nig"<< endl;
                        }

                    }

                }za++;
            }zb++;
            if (Eingabe.at(0)!= 72 && Eingabe.at(0)!= 56){
                za = 0;
            }else{    debug = true;
                if (Buffer.at(1) != 48){
                    return true;
                }
            }
        }
    }return false;
}

bool schachdrohungAktiv(string Eingabe){// schaut ob k\x94nig bedroht wird
    // z\x84hle durch, und wenn ein k\x94nig gefunden wird betrete die Funktion





    int i = 0;
    int Kw = 0;
    int Ks = 0;

    while (i<=63){
        if (Board[i].at(0) == 75){
            if (Board[i].at(1) == 119){ // wenn K\x94nig weiss ist
                Kw = i;
            }
            if (Board[i].at(1) == 115){ // wenn K\x94nig schwarz ist ist
                Ks = i;

            }
        }
        i++;
    }
    if ( gdroht(Eingabe, Kw,Ks) == true){
        return true;
    }

    //ehm ...


    return false; // f\x81r leere funktion

}

bool spielende (){


    int i = 0;
    int Kw = 0;
    int Ks = 0;

    while (i<64){
        if (Board[i].at(0) == 75){
            if (Board[i].at(1) == 119){ // wenn K\x94nig weiss ist
                Kw = i;
            }
            if (Board[i].at(1) == 115){ // wenn K\x94nig schwarz ist ist
                Ks = i;

            }
        }
        i++;
    }

    if (Kw == 0||Ks == 0)return true;

    return false;

}

void test (){
    Eingabe.resize(5);
    Eingabe.at(3)= 65;
    Eingabe.at(4)= 49;
    debug = true;

    for (int za= 0; za<8; za++){
        for (int zb= 0; zb<8; zb++){
            Eingabe.at(0)= zb+65;
            Eingabe.at(1)= za+49;
            //std::cout <<Eingabe.at(0)<<Eingabe.at(1)<<"-";
            Zug.gueltig(Board,Eingabe, source,destination, debug);
            for (int zc= 0; zc<8; zc++){
                for (int zd= 0; zd<8; zd++){
                    Eingabe.at(3)= zd+65;
                    Eingabe.at(4)= zc+49;
                    std::cout <<Eingabe.at(0)<<Eingabe.at(1)<<"-"<<Eingabe.at(3)<<Eingabe.at(4)<< "->";
                    Zug.gueltig(Board,Eingabe, source, destination, debug);
                }
            }
        }
    }
    std::cout << std::endl<< "moeglichkeiten werden gesucht"<< std::endl;





}

void moeglich (char Spieler){
    Eingabe.resize(5);
    Eingabe.at(3)= 65;
    Eingabe.at(4)= 49;
    debug = false;
    std::string Figur  = "leer";

    char farbe = 0;
    if (Spieler == 1){farbe = 119;}
    if (Spieler == 2){farbe = 115;}

    for (int za= 0; za<8; za++){
        for (int zb= 0; zb<8; zb++){
            Eingabe.at(0)= zb+65;
            Eingabe.at(1)= za+49;
            //std::cout <<Eingabe.at(0)<<Eingabe.at(1)<<"-";
            Zug.gueltig(Board,Eingabe, source,destination, debug);
            for (int zc= 0; zc<8; zc++){
                for (int zd= 0; zd<8; zd++){
                    Eingabe.at(3)= zd+65;
                    Eingabe.at(4)= zc+49;
                    if (Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)].at(1) == farbe){
                        if(Zug.gueltig(Board,Eingabe, source, destination, debug)== true){
                            debug = true;
                            switch (Board[(8*(Eingabe.at(1)-49))+(Eingabe.at(0)-65)].at(0)) {
                            case 66:
                                Figur = "Bauer";
                                break;
                            case 84:
                                Figur = "Turm";
                                break;
                            case 76:
                                Figur = "Laeufer";
                                break;
                            case 83:
                                Figur = "Springer";
                                break;
                            case 75:
                                Figur = "Koenig";
                                break;
                            case 68:
                                Figur = "Dame";
                                break;
                            }
                            std::cout << Figur << " auf " <<Eingabe.at(0)<<Eingabe.at(1)<<"->"<<Eingabe.at(3)<<Eingabe.at(4)<< " ::  ";
                            Zug.gueltig(Board,Eingabe, source, destination, debug);
                            debug = false;
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl<< "erfolgreich beendet"<< std::endl;





}


bool turns(bool pogo, string Eingabe){
    Eingabe = "aaaaaa";

    while(true){
        switch (Spieler){
        case 0:
            Eingabe = "aaaaaa"; // weil schachdrohung out of range schmeisst
            //std::cout << "test wird ausgef\x81hrt"<< std::endl; test();
            drawboard();
            schachdrohungAktiv(Eingabe);
            std::cout << "Spieler A,geben sie ihren Zug ein (Bsp: A1-A4),"<< std::endl
                      << "oder exit um das Programm zu Beenden,"<< std::endl
                      << "oder test um das Programm auf Fehler zu testen,"<< std::endl
                      << "oder moeglich um die moeglichen Zuege anzuzeigen,"<< std::endl
                      << "oder pogo um die Ki zu aktivieren:";
            std::cin >> Eingabe;
            if (Eingabe == "test"){std::cout << "test wird ausgef\x81hrt"<< std::endl; Spieler =1;test();Eingabe = "aaaaaa"; continue;}
            if (Eingabe == "exit"){return 0;}
                        if (Eingabe == "moeglich"){std::cout << "moegliche Zuege werden gesucht"<< std::endl; Spieler =1; moeglich(Spieler); Eingabe = "aaaaaa";continue;}
            if (Eingabe == "pogo"){std::cout << "Pogo KI wurde aktiviert"<< std::endl; Spieler =1; pogo = true;Eingabe = "aaaaaa"; continue;}
            if (Eingabe.length() != 5){ std::cout<< "Eingabe zu kurz "<<Eingabe.length(); Eingabe.resize(5); continue;}
            if(valid(Eingabe,Buffer,source,destination, debug)!= true){continue;}
            Spieler =2;
            if (spielende ()== true ){Spieler =3;}
            continue;
        case 1:

            drawboard();
            schachdrohungAktiv(Eingabe);
            std::cout << "Spieler A,geben sie ihren Zug ein:   "<<std::endl;
            std::cin >> Eingabe;
            if (Eingabe == "pogo"){std::cout << "Pogo KI wurde getoggelt"<< pogo<< std::endl; Spieler =1; if (pogo ==  true){pogo = false;}else{pogo = true;}Eingabe = "aaaaaa"; continue;}
            if (Eingabe == "test"){std::cout << "test wird ausgef\x81hrt"<< std::endl; Spieler =1;test(); Eingabe = "aaaaaa";continue;}
            if (Eingabe == "moeglich"){std::cout << "moegliche Zuege werden gesucht"<< std::endl; Spieler =1; moeglich(Spieler); Eingabe = "aaaaaa";continue;}
            if (Eingabe == "exit"){return 0;}
            if (Eingabe.length() != 5){ std::cout<< "Eingabe zu kurz "<<Eingabe.length(); Eingabe.resize(5); continue;}
            if(valid(Eingabe,Buffer,source,destination, debug)!= true){continue;}
            bauernumwandlung(Eingabe);
            Spieler++;
            if (spielende ()== true ){Spieler =3;}
            continue;
        case 2:
            if(pogo == false){
                drawboard();
                schachdrohungAktiv(Eingabe);
                std::cout << "Spieler B,geben sie ihren Zug ein:   "<<std::endl;
                std::cin >> Eingabe;
                if (Eingabe == "pogo"){std::cout << "Pogo KI wurde getoggelt"<< pogo<< std::endl; Spieler =2; if (pogo ==  true){pogo = false;}else{pogo = true;}Eingabe = "aaaaaa"; continue;}
                if (Eingabe == "test"){std::cout << "test wird ausgef\x81hrt"<< std::endl; Spieler =2;test();Eingabe = "aaaaaa"; continue;}
                if (Eingabe == "moeglich"){std::cout << "moegliche Zuege werden gesucht"<< std::endl; Spieler =2; moeglich(Spieler); Eingabe = "aaaaaa";continue;}
                if (Eingabe == "exit"){return 0;}
                if (Eingabe.length() != 5){ std::cout<< "Eingabe zu kurz "<<Eingabe.length(); Eingabe.resize(5); continue;}
                if(valid(Eingabe,Buffer,source,destination, debug)!= true){continue;}
                bauernumwandlung(Eingabe);
                Spieler--;
                if (spielende ()== true ){Spieler =3;}
                continue;}
            else{
                PogoKi(Eingabe, debug);
                //if(valid(Eingabe,Buffer,source,destination, debug)!= true){continue;}
                Spieler--;
                if (spielende ()== true ){Spieler =3;}
                continue;
            }
        case 3:
            std::cout << "Das spiel ist zuende"<<std::endl;
            break;
            /*        case 4:
            std::cout << "Moechten sie gegen eine Pogo Ki spielen?   [y/n]"<<std::endl;
            std::cin >> Eingabe;

            if (Eingabe.at(0) == 121){


                std::cout << "pogo wurde gesetzt"<< endl;
                pogo == true;

            }else{
                if (Eingabe.at(0) == 110){
                    pogo == false;
                }else{
                    std::cout<< "ungueltige eingabe:"<<endl;
                    Spieler = 4;
                    continue;
                }


            }
            Spieler =0;
            continue;*/


        }//switch [Spieler] ende
        return false;
    }//while ende
}//turns ende




int main(){

    char Spiel = 1;
    bool exit1 = false;
    char char1 = 0;


    while(exit1 == false){
        switch (Spiel) {
        case 0:
            Spieler = 0;
            for (int i =0; i<=63; i++){Board[i] = Board2[i];}

            //cout<< "w\x84hlen sie ein Spiel:"<<endl;
            Spiel = 1;
            continue;
        case 1:
            //cout<< "sie haben Schach gew\x84hlt"<<endl;
            cout<< "Schach wird gestartet..."<<endl;
            if(turns(pogo, Eingabe) == false){
                cout<< "Möchten sie ein neues Spiel starten ? [ y / n ]"<<endl;
                cin >>char1;
                if(char1 != 121){exit1 = true; return 0;}
                Spiel =0;
                continue;

            }
            continue;
        case 3:

            //cout<< "w\x84hlen sie ein Spiel:"<<endl;
            Spiel = 1;
            continue;

        }//switch [Spiel] ende

    }// while ende

}
