int main(){
            vecs::v uno(1,2,3);
        uno.Print();
        std::shared_ptr<constExp::Entity> sharedEnt;
        {
            std::cout << "unique Ptr è un scope ptr. Non si possono copiare. quando escono dallo scope liberano la memoria, si ha solo una reference a quella memoria." << std::endl;
            std::unique_ptr<constExp::Entity> uPtr(new constExp::Entity("oijijooi"));
            std::unique_ptr<constExp::Entity> uPtr2 = std::make_unique<constExp::Entity>();
            std::shared_ptr<constExp::Entity> sharedEnt2(new constExp::Entity("jiuhi"));
            constExp::Entity* ePtr = new constExp::Entity;
            sharedEnt = sharedEnt2;
            uPtr->getName2();
        } 
}