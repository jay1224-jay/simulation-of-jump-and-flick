#include <SFML/Graphics.hpp>
#include <iostream>

#define ground 500

#include "main.hpp"


typedef sf::RectangleShape rect;

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 700), "jump and flick");
    window.setFramerateLimit(60);


    rect ground_line( sf::Vector2f(800, 2) );
    ground_line.setPosition(0, ground);
    ground_line.setFillColor(sf::Color::Black);


    sf::RectangleShape player( sf::Vector2f( 60, 100 ) );
    player.setFillColor(sf::Color::Blue);
    player.setPosition(100, ground - 100 );


    bool jump_flag = false;


    while ( window.isOpen() ) {
        
        sf::Event event;

        while ( window.pollEvent(event) ) {

            if ( event.type == sf::Event::Closed ) {
                window.close();
            }

        }

        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
            jump_flag = true;
        }

        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
            if ( player.getPosition().x > 0 )
                player.move(-5.f, 0.f);
        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            if ( player.getPosition().x + player.getSize().x < window.getSize().x )
                player.move(5.f, 0.f);
        }


        if ( jump_flag ) {


            int status = jump(player, current_velocity);

            if ( status == keep_jump )
                ;
            else if ( status == stop_jump ) {
                // reset jump variable;

                begin_velocity = original_velocity;
                current_velocity = original_velocity;

                jump_flag = false;

            }

            else if ( status == re_jump ) {
                begin_velocity *= flick_effect;
                current_velocity = begin_velocity;
            }


        }


        window.clear(sf::Color::White);

        window.draw(player);
        window.draw(ground_line);

        window.display();

    }
}

