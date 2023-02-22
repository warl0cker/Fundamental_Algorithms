#include <iostream>
#include <cmath>
using namespace std;
struct Punct{
       float x;
       float y;
       };
class Cerc{
    private:
        struct Punct centru;
        float raza;
    public:
        Cerc(struct Punct centruCoord, float valRaza){
            centru = centruCoord;
            raza = valRaza;
        }
        float getRaza(){
            return raza;
        }
        struct Punct getCentru(){
            return centru;
        }
        float getAria(){
            return raza*raza*3.14;
        }
        int punctPosPeCerc(struct Punct P){
            int rez = sqrt(pow((P.x - centru.x), 2) + pow((P.y - centru.y), 2));
            if      (rez < raza) return -1;
            else if (rez > raza) return  1;
            else                 return  0;
        }
        void moveCentru(struct Punct P){
            centru.x = P.x;
            centru.y = P.y;
        }
};


int main(){
    struct Punct C;
    float r;
    cout<<"Coordonatele: "; cin>>C.x; cin>>C.y;
    cout<<"Raza = "; cin>>r;
    Cerc obCerc(C, r);
    cout<<"Cercul are raza "<<obCerc.getRaza()<<" si Aria "<<obCerc.getAria();
    cout << "Coordonate centru cerc: O("<< obCerc.getCentru().x <<"," <<obCerc.getCentru().y << ")"<< endl;
    
    struct Punct P;
    cout<<"Coordonatele: "; cin>>P.x; cin>>P.y;
    int rez = obCerc.punctPosPeCerc(P);
    if      (rez < 0) cout<<"P este in interiorul cercului"<<endl;
    else if (rez > 0) cout<<"P este in exteriorul cercului"<<endl;
    else              cout<<"P este pe cerc"<<endl;
    obCerc.moveCentru(P);
    return 0;
}
