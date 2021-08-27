#include "istgueltig.h"



bool istGueltig::turm (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug){
    int xa= (8*(source.at(1)-49))+(source.at(0)-65);

    if(((source.at(0) == destination.at(0))||(source.at(1)==destination.at(1)))){ // wenn eine achse gleichbleibt dann darf der Turm ziehen

        if(source.at(1)==destination.at(1)){ // waagerechte
            for(int i= 1; i<=(destination.at(0)-source.at(0)); i++){//waagerechte+
                if(Board[xa+i].at(1) == Board[xa].at(1) ){
                    if (debug == true) std::cout <<" Man darf die Eigene Figur nicht Schlagen [w+] "<<xa+i<< std::endl;
                    return false;
                }
                if (xa+i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                    if((Board[xa+i].at(1) != 95)){
                        if (debug == true) std::cout <<" Man darf keine Figur Ueberspringen  [w+] "<<xa+i<< std::endl;
                        return false;
                    }
                }

            }
            for(int i= 1; i<=(source.at(0)-destination.at(0)); i++){//waagerechte-
                if(Board[xa-i].at(1) == Board[xa].at(1) ){
                    if (debug == true) std::cout <<" Man darf die Eigene Figur nicht Schlagen [w-] "<<xa-i<< std::endl;
                    return false;
                }
                if (xa-i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                    if(Board[xa-i].at(1) != 95){
                        if (debug == true) std::cout <<" Man darf keine Figur Ueberspringen  [w-] "<<xa-i<< std::endl;
                        return false;
                    }
                }


            }
        }

        if ((source.at(0) == destination.at(0))){// senkrechte
            for(int i= 8; i<=8*(destination.at(1)-source.at(1)); i= i+8){//senkrechte+


                if(Board[xa+i].at(1) == Board[xa].at(1) ){
                    if (debug == true) std::cout <<" Man darf die Eigene Figur nicht Schlagen [s+] "<< xa+i<< std::endl;
                    return false;

                }
                if (xa+i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                    if(Board[xa+i].at(1) != 95 ){
                        if (debug == true) std::cout <<" Man darf keine Figur Ueberspringen  [s+] "<<xa+i<< std::endl;
                        return false;
                    }
                }

            }



            for(int i= 8; i<=8*(source.at(1)-destination.at(1)); i= i+8){//senkrechte-


                if(Board[xa-i].at(1) == Board[xa].at(1) ){
                    if (debug == true) std::cout <<" Man darf die Eigene Figur nicht Schlagen [s-] "<< xa-i<< std::endl;
                    return false;

                }
                if (xa-i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                    if(Board[xa-i].at(1) != 95 ){
                        if (debug == true) std::cout <<" Man darf keine Figur Ueberspringen  [s-] "<<xa-i<< std::endl;
                        return false;
                    }
                }

            }





        }
        if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
        return true;

    }return false;
}

