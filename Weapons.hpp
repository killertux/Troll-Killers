
class Weapon{
protected:
    int pos_x , pos_y, ang_x, ang_y;
    int dmg;
public:
    void setposx (int x){
        pos_x = x;
    }
    void setposy (int y){
        pos_y = y;
    }
    void setangx(int x){
        ang_x = x;
    }
    void setangy(int y){
        ang_y = y;
    }
    void rotation ();
};
