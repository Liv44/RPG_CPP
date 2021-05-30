class Jeux
{   
public:
    Jeux();

    void menuPrincipale();

    inline bool getPlaying() const {return this->playing; }

private:
    int choix;
    bool playing;
};