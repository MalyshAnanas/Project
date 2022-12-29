#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <thread>
using namespace sf;

bool space(int x, int y) {
    if ((x <= 461.283 || x>= 2159.56) || (y <= 281.828 || y >= 1424.58)) { return false; } //cтены
    if (x <= 782.767 && (580.034 <= y && y <= 918.27)) { return false; } //кровать высота
    if ((424.582 <= x && x <= 782.767) && y <= 918.27) { return false; } // кровать ширина
    if ((782.767 <= x && x <= 888.412) && y <= 499.409) { return false; } // цветок
    if ((935.71 <= x && x <= 1776.17) && y <= 483.525) { return false; } // шкаф ширина
    if (( x <= 1776.17) && (483.525<=y && y <= 281.828)) { return false; } // шкаф высота
    if ((1778.44 <= x && x<= 2215.75)&& ((428.112<=y || y <= 1013.8))) { return false; } // стол ширина
    if ((1778.44 <= x && x<= 2215.75) && (y <= 1013.8)) { return false; } // стол высота
    if ((468.805 <= x && x <= 1054.54) &&  y >= 1289.92) { return false; } // шкаф кн ширина
    if (1054.54 >= x && (1289.92 <= y && y <= 1424.58)) { return false; } // шкаф кн высота
    else { return true; }
}

int main() {
    setlocale(LC_ALL, "rus");
    sf::Font font;
    sf::Text text("",font, 30);
    sf::Text name("", font, 35);
    sf::RenderWindow window(sf::VideoMode(3000, 2000), "Soul");
    sf::Texture textureRoom;
    sf::Sprite spriteRoom;
    sf::RectangleShape rectangle(sf::Vector2f(2500, 500));
    rectangle.setPosition(6000, 3000);
    //sf::Music music;
    rectangle.setFillColor(sf::Color::Black);
    textureRoom.loadFromFile("Room.png");
    spriteRoom.setTexture(textureRoom);
    spriteRoom.setPosition(350, 0);
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("Frame.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, 350, 364));
    sprite.setPosition(1300, 750);
    Clock clock;
    font.loadFromFile("a_FuturaRound Bold.ttf");
    text.setColor(Color::White);
    name.setColor(Color::White);
    name.setStyle(Text::Bold);
    bool spaceflag = false;
    bool Bplaceflage = false;
    bool C1placeflage = false;
    bool C2placeflage = false;
    bool Fplaceflage = false;
    bool BCplaceflage = false;
    float frame = 0;
    //music.openFromFile("Snowy.mp3");
    while (window.isOpen()) {
        //music.play();
        sf::Event event;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        while (window.pollEvent(event)){
            if (event.type ==
                sf::Event::Closed)
                window.close();
        }
        Bplaceflage = false;
        if (Keyboard::isKeyPressed(Keyboard::Space)) { spaceflag = true; }
        if (spaceflag == true) {
            if (785.744 >= sprite.getPosition().x && (750.106 >= sprite.getPosition().y && sprite.getPosition().y >= 594.542)) { Bplaceflage = true; }// кровать
        }
        if (spaceflag == true && Bplaceflage == true) {
            rectangle.setPosition(350, 1500);
            text.setString( "I don't think this is the perfect time to sleep.");
            text.setPosition(360, 1560);
            name.setString("Sherli");
            name.setPosition(360, 1520);

        }
        if (spaceflag == false || Bplaceflage == false) {
            spaceflag = false;
            Bplaceflage = false;
            text.setString("");
            name.setString("");
            rectangle.setPosition(6000, 3000);
        }
        /*Fplaceflage = false;
        if (Keyboard::isKeyPressed(Keyboard::Space)) { spaceflag = true; }
        if (spaceflag == true) {
            if ((785.744 <= sprite.getPosition().x && sprite.getPosition().x  <= 876.961) && (sprite.getPosition().y <= 505.409)) { Fplaceflage = true; }// цветок
        }
        if (spaceflag == true && Fplaceflage == true) {
            rectangle.setPosition(350, 1500);
            text.setString("Oh, I remember my mother gave me this flower. She also said that day, 'This is a Chinese rose.As beautiful as you are'.");
            text.setPosition(360, 1560);
            name.setString("Sherli");
            name.setPosition(360, 1520);

        }
        if (spaceflag == false || Fplaceflage == false) {
            spaceflag = false;
            Fplaceflage = false;
            text.setString("");
            name.setString("");
            rectangle.setPosition(6000, 3000);
        }*/
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
            if ((space(sprite.getPosition().x, sprite.getPosition().y) == false)) {
                sprite.setPosition(sprite.getPosition().x + 3, sprite.getPosition().y);
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 718, 350, 364));
            }
            else {
                std::cout << "x="<<sprite.getPosition().x << "\n";
                std::cout << "y="<< sprite.getPosition().y << "\n";
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 718, 350, 364));
                sprite.move(-0.2 * time, 0);
            }
        }
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
            if (space(sprite.getPosition().x, sprite.getPosition().y) == false) {
                sprite.setPosition(sprite.getPosition().x - 3, sprite.getPosition().y);
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 357, 350, 364));
            }
            else {
                std::cout << "x=" << sprite.getPosition().x << "\n";
                std::cout << "y=" << sprite.getPosition().y << "\n";
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 357, 350, 364));
                sprite.move(0.2 * time, 0);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) { 
            if (space(sprite.getPosition().x, sprite.getPosition().y) == false) {
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 3);
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 1103, 350, 364));            }
            else {
                std::cout << "x=" << sprite.getPosition().x << "\n";
                std::cout << "y=" << sprite.getPosition().y << "\n";
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 1103, 350, 364));
                sprite.move(0, -0.2 * time);
            }
        }
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
            if (space(sprite.getPosition().x, sprite.getPosition().y) == false ) {
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 3);
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 0, 350, 358));
            }
            else {
                std::cout << "x=" << sprite.getPosition().x << "\n";
                std::cout << "y=" << sprite.getPosition().y << "\n";
                frame += 0.005 * time;
                if (frame > 4) { frame -= 4; }
                sprite.setTextureRect(IntRect(350 * int(frame), 0, 350, 358));
                sprite.move(0, 0.2 * time);
            }
        }
        window.clear();
        window.draw(spriteRoom);
		window.draw(sprite);
        window.draw(rectangle);
        window.draw(text);
        window.draw(name);
        window.display();
    }
    return 0;
}