bool istGueltig::springer (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug){

    int  xa=((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)));


    if(Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1)){
        if (debug == true) std::cout<< " Man darf die Eigene Figur nicht Schlagen "<< destination<<std::endl;
        return false;
    }else{
        if(xa == 17){
            if ((destination.at(1)-49)==(source.at(1)-47)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa == -17){
            if ((destination.at(1)-49)==(source.at(1)-51)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa == 15){
            if ((destination.at(1)-49)==(source.at(1)-47)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa ==-15){
            if ((destination.at(1)-49)==(source.at(1)-51)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa == 10){
            if ((destination.at(1)-49)==(source.at(1)-48)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa == -10){
            if ((destination.at(1)-49)==(source.at(1)-50)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa == 6){
            if ((destination.at(1)-49)!=(source.at(1)-49)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }if(xa == -6){
            if ((destination.at(1)-49)!=(source.at(1)-49)){
                if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
                return true;
            }
        }

        if (debug == true) std::cout << "geben sie bitte einen g\x81ltigen Zug ein.[S]"<< xa<<std::endl;
        return false;
    }


}

bool istGueltig::laeufer (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug){



    int xa= (8*(source.at(1)-49))+(source.at(0)-65);

    if (Board[54].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "H8"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }
    if (Board[9].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "A1"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }
    if (Board[14].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "H1"){
            if (debug == true)  std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }
    if (Board[49].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "A8"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }



    for (int i= 1;i<=abs(destination.at(1) - source.at(1));i++){

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa+(8*i)-1*i){  // links unten

            if (debug == true) std::cout << "dieser zug geht links nach unten und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=abs(destination.at(1) - source.at(1));i++){
                if((xa+(8*i)-i)>= 63){return false;}
                if (Board[xa+(8*i)-i].at(1)==Board[xa].at(1)){//farbe pr\x81fen links unten
                    if (debug == true)  std::cout << " Man darf die Eigene Figur nicht Schlagen [Llu]" <<std::endl;
                    return false;
                }
                if (Board[xa+(8*i)-i].at(1)== ("w"||"s")){
                    if(xa+(8*i)-i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true) std::cout << " Man darf eine Figur nicht Ürspringen [Llu]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa+(8*i)+1*i){     // rechts unten

            if (debug == true)   std::cout << "dieser zug geht rechts nach unten und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=abs(destination.at(1) - source.at(1));i++){
                if((xa+(8*i)+i)>= 63){return false;}
                if (Board[xa+(8*i)+i].at(1)==Board[xa].at(1)){//farbe pr\x81fen rechts unten
                    if (debug == true)   std::cout << " Man darf die Eigene Figur nicht Schlagen [Lru]" <<std::endl;
                    return false;
                }
                if (Board[xa+(8*i)+i].at(1)== ("w"||"s")){
                    if(xa+(8*i)+i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true)  std::cout << " Man darf eine Figur nicht Ürspringen [Lru]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa-(8*i)-1*i){     // links oben

            if (debug == true)  std::cout << "dieser zug geht links nach oben und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=abs(destination.at(1) - source.at(1));i++){
                if((xa-(8*i)-i)>= 63){return false;}
                if (Board[xa-(8*i)-i].at(1)==Board[xa].at(1)){//farbe pr\x81fen links oben
                    if (debug == true)  std::cout << " Man darf die Eigene Figur nicht Schlagen [Llo]" <<std::endl;
                    return false;
                }
                if (Board[xa-(8*i)-i].at(1)== ("w"||"s")){
                    if(xa-(8*i)-i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true) std::cout << " Man darf eine Figur nicht Ürspringen [Llo]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa-(8*i)+1*i){     // rechts oben

            if (debug == true)    std::cout << "dieser zug geht rechts nach oben und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=abs(destination.at(1) - source.at(1));i++){
                if((xa-(8*i)+i)>= 63){return false;}



                if (Board[xa-(8*i)+i].at(1)==Board[xa].at(1)){//farbe pr\x81fen rechts oben
                    if (debug == true)  std::cout << " Man darf die Eigene Figur nicht Schlagen [Lro]" <<std::endl;
                    return false;
                }
                if (Board[xa-(8*i)+i].at(1)== ("w"||"s")){
                    if(xa-(8*i)+i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true)  std::cout << " Man darf eine Figur nicht Ürspringen [Lro]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

    }

    if (debug == true) std::cout << "geben sie bitte einen g\x81ltigen Zug ein.[L]"<<std::endl;
    return false;
}

bool istGueltig::Koenig (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug){
    int  xa=((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)));


    if(Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1)){
        if (debug == true) std::cout<< " Man darf die Eigene Figur nicht Schlagen "<< destination<<std::endl;
        return false;
    }else{
        if(xa == -7){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa == -8){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa == -9){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa ==-1){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa == 1){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa == 7){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa == 8){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;
        }if(xa == 9){
            if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug :"<<  xa <<std::endl;
            return true;

        }

        if (debug == true) std::cout << "geben sie bitte einen g\x81ltigen Zug ein.[K]"<< xa<<std::endl;
        return false;
    }}

bool istGueltig::Bauer (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug){
    int  xa=abs((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)));



    if(Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1)){
        if (debug == true) std::cout<< " Man darf die Eigene Figur nicht Schlagen "<< destination<<std::endl;
        return false;
    }else{
        if(xa == 8 ){
            if(Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 95){ // pr\x81fung

                if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== -8 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115){// schwarz
                    if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug [Bs]:"<<  xa <<std::endl;
                    return true;
                }
                if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== +8 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119){//weiss
                    if (debug == true) std::cout << "Dies ist ein g\x81ltiger Zug [Bw]:"<<  xa <<std::endl;
                    return true;
                }

            }
        }


        if(xa == 16){
            if ((source.at(1) == 50  && (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119))|| (source.at(1) == 55 && (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115)) ){ // en peasant teilweise
                if(Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119){
                    if(Board[(8*(destination.at(1)-49))+(destination.at(0)-65)-8].at(1) == 95){ // pr\x81fung

                        if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== -16 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115){// schwarz
                            if (debug == true) std::cout << "[pea]Dies ist ein g\x81ltiger Zug [Bs]:"<<  xa <<std::endl;
                            return true;
                        }
                        if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== +16 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119){// weiss
                            if (debug == true) std::cout << "[pea]Dies ist ein g\x81ltiger Zug [Bw]:"<<  xa <<std::endl;
                            return true;
                        }

                    }
                }
                if(Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115){
                    if(Board[(8*(destination.at(1)-49))+(destination.at(0)-65)+8].at(1) == 95){ // pr\x81fung

                        if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== -16 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115){// schwarz
                            if (debug == true) std::cout << "[pea]Dies ist ein g\x81ltiger Zug [Bs]:"<<  xa <<std::endl;
                            return true;
                        }
                        if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== +16 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119){// weiss
                            if (debug == true) std::cout << "[pea]Dies ist ein g\x81ltiger Zug [Bw]:"<<  xa <<std::endl;
                            return true;
                        }

                    }
                }

            }
            if(source.at(1) != 50 ||source.at(1) != 55){
                if (debug == true) std::cout<< "Der Bauer hat nur an der Anfangsposition diese M\x94glichkeit "<< xa << std::endl;
                return false;
            }
        }

        if(xa == 7 ){ //Bauernwurf
            if( (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115) && (Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 119) ){


                if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== -7 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115){// schwarz
                    //if (debug == true) std::cout << "s schl\x84gt w"<<  xa <<std::endl;
                    return true;
                }

            }
            if( (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119) && (Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 115) ){


                if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== +7 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119){// weiss


                    //if (debug == true) std::cout << "w schl\x84gt s"<<  xa <<std::endl;
                    return true;
                }

            }

            if (debug == true) std::cout << "Dies ist kein g\x81ltiger wurf"<<  xa <<std::endl;
            return false;
        }

        if(xa == 9  ){ //Bauernwurf
            if( (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115) && (Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 119) ){


                if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== -9 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 115){// schwarz
                    //if (debug == true) std::cout << "s schl\x84gt w"<<  xa <<std::endl;
                    return true;
                }

            }
            if( (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119) && (Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1) == 115) ){


                if(((8*(destination.at(1)-49)+(destination.at(0)-65))-(8*(source.at(1)-49)+(source.at(0)-65)))== +9 && Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == 119){// weiss


                    //if (debug == true) std::cout << "w schl\x84gt s"<<  xa <<std::endl;
                    return true;
                }

            }

            if (debug == true) std::cout << "Dies ist kein g\x81ltiger wurf"<<  xa <<std::endl;
            return false;
        }

        return false;

    }
    return false;
}

