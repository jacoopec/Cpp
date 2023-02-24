#include "../../cppHeaders.h"

class Window {
    public:
        virtual void draw() = 0;
        virtual std::string getDescription() = 0;
        virtual ~Window() {}
};
 
class SimpleWindow : public Window {
    public:
        void draw() {
            // draw window 
        }
        std::string getDescription() {
            return "simple window\n";
        }
};

class WindowDecorator : public Window {
    protected:
        Window *m_decoratedWindow; 
    
    public:
        WindowDecorator (Window *decoratedWindow): 
        m_decoratedWindow(decoratedWindow) {}
};

class VerticalScrollBarDecorator : public WindowDecorator 
{
    public:
        VerticalScrollBarDecorator (Window *decoratedWindow): 
            WindowDecorator(decoratedWindow) {}
    
        void draw() {
            drawVerticalScrollBar();
            m_decoratedWindow->draw();
        }
    
        std::string getDescription() {
            return m_decoratedWindow->getDescription() + "with vertical scrollbars\n";
        }

    private:
        void drawVerticalScrollBar() {
            // draw the vertical scrollbar
        }
};

class HorizontalScrollBarDecorator : public WindowDecorator {
    public:
        HorizontalScrollBarDecorator (Window *decoratedWindow): 
            WindowDecorator(decoratedWindow) {}
    
        void draw() {
            drawHorizontalScrollBar();
            m_decoratedWindow->draw();
        }
    
        std::string getDescription() {
            return m_decoratedWindow->getDescription() + "with horizontal scrollbars\n";
        }
    private:
        void drawHorizontalScrollBar() {
            // draw the horizontal scrollbar
        }
};

int main(){
    Window *simple = new SimpleWindow();
    std::cout << simple -> getDescription() << std::endl;

    Window *horiz = new HorizontalScrollBarDecorator ( new SimpleWindow());
    std::cout << horiz -> getDescription() << std::endl;

    Window *vert = new VerticalScrollBarDecorator ( new SimpleWindow());
    std::cout << vert -> getDescription() << std::endl;

    Window *decoratedWindow = new HorizontalScrollBarDecorator (
                    new VerticalScrollBarDecorator(new SimpleWindow()));
    std::cout << decoratedWindow -> getDescription() << std::endl;

    return 0;
}