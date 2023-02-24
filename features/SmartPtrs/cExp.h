namespace constExp{
    class Entity{
        int x = 34;
        const char* m_name = "iuhi";
        std::string m_name2;
        mutable int u = 3;
        public:
        Entity(){std::cout << "Created entity " << this->getName2()  << std::endl;};
        ~Entity(){std::cout << "Entity gone " << this->getName2()  << std::endl;};
        Entity(const std::string& name_) : m_name2(name_){std::cout << "Created entity " << this->getName2() << std::endl;};
        const int getX() const {
            return x;
            u = 0;
        }
        const int getX2() const {
            return x;
        }
        const std::string& getName() const{
            const std::string& m = m_name;
            return m;
        }

        std::string& getName2(){
            std::string& m = m_name2;
            return m;
        }

        Entity Add(Entity e) const{
            return Entity(m_name2 + std::string(e.getName2()));
        }

        Entity Sub(Entity e){
            for(int i = 0;  i < e.getName2().size(); i++){
                e.getName2().pop_back();
            }
            return e;
        }

        Entity operator+(Entity e){
            return Add(e);
        }

        Entity operator-(Entity e){
            return Sub(e);
        }
    };

    void printEntity(const Entity& e);
}

void constExp::printEntity(const Entity& e){
    std::cout << e.getX()  << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const vecs::v& vec){
    stream << vec.a << " " << vec.b << " "  << vec.c << std::endl;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const vecs::String& string){

}