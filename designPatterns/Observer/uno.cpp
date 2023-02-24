#include "../../cppHeaders.h"
#include "../../CHeaders.h"

class Subject; 

class Observer 
{ 
    public: 
        Observer() {}; 
        ~Observer() {}; 
        virtual void Update(Subject* theChangeSubject) = 0; 
}; 

class Subject{ 
    public: 
        Subject() {}; 
        virtual ~Subject() {}; 
        virtual void Attach(Observer* o){ 
            _observers.push_back(o); 
        } 
        virtual void Detach(Observer* o){ 
            int count = _observers.size(); 
            int i; 

            for (i = 0; i < count; i++) { 
                if(_observers[i] == o) 
                break; 
            } 
            if(i < count) 
                _observers.erase(_observers.begin() + i); 
        } 
        virtual void Notify(){ 
            int count = _observers.size(); 

            for (int i = 0; i < count; i++) 
                (_observers[i])->Update(this); 
        }
    private: 
        std::vector<Observer*> _observers; 
}; 



class ClockTimer : public Subject{ 
    public: 
        ClockTimer() { _strtime( tmpbuf ); }; 
        int GetHour(); 
        int GetMinute();
        int GetSecond(); 
        void Tick();   
    private: 
        char tmpbuf[128]; 
}; 


void ClockTimer::Tick() 
{ 
    _tzset(); 

// Obtain operating system-style time. 
    _strtime( tmpbuf ); 
    Notify(); 
} 

int ClockTimer::GetHour() { 
    char timebuf[128]; 
    strncpy(timebuf, tmpbuf, 2); 
    timebuf[2] = NULL; 
    
    return atoi(timebuf); 
} 

int ClockTimer::GetMinute() 
{ 
 char timebuf[128]; 
 strncpy(timebuf, tmpbuf+3, 2); 
 timebuf[2] = NULL; 

 return atoi(timebuf); 
} 

int ClockTimer::GetSecond() 
{ 
 char timebuf[128];
 strncpy(timebuf, tmpbuf+6, 2); 
 timebuf[2] = NULL; 

 return atoi(timebuf); 
}


class DigitalClock: public Observer 
{ 
public: 
 DigitalClock(ClockTimer *);  
 ~DigitalClock();   
  void Update(Subject *);   
  void Draw();     
private: 
 ClockTimer *_subject;  
}; 

DigitalClock::DigitalClock (ClockTimer *s) 
{ 
 _subject = s; 
 _subject->Attach(this); 
} 

DigitalClock::~DigitalClock () 
{ 
 _subject->Detach(this); 
} 

void DigitalClock::Update (Subject *theChangedSubject) 
{ 
 if(theChangedSubject == _subject) 
  Draw(); 
} 

void DigitalClock::Draw () 
{ 
 int hour = _subject->GetHour(); 
 int minute = _subject->GetMinute(); 
 int second = _subject->GetSecond(); 

 cout << "Digital time is " << hour << ":" 
          << minute << ":" 
          << second << endl;           
}

class AnalogClock: public Observer 
{ 
public: 
 AnalogClock(ClockTimer *);  
 ~AnalogClock();    
  void Update(Subject *);  
  void Draw();     
private: 
 ClockTimer *_subject;   
}; 

AnalogClock::AnalogClock (ClockTimer *s) 
{ 
 _subject = s; 
 _subject->Attach(this); 
} 

AnalogClock::~AnalogClock () 
{ 
 _subject->Detach(this); 
} 

void AnalogClock::Update (Subject *theChangedSubject) 
{ 
 if(theChangedSubject == _subject) 
  Draw(); 
} 

void AnalogClock::Draw () 
{ 
 int hour = _subject->GetHour(); 
 int minute = _subject->GetMinute(); 
 int second = _subject->GetSecond(); 

 cout << "Analog time is " << hour << ":" 
         << minute << ":" 
         << second << endl; 
}

int main(void) 
{ 
 ClockTimer timer; 

 DigitalClock digitalClock(&timer;); 
 AnalogClock analogClock(&timer;); 
  
 timer.Tick();  
  
 return 0; 
}