bool istGueltig::gueltig (std::string Board [],std::string Eingabe, std::string source, std::string destination, bool debug){

    source.at(0) = Eingabe.at(0);
    source.at(1) = Eingabe.at(1);
    destination.at(0) = Eingabe.at(3);
    destination.at(1) = Eingabe.at(4);
    std::string Figur = Board[(8*(source.at(1)-49))+(source.at(0)-65)];

    if (source == destination){return false;}
    if (Board[(8*(source.at(1)-49))+(source.at(0)-65)].at(1) == Board[(8*(destination.at(1)-49))+(destination.at(0)-65)].at(1)){return false;}



    if(  Figur.at(0) == 84){// Turm
        if (turm (Board ,Eingabe, source, destination,debug)== true){return true;}else{return false;}
    }

    if(  Figur.at(0) == 83){// Springer

        if (springer (Board, Eingabe, source, destination,debug)== true){return true;}else{return false;}

    }

    if(  Figur.at(0) == 76){//L\x84ufer

        if (laeufer (Board,Eingabe, source, destination,debug)== true){return true;}else{return false;}



        /*     int xa= (8*(source.at(1)-49))+(source.at(0)-65);

    if (Board[54].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "H8"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }
    if (Board[9].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "A1"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }
    if (Board[14].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "H1"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }
    if (Board[49].at(1)!= 0){ // 1 feld vor der Ecke abfangen
        if(destination == "A8"){
            if (debug == true) std::cout << " Man darf Keine Figur Ürspringen [L]" <<std::endl;
            return false;
        }
    }



    for (int i= 1;i<destination.at(1);i++){

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa+(8*i)-1*i){  // links unten

            if (debug == true) std::cout << "dieser zug geht links nach unten und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=destination.at(1)-49;i++){
                if (Board[xa+(8*i)-i].at(1)==Board[xa].at(1)){//farbe pr\x81fen links unten
                    if (debug == true) std::cout << " Man darf die Eigene Figur nicht Schlagen [Llu]" <<std::endl;
                    return false;
                }
                if (Board[xa+(8*i)-i].at(1)== ("w"||"s")){
                    if(xa+(8*i)-i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true) std::cout << " Man darf eine Figur nicht Ürspringen [Llu]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa+(8*i)+1*i){     // rechts unten

            if (debug == true) std::cout << "dieser zug geht rechts nach unten und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=destination.at(1)-49;i++){
                if (Board[xa+(8*i)+i].at(1)==Board[xa].at(1)){//farbe pr\x81fen rechts unten
                    if (debug == true) std::cout << " Man darf die Eigene Figur nicht Schlagen [Lru]" <<std::endl;
                    return false;
                }
                if (Board[xa+(8*i)+i].at(1)== ("w"||"s")){
                    if(xa+(8*i)+i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true) std::cout << " Man darf eine Figur nicht Ürspringen [Lru]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa-(8*i)-1*i){     // links oben

            if (debug == true) std::cout << "dieser zug geht links nach oben und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=destination.at(1)-49;i++){
                if (Board[xa-(8*i)-i].at(1)==Board[xa].at(1)){//farbe pr\x81fen links oben
                    if (debug == true) std::cout << " Man darf die Eigene Figur nicht Schlagen [Llo]" <<std::endl;
                    return false;
                }
                if (Board[xa-(8*i)-i].at(1)== ("w"||"s")){
                    if(xa-(8*i)-i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true) std::cout << " Man darf eine Figur nicht Ürspringen [Llo]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

        if ((8*(destination.at(1)-49))+(destination.at(0)-65) == xa-(8*i)+1*i){     // rechts oben

            if (debug == true) std::cout << "dieser zug geht rechts nach oben und ist teil des l\x84ufersets"<< std::endl;
            for (int i= 1;i<=destination.at(1)-49;i++){



                if (Board[xa-(8*i)+i].at(1)==Board[xa].at(1)){//farbe pr\x81fen rechts oben
                    if (debug == true) std::cout << " Man darf die Eigene Figur nicht Schlagen [Lro]" <<std::endl;
                    return false;
                }
                if (Board[xa-(8*i)+i].at(1)== ("w"||"s")){
                    if(xa-(8*i)+i != (8*(destination.at(1)-49))+(destination.at(0)-65)){
                        if (debug == true) std::cout << " Man darf eine Figur nicht Ürspringen [Lro]" <<std::endl;
                        return false;
                    }
                }
            }

            return true;
        }

    }

    if (debug == true) std::cout << "geben sie bitte einen g\x81ltigen Zug ein.[D]"<<std::endl;
    return false;*/
    }

    if(  Figur.at(0) == 68){// Dame

        if (turm (Board,Eingabe, source, destination,debug)== true){
            return true;
        }else{
            if(laeufer (Board,Eingabe, source, destination,debug)== true) return true;
            return false;
        }

    }

    if(  Figur.at(0) == 75){ // K\x94nig

        if (Koenig (Board,Eingabe, source, destination,debug)== true){return true;}else{return false;}



    }

    if(  Figur.at(0) == 66){//Bauer

        if (Bauer (Board,Eingabe, source, destination,debug)== true){return true;}else{return false;}

    }

    else{
        if (debug == true) std::cout<< "Auf diesem Feld befindet sich keine Figur,"<<std::endl;
        if (debug == true) std::cout << "geben sie bitte einen g\x81ltigen Zug ein."<<std::endl;
        return false;

    }

}


istGueltig::istGueltig()
{

}

