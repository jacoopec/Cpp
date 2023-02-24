//Il singleton si usa per funzionalità che si applicano a dati globali
//singletons in c++ are just a way to organise global variables and static functions under a namespace

class Random{
    Random(){};  //the constructor is private
    float m_RandomGen = 0.5f;
    static Random s_Instance;
    float IFloat(){ return m_RandomGen;}

    public:
        Random(const Random&) = delete;
        static Random& Get(){
            static Random instance;
            return s_Instance;
        }
        float Float(){ return m_RandomGen;}
        static float Float(){return Get().IFloat();}
};

Random Random::s_Instance;

int main(){
    float number = Random::Get().Float();
}