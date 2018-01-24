#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    
    RenderWindow window(VideoMode(800, 600), "hey");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::Black);




        window.display();
    }
    return 0;
}