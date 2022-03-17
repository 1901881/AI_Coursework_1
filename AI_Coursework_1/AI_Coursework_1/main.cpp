#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Title");
	ImGui::SFML::Init(window);

	sf::CircleShape shape(200.0f, 100);
	shape.setFillColor(sf::Color(204, 77, 5));//Color Circle
	shape.setPosition(200, 200); //Center Circle

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			ImGui::SFML::Update(window, deltaClock.restart());

			ImGui::Begin("Window title");
			ImGui::Text("Window text!");
			ImGui::End();

			window.clear(sf::Color(18, 33, 43)); //Color Background
			window.draw(shape);
			ImGui::SFML::Render(window);//Make sure ImGui is the last to render
			window.display();
		}
	}

	ImGui::SFML::Shutdown();
	return 0;
}