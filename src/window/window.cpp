//----STANDARD----
#include "iomanip"
#include "sstream"
#include "string.h"

//----LOCAL----
#include "window.h"
#include "common/io.h"

namespace Vast
{
	namespace Window
	{
		Window::Window()
		{
			IO::output("Creating window");
		}

		void Window::initiate()
		{
			this->settings.depthBits = 24;
			this->settings.stencilBits = 8;
			this->settings.antialiasingLevel = 4;
			this->settings.majorVersion = 3;
			this->settings.minorVersion = 3;
			this->settings.attributeFlags = sf::ContextSettings::Attribute::Debug | sf::ContextSettings::Attribute::Core;

			this->internal_window.create(sf::VideoMode(640, 480), "Window", sf::Style::Default, this->settings);

			this->internal_window.setFramerateLimit(60);
			
			this->setTitle("Vast");
			this->setVSync(true);

			IO::output("Initiated window");
		}
		
		void Window::setVSync(bool vsync)
		{
			this->vsync = vsync;
			this->internal_window.setVerticalSyncEnabled(this->vsync);
		}
		
		bool Window::getVSync()
		{
			return this->vsync;
		}

		void Window::setTitle(std::string title)
		{
			this->title = title;
			this->updateTitle();
		}

		std::string Window::getTitle()
		{
			return this->title;
		}
		
		void Window::updateTitle()
		{
			std::stringstream fps_string;
			fps_string << std::setprecision(4) << this->fps;
			this->internal_window.setTitle(std::string(this->title + " | FPS: " + fps_string.str()).c_str());
		}
		
		void Window::setShowFPS(bool show_fps)
		{
			this->show_fps = show_fps;
			this->updateTitle();
		}
		
		bool Window::getShowFPS()
		{
			return this->show_fps;
		}

		void Window::setFPS(uint16 fps)
		{
			this->internal_window.setFramerateLimit(fps);
		}

		void Window::setSize(uint16 width, uint16 height)
		{
			this->internal_window.setSize(sf::Vector2u(width, height));
		}

		glm::ivec2 Window::getSize()
		{
			sf::Vector2u dimensions = this->internal_window.getSize();
			return glm::ivec2(dimensions.x, dimensions.y);
		}

		bool Window::activate(bool active)
		{
			return this->internal_window.setActive(active);
		}

		bool Window::tick(double fps)
		{
			bool closed = false;
			
			//Update the current state of the fps
			this->fps = fps;

			sf::Event event;
			while (this->internal_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					closed = true;
					IO::output("Closed window");
				}
				else if (event.type == sf::Event::Resized)
				{
					IO::output("Resized or moved window");
				}
			}

			this->internal_window.display();
			
			//Set window FPS display
			this->updateTitle();

			return closed;
		}

		void Window::close()
		{
			this->internal_window.close();
		}
	}
}
