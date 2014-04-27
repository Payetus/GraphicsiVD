#include <escena.h>

using namespace std;

escena::escena()

{
    // Capsa minima contenidora provisional: S'ha de fer un recorregut dels objectes de l'escenes
    capsaMinima.pmin[0] = 0; capsaMinima.pmin[1] = 0; capsaMinima.pmin[2]=0;
    capsaMinima.a = 1; capsaMinima.h = 1; capsaMinima.p = 1;

    cotxe = NULL;
    terra = NULL;
}


escena::~escena()
{
    printf("DESTRUCTOR!");

}

void escena::addObjecte(Objecte *obj) {
    if (dynamic_cast<Cotxe*>(obj))
        this->cotxe = (Cotxe*)obj;

    else if (dynamic_cast<Terra*>(obj))
            this->terra = (Terra*)obj;
}


void escena::CapsaMinCont3DEscena()
{

    //Calcular min entre minims i max entre max (ara nomes un cotxe i un terra)

    for (int i =0; i<3;i++){
        if (this->cotxe->capsa.pmin[i]<this->terra->capsa.pmin[i]){
            this->capsaMinima.pmin[i] = this->cotxe->capsa.pmin[i];
        }else{
             this->capsaMinima.pmin[i] = this->terra->capsa.pmin[i];
        }
    }
    if (this->cotxe->capsa.pmin[0] + cotxe->capsa.a < this->terra->capsa.pmin[0] + cotxe->capsa.a){
        this->capsaMinima.a = this->cotxe->capsa.pmin[0] - this->cotxe->capsa.a;
    }else{
        this->capsaMinima.a = this->terra->capsa.pmin[0] - this->terra->capsa.a;
    }
    if (this->cotxe->capsa.pmin[0] + cotxe->capsa.p < this->terra->capsa.pmin[0] + cotxe->capsa.p){
        this->capsaMinima.p = this->cotxe->capsa.pmin[0] - this->cotxe->capsa.p;
    }else{
        this->capsaMinima.p = this->terra->capsa.pmin[0] - this->terra->capsa.p;
    }
    if (this->cotxe->capsa.pmin[0] + cotxe->capsa.h < this->terra->capsa.pmin[0] + cotxe->capsa.h){
        this->capsaMinima.h = this->cotxe->capsa.pmin[0] - this->cotxe->capsa.h;
    }else{
        this->capsaMinima.h = this->terra->capsa.pmin[0] - this->terra->capsa.h;
    }

}

void escena::aplicaTG(mat4 m) {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->aplicaTG(m);
    //else if (terra != NULL)
     //   terra ->aplicaTG();
}

void escena::aplicaTGCentrat(mat4 m) {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->aplicaTGCentrat(m);
    //else if (terra != NULL)
      //  terra ->aplicaTGCentrat();

}

void escena::draw() {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->draw();
    if (terra != NULL)
        terra ->draw();

}

void escena::reset() {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->make();
    if (terra != NULL)
        terra->make();

}

