int main(){
            std::cout << "inheritance" << std::endl;
        Person("Robert", Cat(5,"jerry"));
        Person p;
        Animal a;
        Cat c;
        Animal* p1 = &p;
        Animal* p2 = &c;
        p1->drink();
        p1->eat();
        p1->sleep();
        p.washing();
        p2->drink();
        p2->eat();
        p2->sleep();
        c.washing();
}