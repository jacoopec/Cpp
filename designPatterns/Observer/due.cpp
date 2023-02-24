#include "../../cppHeaders.h"
#include "../../CHeaders.h"

class ObserverInterface{
    public:
        virtual ~ObserverInterface() {}
        virtual void update(int message) = 0;
};

class SubjectInterface{
    public:
        virtual ~SubjectInterface(){};
        virtual void subscribe(ObserverInterface *observer){
	        mObservers.push_back(observer);
        }

        virtual void unsubscribe (ObserverInterface *){
            int count = mObservers.size(); 
            int i; 

            for (i = 0; i < count; i++) { 
                if(mObservers[i] == 0) 
                break; 
            } 
            if(i < count) 
                mObservers.erase(mObservers.begin() + i);
        }
        virtual void notify(int message){
            int count = mObservers.size(); 

            for (int i = 0; i < count; i++) 
                (mObservers[i])->update(message); 
        }
    private:
        std::vector<ObserverInterface *> mObservers;
};



class MySubject : public SubjectInterface
{
public:
	enum Message {ADD, REMOVE};
};

class MyObserver : public ObserverInterface{
    public:
        explicit MyObserver(const std::string &str) : name(str) {}
        void update(int message)
        {
            std::cout << name << " Got message " << message << std::endl;
        }
    private:
        std::string name;
};

int main() 
{
	MyObserver observerA("observerA");
	MyObserver observerB("observerB");
	MyObserver observerC("observerC");

	MySubject subject;
	subject.subscribe(&observerA);
	subject.subscribe(&observerB);
	subject.unsubscribe(&observerB);
	subject.subscribe(&observerC);

	subject.notify(MySubject::ADD);
	subject.notify(MySubject::REMOVE);

	return 0;
}