#include "../../cppHeaders.h"
#include "../../CHeaders.h"

class IBookParser{
    virtual int getNumPages() = 0;
};

class BookParser: public IBookParser{
    public:
        BookParser(std::string book){
            std::cout << "Parsing...\n";
        }
        int getNumPages() override{

        }
};

class LazyBookParserProxy : public IBookParser{
    BookParser *bP = nullptr;
    std::string _book;
    public:
        LazyBookParserProxy(std::string book){
            this->_book = book;
        }
        int getNumPages(){
            if(this->bP == nullptr){
                this->bP = new BookParser(this->bP);
            }
                return this->bP->getNumPages();
        }
};

int main(){

}