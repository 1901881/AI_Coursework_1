#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Title");
	ImGui::SFML::Init(window);

	bool circleExists = true;
	float circleRadius = 200.0f;
	int circleSegments = 100;
	float circleColor[3] = { (float)204 / 255, (float)77 / 255, (float)5 / 255, };
	sf::CircleShape shape(circleRadius, circleSegments);
	
	shape.setFillColor(sf::Color((int)(circleColor[0] * 255), (int)(circleColor[1] * 255), (int)(circleColor[2] * 255)));//Color Circle
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
			ImGui::Checkbox("Circle", &circleExists);
			ImGui::SliderFloat("Radius", &circleRadius, 100.0f, 300.0f);
			ImGui::SliderInt("Segments", &circleSegments, 3.0f, 150.0f);
			ImGui::ColorEdit3("Color", circleColor);
			ImGui::End();

			shape.setRadius(circleRadius);
			shape.setPointCount(circleSegments);
			shape.setFillColor(sf::Color((int)(circleColor[0] * 255), (int)(circleColor[1] * 255), (int)(circleColor[2] * 255)));//Color Circle

			window.clear(sf::Color(18, 33, 43)); //Color Background
			if (circleExists)
			{
				window.draw(shape);
			}
			ImGui::SFML::Render(window);//Make sure ImGui is the last to render
			window.display();
		}
	}

	ImGui::SFML::Shutdown();
	return 0;
}